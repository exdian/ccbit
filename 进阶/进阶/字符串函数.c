#include <assert.h>

// �ַ����ϲ�
char* string_concat(char* dest, const char* str)
{
	assert(dest && str);
	char* ret = dest;
	while (*dest != '\0') // ����ԭ�ַ����Ľ�β
	{
		dest += 1;
	}

	while (*dest++ = *str++)
		; // �����ַ�������ԭ�ַ�����β
	return ret;
}

// �ַ����Ƚ�
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

// �ַ������ƣ������ֽ���
char* string_num_copy(char* dest, const char* src, int num)
{
	assert(dest && src);
	char* ret = dest;
	while ((num-- > 0) && (*dest++ = *src++))
		; // num <= 0 �� *src == '\0' ������ѭ��
	// �� num == 0 ʱ����ִ�� && �������Ҳ��������� num > 1 ���� *src == '\0' ʱ������ѭ��ͬʱִ�� num-- �� dest++
	for (int i = 0; i < num; i++) // num <= 0 ʱ������ѭ��
	{
		dest[i] = '\0';
	}

	return ret;
}

// �ַ����ϲ��������ֽ���
char* string_num_concat(char* dest, const char* str, int num)
{
	assert(dest && str);
	char* ret = dest;
	while (*dest != '\0') // �� dest ָ��ԭ�ַ����� 1 �� '\0'
	{
		dest += 1;
	}

	if (num <= 0)
	{
		return ret;
	}

	while (*dest = *str) // *str == '\0' ʱ����ѭ��
	{
		dest += 1;
		str += 1;
		num -= 1;
		if (0 == num) // ���û���Ƶ� '\0' ���������ﵽ��Ҳ�Զ����� '\0'
		{
			*dest = '\0';
			return ret;
		}

	}

	return ret;
}

// �ַ����Ƚϣ������ֽ���
int string_num_compare(const char* str1, const char* str2, int num)
{
	assert(str1 && str2);
	while (*str1 == *str2)
	{
		num -= 1;
		if ('\0' == *str1 || num <= 0) // �����ַ������������� num == 0 ʱ���ؽ��
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
	char arr0[20] = "abcdef\0������";
	char arr1[20] = "123";
	string_num_concat(arr0, arr1, 3);
}