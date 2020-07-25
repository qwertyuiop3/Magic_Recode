#pragma once

void Redirect_Copy_User_Command(void* Client_Module_Location)
{
	if (Menu_Select::Game_Identifier == 0)
	{
		Redirection_Manager::Redirect_Function(Original_Copy_User_Command_Caller_Location, 0, (void*)((unsigned __int32)Client_Module_Location + 1171440), Redirected_Copy_User_Command);
	}
	else
	{
		unsigned __int8 Copy_User_Command_Bytes[8] =
		{
			85,

			139,

			236,

			139,

			85,

			8,

			59,

			202
		};

		Redirection_Manager::Redirect_Function(Original_Copy_User_Command_Caller_Location, 0, Byte_Manager::Find_Bytes(sizeof Copy_User_Command_Bytes, Client_Module_Location, Copy_User_Command_Bytes, 1), Redirected_Copy_User_Command);
	}
}