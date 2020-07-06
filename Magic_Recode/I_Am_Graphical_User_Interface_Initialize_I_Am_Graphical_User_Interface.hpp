#pragma once

void Initialize_I_Am_Graphical_User_Interface(HWND Game_Window_Handle)
{
	ImGui::CreateContext();

	ImGui::StyleColorsDark();

	unsigned __int8 Direct_3_Dimensional_Device_9_Bytes[7] =
	{
		86,
		
		80,
		
		139,
		
		8,
		
		255,
		
		145,
		
		112
	};

	ImGui_ImplDX9_Init(**(IDirect3DDevice9***)((unsigned __int32)Byte_Manager::Find_Bytes(sizeof Direct_3_Dimensional_Device_9_Bytes, GetModuleHandleW(L"shaderapidx9.dll"), Direct_3_Dimensional_Device_9_Bytes, 0) - 10));

	ImGui_ImplWin32_Init(Game_Window_Handle);
}