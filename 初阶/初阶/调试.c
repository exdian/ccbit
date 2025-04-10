// debug版本是包含调试信息的版本，能够方便进行调试，release版本则是对代码进行了一些优化
// VS环境中，debug版本在栈区开辟空间时先使用高地址再使用低地址，而release版本反之
// 进入调试后，调用堆栈 窗口可以查看函数调用关系，监视窗口 可以使用 数组名,元素数量 来查看数组指针的元素
// 使用断言规避空指针
// const 修饰指针变量
// 1. const 在 * 左边表示指针指向的变量不能通过这个指针修改，但是这个指针变量可以修改
// 2. const 在 * 右边表示这个指针变量不能修改，但是指针指向的变量可以修改
// 
// 优秀的代码
// 1. 代码运行正常
// 2. bug很少
// 3. 效率高
// 4. 可读性高
// 5. 可维护性高
// 6. 注释清晰
// 7. 文档齐全
// 

#include <assert.h>

// 字符串复制
void string_copy(char* dest, const char* src)
{
	assert(src != NULL);
	assert(dest != NULL);
	while (*dest++ = *src++);
}

// 字符串长度
size_t string_length(const char* ptr)
{
	assert(ptr != NULL);
	const char* base = ptr;
	while (*ptr)
	{
		ptr += 1;
	}

	return ptr - base;
}