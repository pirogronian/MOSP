#!/bin/sh

btype="Debug";

if [ -z "$1" ]; then
    btype="$1"
fi

mkdir -p build && cd build
cmake -DCMAKE_BUILD_TYPE="$btype" ..
cmake --build .
