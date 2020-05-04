#include "Includes.hpp"

__int32 __stdcall DllMain(void* This_Module_Location, unsigned __int32 Call_Reason, void* Reserved)
{
	if (Call_Reason == DLL_PROCESS_ATTACH)
	{
		Initialize_Menu_Select();

		void* Client_Module_Location = GetModuleHandleW(L"client.dll");

		Redirect_Menu_Select(Client_Module_Location);

		Initialize_Controller_Move();

		Redirect_Controller_Move(Client_Module_Location);

		Initialize_Copy_User_Command();

		Redirect_Copy_User_Command(Client_Module_Location);

		Redirect_Client_Send_Move();

		Redirect_Physics_Simulate(Client_Module_Location);

		Initialize_Redirect_Chat_Print_Formatted();

		Redirect_Chat_Print_Formatted(Client_Module_Location);

		HWND Game_Window = FindWindowW(nullptr, L"Counter-Strike Source");

		Initialize_I_Am_Graphical_User_Interface(Game_Window);

		Initialize_Window_Procedure();

		Redirect_Window_Procedure(Game_Window);

		Redirect_Present();
	}

	return 1;
}