Pod::Spec.new do |s|

    s.name     = 'QY_iOS_SDK'
    s.version  = '8.2.0'
    s.license  = { :"type" => "Copyright",
                   :"text" => " Copyright 2021 Netease \n"}  
    s.summary  = '网易七鱼客服访客端 iOS SDK'
    s.homepage = 'https://qiyukf.com'
    s.author   = { 'qiyukf' => 'yunshangfu@126.com' }
    s.source   = { :git => 'https://github.com/qiyukf/QY_iOS_SDK.git', :tag => "#{s.version}" }
    s.platform = :ios, '9.0'
    s.frameworks = 'AVFoundation', 'UIKit', 'SystemConfiguration', 'MobileCoreServices', 'WebKit', 'CoreTelephony', 'CoreText', 'CoreMedia', 'ImageIO', 'CoreMotion', 'AudioToolbox', 'Photos', 'AssetsLibrary', 'Accelerate'
    s.libraries = 'c++', 'z','sqlite3.0','xml2'
    s.resources  = ['**/Resources/QYResource.bundle', '**/Resources/QYLanguage.bundle', '**/Resources/QYCustomResource.bundle']
    s.default_subspec = 'Default'
    s.subspec 'Default' do |ds|
    		ds.resources  = ['**/Resources/QYResource.bundle', '**/Resources/QYLanguage.bundle', '**/Resources/QYCustomResource.bundle']
        ds.vendored_frameworks = '**/QYSDK.xcframework'
        ds.dependency 'NIMSDK_LITE', '8.9.110'
      end
    s.subspec 'Abroad' do |as|
    		as.resources  = ['**/Resources/QYResource.bundle', '**/Resources/QYLanguage.bundle', '**/Resources/QYCustomResource.bundle', '**/Resources/QYConfigResource.bundle']
        as.vendored_frameworks = '**/QYSDK.xcframework'
        as.frameworks = 'QYSDK'
        as.dependency 'NIMSDK_LITE', '9.2.8'
        
    end  
    s.subspec 'Video' do |vs|
    		vs.resources  = ['**/Resources/QYResource.bundle', '**/Resources/QYLanguage.bundle', '**/Resources/QYCustomResource.bundle' , '**/Resources/QYVideoResource.bundle']
        vs.vendored_frameworks = ['**/QYSDK.xcframework','**/QYVideoService.xcframework']
        vs.dependency 'NIMSDK_LITE', '8.9.110'
        vs.dependency 'NERtcSDK', '4.6.20'
    end
    s.pod_target_xcconfig = { 'VALID_ARCHS' => 'armv7 x86_64 arm64' }
    s.requires_arc = true
    end



