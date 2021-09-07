#pragma once

void __fastcall Redirected_Copy_User_Command(void* Unknown_Parameter_1, void* Unknown_Parameter_2, void* User_Command)
{
	if (Menu_Select::Freeze_Controlled_Creature == 0)
	{
		auto Find_Copy_User_Command_In_Create_Move_Return_Location = [&]() -> void*
		{
			if (Menu_Select::Game_Identifier == 0)
			{
				return (void*)((unsigned __int32)GetModuleHandleW(L"client.dll") + 1338695);
			}

			unsigned __int8 Copy_User_Command_In_Create_Move_Return_Location_Bytes[4] =
			{
				95,

				137,

				70,

				100
			};

			return (void*)((unsigned __int32)Byte_Manager::Find_Bytes(GetModuleHandleW(L"client.dll"), Copy_User_Command_In_Create_Move_Return_Location_Bytes, sizeof(Copy_User_Command_In_Create_Move_Return_Location_Bytes)) - 13);
		};

		static void* Copy_User_Command_In_Create_Move_Return_Location = Find_Copy_User_Command_In_Create_Move_Return_Location();

		if (__builtin_return_address(0) == Copy_User_Command_In_Create_Move_Return_Location)
		{
			auto Find_Controlled_Creature_Container = [&]() -> void*
			{
				if (Menu_Select::Game_Identifier == 0)
				{
					return (void*)((unsigned __int32)GetModuleHandleW(L"client.dll") + 5007112);
				}

				unsigned __int8 Controlled_Creature_Container_Bytes[6] =
				{
					52,

					83,

					86,

					87,

					139,

					61
				};

				return *(void**)((unsigned __int32)Byte_Manager::Find_Bytes(GetModuleHandleW(L"client.dll"), Controlled_Creature_Container_Bytes, sizeof(Controlled_Creature_Container_Bytes)) + 6);
			};

			static void* Controlled_Creature_Container = Find_Controlled_Creature_Container();

			auto Provide_Game_Appropriate_User_Command_Type = [&]<typename Type>(Type* User_Command) -> void
			{
				static float Previous_View_Angles_Y = User_Command->View_Angles[1];

				using Set_View_Angles_Type = void(__thiscall*)(void* Engine, float* View_Angles);

				auto Find_Set_View_Angles_Type = [&]() -> void*
				{
					if (Menu_Select::Game_Identifier == 0)
					{
						return (void*)((unsigned __int32)GetModuleHandleW(L"engine.dll") + 676992);
					}

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

					return Byte_Manager::Find_Bytes(GetModuleHandleW(L"engine.dll"), Set_View_Angles_Bytes, sizeof(Set_View_Angles_Bytes));
				};

				auto Find_Engine = [&]() -> void*
				{
					if (Menu_Select::Game_Identifier == 0)
					{
						return (void*)((unsigned __int32)GetModuleHandleW(L"engine.dll") + 3916044);
					}

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

					return *(void**)((unsigned __int32)Byte_Manager::Find_Bytes(GetModuleHandleW(L"engine.dll"), Engine_Bytes, sizeof(Engine_Bytes)) - 20);
				};

				static void* Set_View_Angles_Location = Find_Set_View_Angles_Type();

				static void* Engine = Find_Engine();

				if (Strafe_Optimizer_Optimize == 1)
				{
					if (Menu_Select::User_Commands_Recorder_Playback == 0)
					{
						__int8 Optimization_Time;

						if (User_Command->Move[0] == 0)
						{
							if ((User_Command->Buttons_State & 2) == 2)
							{
								auto Find_Prediction = [&]() -> void*
								{
									if (Menu_Select::Game_Identifier == 0)
									{
										return *(void**)((unsigned __int32)GetModuleHandleW(L"engine.dll") + 4554060);
									}

									unsigned __int8 Prediction_Bytes[4] =
									{
										133,

										210,

										139,

										13
									};

									return **(void***)((unsigned __int32)Byte_Manager::Find_Bytes(GetModuleHandleW(L"engine.dll"), Prediction_Bytes, sizeof(Prediction_Bytes)) + 4);
								};

								static void* Prediction = Find_Prediction();

								static void* Predict_Location = *(void**)(*(unsigned __int32*)Prediction + 12);

								auto Find_Prediction_Data = [&]() -> void*
								{
									if (Menu_Select::Game_Identifier == 0)
									{
										return nullptr;
									}

									unsigned __int8 Prediction_Data_Bytes[3] =
									{
										123,

										21,

										161
									};

									return **(void***)((unsigned __int32)Byte_Manager::Find_Bytes(GetModuleHandleW(L"engine.dll"), Prediction_Data_Bytes, sizeof(Prediction_Data_Bytes)) + 3);
								};

								static void* Prediction_Data = Find_Prediction_Data();

								auto Find_Delta_Tick_Container = [&]() -> void*
								{
									if (Menu_Select::Game_Identifier == 0)
									{
										return (void*)((unsigned __int32)GetModuleHandleW(L"engine.dll") + 4671440);
									}

									return (void*)((unsigned __int32)Prediction_Data + 372);
								};

								static void* Delta_Tick_Container = Find_Delta_Tick_Container();

								__int32 Delta_Tick = *(__int32*)Delta_Tick_Container;

								auto Find_Last_Command_Acknowledged_Container = [&]() -> void*
								{
									if (Menu_Select::Game_Identifier == 0)
									{
										return (void*)((unsigned __int32)GetModuleHandleW(L"engine.dll") + 4690268);
									}

									return (void*)((unsigned __int32)Prediction_Data + 19764);
								};

								static void* Last_Command_Acknowledged_Container = Find_Last_Command_Acknowledged_Container();

								auto Find_Last_Outgoing_Command_Container = [&]() -> void*
								{
									if (Menu_Select::Game_Identifier == 0)
									{
										return (void*)((unsigned __int32)GetModuleHandleW(L"engine.dll") + 4690260);
									}

									return (void*)((unsigned __int32)Prediction_Data + 19756);
								};

								static void* Last_Outgoing_Command_Container = Find_Last_Outgoing_Command_Container();

								auto Find_Choked_Commands_Container = [&]() -> void*
								{
									if (Menu_Select::Game_Identifier == 0)
									{
										return (void*)((unsigned __int32)GetModuleHandleW(L"engine.dll") + 4690264);
									}

									return (void*)((unsigned __int32)Prediction_Data + 19760);
								};

								static void* Choked_Commands_Container = Find_Choked_Commands_Container();

								using Predict_Type = void(__thiscall*)(void* Prediction, __int32 Delta_Tick, __int8 Valid, __int32 Last_Command_Acknowledged_Container, __int32 Command_Number);

								Predict_Type((unsigned __int32)Predict_Location)(Prediction, Delta_Tick, Delta_Tick > 0, *(__int32*)Last_Command_Acknowledged_Container, *(__int32*)Last_Outgoing_Command_Container + *(__int32*)Choked_Commands_Container);

								float* Velocity;

								if (Menu_Select::Game_Identifier == 0)
								{
									Velocity = (float*)(*(unsigned __int32*)Controlled_Creature_Container + 244);
								}
								else
								{
									Velocity = (float*)(*(unsigned __int32*)Controlled_Creature_Container + 276);
								}

								if (sqrtf(Velocity[0] * Velocity[0] + Velocity[1] * Velocity[1]) >= Strafe_Optimizer_Required_Speed)
								{
									if (Strafe_Optimizer_Least_Allowed_Distance_To_Wall == 0)
									{
										Optimization_Time = 1;
									}
									else
									{
										struct Ray_Structure
										{
											__int8 Additional_Bytes[70];
										};

										struct Trace_Filter_Structure
										{
											void* Trace_Filter;
										};

										struct Trace_Structure
										{
											__int8 Additional_Bytes_1[12];

											float Ending_Location[3];

											__int8 Additional_Bytes_2[60];
										};

										using Trace_Ray_Type = void(__thiscall*)(void* Engine_Trace, Ray_Structure* Ray, __int32 Mask, Trace_Filter_Structure* Trace_Filter, Trace_Structure* Trace);

										auto Find_Trace_Ray = [&]() -> void*
										{
											if (Menu_Select::Game_Identifier == 0)
											{
												return (void*)((unsigned __int32)GetModuleHandleW(L"engine.dll") + 1654560);
											}

											unsigned __int8 Trace_Ray_Bytes[3] =
											{
												16,

												87,

												168
											};

											return (void*)((unsigned __int32)Byte_Manager::Find_Bytes(GetModuleHandleW(L"engine.dll"), Trace_Ray_Bytes, sizeof(Trace_Ray_Bytes)) - 31);
										};

										static void* Trace_Ray_Location = Find_Trace_Ray();

										auto Find_Engine_Trace = [&]() -> void*
										{
											if (Menu_Select::Game_Identifier == 0)
											{
												return *(void**)((unsigned __int32)GetModuleHandleW(L"client.dll") + 5055848);
											}

											unsigned __int8 Engine_Trace_Bytes[5] =
											{
												36,

												32,

												139,

												117,

												24
											};

											return **(void***)((unsigned __int32)Byte_Manager::Find_Bytes(GetModuleHandleW(L"client.dll"), Engine_Trace_Bytes, sizeof(Engine_Trace_Bytes)) - 14);
										};

										static void* Engine_Trace = Find_Engine_Trace();

										using Initialize_Ray_Type = void(__thiscall*)(Ray_Structure* Ray, float* Starting_Location, float* Ending_Location);

										auto Find_Initialize_Ray = [&]() -> void*
										{
											if (Menu_Select::Game_Identifier == 0)
											{
												return (void*)((unsigned __int32)GetModuleHandleW(L"client.dll") + 389296);
											}

											unsigned __int8 Initialize_Ray_Bytes[9] =
											{
												85,

												8,

												243,

												15,

												16,

												0,

												243,

												15,

												92
											};

											return (void*)((unsigned __int32)Byte_Manager::Find_Bytes(GetModuleHandleW(L"client.dll"), Initialize_Ray_Bytes, sizeof(Initialize_Ray_Bytes)) - 23);
										};

										static void* Initialize_Ray_Location = Find_Initialize_Ray();

										Ray_Structure Ray;

										using Get_Eye_Position_Type = void(__thiscall*)(void* Creature, float Eye_Position[3]);

										auto Find_Get_Eye_Position = [&]() -> void*
										{
											if (Menu_Select::Game_Identifier == 0)
											{
												return (void*)((unsigned __int32)GetModuleHandleW(L"client.dll") + 430752);
											}

											unsigned __int8 Get_Eye_Position_Bytes[4] =
											{
												249,

												139,

												143,

												240
											};

											return (void*)((unsigned __int32)Byte_Manager::Find_Bytes(GetModuleHandleW(L"client.dll"), Get_Eye_Position_Bytes, sizeof(Get_Eye_Position_Bytes)) - 11);
										};

										static void* Get_Eye_Position_Location = Find_Get_Eye_Position();

										float Eye_Position[3];

										Get_Eye_Position_Type((unsigned __int32)Get_Eye_Position_Location)(*(void**)Controlled_Creature_Container, Eye_Position);

										float Ray_Starting_Location[3] =
										{
											Eye_Position[0],

											Eye_Position[1],

											Eye_Position[2]
										};

										float Ray_Angle = 0;

										float Ray_Ending_Location_Maximum_Distance = 16 + Strafe_Optimizer_Least_Allowed_Distance_To_Wall;

										float Ray_Ending_Location[3];

										Ray_Ending_Location[2] = Ray_Starting_Location[2];

										Trace_Filter_Structure Trace_Filter;

										auto Find_Trace_Filter_Table = [&]() -> void*
										{
											if (Menu_Select::Game_Identifier == 0)
											{
												return (void*)((unsigned __int32)GetModuleHandleW(L"client.dll") + 3736588);
											}

											unsigned __int8 Trace_Filter_Table_Bytes[4] =
											{
												255,

												15,

												142,

												61
											};

											return *(void**)((unsigned __int32)Byte_Manager::Find_Bytes(GetModuleHandleW(L"client.dll"), Trace_Filter_Table_Bytes, sizeof(Trace_Filter_Table_Bytes)) - 15);
										};

										static void* Trace_Filter_Table_Location = Find_Trace_Filter_Table();

										Trace_Filter.Trace_Filter = Trace_Filter_Table_Location;

										Trace_Structure Trace;

										Trace_Ray_Label:
										{
											if (Ray_Angle < 360)
											{
												float View_Angles_Yaw_Direction = remainderf(Ray_Angle, 360) * (M_PI / 180);

												Ray_Ending_Location[0] = Ray_Starting_Location[0] + cosf(View_Angles_Yaw_Direction) * Ray_Ending_Location_Maximum_Distance;

												Ray_Ending_Location[1] = Ray_Starting_Location[1] + sinf(View_Angles_Yaw_Direction) * Ray_Ending_Location_Maximum_Distance;

												Initialize_Ray_Type((unsigned __int32)Initialize_Ray_Location)(&Ray, Ray_Starting_Location, Ray_Ending_Location);

												Trace_Ray_Type((unsigned __int32)Trace_Ray_Location)(Engine_Trace, &Ray, 33570827, &Trace_Filter, &Trace);

												float Distance = sqrtf(powf(Ray_Starting_Location[0] - Trace.Ending_Location[0], 2) + powf(Ray_Starting_Location[1] - Trace.Ending_Location[1], 2));

												if (Distance > Strafe_Optimizer_Least_Allowed_Distance_To_Wall)
												{
													Ray_Angle += Strafe_Optimizer_Ray_Angle_Step_Offset;

													goto Trace_Ray_Label;
												}
												else
												{
													Optimization_Time = 0;

													goto Stop_Tracing_Ray_Label;
												}
											}
										}

										Optimization_Time = 1;

										Stop_Tracing_Ray_Label:
										{

										}
									}
								}
								else
								{
									Optimization_Time = 0;
								}

								if (Optimization_Time == 1)
								{
									float Strafe_Angle = remainderf(User_Command->View_Angles[1] - atan2f(Velocity[1], Velocity[0]) * 180 / M_PI, 360) * Strafe_Optimizer_Desired_Gain / 100;

									auto Find_Mouse_Sensitivity_Container = [&]() -> void*
									{
										if (Menu_Select::Game_Identifier == 0)
										{
											return (void*)((unsigned __int32)GetModuleHandleW(L"client.dll") + 5193604);
										}

										unsigned __int8 Mouse_Sensitivity_Bytes[8] =
										{
											12,

											243,

											15,

											17,

											68,

											36,

											12,

											139
										};

										return *(void**)((unsigned __int32)Byte_Manager::Find_Bytes(GetModuleHandleW(L"client.dll"), Mouse_Sensitivity_Bytes, sizeof(Mouse_Sensitivity_Bytes)) - 40);
									};

									static void* Mouse_Sensitivity_Container = Find_Mouse_Sensitivity_Container();

									float Mouse_Sensitivity;

									auto Find_Mouse_Yaw_Factor_Container = [&]() -> void*
									{
										if (Menu_Select::Game_Identifier == 0)
										{
											return (void*)((unsigned __int32)GetModuleHandleW(L"client.dll") + 5193388);
										}

										unsigned __int8 Mouse_Yaw_Factor_Bytes[11] =
										{
											12,

											243,

											15,

											16,

											77,

											12,

											243,

											15,

											89,

											77,

											20
										};

										return *(void**)((unsigned __int32)Byte_Manager::Find_Bytes(GetModuleHandleW(L"client.dll"), Mouse_Yaw_Factor_Bytes, sizeof(Mouse_Yaw_Factor_Bytes)) - 35);
									};

									static void* Mouse_Yaw_Factor_Container = Find_Mouse_Yaw_Factor_Container();

									float Mouse_Yaw_Step;

									if (Menu_Select::Game_Identifier == 0)
									{
										Mouse_Sensitivity = *(float*)Mouse_Sensitivity_Container;

										Mouse_Yaw_Step = Mouse_Sensitivity * *(float*)Mouse_Yaw_Factor_Container;
									}
									else
									{
										unsigned __int32 Raw_Mouse_Sensitivity = *(unsigned __int32*)((unsigned __int32)Mouse_Sensitivity_Container + 44) ^ (unsigned __int32)Mouse_Sensitivity_Container;

										Mouse_Sensitivity = *(float*)&Raw_Mouse_Sensitivity;

										unsigned __int32 Raw_Mouse_Yaw_Factor = *(unsigned __int32*)((unsigned __int32)Mouse_Yaw_Factor_Container + 44) ^ (unsigned __int32)Mouse_Yaw_Factor_Container;

										Mouse_Yaw_Step = Mouse_Sensitivity * *(float*)&Raw_Mouse_Yaw_Factor;
									}

									if (User_Command->Move[1] < 0)
									{
										if (Previous_View_Angles_Y - User_Command->View_Angles[1] < 0)
										{
											if (Strafe_Angle < -Mouse_Yaw_Step)
											{
												if (Strafe_Angle < -Strafe_Optimizer_Greatest_Possible_Strafe_Angle)
												{
													Strafe_Angle = -Strafe_Optimizer_Greatest_Possible_Strafe_Angle;
												}

												Previous_View_Angles_Y = User_Command->View_Angles[1];

												User_Command->View_Angles[1] = remainderf(User_Command->View_Angles[1] - Mouse_Yaw_Step * roundf(Strafe_Angle / Mouse_Yaw_Step), 360);

												User_Command->Mouse_Difference_X = (__int16)(Mouse_Sensitivity * ceilf(remainderf(Previous_View_Angles_Y - User_Command->View_Angles[1], 360) / sqrtf(Mouse_Yaw_Step)));

												Set_View_Angles_Type((unsigned __int32)Set_View_Angles_Location)(Engine, User_Command->View_Angles);
											}
										}
									}
									else
									{
										if (User_Command->Move[1] > 0)
										{
											if (Previous_View_Angles_Y - User_Command->View_Angles[1] > 0)
											{
												if (Strafe_Angle > Mouse_Yaw_Step)
												{
													if (Strafe_Angle > Strafe_Optimizer_Greatest_Possible_Strafe_Angle)
													{
														Strafe_Angle = Strafe_Optimizer_Greatest_Possible_Strafe_Angle;
													}

													Previous_View_Angles_Y = User_Command->View_Angles[1];

													User_Command->View_Angles[1] = remainderf(User_Command->View_Angles[1] - Mouse_Yaw_Step * roundf(Strafe_Angle / Mouse_Yaw_Step), 360);

													User_Command->Mouse_Difference_X = (__int16)(Mouse_Sensitivity * ceilf(remainderf(Previous_View_Angles_Y - User_Command->View_Angles[1], 360) / sqrtf(Mouse_Yaw_Step)));

													Set_View_Angles_Type((unsigned __int32)Set_View_Angles_Location)(Engine, User_Command->View_Angles);
												}
											}
										}
									}
								}
							}
							else
							{
								Optimization_Time = 0;
							}
						}
						else
						{
							Optimization_Time = 0;
						}
					}
				}

				Previous_View_Angles_Y = User_Command->View_Angles[1];

				if (Menu_Select::User_Commands_Recorder_Record == 0)
				{
					if (Menu_Select::User_Commands_Recorder_Playback == 0)
					{
						Recorder_User_Comamand_Number = 0;
					}
					else
					{
						if (Recorder_User_Comamand_Number != Recorded_User_Commands.Allocations)
						{
							Compressed_User_Command_Structure* Recorded_User_Command = Recorded_User_Commands.Read(Recorder_User_Comamand_Number);

							User_Command->View_Angles[0] = Recorded_User_Command->View_Angles[0];

							User_Command->View_Angles[1] = Recorded_User_Command->View_Angles[1];

							User_Command->View_Angles[2] = Recorded_User_Command->View_Angles[2];

							Set_View_Angles_Type((unsigned __int32)Set_View_Angles_Location)(Engine, User_Command->View_Angles);

							User_Command->Move[0] = Recorded_User_Command->Move[0];

							User_Command->Move[1] = Recorded_User_Command->Move[1];

							User_Command->Move[2] = Recorded_User_Command->Move[2];

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
				}
				else
				{
					Compressed_User_Command_Structure Recorded_User_Command;

					Recorded_User_Command.View_Angles[0] = User_Command->View_Angles[0];

					Recorded_User_Command.View_Angles[1] = User_Command->View_Angles[1];

					Recorded_User_Command.View_Angles[2] = User_Command->View_Angles[2];

					Recorded_User_Command.Move[0] = User_Command->Move[0];

					Recorded_User_Command.Move[1] = User_Command->Move[1];

					Recorded_User_Command.Move[2] = User_Command->Move[2];

					Recorded_User_Command.Buttons_State = User_Command->Buttons_State;

					Recorded_User_Command.Impulse = User_Command->Impulse;

					Recorded_User_Command.Mouse_Difference_X = User_Command->Mouse_Difference_X;

					Recorded_User_Command.Mouse_Difference_Y = User_Command->Mouse_Difference_Y;

					Recorded_User_Commands.Append(&Recorded_User_Command);

					Recorder_User_Comamand_Number += 1;
				}
			};

			if (Menu_Select::Game_Identifier == 0)
			{
				Provide_Game_Appropriate_User_Command_Type((Source_User_Command_Structure*)User_Command);
			}
			else
			{
				Provide_Game_Appropriate_User_Command_Type((Global_Offensive_User_Command_Structure*)User_Command);
			}

			if (Route_Recorder_Record == 1)
			{
				unsigned __int32 Recorded_Route_Allocations = Recorded_Route.Allocations;

				using Get_Creature_In_World_Location_Type = float*(__thiscall*)(void* Creature);

				auto Find_Get_Creature_In_World_Location_Location = [&]() -> void*
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

				static void* Get_Creature_In_World_Location_Location = Find_Get_Creature_In_World_Location_Location();

				if (Recorded_Route_Allocations == 0)
				{
					Recorded_Route.Append((Route_Structure*)Get_Creature_In_World_Location_Type(Get_Creature_In_World_Location_Location)(*(void**)Controlled_Creature_Container));
				}
				else
				{
					float* Creature_Location = Get_Creature_In_World_Location_Type(Get_Creature_In_World_Location_Location)(*(void**)Controlled_Creature_Container);

					float* Previous_Creature_Location = Recorded_Route.Read(Recorded_Route_Allocations - 1)->Location;

					if (Creature_Location[0] + Creature_Location[1] + Creature_Location[2] != Previous_Creature_Location[0] + Previous_Creature_Location[1] + Previous_Creature_Location[2])
					{
						Recorded_Route.Append((Route_Structure*)Creature_Location);
					}
				}
			}
		}
	}

	using Copy_User_Command_Type = void(__thiscall*)(void* Unknown_Parameter, void* User_Command);

	Copy_User_Command_Type((unsigned __int32)Original_Copy_User_Command_Caller_Location)(Unknown_Parameter_1, User_Command);
}