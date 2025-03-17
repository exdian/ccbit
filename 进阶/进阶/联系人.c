#include "联系人.h"

void test_contact()
{
	contact con; // 创建列表
	init_contact(&con); // 初始化列表
	void (*func[])(contact*) = { add_contact, rmv_contact, mod_contact, scr_contact, lst_contact, sor_contact }; // 函数指针数组
	int inp = 0;
	do
	{
		menu(con.count);
		scanf(" %d", &inp);
		getchar();
		if (inp >= 1 && inp <= sizeof(func) / sizeof(func[0])) // 1~6
		{
			func[inp - 1](&con);
		}
		else if (0 == inp)
		{
			printf("已退出\n");
		}
		else
		{
			printf("选择错误，请重试\n");
			getchar();
		}

	} while (inp != 0);

}

static void menu(int count)
{
	printf("================  联系人  ================\n");
	printf("======  1.添加    2.删除    3.修改  ======\n");
	printf("======  4.查找    5.列表    6.排序  ======\n");
	printf("======  %d 个联系人%*s\n", count, count <= 0 ? 24 : 24 - (int)log10(count), "0.退出  ======");
	printf("==========================================\n");
	printf("请选择:> ");
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
			return i; // 如果找到返回下标
		}

	}

	return -1;
}

static void show_contact(const struct contact_list* list, int start, int end)
{
	assert(list != NULL);
	if (start < 0) // 防止越界访问
	{
		start = 0;
	}

	if (end >= MAX_LST) // 防止越界访问
	{
		end = MAX_LST - 1;
	}

	printf("%*s%*s%*s%*s\n", -(MAX_NAME + 1), "姓名", -(MAX_ARRD + 1), "地址", -(MAX_TELE + 1), "电话", -(MAX_NOTE + 1), "备注");
	while (start <= end) // 至少打印一行数据
	{
		printf("%*s%*s%*s%*s\n", // list 指针解引用得到 struct contact_list，再访问结构成员
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
		printf("联系人已满，无法添加\n\n");
		return;
	}

	int count = pc->count;
	printf("添加联系人\n姓名:> ");
	scanf("%s", pc->list[count].name);
	printf("地址:> ");
	scanf("%s", pc->list[count].addr);
	printf("电话:> ");
	scanf("%s", pc->list[count].tele);
	printf("备注:> ");
	scanf("%s", pc->list[count].note);
	pc->count += 1;
	printf("添加成功\n\n");
}

static void rmv_contact(contact* pc)
{
	assert(pc != NULL);
	if (pc->count <= 0)
	{
		printf("联系人列表为空，无数据可删除\n\n");
		return;
	}

	printf("删除联系人\n请输入要删除的任意关键字:> ");
	char keyw[MAX_NAME] = { 0 };
	scanf("%s", keyw);
	int lab = find_contact(pc, keyw);
	if (lab < 0)
	{
		printf("删除失败，未找到任何联系人\n\n");
		return;
	}

	printf("找到以下联系人，是否删除\n");
	show_contact(pc->list, lab, lab);
	printf("输入 1 确认删除，其他输入则取消\n");
	scanf(" %c", keyw);
	while (getchar() != '\n');
	if (keyw[0] != '1')
	{
		printf("取消删除\n\n");
		return;
	}

	for (int i = lab; i < pc->count - 1; i++) // 如果删除的是列表里最后一组数据则不会进入循环
	{ // 把数据整体往前覆盖
		pc->list[i] = pc->list[i + 1];
	}

	pc->count -= 1;
	printf("删除成功\n\n");
}

static void mod_contact(contact* pc)
{
	assert(pc != NULL);
	if (pc->count <= 0)
	{
		printf("联系人列表为空，无数据可修改\n\n");
		return;
	}

	printf("修改联系人\n请输入要修改的任意关键字:> ");
	char keyw[MAX_NAME] = { 0 };
	scanf("%s", keyw);
	int lab = find_contact(pc, keyw);
	if (lab < 0)
	{
		printf("修改失败，未找到任何联系人\n\n");
		return;
	}

	printf("找到以下联系人\n");
	show_contact(pc->list, lab, lab);
	printf("输入 1 确认修改，其他输入则取消\n");
	scanf(" %c", keyw);
	while (getchar() != '\n');
	if (keyw[0] != '1')
	{
		printf("取消修改\n\n");
		return;
	}

	printf("修改姓名:> ");
	scanf("%s", pc->list[lab].name);
	printf("修改地址:> ");
	scanf("%s", pc->list[lab].addr);
	printf("修改电话:> ");
	scanf("%s", pc->list[lab].tele);
	printf("修改备注:> ");
	scanf("%s", pc->list[lab].note);
	printf("修改成功\n\n");
}

static void scr_contact(contact* pc) // 为了使用函数指针数组此处不加 const
{
	assert(pc != NULL);
	if (pc->count <= 0)
	{
		printf("联系人列表为空，无数据可查找\n\n");
		return;
	}

	printf("查找联系人\n请输入要查找的任意关键字:> ");
	char keyw[MAX_NAME] = { 0 };
	scanf("%s", keyw);
	int lab = find_contact(pc, keyw);
	if (lab < 0)
	{
		printf("未找到任何联系人\n\n");
		return;
	}

	printf("找到以下联系人\n");
	show_contact(pc->list, lab, lab);
	printf("\n");
}

static void lst_contact(contact* pc) // 为了使用函数指针数组此处不加 const
{
	assert(pc != NULL);
	if (pc->count <= 0)
	{
		printf("列表为空\n\n");
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
		printf("无需排序\n\n");
		return;
	}

	static const char* rk[] = { "姓名", "地址", "电话", "备注" };
	static const char* ck[] = { "升序", "降序" };
	static int (*sort_func[][2])(const void*, const void*) = { sort_name_asc, sort_name_desc,
																sort_addr_asc, sort_addr_desc,
																sort_tele_asc, sort_tele_desc,
																sort_note_asc, sort_note_desc };
	int row = 0;
	int col = 0;
	printf("====  1.姓名  2.地址  3.电话  4.备注  ====\n");
	printf("请选择排序方式:> ");
	scanf(" %d", &row);
	if ((row < 1) || (row > sizeof(sort_func) / sizeof(sort_func[0]))) // 防止函数指针数组越界
	{
		printf("选择错误，取消排序\n\n");
		return;
	}

	printf("===========  1.升序   2.降序  ===========\n");
	printf("请选择排序方式:> ");
	scanf(" %d", &col);
	if (col < 1 || col > 2) // 防止函数指针数组越界
	{
		printf("选择错误，取消排序\n\n");
		return;
	}

	qsort(pc->list, pc->count, sizeof(pc->list[0]), sort_func[row - 1][col - 1]);
	printf("%s%s排序完成\n\n", rk[row - 1], ck[col - 1]);
}

// 名字升序
static int sort_name_asc(const void* elem1, const void* elem2)
{
	return strcmp(((struct contact_list*)elem1)->name, ((struct contact_list*)elem2)->name);
}

// 名字降序
static int sort_name_desc(const void* elem1, const void* elem2)
{
	return strcmp(((struct contact_list*)elem2)->name, ((struct contact_list*)elem1)->name);
}

// 地址升序
static int sort_addr_asc(const void* elem1, const void* elem2)
{
	return strcmp(((struct contact_list*)elem1)->addr, ((struct contact_list*)elem2)->addr);
}

// 地址降序
static int sort_addr_desc(const void* elem1, const void* elem2)
{
	return strcmp(((struct contact_list*)elem2)->addr, ((struct contact_list*)elem1)->addr);
}

// 电话升序
static int sort_tele_asc(const void* elem1, const void* elem2)
{
	return strcmp(((struct contact_list*)elem1)->tele, ((struct contact_list*)elem2)->tele);
}

// 电话降序
static int sort_tele_desc(const void* elem1, const void* elem2)
{
	return strcmp(((struct contact_list*)elem2)->tele, ((struct contact_list*)elem1)->tele);
}

// 备注升序
static int sort_note_asc(const void* elem1, const void* elem2)
{
	return strcmp(((struct contact_list*)elem1)->note, ((struct contact_list*)elem2)->note);
}

// 备注降序
static int sort_note_desc(const void* elem1, const void* elem2)
{
	return strcmp(((struct contact_list*)elem2)->note, ((struct contact_list*)elem1)->note);
}