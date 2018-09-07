cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

project(astaireopenvpn)

INCLUDE(CheckLibraryExists)

# CXX11
set (CMAKE_CXX_STANDARD 11)
set(VERSION "0.1")

# Globally setting this as additional include directories
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/openvpn3
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/asio
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/
    )

# Where astaireopenvpn will be installed
set(CMAKE_INSTALL_BINDIR bin)
add_subdirectory("${astaireopenvpn_SOURCE_DIR}/src/")

# Don't want compilation in source dir
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)
set(CMAKE_DISABLE_SOURCE_CHANGES  ON)
if(",${CMAKE_SOURCE_DIR}," STREQUAL ",${CMAKE_BINARY_DIR},")
    message(FATAL_ERROR "ERROR: In-source builds are not allowed.")
endif()

# Create config.h for extra compiler macros
configure_file(
    "${astaireopenvpn_SOURCE_DIR}/src/config.h.in"
    "${CMAKE_BINARY_DIR}/src/config.h"
    @ONLY
)
