#!/bin/bash

find $@ -name \*.c -o -name \*.cpp -o -name \*.cxx -o -name \*.java -o -name \*.js -o -name \*.h > cscope.files
