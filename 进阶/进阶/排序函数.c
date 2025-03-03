#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

// �Ƚ�����Ԫ�صĴ�С������������Ƚϵ�����
static int compare_int(const void* elem1, const void* elem2)
{
	return *((int*)elem1) - *((int*)elem2); // elem1 > elem2 ʱ����������С��ʱ���ظ���
}

// ģ�� qsort �Ĳ���дһ������
void test_sort()
{
	printf("\n����\n");
	int arr[8] = { 0 };
	int length = sizeof(arr) / sizeof(arr[0]);
	printf("8������ :> ");
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

// ð������
void bubble_sort(void* ptr, int num, int width, int (*pf)(const void*, const void*))
{
	for (int i = 0; i < num - 1; i++)
	{
		char flag = 1;
		for (int j = 0; j < num - 1 - i; j++)
		{
			if (pf((char*)ptr + j * width, (char*)ptr + (j + 1) * width) > 0) // ��� pf ���ش��� 0 �����
			{
				swap((char*)ptr + j * width, (char*)ptr + (j + 1) * width, width);
				flag = 0;
			}

		}

		if (flag) // ���һ����������û��Ԫ�ؽ��������
		{
			break;
		}

	}

}

// ���ֽڽ���
static void swap(char* elem1, char* elem2, int width)
{
	for (int i = 0; i < width; i++)
	{
		char temp = *(elem1 + i);
		*(elem1 + i) = *(elem2 + i);
		*(elem2 + i) = temp;
	}
	
}