# Specify Minimum Required Version
cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

# Specify Project and Language
project(cpp_compile_time LANGUAGES CXX)

# For Clang:
if(CMAKE_CXX_COMPILER_ID MATCHES GNU)
	set(EXTRA_COMPILE_FLAGS "-fconstexpr-loop-limit=10000 -fconstexpr-ops-limit=1000000000")
elseif(CMAKE_CXX_COMPILER_ID MATCHES Clang)
	set(EXTRA_COMPILE_FLAGS "-fconstexpr-steps=100000000")
endif()
set_source_files_properties(app/test_mandelbrot.cpp PROPERTIES COMPILE_FLAGS ${EXTRA_COMPILE_FLAGS})

# Set Include Directory
include_directories(include)

# Add Executable Program
add_executable(test_cexpr_basic_string app/test_cexpr_basic_string.cpp)
add_executable(test_mandelbrot app/test_mandelbrot.cpp)
add_executable(test_cexpr_math app/test_cexpr_math.cpp)
add_executable(test_biquad_filter app/test_biquad_filter.cpp)
