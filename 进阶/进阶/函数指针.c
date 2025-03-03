// 函数指针是指针变量，用来存放函数的地址
// 函数指针数组就是把函数指针放在数组中
// 如果把函数指针作为参数传递给另一个函数，当这个指针被用来调用其所指向的函数时，称为回调函数

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

// 函数指针
void test_function_ptr()
{
	printf("\n函数指针\n");
	{
		printf("%p\n", &printf);
		printf("%p\n", printf); // 这两种写法都能得到函数的地址
		printf("%p\n", &test);

		int (*pf)(char, int) = &test; // pf 是指针，指向的是函数，函数的参数是 char 和 int，函数的返回类型是 int
		pf = test;
		int ret = 0;
		ret = (*pf)(3, 4);
		ret = pf(3, 4);
		printf("%d\n", ret);
	}

	// (*(void (*)())0)(); // void (*)() 是函数指针类型，对 0 强制类型转换成函数指针类型，然后调用，整体表达式就是一次函数调用
	// void (*signal(int, void (*)(int)))(int); // 这是一个函数声明，函数名是 signal，函数参数是 int 和 void (*)(int)，函数返回类型是 void (*)(int)
	// 
	// typedef void (*pf)(int);
	// pf signal(int, pf); // 可以简化
	// 
	// 在相同参数相同返回类型的函数较多的情况下，可以使用函数指针数组灵活调用，能优化很多冗余代码
	{ // 函数指针数组例子
		int (*pf[])(int, int) = { add, sub, mul, div, mod }; // pf 是数组名，每个元素的类型是 int (*)(int, int)
		int length = sizeof(pf) / sizeof(pf[0]);
		printf("1. add\t\t2. sub\n3. mul\t\t4. div\n5. mod\n");
		int inp = 0;
		scanf("%d", &inp);
		if (inp >= 1 && inp <= length)
		{
			printf("左操作数  右操作数 :> ");
			int a = 0;
			int b = 0;
			scanf("%d %d", &a, &b);
			inp -= 1;
			printf("%d\n", pf[inp](a, b));
		}

	}

	{ // 函数指针数组指针
		int (*pf[])(int, int) = { add, sub, mul, div, mod };
		int (*(*ppf)[5])(int, int) = &pf; // ppf 是指针变量，指向的是指针数组，指向的数组有 5 个元素，每个元素的类型是 int (*)(int, int)

		typedef int (*pf_t)(int, int); // 可以使用 typedef 简化写法，可读性更好
		pf_t pf0[] = {add, sub, mul, div, mod}; // pf0 是数组名，每个元素的类型是 pf_t
		pf_t (*ppf0)[5] = &pf0; // ppf0 是指针变量，指向的是 5 个元素的数组，数组中每个元素的类型是 pf_t
	}
	
}