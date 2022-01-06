#pragma once

void Redirect_Physics_Simulate(void* Client_Module_Location)
{
	if (Menu_Select::Game_Identifier == 0)
	{
		Redirection_Manager::Redirect_Function(Original_Physics_Simulate_Caller_Location, 3, (void*)((unsigned __int32)Client_Module_Location + 667984), (void*)Redirected_Physics_Simulate);
	}
	else
	{
		constexpr unsigned __int8 Physics_Simulate_Bytes[11] =
		{
			241,

			139,

			142,

			8,

			3,

			0,

			0,

			131,

			249,

			255,

			116
		};

		Redirection_Manager::Redirect_Function(Original_Physics_Simulate_Caller_Location, 3, (void*)((unsigned __int32)Byte_Manager::Find_Bytes(Client_Module_Location, (void*)Physics_Simulate_Bytes, sizeof(Physics_Simulate_Bytes)) - 2), (void*)Redirected_Physics_Simulate);
	}
}