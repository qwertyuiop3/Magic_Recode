#pragma once

void* __fastcall Redirected_Copy_User_Command(void* Unknown_Parameter_1, void* Unknown_Parameter_2, User_Command_Structure* User_Command)
{
	if (Freeze_Controlled_Creature == 0)
	{
		static void* Copy_User_Command_Create_Move_Return_Location = (void*)((unsigned __int32)GetModuleHandleW(L"client.dll") + 1338695);

		if (*(void**)_AddressOfReturnAddress() == Copy_User_Command_Create_Move_Return_Location)
		{
			auto Record_User_Command = [&]() -> void
			{
				if (Recorded_User_Commands.size() != Recorded_User_Commands.max_size())
				{
					Recorded_User_Commands.push_back(*(User_Command_Structure*)User_Command);

					Recorder_User_Comamand_Number += 1;
				}
				else
				{
					User_Commands_Recorder_Record = 0;

					Recorder_User_Comamand_Number = 0;
				}
			};

			if (User_Commands_Recorder_Record == 1)
			{
				Record_User_Command();
			}
			else
			{
				auto Playback_Recorded_User_Commands = [&]() -> void
				{
					User_Command_Structure* Recorded_User_Command = &Recorded_User_Commands.at(Recorder_User_Comamand_Number);

					User_Command->View_Angles[0] = Recorded_User_Command->View_Angles[0];

					User_Command->View_Angles[1] = Recorded_User_Command->View_Angles[1];

					User_Command->View_Angles[2] = Recorded_User_Command->View_Angles[2];

					using Set_View_Angles_Type = void(__thiscall*)(void* Engine, float* View_Angles);

					static void* Engine_Module_Location = GetModuleHandleW(L"engine.dll");

					static void* Set_View_Angles_Location = (void*)((unsigned __int32)Engine_Module_Location + 676992);

					static void* Engine = (void*)((unsigned __int32)Engine_Module_Location + 3916044);

					Set_View_Angles_Type((unsigned __int32)Set_View_Angles_Location)(Engine, User_Command->View_Angles);

					User_Command->Forward_Move = Recorded_User_Command->Forward_Move;

					User_Command->Side_Move = Recorded_User_Command->Side_Move;

					User_Command->Up_Move = Recorded_User_Command->Up_Move;

					User_Command->Pressed_Buttons = Recorded_User_Command->Pressed_Buttons;

					User_Command->Impulse = Recorded_User_Command->Impulse;

					User_Command->Mouse_Difference_X = Recorded_User_Command->Mouse_Difference_X;

					User_Command->Mouse_Difference_Y = Recorded_User_Command->Mouse_Difference_Y;

					Recorder_User_Comamand_Number += 1;
				};

				if (User_Commands_Recorder_Playback == 1)
				{
					if (Recorder_User_Comamand_Number != Recorded_User_Commands.size())
					{
						Playback_Recorded_User_Commands();
					}
					else
					{
						User_Commands_Recorder_Playback = 0;

						Recorder_User_Comamand_Number = 0;
					}
				}
				else
				{
					Recorder_User_Comamand_Number = 0;
				}
			}
		}
	}

	using Copy_User_Command_Type = void*(__thiscall*)(void* Unknown_Parameter, User_Command_Structure* User_Command);

	return Copy_User_Command_Type(Original_Copy_User_Command_Caller_Location)(Unknown_Parameter_1, User_Command);
}