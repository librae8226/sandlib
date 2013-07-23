# CFLAGS for module 'baz'
CFLAGS_baz := -fPIC

# Archive / Lib to build in module 'baz'
LIBRARY_baz:= libbaz

# Sources for the archive / lib 'libbaz.a' (without headers)
SOURCES_baz := src/baz.c
