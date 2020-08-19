#pragma once

void __fastcall Redirected_Copy_User_Command(void* Unknown_Parameter_1, void* Unknown_Parameter_2, void* User_Command)
{
	if (Menu_Select::Freeze_Controlled_Creature == 0)
	{
		auto Find_Copy_User_Command_In_Create_Move_Return_Location = []() -> void*
		{
			if (Menu_Select::Game_Identifier == 0)
			{
				return (void*)((unsigned __int32)GetModuleHandleW(L"client.dll") + 1338695);
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

				return (void*)((unsigned __int32)Byte_Manager::Find_Bytes(sizeof(Copy_User_Command_In_Create_Move_Return_Location_Bytes), GetModuleHandleW(L"client.dll"), Copy_User_Command_In_Create_Move_Return_Location_Bytes, 0) - 10);
			}
		};

		static void* Copy_User_Command_In_Create_Move_Return_Location = Find_Copy_User_Command_In_Create_Move_Return_Location();

		if (__builtin_return_address(0) == Copy_User_Command_In_Create_Move_Return_Location)
		{
			if (Menu_Select::User_Commands_Recorder_Record == 0)
			{
        if (Menu_Select::User_Commands_Recorder_Playback == 0)
				{
          Recorder_User_Comamand_Number = 0;
        }
        else
        {
          if (Recorder_User_Comamand_Number != Recorded_User_Commands.size())
					{
						using Set_View_Angles_Type = void(__thiscall*)(void* Engine, float* View_Angles);

						auto Find_Set_View_Angles_Type = []() -> void*
						{
							if (Menu_Select::Game_Identifier == 0)
							{
								return (void*)((unsigned __int32)GetModuleHandleW(L"engine.dll") + 676992);
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

								return Byte_Manager::Find_Bytes(sizeof(Set_View_Angles_Bytes), GetModuleHandleW(L"engine.dll"), Set_View_Angles_Bytes, 1);
							}
						};

						static void* Set_View_Angles_Location = Find_Set_View_Angles_Type();

						auto Find_Engine = []() -> void*
						{
							if (Menu_Select::Game_Identifier == 0)
							{
								return (void*)((unsigned __int32)GetModuleHandleW(L"engine.dll") + 3916044);
							}
							else
							{
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

								return *(void**)((unsigned __int32)Byte_Manager::Find_Bytes(sizeof(Engine_Bytes), GetModuleHandleW(L"engine.dll"), Engine_Bytes, 0) - 12);
							}
						};

						static void* Engine = Find_Engine();

						if (Menu_Select::Game_Identifier == 0)
						{
							Compressed_User_Command_Structure Recorded_User_Command = Recorded_User_Commands.at(Recorder_User_Comamand_Number);

							((Source_User_Command_Structure*)User_Command)->View_Angles[0] = Recorded_User_Command.View_Angles[0];

							((Source_User_Command_Structure*)User_Command)->View_Angles[1] = Recorded_User_Command.View_Angles[1];

							((Source_User_Command_Structure*)User_Command)->View_Angles[2] = Recorded_User_Command.View_Angles[2];

							Set_View_Angles_Type((unsigned __int32)Set_View_Angles_Location)(Engine, ((Source_User_Command_Structure*)User_Command)->View_Angles);

							((Source_User_Command_Structure*)User_Command)->Move[0] = Recorded_User_Command.Move[0];

							((Source_User_Command_Structure*)User_Command)->Move[1] = Recorded_User_Command.Move[1];

							((Source_User_Command_Structure*)User_Command)->Move[2] = Recorded_User_Command.Move[2];

							((Source_User_Command_Structure*)User_Command)->Buttons_State = Recorded_User_Command.Buttons_State;

							((Source_User_Command_Structure*)User_Command)->Impulse = Recorded_User_Command.Impulse;

							((Source_User_Command_Structure*)User_Command)->Mouse_Difference_X = Recorded_User_Command.Mouse_Difference_X;

							((Source_User_Command_Structure*)User_Command)->Mouse_Difference_Y = Recorded_User_Command.Mouse_Difference_Y;
						}
						else
						{
							Compressed_User_Command_Structure Recorded_User_Command = Recorded_User_Commands.at(Recorder_User_Comamand_Number);

							((Global_Offensive_User_Command_Structure*)User_Command)->View_Angles[0] = Recorded_User_Command.View_Angles[0];

							((Global_Offensive_User_Command_Structure*)User_Command)->View_Angles[1] = Recorded_User_Command.View_Angles[1];

							((Global_Offensive_User_Command_Structure*)User_Command)->View_Angles[2] = Recorded_User_Command.View_Angles[2];

							Set_View_Angles_Type((unsigned __int32)Set_View_Angles_Location)(Engine, ((Global_Offensive_User_Command_Structure*)User_Command)->View_Angles);

							((Global_Offensive_User_Command_Structure*)User_Command)->Move[0] = Recorded_User_Command.Move[0];

							((Global_Offensive_User_Command_Structure*)User_Command)->Move[1] = Recorded_User_Command.Move[1];

							((Global_Offensive_User_Command_Structure*)User_Command)->Move[2] = Recorded_User_Command.Move[2];

							((Global_Offensive_User_Command_Structure*)User_Command)->Buttons_State = Recorded_User_Command.Buttons_State;

							((Global_Offensive_User_Command_Structure*)User_Command)->Impulse = Recorded_User_Command.Impulse;

							((Global_Offensive_User_Command_Structure*)User_Command)->Mouse_Difference_X = Recorded_User_Command.Mouse_Difference_X;

							((Global_Offensive_User_Command_Structure*)User_Command)->Mouse_Difference_Y = Recorded_User_Command.Mouse_Difference_Y;
						}

						Recorder_User_Comamand_Number += 1;
					}
					else
					{
						Menu_Select::User_Commands_Recorder_Playback = 0;

						Recorder_User_Comamand_Number = 0;
					}
        }
			}
			else
			{
				static unsigned __int32 Recorded_User_Commands_Maximum_Elements_Amount = Recorded_User_Commands.max_size();

				if (Recorded_User_Commands.size() != Recorded_User_Commands_Maximum_Elements_Amount)
				{
					Compressed_User_Command_Structure Compressed_User_Command;

					if (Menu_Select::Game_Identifier == 0)
					{
						Compressed_User_Command.View_Angles[0] = ((Source_User_Command_Structure*)User_Command)->View_Angles[0];

						Compressed_User_Command.View_Angles[1] = ((Source_User_Command_Structure*)User_Command)->View_Angles[1];

						Compressed_User_Command.View_Angles[2] = ((Source_User_Command_Structure*)User_Command)->View_Angles[2];

						Compressed_User_Command.Move[0] = ((Source_User_Command_Structure*)User_Command)->Move[0];

						Compressed_User_Command.Move[1] = ((Source_User_Command_Structure*)User_Command)->Move[1];

						Compressed_User_Command.Move[2] = ((Source_User_Command_Structure*)User_Command)->Move[2];

						Compressed_User_Command.Buttons_State = ((Source_User_Command_Structure*)User_Command)->Buttons_State;

						Compressed_User_Command.Impulse = ((Source_User_Command_Structure*)User_Command)->Impulse;

						Compressed_User_Command.Mouse_Difference_X = ((Source_User_Command_Structure*)User_Command)->Mouse_Difference_X;

						Compressed_User_Command.Mouse_Difference_Y = ((Source_User_Command_Structure*)User_Command)->Mouse_Difference_Y;
					}
					else
					{
						Compressed_User_Command.View_Angles[0] = ((Global_Offensive_User_Command_Structure*)User_Command)->View_Angles[0];

						Compressed_User_Command.View_Angles[1] = ((Global_Offensive_User_Command_Structure*)User_Command)->View_Angles[1];

						Compressed_User_Command.View_Angles[2] = ((Global_Offensive_User_Command_Structure*)User_Command)->View_Angles[2];

						Compressed_User_Command.Move[0] = ((Global_Offensive_User_Command_Structure*)User_Command)->Move[0];

						Compressed_User_Command.Move[1] = ((Global_Offensive_User_Command_Structure*)User_Command)->Move[1];

						Compressed_User_Command.Move[2] = ((Global_Offensive_User_Command_Structure*)User_Command)->Move[2];

						Compressed_User_Command.Buttons_State = ((Global_Offensive_User_Command_Structure*)User_Command)->Buttons_State;

						Compressed_User_Command.Impulse = ((Global_Offensive_User_Command_Structure*)User_Command)->Impulse;

						Compressed_User_Command.Mouse_Difference_X = ((Global_Offensive_User_Command_Structure*)User_Command)->Mouse_Difference_X;

						Compressed_User_Command.Mouse_Difference_Y = ((Global_Offensive_User_Command_Structure*)User_Command)->Mouse_Difference_Y;
					}

					Recorded_User_Commands.push_back(Compressed_User_Command);

					Recorder_User_Comamand_Number += 1;
				}
				else
				{
					Menu_Select::User_Commands_Recorder_Record = 0;

					Recorder_User_Comamand_Number = 0;
				}
			}

			if (Route_Recorder_Record == 1)
			{
				unsigned __int32 Recorded_Route_Elements_Amount = Recorded_Route.size();

				static unsigned __int32 Recorded_Route_Maximum_Elements_Amount = Recorded_Route.max_size();

				if (Recorded_Route_Elements_Amount != Recorded_Route_Maximum_Elements_Amount)
				{
					auto Find_Controlled_Creature_Container = []() -> void*
					{
						if (Menu_Select::Game_Identifier == 0)
						{
							return (void*)((unsigned __int32)GetModuleHandleW(L"client.dll") + 5007112);
						}
						else
						{
							unsigned __int8 Controlled_Creature_Container_Bytes[6] =
							{
								52,

								83,

								86,

								87,

								139,

								61
							};

							return *(void**)((unsigned __int32)Byte_Manager::Find_Bytes(sizeof(Controlled_Creature_Container_Bytes), GetModuleHandleW(L"client.dll"), Controlled_Creature_Container_Bytes, 0) + 1);
						}
					};

					static void* Controlled_Creature_Container = Find_Controlled_Creature_Container();

					using Get_Creature_Location_Type = float*(__thiscall*)(void* Creature);

					auto Find_Get_Creature_Location_Location = [&]() -> void*
					{
						if (Menu_Select::Game_Identifier == 0)
						{
							return (void*)((unsigned __int32)GetModuleHandleW(L"client.dll") + 601456);
						}
						else
						{
							return *(void**)(**(unsigned __int32**)Controlled_Creature_Container + 40);
						}
					};

					static void* Get_Creature_Location_Location = Find_Get_Creature_Location_Location();

					if (Recorded_Route_Elements_Amount == 0)
					{
						Recorded_Route.push_back(*(Route_Structure*)Get_Creature_Location_Type(Get_Creature_Location_Location)(*(void**)Controlled_Creature_Container));
					}
					else
					{
						float* Creature_Location = Get_Creature_Location_Type(Get_Creature_Location_Location)(*(void**)Controlled_Creature_Container);

						float* Previous_Creature_Location = Recorded_Route.at(Recorded_Route_Elements_Amount - 1).Location;

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
				}
				else
				{
					Route_Recorder_Record = 0;
				}
			}
		}
	}

	using Copy_User_Command_Type = void(__thiscall*)(void* Unknown_Parameter, void* User_Command);

	Copy_User_Command_Type((unsigned __int32)Original_Copy_User_Command_Caller_Location)(Unknown_Parameter_1, User_Command);
}