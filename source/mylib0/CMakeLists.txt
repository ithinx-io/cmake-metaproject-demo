# -- Minimum required version
cmake_minimum_required(VERSION 3.5.1)

# -- Project name
project(mylib0)

# -- C++ standard
set(CMAKE_CXX_STANDARD 17)

# -- Add your dependencies here
find_package(mylib1 CONFIG REQUIRED)

include(src/CMakeLists.txt)
