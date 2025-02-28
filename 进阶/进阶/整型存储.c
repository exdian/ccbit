// 整型家族
// char			默认signed还是unsigned取决于编译器，标准未定义
// short		默认signed
// int			默认signed
// long			默认signed
// long long	默认signed
// 
// 整数存储时，如果高位放在低地址，低位放在高地址则称为大端字节序存储，反之为小端存储，取决于硬件
// 使用小端字节序存储整数看起来更加合理

#include <stdbool.h>

// 返回1为小端字节序，返回0为大端字节序
bool chk_endian()
{
	short a = 1;
	return *((char*)(&a));
}