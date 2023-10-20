// Copyright Epic Games, Inc. All Rights Reserved.

using System.IO;
using UnrealBuildTool;

public class QuimAR : ModuleRules
{
	public QuimAR(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "AugmentedReality" });

        PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "OCR-Linux", "include"));
        //PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "OCR", "include"));

        PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "OCR", "lib", "archive.lib"));
        PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "OCR", "lib", "leptonica-1.83.1.lib"));
        PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "OCR", "lib", "tesseract53.lib"));

        PublicDelayLoadDLLs.Add("archive.dll");
        PublicDelayLoadDLLs.Add("bz2.dll");
        PublicDelayLoadDLLs.Add("charset-1.dll");
        PublicDelayLoadDLLs.Add("gif.dll");
        PublicDelayLoadDLLs.Add("iconv-2.dll");
        PublicDelayLoadDLLs.Add("jpeg62.dll");
        PublicDelayLoadDLLs.Add("legacy.dll");
        PublicDelayLoadDLLs.Add("libcrypto-3-x64.dll");
        PublicDelayLoadDLLs.Add("libcurl.dll");
        PublicDelayLoadDLLs.Add("liblzma.dll");
        PublicDelayLoadDLLs.Add("libpng16.dll");
        PublicDelayLoadDLLs.Add("libsharpyuv.dll");
        PublicDelayLoadDLLs.Add("libssl-3-x64.dll");
        PublicDelayLoadDLLs.Add("libwebp.dll");
        PublicDelayLoadDLLs.Add("libwebpdecoder.dll");
        PublicDelayLoadDLLs.Add("libwebpdemux.dll");
        PublicDelayLoadDLLs.Add("libwebpmux.dll");
        PublicDelayLoadDLLs.Add("libxml2.dll");
        PublicDelayLoadDLLs.Add("lz4.dll");
        PublicDelayLoadDLLs.Add("openjp2.dll");
        PublicDelayLoadDLLs.Add("tiff.dll");
        PublicDelayLoadDLLs.Add("turbojpeg.dll");
        PublicDelayLoadDLLs.Add("zlib1.dll");
        PublicDelayLoadDLLs.Add("zstd.dll");
        PublicDelayLoadDLLs.Add("leptonica-1.83.1.dll");
        PublicDelayLoadDLLs.Add("tesseract53.dll");

        RuntimeDependencies.Add("$(BinaryOutputDir)/archive.dll", Path.Combine(ModuleDirectory, "OCR", "bin", "archive.dll"));
        RuntimeDependencies.Add("$(BinaryOutputDir)/bz2.dll", Path.Combine(ModuleDirectory, "OCR", "bin", "bz2.dll"));
        RuntimeDependencies.Add("$(BinaryOutputDir)/charset-1.dll", Path.Combine(ModuleDirectory, "OCR", "bin", "charset-1.dll"));
        RuntimeDependencies.Add("$(BinaryOutputDir)/gif.dll", Path.Combine(ModuleDirectory, "OCR", "bin", "gif.dll"));
        RuntimeDependencies.Add("$(BinaryOutputDir)/iconv-2.dll", Path.Combine(ModuleDirectory, "OCR", "bin", "iconv-2.dll"));
        RuntimeDependencies.Add("$(BinaryOutputDir)/jpeg62.dll", Path.Combine(ModuleDirectory, "OCR", "bin", "jpeg62.dll"));
        RuntimeDependencies.Add("$(BinaryOutputDir)/legacy.dll", Path.Combine(ModuleDirectory, "OCR", "bin", "legacy.dll"));
        RuntimeDependencies.Add("$(BinaryOutputDir)/libcrypto-3-x64.dll", Path.Combine(ModuleDirectory, "OCR", "bin", "libcrypto-3-x64.dll"));
        RuntimeDependencies.Add("$(BinaryOutputDir)/libcurl.dll", Path.Combine(ModuleDirectory, "OCR", "bin", "libcurl.dll"));
        RuntimeDependencies.Add("$(BinaryOutputDir)/liblzma.dll", Path.Combine(ModuleDirectory, "OCR", "bin", "liblzma.dll"));
        RuntimeDependencies.Add("$(BinaryOutputDir)/libpng16.dll", Path.Combine(ModuleDirectory, "OCR", "bin", "libpng16.dll"));
        RuntimeDependencies.Add("$(BinaryOutputDir)/libsharpyuv.dll", Path.Combine(ModuleDirectory, "OCR", "bin", "libsharpyuv.dll"));
        RuntimeDependencies.Add("$(BinaryOutputDir)/libssl-3-x64.dll", Path.Combine(ModuleDirectory, "OCR", "bin", "libssl-3-x64.dll"));
        RuntimeDependencies.Add("$(BinaryOutputDir)/libwebp.dll", Path.Combine(ModuleDirectory, "OCR", "bin", "libwebp.dll"));
        RuntimeDependencies.Add("$(BinaryOutputDir)/libwebpdecoder.dll", Path.Combine(ModuleDirectory, "OCR", "bin", "libwebpdecoder.dll"));
        RuntimeDependencies.Add("$(BinaryOutputDir)/libwebpdemux.dll", Path.Combine(ModuleDirectory, "OCR", "bin", "libwebpdemux.dll"));
        RuntimeDependencies.Add("$(BinaryOutputDir)/libwebpmux.dll", Path.Combine(ModuleDirectory, "OCR", "bin", "libwebpmux.dll"));
        RuntimeDependencies.Add("$(BinaryOutputDir)/libxml2.dll", Path.Combine(ModuleDirectory, "OCR", "bin", "libxml2.dll"));
        RuntimeDependencies.Add("$(BinaryOutputDir)/lz4.dll", Path.Combine(ModuleDirectory, "OCR", "bin", "lz4.dll"));
        RuntimeDependencies.Add("$(BinaryOutputDir)/openjp2.dll", Path.Combine(ModuleDirectory, "OCR", "bin", "openjp2.dll"));
        RuntimeDependencies.Add("$(BinaryOutputDir)/tiff.dll", Path.Combine(ModuleDirectory, "OCR", "bin", "tiff.dll"));
        RuntimeDependencies.Add("$(BinaryOutputDir)/turbojpeg.dll", Path.Combine(ModuleDirectory, "OCR", "bin", "turbojpeg.dll"));
        RuntimeDependencies.Add("$(BinaryOutputDir)/zlib1.dll", Path.Combine(ModuleDirectory, "OCR", "bin", "zlib1.dll"));
        RuntimeDependencies.Add("$(BinaryOutputDir)/zstd.dll", Path.Combine(ModuleDirectory, "OCR", "bin", "zstd.dll"));
        RuntimeDependencies.Add("$(BinaryOutputDir)/leptonica-1.83.1.dll", Path.Combine(ModuleDirectory, "OCR", "bin", "leptonica-1.83.1.dll"));
        RuntimeDependencies.Add("$(BinaryOutputDir)/tesseract53.dll", Path.Combine(ModuleDirectory, "OCR", "bin", "tesseract53.dll"));

        PublicDelayLoadDLLs.Add("libleptonica.so");
        RuntimeDependencies.Add("$(BinaryOutputDir)/libleptonica.so", Path.Combine(ModuleDirectory, "OCR-Linux", "bin", "libleptonica.so"));
        PublicDelayLoadDLLs.Add("liblept.so");
        RuntimeDependencies.Add("$(BinaryOutputDir)/liblept.so", Path.Combine(ModuleDirectory, "OCR-Linux", "bin", "liblept.so"));

        // Uncomment if you are using Slate UI
        // PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        // Uncomment if you are using online features
        // PrivateDependencyModuleNames.Add("OnlineSubsystem");

        // To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
    }
}
