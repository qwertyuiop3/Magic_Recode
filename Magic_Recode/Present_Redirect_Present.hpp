#pragma once

void Redirect_Present(IDirect3DDevice9* Direct_3_Dimensional_Device_9)
{
	Redirection_Manager::Redirect_Function(Original_Present_Caller_Location, 0, *(void**)(*(unsigned __int32*)Direct_3_Dimensional_Device_9 + 68), Redirected_Present);
}