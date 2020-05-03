#pragma once

void Redirect_Client_Send_Move()
{
	Redirection_Manager::Redirect_Function(Original_Client_Send_Move_Caller_Location, 3, (void*)((unsigned __int32)GetModuleHandleW(L"engine.dll") + 771696), 1, Redirected_Client_Send_Move);
}