#pragma once

void Redirect_Present(IDirect3DDevice9* Direct_3_Dimensional_Device_9)
{
	ZydisDecoder Zydis_Decoder;

	ZydisDecoderInit(&Zydis_Decoder, ZYDIS_MACHINE_MODE_LEGACY_32, ZYDIS_ADDRESS_WIDTH_32);

	void* Present_Location = *(void**)(*(unsigned __int32*)Direct_3_Dimensional_Device_9 + 68);

	Resolve_Present_Location_Label:
	{
		if (*(unsigned __int8*)Present_Location == 233)
		{
			Present_Location = (void*)((unsigned __int32)Present_Location + *(__int32*)((unsigned __int32)Present_Location + 1) + 5);

			goto Resolve_Present_Location_Label;
		}
	}

	unsigned __int32 Offset_To_Instruction = 0;

	ZydisDecodedInstruction Zydis_Decoded_Instruction;

	Decode_Instruction_Label:
	{
		ZydisDecoderDecodeBuffer(&Zydis_Decoder, (void*)((unsigned __int32)Present_Location + Offset_To_Instruction), UINT_MAX, &Zydis_Decoded_Instruction);

		if (Offset_To_Instruction < 6)
		{
			unsigned __int32 Future_Offset_To_Instruction = Offset_To_Instruction + Zydis_Decoded_Instruction.length;

			if (Future_Offset_To_Instruction < 6)
			{
				Offset_To_Instruction = Future_Offset_To_Instruction;

				goto Decode_Instruction_Label;
			}
			else
			{
				Redirection_Manager::Redirect_Function(Original_Present_Caller_Location, Future_Offset_To_Instruction - 6, Present_Location, (void*)Redirected_Present);
			}
		}
		else
		{
			Offset_To_Instruction += Zydis_Decoded_Instruction.length;

			goto Decode_Instruction_Label;
		}
	}
}
