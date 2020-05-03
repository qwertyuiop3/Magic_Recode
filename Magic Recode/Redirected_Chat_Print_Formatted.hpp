#pragma once

void Redirected_Chat_Print_Formatted(void* Unknown_Parameter_1, void* Unknown_Parameter_2, void* Unknown_Parameter_3, char* Message, ...)
{
	va_list Variadic_Parameters;

	va_start(Variadic_Parameters, Message);

	char Formatted_Message[4096];

	vsnprintf(Formatted_Message, sizeof Formatted_Message, Message, Variadic_Parameters);

	va_end(Variadic_Parameters);

	auto Handle_Chat_Message = [&]() -> void
	{
		if (strncmp(Formatted_Message, "[ Magic ] A", strlen(Formatted_Message)) == 0)
		{
			Freeze_Controlled_Creature = 2;

			Recorder_User_Comamand_Number_History.push_back(Current_Recorder_User_Comamand_Number);

			Recorder_User_Comamand_Number_History_Number = Recorder_User_Comamand_Number_History_Highest_Number;

			Recorder_User_Comamand_Number_History_Highest_Number += 1;
		}
		else
		{
			if (strncmp(Formatted_Message, "[ Magic ] B", strlen(Formatted_Message)) == 0)
			{
				Freeze_Controlled_Creature = 2;

				unsigned __int32 Future_Recorder_User_Comamand_Number_History = Recorder_User_Comamand_Number_History.at(Recorder_User_Comamand_Number_History_Number);

				if (User_Commands_Recorder_Record == 1)
				{
					Recorded_User_Commands.resize(Future_Recorder_User_Comamand_Number_History);
				}

				Current_Recorder_User_Comamand_Number = Future_Recorder_User_Comamand_Number_History;
			}
			else
			{
				if (strncmp(Formatted_Message, "[ Magic ] C", strlen(Formatted_Message)) == 0)
				{
					Recorder_User_Comamand_Number_History_Number -= 1;
				}
				else
				{
					if (strncmp(Formatted_Message, "[ Magic ] D", strlen(Formatted_Message)) == 0)
					{
						Recorder_User_Comamand_Number_History_Number += 1;
					}
					else
					{
						if (strncmp(Formatted_Message, "[ Magic ] E", strlen(Formatted_Message)) == 0)
						{
							Recorded_User_Commands.clear();

							Current_Recorder_User_Comamand_Number = 0;

							Recorder_User_Comamand_Number_History.clear();

							Recorder_User_Comamand_Number_History_Number = 0;

							Recorder_User_Comamand_Number_History_Highest_Number = 0;
						}
					}
				}
			}
		}
	};

	if (User_Commands_Recorder_Record == 1)
	{
		Handle_Chat_Message();
	}
	else
	{
		if (User_Commands_Recorder_Playback == 1)
		{
			Handle_Chat_Message();
		}
	}

	using Chat_Print_Formatted_Type = void(__cdecl*)(void* Unknown_Parameter_1, void* Unknown_Parameter_2, void* Unknown_Parameter_3, char* Message);

	Chat_Print_Formatted_Type((unsigned __int32)Original_Chat_Print_Formatted_Caller_Location)(Unknown_Parameter_1, Unknown_Parameter_2, Unknown_Parameter_3, Formatted_Message);
}