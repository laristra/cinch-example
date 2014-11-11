#------------------------------------------------------------------------------#
# Copyright (c) 2014 Los Alamos National Security, LLC
# All rights reserved.
#------------------------------------------------------------------------------#

#------------------------------------------------------------------------------#
# Add subdirectory files
#------------------------------------------------------------------------------#

# This loop adds header and source files for each listed sub-directory
# to the main header and source file lists.  Additionally, it adds the
# listed sub-directories to the include search path.  Lastly, it creates
# a catalog for each sub-directory with information on the source and
# headers files from the directory using the 'info.cmake' script that is
# located in the top-level 'cmake' directory.
foreach(_SUBDIR util data grid)
  add_subdirectory(${_SUBDIR})
  list(APPEND INCDIRS ${CMAKE_CURRENT_SOURCE_DIR}/${_SUBDIR})
  list(APPEND HEADERS ${${_SUBDIR}_HEADERS})
  list(APPEND SOURCES ${${_SUBDIR}_SOURCES})
  make_info("${_SUBDIR}" "${${_SUBDIR}_HEADERS}" "${${_SUBDIR}_SOURCES}")
  add_custom_target(${NGC_CONFIG_INFOTAG}.${_SUBDIR}
    cat "${CMAKE_BINARY_DIR}/.${_SUBDIR}.buildinfo")
endforeach(_SUBDIR)

set(libtest_HEADERS ${HEADERS} PARENT_SCOPE)
set(libtest_SOURCES ${SOURCES} PARENT_SCOPE)
set(libtest_INCDIRS ${INCDIRS} PARENT_SCOPE)

#------------------------------------------------------------------------------#
# Formatting options for emacs and vim.
# vim: set tabstop=2 shiftwidth=2 expandtab :
#------------------------------------------------------------------------------#
