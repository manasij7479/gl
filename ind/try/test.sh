#!/bin/bash
cp mygl.cpp ../../
cd ../..
make -j9
mv main ind/try
cd ind/try
./main
