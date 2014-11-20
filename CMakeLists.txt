#------------------------------------------------------------------------------#
# Copyright (c) 2014 Los Alamos National Security, LLC
# All rights reserved.
#------------------------------------------------------------------------------#

#------------------------------------------------------------------------------#
# Require some version of cmake
#------------------------------------------------------------------------------#

cmake_minimum_required(VERSION 2.8.12)

#------------------------------------------------------------------------------#
# Add path for local modules
#------------------------------------------------------------------------------#

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

#------------------------------------------------------------------------------#
# CMake includes
#------------------------------------------------------------------------------#

include(info)
include(insource)

#----------------------------------------------------------------------------#
# Keep users from creating insource builds.
# This script is in cmake/insource.cmake
#----------------------------------------------------------------------------#

prevent_insource_builds()

#----------------------------------------------------------------------------#
# Add top-level targets
#----------------------------------------------------------------------------#
  
if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR})
    add_custom_target(distclean rm -rf ${CMAKE_BINARY_DIR}/*)
    set(NGC_CONFIG_INFOTAG)
else()
    set(NGC_CONFIG_INFOTAG "libtest")
endif(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR})

#------------------------------------------------------------------------------#
# Test project to demonstrate cmake configuration
#------------------------------------------------------------------------------#

project(libtest)

# Version informaiton
set(libtest_VERSION_MAJOR 1)
set(libtest_VERSION_MINOR 0)
set(libtest_VERSION_PATCH 1)

# Global project settings
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

add_subdirectory(src)
include_directories(${libtest_INCDIRS})

# Add a rule to build the library
add_library(libtest SHARED ${libtest_SOURCES} ${libtest_HEADERS})

# Add a rule to build the executable
add_executable(app src/app/app.cc)
target_link_libraries(app libtest ${EXTRA_LIBS})

# Generate info file for libtest library
make_info(libtest "${libtest_HEADERS}" "${applib_SOURCES}")

#------------------------------------------------------------------------------#
# Formatting options for emacs and vim.
# vim: set tabstop=4 shiftwidth=4 expandtab :
#------------------------------------------------------------------------------#
