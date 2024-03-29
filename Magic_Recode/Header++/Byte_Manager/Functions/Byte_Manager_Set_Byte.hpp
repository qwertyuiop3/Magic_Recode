#pragma once

void Set_Byte(void* Starting_Location, unsigned __int8 Byte)
{
	unsigned long __int32 Previous_Access_Rights;

	VirtualProtect(Starting_Location, 1, PAGE_EXECUTE_READWRITE, &Previous_Access_Rights);

	__builtin_memset(Starting_Location, Byte, 1);

	VirtualProtect(Starting_Location, 1, Previous_Access_Rights, &Previous_Access_Rights);
}