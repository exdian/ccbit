// ���ͼ���
// char			Ĭ��signed����unsignedȡ���ڱ���������׼δ����
// short		Ĭ��signed
// int			Ĭ��signed
// long			Ĭ��signed
// long long	Ĭ��signed
// 
// �����洢ʱ�������λ���ڵ͵�ַ����λ���ڸߵ�ַ���Ϊ����ֽ���洢����֮ΪС�˴洢��ȡ����Ӳ��
// ʹ��С���ֽ���洢�������������Ӻ���

#include <stdbool.h>

// ����1ΪС���ֽ��򣬷���0Ϊ����ֽ���
bool chk_endian()
{
	short a = 1;
	return *((char*)(&a));
}