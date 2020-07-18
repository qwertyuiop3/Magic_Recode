#pragma once

void* Find_Bytes(unsigned __int32 Bytes_Amount, void* Starting_Location, unsigned __int8* Bytes, __int8 Return_Starting_Location_Of_Found_Bytes)
{
	Bytes_Amount -= 1;
		
	Compare_First_Byte_Label:
	{
		unsigned __int32 Byte_Number = 0;
			
		Compare_Next_Byte_Label:
		{
			if (*(unsigned __int8*)Starting_Location == Bytes[Byte_Number])
			{
				if (Bytes_Amount == Byte_Number)
				{
					if (Return_Starting_Location_Of_Found_Bytes == 0)
					{
						return Starting_Location;
					}

					return (void*)((unsigned __int32)Starting_Location - Bytes_Amount);
				}

				Starting_Location = (void*)((unsigned __int32)Starting_Location + 1);

				Byte_Number += 1;

				goto Compare_Next_Byte_Label;
			}
		}

		Starting_Location = (void*)((unsigned __int32)Starting_Location + 1);

		goto Compare_First_Byte_Label;
	}
}