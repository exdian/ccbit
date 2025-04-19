#define _CRT_SECURE_NO_WARNINGS 1

#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
	size_t data;
	struct Node* next;
} Node;

// �ϲ�����������������ʵ�飬x64 ƽ̨������д���� debug �汾ֻ�ܴ����Լ 8040 ���ڵ㣬�����ᵼ��ջ������� release �汾�ܴ����Լ 42900 ���ڵ�
static Node* merge(Node* l1, Node* l2)
{
	if (NULL == l1)
	{
		return l2;
	}

	if (NULL == l2)
	{
		return l1;
	}

	if (l1->data > l2->data)
	{
		l1->next = merge(l1->next, l2);
		return l1;
	}
	else
	{
		l2->next = merge(l1, l2->next);
		return l2;
	}

}

// �鲢����������
Node* mergeSort(Node* head)
{
	if (NULL == head || NULL == head->next)
	{
		return head;
	}

	// ����ָ���ҵ��е�
	Node* slow = head;
	Node* fast = head->next;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	fast = slow->next;
	slow->next = NULL; // �ж�����

	slow = mergeSort(head); // �ݹ���� log2(�ڵ�����) ��(����ȡ��)���˴�����ջ����Ŀ���
	fast = mergeSort(fast);

	return merge(slow, fast); // �ڵ�϶�ʱ��ջ���
	
	// �Ľ��汾�����ݹ�չ��
	Node* ret = NULL;
	Node* cur = NULL;
	if (slow->data > fast->data) // ���е����� left �� right �϶�Ϊ��������
	{
		cur = slow;
		slow = slow->next;
	}
	else
	{
		cur = fast;
		fast = fast->next;
	}

	ret = cur; // ȷ����ͷ
	while (slow != NULL && fast != NULL)
	{
		if (slow->data > fast->data)
		{
			cur->next = slow;
			slow = slow->next;
		}
		else
		{
			cur->next = fast;
			fast = fast->next;
		}

		cur = cur->next;
	}

	while (slow != NULL)
	{
		cur->next = slow;
		cur = slow;
		slow = slow->next;
	}

	while (fast != NULL)
	{
		cur->next = fast;
		cur = fast;
		fast = fast->next;
	}

	return ret;
}

// �����Ƿ�ջ���
void test_linklist()
{
	size_t node_num = 1;
	Node* last = NULL;
	Node* head = NULL;
	while ((last = head = malloc(sizeof(Node))) == NULL)
	{
		printf("��ʼ��ʧ�ܣ��� Enter ����");
		while (getchar() != '\n');
	}

	head->data = 0;
	do
	{
		printf("����ڵ���:> ");
		while (scanf("%zu", &node_num) != 1)
		{
			while (getchar() != '\n');
			printf("����ڵ���:> ");
		}

		while (getchar() != '\n'); // ��ջ�����
		for (size_t i = 1; i < node_num; i++)
		{
			while ((last->next = malloc(sizeof(Node))) == NULL)
			{
				printf("��ʼ��ʧ�ܣ��� Enter ����");
				while (getchar() != '\n');
			}

			last = last->next;
			last->data = i;
		}

		last->next = NULL;
		printf("�Ѵ��� %zu ���ڵ������\n", node_num);
		head = mergeSort(head);
		printf("�������\n");
		while (getchar() != '\n');
		while (head->next != NULL)
		{
			last = head->next;
			free(head);
			head = last;
		}

		printf("���ͷ��ڴ�\n");
		head->data = 0;
	} while (node_num != 0);

	free(head);
	head = NULL;
	last = NULL;
	printf("���˳�\n");
	while (getchar() != '\n');
}