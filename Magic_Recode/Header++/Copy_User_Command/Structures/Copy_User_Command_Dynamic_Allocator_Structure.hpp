#pragma once

template <typename Dynamic_Allocator_Type, unsigned __int32 Reserve> struct Dynamic_Allocator_Structure
{
	unsigned __int32 Allocation_Size;

	void* Allocator;

	unsigned __int32 Allocations;

	void Initialize()
	{
		Allocation_Size = sizeof(Dynamic_Allocator_Type) * Reserve;

		Allocator = malloc(Allocation_Size);

		Allocations = 0;
	}

	void Append(Dynamic_Allocator_Type* Value)
	{
		if (sizeof(Dynamic_Allocator_Type) * Allocations >= Allocation_Size)
		{
			Allocation_Size = sizeof(Dynamic_Allocator_Type) * (Allocations + Reserve);

			Allocator = realloc(Allocator, Allocation_Size);
		}

		__builtin_memcpy((void*)((unsigned __int32)Allocator + sizeof(Dynamic_Allocator_Type) * Allocations), Value, sizeof(Dynamic_Allocator_Type));

		Allocations += 1;
	}

	Dynamic_Allocator_Type* Read(unsigned __int32 Number)
	{
		return (Dynamic_Allocator_Type*)((unsigned __int32)Allocator + sizeof(Dynamic_Allocator_Type) * Number);
	}

	void Reallocate(unsigned __int32 Reallocations)
	{
		Allocation_Size = sizeof(Dynamic_Allocator_Type) * (Reallocations + Reserve);

		Allocator = realloc(Allocator, Allocation_Size);

		Allocations = Reallocations;
	}

	void Clear()
	{
		free(Allocator);

		Allocation_Size = sizeof(Dynamic_Allocator_Type) * Reserve;

		Allocator = malloc(Allocation_Size);

		Allocations = 0;
	}
};