Pod::Spec.new do |s|

    s.name     = 'QY_iOS_SDK'
    s.version  = '11.6.0'
    s.license  = { :"type" => "Copyright",
                   :"text" => " Copyright 2021 Netease \n"}  
    s.summary  = '网易七鱼客服访客端 iOS SDK'
    s.homepage = 'https://qiyukf.com'
    s.author   = { 'qiyukf' => 'yunshangfu@126.com' }
    s.source   = { :git => 'https://github.com/qiyukf/QY_iOS_SDK.git', :tag => "#{s.version}" }
    s.platform = :ios, '9.0'
    s.frameworks = 'AVFoundation', 'UIKit', 'SystemConfiguration', 'MobileCoreServices', 'WebKit', 'CoreTelephony', 'CoreText', 'CoreMedia', 'ImageIO', 'CoreMotion', 'AudioToolbox', 'Photos', 'Accelerate','PhotosUI'
    s.libraries = 'c++', 'z','sqlite3.0','xml2','resolv'
    s.resources  = ['**/Resources/QYResource.bundle', '**/Resources/QYLanguage.bundle', '**/Resources/QYCustomResource.bundle']
    s.default_subspec = 'Default'

    # ----------------------------------------------------------------------------
    # [QY] Archive 阶段把 SDK 内置 dSYM 拷贝到 xcarchive 的 dSYMs 目录
    # 起因：CocoaPods 在解析同 subspec 下多个 vendored xcframework 时，会用
    #      `rsync --delete` 把每个 xcframework 的 ios-arm64 slice 解到同一个目录
    #      （${PODS_XCFRAMEWORKS_BUILD_DIR}/QY_iOS_SDK/<Subspec>/）。每个 xcframework
    #      内部都有同名的 `dSYMs/` 子目录，rsync --delete 会让它们互相覆盖，最终只剩
    #      最后一个 install_xcframework 的那一份。结果上传 App Store 时，其它
    #      framework 都报 "Upload Symbols Failed"。
    # 解法：绕开 CocoaPods 的中间目录，archive 阶段直接从 Pods 根目录下的 xcframework
    #      把 dSYM 拷到 ${DWARF_DSYM_FOLDER_PATH}（即 *.xcarchive/dSYMs/）。
    # ----------------------------------------------------------------------------
    qy_dsym_phase = {
      :name => '[QY] Copy SDK dSYMs to xcarchive',
      :execution_position => :after_compile,
      :shell_path => '/bin/sh',
      :script => <<~'SH'
        set -eu
        # 仅在 archive 时 Xcode 会设置 DWARF_DSYM_FOLDER_PATH，其它时候跳过
        if [ -z "${DWARF_DSYM_FOLDER_PATH:-}" ]; then
          exit 0
        fi

        # 选 slice：真机 vs 模拟器
        if [[ "${PLATFORM_NAME:-iphoneos}" == *simulator ]]; then
          SLICE="ios-arm64_x86_64-simulator"
        else
          SLICE="ios-arm64"
        fi

        # 兼容多种集成方式定位 SDK 根目录：
        #   1) 远端 :git / Release pod      → ${PODS_ROOT}/QY_iOS_SDK/SDK
        #   2) 本地 :path => './QY_iOS_SDK' → ${SRCROOT}/QY_iOS_SDK/SDK 或 ${PODS_ROOT}/../QY_iOS_SDK/SDK
        SDK_ROOT=""
        for cand in \
          "${PODS_ROOT}/QY_iOS_SDK/SDK" \
          "${SRCROOT}/QY_iOS_SDK/SDK" \
          "${PODS_ROOT}/../QY_iOS_SDK/SDK"; do
          if [ -d "$cand" ]; then
            SDK_ROOT="$cand"
            break
          fi
        done
        if [ -z "${SDK_ROOT}" ]; then
          echo "warning: [QY] SDK_ROOT not found, skip dSYM copy"
          exit 0
        fi
        echo "[QY] SDK_ROOT=${SDK_ROOT}, SLICE=${SLICE}"

        mkdir -p "${DWARF_DSYM_FOLDER_PATH}"

        # 列出 podspec 三个 subspec 涉及到的所有 xcframework；不存在的会被自动跳过
        for fw in QYSDK QYKFNIMSDK QYKFNIMNOS QYVideoService QYKFAWSCore QYKFAWSS3; do
          SRC="${SDK_ROOT}/${fw}.xcframework/${SLICE}/dSYMs/${fw}.framework.dSYM"
          DST="${DWARF_DSYM_FOLDER_PATH}/${fw}.framework.dSYM"
          if [ -d "${SRC}" ]; then
            /usr/bin/ditto "${SRC}" "${DST}"
            echo "[QY] Copied ${fw}.framework.dSYM"
          fi
        done
      SH
    }

    s.subspec 'Default' do |ds|
        ds.resources  = ['**/Resources/QYResource.bundle', '**/Resources/QYLanguage.bundle', '**/Resources/QYCustomResource.bundle']
        ds.vendored_frameworks = ['**/QYSDK.xcframework','**/QYKFNIMSDK.xcframework','**/QYKFNIMNOS.xcframework']
        ds.script_phases = [qy_dsym_phase]
      end
    s.subspec 'Abroad' do |as|
        as.resources  = ['**/Resources/QYResource.bundle', '**/Resources/QYLanguage.bundle', '**/Resources/QYCustomResource.bundle', '**/Resources/QYConfigResource.bundle']
        as.vendored_frameworks = ['**/QYSDK.xcframework','**/QYKFNIMSDK.xcframework','**/QYKFNIMNOS.xcframework','**/QYKFAWSCore.xcframework','**/QYKFAWSS3.xcframework']
        as.script_phases = [qy_dsym_phase]
    end  
    s.subspec 'Video' do |vs|
        vs.resources  = ['**/Resources/QYResource.bundle', '**/Resources/QYLanguage.bundle', '**/Resources/QYCustomResource.bundle' , '**/Resources/QYVideoResource.bundle']
        vs.vendored_frameworks = ['**/QYSDK.xcframework','**/QYKFNIMSDK.xcframework','**/QYKFNIMNOS.xcframework','**/QYVideoService.xcframework']
        vs.dependency 'NERtcSDK/RtcBasic', '5.6.50'
        vs.dependency 'NERtcSDK/ScreenShare', '5.6.50'
        vs.script_phases = [qy_dsym_phase]
    end
    s.pod_target_xcconfig = { 'VALID_ARCHS' => 'armv7 x86_64 arm64' }
    s.requires_arc = true
    end



