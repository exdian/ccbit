#include <assert.h>

// 字符串合并
char* string_concat(char* dest, const char* str)
{
	assert(dest && str);
	char* ret = dest;
	while (*dest != '\0') // 先找原字符串的结尾
	{
		dest += 1;
	}

	while (*dest++ = *str++)
		; // 复制字符串放在原字符串结尾
	return ret;
}

// 字符串比较
int string_compare(const char* str1, const char* str2)
{
	assert(str1 && str2);
	while (*str1 == *str2)
	{
		if (*str1 == '\0')
		{
			return 0;
		}

		str1 += 1;
		str2 += 1;
	}
	
	return *str1 - *str2;
}

// 字符串复制，限制字节数
char* string_num_copy(char* dest, const char* src, int num)
{
	assert(dest && src);
	char* ret = dest;
	while ((num-- > 0) && (*dest++ = *src++))
		; // num <= 0 或 *src == '\0' 才跳出循环
	// 当 num == 0 时，不执行 && 操作符右操作数；当 num > 1 并且 *src == '\0' 时，跳出循环同时执行 num-- 和 dest++
	for (int i = 0; i < num; i++) // num <= 0 时不进入循环
	{
		dest[i] = '\0';
	}

	return ret;
}

// 字符串合并，限制字节数
char* string_num_concat(char* dest, const char* str, int num)
{
	assert(dest && str);
	char* ret = dest;
	while (*dest != '\0') // 让 dest 指向原字符串第 1 个 '\0'
	{
		dest += 1;
	}

	if (num <= 0)
	{
		return ret;
	}

	while (*dest = *str) // *str == '\0' 时跳出循环
	{
		dest += 1;
		str += 1;
		num -= 1;
		if (0 == num) // 如果没复制到 '\0' 但是数量达到了也自动补上 '\0'
		{
			*dest = '\0';
			return ret;
		}

	}

	return ret;
}

// 字符串比较，限制字节数
int string_num_compare(const char* str1, const char* str2, int num)
{
	assert(str1 && str2);
	while (*str1 == *str2)
	{
		num -= 1;
		if ('\0' == *str1 || num <= 0) // 两个字符串都结束或者 num == 0 时返回结果
		{
			return *str1 - *str2;
		}

		str1 += 1;
		str2 += 1;
	}

	return *str1 - *str2;
}

void test_string_function()
{
	char arr0[20] = "abcdef\0烫烫烫";
	char arr1[20] = "123";
	string_num_concat(arr0, arr1, 3);
}