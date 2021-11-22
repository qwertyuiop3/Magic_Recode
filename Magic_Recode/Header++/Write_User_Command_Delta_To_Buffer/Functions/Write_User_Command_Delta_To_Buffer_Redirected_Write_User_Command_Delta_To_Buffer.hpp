#pragma once

__int8 __thiscall Redirected_Write_User_Command_Delta_To_Buffer(void* Unknown_Parameter_1, void* Unknown_Parameter_2, void* Unknown_Parameter_3, void* Unknown_Parameter_4, void* Unknown_Parameter_5, void* Unknown_Parameter_6)
{
	if (Menu_Select::Freeze_Controlled_Creature == 0)
	{
		return (decltype(&Redirected_Write_User_Command_Delta_To_Buffer)(Original_Write_User_Command_Delta_To_Buffer_Caller_Location))(Unknown_Parameter_1, Unknown_Parameter_2, Unknown_Parameter_3, Unknown_Parameter_4, Unknown_Parameter_5, Unknown_Parameter_6);
	}

	return 0;
}