CMake_Minimum_Required(VERSION "3.0.0")

Project("Magic_Recode")

Set(CMAKE_CXX_COMPILER "i686-w64-mingw32-g++")

Set(CMAKE_CXX_FLAGS "-D IMGUI_IMPL_WIN32_DISABLE_GAMEPAD -fpermissive -w -s -Ofast -DNDEBUG -funroll-loops -fno-exceptions -fno-rtti -static-libgcc -static-libstdc++")

File(GLOB_RECURSE Files "*.hpp")

ForEach(File ${Files})
    Get_Filename_Component(Folder ${File} PATH)

    Set(Includes ${Includes} ${Folder})
EndForEach()

List(REMOVE_DUPLICATES Includes)

Set(CMAKE_C_COMPILER "i686-w64-mingw32-gcc")

Set(CMAKE_C_FLAGS "-s -Ofast -DNDEBUG -funroll-loops -fno-exceptions")

Include_Directories(
    ${Includes}

    "imgui"

    "imgui/examples"

    "zydis"

    "zydis/src"

    "zydis/dependencies/zycore"

    "zydis/dependencies/zycore/include"

    "zydis/include"
)

Add_Library(
    "Magic_Recode" SHARED

    "Magic_Recode/C++/Entry_Point.cpp"

    "imgui/imgui.cpp"

    "imgui/imgui_widgets.cpp"

    "imgui/imgui_draw.cpp"

    "imgui/examples/imgui_impl_dx9.cpp"

    "imgui/examples/imgui_impl_win32.cpp"

    "zydis/src/Zydis.c"

    "zydis/src/Decoder.c"

    "zydis/src/DecoderData.c"

    "zydis/src/Formatter.c"

    "zydis/src/FormatterATT.c"

    "zydis/src/FormatterBase.c"

    "zydis/src/FormatterBuffer.c"

    "zydis/src/FormatterIntel.c"

    "zydis/src/MetaInfo.c"

    "zydis/src/Mnemonic.c"

    "zydis/src/Register.c"

    "zydis/src/SharedData.c"

    "zydis/src/String.c"

    "zydis/src/Utils.c"
)

Target_Link_Libraries(
    "Magic_Recode"

    "gdi32"
)