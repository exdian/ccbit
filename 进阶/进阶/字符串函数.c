#define _CRT_SECURE_NO_WARNINGS 1
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
	while (*str1 == *str2) // ��һ��ʱ����ѭ��
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

// �ַ��������Ӵ�
char* string_find(const char* str1, const char* str2)
{
	assert(str1 && str2);
	while (*str1 != '\0')
	{
		const char* base = str1;
		const char* goal = str2;
		while ((*base != '\0') && (*base == *goal)) // ��� goal ���ҵ�'\0'�˾Ͳ����� *base == *goal��Ҳ������ѭ��
		{
			base += 1;
			goal += 1;
		}

		if (*goal == '\0') // ���Ϊ'\0'˵����'\0'֮ǰ�������ַ���ƥ��ɹ���
		{
			return (char*)str1;
		}

		str1 += 1;
	}

	return NULL;
}

#include <string.h>
#include <stdio.h>
#include <errno.h>
void test_string_function()
{
	char arr0[20] = "abcdef\0������";
	char arr1[20] = "123";
	string_num_concat(arr0, arr1, 3);
	string_find("abc", "abc");
	string_find("abcd", "abc");
	string_find("ab", "abc");
	string_find("", "abc");
	string_find("abc", "");
	string_find("abbbbc", "bbc");

	char arr2[] = "10.100.1000.10000";
	char arr3[] = "10a100b1000c10000";
	for (char* ret = strtok(arr2, "."); ret != NULL; ret = strtok(NULL, ".")) // strtok ���ܻ�ı��ַ�������
	{
		printf("%s\n", ret);
	}
	
	for (char* ret = strtok(arr3, "abc"); ret != NULL; ret = strtok(NULL, "abc"))
	{
		printf("%s\n", ret);
	}

	FILE* pf = fopen("filename.txt", "r"); // �⺯��ִ��ʧ�ܶ������ô�����
	if (NULL == pf)
	{
		printf("%s\n", strerror(errno)); // ʹ�� strerror ��ȡ�����룬�Żش�����Ϣ���ַ�����ַ
	}
	else
	{
		printf("%s\n", strerror(errno));
	}

}
// �ַ����ຯ��
// ������һ�����������棬�����ж� �����ַ����հ��ַ���ʮ�������֡�ʮ���������֡�Сд��ĸ����д��ĸ����Сд��ĸ����ĸ�����֡������š�ͼ���ַ����ɴ�ӡ�ַ�
// 
// �ַ�ת������
// tolower	תСд
// toupper	ת��д