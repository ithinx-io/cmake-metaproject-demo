include(GNUInstallDirs)

# -- Set the target's name (probably the same as the project's name)
set(TARGET ${PROJECT_NAME})

# -- Add target as library or executable
add_executable(${TARGET} "")

# -- Additional compile definitions
target_compile_definitions(
  ${TARGET}
  PRIVATE
    "COMPONENT=\"${TARGET}\"")

# -- Source files
target_sources(${TARGET}
  PRIVATE
    # sources
    ${CMAKE_CURRENT_LIST_DIR}/main.cpp
    ${CMAKE_CURRENT_LIST_DIR}/myapp.cpp
    # headers
    ${CMAKE_CURRENT_LIST_DIR}/myapp.h)

# -- Include directories
target_include_directories(${TARGET}
  PUBLIC
    $<INSTALL_INTERFACE:include>
  PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    ${CMAKE_CURRENT_LIST_DIR}
    ${CMAKE_CURRENT_BINARY_DIR})

# -- Library dependencies
target_link_libraries(${TARGET}
  PRIVATE
    ::mylib0)

# -- Installation setup
install(
  TARGETS ${TARGET}
  EXPORT ${TARGET}_targets
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR} COMPONENT exec)
