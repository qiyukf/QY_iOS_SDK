Pod::Spec.new do |s|

    s.name     = 'QY_iOS_SDK'
    s.version  = '5.16.0'
    s.license  = { :"type" => "Copyright",
                   :"text" => " Copyright 2020 Netease \n"}  
    s.summary  = '网易七鱼客服访客端 iOS SDK'
    s.homepage = 'https://qiyukf.com'
    s.author   = { 'qiyukf' => 'yunshangfu@126.com' }
    s.source   = { :git => 'https://github.com/qiyukf/QY_iOS_SDK.git', :tag => "5.16.0" }
    s.platform = :ios, '9.0'

    s.vendored_frameworks = '**/QYSDK.framework'
    s.framework = 'AVFoundation', 'UIKit', 'SystemConfiguration', 'MobileCoreServices', 'WebKit', 'CoreTelephony', 'CoreText', 'CoreMedia', 'ImageIO', 'CoreMotion', 'AudioToolbox', 'Photos', 'AssetsLibrary', 'Accelerate'
    s.libraries = 'c++', 'z','sqlite3.0','xml2'
    s.resource  = '**/Resources/QYResource.bundle'
    s.dependency 'NIMSDK_LITE', '8.1.2'
    s.dependency 'libwebp', '~> 1.1.0'

    s.requires_arc = true

end
