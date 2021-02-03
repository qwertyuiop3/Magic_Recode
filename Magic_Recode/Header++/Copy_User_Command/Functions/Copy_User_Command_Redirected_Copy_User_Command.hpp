#pragma once

/*
//todo list i can't work on now
optimize prediction call
//do correct logical sorting
//try to use traceray
use up to date traceray
*/

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

			unsigned __int8 Copy_User_Command_In_Create_Move_Return_Location_Bytes[4] =
			{
				95,

				137,

				70,

				100
			};

			return (void*)((unsigned __int32)Byte_Manager::Find_Bytes(sizeof(Copy_User_Command_In_Create_Move_Return_Location_Bytes), GetModuleHandleW(L"client.dll"), Copy_User_Command_In_Create_Move_Return_Location_Bytes, 0) - 10);
		};

		static void* Copy_User_Command_In_Create_Move_Return_Location = Find_Copy_User_Command_In_Create_Move_Return_Location();

		if (__builtin_return_address(0) == Copy_User_Command_In_Create_Move_Return_Location)
		{
			auto Find_Controlled_Creature_Container = []() -> void*
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

				return *(void**)((unsigned __int32)Byte_Manager::Find_Bytes(sizeof(Controlled_Creature_Container_Bytes), GetModuleHandleW(L"client.dll"), Controlled_Creature_Container_Bytes, 0) + 1);
			};

			auto Initialize_Previous_View_Angles_Y = [&]() -> float
			{
				if (Menu_Select::Game_Identifier == 0)
				{
					return ((Source_User_Command_Structure*)User_Command)->View_Angles[1];
				}

				return ((Global_Offensive_User_Command_Structure*)User_Command)->View_Angles[1];
			};

			static float Previous_View_Angles_Y = Initialize_Previous_View_Angles_Y();

			using Set_View_Angles_Type = void(__thiscall*)(void* Engine, float* View_Angles);

			auto Find_Set_View_Angles_Type = []() -> void*
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

				return Byte_Manager::Find_Bytes(sizeof(Set_View_Angles_Bytes), GetModuleHandleW(L"engine.dll"), Set_View_Angles_Bytes, 1);
			};

			auto Find_Engine = []() -> void*
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

				return *(void**)((unsigned __int32)Byte_Manager::Find_Bytes(sizeof(Engine_Bytes), GetModuleHandleW(L"engine.dll"), Engine_Bytes, 0) - 12);
			};

			if (Strafe_Optimizer_Optimize == 1)
			{
				if (Menu_Select::User_Commands_Recorder_Playback == 0)
				{
					auto Find_Prediction = []() -> void*
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

						return **(void***)((unsigned __int32)Byte_Manager::Find_Bytes(sizeof(Prediction_Bytes), GetModuleHandleW(L"engine.dll"), Prediction_Bytes, 0) + 1);
					};

					auto Find_Prediction_Data = []() -> void*
					{
						if (Menu_Select::Game_Identifier == 1)
						{
							return *(void**)((unsigned __int32)GetModuleHandleW(L"engine.dll") + 5828580);
						}

						return nullptr;
					};

					auto Find_Delta_Tick_Container = [](void* Prediction_Data) -> void*
					{
						if (Menu_Select::Game_Identifier == 0)
						{
							return (void*)((unsigned __int32)GetModuleHandleW(L"engine.dll") + 4671440);
						}

						return (void*)((unsigned __int32)Prediction_Data + 372);
					};

					auto Find_Last_Command_Acknowledged_Container = [](void* Prediction_Data) -> void*
					{
						if (Menu_Select::Game_Identifier == 0)
						{
							return (void*)((unsigned __int32)GetModuleHandleW(L"engine.dll") + 4690268);
						}

						return (void*)((unsigned __int32)Prediction_Data + 19764);
					};

					auto Find_Last_Outgoing_Command_Container = [](void* Prediction_Data) -> void*
					{
						if (Menu_Select::Game_Identifier == 0)
						{
							return (void*)((unsigned __int32)GetModuleHandleW(L"engine.dll") + 4690260);
						}

						return (void*)((unsigned __int32)Prediction_Data + 19756);
					};

					auto Find_Choked_Commands_Container = [](void* Prediction_Data) -> void*
					{
						if (Menu_Select::Game_Identifier == 0)
						{
							return (void*)((unsigned __int32)GetModuleHandleW(L"engine.dll") + 4690264);
						}

						return (void*)((unsigned __int32)Prediction_Data + 19760);
					};

					float* Velocity;

					__int8 Optimization_Time;

					if (Menu_Select::Game_Identifier == 0)
					{
						if (((Source_User_Command_Structure*)User_Command)->Move[0] == 0)
						{
							if ((((Source_User_Command_Structure*)User_Command)->Buttons_State & 2) == 2)
							{
								static void* Prediction = Find_Prediction();

								static void* Predict_Location = *(void**)(*(unsigned __int32*)Prediction + 12);

								static void* Prediction_Data = Find_Prediction_Data();

								static void* Delta_Tick_Container = Find_Delta_Tick_Container(Prediction_Data);

								__int32 Delta_Tick = *(__int32*)Delta_Tick_Container;

								static void* Last_Command_Acknowledged_Container = Find_Last_Command_Acknowledged_Container(Prediction_Data);

								static void* Last_Outgoing_Command_Container = Find_Last_Outgoing_Command_Container(Prediction_Data);

								static void* Choked_Commands_Container = Find_Choked_Commands_Container(Prediction_Data);

								using Predict_Type = void(__thiscall*)(void* Prediction, __int32 Delta_Tick, __int8 Valid, __int32 Last_Command_Acknowledged_Container, __int32 Command_Number);

								Predict_Type((unsigned __int32)Predict_Location)(Prediction, Delta_Tick, Delta_Tick > 0, *(__int32*)Last_Command_Acknowledged_Container, *(__int32*)Last_Outgoing_Command_Container + *(__int32*)Choked_Commands_Container);

								static void* Controlled_Creature_Container = Find_Controlled_Creature_Container();

								Velocity = (float*)(*(unsigned __int32*)Controlled_Creature_Container + 244);

								if (sqrtf(Velocity[0] * Velocity[0] + Velocity[1] * Velocity[1]) >= Strafe_Optimizer_Required_Speed)
								{
									if (Strafe_Optimizer_Least_Allowed_Distance_To_Wall == 0)
									{
										Optimization_Time = 1;
									}
									else
									{
										struct Structure_Ray
										{
											__int8 Additional_Bytes[66];
										};

										struct Structure_Trace_Filter
										{
											void* Trace_Filter;
										};

										struct Structure_Trace
										{
											__int8 Additional_Bytes_1[12];

											float Ending_Location[3];

											__int8 Additional_Bytes_2[60];
										};

										using Trace_Ray_Type = void(__thiscall*)(void* Engine_Trace, Structure_Ray* Ray, __int32 Mask, Structure_Trace_Filter* Trace_Filter, Structure_Trace* Trace);

										static void* Trace_Ray_Location = (void*)((unsigned __int32)GetModuleHandleW(L"engine.dll") + 1654560);

										static void* Engine_Trace = *(void**)((unsigned __int32)GetModuleHandleW(L"client.dll") + 5055848);

										using Initialize_Ray_Type = void(__thiscall*)(Structure_Ray* Ray, float* Starting_Location, float* Ending_Location);

										static void* Initialize_Ray_Location = (void*)((unsigned __int32)GetModuleHandleW(L"client.dll") + 389296);

										Structure_Ray Ray;

										float Ray_Angle = 0;

										Structure_Trace_Filter Trace_Filter;

										static void* Trace_Filter_Table_Location = (void*)((unsigned __int32)GetModuleHandleW(L"client.dll") + 3736588);

										Trace_Filter.Trace_Filter = Trace_Filter_Table_Location;

										Structure_Trace Trace;

										Trace_Ray_Label:
										{
											float* Controlled_Creature_In_World_Location = (float*)(*(unsigned __int32*)Controlled_Creature_Container + 824);

											float* Controlled_Creature_View_Offset = (float*)(*(unsigned __int32*)Controlled_Creature_Container + 232);

											float Ray_Starting_Location[3] =
											{
												Controlled_Creature_In_World_Location[0] + Controlled_Creature_View_Offset[0],

												Controlled_Creature_In_World_Location[1] + Controlled_Creature_View_Offset[1],

												Controlled_Creature_In_World_Location[2]
											};

											float View_Angles_Yaw_Direction = remainderf(Ray_Angle, 360) * (M_PI / 180);

											float Ray_Ending_Location_Maximum_Distance = 1 + 16 * Strafe_Optimizer_Least_Allowed_Distance_To_Wall;

											float Ray_Ending_Location[3] =
											{
												Ray_Starting_Location[0] + cosf(View_Angles_Yaw_Direction) * Ray_Ending_Location_Maximum_Distance,

												Ray_Starting_Location[1] + sinf(View_Angles_Yaw_Direction) * Ray_Ending_Location_Maximum_Distance,

												Ray_Starting_Location[2]
											};

											Initialize_Ray_Type((unsigned __int32)Initialize_Ray_Location)(&Ray, Ray_Starting_Location, Ray_Ending_Location);

											Trace_Ray_Type((unsigned __int32)Trace_Ray_Location)(Engine_Trace, &Ray, 33570827, &Trace_Filter, &Trace);

											float Distance = sqrtf(powf(Ray_Starting_Location[0] - Trace.Ending_Location[0], 2) + powf(Ray_Starting_Location[1] - Trace.Ending_Location[1], 2));

											if (Distance > 16 * Strafe_Optimizer_Least_Allowed_Distance_To_Wall)
											{
												Optimization_Time = 1;
											}
											else
											{
												Optimization_Time = 0;

												goto Stop_Tracing_Ray_Label;
											}

											if (Ray_Angle != 270)
											{
												Ray_Angle += 90;

												goto Trace_Ray_Label;
											}
										}

										Stop_Tracing_Ray_Label:
										{

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
						else
						{
							Optimization_Time = 0;
						}
					}
					else
					{
						if (((Global_Offensive_User_Command_Structure*)User_Command)->Move[0] == 0)
						{
							if ((((Global_Offensive_User_Command_Structure*)User_Command)->Buttons_State & 2) == 2)
							{
								static void* Prediction = Find_Prediction();

								static void* Predict_Location = *(void**)(*(unsigned __int32*)Prediction + 12);

								static void* Prediction_Data = Find_Prediction_Data();

								static void* Delta_Tick_Container = Find_Delta_Tick_Container(Prediction_Data);

								__int32 Delta_Tick = *(__int32*)Delta_Tick_Container;

								static void* Last_Command_Acknowledged_Container = Find_Last_Command_Acknowledged_Container(Prediction_Data);

								static void* Last_Outgoing_Command_Container = Find_Last_Outgoing_Command_Container(Prediction_Data);

								static void* Choked_Commands_Container = Find_Choked_Commands_Container(Prediction_Data);

								using Predict_Type = void(__thiscall*)(void* Prediction, __int32 Delta_Tick, __int8 Valid, __int32 Last_Command_Acknowledged_Container, __int32 Command_Number);

								Predict_Type((unsigned __int32)Predict_Location)(Prediction, Delta_Tick, Delta_Tick > 0, *(__int32*)Last_Command_Acknowledged_Container, *(__int32*)Last_Outgoing_Command_Container + *(__int32*)Choked_Commands_Container);

								static void* Controlled_Creature_Container = Find_Controlled_Creature_Container();

								Velocity = (float*)(*(unsigned __int32*)Controlled_Creature_Container + 276);

								if (sqrtf(Velocity[0] * Velocity[0] + Velocity[1] * Velocity[1]) >= Strafe_Optimizer_Required_Speed)
								{
									Optimization_Time = 1;
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
						else
						{
							Optimization_Time = 0;
						}
					}

					if (Optimization_Time == 1)
					{
						auto Find_Mouse_Sensitivity_Container = []() -> void*
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

							return *(void**)((unsigned __int32)Byte_Manager::Find_Bytes(sizeof(Mouse_Sensitivity_Bytes), GetModuleHandleW(L"client.dll"), Mouse_Sensitivity_Bytes, 0) - 33);
						};

						auto Find_Mouse_Yaw_Factor_Container = []() -> void*
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

							return *(void**)((unsigned __int32)Byte_Manager::Find_Bytes(sizeof(Mouse_Yaw_Factor_Bytes), GetModuleHandleW(L"client.dll"), Mouse_Yaw_Factor_Bytes, 0) - 25);
						};

						if (Menu_Select::Game_Identifier == 0)
						{
							if (((Source_User_Command_Structure*)User_Command)->Move[1] < 0)
							{
								if (Previous_View_Angles_Y - ((Source_User_Command_Structure*)User_Command)->View_Angles[1] < 0)
								{
									float Strafe_Angle = remainderf(((Source_User_Command_Structure*)User_Command)->View_Angles[1] - atan2f(Velocity[1], Velocity[0]) * 180 / M_PI, 360) * Strafe_Optimizer_Desired_Gain / 100;

									static void* Mouse_Sensitivity_Container = Find_Mouse_Sensitivity_Container();

									float Mouse_Sensitivity = *(float*)Mouse_Sensitivity_Container;

									static void* Mouse_Yaw_Factor_Container = Find_Mouse_Yaw_Factor_Container();

									float Mouse_Yaw_Factor = *(float*)Mouse_Yaw_Factor_Container;

									float Mouse_Yaw_Step = Mouse_Sensitivity * Mouse_Yaw_Factor;

									if (Strafe_Angle < -Mouse_Yaw_Step)
									{
										if (Strafe_Angle < -Strafe_Optimizer_Greatest_Possible_Strafe_Angle)
										{
											Strafe_Angle = -Strafe_Optimizer_Greatest_Possible_Strafe_Angle;
										}

										Previous_View_Angles_Y = ((Source_User_Command_Structure*)User_Command)->View_Angles[1];

										((Source_User_Command_Structure*)User_Command)->View_Angles[1] = remainderf(((Source_User_Command_Structure*)User_Command)->View_Angles[1] - Mouse_Yaw_Step * roundf(Strafe_Angle / Mouse_Yaw_Step), 360);

										((Source_User_Command_Structure*)User_Command)->Mouse_Difference_X = (__int16)(Mouse_Sensitivity * ceilf(remainderf(Previous_View_Angles_Y - ((Source_User_Command_Structure*)User_Command)->View_Angles[1], 360) / sqrtf(Mouse_Yaw_Step)));

										static void* Set_View_Angles_Location = Find_Set_View_Angles_Type();

										static void* Engine = Find_Engine();

										Set_View_Angles_Type((unsigned __int32)Set_View_Angles_Location)(Engine, ((Source_User_Command_Structure*)User_Command)->View_Angles);
									}
								}
							}
							else
							{
								if (((Source_User_Command_Structure*)User_Command)->Move[1] > 0)
								{
									if (Previous_View_Angles_Y - ((Source_User_Command_Structure*)User_Command)->View_Angles[1] > 0)
									{
										float Strafe_Angle = remainderf(((Source_User_Command_Structure*)User_Command)->View_Angles[1] - atan2f(Velocity[1], Velocity[0]) * 180 / M_PI, 360) * Strafe_Optimizer_Desired_Gain / 100;

										static void* Mouse_Sensitivity_Container = Find_Mouse_Sensitivity_Container();

										float Mouse_Sensitivity = *(float*)Mouse_Sensitivity_Container;

										static void* Mouse_Yaw_Factor_Container = Find_Mouse_Yaw_Factor_Container();

										float Mouse_Yaw_Factor = *(float*)Mouse_Yaw_Factor_Container;

										float Mouse_Yaw_Step = Mouse_Sensitivity * Mouse_Yaw_Factor;

										if (Strafe_Angle > Mouse_Yaw_Step)
										{
											if (Strafe_Angle > Strafe_Optimizer_Greatest_Possible_Strafe_Angle)
											{
												Strafe_Angle = Strafe_Optimizer_Greatest_Possible_Strafe_Angle;
											}

											Previous_View_Angles_Y = ((Source_User_Command_Structure*)User_Command)->View_Angles[1];

											((Source_User_Command_Structure*)User_Command)->View_Angles[1] = remainderf(((Source_User_Command_Structure*)User_Command)->View_Angles[1] - Mouse_Yaw_Step * roundf(Strafe_Angle / Mouse_Yaw_Step), 360);

											((Source_User_Command_Structure*)User_Command)->Mouse_Difference_X = (__int16)(Mouse_Sensitivity * ceilf(remainderf(Previous_View_Angles_Y - ((Source_User_Command_Structure*)User_Command)->View_Angles[1], 360) / sqrtf(Mouse_Yaw_Step)));

											static void* Set_View_Angles_Location = Find_Set_View_Angles_Type();

											static void* Engine = Find_Engine();

											Set_View_Angles_Type((unsigned __int32)Set_View_Angles_Location)(Engine, ((Source_User_Command_Structure*)User_Command)->View_Angles);
										}
									}
								}
							}
						}
						else
						{
							if (((Global_Offensive_User_Command_Structure*)User_Command)->Move[1] < 0)
							{
								if (Previous_View_Angles_Y - ((Global_Offensive_User_Command_Structure*)User_Command)->View_Angles[1] < 0)
								{
									float Strafe_Angle = remainderf(((Global_Offensive_User_Command_Structure*)User_Command)->View_Angles[1] - atan2f(Velocity[1], Velocity[0]) * 180 / M_PI, 360) * Strafe_Optimizer_Desired_Gain / 100;

									static void* Mouse_Sensitivity_Container = Find_Mouse_Sensitivity_Container();

									unsigned __int32 Raw_Mouse_Sensitivity = *(unsigned __int32*)((unsigned __int32)Mouse_Sensitivity_Container + 44) ^ (unsigned __int32)Mouse_Sensitivity_Container;

									float Mouse_Sensitivity = *(float*)&Raw_Mouse_Sensitivity;

									static void* Mouse_Yaw_Factor_Container = Find_Mouse_Yaw_Factor_Container();

									unsigned __int32 Raw_Mouse_Yaw_Factor = *(unsigned __int32*)((unsigned __int32)Mouse_Yaw_Factor_Container + 44) ^ (unsigned __int32)Mouse_Yaw_Factor_Container;

									float Mouse_Yaw_Factor = *(float*)&Raw_Mouse_Yaw_Factor;

									float Mouse_Yaw_Step = Mouse_Sensitivity * Mouse_Yaw_Factor;

									if (Strafe_Angle < -Mouse_Yaw_Step)
									{
										if (Strafe_Angle < -Strafe_Optimizer_Greatest_Possible_Strafe_Angle)
										{
											Strafe_Angle = -Strafe_Optimizer_Greatest_Possible_Strafe_Angle;
										}

										Previous_View_Angles_Y = ((Global_Offensive_User_Command_Structure*)User_Command)->View_Angles[1];

										((Global_Offensive_User_Command_Structure*)User_Command)->View_Angles[1] = remainderf(((Global_Offensive_User_Command_Structure*)User_Command)->View_Angles[1] - Mouse_Yaw_Step * roundf(Strafe_Angle / Mouse_Yaw_Step), 360);

										((Global_Offensive_User_Command_Structure*)User_Command)->Mouse_Difference_X = (__int16)(Mouse_Sensitivity * ceilf(remainderf(Previous_View_Angles_Y - ((Global_Offensive_User_Command_Structure*)User_Command)->View_Angles[1], 360) / sqrtf(Mouse_Yaw_Step)));

										static void* Set_View_Angles_Location = Find_Set_View_Angles_Type();

										static void* Engine = Find_Engine();

										Set_View_Angles_Type((unsigned __int32)Set_View_Angles_Location)(Engine, ((Global_Offensive_User_Command_Structure*)User_Command)->View_Angles);
									}
								}
							}
							else
							{
								if (((Global_Offensive_User_Command_Structure*)User_Command)->Move[1] > 0)
								{
									if (Previous_View_Angles_Y - ((Global_Offensive_User_Command_Structure*)User_Command)->View_Angles[1] > 0)
									{
										float Strafe_Angle = remainderf(((Global_Offensive_User_Command_Structure*)User_Command)->View_Angles[1] - atan2f(Velocity[1], Velocity[0]) * 180 / M_PI, 360) * Strafe_Optimizer_Desired_Gain / 100;

										static void* Mouse_Sensitivity_Container = Find_Mouse_Sensitivity_Container();

										unsigned __int32 Raw_Mouse_Sensitivity = *(unsigned __int32*)((unsigned __int32)Mouse_Sensitivity_Container + 44) ^ (unsigned __int32)Mouse_Sensitivity_Container;

										float Mouse_Sensitivity = *(float*)&Raw_Mouse_Sensitivity;

										static void* Mouse_Yaw_Factor_Container = Find_Mouse_Yaw_Factor_Container();

										unsigned __int32 Raw_Mouse_Yaw_Factor = *(unsigned __int32*)((unsigned __int32)Mouse_Yaw_Factor_Container + 44) ^ (unsigned __int32)Mouse_Yaw_Factor_Container;

										float Mouse_Yaw_Factor = *(float*)&Raw_Mouse_Yaw_Factor;

										float Mouse_Yaw_Step = Mouse_Sensitivity * Mouse_Yaw_Factor;

										if (Strafe_Angle > Mouse_Yaw_Step)
										{
											if (Strafe_Angle > Strafe_Optimizer_Greatest_Possible_Strafe_Angle)
											{
												Strafe_Angle = Strafe_Optimizer_Greatest_Possible_Strafe_Angle;
											}

											Previous_View_Angles_Y = ((Global_Offensive_User_Command_Structure*)User_Command)->View_Angles[1];

											((Global_Offensive_User_Command_Structure*)User_Command)->View_Angles[1] = remainderf(((Global_Offensive_User_Command_Structure*)User_Command)->View_Angles[1] - Mouse_Yaw_Step * roundf(Strafe_Angle / Mouse_Yaw_Step), 360);

											((Global_Offensive_User_Command_Structure*)User_Command)->Mouse_Difference_X = (__int16)(Mouse_Sensitivity * ceilf(remainderf(Previous_View_Angles_Y - ((Global_Offensive_User_Command_Structure*)User_Command)->View_Angles[1], 360) / sqrtf(Mouse_Yaw_Step)));

											static void* Set_View_Angles_Location = Find_Set_View_Angles_Type();

											static void* Engine = Find_Engine();

											Set_View_Angles_Type((unsigned __int32)Set_View_Angles_Location)(Engine, ((Global_Offensive_User_Command_Structure*)User_Command)->View_Angles);
										}
									}
								}
							}
						}
					}
				}
			}

			if (Menu_Select::Game_Identifier == 0)
			{
				Previous_View_Angles_Y = ((Source_User_Command_Structure*)User_Command)->View_Angles[1];
			}
			else
			{
				Previous_View_Angles_Y = ((Global_Offensive_User_Command_Structure*)User_Command)->View_Angles[1];
			}

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
						static void* Set_View_Angles_Location = Find_Set_View_Angles_Type();

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
