#pragma once

unsigned __int32 __stdcall Redirected_Window_Procedure(HWND Window, unsigned __int32 Message, unsigned __int32 Parameter_1, unsigned __int32 Parameter_2)
{
	if (Setting_Up_Keybinds == 0)
	{
		auto Keybinds = [&]() -> __int8
		{
			if (Parameter_1 == VK_INSERT)
			{
				if (Message == WM_KEYDOWN)
				{
					return 1;
				}

				Draw_Graphical_User_Interface ^= 1;

				return 1;
			}

			if (Parameter_1 == User_Commands_Recorder_Record_Bound_To)
			{
				if (Message == WM_KEYDOWN)
				{
					return 1;
				}

				if (User_Commands_Recorder_Playback == 1)
				{
					Recorded_User_Commands.resize(Current_Recorder_User_Comamand_Number);

					User_Commands_Recorder_Record = 1;

					User_Commands_Recorder_Playback = 0;
				}
				else
				{
					User_Commands_Recorder_Record ^= 1;

					if (User_Commands_Recorder_Record == 1)
					{
						Recorded_User_Commands.clear();

						User_Commands_Recorder_Playback = 0;
					}
				}

				return 1;
			}

			if (Recorded_User_Commands.empty() == 0)
			{
				if (Parameter_1 == User_Commands_Recorder_Playback_Bound_To)
				{
					if (Message == WM_KEYDOWN)
					{
						return 1;
					}

					User_Commands_Recorder_Record = 0;

					User_Commands_Recorder_Playback ^= 1;

					return 1;
				}
			}

			return 0;
		};

		if (Message == WM_KEYDOWN)
		{
			if (Keybinds() == 1)
			{
				return WM_CREATE;
			}
		}
		else
		{
			if (Message == WM_KEYUP)
			{
				if (Keybinds() == 1)
				{
					return WM_CREATE;
				}
			}
		}
	}

	if (Draw_Graphical_User_Interface == 1)
	{
		IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

		ImGui_ImplWin32_WndProcHandler(Window, Message, Parameter_1, Parameter_2);

		return WM_CREATE;
	}

	return CallWindowProcW((WNDPROC)Original_Window_Procedure_Location, Window, Message, Parameter_1, Parameter_2);
}