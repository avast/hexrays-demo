cmake_minimum_required(VERSION 3.6)

project(hexrays-demo CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")

# Check that obligatory parameters were defined.
if(NOT IDA_SDK_DIR)
	message(FATAL_ERROR "Path to IDA SDK was not specified. "
		"Use -DIDA_SDK_DIR=<path>.")
endif()
if(NOT EXISTS "${IDA_SDK_DIR}")
	message(FATAL_ERROR "Specified IDA SDK path does not exist.")
endif()

if(NOT IDA_DIR)
	message(WARNING "Path to IDA was not specified. "
		"Use -DIDA_DIR=<path> if you want to install the plugin.")
endif()

# Build parameters.
if(MSVC) # Windows
	# Disable warnings (there are too many of them, including warnings from
	# third-party libraries, which cannot be selectively disabled when using MSVC).
	string(REGEX REPLACE "/W[0-4]" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W0")

	# Disable the min() and max() macros to prevent errors when using e.g.
	# std::numeric_limits<...>::max()
	# (http://stackoverflow.com/questions/1904635/warning-c4003-and-errors-c2589-and-c2059-on-x-stdnumeric-limitsintmax).
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /DNOMINMAX")
elseif(UNIX) # Linux or macOS
	# Common options.
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wextra")

	# Ignore the following warnings (they are not fixable).
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-format")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-unused-parameter")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-non-virtual-dtor")

	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
else()
	message(FATAL_ERROR "Unsupported system type: ${CMAKE_SYSTEM_NAME}")
endif()

# Global defines.
add_definitions(-D__IDP__ -D__PLUGIN__ -DNO_OBSOLETE_FUNCS)
add_definitions(-D__X64__)
if(WIN32)
	add_definitions(-D__NT__)
elseif(APPLE)
	add_definitions(-D__MAC__)
elseif(UNIX) # APPLE is also UNIX, so it MUST be before this elseif().
	add_definitions(-D__LINUX__)
else()
	message(FATAL_ERROR "Unsupported system type: ${CMAKE_SYSTEM_NAME}")
endif()

# IDA SDK libs.
if(WIN32)
	set(idasdk_ea32 "${IDA_SDK_DIR}/lib/x64_win_vc_32/ida.lib")
	set(idasdk_ea64 "${IDA_SDK_DIR}/lib/x64_win_vc_64/ida.lib")
elseif(APPLE)
	set(idasdk_ea32 "${IDA_SDK_DIR}/lib/x64_mac_gcc_32/libida.dylib")
	set(idasdk_ea64 "${IDA_SDK_DIR}/lib/x64_mac_gcc_64/libida64.dylib")
elseif(UNIX) # APPLE is also UNIX, so it MUST be before this elseif().
	set(idasdk_ea32 "${IDA_SDK_DIR}/lib/x64_linux_gcc_32/libida.so")
	set(idasdk_ea64 "${IDA_SDK_DIR}/lib/x64_linux_gcc_64/libida64.so")
else()
	message(FATAL_ERROR "Unsupported system type: ${CMAKE_SYSTEM_NAME}")
endif()

# Includes.
include_directories(SYSTEM
	"${IDA_SDK_DIR}/include" # Make IDA SDK includes work.
)

# Sources
set(DEMO_SOURCES
	context.cpp
	decompiler.cpp
	function.cpp
	demo.cpp
	place.cpp
	token.cpp
	ui.cpp
	yx.cpp
)

# Libs.
add_library(demo32 SHARED ${DEMO_SOURCES})
add_library(demo64 SHARED ${DEMO_SOURCES})

target_compile_definitions(demo64 PUBLIC __EA64__)

target_link_libraries(demo32 jsoncpp ${idasdk_ea32})
target_link_libraries(demo64 jsoncpp ${idasdk_ea64})

if(MSYS)
	target_link_libraries(demo32 ws2_32)
	target_link_libraries(demo64 ws2_32)
endif()

set_target_properties(demo32 PROPERTIES PREFIX "")
set_target_properties(demo64 PROPERTIES PREFIX "")
set_target_properties(demo32 PROPERTIES OUTPUT_NAME "hexrays-demo")
set_target_properties(demo64 PROPERTIES OUTPUT_NAME "hexrays-demo64")

# Installation.
if(IDA_DIR)
	install(TARGETS demo32 demo64
		LIBRARY DESTINATION "${IDA_DIR}/plugins/"
		RUNTIME DESTINATION "${IDA_DIR}/plugins/"
	)
endif()
