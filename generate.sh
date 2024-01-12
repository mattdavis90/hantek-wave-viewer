#!/bin/bash

set -e

echo "Generating Python"
kaitai-struct-compiler --target python --outdir python/hantek_wave_viewer/parser kaitai/hantek.ksy

echo "Generating C++"
kaitai-struct-compiler --target cpp_stl --cpp-standard=11 --outdir cpp kaitai/hantek.ksy
mv cpp/hantek.cpp cpp/src/hantek_parser.cpp
sed -i -e "s/hantek.h/hantek_parser.hpp/" cpp/src/hantek_parser.cpp
mv cpp/hantek.h cpp/inc/hantek_parser.hpp
