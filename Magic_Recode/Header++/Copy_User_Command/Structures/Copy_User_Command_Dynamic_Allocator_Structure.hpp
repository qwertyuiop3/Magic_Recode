template <typename Dynamic_Allocator_Type, unsigned __int32 Reserve> struct Dynamic_Allocator_Structure
{
	unsigned __int32 Allocation_Size;

	unsigned __int32 Allocations_Size;

	void* Allocator;

	unsigned __int32 Allocations;

	void Initialize()
	{
		Allocation_Size = sizeof(Dynamic_Allocator_Type);

		Allocations_Size = Allocation_Size * Reserve;

		Allocator = malloc(Allocations_Size);

		Allocations = 0;
	}

	void Clear()
	{
		Allocations = 0;
	}

	void Preallocate(unsigned __int32 Preallocations_Size)
	{
		Allocator = realloc(Allocator, Preallocations_Size * Allocation_Size);
	}

	void Append(Dynamic_Allocator_Type* Value)
	{
		if (Allocation_Size * Allocations >= Allocations_Size)
		{
			Allocations_Size = Allocation_Size * (Allocations + Reserve);

			Allocator = realloc(Allocator, Allocations_Size);
		}

		memcpy((void*)((unsigned __int32)Allocator + Allocation_Size * Allocations), Value, Allocation_Size);

		Allocations += 1;
	}

	Dynamic_Allocator_Type* Read(unsigned __int32 Number)
	{
		return (Dynamic_Allocator_Type*)((unsigned __int32)Allocator + Allocation_Size * Number);
	}

	void Free()
	{
		free(Allocator);
	}
};