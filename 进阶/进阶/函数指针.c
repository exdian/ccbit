// ����ָ����ָ�������������ź����ĵ�ַ
// ����ָ��������ǰѺ���ָ�����������
// ����Ѻ���ָ����Ϊ�������ݸ���һ�������������ָ�뱻������������ָ��ĺ���ʱ����Ϊ�ص�����

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

static int test(char a, int b)
{
	return ~a + 1 + b;
}

static int add(int a, int b) { return a + b; }
static int sub(int a, int b) { return a - b; }
static int mul(int a, int b) { return a * b; }
static int div(int a, int b) { return a / b; }
static int mod(int a, int b) { return a % b; }

// ����ָ��
void test_function_ptr()
{
	printf("\n����ָ��\n");
	{
		printf("%p\n", &printf);
		printf("%p\n", printf); // ������д�����ܵõ������ĵ�ַ
		printf("%p\n", &test);

		int (*pf)(char, int) = &test; // pf ��ָ�룬ָ����Ǻ����������Ĳ����� char �� int�������ķ��������� int
		pf = test;
		int ret = 0;
		ret = (*pf)(3, 4);
		ret = pf(3, 4);
		printf("%d\n", ret);
	}

	// (*(void (*)())0)(); // void (*)() �Ǻ���ָ�����ͣ��� 0 ǿ������ת���ɺ���ָ�����ͣ�Ȼ����ã�������ʽ����һ�κ�������
	// void (*signal(int, void (*)(int)))(int); // ����һ�������������������� signal������������ int �� void (*)(int)���������������� void (*)(int)
	// 
	// typedef void (*pf)(int);
	// pf signal(int, pf); // ���Լ�
	// 
	// ����ͬ������ͬ�������͵ĺ����϶������£�����ʹ�ú���ָ�����������ã����Ż��ܶ��������
	{ // ����ָ����������
		int (*pf[])(int, int) = { add, sub, mul, div, mod }; // pf ����������ÿ��Ԫ�ص������� int (*)(int, int)
		int length = sizeof(pf) / sizeof(pf[0]);
		printf("1. add\t\t2. sub\n3. mul\t\t4. div\n5. mod\n");
		int inp = 0;
		scanf("%d", &inp);
		if (inp >= 1 && inp <= length)
		{
			printf("�������  �Ҳ����� :> ");
			int a = 0;
			int b = 0;
			scanf("%d %d", &a, &b);
			inp -= 1;
			printf("%d\n", pf[inp](a, b));
		}

	}

	{ // ����ָ������ָ��
		int (*pf[])(int, int) = { add, sub, mul, div, mod };
		int (*(*ppf)[5])(int, int) = &pf; // ppf ��ָ�������ָ�����ָ�����飬ָ��������� 5 ��Ԫ�أ�ÿ��Ԫ�ص������� int (*)(int, int)

		typedef int (*pf_t)(int, int); // ����ʹ�� typedef ��д�����ɶ��Ը���
		pf_t pf0[] = {add, sub, mul, div, mod}; // pf0 ����������ÿ��Ԫ�ص������� pf_t
		pf_t (*ppf0)[5] = &pf0; // ppf0 ��ָ�������ָ����� 5 ��Ԫ�ص����飬������ÿ��Ԫ�ص������� pf_t
	}
	
}