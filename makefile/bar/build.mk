# CFLAGS for module 'bar'
CFLAGS_bar :=
LDFLAGS_bar := -L$(LIBDIR) -lbaz

# Executable to build in module 'bar'
BINARY_bar := bar

# Libraries that the executable depends on:
LIBRARIES_bar := libbaz.a

# Sources for the executable 'bar' (without headers)
SOURCES_bar := \
	src/kool.c \
	src/test/koo.c \
