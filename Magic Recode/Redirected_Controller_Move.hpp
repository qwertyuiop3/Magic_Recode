#pragma once

void __fastcall Redirected_Controller_Move(void* Unknown_Parameter_1, void* Unknown_Parameter_2, void* Unknown_Parameter_3, void* Unknown_Parameter_4)
{
	if (Draw_Graphical_User_Interface == 0)
	{
		auto Controller_Move_Type = [&]() -> void
		{
			using Controller_Move_Type = void(__thiscall*)(void* Unknown_Parameter_1, void* Unknown_Parameter_2, void* Unknown_Parameter_3);

			Controller_Move_Type((unsigned __int32)Original_Controller_Move_Caller_Location)(Unknown_Parameter_1, Unknown_Parameter_3, Unknown_Parameter_4);
		};

		if (Freeze_Controlled_Creature == 2)
		{
			Freeze_Controlled_Creature = 0;

			*(__int8*)((unsigned __int32)Unknown_Parameter_1 + 5) = 0;

			Controller_Move_Type();
		}
		else
		{
			if (Freeze_Controlled_Creature == 0)
			{
				Controller_Move_Type();
			}
		}
	}
}