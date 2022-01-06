#pragma once

void Redirect_Write_User_Command_Delta_To_Buffer(void* Client_Module_Location)
{
	constexpr unsigned __int8 Write_user_Command_Delta_To_Buffer_Bytes[6] =
	{
		104,

		83,

		86,

		139,

		217,

		199
	};

	Redirection_Manager::Redirect_Function(Original_Write_User_Command_Delta_To_Buffer_Caller_Location, 0, (void*)((unsigned __int32)Byte_Manager::Find_Bytes(Client_Module_Location, (void*)Write_user_Command_Delta_To_Buffer_Bytes, sizeof(Write_user_Command_Delta_To_Buffer_Bytes)) - 5), (void*)Redirected_Write_User_Command_Delta_To_Buffer);
}