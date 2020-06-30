#pragma once

void Initialize_I_Am_Graphical_User_Interface(HWND Game_Window_Handle)
{
	ImGui::CreateContext();

	ImGui::StyleColorsDark();

	ImGui_ImplDX9_Init(*(IDirect3DDevice9**)((unsigned __int32)GetModuleHandleW(L"shaderapidx9.dll") + 1599884));

	ImGui_ImplWin32_Init(Game_Window_Handle);
}