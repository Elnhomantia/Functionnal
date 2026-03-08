cmake_minimum_required(VERSION 3.16)

project(option VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(TARGET_NAME ${PROJECT_NAME})
set(EXPORT_NAME ${PROJECT_NAME}Targets)
set(CONFIG_NAME ${PROJECT_NAME}Config)
set(INSTALL_NAMESPACE Elth)

add_library(${TARGET_NAME} INTERFACE)

target_include_directories(${TARGET_NAME} INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/${INSTALL_NAMESPACE}/functionnal>
)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

install(FILES ${PROJECT_NAME}.h
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${INSTALL_NAMESPACE}/functionnal
        RENAME ${TARGET_NAME})

install(TARGETS ${TARGET_NAME} EXPORT ${EXPORT_NAME})

install(EXPORT ${EXPORT_NAME}
        FILE ${EXPORT_NAME}.cmake
        NAMESPACE ${INSTALL_NAMESPACE}::
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${TARGET_NAME})

write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/${CONFIG_NAME}Version.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/${CONFIG_NAME}.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${TARGET_NAME}
)

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/${CONFIG_NAME}.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/${CONFIG_NAME}Version.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${TARGET_NAME}
)

# ============ Tests ============

add_subdirectory(tests)
