# This project requires at least CMake version 4.3.3 to run
cmake_minimum_required(VERSION 4.3.3)

# The name and version of the project
# Languages are C and C++
project(CppProjectTemplate VERSION 1.0.0 LANGUAGES C CXX)

# The syntax is (name the_source_file_that_will_be_compiled)
add_executable(Executable main.cc)

# To use this file:
# cd build
# cmake ..
# cmake --build .
# ./Executable
