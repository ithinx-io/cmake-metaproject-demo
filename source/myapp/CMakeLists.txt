# -- Minimum required version
cmake_minimum_required(VERSION 3.5.1)

# -- Project name
project(myapp)

# -- C++ standard
set(CMAKE_CXX_STANDARD 17)

# -- Dependencies
find_package(mylib0 CONFIG REQUIRED)

include(src/CMakeLists.txt)
