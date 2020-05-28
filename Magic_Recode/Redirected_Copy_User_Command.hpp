#pragma once

void* __fastcall Redirected_Copy_User_Command(void* Unknown_Parameter_1, void* Unknown_Parameter_2, User_Command_Structure* User_Command)
{
	if (Freeze_Controlled_Creature == 0)
	{
		static void* Copy_User_Command_Create_Move_Return_Location = (void*)((unsigned __int32)GetModuleHandleW(L"client.dll") + 1338695);

		if (_ReturnAddress() == Copy_User_Command_Create_Move_Return_Location)
		{
			if (User_Commands_Recorder_Record == 1)
			{
				static unsigned __int32 Recorded_User_Commands_Maximum_Elements_Amount = Recorded_User_Commands.max_size();

				if (Recorded_User_Commands.size() != Recorded_User_Commands_Maximum_Elements_Amount)
				{
					Compressed_User_Command_Structure Compressed_User_Command;

					float* User_Command_View_Angles = User_Command->View_Angles;

					Compressed_User_Command.View_Angles[0] = User_Command_View_Angles[0];

					Compressed_User_Command.View_Angles[1] = User_Command_View_Angles[1];

					Compressed_User_Command.View_Angles[2] = User_Command_View_Angles[2];

					Compressed_User_Command.Forward_Move = User_Command->Forward_Move;

					Compressed_User_Command.Side_Move = User_Command->Side_Move;

					Compressed_User_Command.Up_Move = User_Command->Up_Move;

					Compressed_User_Command.Buttons_State = User_Command->Buttons_State;

					Compressed_User_Command.Impulse = User_Command->Impulse;

					Compressed_User_Command.Mouse_Difference_X = User_Command->Mouse_Difference_X;

					Compressed_User_Command.Mouse_Difference_Y = User_Command->Mouse_Difference_Y;

					Recorded_User_Commands.push_back(Compressed_User_Command);

					Recorder_User_Comamand_Number += 1;
				}
				else
				{
					User_Commands_Recorder_Record = 0;

					Recorder_User_Comamand_Number = 0;
				}
			}
			else
			{
				if (User_Commands_Recorder_Playback == 1)
				{
					if (Recorder_User_Comamand_Number != Recorded_User_Commands.size())
					{
						Compressed_User_Command_Structure* Recorded_User_Command = &Recorded_User_Commands.at(Recorder_User_Comamand_Number);

						float* User_Command_View_Angles = User_Command->View_Angles;

						float* Recorded_User_Command_View_Angles = Recorded_User_Command->View_Angles;

						User_Command_View_Angles[0] = Recorded_User_Command_View_Angles[0];

						User_Command_View_Angles[1] = Recorded_User_Command_View_Angles[1];

						User_Command_View_Angles[2] = Recorded_User_Command_View_Angles[2];

						using Set_View_Angles_Type = void(__thiscall*)(void* Engine, float* View_Angles);

						static void* Set_View_Angles_Location = (void*)((unsigned __int32)GetModuleHandleW(L"engine.dll") + 676992);

						static void* Engine = (void*)((unsigned __int32)GetModuleHandleW(L"engine.dll") + 3916044);

						Set_View_Angles_Type((unsigned __int32)Set_View_Angles_Location)(Engine, User_Command->View_Angles);

						User_Command->Forward_Move = Recorded_User_Command->Forward_Move;

						User_Command->Side_Move = Recorded_User_Command->Side_Move;

						User_Command->Up_Move = Recorded_User_Command->Up_Move;

						User_Command->Buttons_State = Recorded_User_Command->Buttons_State;

						User_Command->Impulse = Recorded_User_Command->Impulse;

						User_Command->Mouse_Difference_X = Recorded_User_Command->Mouse_Difference_X;

						User_Command->Mouse_Difference_Y = Recorded_User_Command->Mouse_Difference_Y;

						Recorder_User_Comamand_Number += 1;
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

			if (Route_Recorder_Record == 1)
			{
				unsigned __int32 Recorded_Route_Elements_Amount = Recorded_Route.size();

				using Get_Creature_Location_Type = float*(__thiscall*)(void* Creature);

				static void* Get_Creature_Location_Location = (void*)((unsigned __int32)GetModuleHandleW(L"client.dll") + 601456);

				static void* Controlled_Creature_Container = (void*)((unsigned __int32)GetModuleHandleW(L"client.dll") + 5007112);

				if (Recorded_Route_Elements_Amount == 0)
				{
					Recorded_Route.push_back(*(Route_Structure*)Get_Creature_Location_Type(Get_Creature_Location_Location)(*(void**)Controlled_Creature_Container));
				}
				else
				{
					static unsigned __int32 Recorded_Route_Maximum_Elements_Amount = Recorded_Route.max_size();

					if (Recorded_Route_Elements_Amount != Recorded_Route_Maximum_Elements_Amount)
					{
						float* Creature_Location = Get_Creature_Location_Type(Get_Creature_Location_Location)(*(void**)Controlled_Creature_Container);

						float* Previous_Creature_Location = Recorded_Route.at(Recorded_Route.size() - 1).Location;

						if (Creature_Location[0] != Previous_Creature_Location[0])
						{
							Recorded_Route.push_back(*(Route_Structure*)Creature_Location);
						}
						else
						{
							if (Creature_Location[1] != Previous_Creature_Location[1])
							{
								Recorded_Route.push_back(*(Route_Structure*)Creature_Location);
							}
							else
							{
								if (Creature_Location[2] != Previous_Creature_Location[2])
								{
									Recorded_Route.push_back(*(Route_Structure*)Creature_Location);
								}
							}
						}
					}
					else
					{
						Route_Recorder_Record = 0;
					}
				}
			}
		}
	}

	using Copy_User_Command_Type = void*(__thiscall*)(void* Unknown_Parameter, User_Command_Structure* User_Command);

	return Copy_User_Command_Type(Original_Copy_User_Command_Caller_Location)(Unknown_Parameter_1, User_Command);
}