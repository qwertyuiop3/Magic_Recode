#pragma once

void Redirect_Present(IDirect3DDevice9* Direct_3_Dimensional_Device_9)
{
	void* Present_Location = *(void**)(*(unsigned __int32*)Direct_3_Dimensional_Device_9 + 68);

	Resolve_Present_Location_Label:
	{
		if (*(unsigned __int8*)Present_Location == 233)
		{
			Present_Location = (void*)((unsigned __int32)Present_Location + *(unsigned __int32*)((unsigned __int32)Present_Location + 1) + 5);

			goto Resolve_Present_Location_Label;
		}
	}

	ZyanU8 data[] =
	{
		0x83, 0xEC, 0x2C, 0x8B, 0x44, 0x24, 0x40
	};

	ZydisDecoder decoder;

	ZydisDecoderInit(&decoder, ZYDIS_MACHINE_MODE_LEGACY_32, ZYDIS_ADDRESS_WIDTH_32);

	Redirection_Manager::Redirect_Function(Original_Present_Caller_Location, 0, Present_Location, Redirected_Present);
}