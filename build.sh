#!/bin/bash

set -e

echo "Generating Python"
kaitai-struct-compiler --target python --outdir python/hantek_wave_viewer/parser kaitai/hantek.ksy

echo "Generating Rust"
kaitai-struct-compiler --target rust --outdir rust/parser kaitai/hantek.ksy
