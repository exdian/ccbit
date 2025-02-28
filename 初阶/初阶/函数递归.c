// 一个过程或函数在其定义或说明中有直接或间接调用自身的称为递归
// 递归应存在限制条件，当满足限制条件时停止递归，每次递归都应该越来越接近这个限制条件

#include <stdio.h>

// 逐位打印
void print_num(unsigned int n)
{
	if (n > 9)
	{
		print_num(n / 10);
	}

	printf("%u ", n % 10);
}