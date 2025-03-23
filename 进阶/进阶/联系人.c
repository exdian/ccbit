#include "��ϵ��.h"

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

	void (*func[])(size_t*, contact**, contact**) = { add_contact, rmv_contact, mod_contact, scr_contact, lst_contact, sor_contact }; // ����ָ������
	int inp = 0;
	do
	{
		menu(count);
		fflush(stdin);
		scanf(" %d", &inp);
		fflush(stdin);
		if (inp >= 1 && inp <= sizeof(func) / sizeof(func[0])) // 1~6
		{
			func[inp - 1](&count, &start, &end);
		}
		else if (0 == inp)
		{
			printf("���˳�\n");
		}
		else
		{
			printf("ѡ�����������\n");
			getchar();
		}

	} while (inp != 0);
	
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
		getchar();
	}

	*start = node; // �����˵�һ���ڵ�
	node->next = NULL;
	contact* last = node; // �����һ���ڵ�Ҳ�����һ���ڵ㣬��ʱ *start��node��last ָ��ͬһ��ռ�
	perror("��ʼ��");
	FILE* pfile = fopen("contact.bin", "rb");
	perror("���ļ�");
	if (NULL == pfile)
	{
		return last; // ����ļ��������򷵻ؿ�ָ��
	}

	while (1 == fread(&node->data, sizeof(node->data), 1, pfile)) // ���ɹ���ȡ������������ʱ����ѭ��
	{
		*count += 1;
		last = node; // ��һ���ڵ�
		while ((node = malloc(sizeof(contact))) == NULL) // ������һ���ڵ�
		{
			fflush(stdin);
			printf("��ʼ��ʧ�ܣ��� Enter ������");
			getchar();
		}

		last->next = node; // ����һ���ڵ㴴���ɹ�ʱ����ַ������һ���ڵ�
	}

	if (*count > 0) // ��� if �����һ�������
	{
		free(node); // ���һ���ڵ�ض�û�����ݣ�free �� last->next ��Ұָ��
		node = NULL;
		last->next = NULL; // ���ֻ����һ��������ô last �� *start ָ�����ͬһ��ռ�
	}

	if (0 == feof(pfile)) // ����ȡ����ʱ����Ƿ����������ļ�ĩβ
	{
		printf("��ȡʧ��\n");
		while (NULL != (node = (*start)->next))
		{
			free(*start); // �ͷŵ�һ���ڵ�
			*start = node; // ��һ���ڵ���Ϊ��һ���ڵ�
		}

		free(*start);
		*start = NULL;
		*count = 0;
		last = NULL;
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
			link.node = start;
			return link; // ����ҵ������±�
		}

		link.last = start; // ������һ���ڵ����Ҫ�ҵ����ݣ���¼��һ���ڵ�
		start = start->next; // ��һ���ڵ�
	} while (start != NULL);

	return link;
}

static void show_contact(const contact* start, const contact* end)
{
	assert(start && end);
	printf("%*s%*s%*s%*s\n", -(MAX_NAME + 1), "����", -(MAX_ARRD + 1), "��ַ", -(MAX_TELE + 1), "�绰", -(MAX_NOTE + 1), "��ע");
	do
	{
		printf("%*s%*s%*s%*s\n",
			-(MAX_NAME + 1), start->data.name, -(MAX_ARRD + 1), start->data.addr,
			-(MAX_TELE + 1), start->data.tele, -(MAX_NOTE + 1), start->data.note);
		start = start->next;
	} while (start == end->next);

}

static void add_contact(size_t* count, contact** start, contact** end)
{
	assert(count && start && end);
	contact* node = *end;
	if (*count > 0)
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
	printf("��ַ:> ");
	scanf("%s", node->data.addr);
	printf("�绰:> ");
	scanf("%s", node->data.tele);
	printf("��ע:> ");
	scanf("%s", node->data.note);
	*count += 1;
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
	if (keyw[0] != '1')
	{
		printf("ȡ��ɾ��\n\n");
		return;
	}

	if(*count > 1) // ���ֻ�� 1 �������򲻽���
	{
		link.last->next = link.node->next;
		if (NULL == link.node->next) // ���ɾ���������һ���ڵ������
		{
			*end = link.last;
		}

		free(link.node);
	}

	*count -= 1;
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
	if (keyw[0] != '1')
	{
		printf("ȡ���޸�\n\n");
		return;
	}

	printf("�޸�����:> ");
	scanf("%s", node->data.name);
	printf("�޸ĵ�ַ:> ");
	scanf("%s", node->data.addr);
	printf("�޸ĵ绰:> ");
	scanf("%s", node->data.tele);
	printf("�޸ı�ע:> ");
	scanf("%s", node->data.note);
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

	show_contact(*start, *end);
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
	if ((row < 1) || (row > sizeof(sort_func) / sizeof(sort_func[0]))) // ��ֹ����ָ������Խ��
	{
		printf("ѡ�����ȡ������\n\n");
		return;
	}

	printf("===========  1.����   2.����  ===========\n");
	printf("��ѡ������ʽ:> ");
	scanf(" %d", &col);
	if (col < 1 || col > 2) // ��ֹ����ָ������Խ��
	{
		printf("ѡ�����ȡ������\n\n");
		return;
	}

	// ����

	printf("%s%s�������\n\n", rk[row - 1], ck[col - 1]);
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