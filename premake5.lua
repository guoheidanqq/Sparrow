workspace "Sparrow"
	architecture "x64"
	configurations
	{
	"Debug",
	"Release",
	"Dist"	
	}

TPDirs ={}
TPDirs["imgui"] = "ThirdPartySuppliers/imgui"



project "Imgui"
	location "Imgui"
	kind "StaticLib"
	language "C++"
	targetdir("x64/Debug")
	objdir("%{prj.name}/x64")

	files{
	"%{TPDirs.imgui}/imconfig.h",
	"%{TPDirs.imgui}/imgui.h",
	"%{TPDirs.imgui}/imgui_inernal.h",
	"%{TPDirs.imgui}/imstb_rectpack.h",
	"%{TPDirs.imgui}/imstb_textedit.h",
	"%{TPDirs.imgui}/imstb_truetype.h",
	"%{TPDirs.imgui}/imgui.cpp",
	"%{TPDirs.imgui}/imgui_demo.cpp",
	"%{TPDirs.imgui}/imgui_draw.cpp",
	"%{TPDirs.imgui}/imgui_tables.cpp",
	}

	filter "system:windows"
		systemversion "latest"
		staticruntime "On"
		cppdialect "C++17"

	filter "configurations:Debug"
		runtime "Debug"
		symbols "On"
	filter "configurations:Release"
		runtime "Release"
		optimize "On"



	



project "Glad"
	location "Glad"
	kind "StaticLib"
	language "C"
	targetdir("x64/Debug")
	objdir("Glad/x64/Debug")

	includedirs 
	{
	"ThirdPartySuppliers/glad/include"
	}

	files
	{
		"ThirdPartySuppliers/glad/include/glad.h",
		"ThirdPartySuppliers/glad/KHR/khrplatform.h",
		"ThirdPartySuppliers/glad/src/glad.c"
	}

	filter "system:windows"		
		staticruntime "On"		
		systemversion "latest"

	filter "configurations:Debug"
		symbols "On"
		



project "GLFW"
	location "GLFW"
	kind "ConsoleApp"
	language "C++"
	targetdir("x64/Debug")
	objdir("GLFW/x64/Debug")
	libdirs { "ThirdPartyBins/glfw/x64/Debug","ThirdPartyBins/glad/x64/Debug" }
	links{"Glad32","glfw3","OpenGL32","User32","Gdi32","Shell32"}

	files
	{
		"GLFW/src/**.h",
		"GLFW/src/**.cpp"
	}

	includedirs 
	{
	"ThirdPartySuppliers/glfw/include",
	"ThirdPartySuppliers/glad/include"
	
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "Off"
		inheritdependencies "Off"
		systemversion "latest"
		defines
		{		
		
		}



	filter "configurations:Debug"		
		defines "SPARROW_DEBUG"
		symbols "On"
		
		

	filter "configurations:Release"	    
		defines "SPARROW_RELEASE"
		optimize "On"
		

	filter "configurations:Dist"		
		defines "SPARROW_Dist"
		optimize "On"
		

project "Sparrow"
	location "Sparrow"
	kind "SharedLib"
	language "C++"
	targetdir("x64/Debug")
	objdir("Sparrow/x64/Debug")


	libdirs { "ThirdPartyBins/glfw/x64/Debug",
			"ThirdPartyBins/glad/x64/Debug",
			"ThirdPartyBins/imgui/x64/Debug" }
	links{"Imgui","Glad32","glfw3","OpenGL32","User32","Gdi32","Shell32"}

	files
	{
		"Sparrow/src/**.h",
		"Sparrow/src/**.cpp"
	}

	includedirs 
	{
	"ThirdPartySuppliers/spdlog/include",
	"ThirdPartySuppliers/glfw/include",
	"ThirdPartySuppliers/glad/include", 
	"ThirdPartySuppliers/imgui/src"
	}

	filter "system:windows"
		cppdialect "C++17"		
		systemversion "10.0.22621.0"

		defines
		{
		"SPARROW_DLLEXPORT",
		"_WINDLL"
		}
		
	filter "configurations:Debug"
		defines "SPARROW_DEBUG"
		symbols"On"

	filter "configurations:Release"
		defines "SPARROW_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "SPARROW_Dist"
		optimize "On"






project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	targetdir("x64/Debug")
	objdir("Sandbox/x64/Debug")

	links
	{
	"Sparrow"
	}

	files
	{
		"Sandbox/src/**.h",
		"Sandbox/src/**.cpp"
	}

	includedirs 
	{
	"ThirdPartySuppliers/spdlog/include",
	"Sparrow/src"
	}

	filter "system:windows"
		cppdialect "C++17"		
		systemversion "10.0.22621.0"

		defines
		{		
		
		}


	filter "configurations:Debug"
		defines "SPARROW_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "SPARROW_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "SPARROW_Dist"
		optimize "On"


