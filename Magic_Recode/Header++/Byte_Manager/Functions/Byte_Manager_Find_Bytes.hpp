#pragma once

// Reformat -> void* Find_Bytes(void* Starting_Location, void* Bytes, unsigned __int32 Bytes_Amount)

void* Find_Bytes(unsigned __int32 Bytes_Amount, void* Starting_Location, unsigned __int8* Bytes, __int8 Return_Starting_Location_Of_Found_Bytes)
{
	Compare_Bytes_Label:
	{
		if (__builtin_memcmp(Starting_Location, Bytes, Bytes_Amount) == 0)
		{
			if (Return_Starting_Location_Of_Found_Bytes == 0)
			{
				return (void*)((unsigned __int32)Starting_Location + Bytes_Amount);
			}

			return Starting_Location;
		}

		#ifdef Bits_32
			Starting_Location = (void*)((unsigned __int32)Starting_Location + 1);
		#else
			Starting_Location = (void*)((unsigned __int64)Starting_Location + 1);
		#endif

		goto Compare_Bytes_Label;
	}
}