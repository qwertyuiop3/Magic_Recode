#pragma once

unsigned __int32 __stdcall Redirected_Present(IDirect3DDevice9* Direct_3_Dimensional_Device_9, void* Unknown_Parameter_1, void* Unknown_Parameter_2, void* Unknown_Parameter_3, void* Unknown_Parameter_4)
{
	if (Window_Procedure::Visuals_Recorded_Route_Draw == 1)
	{
		unsigned __int32 Recorded_Route_Allocations = Copy_User_Command::Recorded_Route.Allocations;

		if (Recorded_Route_Allocations > Visuals_Recorded_Route_Step_Length)
		{
			auto Find_View_Matrix_Location = [&]() -> float*
			{
				if (Menu_Select::Game_Identifier == 0)
				{
					return (float*)((unsigned __int32)GetModuleHandleW(L"engine.dll") + 5954552);
				}

				unsigned __int8 View_Matrix_Bytes[5] =
				{
					80,

					15,

					17,

					133,

					120
				};

				return (float*)(*(unsigned __int32*)((unsigned __int32)Byte_Manager::Find_Bytes(GetModuleHandleW(L"client.dll"), View_Matrix_Bytes, sizeof(View_Matrix_Bytes)) - 12) + 128);
			};

			static float* View_Matrix_Location = Find_View_Matrix_Location();

			D3DVIEWPORT9 Direct_3_Dimensional_Viewport_9;

			Direct_3_Dimensional_Device_9->GetViewport(&Direct_3_Dimensional_Viewport_9);

			float Screen_Width = (float)Direct_3_Dimensional_Viewport_9.Width;

			float Screen_Height = (float)Direct_3_Dimensional_Viewport_9.Height;

			auto In_World_Location_To_On_Screen_Location = [&](float* In_World_Location, float* On_Screen_Location) -> __int8
			{
				float W = In_World_Location[0] * View_Matrix_Location[12] + View_Matrix_Location[13] * In_World_Location[1] + View_Matrix_Location[14] * In_World_Location[2] + View_Matrix_Location[15];

				if (W != 0)
				{
						On_Screen_Location[0] = 0.5f * ((View_Matrix_Location[0] * In_World_Location[0] + View_Matrix_Location[1] * In_World_Location[1] + View_Matrix_Location[2] * In_World_Location[2] + View_Matrix_Location[3]) / W) * Screen_Width + 0.5f * Screen_Width;

						On_Screen_Location[1] = -0.5f * ((View_Matrix_Location[4] * In_World_Location[0] + View_Matrix_Location[5] * In_World_Location[1] + View_Matrix_Location[6] * In_World_Location[2] + View_Matrix_Location[7]) / W) * Screen_Height + 0.5f * Screen_Height;

						return 1;
				}

				return 0;
			};

			unsigned __int32 Recorded_Route_Number = Visuals_Recorded_Route_Step_Length;

			Direct_3_Dimensional_Device_9->SetRenderState(D3DRS_SRGBWRITEENABLE, 0);

			unsigned long __int32 Previous_Direct_3_Dimensional_Render_State_Destination_Blend;

			Direct_3_Dimensional_Device_9->GetRenderState(D3DRS_DESTBLEND, &Previous_Direct_3_Dimensional_Render_State_Destination_Blend);

			Direct_3_Dimensional_Device_9->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

			Direct_3_Dimensional_Device_9->SetTexture(0, nullptr);

			Direct_3_Dimensional_Device_9->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);

			Direct_3_Dimensional_Device_9->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_DIFFUSE);

			Direct_3_Dimensional_Device_9->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_TEXTURE);

			IDirect3DVertexDeclaration9* Previous_Direct_3_Dimensional_Vertex_Declaration_9;

			Direct_3_Dimensional_Device_9->GetVertexDeclaration(&Previous_Direct_3_Dimensional_Vertex_Declaration_9);

			Direct_3_Dimensional_Device_9->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE);

			IDirect3DPixelShader9* Previous_Direct_3_Dimensional_Pixel_Shader_9;

			Direct_3_Dimensional_Device_9->GetPixelShader(&Previous_Direct_3_Dimensional_Pixel_Shader_9);

			Direct_3_Dimensional_Device_9->SetPixelShader(nullptr);

			__int8 Stop_Drawing_Recorded_Route = 0;

			unsigned __int32 Recorded_Route_Allocations_With_Subtracted_Step = Recorded_Route_Allocations - Visuals_Recorded_Route_Step_Length;

			Draw_Recorded_Route_Label:
			{
				unsigned __int32 Recorded_Route_Number_With_Subtracted_Step = Recorded_Route_Number - Visuals_Recorded_Route_Step_Length;

				float Recorded_Route_On_Screen_Location_From[2];

				if (In_World_Location_To_On_Screen_Location((float*)Copy_User_Command::Recorded_Route.Read(Recorded_Route_Number_With_Subtracted_Step), Recorded_Route_On_Screen_Location_From) == 1)
				{
					float Recorded_Route_On_Screen_Location_To[2];

					if (In_World_Location_To_On_Screen_Location((float*)Copy_User_Command::Recorded_Route.Read(Recorded_Route_Number), Recorded_Route_On_Screen_Location_To) == 1)
					{
						struct Vertex_Structure
						{
							float X;

							float Y;

							float Z;

							float Reciprocal_Homogeneous_W;

							unsigned __int32 Color;
						};

						auto Hue_To_Alpha_Red_Green_Blue = [](float Hue) -> unsigned __int32
						{
							if (Hue < 60)
							{
								return D3DCOLOR_ARGB(255, 255, (unsigned __int8)((1 - fabsf(fmodf(Hue / 60, 2) - 1)) * 255), 0);
							}

							if (Hue < 120)
							{
								return D3DCOLOR_ARGB(255, (unsigned __int8)((1 - fabsf(fmodf(Hue / 60, 2) - 1)) * 255), 255, 0);
							}

							if (Hue < 180)
							{
								return D3DCOLOR_ARGB(255, 0, 255, (unsigned __int8)((1 - fabsf(fmodf(Hue / 60, 2) - 1)) * 255));
							}

							if (Hue < 240)
							{
								return D3DCOLOR_ARGB(255, 0, (unsigned __int8)((1 - fabsf(fmodf(Hue / 60, 2) - 1)) * 255), 255);
							}

							if (Hue < 300)
							{
								return D3DCOLOR_ARGB(255, (unsigned __int8)((1 - fabsf(fmodf(Hue / 60, 2) - 1)) * 255), 0, 255);
							}

							return D3DCOLOR_ARGB(255, 255, 0, (unsigned __int8)((1 - fabsf(fmodf(Hue / 60, 2) - 1)) * 255));
						};

						Vertex_Structure Vertices[2]
						{
							{
								Recorded_Route_On_Screen_Location_From[0],

								Recorded_Route_On_Screen_Location_From[1],

								0,

								0,

								Hue_To_Alpha_Red_Green_Blue((float)(Recorded_Route_Number_With_Subtracted_Step % 361))
							},

							{
								Recorded_Route_On_Screen_Location_To[0],

								Recorded_Route_On_Screen_Location_To[1],

								0,

								0,

								Hue_To_Alpha_Red_Green_Blue((float)(Recorded_Route_Number % 361))
							}
						};

						Direct_3_Dimensional_Device_9->DrawPrimitiveUP(D3DPT_LINELIST, 1, Vertices, sizeof(Vertex_Structure));
					}
				}

				if (Stop_Drawing_Recorded_Route == 0)
				{
					if (Recorded_Route_Number < Recorded_Route_Allocations_With_Subtracted_Step)
					{
						Recorded_Route_Number += Visuals_Recorded_Route_Step_Length;
					}
					else
					{
						Recorded_Route_Number = Recorded_Route_Allocations - 1;

						Stop_Drawing_Recorded_Route = 1;
					}

					goto Draw_Recorded_Route_Label;
				}
			}

			Direct_3_Dimensional_Device_9->SetRenderState(D3DRS_DESTBLEND, Previous_Direct_3_Dimensional_Render_State_Destination_Blend);

			Direct_3_Dimensional_Device_9->SetRenderState(D3DRS_SRGBWRITEENABLE, 1);

			Direct_3_Dimensional_Device_9->SetVertexDeclaration(Previous_Direct_3_Dimensional_Vertex_Declaration_9);

			Direct_3_Dimensional_Device_9->SetPixelShader(Previous_Direct_3_Dimensional_Pixel_Shader_9);
		}
	}

	if (Controller_Move::Draw_Graphical_User_Interface == 1)
	{
		ImGui_ImplDX9_NewFrame();

		ImGui_ImplWin32_NewFrame();

		ImGui::NewFrame();

		ImGui::Begin("User Commands", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoNavInputs);

		static __int8 Setting_Up_Keybind[3] =
		{
			0,

			0,

			0
		};

		__int8 Keybind_Number = 0;

		auto Setup_Keybind = [&](char* Function_Name, unsigned __int8& Key_Number) -> void
		{
			if (Setting_Up_Keybind[Keybind_Number] == 0)
			{
				Draw_Keybind:
				{
					char Formatted_Button_Name[30];

					sprintf_s(Formatted_Button_Name, "%s Bound To Function %i", Function_Name, Key_Number - (VK_F1 - 1));

					if (ImGui::Button(Formatted_Button_Name) == 1)
					{
						if (Window_Procedure::Setting_Up_Keybinds == 0)
						{
							Window_Procedure::Setting_Up_Keybinds = 1;

							Setting_Up_Keybind[Keybind_Number] = 1;
						}
					}
				}
			}
			else
			{
				unsigned __int8 Function_Key_Number = VK_F1;

				Function_Key_Released_Check_Label:
				{
					if (Function_Key_Number != VK_F24 + 1)
					{
						if (ImGui::IsKeyReleased(Function_Key_Number) == 1)
						{
							Window_Procedure::Setting_Up_Keybinds = 0;

							Setting_Up_Keybind[Keybind_Number] = 0;

							Key_Number = Function_Key_Number;

							goto Draw_Keybind;
						}

						Function_Key_Number += 1;

						goto Function_Key_Released_Check_Label;
					}
				}

				ImGui::Button("Press Any Function Key");
			}

			Keybind_Number += 1;
		};

		if (ImGui::TreeNodeEx("Strafe Optimizer", ImGuiTreeNodeFlags_Framed | ImGuiTreeNodeFlags_NoAutoOpenOnLog) == 1)
		{
			ImGui::Checkbox("Optimize", (bool*)&Copy_User_Command::Strafe_Optimizer_Optimize);

			if (ImGui::DragScalar("Required Speed", ImGuiDataType_Float, &Copy_User_Command::Strafe_Optimizer_Required_Speed, 1, nullptr, nullptr, "%.0f") == 1)
			{
				if (Copy_User_Command::Strafe_Optimizer_Required_Speed < 0)
				{
					Copy_User_Command::Strafe_Optimizer_Required_Speed = 0;
				}
			}

			if (ImGui::DragScalar("Least Allowed Distance To Wall", ImGuiDataType_Float, &Copy_User_Command::Strafe_Optimizer_Least_Allowed_Distance_To_Wall, 1, nullptr, nullptr, "%.2f") == 1)
			{
				if (Copy_User_Command::Strafe_Optimizer_Least_Allowed_Distance_To_Wall < 0)
				{
					Copy_User_Command::Strafe_Optimizer_Least_Allowed_Distance_To_Wall = 0;
				}
			}

			if (ImGui::DragScalar("Ray Angle Step Offset", ImGuiDataType_Float, &Copy_User_Command::Strafe_Optimizer_Ray_Angle_Step_Offset, 1, nullptr, nullptr, "%.7f") == 1)
			{
				if (Copy_User_Command::Strafe_Optimizer_Ray_Angle_Step_Offset < 1)
				{
					Copy_User_Command::Strafe_Optimizer_Ray_Angle_Step_Offset = 1;
				}
				else
				{
					if (Copy_User_Command::Strafe_Optimizer_Ray_Angle_Step_Offset > 180)
					{
						Copy_User_Command::Strafe_Optimizer_Ray_Angle_Step_Offset = 180;
					}
				}
			}

			if (ImGui::DragScalar("Desired Gain", ImGuiDataType_Float, &Copy_User_Command::Strafe_Optimizer_Desired_Gain, 1, nullptr, nullptr, "%.2f") == 1)
			{
				if (Copy_User_Command::Strafe_Optimizer_Desired_Gain < 0)
				{
					Copy_User_Command::Strafe_Optimizer_Desired_Gain = 0;
				}
				else
				{
					if (Copy_User_Command::Strafe_Optimizer_Desired_Gain > 100)
					{
						Copy_User_Command::Strafe_Optimizer_Desired_Gain = 100;
					}
				}
			}

			if (ImGui::DragScalar("Greatest Possible Strafe Angle", ImGuiDataType_Float, &Copy_User_Command::Strafe_Optimizer_Greatest_Possible_Strafe_Angle, 1, nullptr, nullptr, "%.2f") == 1)
			{
				if (Copy_User_Command::Strafe_Optimizer_Greatest_Possible_Strafe_Angle < 0)
				{
					Copy_User_Command::Strafe_Optimizer_Greatest_Possible_Strafe_Angle = 0;
				}
				else
				{
					if (Copy_User_Command::Strafe_Optimizer_Greatest_Possible_Strafe_Angle > 180)
					{
						Copy_User_Command::Strafe_Optimizer_Greatest_Possible_Strafe_Angle = 180;
					}
				}
			}

			if (ImGui::TreeNodeEx("Keybinds", ImGuiTreeNodeFlags_Framed | ImGuiTreeNodeFlags_NoAutoOpenOnLog) == 1)
			{
				Setup_Keybind((char*)"Optimize", Window_Procedure::User_Commands_Strafe_Optimizer_Optimize_Bound_To);

				ImGui::TreePop();
			}

			ImGui::TreePop();
		}

		auto Find_Map_Name = [&]() -> wchar_t*
		{
			if (Menu_Select::Game_Identifier == 0)
			{
				return (wchar_t*)((unsigned __int32)GetModuleHandleW(L"client.dll") + 5245916);
			}

			unsigned __int8 Map_Name_Bytes[7] =
			{
				83,

				139,

				1,

				255,

				80,

				60,

				184
			};

			return *(wchar_t**)((unsigned __int32)Byte_Manager::Find_Bytes(GetModuleHandleW(L"client.dll"), Map_Name_Bytes, sizeof(Map_Name_Bytes)) + 7);
		};

		static wchar_t* Map_Name = Find_Map_Name();

		unsigned __int32 Map_Name_Length = wcslen(Map_Name) * 2;

		wchar_t* Adjusted_Map_Name = (wchar_t*)malloc(Map_Name_Length + 6);

		Byte_Manager::Copy_Bytes(0, Adjusted_Map_Name, Map_Name_Length, (unsigned __int8*)Map_Name);

		*(wchar_t*)((unsigned __int32)Adjusted_Map_Name + Map_Name_Length) = L'-';

		static __int8 File_Number = 0;

		*(__int16*)((unsigned __int32)Adjusted_Map_Name + Map_Name_Length + 2) = 48 + File_Number;

		*(__int16*)((unsigned __int32)Adjusted_Map_Name + Map_Name_Length + 4) = 0;

		auto File_Number_Editor = [&]()
		{
			if (ImGui::DragScalar("File Number", ImGuiDataType_S8, &File_Number, 1, nullptr, nullptr, "%i") == 1)
			{
				if (File_Number < 0)
				{
					File_Number = 0;
				}
				else
				{
					if (File_Number > 9)
					{
						File_Number = 9;
					}
				}
			}
		};

		if (ImGui::TreeNodeEx("Recorder", ImGuiTreeNodeFlags_Framed | ImGuiTreeNodeFlags_NoAutoOpenOnLog) == 1)
		{
			if (ImGui::Checkbox("Record", (bool*)&Menu_Select::User_Commands_Recorder_Record) == 1)
			{
				if (Menu_Select::User_Commands_Recorder_Record == 1)
				{
					if (Menu_Select::User_Commands_Recorder_Playback == 0)
					{
						Copy_User_Command::Recorded_User_Commands.Clear();
					}
					else
					{

						Menu_Select::User_Commands_Recorder_Playback = 0;

						Copy_User_Command::Recorded_User_Commands.Reallocate(Copy_User_Command::Recorder_User_Comamand_Number);
					}
				}
			}

			if (Menu_Select::User_Commands_Recorder_Record == 0)
			{
				if (Copy_User_Command::Recorded_User_Commands.Allocations == 0)
				{
					File_Number_Editor();

					if (ImGui::Button("Save To File") == 1)
					{
						void* Recorded_User_Commands_File_Handle = CreateFileW(Adjusted_Map_Name, FILE_WRITE_DATA, 0, nullptr, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);

						unsigned __int32 Recorded_User_Commands_Allocations = Copy_User_Command::Recorded_User_Commands.Allocations;

						unsigned long __int32 Recorded_User_Commands_Accessed_Bytes_Count;

						WriteFile(Recorded_User_Commands_File_Handle, &Recorded_User_Commands_Allocations, sizeof(unsigned __int32), &Recorded_User_Commands_Accessed_Bytes_Count, nullptr);

						SetFilePointer(Recorded_User_Commands_File_Handle, sizeof(unsigned __int32), nullptr, FILE_BEGIN);

						WriteFile(Recorded_User_Commands_File_Handle, Copy_User_Command::Recorded_User_Commands.Read(0), Recorded_User_Commands_Allocations * sizeof(Copy_User_Command::Compressed_User_Command_Structure), &Recorded_User_Commands_Accessed_Bytes_Count, nullptr);

						CloseHandle(Recorded_User_Commands_File_Handle);
					}
				}
			}

			if (ImGui::TreeNodeEx("Keybinds", ImGuiTreeNodeFlags_Framed | ImGuiTreeNodeFlags_NoAutoOpenOnLog) == 1)
			{
				Setup_Keybind((char*)"Record", Window_Procedure::User_Commands_Recorder_Record_Bound_To);

				ImGui::TreePop();
			}

			ImGui::TreePop();
		}

		if (ImGui::TreeNodeEx("Player", ImGuiTreeNodeFlags_Framed | ImGuiTreeNodeFlags_NoAutoOpenOnLog) == 1)
		{
			if (Menu_Select::User_Commands_Recorder_Record == 0)
			{
				auto Load_From_File_Button = [&]()
				{
					if (GetFileAttributesW(Adjusted_Map_Name) != -1)
					{
						if (ImGui::Button("Load From File") == 1)
						{
							void* Recorded_User_Commands_File_Handle = CreateFileW(Adjusted_Map_Name, FILE_READ_DATA, 0, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);

							unsigned __int32 Recorded_User_Commands_Allocations;

							unsigned long __int32 Recorded_User_Commands_Accessed_Bytes_Count;

							ReadFile(Recorded_User_Commands_File_Handle, &Recorded_User_Commands_Allocations, sizeof(unsigned __int32), &Recorded_User_Commands_Accessed_Bytes_Count, nullptr);

							Copy_User_Command::Recorded_User_Commands.Reallocate(Recorded_User_Commands_Allocations);

							SetFilePointer(Recorded_User_Commands_File_Handle, sizeof(unsigned __int32), nullptr, FILE_BEGIN);

							ReadFile(Recorded_User_Commands_File_Handle, Copy_User_Command::Recorded_User_Commands.Read(0), Recorded_User_Commands_Allocations * sizeof(Copy_User_Command::Compressed_User_Command_Structure), &Recorded_User_Commands_Accessed_Bytes_Count, nullptr);

							CloseHandle(Recorded_User_Commands_File_Handle);
						}
					}
				};

				if (Copy_User_Command::Recorded_User_Commands.Allocations == 0)
				{
					if (Menu_Select::User_Commands_Recorder_Playback == 0)
					{
						File_Number_Editor();

						Load_From_File_Button();
					}

					if (ImGui::Checkbox("Playback", (bool*)&Menu_Select::User_Commands_Recorder_Playback) == 1)
					{
						Menu_Select::User_Commands_Recorder_Record = 0;
					}

					if (ImGui::TreeNodeEx("Keybinds", ImGuiTreeNodeFlags_Framed | ImGuiTreeNodeFlags_NoAutoOpenOnLog) == 1)
					{
						Setup_Keybind((char*)"Playback", Window_Procedure::User_Commands_Recorder_Playback_Bound_To);

						ImGui::TreePop();
					}
				}
				else
				{
					File_Number_Editor();

					Load_From_File_Button();
				}
			}

			ImGui::TreePop();
		}

		ImGui::End();

		ImGui::Begin("Route", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoNavInputs);

		*(wchar_t*)((unsigned __int32)Adjusted_Map_Name + Map_Name_Length) = L'_';

		if (ImGui::TreeNodeEx("Recorder", ImGuiTreeNodeFlags_Framed | ImGuiTreeNodeFlags_NoAutoOpenOnLog) == 1)
		{
			if (Window_Procedure::Visuals_Recorded_Route_Draw == 0)
			{
				if (ImGui::Checkbox("Record", (bool*)&Copy_User_Command::Route_Recorder_Record) == 1)
				{
					if (Copy_User_Command::Route_Recorder_Record == 1)
					{
						Copy_User_Command::Recorded_Route.Clear();
					}
				}
			}

			if (Copy_User_Command::Route_Recorder_Record == 0)
			{
				if (Copy_User_Command::Recorded_Route.Allocations == 0)
				{
					File_Number_Editor();

					if (ImGui::Button("Save To File") == 1)
					{
						void* Recorded_Route_File_Handle = CreateFileW(Adjusted_Map_Name, FILE_WRITE_DATA, 0, nullptr, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);

						unsigned __int32 Recorded_Route_Allocations = Copy_User_Command::Recorded_Route.Allocations;

						unsigned long __int32 Recorded_Route_Accessed_Bytes_Count;

						WriteFile(Recorded_Route_File_Handle, &Recorded_Route_Allocations, sizeof(unsigned __int32), &Recorded_Route_Accessed_Bytes_Count, nullptr);

						SetFilePointer(Recorded_Route_File_Handle, sizeof(unsigned __int32), nullptr, FILE_BEGIN);

						WriteFile(Recorded_Route_File_Handle, Copy_User_Command::Recorded_Route.Read(0), Recorded_Route_Allocations * sizeof(Copy_User_Command::Route_Structure), &Recorded_Route_Accessed_Bytes_Count, nullptr);

						CloseHandle(Recorded_Route_File_Handle);
					}
				}
			}

			if (Window_Procedure::Visuals_Recorded_Route_Draw == 0)
			{
				if (ImGui::TreeNodeEx("Keybinds", ImGuiTreeNodeFlags_Framed | ImGuiTreeNodeFlags_NoAutoOpenOnLog) == 1)
				{
					Setup_Keybind((char*)"Record", Window_Procedure::Route_Recorder_Record_Bound_To);

					ImGui::TreePop();
				}
			}

			ImGui::TreePop();
		}

		ImGui::End();

		ImGui::Begin("Visuals", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoNavInputs);

		if (ImGui::TreeNodeEx("Route", ImGuiTreeNodeFlags_Framed | ImGuiTreeNodeFlags_NoAutoOpenOnLog) == 1)
		{
			if (ImGui::TreeNodeEx("Drawer", ImGuiTreeNodeFlags_Framed | ImGuiTreeNodeFlags_NoAutoOpenOnLog) == 1)
			{
				if (Copy_User_Command::Route_Recorder_Record == 0)
				{
					if (Window_Procedure::Visuals_Recorded_Route_Draw == 0)
					{
						File_Number_Editor();

						if (GetFileAttributesW(Adjusted_Map_Name) != -1)
						{
							if (ImGui::Button("Load From File") == 1)
							{
								void* Recorded_Route_File_Handle = CreateFileW(Adjusted_Map_Name, FILE_READ_DATA, 0, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);

								unsigned __int32 Recorded_Route_Allocations;

								unsigned long __int32 Recorded_Route_Accessed_Bytes_Count;

								ReadFile(Recorded_Route_File_Handle, &Recorded_Route_Allocations, sizeof(unsigned __int32), &Recorded_Route_Accessed_Bytes_Count, nullptr);

								Copy_User_Command::Recorded_Route.Reallocate(Recorded_Route_Allocations);

								SetFilePointer(Recorded_Route_File_Handle, sizeof(unsigned __int32), nullptr, FILE_BEGIN);

								ReadFile(Recorded_Route_File_Handle, Copy_User_Command::Recorded_Route.Read(0), Recorded_Route_Allocations * sizeof(Copy_User_Command::Route_Structure), &Recorded_Route_Accessed_Bytes_Count, nullptr);

								CloseHandle(Recorded_Route_File_Handle);
							}
						}
					}

					if (Copy_User_Command::Recorded_Route.Allocations == 0)
					{
						ImGui::Checkbox("Draw", (bool*)&Window_Procedure::Visuals_Recorded_Route_Draw);

						if (ImGui::DragScalar("Step Length", ImGuiDataType_U32, &Visuals_Recorded_Route_Step_Length, 1, nullptr, nullptr, "%i") == 1)
						{
							if (Visuals_Recorded_Route_Step_Length < 1)
							{
								Visuals_Recorded_Route_Step_Length = 1;
							}
						}
					}
				}

				ImGui::TreePop();
			}

			ImGui::TreePop();
		}

		free(Adjusted_Map_Name);

		if (ImGui::TreeNodeEx("Physics", ImGuiTreeNodeFlags_Framed | ImGuiTreeNodeFlags_NoAutoOpenOnLog) == 1)
		{
			static __int8 Visuals_Physics_Continue_Jumping_If_Jump_Button_Held = 0;

			if (ImGui::Checkbox("Continue Jumping If Jump Button Held", (bool*)&Visuals_Physics_Continue_Jumping_If_Jump_Button_Held) == 1)
			{
				auto Find_Previous_Buttons_In_Jump_Check_Location = [&]() -> void*
				{
					if (Menu_Select::Game_Identifier == 0)
					{
						return (void*)((unsigned __int32)GetModuleHandleW(L"client.dll") + 1936491);
					}

					unsigned __int8 Previous_Buttons_In_Jump_Check_Bytes[3] =
					{
						40,

						2,

						116
					};

					return (void*)((unsigned __int64)Byte_Manager::Find_Bytes(GetModuleHandleW(L"client.dll"), Previous_Buttons_In_Jump_Check_Bytes, sizeof(Previous_Buttons_In_Jump_Check_Bytes)) + 2);
				};

				static void* Previous_Buttons_In_Jump_Check_Location = Find_Previous_Buttons_In_Jump_Check_Location();

				if (Menu_Select::Game_Identifier == 0)
				{
					if (Visuals_Physics_Continue_Jumping_If_Jump_Button_Held == 0)
					{
						static unsigned __int8 Original_Previous_Buttons_In_Jump_Check[4] =
						{
							246,

							64,

							40,

							2
						};

						Byte_Manager::Copy_Bytes(1, Previous_Buttons_In_Jump_Check_Location, sizeof(Original_Previous_Buttons_In_Jump_Check), Original_Previous_Buttons_In_Jump_Check);
					}
					else
					{
						static unsigned __int8 Modified_Previous_Buttons_In_Jump_Check[4] =
						{
							50,

							192,

							144,

							144
						};

						Byte_Manager::Copy_Bytes(1, Previous_Buttons_In_Jump_Check_Location, sizeof(Modified_Previous_Buttons_In_Jump_Check), Modified_Previous_Buttons_In_Jump_Check);
					}
				}
				else
				{
					if (Visuals_Physics_Continue_Jumping_If_Jump_Button_Held == 0)
					{
						Byte_Manager::Set_Byte(Previous_Buttons_In_Jump_Check_Location, 116);
					}
					else
					{
						Byte_Manager::Set_Byte(Previous_Buttons_In_Jump_Check_Location, 235);
					}
				}
			}

			ImGui::TreePop();
		}

		ImGui::End();

		Direct_3_Dimensional_Device_9->SetRenderState(D3DRS_SRGBWRITEENABLE, 0);

		ImGui::GetIO().MouseDrawCursor = 1;

		ImGui::Render();

		ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());

		Direct_3_Dimensional_Device_9->SetRenderState(D3DRS_SRGBWRITEENABLE, 1);
	}

	using Present_Type = unsigned __int32(__stdcall*)(IDirect3DDevice9* Direct_3_Dimensional_Device_9, void* Unknown_Parameter_1, void* Unknown_Parameter_2, void* Unknown_Parameter_3, void* Unknown_Parameter_4);

	return Present_Type(Original_Present_Caller_Location)(Direct_3_Dimensional_Device_9, Unknown_Parameter_1, Unknown_Parameter_2, Unknown_Parameter_3, Unknown_Parameter_4);
}