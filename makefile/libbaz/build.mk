# CFLAGS for module 'baz'
CFLAGS_libbaz := -fPIC

# Archive / Lib to build in module 'baz'
LIBRARY_libbaz:= libbaz

# Sources for the archive / lib 'libbaz.a' (without headers)
SOURCES_libbaz := src/baz.c
