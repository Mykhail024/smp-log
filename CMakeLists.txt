cmake_minimum_required(VERSION 4.0)

project(smp-log
  VERSION 0.1.0
  DESCRIPTION "Simple header-only C++ logging library"
  LANGUAGES CXX
)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

option(SMP_LOG_BUILD_EXAMPLES "Build examples" ON)

add_library(smp-log INTERFACE)
add_library(smp::log ALIAS smp-log)
set_target_properties(smp-log PROPERTIES EXPORT_NAME log)

target_compile_features(smp-log INTERFACE cxx_std_20)

target_include_directories(smp-log
  INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

target_sources(smp-log
  INTERFACE
    FILE_SET HEADERS
    BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/include
    FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/smp/log.hpp
)

install(TARGETS smp-log
    EXPORT smp-logTargets
    FILE_SET HEADERS DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(EXPORT smp-logTargets
    FILE smp-logTargets.cmake
    NAMESPACE smp::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/smp-log
)

configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/smp-logConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/smp-logConfig.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/smp-log
)

write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/smp-logConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/smp-logConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/smp-logConfigVersion.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/smp-log
)

