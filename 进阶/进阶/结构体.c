// �ṹ��һЩֵ�ļ��ϣ���Щֵ��Ϊ��Ա�������ṹ��ÿ����Ա�����ǲ�ͬ���͵ı���
// �ṹ�����͵Ķ���
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
} s1, s2; // ����ṹ������ͬʱ���� s1, s2 �����ṹ�����

static struct // �� tag ʡ��ʱ����Ϊ�����ṹ�����
{
	char name[20];
	int age;
} us1; // �����ṹ�����ֻ���ڶ�������ʱ����

static struct stu3
{
	char name[20];
	int age;
} arr[5], * p; // ���� arr ���飬ÿ��Ԫ�ص����Ͷ��� struct stu3������ p ָ�룬ָ��������� struct stu3

// �ṹ���������
struct node1
{
	int data; // ������
	struct node1* next; // ָ����
};

// ʹ�� typedef �������ṹ������
typedef struct node2
{
	int data;
	struct node2* next;
} node2;

static struct node2 n1;
static node2 n2; // n1 �� n2 ��ͬ����

// ����ṹ������ͬʱ������ָ��ýṹ�����͵�ָ��
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