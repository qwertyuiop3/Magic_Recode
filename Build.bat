@echo off

cls

cmake -B CMake

make -C CMake -s

mkdir Output 2>nul

move CMake\Magic_Recode.dll Output\Magic_Recode.dll