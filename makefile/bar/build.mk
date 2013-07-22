# CFLAGS for module 'bar'
CFLAGS_bar :=
LDFLAGS_bar := -Llib -lbaz

# Executable to build in module 'bar'
bar_PROGRAM := bar

# Libraries that the executable depends on:
bar_LIBRARIES := libbaz.a

# Sources for the executable 'bar' (without headers)
bar_SOURCES := kool.c
