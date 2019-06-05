Pod::Spec.new do |s|
  s.name         = "NvsStreamingSdk"
  s.version      = "2.9.0"
  s.summary      = "Meishe SDK"
  s.description  = <<-DESC
                     This is Meishe SDK
                   DESC

  s.homepage     = "https://www.meishesdk.com"
  s.license      = { :type => "Meishe SDK License", :file => "LICENSE.md" }
  s.author       = { "shizhouhu" => "shi_zhouhu@cdv.com" }
  s.platform     = :ios, "8.0"
  s.source       = { :git => "https://github.com/shizhouhu/NvsStreamingSdk.git", :tag => s.version}
  s.source_files = "lib/**/NvStreamingSdkCore.framework/Headers/*.h"
  s.public_header_files = "lib/**/NvStreamingSdkCore.framework/Headers/*.h"
  s.ios.vendored_frameworks = "lib/**/NvStreamingSdkCore.framework"
  s.requires_arc       = true
  s.user_target_xcconfig = {"ENABLE_BITCODE" => "NO", "VALID_ARCHS" => "arm64 armv7 x86_64", "HEADER_SEARCH_PATHS" => "$(inherited) \"${PODS_ROOT}/NvsStreamingSdk/lib/ios/NvStreamingSdkCore.framework/Headers\""}
end
