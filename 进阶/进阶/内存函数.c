#include <assert.h>

// ���ֽڸ���
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

// ���ֽڸ���
void* memory_move(void* dest, const void* src, size_t num)
{
	assert(dest && src);
	char* goal = (char*)dest;
	const char* srce = (char*)src;
	if (goal < srce) // ���Ŀ���ַ�ĸߵ�ַ��Դ��ַ�ĵ͵�ַ�ص����ȸ��Ƶ͵�ַ����
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

// ���ֽڱȽϣ�����'\0'
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

// ���ֽڳ�ʼ��
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