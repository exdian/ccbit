#define _CRT_SECURE_NO_WARNINGS 1

#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
	size_t data;
	struct Node* next;
} Node;

// 合并两个有序链表。经过实验，x64 平台下这种写法在 debug 版本只能处理大约 8040 个节点，超过会导致栈溢出，在 release 版本能处理大约 42900 个节点
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

// 归并排序主函数
Node* mergeSort(Node* head)
{
	if (NULL == head || NULL == head->next)
	{
		return head;
	}

	// 快慢指针找到中点
	Node* slow = head;
	Node* fast = head->next;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	fast = slow->next;
	slow->next = NULL; // 切断链表

	slow = mergeSort(head); // 递归最多 log2(节点总数) 层(向上取整)，此处已无栈溢出的可能
	fast = mergeSort(fast);

	return merge(slow, fast); // 节点较多时会栈溢出
	
	// 改进版本，将递归展开
	Node* ret = NULL;
	Node* cur = NULL;
	if (slow->data > fast->data) // 运行到这里 left 和 right 肯定为有序链表
	{
		cur = slow;
		slow = slow->next;
	}
	else
	{
		cur = fast;
		fast = fast->next;
	}

	ret = cur; // 确定表头
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

// 测试是否栈溢出
void test_linklist()
{
	size_t node_num = 1;
	Node* last = NULL;
	Node* head = NULL;
	while ((last = head = malloc(sizeof(Node))) == NULL)
	{
		printf("初始化失败，按 Enter 重试");
		while (getchar() != '\n');
	}

	head->data = 0;
	do
	{
		printf("输入节点数:> ");
		while (scanf("%zu", &node_num) != 1)
		{
			while (getchar() != '\n');
			printf("输入节点数:> ");
		}

		while (getchar() != '\n'); // 清空缓冲区
		for (size_t i = 1; i < node_num; i++)
		{
			while ((last->next = malloc(sizeof(Node))) == NULL)
			{
				printf("初始化失败，按 Enter 重试");
				while (getchar() != '\n');
			}

			last = last->next;
			last->data = i;
		}

		last->next = NULL;
		printf("已创建 %zu 个节点的链表\n", node_num);
		head = mergeSort(head);
		printf("排序完成\n");
		while (getchar() != '\n');
		while (head->next != NULL)
		{
			last = head->next;
			free(head);
			head = last;
		}

		printf("已释放内存\n");
		head->data = 0;
	} while (node_num != 0);

	free(head);
	head = NULL;
	last = NULL;
	printf("已退出\n");
	while (getchar() != '\n');
}