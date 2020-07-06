#include "Includes.hpp"

__int32 __stdcall DllMain(void* This_Module_Location, unsigned __int32 Call_Reason, void* Reserved)
{
	if (Call_Reason == DLL_PROCESS_ATTACH)
	{
		HWND Game_Window_Handle = FindWindowW(nullptr, L"Counter-Strike Source");

		void* Client_Module_Location = GetModuleHandleW(L"client.dll");

		if (Game_Window_Handle == nullptr)
		{
			Menu_Select::Game_Identifier = 1;

			Game_Window_Handle = FindWindowW(nullptr, L"Counter-Strike: Global Offensive");
		}

		Menu_Select::Initialize_Menu_Select();

		Menu_Select::Redirect_Menu_Select(Client_Module_Location);

		Controller_Move::Initialize_Controller_Move();

		Controller_Move::Redirect_Controller_Move(Client_Module_Location);

		Copy_User_Command::Initialize_Copy_User_Command();

		Menu_Select::Game_Identifier = 1;

		Copy_User_Command::Redirect_Copy_User_Command(Client_Module_Location);

		Client_Send_Move::Redirect_Client_Send_Move();

		Physics_Simulate::Redirect_Physics_Simulate(Client_Module_Location);

		Chat_Print_Formatted::Initialize_Chat_Print_Formatted();

		Chat_Print_Formatted::Redirect_Chat_Print_Formatted(Client_Module_Location);

		I_Am_Graphical_User_Interface::Initialize_I_Am_Graphical_User_Interface(Game_Window_Handle);

		Window_Procedure::Initialize_Window_Procedure();

		Window_Procedure::Redirect_Window_Procedure(Game_Window_Handle);

		Present::Initialize_Present();
		
		Present::Redirect_Present();
	}

	return 1;
}