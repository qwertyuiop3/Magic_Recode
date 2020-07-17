#!/bin/bash

mkdir -p Magic

i686-w64-mingw32-g++ \
-std=c++2a \
-s \
-Ofast \
-DNDEBUG \
-funroll-loops \
-fno-exceptions \
-fno-rtti \
-shared \
-static-libgcc \
-static-libstdc++ \
-fpermissive \
-w \
-D IMGUI_IMPL_WIN32_DISABLE_GAMEPAD \
-I Magic_Recode \
-I Magic_Recode/imgui \
-I Magic_Recode/imgui/examples \
Magic_Recode/Entry_Point.cpp \
Magic_Recode/imgui/imgui.cpp \
Magic_Recode/imgui/imgui_widgets.cpp \
Magic_Recode/imgui/imgui_draw.cpp \
Magic_Recode/imgui/examples/imgui_impl_dx9.cpp \
Magic_Recode/imgui/examples/imgui_impl_win32.cpp \
-lgdi32 \
-o Magic/Magic_Recode.dll