#pragma once

IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

namespace Window_Procedure
{
	#include "Window_Procedure_Variables.hpp"

	#include "Window_Procedure_Functions.hpp"
};