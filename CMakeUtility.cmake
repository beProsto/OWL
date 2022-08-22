# Determines the System
if(EMSCRIPTEN)
	set(OWL_SYSTEM_EMSCRIPTEN TRUE)

elseif(WIN32)
	set(OWL_SYSTEM_WINDOWS TRUE)

elseif(UNIX)
	set(OWL_SYSTEM_LINUX TRUE)

endif()


# Determines if the library is statically compiled
if(LIBTYPE STREQUAL "STATIC")
	set(OWL_BUILD_STATIC TRUE)

endif()


# Determines the preffered windowing subsystem on linux
if(DISABLE_WAYLAND STREQUAL "YES")
	set(OWL_WAYLAND_OFF TRUE)
	set(OWL_X11_ON TRUE)

elseif(DISABLE_X11 STREQUAL "YES")
	set(OWL_WAYLAND_ON TRUE)
	set(OWL_X11_OFF TRUE)

endif()


# Determines if building examples is enabled
if(BUILD_EXAMPLES STREQUAL "NO")
	set(OWL_EXAMPLES_OFF TRUE)

else()
	set(OWL_EXAMPLES_ON TRUE)

endif()


# Sets the executable type
if(OWL_SYSTEM_WINDOWS)
	set(OWL_EXE_TYPE WIN32)

else()
	set(OWL_EXE_TYPE )

endif()


# Generates a basic html file for our emscripten/wasm build targets (examples)
function(OWL_GenerateHtml name)
	set(base 
		"<meta charset=\"utf-8\">"
		"<title>OWL ${name}</title>"
		"<canvas id=\"canvas\" style=\"position:absolute\;top:0px\;left:0px\;margin:0px\;border:0\;width:100%\;height:100%\;overflow:hidden\;display:block\;\"></canvas>"
		"<script>var Module={"
			"print:(t)=>{console.log(t)},"
			"printErr:(text)=>{"
				"if(arguments.length>1)text=Array.prototype.slice.call(arguments).join(' ')\;"
				"if(0){dump(text+'\\n')}"
			"},"
			"canvas:(()=>{"
				"var canvas=document.getElementById('canvas')\;"
				"return canvas"
			"})()"
		"}\;</script>"
		
		"<script src=\"./${name}.js\"></script>"
	)

	file(WRITE ${CMAKE_BINARY_DIR}/${name}.html ${base})
endfunction()


# Adds an executable target for our examples
function(OWL_AddExample name)
	file(GLOB_RECURSE ${name}_srcs
		"examples/${name}/*.hpp"
		"examples/${name}/*.cpp"
	)

	add_executable(${name} ${OWL_EXE_TYPE} ${${name}_srcs})

	if(OWL_BUILD_STATIC)
		target_compile_definitions(${name} PRIVATE OWL_BUILD_STATIC)
	endif()

	if(OWL_SYSTEM_EMSCRIPTEN)
		OWL_GenerateHtml(${name})
	endif()
endfunction()