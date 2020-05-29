# Specify Minimum Required Version
cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

# Specify Project and Language
project(cpp_compile_time LANGUAGES CXX)

# Set Include Directory
include_directories(include)

# Add Executable Program
add_executable(test_cexpr_basic_string app/test_cexpr_basic_string.cpp)
