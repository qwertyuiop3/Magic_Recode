#pragma once

void Redirect_Window_Procedure(HWND Game_Window_Handle)
{
	Original_Window_Procedure_Location = SetWindowLongW(Game_Window_Handle, GWL_WNDPROC, (unsigned __int32)Redirected_Window_Procedure);
}