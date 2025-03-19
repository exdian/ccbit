// ����������ʹ�ýṹ��Ͷ�̬�ڴ���ʵ�ֵ�
// �� C99 ��׼�У��ṹ�����һ����Ա������δ֪��С�����飬��������������Ա
// ���������ǽṹ�������һ����Ա��������ǰ���������һ��������Ա
// sizeof �������ֽṹ��Ĵ�С��������������Ĵ�С
// ʹ�� malloc �������������鶯̬�����ڴ棬�����ṹ�嶼�Ƿ��ڶ����ϵ�

#include <stdio.h>
#include <stdlib.h>
// ��������Ķ���
struct alloc_arr
{
	int a;
	int arr[];
};

void test_softarr()
{
	printf("\n��������\n");
	printf("%zu\n", sizeof(struct alloc_arr));
	// ���������ʹ��
	struct alloc_arr* pa = (struct alloc_arr*)malloc(sizeof(struct alloc_arr) + 40);
	// ��ʱ�ṹ���ڵ� arr �����СΪ 40 ���ֽڣ�ʹ�÷��ص�ָ�������ʽṹ��
	perror("malloc"); // ��ӡ������Ϣ
	if (NULL == pa)
	{
		return;
	}

	pa->a = 1;
	pa->arr[0] = 1;
	// �������������
	void* ptr = realloc(pa, sizeof(struct alloc_arr) + 80);
	perror("malloc");
	if (NULL == ptr)
	{
		return;
	}

	pa = ptr; // C++ ��ֻ�� void* ָ����ղ���Ҫǿת���� C �����к� void* �����໥��ֵ���Բ���ǿת
	ptr = NULL;

	free(pa);
	pa = NULL;
}