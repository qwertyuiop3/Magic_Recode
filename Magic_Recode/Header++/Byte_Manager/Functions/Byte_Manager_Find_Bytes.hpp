#pragma once

void* Find_Bytes(void* Starting_Location, void* Bytes, unsigned __int32 Bytes_Amount)
{
	Compare_Bytes_Label:
	{
		if (__builtin_memcmp(Starting_Location, Bytes, Bytes_Amount) == 0)
		{
			return Starting_Location;
		}

		Starting_Location = (void*)((unsigned __int32)Starting_Location + 1);

		goto Compare_Bytes_Label;
	}
}