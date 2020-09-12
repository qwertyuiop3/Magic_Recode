CMake_Minimum_Required(VERSION "3.0.0")

Project("Magic_Recode")

Set(CMAKE_CXX_COMPILER "i686-w64-mingw32-g++")

Set(CMAKE_CXX_FLAGS "-D IMGUI_IMPL_WIN32_DISABLE_GAMEPAD -D NDEBUG -fpermissive -s -Ofast -funroll-loops -fno-exceptions -fno-rtti -static")

File(GLOB_RECURSE Files "*.hpp")

ForEach(File ${Files})
    Get_Filename_Component(Folder ${File} PATH)

    Set(Includes ${Includes} ${Folder})
EndForEach()

List(REMOVE_DUPLICATES Includes)

Set(CMAKE_C_COMPILER "i686-w64-mingw32-gcc")

Set(CMAKE_C_FLAGS "-D ZYDIS_MINIMAL_MODE -D NDEBUG -s -Ofast -funroll-loops -fno-exceptions")

Include_Directories(
    ${Includes}

    "imgui"

    "imgui/examples"

    "zydis/dependencies/zycore/include"

    "zydis"

    "zydis/dependencies/zycore"

    "zydis/include"

    "zydis/src"
)

Add_Library(
    "Magic_Recode" SHARED

    "Magic_Recode/C++/Entry_Point.cpp"

    "imgui/imgui.cpp"

    "imgui/imgui_widgets.cpp"

    "imgui/imgui_draw.cpp"

    "imgui/examples/imgui_impl_dx9.cpp"

    "imgui/examples/imgui_impl_win32.cpp"

    "zydis/src/Decoder.c"

    "zydis/src/DecoderData.c"

    "zydis/src/SharedData.c"
)

Target_Link_Libraries(
    "Magic_Recode"

    "gdi32"
)

Set_Target_Properties("Magic_Recode" PROPERTIES PREFIX "")

Set_Target_Properties("Magic_Recode" PROPERTIES OUTPUT_NAME "Magic_Recode")

Set_Target_Properties("Magic_Recode" PROPERTIES SUFFIX ".dll")