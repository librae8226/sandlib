# CFLAGS for module 'baz'
CFLAGS_baz := -fPIC

# Archive / Lib to build in module 'baz'
baz_LIBRARY:= libbaz

# Sources for the archive / lib 'libbaz.a' (without headers)
libbaz_SOURCES := baz.c
