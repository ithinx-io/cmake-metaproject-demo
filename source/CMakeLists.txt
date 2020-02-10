cmake_minimum_required(VERSION 3.5)

project(mymetaproject)
include(ExternalProject)

# ----------------------------------------------------------------------
#         Define common cmake arguments (pathes, options, ...)
# ----------------------------------------------------------------------
set(base_path "${CMAKE_CURRENT_LIST_DIR}/..")
list(APPEND common_cmake_args
     "-DCMAKE_PREFIX_PATH=${base_path}/sysroot")
list(APPEND common_cmake_args
     "-DCMAKE_INSTALL_PREFIX=${base_path}/sysroot/usr")

# ----------------------------------------------------------------------
#           Component and dependency definition helpers
# ----------------------------------------------------------------------
function(AddComponent target #[[optional cmake args]])
  set(opt_cmake_args ${ARGN})
  ExternalProject_Add(${target}
    PREFIX ${base_path}/build/${target}/report
    SOURCE_DIR ${base_path}/source/${target}
    BINARY_DIR ${base_path}/build/${target}
    BUILD_COMMAND make -j$(nproc)
    BUILD_ALWAYS true
    LIST_SEPARATOR |
    CMAKE_ARGS -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
               ${common_cmake_args}               
               ${opt_cmake_args})
endfunction()

function(AddDependencies target #[[optional dependency list]])
  if(NOT ARGN STREQUAL "")
    ExternalProject_Add_StepDependencies(${target} build ${ARGN})
  endif()
endfunction()

# ----------------------------------------------------------------------
#            Define components to use (order doesn't matter)
# ----------------------------------------------------------------------
AddComponent(myapp)
AddComponent(mylib0)
AddComponent(mylib1)

# ----------------------------------------------------------------------
#      Define component build dependencies (order doesn't matter)
# ----------------------------------------------------------------------
# libraries
AddDependencies(mylib0 mylib1)

# executables
AddDependencies(myapp mylib0)
