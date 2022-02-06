#pragma once

void Redirected_Menu_Select(void* Data)
{
	auto Handle_Menu_Select = [&]() -> void
	{
		auto Find_Menu_Name = []() -> char*
		{
			if (Game_Identifier == 0)
			{
				return (char*)((unsigned __int32)GetModuleHandleW(L"client.dll") + 5204504);
			}

			constexpr unsigned __int8 Menu_Name_Bytes[4] =
			{
				208,

				139,

				202,

				128
			};

			return *(char**)((unsigned __int32)Byte_Manager::Find_Bytes(GetModuleHandleW(L"client.dll"), (void*)Menu_Name_Bytes, sizeof(Menu_Name_Bytes)) - 8);
		};

		static char* Menu_Name = Find_Menu_Name();

		if (__builtin_strncmp(Menu_Name, "Magic", 5) == 0)
		{
			char* Menu_Selection = *(char**)((unsigned __int32)Data + 1036);

			if (Game_Identifier == 0)
			{
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
							if (Menu_Selection[0] == '4')
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
			else
			{
				if (Freeze_Controlled_Creature == 0)
				{
					if (Menu_Selection[0] == '1')
					{
						Freeze_Controlled_Creature = 1;
					}
					else
					{
						if (Menu_Selection[0] == '4')
						{
							Freeze_Controlled_Creature = 1;
						}
					}
				}
				else
				{
					if (Menu_Selection[0] == '9')
					{
						Freeze_Controlled_Creature = 0;
					}
					else
					{
						Menu_Selection[0] = 0;
					}
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

	(decltype(&Redirected_Menu_Select)(Original_Menu_Select_Caller_Location))(Data);
}