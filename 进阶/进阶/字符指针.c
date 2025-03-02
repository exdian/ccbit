#include <stdio.h>
#include <string.h>

void test_char_ptr()
{
	printf("\n�ַ�ָ��\n");
	const char* cp = "abcd"; // ���ַ������ַ�'a'�ĵ�ַ������ָ����� cp��������ַ����ǳ��������޸�
	printf("%s\n", cp);
	printf("%d\n", (int)strlen(cp));

	const char* cp1 = "abc"; // ͬһ�������ַ������ڴ���ֻ��һ���ڴ棬���Ե���ͬ��ָ��ָ��ͬһ�������ַ���ʱ��ַ���
	const char* cp2 = "abc";
	const char* cp3 = "abcde";
	if (cp == cp1)
	{
		printf("cp == cp1\n");
	}
	else
	{
		printf("cp != cp1\n"); // true
	}

	if (cp1 == cp2)
	{
		printf("cp1 == cp2\n"); // true
	}
	else
	{
		printf("cp1 != cp2\n");
	}

	if (cp2 == cp3)
	{
		printf("cp2 == cp3\n");
	}
	else
	{
		printf("cp2 != cp3\n"); // true
	}

}
