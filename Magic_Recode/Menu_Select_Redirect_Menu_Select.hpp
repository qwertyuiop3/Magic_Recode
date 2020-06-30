#pragma once

void Redirect_Menu_Select(void* Client_Module_Location)
{
	Redirection_Manager::Redirect_Function(Original_Menu_Select_Caller_Location, 0, (void*)((unsigned __int32)Client_Module_Location + 2031904), Redirected_Menu_Select);
}