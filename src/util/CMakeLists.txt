#------------------------------------------------------------------------------#
# Copyright (c) 2014 Los Alamos National Security, LLC
# All rights reserved.
#------------------------------------------------------------------------------#

# Add header files
set(util_HEADERS
    upart.h
    PARENT_SCOPE
)

# Add source files
set(util_SOURCES
    upart.cc
    PARENT_SCOPE
)

if(ENABLE_UNIT_TESTS)
    cinch_add_unit(times_two times_two.cc)
endif(ENABLE_UNIT_TESTS)

#------------------------------------------------------------------------------#
# Formatting options for emacs and vim.
# vim: set tabstop=4 shiftwidth=4 expandtab :
#------------------------------------------------------------------------------#
