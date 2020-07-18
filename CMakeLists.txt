Project(Magic_Recode)

CMake_Minimum_Required(VERSION "3.0.0")

Set(CMAKE_CXX_COMPILER "i686-w64-mingw32-g++")

Set(CMAKE_CXX_FLAGS "-std=c++2a -D IMGUI_IMPL_WIN32_DISABLE_GAMEPAD -fpermissive -w -s -Ofast -DNDEBUG -funroll-loops -fno-exceptions -fno-rtti -static-libgcc -static-libstdc++")

File(GLOB_RECURSE Files *.hpp)

ForEach(File ${Files})
    Get_Filename_Component(Folder ${File} PATH)

    Set(Includes ${Includes} ${Folder})
EndForEach()

List(REMOVE_DUPLICATES Includes)

Include_Directories(
    ${Includes}

    imgui

    imgui/examples
)

Add_Library(
    Magic_Recode SHARED

    Magic_Recode/C++/Entry_Point.cpp

    imgui/imgui.cpp

    imgui/imgui_widgets.cpp

    imgui/imgui_draw.cpp

    imgui/examples/imgui_impl_dx9.cpp

    imgui/examples/imgui_impl_win32.cpp
)

Target_Link_Libraries(
    Magic_Recode

    gdi32
)
