######################################################
# Build configurations
include $(BUILDSYS)/common.mak

######################################################

# Module library

MODULE_NAME = test_i2c

MODULE_SRCS = $(wildcard *.c)

######################################################
# Application

PROGRAM =

PROGRAM_SRCS =

PROGRAM_OBJS =

######################################################
# Module flags

MODULE_CFLAGS += -I$(TOPDIR)/amp/src/dev/i2c/inc \

MODULE_LDFLAGS =

######################################################
# Unittest setting

UNITTEST_SRCS =

UNITTEST_OBJS =

######################################################
# Release setting

# released source files
RELEASE_SRCS =

# released header files
RELEASE_HEADER_FILES =

# released library
RELEASE_LIBRARY = MODULE_LIBRARY

# source files to build released library
RELEASE_LIB_SRCS = MODULE_SRCS

# object files to build released library
RELEASE_LIB_OBJS = MODULE_OBJS

######################################################
# Common dependency process

include $(BUILDSYS)/module.mak
