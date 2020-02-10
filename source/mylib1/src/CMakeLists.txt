include(GNUInstallDirs)
include(CMakePackageConfigHelpers)
include(GenerateExportHeader)

# -- Set the target's name (probably the same as the project's name)
set(TARGET ${PROJECT_NAME})

# -- Add target as shared library
add_library(${TARGET} SHARED "")

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

# -- Additional compile definitions
target_compile_definitions(
  ${TARGET}
  PRIVATE
    "COMPONENT=\"${TARGET}\"")

# -- Source files
target_sources(${TARGET}
  PRIVATE
    # sources
    ${CMAKE_CURRENT_LIST_DIR}/mylib1.cpp
    # headers
    ${CMAKE_CURRENT_LIST_DIR}/mylib1-defs.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/${TARGET}.h)

# -- Public headers
set(${TARGET}_PUBLIC_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/include/${TARGET}.h)

# -- Include directories
target_include_directories(${TARGET}
  PUBLIC
    $<INSTALL_INTERFACE:include>
  PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    ${CMAKE_CURRENT_LIST_DIR}
    ${CMAKE_CURRENT_BINARY_DIR})

# -- Library dependencies
#target_link_libraries(${TARGET}
#  PRIVATE

# -- Generate and append export header
generate_export_header(${TARGET})
list(APPEND ${TARGET}_PUBLIC_HEADERS ${CMAKE_CURRENT_BINARY_DIR}/${TARGET}_export.h)

# -- Symbol visibility and public headers
set_target_properties(${TARGET}
  PROPERTIES
    CXX_VISIBILITY_PRESET hidden
    VISIBILITY_INLINES_HIDDEN 1
    PUBLIC_HEADER "${${TARGET}_PUBLIC_HEADERS}")

# -- Installation setup
install(TARGETS ${TARGET}
  EXPORT ${TARGET}_targets
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} COMPONENT shlib
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${TARGET} COMPONENT Development
  INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${TARGET})

# -- Create cmake config files for find_package(<...> CONFIG <...>)
set(ConfigPackageLocation ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME})

configure_package_config_file(
  ${PROJECT_NAME}-config.cmake.in
  ${PROJECT_BINARY_DIR}/${PROJECT_NAME}-config.cmake
  INSTALL_DESTINATION ${ConfigPackageLocation})

install(
  EXPORT ${PROJECT_NAME}_targets
  FILE ${PROJECT_NAME}-targets.cmake
  NAMESPACE ${CONFIG_NAMESPACE_CMAKE}::
  DESTINATION ${ConfigPackageLocation})

install(
  FILES ${PROJECT_BINARY_DIR}/${PROJECT_NAME}-config.cmake
  DESTINATION ${ConfigPackageLocation}
  COMPONENT Development)
