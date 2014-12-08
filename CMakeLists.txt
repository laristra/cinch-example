#------------------------------------------------------------------------------#
# Copyright (c) 2014 Los Alamos National Security, LLC
# All rights reserved.
#------------------------------------------------------------------------------#

project(libtest)

set(CINCH_APPLICATION_DIRECTORY "app")
set(CINCH_LIBRARY_TARGET "testlib")
set(CINCH_CONFIG_SUBPROJECTS)

# Version informaiton
set(${PROJECT_NAME}_VERSION_MAJOR 1)
set(${PROJECT_NAME}_VERSION_MINOR 0)
set(${PROJECT_NAME}_VERSION_PATCH 1)

################################################################################
# Please Do Not Edit Below Here Unless You Know What You Are Doing!!!
#
# Any changes to the basic build template should be discussed with the
# project maintainers.
################################################################################

#------------------------------------------------------------------------------#
# Require some version of cmake
#------------------------------------------------------------------------------#

cmake_minimum_required(VERSION 2.8.12)

#------------------------------------------------------------------------------#
# Add path for cinch modules
#------------------------------------------------------------------------------#

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cinch/cmake)

#------------------------------------------------------------------------------#
# CMake includes
#------------------------------------------------------------------------------#

include(info)
include(insource)
include(subdirlist)
include(unit)

#------------------------------------------------------------------------------#
# Keep users from creating insource builds.
# This script is in cmake/insource.cmake
#------------------------------------------------------------------------------#

cinch_prevent_insource_builds()

#------------------------------------------------------------------------------#
# Add top-level targets
#------------------------------------------------------------------------------#

if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR})

    #--------------------------------------------------------------------------#
    # This is a top-level build
    #--------------------------------------------------------------------------#

    add_custom_target(distclean rm -rf ${CMAKE_BINARY_DIR}/*)
    set(CINCH_CONFIG_INFOTAG)

    #--------------------------------------------------------------------------#
    # Add support for ctest
    #--------------------------------------------------------------------------#

    option(ENABLE_UNIT_TESTS "Enable unit testing" OFF)

    if(ENABLE_UNIT_TESTS)
        enable_testing()
        add_subdirectory(cinch/gtest)
        include_directories(cinch/gtest/include)
        add_custom_target(jenkins
            cmake -DCINCH_MODULE_DIR=${CMAKE_SOURCE_DIR}/cinch/cmake
                -P ${CMAKE_SOURCE_DIR}/cinch/cmake/run_units.cmake)
    endif(ENABLE_UNIT_TESTS)

else()

    #--------------------------------------------------------------------------#
    # This is a submodule
    #--------------------------------------------------------------------------#

    set(CINCH_CONFIG_INFOTAG "${PROJECT_NAME}.")

endif(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR})

#------------------------------------------------------------------------------#
# Set output directories for targets
#------------------------------------------------------------------------------#

# Global project settings
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

#------------------------------------------------------------------------------#
# Add sub-projects
#------------------------------------------------------------------------------#

if(CINCH_CONFIG_SUBPROJECTS)
    foreach(subproject ${CINCH_CONFIG_SUBPROJECTS})
        add_subdirectory(${subproject})
    endforeach(subproject)
endif(CINCH_CONFIG_SUBPROJECTS)

#------------------------------------------------------------------------------#
# Library target
#------------------------------------------------------------------------------#

if(CINCH_LIBRARY_TARGET)

    add_subdirectory(src)

    include_directories(${${CINCH_LIBRARY_TARGET}_INCDIRS})

    #--------------------------------------------------------------------------#
    # Generate info target
    #--------------------------------------------------------------------------#

    cinch_make_info("${CINCH_CONFIG_INFOTAG}main"
        "${${CINCH_LIBRARY_TARGET}_HEADERS}"
        "${${CINCH_LIBRARY_TARGET}_SOURCES}")

    #--------------------------------------------------------------------------#
    # Add a rule to build the library
    #--------------------------------------------------------------------------#

    add_library(${CINCH_LIBRARY_TARGET} ${${CINCH_LIBRARY_TARGET}_SOURCES}
        ${${CINCH_LIBRARY_TARGET}_HEADERS})

endif(CINCH_LIBRARY_TARGET)

if(CINCH_APPLICATION_DIRECTORY)
    add_subdirectory(${CINCH_APPLICATION_DIRECTORY})
endif(CINCH_APPLICATION_DIRECTORY)

#------------------------------------------------------------------------------#
# Formatting options for emacs and vim.
# vim: set tabstop=4 shiftwidth=4 expandtab :
#------------------------------------------------------------------------------#
