#include <assert.h>

// 按字节复制
void* memory_copy(void* dest, const void* src, size_t num)
{
	assert(dest && src);
	char* dest_ = (char*)dest;
	const char* src_ = (char*)src;
	while (num)
	{
		*dest_ = *src_;
		dest_ += 1;
		src_ += 1;
		num -= 1;
	}

	return dest;
}

// 按字节复制
void* memory_move(void* dest, const void* src, size_t num)
{
	assert(dest && src);
	char* goal = (char*)dest;
	const char* srce = (char*)src;
	if (goal < srce) // 如果目标地址的高地址和源地址的低地址重叠就先复制低地址数据
	{
		while (num)
		{
			*goal = *srce;
			goal += 1;
			srce += 1;
			num -= 1;
		}

	}
	else
	{
		while (num)
		{
			num -= 1;
			*(goal + num) = *(srce + num); // goal[num] = srce[num];
		}

	}

	return dest;
}

// 按字节比较，忽略'\0'
int memory_compare(const void* ptr1, const void* ptr2, size_t num)
{
	assert(ptr1 && ptr2);
	while (num)
	{
		if (*(char*)ptr1 != *(char*)ptr2)
		{
			return (int)(*(char*)ptr1 - *(char*)ptr2);
		}

		ptr1 = (char*)ptr1 + 1;
		ptr2 = (char*)ptr2 + 1;
		num -= 1;
	}

	return 0;
}

// 按字节初始化
void* memory_set(void* ptr, int value, size_t num)
{
	assert(ptr != NULL);
	char* target = (char*)ptr;
	while (num)
	{
		*target = (char)value;
		target += 1;
		num -= 1;
	}

	return ptr;
}