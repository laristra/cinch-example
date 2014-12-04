#------------------------------------------------------------------------------#
# Copyright (c) 2014 Los Alamos National Security, LLC
# All rights reserved.
#------------------------------------------------------------------------------#

#------------------------------------------------------------------------------#
# Add subdirectories
#------------------------------------------------------------------------------#

set(CINCH_CONFIG_SUBDIRECTORIES "util;data;grid")

################################################################################
# Please Do Not Edit Below Here Unless You Know What You Are Doing!!!
#
# Any changes to the basic build template should be discussed with the
# project maintainers.
################################################################################

#------------------------------------------------------------------------------#
# Add subdirectory files
#------------------------------------------------------------------------------#

# This loop adds header and source files for each listed sub-directory
# to the main header and source file lists.  Additionally, it adds the
# listed sub-directories to the include search path.  Lastly, it creates
# a catalog for each sub-directory with information on the source and
# headers files from the directory using the 'info.cmake' script that is
# located in the top-level 'cmake' directory.
foreach(_SUBDIR ${CINCH_CONFIG_SUBDIRECTORIES})
    add_subdirectory(${_SUBDIR})
    list(APPEND INCDIRS ${CMAKE_CURRENT_SOURCE_DIR}/${_SUBDIR})
    list(APPEND HEADERS ${${_SUBDIR}_HEADERS})
    list(APPEND SOURCES ${${_SUBDIR}_SOURCES})
    cinch_make_info("${CINCH_CONFIG_INFOTAG}${_SUBDIR}"
        "${${_SUBDIR}_HEADERS}" "${${_SUBDIR}_SOURCES}")
endforeach(_SUBDIR)

set(${CINCH_LIBRARY_TARGET}_HEADERS ${HEADERS} PARENT_SCOPE)
set(${CINCH_LIBRARY_TARGET}_SOURCES ${SOURCES} PARENT_SCOPE)
set(${CINCH_LIBRARY_TARGET}_INCDIRS ${INCDIRS} PARENT_SCOPE)

#------------------------------------------------------------------------------#
# Formatting options for emacs and vim.
# vim: set tabstop=4 shiftwidth=4 expandtab :
#------------------------------------------------------------------------------#
