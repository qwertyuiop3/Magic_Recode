@echo off

cls

cmake -Wno-dev zydis -B zydis

cmake -Wno-dev zydis\dependencies\zycore -B zydis\dependencies\zycore

cmake -Wno-dev -B CMake

make -C CMake -s