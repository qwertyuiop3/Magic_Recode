#pragma once

unsigned __int32 __stdcall Redirected_Window_Procedure(HWND Window_Handle, unsigned __int32 Message, unsigned __int32 Parameter_1, unsigned __int32 Parameter_2)
{
	if (Setting_Up_Keybinds == 0)
	{
		auto Keybinds = [&]() -> __int8
		{
			if (Parameter_1 == VK_INSERT)
			{
				if (Message == WM_KEYUP)
				{
					Controller_Move::Draw_Graphical_User_Interface ^= 1;
				}

				return 1;
			}

			if (Parameter_1 == User_Commands_Recorder_Record_Bound_To)
			{
				if (Message == WM_KEYUP)
				{
					Menu_Select::User_Commands_Recorder_Record ^= 1;

					if (Menu_Select::User_Commands_Recorder_Record == 1)
					{
						if (Menu_Select::User_Commands_Recorder_Playback == 1)
						{
							Menu_Select::User_Commands_Recorder_Playback = 0;

							Copy_User_Command::Recorded_User_Commands.resize(Copy_User_Command::Recorder_User_Comamand_Number);
						}
						else
						{
							Menu_Select::User_Commands_Recorder_Playback = 0;

							Copy_User_Command::Recorded_User_Commands.clear();
						}
					}
				}

				return 1;
			}

			if (Menu_Select::User_Commands_Recorder_Record == 0)
			{
				if (Copy_User_Command::Recorded_User_Commands.empty() == 0)
				{
					if (Parameter_1 == User_Commands_Recorder_Playback_Bound_To)
					{
						if (Message == WM_KEYUP)
						{
							Menu_Select::User_Commands_Recorder_Playback ^= 1;
						}

						return 1;
					}
				}
			}

			if (Parameter_1 == Route_Recorder_Record_Bound_To)
			{
				if (Message == WM_KEYUP)
				{
					if (Visuals_Recorded_Route_Draw == 0)
					{
						Copy_User_Command::Route_Recorder_Record ^= 1;

						if (Copy_User_Command::Route_Recorder_Record == 1)
						{
							Copy_User_Command::Recorded_Route.clear();
						}
					}
				}

				return 1;
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

	if (Controller_Move::Draw_Graphical_User_Interface == 1)
	{
		ImGui_ImplWin32_WndProcHandler(Window_Handle, Message, Parameter_1, Parameter_2);

		return WM_CREATE;
	}

	return CallWindowProcW((WNDPROC)Original_Window_Procedure_Location, Window_Handle, Message, Parameter_1, Parameter_2);
}