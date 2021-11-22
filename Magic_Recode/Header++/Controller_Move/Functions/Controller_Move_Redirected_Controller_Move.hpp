#pragma once

void __thiscall Redirected_Controller_Move(void* Input, void* Unknown_Parameter_1, void* Unknown_Parameter_2)
{
	static __int8 Previous_Draw_Graphical_User_Interface = Draw_Graphical_User_Interface;

	if (Draw_Graphical_User_Interface == 0)
	{
		if (Previous_Draw_Graphical_User_Interface == 0)
		{
			if (Menu_Select::Freeze_Controlled_Creature == 0)
			{
				(decltype(&Redirected_Controller_Move)(Original_Controller_Move_Caller_Location))(Input, Unknown_Parameter_1, Unknown_Parameter_2);
			}
			else
			{
				if (Menu_Select::Game_Identifier == 0)
				{
					*(__int8*)((unsigned __int32)Input + 5) = 0;
				}
				else
				{
					*(__int8*)((unsigned __int32)Input + 14) = 0;
				}

				if (Menu_Select::Freeze_Controlled_Creature == 2)
				{
					Menu_Select::Freeze_Controlled_Creature = 0;
				}
			}
		}
		else
		{
			if (Menu_Select::Game_Identifier == 0)
			{
				*(__int8*)((unsigned __int32)Input + 5) = 0;
			}
			else
			{
				*(__int8*)((unsigned __int32)Input + 14) = 0;
			}

			Previous_Draw_Graphical_User_Interface = 0;
		}
	}
	else
	{
		Previous_Draw_Graphical_User_Interface = 1;
	}
}