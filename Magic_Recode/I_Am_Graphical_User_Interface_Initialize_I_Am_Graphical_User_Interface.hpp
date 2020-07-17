#pragma once

void Initialize_I_Am_Graphical_User_Interface(IDirect3DDevice9* Direct_3_Dimensional_Device_9, HWND Game_Window_Handle)
{
	ImGui::CreateContext();

	ImGui::StyleColorsDark();

	ImGui_ImplDX9_Init(Direct_3_Dimensional_Device_9);

	ImGui_ImplWin32_Init(Game_Window_Handle);
}