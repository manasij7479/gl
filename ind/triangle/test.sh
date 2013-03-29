#!/bin/bash
cp tri.cpp ../../
cd ../..
make -j9
rm tri.cpp
mv main ind/triangle
cd ind/triangle
./main
