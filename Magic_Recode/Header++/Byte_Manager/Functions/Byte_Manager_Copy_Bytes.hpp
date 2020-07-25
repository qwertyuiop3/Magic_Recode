#pragma once

void Copy_Bytes(__int8 Modify_Access_Rights, void* Starting_Location, unsigned __int32 Bytes_Amount, unsigned __int8* Bytes)
{
	unsigned long __int32 Previous_Access_Rights;

	if (Modify_Access_Rights == 1)
	{
		VirtualProtect(Starting_Location, Bytes_Amount, PAGE_EXECUTE_READWRITE, &Previous_Access_Rights);
	}

	unsigned __int32 Byte_Number = 0;

	Copy_Byte_Label:
	{
		if (Bytes_Amount != Byte_Number)
		{
			*(unsigned __int8*)((unsigned __int32)Starting_Location + Byte_Number) = Bytes[Byte_Number];

			Byte_Number += 1;

			goto Copy_Byte_Label;
		}
	}

	if (Modify_Access_Rights == 1)
	{
		VirtualProtect(Starting_Location, Bytes_Amount, Previous_Access_Rights, &Previous_Access_Rights);
	}
}