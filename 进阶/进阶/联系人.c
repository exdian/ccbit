#include "��ϵ��.h"

void test_contact()
{
	contact con;
	init_contact(&con);
	int inp = 0;
	do
	{
		menu(con.count);
		scanf(" %d", &inp);
		getchar();
		switch (inp)
		{
		default:
			printf("ѡ�����������\n");
			getchar();
			break;
		case 0:
			printf("���˳�\n");
			break;
		case 1:
			add_contact(&con);
			break;
		case 2:
			rmv_contact(&con);
			break;
		case 3:
			mod_contact(&con);
			break;
		case 4:
			scr_contact(&con);
			break;
		case 5:
			lst_contact(&con);
			break;
		case 6:
			sor_contact(&con);
			break;
		}

	} while (inp != 0);

}

static void menu(int count)
{
	printf("================  ��ϵ��  ================\n");
	printf("======  1.���    2.ɾ��    3.�޸�  ======\n");
	printf("======  4.����    5.�б�    6.����  ======\n");
	printf("======  %d ����ϵ��%*s\n", count, count <= 0 ? 24 : 24 - (int)log10(count), "0.�˳�  ======");
	printf("==========================================\n");
	printf("��ѡ��:> ");
}

static void init_contact(contact* pc)
{
	assert(pc != NULL);
	pc->count = 0;
	memset(pc->list, 0, sizeof(pc->list));
}

static int find_contact(const contact* pc, const char* str)
{
	assert(pc && str);
	for (int i = 0; i < pc->count; i++)
	{
		if ((strstr(pc->list[i].name, str) != NULL) || (strstr(pc->list[i].tele, str) != NULL) ||
			(strstr(pc->list[i].note, str) != NULL) || (strstr(pc->list[i].addr, str) != NULL))
		{
			return i; // ����ҵ������±�
		}

	}

	return -1;
}

static void show_contact(const struct contact_list* list, int start, int end)
{
	assert(list != NULL);
	if (start < 0) // ��ֹԽ�����
	{
		start = 0;
	}

	if (end >= MAX_LST) // ��ֹԽ�����
	{
		end = MAX_LST - 1;
	}

	printf("%*s%*s%*s%*s\n", -(MAX_NAME + 1), "����", -(MAX_ARRD + 1), "��ַ", -(MAX_TELE + 1), "�绰", -(MAX_NOTE + 1), "��ע");
	while (start <= end) // ���ٴ�ӡһ������
	{
		printf("%*s%*s%*s%*s\n", // list ָ������õõ� struct contact_list���ٷ��ʽṹ��Ա
			-(MAX_NAME + 1), list[start].name, -(MAX_ARRD + 1), list[start].addr,
			-(MAX_TELE + 1), list[start].tele, -(MAX_NOTE + 1), list[start].note);
		start += 1;
	}

}

static void add_contact(contact* pc)
{
	assert(pc != NULL);
	if (pc->count >= MAX_LST)
	{
		printf("��ϵ���������޷����\n\n");
		return;
	}

	int count = pc->count;
	printf("�����ϵ��\n����:> ");
	scanf("%s", pc->list[count].name);
	printf("��ַ:> ");
	scanf("%s", pc->list[count].addr);
	printf("�绰:> ");
	scanf("%s", pc->list[count].tele);
	printf("��ע:> ");
	scanf("%s", pc->list[count].note);
	pc->count += 1;
	printf("��ӳɹ�\n\n");
}

static void rmv_contact(contact* pc)
{
	assert(pc != NULL);
	if (pc->count <= 0)
	{
		printf("��ϵ���б�Ϊ�գ������ݿ�ɾ��\n\n");
		return;
	}

	printf("ɾ����ϵ��\n������Ҫɾ��������ؼ���:> ");
	char keyw[MAX_NAME] = { 0 };
	scanf("%s", keyw);
	int lab = find_contact(pc, keyw);
	if (lab < 0)
	{
		printf("ɾ��ʧ�ܣ�δ�ҵ��κ���ϵ��\n\n");
		return;
	}

	printf("�ҵ�������ϵ�ˣ��Ƿ�ɾ��\n");
	show_contact(pc->list, lab, lab);
	printf("���� 1 ȷ��ɾ��������������ȡ��\n");
	scanf(" %c", keyw);
	while (getchar() != '\n');
	if (keyw[0] != '1')
	{
		printf("ȡ��ɾ��\n\n");
		return;
	}

	for (int i = lab; i < pc->count - 1; i++) // ���ɾ�������б������һ�������򲻻����ѭ��
	{ // ������������ǰ����
		pc->list[i] = pc->list[i + 1];
	}

	pc->count -= 1;
	printf("ɾ���ɹ�\n\n");
}

static void mod_contact(contact* pc)
{
	assert(pc != NULL);
	if (pc->count <= 0)
	{
		printf("��ϵ���б�Ϊ�գ������ݿ��޸�\n\n");
		return;
	}

	printf("�޸���ϵ��\n������Ҫ�޸ĵ�����ؼ���:> ");
	char keyw[MAX_NAME] = { 0 };
	scanf("%s", keyw);
	int lab = find_contact(pc, keyw);
	if (lab < 0)
	{
		printf("�޸�ʧ�ܣ�δ�ҵ��κ���ϵ��\n\n");
		return;
	}

	printf("�ҵ�������ϵ��\n");
	show_contact(pc->list, lab, lab);
	printf("���� 1 ȷ���޸ģ�����������ȡ��\n");
	scanf(" %c", keyw);
	while (getchar() != '\n');
	if (keyw[0] != '1')
	{
		printf("ȡ���޸�\n\n");
		return;
	}

	printf("�޸�����:> ");
	scanf("%s", pc->list[lab].name);
	printf("�޸ĵ�ַ:> ");
	scanf("%s", pc->list[lab].addr);
	printf("�޸ĵ绰:> ");
	scanf("%s", pc->list[lab].tele);
	printf("�޸ı�ע:> ");
	scanf("%s", pc->list[lab].note);
	printf("�޸ĳɹ�\n\n");
}

static void scr_contact(contact* pc) // Ϊ��ʹ�ú���ָ������˴����� const
{
	assert(pc != NULL);
	if (pc->count <= 0)
	{
		printf("��ϵ���б�Ϊ�գ������ݿɲ���\n\n");
		return;
	}

	printf("������ϵ��\n������Ҫ���ҵ�����ؼ���:> ");
	char keyw[MAX_NAME] = { 0 };
	scanf("%s", keyw);
	int lab = find_contact(pc, keyw);
	if (lab < 0)
	{
		printf("δ�ҵ��κ���ϵ��\n\n");
		return;
	}

	printf("�ҵ�������ϵ��\n");
	show_contact(pc->list, lab, lab);
	printf("\n");
}

static void lst_contact(contact* pc) // Ϊ��ʹ�ú���ָ������˴����� const
{
	assert(pc != NULL);
	if (pc->count <= 0)
	{
		printf("�б�Ϊ��\n\n");
		return;
	}

	show_contact(pc->list, 0, pc->count - 1);
	printf("\n");
}

static void sor_contact(contact* pc)
{
	assert(pc != NULL);
	if (pc->count <= 1)
	{
		printf("��������\n\n");
		return;
	}

	qsort(pc->list, pc->count, sizeof(pc->list[0]), sort_name);
	printf("�������\n\n");
}

// ��������
static int sort_name(const void* elem1, const void* elem2)
{
	return strcmp(((struct contact_list*)elem1)->name, ((struct contact_list*)elem2)->name);
}