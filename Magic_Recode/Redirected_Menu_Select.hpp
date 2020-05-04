#pragma once

void __cdecl Redirected_Menu_Select(void** Data)
{
	auto Handle_Menu_Select = [&]() -> void
	{
		static void* Menu_Name_Location = (void*)((unsigned __int32)GetModuleHandleW(L"client.dll") + 5195824);

		if (strlen((char*)Menu_Name_Location) > 4)
		{
			if (strncmp((char*)Menu_Name_Location, "Magic", 5) == 0)
			{
				char* Menu_Selection = (char*)Data[259];

				if (Menu_Selection[1] == 0)
				{
					if (Freeze_Controlled_Creature == 0)
					{
						if (Menu_Selection[0] == '1')
						{
							Freeze_Controlled_Creature = 1;
						}
						else
						{
							if (Menu_Selection[0] == '2')
							{
								Freeze_Controlled_Creature = 1;
							}
						}
					}
					else
					{
						Menu_Selection[0] = 0;
					}
				}
				else
				{
					Freeze_Controlled_Creature = 0;
				}
			}
		}
	};

	if (User_Commands_Recorder_Record == 1)
	{
		Handle_Menu_Select();
	}
	else
	{
		if (User_Commands_Recorder_Playback == 1)
		{
			Handle_Menu_Select();
		}
	}

	using Menu_Select_Type = void(__cdecl*)(void* Data);

	Menu_Select_Type((unsigned __int32)Original_Menu_Select_Caller_Location)(Data);
}