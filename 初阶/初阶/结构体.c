// �ṹ��һЩֵ�ļ��ϣ���Щֵ��Ϊ��Ա����
// �ṹ������
// struct tag
// {
//     member list;
// } variable list;
// 
// variable listһ�㲻д����Ҫ�õ�ʱ��ʹ�ýṹ���ʹ�������
// �ṹ�ĳ�Ա�����Ǳ��������顢ָ�롢�����ṹ��
// �ṹ�崫��ʱҪ���ṹ������ĵ�ַ�Եõ����õ�����
// 

#include "��ϰ.h"

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
	peo p1 = { "�������", "11111111111", "��", 123 }; // �����ṹ�����ͬʱ��ʼ��
	struct student p2 = { {"nothing", "00000000000", "none", 0}, 101, 1.2f };
	printf("%s %s %s %d\n", p1.name, p1.tele, p1.sex, p1.high);
	printf("%s %s %s %d %d %f\n", p2.peop.name, p2.peop.tele, p2.peop.sex, p2.peop.high, p2.num, p2.high);

}