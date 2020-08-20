#!/bin/zsh

clear

cmake -Wno-dev zydis -B zydis

cmake -Wno-dev zydis/dependencies/zycore -B zydis/dependencies/zycore

cmake -Wno-dev -B CMake

make -C CMake -s

mkdir Output 2>/dev/null

mv CMake/libMagic_Recode.so Output/Magic_Recode.dll