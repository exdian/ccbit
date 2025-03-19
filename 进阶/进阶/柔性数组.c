// 柔性数组是使用结构体和动态内存来实现的
// 在 C99 标准中，结构体最后一个成员允许是未知大小的数组，这就是柔性数组成员
// 柔性数组是结构体中最后一个成员，在数组前面必须至少一个其他成员
// sizeof 返回这种结构体的大小不包括柔性数组的大小
// 使用 malloc 函数对柔性数组动态分配内存，整个结构体都是放在堆区上的

#include <stdio.h>
#include <stdlib.h>
// 柔性数组的定义
struct alloc_arr
{
	int a;
	int arr[];
};

void test_softarr()
{
	printf("\n柔性数组\n");
	printf("%zu\n", sizeof(struct alloc_arr));
	// 柔性数组的使用
	struct alloc_arr* pa = (struct alloc_arr*)malloc(sizeof(struct alloc_arr) + 40);
	// 此时结构体内的 arr 数组大小为 40 个字节，使用返回的指针来访问结构体
	perror("malloc"); // 打印错误信息
	if (NULL == pa)
	{
		return;
	}

	pa->a = 1;
	pa->arr[0] = 1;
	// 柔性数组的扩容
	void* ptr = realloc(pa, sizeof(struct alloc_arr) + 80);
	perror("malloc");
	if (NULL == ptr)
	{
		return;
	}

	pa = ptr; // C++ 中只有 void* 指针接收不需要强转；而 C 语言中和 void* 类型相互赋值可以不用强转
	ptr = NULL;

	free(pa);
	pa = NULL;
}