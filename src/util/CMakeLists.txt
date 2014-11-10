#------------------------------------------------------------------------------#
# Copyright (c) 2014 Los Alamos National Security, LLC
# All rights reserved.
#------------------------------------------------------------------------------#

# Add header files
set(util_HEADERS
  ${CMAKE_CURRENT_SOURCE_DIR}/upart.h
  PARENT_SCOPE
)

# Add source files
set(util_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/upart.cc
  PARENT_SCOPE
)

#------------------------------------------------------------------------------#
# Formatting options for emacs and vim.
# vim: set tabstop=2 shiftwidth=2 expandtab :
#------------------------------------------------------------------------------#
