#include <stdio.h>
#include <string.h>

void test_char_ptr()
{
	printf("\n字符指针\n");
	const char* cp = "abcd"; // 把字符串首字符'a'的地址赋给了指针变量 cp，这里的字符串是常量不能修改
	printf("%s\n", cp);
	printf("%d\n", (int)strlen(cp));

	const char* cp1 = "abc"; // 同一个常量字符串在内存中只有一块内存，所以当不同的指针指向同一个常量字符串时地址相等
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
