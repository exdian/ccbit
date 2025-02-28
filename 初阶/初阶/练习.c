// 注意所有可能溢出的情况
// 条件判断注意==

#include "练习.h"

// 二分法查找
void find_test()
{
	int num[] = { 1, 3, 4, 5, 7, 8, 9, 11, 14, 16, 26, 90 };
	int right_lab = sizeof(num) / sizeof(num[0]) - 1;
	int left_lab = 0;
	int mid_lab = 0;
	int inp = 0;
	printf("\n练习\n数字\n");
	scanf("%d", &inp);
	do
	{
		mid_lab = (right_lab - left_lab) / 2 + left_lab;
		if (num[mid_lab] < inp)
		{
			left_lab = mid_lab + 1;
		}
		else if (num[mid_lab] > inp)
		{
			right_lab = mid_lab - 1;
		}
		else
		{
			printf("第%d\n", mid_lab + 1);
			break;
		}

	} while (left_lab <= right_lab);
	
	if (left_lab > right_lab)
	{
		printf("N/A\n");
	}

}

// 字符串打印
void print_tit()
{
	char def[] = "Langer Mecca";
	char oup[] = "############";
	int left = 0;
	int right = ((int)strlen(def)) - 1;
	printf("\n练习\nEnter");
	while (getchar() != '\n');
	while (left <= right)
	{
		oup[left++] = def[left];
		oup[right--] = def[right];
		//left++;
		//right--;
		getchar();
		printf("%s", oup);
	}

	printf("\n");
}

// 模拟登录
void login()
{
	int i = 0;
	char inp[20] = { 0 };
	for (i = 0; i < 3; i++)
	{
		printf("\nabc\n");
		scanf("%s", inp);
		if (strcmp(inp, "abc") == 0)
		{
			printf("ture\n");
			break;
		}

		printf("not\n");
	}

	if (3 == i)
	{
		printf("false\n");
	}

}

// 猜数字
static int inside()
{
	int inp = 0;
	int def = (rand() % 100) + 1;
	printf("%d\n", def);
	while (1)
	{
		scanf("%d", &inp);
		if (inp < def)
		{
			printf("<\n");
		}
		else if (inp > def)
		{
			printf(">\n");
		}
		else
		{
			printf("=%d\n", def);
			break;
		}

	}

	printf("continue?\nY/N\n");
	char inpu = 0;
	scanf(" %c", &inpu);
	if (inpu == 'Y')
	{
		return 0;
	}
	else
	{
		printf("exit\n");
		return 2;
	}

}

// 猜数字
void game_pick_num()
{
	int inp = 1;
	printf("\n1/2\n");
	srand((unsigned int)time(NULL));
	do
	{
		if (inp)
		{
			scanf("%d", &inp);
			if (0 == inp)
			{
				inp = -1;
			}

		}

		switch (inp)
		{
		case 0:
		case 1:
			printf("start\n");
			inp = inside();
			while (getchar() != '\n');
			break;
		case 2:
			printf("exit\n");
			break;
		default:
			printf("?\n");
			break;
		}

	} while (2 != inp);

}

// 递归逆序字符串
void reverse_str(char* ptr)
{
	int len = (int)strlen(ptr) - 1;
	char temp = ptr[0];
	ptr[0] = ptr[len];
	ptr[len] = '\0';
	if (len > 1)
	{
		reverse_str(ptr + 1);
	}

	ptr[len] = temp;
}

// 每一位之和
int num_sum(unsigned int num)
{
	if (num > 9)
	{
		return num % 10 + num_sum(num / 10);
	}

	return num;
}

