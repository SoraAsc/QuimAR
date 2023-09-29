// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class QuimAR : ModuleRules
{
	public QuimAR(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "AugmentedReality" });

/*        PublicIncludePaths.AddRange(
             new string[] {
                "C:/tools/vcpkg/installed/x64-windows-static/include",
             }
         );*/

        //PublicAdditionalLibraries.Add("C:/tools/vcpkg/installed/x64-windows-static/lib/tesseract53.lib");

        //PrivateDependencyModuleNames.AddRange(new string[] { "AugmentedReality" });

        // Uncomment if you are using Slate UI
        // PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        // Uncomment if you are using online features
        // PrivateDependencyModuleNames.Add("OnlineSubsystem");

        // To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true

        /*PublicIncludePaths.AddRange(
        new string[] {
            "C:/tools/vcpkg/installed/x64-windows-static/include",
        }
        );
        PublicAdditionalLibraries.Add("C:/tools/vcpkg/installed/x64-windows-static/lib/tesseract53.lib");
        */
        /*       PublicAdditionalLibraries.Add("C:\\tools\\vcpkg\\installed\\x64-windows-static\\lib\\archive.lib");
               PublicAdditionalLibraries.Add("C:\\tools\\vcpkg\\installed\\x64-windows-static\\lib\\bz2.lib");
               PublicAdditionalLibraries.Add("C:\\tools\\vcpkg\\installed\\x64-windows-static\\lib\\charset.lib");
               PublicAdditionalLibraries.Add("C:\\tools\\vcpkg\\installed\\x64-windows-static\\lib\\gif.lib");
               PublicAdditionalLibraries.Add("C:\\tools\\vcpkg\\installed\\x64-windows-static\\lib\\iconv.lib");
               PublicAdditionalLibraries.Add("C:\\tools\\vcpkg\\installed\\x64-windows-static\\lib\\jpeg.lib");
               PublicAdditionalLibraries.Add("C:\\tools\\vcpkg\\installed\\x64-windows-static\\lib\\leptonica-1.83.1.lib");
               PublicAdditionalLibraries.Add("C:\\tools\\vcpkg\\installed\\x64-windows-static\\lib\\libcrypto.lib");
               PublicAdditionalLibraries.Add("C:\\tools\\vcpkg\\installed\\x64-windows-static\\lib\\libcurl.lib"); //d
               PublicAdditionalLibraries.Add("C:\\tools\\vcpkg\\installed\\x64-windows-static\\lib\\libpng16.lib");
               PublicAdditionalLibraries.Add("C:\\tools\\vcpkg\\installed\\x64-windows-static\\lib\\libsharpyuv.lib"); //d
               PublicAdditionalLibraries.Add("C:\\tools\\vcpkg\\installed\\x64-windows-static\\lib\\libssl.lib");
               PublicAdditionalLibraries.Add("C:\\tools\\vcpkg\\installed\\x64-windows-static\\lib\\libwebp.lib"); //d
               PublicAdditionalLibraries.Add("C:\\tools\\vcpkg\\installed\\x64-windows-static\\lib\\libwebpdecoder.lib"); //d
               PublicAdditionalLibraries.Add("C:\\tools\\vcpkg\\installed\\x64-windows-static\\lib\\libwebpdemux.lib"); //d
               PublicAdditionalLibraries.Add("C:\\tools\\vcpkg\\installed\\x64-windows-static\\lib\\libwebpmux.lib");
               PublicAdditionalLibraries.Add("C:\\tools\\vcpkg\\installed\\x64-windows-static\\lib\\libxml2.lib");
               PublicAdditionalLibraries.Add("C:\\tools\\vcpkg\\installed\\x64-windows-static\\lib\\lz4.lib");
               PublicAdditionalLibraries.Add("C:\\tools\\vcpkg\\installed\\x64-windows-static\\lib\\lzma.lib");
               PublicAdditionalLibraries.Add("C:\\tools\\vcpkg\\installed\\x64-windows-static\\lib\\lzo2.lib");
               PublicAdditionalLibraries.Add("C:\\tools\\vcpkg\\installed\\x64-windows-static\\lib\\openjp2.lib");
               PublicAdditionalLibraries.Add("C:\\tools\\vcpkg\\installed\\x64-windows-static\\lib\\tesseract53.lib");
               PublicAdditionalLibraries.Add("C:\\tools\\vcpkg\\installed\\x64-windows-static\\lib\\tiff.lib");
               //tiffxx
               PublicAdditionalLibraries.Add("C:\\tools\\vcpkg\\installed\\x64-windows-static\\lib\\turbojpeg.lib");
               //web
               PublicAdditionalLibraries.Add("C:\\tools\\vcpkg\\installed\\x64-windows-static\\lib\\xxhash.lib");
               PublicAdditionalLibraries.Add("C:\\tools\\vcpkg\\installed\\x64-windows-static\\lib\\zlib.lib");
               PublicAdditionalLibraries.Add("C:\\tools\\vcpkg\\installed\\x64-windows-static\\lib\\zstd.lib");*/

        /* RuntimeDependencies.Add("C:\\tools\\vcpkg\\installed\\x64-windows-static\\lib\\archive.lib");
         RuntimeDependencies.Add("C:\\tools\\vcpkg\\installed\\x64-windows-static\\lib\\bz2.lib");
         RuntimeDependencies.Add("C:\\tools\\vcpkg\\installed\\x64-windows-static\\lib\\charset.lib");
         RuntimeDependencies.Add("C:\\tools\\vcpkg\\installed\\x64-windows-static\\lib\\gif.lib");
         RuntimeDependencies.Add("C:\\tools\\vcpkg\\installed\\x64-windows-static\\lib\\iconv.lib");
         RuntimeDependencies.Add("C:\\tools\\vcpkg\\installed\\x64-windows-static\\lib\\jpeg.lib");
         RuntimeDependencies.Add("C:\\tools\\vcpkg\\installed\\x64-windows-static\\lib\\leptonica-1.83.1.lib");
         RuntimeDependencies.Add("C:\\tools\\vcpkg\\installed\\x64-windows-static\\lib\\libcrypto.lib");
         RuntimeDependencies.Add("C:\\tools\\vcpkg\\installed\\x64-windows-static\\lib\\libcurl.lib"); //d
         RuntimeDependencies.Add("C:\\tools\\vcpkg\\installed\\x64-windows-static\\lib\\libpng16.lib");
         RuntimeDependencies.Add("C:\\tools\\vcpkg\\installed\\x64-windows-static\\lib\\libsharpyuv.lib"); //d
         RuntimeDependencies.Add("C:\\tools\\vcpkg\\installed\\x64-windows-static\\lib\\libssl.lib");
         RuntimeDependencies.Add("C:\\tools\\vcpkg\\installed\\x64-windows-static\\lib\\libwebp.lib"); //d
         RuntimeDependencies.Add("C:\\tools\\vcpkg\\installed\\x64-windows-static\\lib\\libwebpdecoder.lib"); //d
         RuntimeDependencies.Add("C:\\tools\\vcpkg\\installed\\x64-windows-static\\lib\\libwebpdemux.lib"); //d
         RuntimeDependencies.Add("C:\\tools\\vcpkg\\installed\\x64-windows-static\\lib\\libwebpmux.lib");
         RuntimeDependencies.Add("C:\\tools\\vcpkg\\installed\\x64-windows-static\\lib\\libxml2.lib");
         RuntimeDependencies.Add("C:\\tools\\vcpkg\\installed\\x64-windows-static\\lib\\lz4.lib");
         RuntimeDependencies.Add("C:\\tools\\vcpkg\\installed\\x64-windows-static\\lib\\lzma.lib");
         RuntimeDependencies.Add("C:\\tools\\vcpkg\\installed\\x64-windows-static\\lib\\lzo2.lib");
         RuntimeDependencies.Add("C:\\tools\\vcpkg\\installed\\x64-windows-static\\lib\\openjp2.lib");
         RuntimeDependencies.Add("C:\\tools\\vcpkg\\installed\\x64-windows-static\\lib\\tesseract53.lib");
         RuntimeDependencies.Add("C:\\tools\\vcpkg\\installed\\x64-windows-static\\lib\\tiff.lib");
         //tiffxx
         RuntimeDependencies.Add("C:\\tools\\vcpkg\\installed\\x64-windows-static\\lib\\turbojpeg.lib");
         //web
         RuntimeDependencies.Add("C:\\tools\\vcpkg\\installed\\x64-windows-static\\lib\\xxhash.lib");
         RuntimeDependencies.Add("C:\\tools\\vcpkg\\installed\\x64-windows-static\\lib\\zlib.lib");
         RuntimeDependencies.Add("C:\\tools\\vcpkg\\installed\\x64-windows-static\\lib\\zstd.lib");*/
    }
}
