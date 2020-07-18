#!/bin/bash

clear

cmake ./ -B CMake

make -C CMake

mv CMake/libMagic_Recode.so Magic/Magic_Recode.dll