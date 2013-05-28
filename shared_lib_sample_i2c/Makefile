######################################################
# Build configurations
include $(BUILDSYS)/common.mak

######################################################
# Module library

MODULE_NAME = i2c

MODULE_SRCS = $(wildcard src/*.c) $(wildcard *.s)

######################################################
# Dynamic library

MODULE_DYN_LIB =

DYN_LIB_SRCS =

######################################################
# Header files

PUBLIC_HEADER_FILES = $(wildcard inc/*.h)

######################################################
# Application

PROGRAM =

PROGRAM_SRCS =

PROGRAM_OBJS =

######################################################
# Module flags

MODULE_CFLAGS += -Iinc \

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
