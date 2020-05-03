#pragma once

void __fastcall Redirected_Physics_Simulate(void* Unknown_Parameter_1, void* Unknown_Parameter_2)
{
	if (Freeze_Controlled_Creature == 1)
	{
		*(__int8*)((unsigned __int32)Unknown_Parameter_1 + 4552) = 0;
	}

	using Physics_Simulate_Type = void(__thiscall*)(void* Unknown_Parameter);

	Physics_Simulate_Type((unsigned __int32)Original_Physics_Simulate_Caller_Location)(Unknown_Parameter_1);
}