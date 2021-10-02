#pragma once

void Redirect_Menu_Select(void* Client_Module_Location)
{
	unsigned __int8 Menu_Select_Bytes[5] =
	{
		1,

		131,

		248,

		2,

		15
	};

	Redirection_Manager::Redirect_Function(Original_Menu_Select_Caller_Location, 0, (void*)((unsigned __int32)Byte_Manager::Find_Bytes(Client_Module_Location, Menu_Select_Bytes, sizeof(Menu_Select_Bytes)) - 7), (void*)Redirected_Menu_Select);
}