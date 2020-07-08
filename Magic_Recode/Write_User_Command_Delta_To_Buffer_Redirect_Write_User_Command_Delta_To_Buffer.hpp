#pragma once

void Redirect_Write_User_Command_Delta_To_Buffer(void* Client_Module_Location)
{
	Redirection_Manager::Redirect_Function(Original_Write_User_Command_Delta_To_Buffer_Caller_Location, 0, (void*)((unsigned __int32)Client_Module_Location + 0x2DC380), Redirected_Write_User_Command_Delta_To_Buffer);
}