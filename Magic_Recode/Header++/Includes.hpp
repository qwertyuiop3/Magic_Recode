#pragma once

#include <d3d9.h>

#include "Redirection_Manager.hpp"

#include "Byte_Manager.hpp"

#include "Menu_Select.hpp"

#include "Controller_Move.hpp"

#include <vector>

#include <cmath>

#include "Copy_User_Command.hpp"

#include "Client_Send_Move.hpp"

#include "Write_User_Command_Delta_To_Buffer.hpp"

#include "Physics_Simulate.hpp"

#include <cstdio>

#include "Chat_Print_Formatted.hpp"

#include "imgui.h"

#include "imgui_impl_dx9.h"

#include "imgui_impl_win32.h"

IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

#include "Immediate_Mode_Graphical_User_Interface.hpp"

#include "Window_Procedure.hpp"

#include "Zydis/Zydis.h"

#include "Present.hpp"