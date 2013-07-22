# CFLAGS for module 'baz'
CFLAGS_baz := -fPIC

# Archive / Lib to build in module 'baz'
baz_ARCHIVE := libbaz.a

# Sources for the archive / lib 'libbaz.a' (without headers)
libbaz.a_SOURCES := baz.c
