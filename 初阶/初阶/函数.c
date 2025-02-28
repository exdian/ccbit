// ����ú�����ô�ã���ȥʵ�ֺ���
// ���鴫��ʱ�Ǵ���������Ԫ�صĵ�ַ����������������
// �����Ķ������Դ�ļ�����������������ͷ�ļ�

#include "����.h"

// �ж��Ƿ�����
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

// �ж�����
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

// ����һά�����������Ƿ���ĳ������num ΪҪ���ҵ�����count Ϊ����Ԫ�ظ���
int binary_search(int arr[], int num, int count)
{
	int min_lab = 0;
	int max_lab = count - 1;
	do
	{
		int mid_lab = (max_lab - min_lab) / 2 + min_lab;
		if (arr[mid_lab] < num) // ���Ҫ���������λ����
		{
			min_lab = mid_lab + 1;
		}
		else if (arr[mid_lab] > num) // ���Ҫ���������λ��С
		{
			max_lab = mid_lab - 1;
		}
		else
		{
			return mid_lab; // �ҵ�ʱ�����±�
		}

	} while (min_lab <= max_lab);

	return -1; // û���ҵ�����-1
}

// 쳲���������
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

// ͳ��һ������������1�ĸ���
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