#pragma once

void Redirected_Client_Send_Move()
{
	if (Freeze_Controlled_Creature == 0)
	{
		using Move_Type = void(__cdecl*)();

		Move_Type((unsigned __int32)Original_Client_Send_Move_Caller_Location)();
	}
}