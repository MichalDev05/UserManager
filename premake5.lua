workspace "UserManager"
    architecture "x64"
    configurations{
        "Debug",
        "Release"
    }
    
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "UserManager"
    location "UserManager"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files{
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
        "%{prj.name}/src",
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

    filter "configurations:Debug"
        defines "CF_DEBUG"
        buildoptions "/MDd"
        symbols "On"
        
        filter "configurations:Release"
        defines "CF_RELEASE"
        buildoptions "/MD"
        optimize "On"