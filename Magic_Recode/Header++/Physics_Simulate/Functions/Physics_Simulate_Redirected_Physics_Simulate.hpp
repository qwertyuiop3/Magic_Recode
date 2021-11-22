#pragma once

void __thiscall Redirected_Physics_Simulate(void* Creature)
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

	(decltype(&Redirected_Physics_Simulate)(Original_Physics_Simulate_Caller_Location))(Creature);
}