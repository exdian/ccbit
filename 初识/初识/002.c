// C语言代码中一定要有main函数，main函数作为程序的入口且唯一

// C语言数据类型
// char			字符
// short		短整形
// int			整形
// long			长整形
// long long	更长的整形(C99)
// float		单精度浮点型
// double		双精度浮点型

// 变量
// 局部变量		{}内定义的变量
// 全局变量		{}外定义的变量
// 尽量避免全局变量和局部变量名字相同，名字相同的情况下，局部优先
// 
// 变量的作用域
// 局部变量的作用域是变量所在的局部范围
// 全局变量的作用域是整个工程
// 
// 变量的生命周期
// 局部变量：进入作用域生命周期开始，出作用域生命周期结束
// 全局变量：整个程序的生命周期

// 常量
// 1. 字面常量
// 2. const 修饰的常变量，本质是变量，但是不能修改
// 3. define 定义的标识符常量
// 4. 枚举常量

// 字符串
// C语言没有字符串类型
// 使用双引号来表示字符串
// 字符串可以使用 char 数组保存，以'\0'表示字符串结束，ASCII值是 0

// 转义字符
// \?		防止解析成三字母词，远古版本编译器才支持三字母词
// \n		换行
// \r		回车
// \t		水平制表符
// \ddd		ddd 表示 1~3 个八进制数字，取对应ASCII码的字符
// \xdd		dd 表示 2 个十六进制数字，取对应ASCII码的字符
// \a		警告字符，使主板发出蜂鸣，不常用
// \b		退格符，不常用
// \f		进纸符，不常用
// \v		垂直制表符，不常用
// \'		字符常量
// \"		字符常量
// \\		字符常量

// 占位符(不重要)
// %d	十进制整数
// %i	整数，自动识别进制，输入 0x10 会解析为十六进制的 16
// %u	无符号十进制整数
// %f	单精度浮点数，默认 6 位小数，
// %lf	双精度浮点数，与 %f 在 printf 中效果相同
// %c	单个字符
// %s	字符串
// %p	指针地址
// %x	十六进制，小写
// %X	十六进制，大写
// %o	八进制
// %.nf	控制小数位数，例如 %.2f 保留 2 位小数
// %e	科学计数法，小写
// %E	科学计数法，大写
// %g	自动选择 %f 或 %e，短格式优先
// %%	百分号本身
// %n	记录已输出的字符数
// %zu	size_t类型
// %lld	长整数
// %nd	最小宽度为 n 的绝对值，用空格补齐，n 正数时右对齐，负数时左对齐
// %0nd	最小宽度为 n，左边用 0 补齐
// %*d	动态指定宽度

/* 注释 */
// 早期C语言使用 /* 和 */ 来注释中间的内容，缺点是不能嵌套注释

// C语句分为五类
// 1. 表达式语句
// 2. 函数调用语句
// 
// 3. 控制语句
// 3.1 条件判断语句
// 3.2 循环执行语句
// 3.3 转向语句
// 
// 4. 复合语句
// 5. 空语句

// 选择语句
// if else
// switch

// 循环语句
// while
// for
// do while

// 函数
// int 为返回类型，Add 为函数名，(int x, int y) 为函数参数，{} 为函数体
//int Add(int x, int y)
//{
//	return x + y;
//}

// 数组
// 一组相同类型的元素集合
// int 为数组类型，arr 为数组名，[10] 为数组元素个数，{} 括起来的内容为数组元素
//int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
// 初始化数组时元素个数省略将以 {} 内的元素个数确定，不完全初始化时剩余部分会默认为 0
// C99标准之前创建数组只能用常量或常量表达式指定数组大小，C99标准之后支持变长数组，但是这种指定方式不能初始化
// 数组下标是从 0 开始的整数，使用 arr[下标] 从数组中取值

// 操作符
// 0 表示假，非0 表示真
// 
// 1. 算术操作符
// +  -  *  /  %
// 
// 2. 移位操作符
// >>	<<
// 
// 3. 位操作符
// &  ^  |
// 
// 4. 赋值操作符
// =  +=  -=  *=  /=  &=  ^=  |=  >>=  <<=
// 
// 5. 单目操作符
// !		逻辑反操作
// -		负值
// +		正值
// &		取地址
// sizeof	操作数的类型长度，单位为字节
// ~		对一个数的二进制按位取反
// --		前置是先 -- 再使用、后置是先使用再 --
// ++		前置是先 ++ 再使用、后置是先使用再 ++
// *		间接访问操作符（解引用操作符）
// (类型)	强制类型转换
// 
// 6. 关系操作符
// >  >=  <  <=  !=  ==
// 
// 7. 逻辑操作符
// &&  ||
// 
// 8. 条件操作符（三目操作符）
// exp1 ? exp2 : exp3
// exp1 为真则结果为 exp2；exp1 为假则结果为 exp3
// 
// 9. 逗号表达式
// exp1, exp2, exp3, ……
// 从左到右依次计算，整个表达式的结果是最后一个表达式的结果
// 
// 10. 下标引用、函数调用和结构成员
// []  ()  .  ->

// 关键字 typedef
// 类型重命名
//typedef unsigned int uint;
//unsigned int num0;
//uint num1;
// 以上代码中 uint 等价于 unsigned int，num0 和 num1 是相同类型

// 关键字 static
// 1. 修饰局部变量，称为静态局部变量，使变量存储位置从栈区改到静态区，使变量生命周期和程序生命周期一样
// 2. 修饰全局变量，称为静态全局变量，使全局变量的外部链接属性变为内部链接属性，减小了作用域，只能在当前源文件使用
// 3. 修饰函数，称为静态函数，使函数的外部链接属性变为内部链接属性

// 关键字 register
//register int num;
// 用来建议变量存放在寄存器中

// define 定义常量和宏
// 属于预处理指令，无实际的汇编代码
//#define NUM 100 // 出现NUM这个符号的地方都换成100
//#define ADD(x, y) ((x) + (y)) // ADD 为宏名，(x, y) 为宏的参数，((x) + (y)) 为宏体
// 宏的参数是无类型的，实际作用是替换

// 指针
// 也就是内存单元的地址，x86 是 4 个字节，x64 是 8 个字节
//int a = 10;
//int* p = &a; // int 表示 p 指向的对象是 int 类型的，* 表示 p 是指针变量
//*p = 11; // * 为解引用操作符，使用 p 中的内容作为地址找到 p 所指向的对象
//int* p1, * p2, * p3; // 连续定义多个指针变量

// 结构体
// 结构体是把一些单一类型组合在一起的做法

#define _CRT_SECURE_NO_WARNINGS // 不安全报错解决办法，需要写在最开头，只在VS环境有效
#include <stdio.h> // 加载头文件

// 枚举常量
enum Color
{
	RED,
	GREEN,
	BLUE
};

// 结构体
struct StuStruct
{
	char stu_name[20];
	int stu_age;
	char stu_sex[9];
	char stu_tele[12];
};

int Add(int x, int y) // int 为返回类型，Add 为函数名，(int x, int y) 为函数参数，{} 为函数体
{
	return x + y;
}

void Print_Struct(struct StuStruct* pStruct)
{
	printf("%s %d %s %s\n", (*pStruct).stu_name, (*pStruct).stu_age, (*pStruct).stu_sex, (*pStruct).stu_tele);
	printf("%s %d %s %s\n", pStruct->stu_name, pStruct->stu_age, pStruct->stu_sex, pStruct->stu_tele); // 结构体指针变量->成员名
}

int main()
{
	printf("%zu\n", sizeof(char)); // 返回的是对应数据类型在内存中所占空间的大小，单位字节
	printf("%zu\n", sizeof(short));
	printf("%zu\n", sizeof(int));
	printf("%zu\n", sizeof(long));
	printf("%zu\n", sizeof(long long));
	printf("%zu\n", sizeof(float));
	printf("%zu\n", sizeof(double));

	{
		int num1 = 0; // 创建变量基本方法，同时初始化值，否则为随机值
		int num2 = 0;
		printf("%d\n", scanf("%d %d", &num1, &num2)); // "%d %d"表示格式，按照两个整形读取，中间用空格隔开，变量名前加上 & 表示取地址
		int sum = Add(num1, num2);
		printf("结果%d\n", sum);
	}

	//extern int a; // 声明来自外部的变量
	//extern 函数返回类型 函数名(函数参数); // 声明来自外部的函数
	//const int a = 0; // 常变量
	//#define CCOM 100 // 标识符常量
	//enum Color c = RED; // 创建枚举类型变量

	{
		struct StuStruct s = { "zhang", 20, "nan", "11111111111" }; // 使用结构体创建对象
		printf("%s %d %s %s\n", s.stu_name, s.stu_age, s.stu_sex, s.stu_tele); // 结构体对象.成员名
		Print_Struct(&s);
	}

	return 0;
}