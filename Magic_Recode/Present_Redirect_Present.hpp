#pragma once

void Redirect_Present()
{
	unsigned __int8 Present_Bytes[7] =
	{
		85,

		139,

		236,

		131,

		236,

		64,

		185
	};

	Redirection_Manager::Redirect_Function(Original_Present_Caller_Location, 0, Byte_Manager::Find_Bytes(sizeof Present_Bytes, GetModuleHandleW(L"gameoverlayrenderer.dll"), Present_Bytes, 1), Redirected_Present);
}