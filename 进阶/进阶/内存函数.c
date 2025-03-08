#include <assert.h>

// °´×Ö½Ú¸´ÖÆ
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