// 数组名能表示首元素地址
// 数组名有两种特殊情况：sizeof 中数组名表示整个数组；对数组名使用 & 时取出的是整个数组的地址
// 假设 arr 是数组名，表示数组中首元素的地址，arr 和 &arr[0] 效果相同，地址在加减整数时步长是元素的大小，而 &arr 在加减整数时步长是整个数组的大小

// 冒泡排序
void sort_bubble(int arr[], int count)
{
	int max_lab = count - 1;
	for (int i = 0; i < max_lab; i++)
	{
		int lab = max_lab - i;
		for (int j = 0; j < lab; j++)
		{
			int a = j + 1;
			if (arr[j] > arr[a]) // 升序
			{
				int b = arr[j];
				arr[j] = arr[a];
				arr[a] = b;
			}

		}

	}

}