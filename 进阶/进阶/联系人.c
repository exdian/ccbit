#include "联系人.h"

void test_contact()
{
	size_t count = 0;
	contact* start = NULL;
	contact* end = init_contact(&count, &start); // 初始化列表
	if (NULL == start || NULL == end) // 如果有一个为空指针则进入
	{
		printf("出现错误，已退出\n");
		return;
	}

	void (*func[])(size_t*, contact**, contact**) = { add_contact, rmv_contact, mod_contact, scr_contact, lst_contact, sor_contact }; // 函数指针数组
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
			printf("已退出\n");
		}
		else
		{
			printf("选择错误，请重试\n");
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

	printf("================  联系人  ================\n");
	printf("======  1.添加    2.删除    3.修改  ======\n");
	printf("======  4.查找    5.列表    6.排序  ======\n");
	printf("======  %zu 个联系人%*s\n", count, 24 - num, "0.退出  ======");
	printf("==========================================\n");
	printf("请选择:> ");
}

static contact* init_contact(size_t* count, contact** start)
{
	assert(count && start);
	contact* node = NULL;
	while ((node = malloc(sizeof(contact))) == NULL)
	{
		fflush(stdin);
		printf("初始化失败，按 Enter 键重试");
		getchar();
	}

	*start = node; // 创建了第一个节点
	node->next = NULL;
	contact* last = node; // 假设第一个节点也是最后一个节点，此时 *start、node、last 指向同一块空间
	perror("初始化");
	FILE* pfile = fopen("contact.bin", "rb");
	perror("打开文件");
	if (NULL == pfile)
	{
		return last; // 如果文件不存在则返回空指针
	}

	while (1 == fread(&node->data, sizeof(node->data), 1, pfile)) // 当成功读取到完整的数据时进入循环
	{
		*count += 1;
		last = node; // 上一个节点
		while ((node = malloc(sizeof(contact))) == NULL) // 创建下一个节点
		{
			fflush(stdin);
			printf("初始化失败，按 Enter 键重试");
			getchar();
		}

		last->next = node; // 当下一个节点创建成功时将地址赋给上一个节点
	}

	if (*count > 0) // 这个 if 块和下一个相关联
	{
		free(node); // 最后一个节点必定没有数据，free 后 last->next 是野指针
		node = NULL;
		last->next = NULL; // 如果只读了一个数据那么 last 和 *start 指向的是同一块空间
	}

	if (0 == feof(pfile)) // 当读取结束时检查是否是遇到了文件末尾
	{
		printf("读取失败\n");
		while (NULL != (node = (*start)->next))
		{
			free(*start); // 释放第一个节点
			*start = node; // 下一个节点作为第一个节点
		}

		free(*start);
		*start = NULL;
		*count = 0;
		last = NULL;
	}

	fclose(pfile);
	pfile = NULL;
	return last; // 如果一个数据也没读到会返回第一个节点，如果读取错误返回空指针
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
			return link; // 如果找到返回下标
		}

		link.last = start; // 假设下一个节点就是要找的数据，记录上一个节点
		start = start->next; // 下一个节点
	} while (start != NULL);

	return link;
}

static void show_contact(const contact* start, const contact* end)
{
	assert(start && end);
	printf("%*s%*s%*s%*s\n", -(MAX_NAME + 1), "姓名", -(MAX_ARRD + 1), "地址", -(MAX_TELE + 1), "电话", -(MAX_NOTE + 1), "备注");
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
			printf("添加失败，请重试\n\n");
			return;
		}

		(*end)->next = node;
		node->next = NULL;
		*end = node;
	}

	printf("添加联系人\n姓名:> ");
	scanf("%s", node->data.name); // 传递 char 数组名
	printf("地址:> ");
	scanf("%s", node->data.addr);
	printf("电话:> ");
	scanf("%s", node->data.tele);
	printf("备注:> ");
	scanf("%s", node->data.note);
	*count += 1;
	printf("添加成功\n\n");
}

static void rmv_contact(size_t* count, contact** start, contact** end)
{
	assert(count && start && end);
	if (*count <= 0)
	{
		printf("联系人列表为空，无数据可删除\n\n");
		return;
	}

	printf("删除联系人\n请输入要删除的任意关键字:> ");
	char keyw[MAX_NOTE] = { 0 };
	scanf("%s", keyw);
	struct link link = find_contact(*start, keyw); // link.last->next == link.node
	if (NULL == link.node)
	{
		printf("删除失败，未找到任何联系人\n\n");
		return;
	}

	printf("找到以下联系人，是否删除\n");
	show_contact(link.node, link.node);
	printf("输入 1 确认删除，其他输入则取消\n");
	scanf(" %c", keyw);
	if (keyw[0] != '1')
	{
		printf("取消删除\n\n");
		return;
	}

	if(*count > 1) // 如果只有 1 个数据则不进入
	{
		link.last->next = link.node->next;
		if (NULL == link.node->next) // 如果删除的是最后一个节点则进入
		{
			*end = link.last;
		}

		free(link.node);
	}

	*count -= 1;
	printf("删除成功\n\n");
}

static void mod_contact(size_t* count, contact** start, contact** end)
{
	assert(count && start && end);
	if (*count <= 0)
	{
		printf("联系人列表为空，无数据可修改\n\n");
		return;
	}

	printf("修改联系人\n请输入要修改的任意关键字:> ");
	char keyw[MAX_NOTE] = { 0 };
	scanf("%s", keyw);
	struct link link = find_contact(*start, keyw);
	contact* node = link.node;
	if (NULL == node)
	{
		printf("修改失败，未找到任何联系人\n\n");
		return;
	}

	printf("找到以下联系人\n");
	show_contact(node, node);
	printf("输入 1 确认修改，其他输入则取消\n");
	scanf(" %c", keyw);
	if (keyw[0] != '1')
	{
		printf("取消修改\n\n");
		return;
	}

	printf("修改姓名:> ");
	scanf("%s", node->data.name);
	printf("修改地址:> ");
	scanf("%s", node->data.addr);
	printf("修改电话:> ");
	scanf("%s", node->data.tele);
	printf("修改备注:> ");
	scanf("%s", node->data.note);
	printf("修改成功\n\n");
}

static void scr_contact(size_t* count, contact** start, contact** end)
{
	assert(count && start && end);
	if (*count <= 0)
	{
		printf("联系人列表为空，无数据可查找\n\n");
		return;
	}

	printf("查找联系人\n请输入要查找的任意关键字:> ");
	char keyw[MAX_NOTE] = { 0 };
	scanf("%s", keyw);
	struct link link = find_contact(*start, keyw);
	if (NULL == link.node)
	{
		printf("未找到任何联系人\n\n");
		return;
	}

	printf("找到以下联系人\n");
	show_contact(link.node, link.node);
	printf("\n");
}

static void lst_contact(size_t* count, contact** start, contact** end)
{
	assert(count && start && end);
	if (*count <= 0)
	{
		printf("列表为空\n\n");
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

	// 排序

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