// 联合是一种特殊的自定义类型，这种类型定义的变量也包含一系列的成员，特征是这些成员共用同一块内存空间，所以联合也叫共用体
// 一个联合变量的大小，至少是最大成员的大小，当最大成员大小不是最大对齐数的整数倍的时候，就要对齐到最大对齐数整数倍

#include <stdio.h>
// 联合类型的声明
union un
{
	int a;
	char b;
};

void test_union()
{
	union un u = { 0x11223344 }; // 使用联合类型创建变量 u，初始化时必须使用花括号，但是只能填一个值
	printf("%x\n", u.a); // 11223344
	printf("%x\n", u.b); // 44
	printf("%s\n", ((void*)&u == (void*)&u.a && (void*)&u == (void*)&u.b) ? "==" : "!="); // 联合体的所有成员首地址都一样
}