// 结构是一些值的集合，这些值称为成员变量，结构的每个成员可以是不同类型的变量
// 结构体类型的定义
// struct tag
// {
//     member-list;
// } variable-list;
struct stu1
{
	char name[20];
	int age;
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

static struct node2 n1;
static node2 n2; // n1 和 n2 是同类型

// 定义结构体类型同时重命名指向该结构体类型的指针
typedef struct node3
{
	int data;
	struct node3* next;
} *linklist;

static struct stu4
{
	char name[20];
	int age;
} s4 = { 0, 0 };