# CFLAGS for module 'test'
CFLAGS_bar :=
LDFLAGS_bar :=

# Executable to build in module 'bar'
test_PROGRAM := test

# Libraries that the executable depends on:
test_LIBRARIES :=

# Sources for the executable 'test' (without headers)
test_SOURCES := \
	main.c
