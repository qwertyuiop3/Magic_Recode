#pragma once

void Redirect_Physics_Simulate(void* Client_Module_Location)
{
	Redirection_Manager::Redirect_Function(Original_Physics_Simulate_Caller_Location, 3, (void*)((unsigned __int32)Client_Module_Location + 666608), Redirected_Physics_Simulate);
}