cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(compile_time LANGUAGES CXX)

option(ENABLE_EXTRAS "Enable extras" false)
option(DISABLE_CONSTEXPR "Disable constexpr" false)
option(BIG_MANDELBROT "Big Mandelbrot" false)

#include(Sanitizers.cmake)

#find_package(Boost REQUIRED COMPONENTS math)
find_package(Catch2 REQUIRED)

set(CMAKE_VERBOSE_MAKEFILE true)
set(CMAKE_EXPORT_COMPILE_COMMANDS true)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

if (CMAKE_CXX_COMPILER_ID MATCHES GNU OR
  CMAKE_CXX_COMPILER_ID MATCHES Clang)
	add_compile_options("-pedantic-errors")
endif()

if (BIG_MANDELBROT)
	set(MANDELBROT_DEFINES "MANDELBROT_WIDTH=512" "MANDELBROT_HEIGHT=512")
endif()

if (CMAKE_CXX_COMPILER_ID MATCHES GNU)
	set(EXTRA_COMPILE_FLAGS "-fconstexpr-loop-limit=10000 -fconstexpr-ops-limit=1000000000")
elseif (CMAKE_CXX_COMPILER_ID MATCHES Clang)
	set(EXTRA_COMPILE_FLAGS "-fconstexpr-steps=100000000")
endif()

if (DISABLE_CONSTEXPR)
	add_definitions(
	  "-DRA_CEXPR_BASIC_STRING_USE_CONSTEXPR=0"
	  "-DTEST_CEXPR_BASIC_STRING_USE_CONSTEXPR=0"
	  "-DRA_CEXPR_MATH_USE_CONSTEXPR=0"
	  "-DTEST_CEXPR_MATH_USE_CONSTEXPR=0"
	  "-DRA_BIQUAD_USE_CONSTEXPR=0"
	  "-DTEST_BIQUAD_USE_CONSTEXPR=0"
	)
endif()

message(STATUS "CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS}")
message(STATUS "EXTRA_COMPILE_FLAGS ${EXTRA_COMPILE_FLAGS}")
message(STATUS "MANDELBROT_DEFINES ${MANDELBROT_DEFINES}")

set(STRING_FOUND 0)
if(EXISTS ${CMAKE_SOURCE_DIR}/include/ra/cexpr_basic_string.hpp AND
  EXISTS ${CMAKE_SOURCE_DIR}/include/ra/mandelbrot.hpp)
	set(STRING_FOUND 1)
endif()
message(STATUS "string found: ${STRING_FOUND}")

set(MATH_FOUND 0)
if(EXISTS ${CMAKE_SOURCE_DIR}/include/ra/biquad_filter.hpp AND
  EXISTS ${CMAKE_SOURCE_DIR}/include/ra/cexpr_math.hpp)
	set(MATH_FOUND 1)
endif()
message(STATUS "math found: ${MATH_FOUND}")

add_library(ra INTERFACE)
target_include_directories(ra INTERFACE include)
#target_link_libraries(ra INTERFACE Boost::boost)

if (STRING_FOUND)
	set_source_files_properties(app/test_mandelbrot.cpp PROPERTIES
	  COMPILE_FLAGS ${EXTRA_COMPILE_FLAGS})
	set_source_files_properties(app/test_mandelbrot.cpp PROPERTIES
	  COMPILE_DEFINITIONS "${MANDELBROT_DEFINES}")
	add_executable(test_mandelbrot app/test_mandelbrot.cpp)
	add_executable(test_cexpr_basic_string app/test_cexpr_basic_string.cpp)
	target_link_libraries(test_mandelbrot ra)
	target_link_libraries(test_cexpr_basic_string ra Catch2::Catch2)
	if(ENABLE_EXTRAS)
		set_source_files_properties(app/trivial_mandelbrot.cpp PROPERTIES
		  COMPILE_FLAGS ${EXTRA_COMPILE_FLAGS})
		set_source_files_properties(app/trivial_mandelbrot.cpp PROPERTIES
		  COMPILE_DEFINITIONS "${MANDELBROT_DEFINES}")
		add_executable(trivial_mandelbrot app/trivial_mandelbrot.cpp)
		target_link_libraries(trivial_mandelbrot ra)
		add_executable(trivial_cexpr_basic_string
		  app/trivial_cexpr_basic_string.cpp)
		target_link_libraries(trivial_cexpr_basic_string ra)
	endif()
endif()

if(MATH_FOUND)
	add_executable(test_cexpr_math app/test_cexpr_math.cpp)
	target_link_libraries(test_cexpr_math ra Catch2::Catch2)
	add_executable(test_biquad_filter app/test_biquad_filter.cpp)
	target_link_libraries(test_biquad_filter ra Catch2::Catch2)
	if(ENABLE_EXTRAS)
		add_executable(demo_biquad_filter app/demo_biquad_filter.cpp)
		target_link_libraries(demo_biquad_filter ra)
		add_executable(trivial_cexpr_math app/trivial_cexpr_math.cpp)
		target_link_libraries(trivial_cexpr_math ra)
		add_executable(demo_cexpr_math app/demo_cexpr_math.cpp)
		target_link_libraries(demo_cexpr_math ra)
		add_executable(trivial_biquad_filter app/trivial_biquad_filter.cpp)
		target_link_libraries(trivial_biquad_filter ra)
	endif()
endif()

#if (ENABLE_EXTRAS)
#	add_test(test_mandelbrot test_mandelbrot)
#	add_test(test_cexpr_basic_string test_cexpr_basic_string)
#	enable_testing()
#endif()
