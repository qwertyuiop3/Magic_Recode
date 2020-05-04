#pragma once

void __fastcall Redirected_Controller_Move(void* Input, void* Unknown_Parameter_1, void* Unknown_Parameter_2, void* Unknown_Parameter_3)
{
	static __int8 Previous_Draw_Graphical_User_Interface = Draw_Graphical_User_Interface;

	if (Draw_Graphical_User_Interface == 0)
	{
		static void* Mouse_Enable_Location = (void*)((unsigned __int32)Input + 5);

		if (Previous_Draw_Graphical_User_Interface == 1)
		{
			Previous_Draw_Graphical_User_Interface = 0;

			*(float*)Mouse_Enable_Location = 0;
		}

		auto Controller_Move = [&]() -> void
		{
			using Controller_Move_Type = void(__thiscall*)(void* Input, void* Unknown_Parameter_1, void* Unknown_Parameter_2);

			Controller_Move_Type((unsigned __int32)Original_Controller_Move_Caller_Location)(Input, Unknown_Parameter_2, Unknown_Parameter_3);
		};

		if (Freeze_Controlled_Creature == 2)
		{
			Freeze_Controlled_Creature = 0;

			*(float*)Mouse_Enable_Location = 0;

			Controller_Move();
		}
		else
		{
			if (Freeze_Controlled_Creature == 0)
			{
				Controller_Move();
			}
		}
	}
	else
	{
		Previous_Draw_Graphical_User_Interface = 1;
	}
}