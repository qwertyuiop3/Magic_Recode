#pragma once

__int32 __stdcall Redirected_Present(IDirect3DDevice9* Direct_3_Dimensional_Device_9, void* Unknown_Parameter_1, void* Unknown_Parameter_2, void* Unknown_Parameter_3, void* Unknown_Parameter_4)
{
	if (Draw_Graphical_User_Interface == 1)
	{
		Direct_3_Dimensional_Device_9->SetRenderState(D3DRS_SRGBWRITEENABLE, 0);

		ImGui_ImplDX9_NewFrame();

		ImGui_ImplWin32_NewFrame();

		ImGui::NewFrame();

		ImGui::Begin("User Commands", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_AlwaysAutoResize);

		static void* Client_Module_Location = GetModuleHandleW(L"client.dll");

		if (ImGui::TreeNodeEx("Recorder", ImGuiTreeNodeFlags_Framed | ImGuiTreeNodeFlags_NoAutoOpenOnLog) == 1)
		{
			if (ImGui::Checkbox("Record", (bool*)&User_Commands_Recorder_Record) == 1)
			{
				if (User_Commands_Recorder_Playback == 1)
				{
					Recorded_User_Commands.resize(Current_Recorder_User_Comamand_Number);

					User_Commands_Recorder_Playback = 0;
				}
				else
				{
					if (User_Commands_Recorder_Record == 1)
					{
						Recorded_User_Commands.clear();

						User_Commands_Recorder_Playback = 0;
					}
				}
			}

			static void* Map_Name_Location = (void*)((unsigned __int32)Client_Module_Location + 5245916);

			unsigned __int32 Map_Name_Length = wcslen((wchar_t*)Map_Name_Location) * 2;

			wchar_t* Adjusted_Map_Name = (wchar_t*)malloc(Map_Name_Length + 6);

			Byte_Manager::Copy_Bytes(0, Adjusted_Map_Name, Map_Name_Length, (unsigned __int8*)Map_Name_Location);

			*(wchar_t*)((unsigned __int32)Adjusted_Map_Name + Map_Name_Length) = L'.';

			static __int32 Save_Number = 0;

			ImGui::DragInt("Save Number", &Save_Number, 0, 0, 9);

			if (Save_Number < 0)
			{
				Save_Number = 0;
			}
			else
			{
				if (Save_Number > 9)
				{
					Save_Number = 9;
				}
			}

			*(__int16*)((unsigned __int32)Adjusted_Map_Name + Map_Name_Length + 2) = 48 + Save_Number;

			*(__int16*)((unsigned __int32)Adjusted_Map_Name + Map_Name_Length + 4) = 0;

			if (Recorded_User_Commands.empty() == 0)
			{
				if (ImGui::Checkbox("Playback", (bool*)&User_Commands_Recorder_Playback) == 1)
				{
					User_Commands_Recorder_Record = 0;
				}

				if (User_Commands_Recorder_Record == 0)
				{
					if (ImGui::Button("Save") == 1)
					{
						void* Recorded_User_Commands_File_Handle = CreateFileW(Adjusted_Map_Name, FILE_WRITE_DATA, 0, nullptr, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);

						unsigned __int32 Recorded_User_Commands_Amount = Recorded_User_Commands.size();

						WriteFile(Recorded_User_Commands_File_Handle, &Recorded_User_Commands_Amount, sizeof(unsigned __int32), nullptr, nullptr);

						SetFilePointer(Recorded_User_Commands_File_Handle, sizeof(unsigned __int32), 0, FILE_BEGIN);

						WriteFile(Recorded_User_Commands_File_Handle, Recorded_User_Commands.data(), Recorded_User_Commands.size() * sizeof User_Command_Structure, nullptr, nullptr);

						CloseHandle(Recorded_User_Commands_File_Handle);
					}
				}
			}
			
			if (User_Commands_Recorder_Record == 0)
			{
				if (User_Commands_Recorder_Playback == 0)
				{
					if (GetFileAttributesW(Adjusted_Map_Name) != -1)
					{
						if (ImGui::Button("Load From Save") == 1)
						{
							void* Recorded_User_Commands_File_Handle = CreateFileW(Adjusted_Map_Name, FILE_READ_DATA, 0, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);

							unsigned __int32 Recorded_User_Commands_Amount;

							ReadFile(Recorded_User_Commands_File_Handle, &Recorded_User_Commands_Amount, sizeof(unsigned __int32), nullptr, nullptr);

							Recorded_User_Commands.resize(Recorded_User_Commands_Amount);

							SetFilePointer(Recorded_User_Commands_File_Handle, sizeof(unsigned __int32), 0, FILE_BEGIN);

							ReadFile(Recorded_User_Commands_File_Handle, Recorded_User_Commands.data(), Recorded_User_Commands_Amount * sizeof User_Command_Structure, nullptr, nullptr);

							CloseHandle(Recorded_User_Commands_File_Handle);
						}
					}
				}
			}

			free(Adjusted_Map_Name);

			if (ImGui::TreeNodeEx("Keybinds", ImGuiTreeNodeFlags_Framed | ImGuiTreeNodeFlags_NoAutoOpenOnLog) == 1)
			{
				static __int8 Setting_Up_Keybind[2] =
				{
					0,

					0
				};

				auto Setup_Keybind = [](char* Function_Name, unsigned __int8& Key_Number, __int8& Button_Number) -> void
				{
					if (Setting_Up_Keybind[Button_Number] == 0)
					{
						Draw_X_Bound_To_Function_X_Label:
						{
							char Formatted_Button_Name[32];

							sprintf_s(Formatted_Button_Name, "%s Bound To Function %i", Function_Name, Key_Number - VK_DIVIDE);

							if (ImGui::Button(Formatted_Button_Name) == 1)
							{
								if (Setting_Up_Keybinds == 0)
								{
									Setting_Up_Keybinds = 1;

									Setting_Up_Keybind[Button_Number] = 1;
								}
							}
						}
					}
					else
					{
						unsigned __int8 Function_Key_Number = VK_F1;

						Is_Function_Key_Released_ChecK_Label:
						{
							if (Function_Key_Number != VK_NAVIGATION_VIEW)
							{
								if (ImGui::IsKeyReleased(Function_Key_Number) == 1)
								{
									Setting_Up_Keybinds = 0;

									Setting_Up_Keybind[Button_Number] = 0;

									Key_Number = Function_Key_Number;

									goto Draw_X_Bound_To_Function_X_Label;
								}

								Function_Key_Number += 1;

								goto Is_Function_Key_Released_ChecK_Label;
							}
						}

						ImGui::Button("Press Any Function Key");
					}

					Button_Number += 1;
				};

				__int8 Button_Number = 0;

				Setup_Keybind((char*)"Record", User_Commands_Recorder_Record_Bound_To, Button_Number);

				if (Recorded_User_Commands.empty() == 0)
				{
					Setup_Keybind((char*)"Playback", User_Commands_Recorder_Playback_Bound_To, Button_Number);
				}

				ImGui::TreePop();
			}

			ImGui::TreePop();
		}

		ImGui::End();

		ImGui::Begin("Visuals", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_AlwaysAutoResize);

		if (ImGui::TreeNodeEx("Physics", ImGuiTreeNodeFlags_Framed | ImGuiTreeNodeFlags_NoAutoOpenOnLog) == 1)
		{
			static __int8 Visuals_Physics_Continue_Jumping_If_Jump_Button_Held = 0;

			if (ImGui::Checkbox("Continue Jumping If Jump Button Held", (bool*)&Visuals_Physics_Continue_Jumping_If_Jump_Button_Held) == 1)
			{
				static void* Previous_Buttons_In_Jump_Check_Location = (void*)((unsigned __int32)Client_Module_Location + 1936491);

				if (Visuals_Physics_Continue_Jumping_If_Jump_Button_Held == 1)
				{
					static unsigned __int8 Modified_Previous_Buttons_In_Jump_Check[4] =
					{
						50,

						192,

						144,

						144
					};

					Byte_Manager::Copy_Bytes(1, Previous_Buttons_In_Jump_Check_Location, sizeof Modified_Previous_Buttons_In_Jump_Check, Modified_Previous_Buttons_In_Jump_Check);
				}
				else
				{
					static unsigned __int8 Original_Previous_Buttons_In_Jump_Check[4] =
					{
						246,

						64,

						40,

						2
					};

					Byte_Manager::Copy_Bytes(1, Previous_Buttons_In_Jump_Check_Location, sizeof Original_Previous_Buttons_In_Jump_Check, Original_Previous_Buttons_In_Jump_Check);
				}
			}

			ImGui::TreePop();
		}

		ImGui::End();

		ImGui::GetIO().MouseDrawCursor = 1;

		ImGui::Render();

		ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());

		Direct_3_Dimensional_Device_9->SetRenderState(D3DRS_SRGBWRITEENABLE, 1);
	}

	using Present_Type = __int32(__stdcall*)(IDirect3DDevice9* Direct_3_Dimensional_Device_9, void* Unknown_Parameter_1, void* Unknown_Parameter_2, void* Unknown_Parameter_3, void* Unknown_Parameter_4);

	return Present_Type(Original_Present_Caller_Location)(Direct_3_Dimensional_Device_9, Unknown_Parameter_1, Unknown_Parameter_2, Unknown_Parameter_3, Unknown_Parameter_4);
}