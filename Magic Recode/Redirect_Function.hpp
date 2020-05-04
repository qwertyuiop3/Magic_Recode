#pragma once

void Redirect_Function(void*& Original_Function_Caller_Location, unsigned __int32 Original_Function_Caller_Offset, void* Original_Function_Location, __int8 Modify_Access_Rights, void* Redirected_Function_Location)
{
	unsigned long __int32 Previous_Access_Rights;

	Original_Function_Caller_Location = malloc(12 + Original_Function_Caller_Offset);

	Original_Function_Location = Original_Function_Location;

	*(void**)Original_Function_Caller_Location = *(void**)Original_Function_Location;

	*(unsigned __int16*)((unsigned __int32)Original_Function_Caller_Location + 4) = *(unsigned __int16*)((unsigned __int32)Original_Function_Location + 4);

	unsigned __int32 Byte_Number = 0;

	Copy_Byte_Label:
	{
		if (Byte_Number != Original_Function_Caller_Offset)
		{
			*(unsigned __int8*)((unsigned __int32)Original_Function_Caller_Location + 6 + Byte_Number) = *(unsigned __int32*)((unsigned __int64)Original_Function_Location + 6 + Byte_Number);

			Byte_Number += 1;

			goto Copy_Byte_Label;
		}
	}

	*(unsigned __int8*)((unsigned __int32)Original_Function_Caller_Location + 6 + Original_Function_Caller_Offset) = 104;

	*(void**)((unsigned __int32)Original_Function_Caller_Location + 7 + Original_Function_Caller_Offset) = (void*)((unsigned __int32)Original_Function_Location + 6 + Original_Function_Caller_Offset);

	*(unsigned __int8*)((unsigned __int32)Original_Function_Caller_Location + 11 + Original_Function_Caller_Offset) = 195;

	VirtualProtect(Original_Function_Caller_Location, 12 + Original_Function_Caller_Offset, PAGE_EXECUTE_READWRITE, &Previous_Access_Rights);

	if (Modify_Access_Rights == 1)
	{
		VirtualProtect(Original_Function_Location, 6, PAGE_EXECUTE_READWRITE, &Previous_Access_Rights);
	}

	*(unsigned __int8*)Original_Function_Location = 104;

	*(void**)((unsigned __int32)Original_Function_Location + 1) = Redirected_Function_Location;

	*(unsigned __int8*)((unsigned __int32)Original_Function_Location + 5) = 195;

	if (Modify_Access_Rights == 1)
	{
		VirtualProtect(Original_Function_Location, 6, Previous_Access_Rights, &Previous_Access_Rights);
	}
}