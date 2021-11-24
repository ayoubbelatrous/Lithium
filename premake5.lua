workspace "Lithium"
	architecture "x86"
	startproject "Isotope"

	configurations
	{
		"Debug",
		"Release"
	}
	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["glfw"] = "%{wks.location}/Lithium/dep/glfw/include"
IncludeDir["glew"] = "%{wks.location}/Lithium/dep/glew/include"
IncludeDir["imgui"] = "%{wks.location}/Lithium/src/vendor/imgui"
IncludeDir["glm"] = "%{wks.location}/Lithium/dep/glm/glm"
IncludeDir["stb"] = "%{wks.location}/Lithium/src/vendor/stb"
IncludeDir["imguizmo"] = "%{wks.location}/Lithium/src/vendor/imguizmo"

project "Lithium"
     location "Lithium"
     Kind "Staticlib"
     language "C++"
     targetdir "bin/%{cfg.buildcfg}/%{prj.name}"
	 objdir "bin-int/%{cfg.buildcfg}/%{prj.name}"

	files
	{
		"%{prj.location}/src/**.h",
		"%{prj.location}/src/**.cpp",
	}

	links
	{
		"%{wks.location}glfw.lib",
		"%{wks.location}glew.lib",
		"opengl32.lib"
	}
