template <typename Dynamic_Allocator_Type, size_t Reserve> struct Dynamic_Allocator_Structure
{
	size_t Allocation_Size;

	size_t Allocations_Size;

	void* Allocator;

	size_t Allocations;

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

	void Append(Dynamic_Allocator_Type* Value)
	{
		if (Allocation_Size * Allocations >= Allocations_Size)
		{
			Allocations_Size = Allocation_Size * (Allocations + Reserve);

			Allocator = realloc(Allocator, Allocations_Size);
		}

		memcpy((void*)((unsigned __int64)Allocator + Allocation_Size * Allocations), Value, Allocation_Size);

		Allocations += 1;
	}

	Dynamic_Allocator_Type* Read(size_t Number)
	{
		return (Dynamic_Allocator_Type*)((unsigned __int64)Allocator + Allocation_Size * Number);
	}

	void Free()
	{
		using Free_Type = void(__cdecl*)(void* Block);

		free(Allocator);
	}
};