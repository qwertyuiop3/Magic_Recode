@echo off

cls

cmake zydis -B zydis

cmake zydis\dependencies\zycore -B zydis\dependencies\zycore

cmake -B CMake

make -C CMake -s

mkdir Output 2>nul

move CMake\Magic_Recode.dll Output\Magic_Recode.dll
