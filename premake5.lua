-- Box2D premake script.
-- http://industriousone.com/premake

project "box2D"
	language "C++"
	kind "staticlib"

	files { "include/**.h", "src/**.cpp" }
    
    includedirs { "include" }
    
	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"
        


		
