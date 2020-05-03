#pragma once

void Redirect_Controller_Move(void* Client_Module_Location)
{
	Redirection_Manager::Redirect_Function(Original_Controller_Move_Caller_Location, 0, (void*)((unsigned __int32)Client_Module_Location + 1337472), 1, Redirected_Controller_Move);
}