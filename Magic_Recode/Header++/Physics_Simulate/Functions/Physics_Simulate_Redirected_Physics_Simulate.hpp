#pragma once

void __fastcall Redirected_Physics_Simulate(void* Creature, void* Unknown_Parameter)
{
	if (Menu_Select::Freeze_Controlled_Creature == 1)
	{
		if (Menu_Select::Game_Identifier == 0)
		{
			*(__int8*)((unsigned __int32)Creature + 4552) = 0;
		}
		else
		{
			*(__int8*)((unsigned __int32)Creature + 13564) = 0;
		}
	}

	using Physics_Simulate_Type = void(__thiscall*)(void* Creature);

	Physics_Simulate_Type((unsigned __int32)Original_Physics_Simulate_Caller_Location)(Creature);
}