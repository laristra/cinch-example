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

#------------------------------------------------------------------------------#
# Keep users from creating insource builds.
# This script is in cmake/insource.cmake
#------------------------------------------------------------------------------#

prevent_insource_builds()

#------------------------------------------------------------------------------#
# Test project to demonstrate cmake configuration
#------------------------------------------------------------------------------#

project(test)

  # Version informaiton
  set(test_VERSION_MAJOR 1)
  set(test_VERSION_MINOR 0)
  set(test_VERSION_PATCH 1)

  # Global project settings
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)
  set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY lib)
  set(CMAKE_LIBRARY_OUTPUT_DIRECTORY lib)

  add_subdirectory(src)
  include_directories(${ngc_INCDIRS})

  # Add a rule to build the library
  add_library(ngc SHARED ${ngc_SOURCES} ${ngc_HEADERS})

  # Add a rule to build the executable
  add_executable(app src/app/app.cc)
  target_link_libraries(app ngc ${EXTRA_LIBS})

  # Generate info file for main library
  make_info(main "${ngc_HEADERS}" "${ngc_SOURCES}")

#  add_custom_target(info cat .main.buildinfo)
#  add_custom_target(distclean rm -rf ${CMAKE_BINARY_DIR}/*)

# project

#------------------------------------------------------------------------------#
# Formatting options for emacs and vim.
# vim: set tabstop=2 shiftwidth=2 expandtab :
#------------------------------------------------------------------------------#
