#pragma once

void Redirected_Chat_Print_Formatted(void* Unknown_Parameter_1, void* Unknown_Parameter_2, void* Unknown_Parameter_3, char* Message, ...)
{
	va_list Variadic_Parameters;

	va_start(Variadic_Parameters, Message);

	char Formatted_Message[4096];

	vsnprintf(Formatted_Message, sizeof Formatted_Message, Message, Variadic_Parameters);

	va_end(Variadic_Parameters);

	auto Handle_Formatted_Message = [&]() -> __int8
	{
		if (strncmp(Formatted_Message, "[ Magic ] A", 11) == 0)
		{
			Freeze_Controlled_Creature = 2;

			Recorder_User_Comamand_Number_History.push_back(Current_Recorder_User_Comamand_Number);

			Recorder_User_Comamand_Number_History_Number = Recorder_User_Comamand_Number_History_Highest_Number;

			Recorder_User_Comamand_Number_History_Highest_Number += 1;

			return 1;
		}
		else
		{
			if (strncmp(Formatted_Message, "[ Magic ] B", 11) == 0)
			{
				Freeze_Controlled_Creature = 2;

				unsigned __int32 Future_Recorder_User_Comamand_Number_History = Recorder_User_Comamand_Number_History.at(Recorder_User_Comamand_Number_History_Number);

				if (User_Commands_Recorder_Record == 1)
				{
					Recorded_User_Commands.resize(Future_Recorder_User_Comamand_Number_History);
				}

				Current_Recorder_User_Comamand_Number = Future_Recorder_User_Comamand_Number_History;

				return 1;
			}
			else
			{
				if (strncmp(Formatted_Message, "[ Magic ] C", 11) == 0)
				{
					Recorder_User_Comamand_Number_History_Number -= 1;

					return 1;
				}
				else
				{
					if (strncmp(Formatted_Message, "[ Magic ] D", 11) == 0)
					{
						Recorder_User_Comamand_Number_History_Number += 1;

						return 1;
					}
					else
					{
						return 0;
					}
				}
			}
		}
	};

	if (strlen(Formatted_Message) == 12)
	{
		__int8 Handle_Message_Return_Value;

		if (User_Commands_Recorder_Record == 1)
		{
			Handle_Message_Return_Value = Handle_Formatted_Message();
		}
		else
		{
			if (User_Commands_Recorder_Playback == 1)
			{
				Handle_Message_Return_Value = Handle_Formatted_Message();
			}
			else
			{
				Handle_Message_Return_Value = 0;
			}
		}

		if (Handle_Message_Return_Value == 0)
		{
			if (strncmp(Formatted_Message, "[ Magic ] E", 11) == 0)
			{
				if (User_Commands_Recorder_Record == 1)
				{
					Recorded_User_Commands.clear();

					Current_Recorder_User_Comamand_Number = 0;
				}

				Recorder_User_Comamand_Number_History.clear();

				Recorder_User_Comamand_Number_History_Number = 0;

				Recorder_User_Comamand_Number_History_Highest_Number = 0;
			}
		}
	}

	using Chat_Print_Formatted_Type = void(__cdecl*)(void* Unknown_Parameter_1, void* Unknown_Parameter_2, void* Unknown_Parameter_3, char* Message);

	Chat_Print_Formatted_Type((unsigned __int32)Original_Chat_Print_Formatted_Caller_Location)(Unknown_Parameter_1, Unknown_Parameter_2, Unknown_Parameter_3, Formatted_Message);
}