#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

// 比较两个元素的大小，由需求决定比较的类型
static int compare_int(const void* elem1, const void* elem2)
{
	return *((int*)elem1) - *((int*)elem2); // elem1 > elem2 时返回正数，小于时返回负数
}

// 模仿 qsort 的参数写一个排序
void test_sort()
{
	printf("\n排序\n");
	int arr[8] = { 0 };
	int length = sizeof(arr) / sizeof(arr[0]);
	printf("8个数据 :> ");
	for (int i = 0; i < length; i++)
	{
		scanf("%d", arr + i);
	}

	void bubble_sort(void* ptr, int num, int width, int (*pf)(const void*, const void*));
	bubble_sort(arr, length, sizeof(arr[0]), compare_int);
	for (int i = 0; i < length; i++)
	{
		printf("%d ", arr[i]);
	}

}

static void swap(char* elem1, char* elem2, int width);

// 冒泡排序
void bubble_sort(void* ptr, int num, int width, int (*pf)(const void*, const void*))
{
	for (int i = 0; i < num - 1; i++)
	{
		char flag = 1;
		for (int j = 0; j < num - 1 - i; j++)
		{
			if (pf((char*)ptr + j * width, (char*)ptr + (j + 1) * width) > 0) // 如果 pf 返回大于 0 则进入
			{
				swap((char*)ptr + j * width, (char*)ptr + (j + 1) * width, width);
				flag = 0;
			}

		}

		if (flag) // 如果一轮排序下来没有元素交换则进入
		{
			break;
		}

	}

}

// 按字节交换
static void swap(char* elem1, char* elem2, int width)
{
	for (int i = 0; i < width; i++)
	{
		char temp = *(elem1 + i);
		*(elem1 + i) = *(elem2 + i);
		*(elem2 + i) = temp;
	}
	
}