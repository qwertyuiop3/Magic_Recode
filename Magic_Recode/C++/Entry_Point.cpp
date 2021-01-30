#include "Includes.hpp"

__int32 __stdcall DllMain(void* This_Module_Location, unsigned __int32 Call_Reason, void* Reserved)
{
	if (Call_Reason == DLL_PROCESS_ATTACH)
	{
		HWND Game_Window_Handle = FindWindowW(nullptr, L"Counter-Strike Source");

		if (Game_Window_Handle == nullptr)
		{
			Menu_Select::Game_Identifier = 1;

			Game_Window_Handle = FindWindowW(nullptr, L"Counter-Strike: Global Offensive");
		}

		Menu_Select::Initialize_Menu_Select();

		void* Client_Module_Location = GetModuleHandleW(L"client.dll");

		Menu_Select::Redirect_Menu_Select(Client_Module_Location);

		Controller_Move::Initialize_Controller_Move();

		Controller_Move::Redirect_Controller_Move(Client_Module_Location);

		Copy_User_Command::Initialize_Copy_User_Command();

		Copy_User_Command::Redirect_Copy_User_Command(Client_Module_Location);

		if (Menu_Select::Game_Identifier == 0)
		{
			Client_Send_Move::Redirect_Client_Send_Move();
		}
		else
		{
			Write_User_Command_Delta_To_Buffer::Redirect_Write_User_Command_Delta_To_Buffer(Client_Module_Location);
		}

		Physics_Simulate::Redirect_Physics_Simulate(Client_Module_Location);

		Chat_Print_Formatted::Initialize_Chat_Print_Formatted();

		Chat_Print_Formatted::Redirect_Chat_Print_Formatted(Client_Module_Location);

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

		IDirect3DDevice9* Direct_3_Dimensional_Device_9 = **(IDirect3DDevice9***)((unsigned __int32)Byte_Manager::Find_Bytes(sizeof(Direct_3_Dimensional_Device_9_Bytes), GetModuleHandleW(L"shaderapidx9.dll"), Direct_3_Dimensional_Device_9_Bytes, 0) - 10);

		Immediate_Mode_Graphical_User_Interface::Initialize_Immediate_Mode_Graphical_User_Interface(Direct_3_Dimensional_Device_9, Game_Window_Handle);

		Window_Procedure::Initialize_Window_Procedure();

		Window_Procedure::Redirect_Window_Procedure(Game_Window_Handle);

		Present::Initialize_Present();

		Present::Redirect_Present(Direct_3_Dimensional_Device_9);
	}

	return 1;
}
