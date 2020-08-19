#pragma once

void Handle_Formatted_Message(char* Formatted_Message)
{
	if (strlen(Formatted_Message) == 12)
	{
		__int8 Handle_Formatted_Message_Return_Value;

		auto Handle_Formatted_Message = [&]() -> __int8
		{
			if (strncmp(Formatted_Message, "[ Magic ] A", 11) == 0)
			{
				Menu_Select::Freeze_Controlled_Creature = 2;

				Recorder_User_Comamand_Number_History.push_back(Copy_User_Command::Recorder_User_Comamand_Number);

				Recorder_User_Comamand_Number_History_Number = Recorder_User_Comamand_Number_Greatest_History_Number;

				Recorder_User_Comamand_Number_Greatest_History_Number += 1;

				return 1;
			}
			else
			{
				if (strncmp(Formatted_Message, "[ Magic ] B", 11) == 0)
				{
					Recorder_User_Comamand_Number_History_Number -= 1;

					return 1;
				}
				else
				{
					if (strncmp(Formatted_Message, "[ Magic ] C", 11) == 0)
					{
						Recorder_User_Comamand_Number_History_Number += 1;

						return 1;
					}
					else
					{
						if (strncmp(Formatted_Message, "[ Magic ] D", 11) == 0)
						{
							Menu_Select::Freeze_Controlled_Creature = 2;

							unsigned __int32 Future_Recorder_User_Comamand_Number = Recorder_User_Comamand_Number_History.at(Recorder_User_Comamand_Number_History_Number);

							if (Menu_Select::User_Commands_Recorder_Record == 1)
							{
								Copy_User_Command::Recorded_User_Commands.resize(Future_Recorder_User_Comamand_Number);
							}

							Copy_User_Command::Recorder_User_Comamand_Number = Future_Recorder_User_Comamand_Number;

							return 1;
						}

						return 0;
					}
				}
			}
		};

		if (Menu_Select::User_Commands_Recorder_Record == 0)
		{
			if (Menu_Select::User_Commands_Recorder_Playback == 0)
			{
				Handle_Formatted_Message_Return_Value = 0;
			}
			else
			{
				Handle_Formatted_Message_Return_Value = Handle_Formatted_Message();
			}
		}
		else
		{
			Handle_Formatted_Message_Return_Value = Handle_Formatted_Message();
		}

		if (Handle_Formatted_Message_Return_Value == 0)
		{
			if (strncmp(Formatted_Message, "[ Magic ] E", 11) == 0)
			{
				if (Menu_Select::User_Commands_Recorder_Record == 1)
				{
					Copy_User_Command::Recorded_User_Commands.clear();

					Copy_User_Command::Recorder_User_Comamand_Number = 0;
				}

				Recorder_User_Comamand_Number_History.clear();

				Recorder_User_Comamand_Number_History_Number = 0;

				Recorder_User_Comamand_Number_Greatest_History_Number = 0;
			}
		}
	}
}