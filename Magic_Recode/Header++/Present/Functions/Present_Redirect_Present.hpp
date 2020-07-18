#pragma once

void Redirect_Present(IDirect3DDevice9* Direct_3_Dimensional_Device_9)
{
	void* Present_Location = *(void**)(*(unsigned __int32*)Direct_3_Dimensional_Device_9 + 68);

	Find_Final_Present_Location_Label:
	{
		if (*(unsigned __int8*)Present_Location == 232)
		{
			Present_Location = (void*)((unsigned __int32)Present_Location + *(unsigned __int32*)((unsigned __int32)Present_Location + 1) + 5);

			goto Find_Final_Present_Location_Label;
		}
		else
		{
			if (*(unsigned __int8*)Present_Location == 233)
			{
				Present_Location = (void*)((unsigned __int32)Present_Location + *(unsigned __int32*)((unsigned __int32)Present_Location + 1) + 5);

				goto Find_Final_Present_Location_Label;
			}
		}
	}

	Redirection_Manager::Redirect_Function(Original_Present_Caller_Location, 0, Present_Location, Redirected_Present);
}