// 指针数组是用来存放指针的数组
// 数组指针就是指针变量，指向的是数组
// 
// 数组名大部分情况下都是表示首元素的地址，不过有两个例外：
// 1. sizeof(数组名)		得到的是整个数组的大小，单位是字节
// 2. &数组名			得到的是整个数组的地址，值属性和首元素地址相同，类型属性是 数组指针类型
// 

#include <stdio.h>

// 指针数组
void test_ptr_arr()
{
	int* arr[5] = { NULL }; // 数组名是 arr，数组元素个数是 5，每个元素类型都是 int*
	int** arr0[5] = { NULL }; // 数组名是 arr0，数组元素个数是 5，每个元素类型都是 int**

	int arr1[] = { 11, 12, 13, 14, 15 };
	int arr2[] = { 21, 22, 23, 24, 25 };
	int arr3[] = { 31, 32, 33, 34, 35 };
	int* parr[] = { arr1, arr2, arr3 }; // 存放首元素地址
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%d ", parr[i][j]); // *(*(parr + i) + j) == parr[i][j]
		}

		printf("\n");
	}
	
}

// 数组指针
void test_arr_ptr()
{
	int(*ptr)[5] = NULL; // ptr 是一个指针变量，指向的是5个元素的数组，每个元素的类型是 int
	int arr[5] = { 0 };
	ptr = &arr;

	int* arr0[5] = { NULL };
	int* (*ptr0)[5] = &arr0;
}