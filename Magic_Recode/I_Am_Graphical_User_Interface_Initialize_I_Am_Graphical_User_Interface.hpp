#pragma once

void Initialize_I_Am_Graphical_User_Interface(HWND Game_Window_Handle)
{
	ImGui::CreateContext();

	ImGui::StyleColorsDark();

	IDirect3DDevice9* Direct_3_Dimensional_Device_9 = *(IDirect3DDevice9**)((unsigned __int32)GetModuleHandleW(L"shaderapidx9.dll") + 1599884);

	ImGui_ImplDX9_Init(Direct_3_Dimensional_Device_9);

	ImGui_ImplWin32_Init(Game_Window_Handle);
}