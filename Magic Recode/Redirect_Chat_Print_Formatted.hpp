#pragma once

void Redirect_Chat_Print_Formatted(void* Client_Module_Location)
{
	Redirection_Manager::Redirect_Function(Original_Chat_Print_Formatted_Caller_Location, 2, (void*)((unsigned __int32)Client_Module_Location + 1217136), 1, Redirected_Chat_Print_Formatted);
}