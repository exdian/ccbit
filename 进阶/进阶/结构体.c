// 结构是一些值的集合，这些值称为成员变量，结构的每个成员可以是不同类型的变量
// 结构体类型的定义
// struct tag
// {
//     member-list;
// } variable-list;
// 
// 结构体内存对齐
// 1. 结构体第一个成员在与结构体变量偏移量为 0 的地址处
// 2. 其他成员变量要对齐到 对齐数 的整数倍的地址处。对齐数是编译器默认对齐数与该成员大小的较小值，只有VS编译器存在默认对齐数，x86 是 8，x64 是 16
// 3. 结构体总大小为最大对齐数的整数倍
// 4. 如果嵌套了结构体，那么嵌套的结构体对齐到自己的最大对齐数的整数倍处，结构体的整体大小就是所有包括嵌套在内的对齐数中最大对齐数的整数倍
// 
// 内存对齐是拿空间换时间的做法，设计结构体时既要满足对齐，又要节省空间
// 预处理指令 #pragma pack() 可以修改默认对齐数
// 使用 offsetof 可以返回结构体类型中某个成员在结构体变量中的偏移量，需要引用头文件 stddef.h
// 结构体传参时传地址比较好
// 
// 结构体可实现位段，位段的声明与结构体类似
// 位段的成员一般都是同一种整型家族类型，成员名后边有一个冒号和一个数字，数字表示这个成员所占用的比特位。位段可以节省空间
// 位段的内存空间上是按照 4 个字节(int)或者 1 个字节(char)的方式来开辟的
// 
// 位段的不确定因素
// 1. int 位段是有符号数还是无符号数是不确定的
// 2. 位段的最大位数不能确定，32 位机器的代码和 16 位机器的代码不能一样
// 3. 标准未定义位段中的成员在内存中是从左向右还是从右向左分配
// 4. 当需要开辟新的空间时，上一个位段剩余的位是舍弃还是继续使用是不确定的
// 因此使用位段需要处理好跨平台问题

//#pragma pack(show) // 在警告中显示默认对齐数
#pragma pack(2) // 设置默认对齐数为 2，有效值为 1、2、4、8、16
//#pragma pack(show)
struct stu0
{
	char name[10];
	int age;
};
//#pragma pack(show)
#pragma pack(/*16*/)
//#pragma pack(show)
struct stu1
{
	char name[20];
	int age;
	struct stu0 nest; // 嵌套结构体
};

static struct stu2
{
	char name[20];
	int age;
} s1, s2; // 定义结构体类型同时定义 s1, s2 两个结构体变量

static struct // 当 tag 省略时，称为匿名结构体变量
{
	char name[20];
	int age;
} us1; // 匿名结构体变量只能在定义类型时定义

static struct stu3
{
	char name[20];
	int age;
} arr[5], * p; // 定义 arr 数组，每个元素的类型都是 struct stu3，定义 p 指针，指向的类型是 struct stu3

// 结构体的自引用
struct node1
{
	int data; // 数据域
	struct node1* next; // 指针域
};

// 使用 typedef 重命名结构体类型
typedef struct node2
{
	int data;
	struct node2* next;
} node2;

static struct node2 n1 = { 0 };
static node2 n2 = { 0 }; // n1 和 n2 是同类型

// 定义结构体类型同时重命名指向该结构体类型的指针
typedef struct node3
{
	int data;
	struct node3* next;
} *linklist;

// 位段
static struct emp
{
	int a : 2;
	int b : 4;
	int c : 7;
	int d : 18;
} s4 = { 0, 0, 0, 0 };

#include <stdio.h>
#define OFFSETOF(STRUCT, MEMBER) ((size_t)&((STRUCT*)0)->MEMBER) // 模拟实现 offsetof
void test_offsetof()
{
	printf("%zu ", OFFSETOF(struct node3, next));
}