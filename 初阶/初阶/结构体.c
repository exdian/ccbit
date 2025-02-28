// 结构是一些值的集合，这些值称为成员变量
// 结构的声明
// struct tag
// {
//     member list;
// } variable list;
// 
// variable list一般不写，需要用到时才使用结构类型创建变量
// 结构的成员可以是标量、数组、指针、其他结构体
// 结构体传参时要传结构体变量的地址以得到更好的性能
// 

#include "练习.h"

typedef struct people
{
	char name[20];
	char tele[12];
	char sex[5];
	int high;
} peo;

struct student
{
	peo peop;
	int num;
	float high;
};

void test_struct()
{
	peo p1 = { "兰格麦加", "11111111111", "男", 123 }; // 创建结构体变量同时初始化
	struct student p2 = { {"nothing", "00000000000", "none", 0}, 101, 1.2f };
	printf("%s %s %s %d\n", p1.name, p1.tele, p1.sex, p1.high);
	printf("%s %s %s %d %d %f\n", p2.peop.name, p2.peop.tele, p2.peop.sex, p2.peop.high, p2.num, p2.high);

}