#pragma once

void Redirected_Client_Send_Move()
{
	if (Menu_Select::Freeze_Controlled_Creature == 0)
	{
		(decltype(&Redirected_Client_Send_Move)(Original_Client_Send_Move_Caller_Location))();
	}
}