workspace "MatUTM"
	architecture "x64"
	startproject "MatUTM"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "MatUTM/vendor/GLFW/include"
IncludeDir["Glad"] = "MatUTM/vendor/Glad/include"
IncludeDir["ImGui"] = "MatUTM/vendor/imgui"
IncludeDir["glm"] = "MatUTM/vendor/glm"


group "Dependencies"
	include "MatUTM/vendor/GLFW"
	include "MatUTM/vendor/Glad"
	include "MatUTM/vendor/imgui"
group ""



function queryTerminal(command)
    local success, handle = pcall(io.popen, command)
    if not success then 
        return ""
    end
    result = handle:read("*a")
    handle:close()
    result = string.gsub(result, "\n$", "") -- remove trailing whitespace
    return result
end
function getPythonPath()
    local p = queryTerminal('python -c "import sys; import os; print(os.path.dirname(sys.executable))"')
    -- sanitize path before returning it
    p = string.gsub(p, "\\\\", "\\") -- replace double backslash
    p = string.gsub(p, "\\", "/") -- flip slashes
    return p
end
function getPythonLib()
    return queryTerminal("python -c \"import sys; import os; import glob; path = os.path.dirname(sys.executable); libs = glob.glob(path + '/libs/python*'); print(os.path.splitext(os.path.basename(libs[-1]))[0]);\"")
end


------------------------------
-----  %{prj.name} lib-------------
------------------------------
project "MatUTM"
	location "%{prj.name}"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"
	flags       { "MultiProcessorCompile" }

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "mathpch.h"
	pchsource "MatUTM/src/mathpch.cpp"



	
	pythonPath      = getPythonPath()
	pythonIncludePath = pythonPath .. "/include/"
	pythonLibPath     = pythonPath .. "/libs/"
	pythonLib         = getPythonLib()

	if pythonPath == "" or pythonLib == "" then
	    error("Failed to find python path!")
	else
	    print("Python includes: " .. pythonIncludePath)
	    print("Python libs: " .. pythonLibPath)
	    print("lib: " .. pythonLib)
	end




	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/stb_image/**.h",
		"%{prj.name}/vendor/stb_image/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl",

	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/vendor/pybind11/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}",
		pythonIncludePath,
	}
	libdirs{
		pythonLibPath
	}

	

	links 
	{ 
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib",
		pythonLib
	}


	--if os.host() == "windows" then
    --    cppdialect "C++17"
    --    systemversion("latest")
    --    system      "windows"
    --   
--
    --    symbolspath '$(TargetName).pdb'
    --    libdirs     { pythonLibPath }
    --    links { pythonLib }
--
	--	end

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "BR_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "BR_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "BR_DIST"
		runtime "Release"
		optimize "on"






