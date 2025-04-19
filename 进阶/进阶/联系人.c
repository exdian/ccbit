#include "��ϵ��.h"
static int isChanged = 0;
void test_contact()
{
	size_t count = 0;
	contact* start = NULL;
	contact* end = init_contact(&count, &start); // ��ʼ���б�
	if (NULL == start || NULL == end) // �����һ��Ϊ��ָ�������
	{
		printf("���ִ������˳�\n");
		return;
	}

	void (*func[])(size_t*, contact**, contact**) = { add_contact, rmv_contact, mod_contact,
	                                                  scr_contact, lst_contact, sor_contact }; // ����ָ������
	int inp = CONTINUE;
	do
	{
		menu(count);
		fflush(stdin);
		if (scanf(" %d", &inp) != 1)
		{
			inp = CONTINUE;
		}

		while (getchar() != '\n')
			;
		if (inp >= 1 && inp <= sizeof(func) / sizeof(func[0])) // 1~6
		{
			func[inp - 1](&count, &start, &end);
		}
		else if (0 == inp)
		{
			inp = quit_contact(count, start); // ����Ƿ��и���
		}
		else
		{
			printf("ѡ�����������\n");
			while (getchar() != '\n')
				;
		}

	} while (inp != 0);
	
	free_contact(start); // �ͷ��ڴ�
	count = 0;
	start = NULL;
	end = NULL;
	printf("���˳�\n");
	while (getchar() != '\n')
		;
}

static void menu(size_t count)
{
	int num = 0;
	while (count >= 10)
	{
		count /= 10;
		num += 1;
	}

	printf("================  ��ϵ��  ================\n");
	printf("======  1.���    2.ɾ��    3.�޸�  ======\n");
	printf("======  4.����    5.�б�    6.����  ======\n");
	printf("======  %zu ����ϵ��%*s\n", count, 24 - num, "0.�˳�  ======");
	printf("==========================================\n");
	printf("��ѡ��:> ");
}

static contact* init_contact(size_t* count, contact** start)
{
	assert(count && start);
	contact* node = NULL;
	while ((node = malloc(sizeof(contact))) == NULL)
	{
		fflush(stdin);
		printf("��ʼ��ʧ�ܣ��� Enter ������");
		while (getchar() != '\n')
			;
	}

	*start = node; // �����˵�һ���ڵ�
	node->next = NULL;
	contact* last = node; // �����һ���ڵ�Ҳ�����һ���ڵ㣬��ʱ *start��node��last ָ��ͬһ��ռ�
	perror("��ʼ��");
	FILE* pfile = fopen("contact.bin", "rb");
	perror("���ļ�");
	if (NULL == pfile)
	{
		return last; // ����ļ��������򷵻ص�һ���ڵ�
	}

	while (1 == fread(&node->data, sizeof(node->data), 1, pfile)) // ���ɹ���ȡ������������ʱ����ѭ��
	{
		*count += 1;
		last = node; // ��һ���ڵ�
		while ((node = malloc(sizeof(contact))) == NULL) // ������һ���ڵ�
		{
			fflush(stdin);
			printf("��ʼ��ʧ�ܣ��� Enter ������");
			while (getchar() != '\n')
				;
		}

		last->next = node; // ����һ���ڵ㴴���ɹ�ʱ����ַ������һ���ڵ�
	}

	if (*count > 0)
	{
		free(node); // ���һ���ڵ�ض�û�����ݣ�free �� last->next ��Ұָ��
		node = NULL;
		last->next = NULL; // ���ֻ����һ��������ô last �� *start ָ�����ͬһ��ռ�
	}

	if (0 == feof(pfile)) // ����ȡ����ʱ����Ƿ����������ļ�ĩβ
	{
		printf("��ȡʧ��\n");
		free_contact(*start);
		*start = NULL;
		*count = 0;
		last = NULL;
		node = NULL;
	}

	fclose(pfile);
	pfile = NULL;
	return last; // ���һ������Ҳû�����᷵�ص�һ���ڵ㣬�����ȡ���󷵻ؿ�ָ��
}

static struct link find_contact(const contact* start, const char* str)
{
	assert(start && str);
	struct link link = { NULL };
	do
	{
		if ((strstr(start->data.name, str) != NULL) || (strstr(start->data.tele, str) != NULL) ||
			(strstr(start->data.note, str) != NULL) || (strstr(start->data.addr, str) != NULL))
		{
			link.node = (contact*)start;
			return link; // ����ҵ������±�
		}

		link.last = (contact*)start; // ������һ���ڵ����Ҫ�ҵ����ݣ���¼��һ���ڵ�
		start = start->next; // ��һ���ڵ�
	} while (start != NULL);

	return link;
}

static void show_contact(const contact* start, const contact* end)
{
	assert(start != NULL);
	printf("%*s%*s%*s%*s\n", -(MAX_NAME + 1), "����", -(MAX_ARRD + 1), "��ַ", -(MAX_TELE + 1), "�绰", -(MAX_NOTE + 1), "��ע");
	if (NULL == end) // �� end == NULL ʱ��ӡ����β
	{
		do
		{
			printf("%*s%*s%*s%*s\n",
				-(MAX_NAME + 1), start->data.name, -(MAX_ARRD + 1), start->data.addr,
				-(MAX_TELE + 1), start->data.tele, -(MAX_NOTE + 1), start->data.note);
			start = start->next;
		} while (start != NULL);

	}
	else // ��ӡ�� end
	{
		do
		{
			printf("%*s%*s%*s%*s\n",
				-(MAX_NAME + 1), start->data.name, -(MAX_ARRD + 1), start->data.addr,
				-(MAX_TELE + 1), start->data.tele, -(MAX_NOTE + 1), start->data.note);
			start = start->next;
		} while (start != end->next);

	}

}

static int save_contact(size_t count, const contact* start)
{
	assert(start != NULL);
	FILE* pfile = fopen("contact.bin", "wb");
	if (NULL == pfile)
	{
		return CONTINUE; // ���ط���ʱ�����������
	}

	if (count <= 0) // ���ɾ����������������ļ�
	{
		fclose(pfile);
		pfile = NULL;
		return 0;
	}

	do // д���ļ�
	{
		if (1 != fwrite(&start->data, sizeof(start->data), 1, pfile))
		{
			fclose(pfile);
			pfile = NULL;
			return CONTINUE;
		}

		start = start->next;
	} while (start != NULL);

	fclose(pfile); // ���е�����˵���ɹ�д����������
	pfile = NULL;
	return 0;
}

static void free_contact(contact* start)
{
	assert(start != NULL);
	while (start != NULL)
	{
		contact* node = start->next;
		free(start); // �ͷŵ�һ���ڵ�
		start = node; // ��һ���ڵ���Ϊ��һ���ڵ�
	}

}

static int quit_contact(size_t count, contact* start)
{
	assert(start != NULL);
	if (isChanged)
	{
		printf("=====  1.����    2.������    3.ȡ��  =====\n");
		printf("�Ƿ񱣴���ģ�\n");
		int inp = 3;
		scanf(" %d", &inp);
		while (getchar() != '\n')
			;
		if (1 == inp)
		{
			if (0 == save_contact(count, start))
			{
				printf("����ɹ�\n");
			}
			else
			{
				printf("����ʧ�ܣ�������\n");
				while (getchar() != '\n')
					;
				return CONTINUE; // ���ط���ʱ�����������
			}

		}
		else if (2 != inp) // ���벻�� 1 Ҳ���� 2 ʱ��������
		{
			printf("ȡ��\n\n");
			return CONTINUE; // ���ط���ʱ�����������
		}

	}

	return 0; // ����ɹ�ʱҲ���е���
}

static void add_contact(size_t* count, contact** start, contact** end)
{
	assert(count && start && end);
	contact* node = *end;
	if (*count > 0) // ʼ�ջᱣ������ͷ
	{
		node = malloc(sizeof(contact));
		if (NULL == node)
		{
			printf("���ʧ�ܣ�������\n\n");
			return;
		}

		(*end)->next = node;
		node->next = NULL;
		*end = node;
	}

	printf("�����ϵ��\n����:> ");
	scanf("%s", node->data.name); // ���� char ������
	while (getchar() != '\n')
		;
	printf("��ַ:> ");
	scanf("%s", node->data.addr);
	while (getchar() != '\n')
		;
	printf("�绰:> ");
	scanf("%s", node->data.tele);
	while (getchar() != '\n')
		;
	printf("��ע:> ");
	scanf("%s", node->data.note);
	while (getchar() != '\n')
		;
	*count += 1;
	isChanged = 1;
	printf("��ӳɹ�\n\n");
}

static void rmv_contact(size_t* count, contact** start, contact** end)
{
	assert(count && start && end);
	if (*count <= 0)
	{
		printf("��ϵ���б�Ϊ�գ������ݿ�ɾ��\n\n");
		return;
	}

	printf("ɾ����ϵ��\n������Ҫɾ��������ؼ���:> ");
	char keyw[MAX_NOTE] = { 0 };
	scanf("%s", keyw);
	while (getchar() != '\n')
		;
	struct link link = find_contact(*start, keyw); // link.last->next == link.node
	if (NULL == link.node)
	{
		printf("ɾ��ʧ�ܣ�δ�ҵ��κ���ϵ��\n\n");
		return;
	}

	printf("�ҵ�������ϵ�ˣ��Ƿ�ɾ��\n");
	show_contact(link.node, link.node);
	printf("���� 1 ȷ��ɾ��������������ȡ��\n");
	scanf(" %c", keyw);
	while (getchar() != '\n')
		;
	if (keyw[0] != '1')
	{
		printf("ȡ��ɾ��\n\n");
		return;
	}

	if (*count > 1) // ���ֻ�� 1 �������򲻽���
	{
		if (NULL == link.last) // ���ɾ�����ǵ�һ���ڵ������
		{
			*start = link.node->next;
		}
		else
		{
			link.last->next = link.node->next;
		}

		if (NULL == link.node->next) // ���ɾ���������һ���ڵ������
		{
			*end = link.last;
		}

		free(link.node);
		link.node = NULL;
	}

	*count -= 1;
	isChanged = 1;
	printf("ɾ���ɹ�\n\n");
}

static void mod_contact(size_t* count, contact** start, contact** end)
{
	assert(count && start && end);
	if (*count <= 0)
	{
		printf("��ϵ���б�Ϊ�գ������ݿ��޸�\n\n");
		return;
	}

	printf("�޸���ϵ��\n������Ҫ�޸ĵ�����ؼ���:> ");
	char keyw[MAX_NOTE] = { 0 };
	scanf("%s", keyw);
	while (getchar() != '\n')
		;
	struct link link = find_contact(*start, keyw);
	contact* node = link.node;
	if (NULL == node)
	{
		printf("�޸�ʧ�ܣ�δ�ҵ��κ���ϵ��\n\n");
		return;
	}

	printf("�ҵ�������ϵ��\n");
	show_contact(node, node);
	printf("���� 1 ȷ���޸ģ�����������ȡ��\n");
	scanf(" %c", keyw);
	while (getchar() != '\n')
		;
	if (keyw[0] != '1')
	{
		printf("ȡ���޸�\n\n");
		return;
	}

	printf("�޸�����:> ");
	scanf("%s", node->data.name);
	while (getchar() != '\n')
		;
	printf("�޸ĵ�ַ:> ");
	scanf("%s", node->data.addr);
	while (getchar() != '\n')
		;
	printf("�޸ĵ绰:> ");
	scanf("%s", node->data.tele);
	while (getchar() != '\n')
		;
	printf("�޸ı�ע:> ");
	scanf("%s", node->data.note);
	while (getchar() != '\n')
		;
	isChanged = 1;
	printf("�޸ĳɹ�\n\n");
}

static void scr_contact(size_t* count, contact** start, contact** end)
{
	assert(count && start && end);
	if (*count <= 0)
	{
		printf("��ϵ���б�Ϊ�գ������ݿɲ���\n\n");
		return;
	}

	printf("������ϵ��\n������Ҫ���ҵ�����ؼ���:> ");
	char keyw[MAX_NOTE] = { 0 };
	scanf("%s", keyw);
	while (getchar() != '\n')
		;
	struct link link = find_contact(*start, keyw);
	if (NULL == link.node)
	{
		printf("δ�ҵ��κ���ϵ��\n\n");
		return;
	}

	printf("�ҵ�������ϵ��\n");
	show_contact(link.node, link.node);
	printf("\n");
}

static void lst_contact(size_t* count, contact** start, contact** end)
{
	assert(count && start && end);
	if (*count <= 0)
	{
		printf("�б�Ϊ��\n\n");
		return;
	}

	show_contact(*start, NULL);
	printf("\n");
}

static void sor_contact(size_t* count, contact** start, contact** end)
{
	assert(count && start && end);
	if (*count <= 1)
	{
		printf("��������\n\n");
		return;
	}

	static const char* rk[] = { "����", "��ַ", "�绰", "��ע" };
	static const char* ck[] = { "����", "����" };
	static int (*sort_func[][2])(const void*, const void*) = { sort_name_asc, sort_name_desc,
	                                                           sort_addr_asc, sort_addr_desc,
	                                                           sort_tele_asc, sort_tele_desc,
	                                                           sort_note_asc, sort_note_desc };
	int row = 0;
	int col = 0;
	printf("====  1.����  2.��ַ  3.�绰  4.��ע  ====\n");
	printf("��ѡ������ʽ:> ");
	scanf(" %d", &row);
	while (getchar() != '\n')
		;
	if ((row < 1) || (row > sizeof(sort_func) / sizeof(sort_func[0]))) // ��ֹ����ָ������Խ��
	{
		printf("ѡ�����ȡ������\n\n");
		return;
	}

	printf("===========  1.����   2.����  ===========\n");
	printf("��ѡ������ʽ:> ");
	scanf(" %d", &col);
	while (getchar() != '\n')
		;
	if (col < 1 || col > 2) // ��ֹ����ָ������Խ��
	{
		printf("ѡ�����ȡ������\n\n");
		return;
	}
	
	*end = sort_linklist(start, offsetof(contact, next), sort_func[row - 1][col - 1]); // offset == 96
	isChanged = 1;
	printf("%s%s�������\n\n", rk[row - 1], ck[col - 1]);
}

// ��������鲢���򡣷���ֵ������Ľ�β��ͬʱ�޸�����Ŀ�ͷ
void* sort_linklist(void** head, size_t offsetof_next, int (*pfunc)(const void* elem1, const void* elem2))
{
	if (NULL == head)
	{
		return NULL;
	}

	if (NULL == *head || NULL == *(void**)((char*)*head + offsetof_next))
	{
		return *head;
	}

	// ����ָ���ҵ��е㡣���е�����˵�������� 2 ���ڵ�
	void* left = *head;
	void* right = *(void**)((char*)*head + offsetof_next); // (char*)node + offsetof_next �õ���һ���ڵ�ָ��ĵ�ַ������ǿ������ת������ָ��
	while (right != NULL && *(void**)((char*)right + offsetof_next) != NULL) // ��ֻ�� 2 ���ڵ�ʱ������
	{
		left = *(void**)((char*)left + offsetof_next);
		right = *(void**)((char*)right + offsetof_next);
		right = *(void**)((char*)right + offsetof_next);
	}

	right = *(void**)((char*)left + offsetof_next);
	*(void**)((char*)left + offsetof_next) = NULL; // �ж�����
	sort_linklist(head, offsetof_next, pfunc); // �ݹ�������Ϊ log2(node_count)������ȡ����
	sort_linklist(&right, offsetof_next, pfunc);
	left = *head;
	// left �� right �ڴ�ʱ������Ϊ NULL
	void* cur = NULL;
	if (pfunc(left, right) > 0)
	{
		cur = right;
		right = *(void**)((char*)right + offsetof_next);
	}
	else
	{
		cur = left;
		left = *(void**)((char*)left + offsetof_next);
	}

	*head = cur; // �޸�������ͷ��ֻ�е�һ�εݹ鵽�������Ǹ���֧�޸ĵĲ��������� *head�������֧�����޸��˾ֲ����� right
	while (left != NULL && right != NULL) // �ݵĹ��̲����룬��Ĺ��̲Ž��롣������ﰴ�ճ����ķ�����װ�ɺ���һ��һ���ڵ�ݹ�Ļ����ܵ���ջ���
	{
		if (pfunc(left, right) > 0)
		{
			*(void**)((char*)cur + offsetof_next) = right;
			cur = right;
			right = *(void**)((char*)right + offsetof_next);
		}
		else
		{
			*(void**)((char*)cur + offsetof_next) = left;
			cur = left;
			left = *(void**)((char*)left + offsetof_next);
		}

	}

	while (left != NULL)
	{
		*(void**)((char*)cur + offsetof_next) = left;
		cur = left;
		left = *(void**)((char*)left + offsetof_next);
	}

	while (right != NULL)
	{
		*(void**)((char*)cur + offsetof_next) = right;
		cur = right;
		right = *(void**)((char*)right + offsetof_next);
	}

	return cur;
}

// ��������
static int sort_name_asc(const void* elem1, const void* elem2)
{
	return strcmp(((struct contact_list*)elem1)->name, ((struct contact_list*)elem2)->name);
}

// ���ֽ���
static int sort_name_desc(const void* elem1, const void* elem2)
{
	return strcmp(((struct contact_list*)elem2)->name, ((struct contact_list*)elem1)->name);
}

// ��ַ����
static int sort_addr_asc(const void* elem1, const void* elem2)
{
	return strcmp(((struct contact_list*)elem1)->addr, ((struct contact_list*)elem2)->addr);
}

// ��ַ����
static int sort_addr_desc(const void* elem1, const void* elem2)
{
	return strcmp(((struct contact_list*)elem2)->addr, ((struct contact_list*)elem1)->addr);
}

// �绰����
static int sort_tele_asc(const void* elem1, const void* elem2)
{
	return strcmp(((struct contact_list*)elem1)->tele, ((struct contact_list*)elem2)->tele);
}

// �绰����
static int sort_tele_desc(const void* elem1, const void* elem2)
{
	return strcmp(((struct contact_list*)elem2)->tele, ((struct contact_list*)elem1)->tele);
}

// ��ע����
static int sort_note_asc(const void* elem1, const void* elem2)
{
	return strcmp(((struct contact_list*)elem1)->note, ((struct contact_list*)elem2)->note);
}

// ��ע����
static int sort_note_desc(const void* elem1, const void* elem2)
{
	return strcmp(((struct contact_list*)elem2)->note, ((struct contact_list*)elem1)->note);
}