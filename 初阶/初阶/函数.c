// 先想好函数怎么用，再去实现函数
// 数组传参时是传递数组首元素的地址，而不是整个数组
// 函数的定义放在源文件，函数的声明放在头文件

#include "函数.h"

// 判断是否素数
bool is_prime(int n)
{
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			return false;
		}

	}

	return true;
}

// 判断闰年
bool is_leap_year(int n)
{
	if ((n % 4 == 0) && (n % 100 != 0))
	{
		return true;
	}

	if (n % 400 == 0)
	{
		return true;
	}

	return false;
	//return ((n % 4 == 0) && (n % 100 != 0)) || (n % 400 == 0);
}

// 查找一维升序数组中是否有某个数。num 为要查找的数，count 为数组元素个数
int binary_search(int arr[], int num, int count)
{
	int min_lab = 0;
	int max_lab = count - 1;
	do
	{
		int mid_lab = (max_lab - min_lab) / 2 + min_lab;
		if (arr[mid_lab] < num) // 如果要查的数比中位数大
		{
			min_lab = mid_lab + 1;
		}
		else if (arr[mid_lab] > num) // 如果要查的数比中位数小
		{
			max_lab = mid_lab - 1;
		}
		else
		{
			return mid_lab; // 找到时返回下标
		}

	} while (min_lab <= max_lab);

	return -1; // 没有找到返回-1
}

// 斐波那契数列
int fib(int n)
{
	int a = 1, b = 1, c = 1;
	while (n > 2)
	{
		c = a + b;
		a = b;
		b = c;
		n -= 1;
	}
	
	return c;
}

// 统计一个数二进制中1的个数
int count_bin1(int n)
{
	int count = 0;
	while (n)
	{
		n &= n - 1;
		count += 1;
	}

	return count;
}