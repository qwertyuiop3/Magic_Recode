#pragma once

void Redirect_Copy_User_Command(void* Client_Module_Location)
{
	Redirection_Manager::Redirect_Function(Original_Copy_User_Command_Caller_Location, 0, (void*)((unsigned __int32)Client_Module_Location + 1171440), 1, Redirected_Copy_User_Command);
}