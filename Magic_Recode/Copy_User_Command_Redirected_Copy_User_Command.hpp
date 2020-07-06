#pragma once

void __fastcall Redirected_Copy_User_Command(void* Unknown_Parameter_1, void* Unknown_Parameter_2, User_Command_Structure* User_Command)
{
	if (Menu_Select::Freeze_Controlled_Creature == 0)
	{
		static void* Copy_User_Command_In_Create_Move_Return_Location = nullptr;

		if (Copy_User_Command_In_Create_Move_Return_Location == nullptr)
		{
			if (Menu_Select::Game_Identifier == 0)
			{
				Copy_User_Command_In_Create_Move_Return_Location = (void*)((unsigned __int32)GetModuleHandleW(L"client.dll") + 1338695);
			}
			else
			{
				unsigned __int8 Copy_User_Command_In_Create_Move_Return_Location_Bytes[4] =
				{
					95,

					137,

					70,

					100
				};

				Copy_User_Command_In_Create_Move_Return_Location = (void*)((unsigned __int32)Byte_Manager::Find_Bytes(sizeof Copy_User_Command_In_Create_Move_Return_Location_Bytes, GetModuleHandleW(L"client.dll"), Copy_User_Command_In_Create_Move_Return_Location_Bytes, 0) - 10);
			}
		}

		if (_ReturnAddress() == Copy_User_Command_In_Create_Move_Return_Location)
		{
			if (Menu_Select::User_Commands_Recorder_Record == 1)
			{
				static unsigned __int32 Recorded_User_Commands_Maximum_Elements_Amount = Recorded_User_Commands.max_size();

				if (Recorded_User_Commands.size() != Recorded_User_Commands_Maximum_Elements_Amount)
				{
					Compressed_User_Command_Structure Compressed_User_Command;

					float* User_Command_View_Angles = User_Command->View_Angles;

					Compressed_User_Command.View_Angles[0] = User_Command_View_Angles[0];

					Compressed_User_Command.View_Angles[1] = User_Command_View_Angles[1];

					Compressed_User_Command.View_Angles[2] = User_Command_View_Angles[2];

					float* User_Command_Move = User_Command->Move;

					Compressed_User_Command.Move[0] = User_Command_Move[0];

					Compressed_User_Command.Move[1] = User_Command_Move[1];

					Compressed_User_Command.Move[2] = User_Command_Move[2];

					Compressed_User_Command.Buttons_State = User_Command->Buttons_State;

					Compressed_User_Command.Impulse = User_Command->Impulse;

					Compressed_User_Command.Mouse_Difference_X = User_Command->Mouse_Difference_X;

					Compressed_User_Command.Mouse_Difference_Y = User_Command->Mouse_Difference_Y;

					Recorded_User_Commands.push_back(Compressed_User_Command);

					Recorder_User_Comamand_Number += 1;
				}
				else
				{
					Menu_Select::User_Commands_Recorder_Record = 0;

					Recorder_User_Comamand_Number = 0;
				}
			}
			else
			{
				if (Menu_Select::User_Commands_Recorder_Playback == 1)
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

						static void* Set_View_Angles_Location = nullptr;

						static void* Engine;

						if (Set_View_Angles_Location == nullptr)
						{
							if (Menu_Select::Game_Identifier == 0)
							{
								Set_View_Angles_Location = (void*)((unsigned __int32)GetModuleHandleW(L"engine.dll") + 676992);

								Engine = (void*)((unsigned __int32)GetModuleHandleW(L"engine.dll") + 3916044);
							}
							else
							{
								unsigned __int8 Set_View_Angles_Bytes[14] =
								{
									85,
									
									139,
									
									236,
									
									131,
									
									228,
									
									192,
									
									131,
									
									236,
									
									60,
									
									86,
									
									139,
									
									117,
									
									8,
									
									139
								};

								Set_View_Angles_Location = Byte_Manager::Find_Bytes(sizeof Set_View_Angles_Bytes, GetModuleHandleW(L"engine.dll"), Set_View_Angles_Bytes, 1);

								unsigned __int8 Engine_Bytes[9] =
								{
									255,
									
									117,
									
									220,
									
									255,
									
									117,
									
									224,
									
									255,
									
									117,
									
									228
								};

								Engine = *(void**)((unsigned __int32)Byte_Manager::Find_Bytes(sizeof Engine_Bytes, GetModuleHandleW(L"engine.dll"), Engine_Bytes, 0) - 12);
							}
						}

						Set_View_Angles_Type((unsigned __int32)Set_View_Angles_Location)(Engine, User_Command->View_Angles);

						float* User_Command_Move = User_Command->Move;

						float* Recorded_User_Command_Move = Recorded_User_Command->Move;

						User_Command_Move[0] = Recorded_User_Command_Move[0];

						User_Command_Move[1] = Recorded_User_Command_Move[1];

						User_Command_Move[2] = Recorded_User_Command_Move[2];

						User_Command->Buttons_State = Recorded_User_Command->Buttons_State;

						User_Command->Impulse = Recorded_User_Command->Impulse;

						User_Command->Mouse_Difference_X = Recorded_User_Command->Mouse_Difference_X;

						User_Command->Mouse_Difference_Y = Recorded_User_Command->Mouse_Difference_Y;

						Recorder_User_Comamand_Number += 1;
					}
					else
					{
						Menu_Select::User_Commands_Recorder_Playback = 0;

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

				if (Recorded_Route_Elements_Amount == 0)
				{
					static void* Get_Creature_Location_Location = (void*)((unsigned __int32)GetModuleHandleW(L"client.dll") + 601456);

					static void* Controlled_Creature_Container = (void*)((unsigned __int32)GetModuleHandleW(L"client.dll") + 5007112);

					Recorded_Route.push_back(*(Route_Structure*)Get_Creature_Location_Type(Get_Creature_Location_Location)(*(void**)Controlled_Creature_Container));
				}
				else
				{
					static unsigned __int32 Recorded_Route_Maximum_Elements_Amount = Recorded_Route.max_size();

					if (Recorded_Route_Elements_Amount != Recorded_Route_Maximum_Elements_Amount)
					{
						static void* Get_Creature_Location_Location = (void*)((unsigned __int32)GetModuleHandleW(L"client.dll") + 601456);

						static void* Controlled_Creature_Container = (void*)((unsigned __int32)GetModuleHandleW(L"client.dll") + 5007112);

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

	using Copy_User_Command_Type = void(__thiscall*)(void* Unknown_Parameter, User_Command_Structure* User_Command);

	Copy_User_Command_Type((unsigned __int32)Original_Copy_User_Command_Caller_Location)(Unknown_Parameter_1, User_Command);
}