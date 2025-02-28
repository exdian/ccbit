#include "扫雷.h"

void game_mine()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	int inp = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		scanf("%d", &inp);
		switch (inp)
		{
		default:
			printf("敬请期待\n");
			break;
		case 1:
			printf("游戏开始\n");
			inside();
			break;
		case 2:
			printf("已退出\n");
			break;
		}

	} while (inp != 2);

}

// 打印菜单
static void menu()
{
		printf("==============  扫雷  ==============\n");
		printf("======   1. 开始    2. 退出   ======\n");
		printf("====================================\n");
}

// 开始游戏
static void inside()
{
	// 初始化
	char mine[ROWS][COLS] = { 0 }; // 雷的信息
	char show[ROWS][COLS] = { 0 }; // 显示信息。此处可使用一个数组，思路是设计符号，分别表示雷未被排查、非雷未被排查、非雷已排查的状态
	memset(mine, 0, ROWS * COLS); // 雷ascii 1，非雷ascii 0。打印时使用 %u
	//memset(show, '*', ROWS * COLS);
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (0 == i || ROWS - 1 == i || 0 == j || COLS - 1 == j)
			{
				show[i][j] = '%'; // 如果是外圈则修改为 %
			}
			else
			{
				show[i][j] = '*'; // 未排查的位置显示 *
			}
			
		}

	}
	
	// 生成雷
	int mine_num = put_mine(mine, ROWS - 2, COLS - 2);

	// 打印
	print(show, ROWS - 2, COLS - 2);
	//print(mine, ROWS - 2, COLS - 2);

	// 排查
	sweep(mine, show, mine_num, ROWS - 2, COLS - 2);
}

// 生成雷
static int put_mine(char mine[ROWS][COLS], int rows, int cols)
{
	printf("请输入雷的数量\n");
	int mine_num = 0;
	scanf("%d", &mine_num);
	if (mine_num > rows * cols) // 防止死循环
	{
		mine_num = rows * cols;
	}

	if (mine_num < 0)
	{
		mine_num = 0;
	}

	int i = 0;
	while (i < mine_num) // 用户输入大于 0 才进入循环，输入负数和 0 不进入循环
	{
		int r = rand() % rows + 1;
		int c = rand() % cols + 1;
		if (0 == mine[r][c]) // 随机到的格子不是雷才进入
		{
			i++;
			mine[r][c] = 1;
		}

	}

	return mine_num;
}

// 打印 char 数组，内圈开始
static void print(const char arr[ROWS][COLS], int rows, int cols)
{
	for (int i = 0; i < cols; i++)
	{
		printf("--");
	}

	printf("-\n");
	for (int i = 0; i <= cols; i++) // 打印列号
	{
		printf("%d ", i);
	}

	printf("\n");
	if (arr[0][0] > 2)
	{
		for (int i = 1; i <= rows; i++)
		{
			printf("%d ", i); // 行号
			for (int j = 1; j <= cols; j++)
			{
				printf("%c ", arr[i][j]);
			}

			printf("\n");
		}

	}
	else
	{
		for (int i = 1; i <= rows; i++)
		{
			printf("%d ", i); // 行号
			for (int j = 1; j <= cols; j++)
			{
				printf("%u ", arr[i][j]);
			}

			printf("\n");
		}

	}

	for (int i = 0; i < cols; i++)
	{
		printf("--");
	}

	printf("-\n\n");
}

// 排查
static void sweep(char mine[ROWS][COLS], char show[ROWS][COLS], int mine_num, int rows, int cols)
{
	int done = 0; // 已排查的格子
	int inp_row = 0;
	int inp_col = 0;
	chk_inp(show, &inp_row, &inp_col, rows, cols); // 第一次输入
	if (1 == mine[inp_row][inp_col] && rows * cols != mine_num) // 保护第一次输入
	{
		while (true)
		{
			int r = rand() % rows + 1;
			int c = rand() % cols + 1;
			if (0 == mine[r][c]) // 随机到的格子不是雷才进入
			{
				mine[r][c] = 1;
				mine[inp_row][inp_col] = 0;
				break;
			}

		}

	}

	while (true)
	{
		if (1 == mine[inp_row][inp_col]) // 如果是雷则进入
		{
			printf("失败\n");
			break;
		}
		
		done++;
		char show_num = mine_around(mine, inp_row, inp_col); // 检查周围雷的个数
		if (show_num)
		{
			show[inp_row][inp_col] = show_num + '0'; // 将雷的个数放在 show 数组对应格子中
		}
		else
		{
			show[inp_row][inp_col] = ' '; // 如果是 0 则对应格子放入空格，并且自动排查周围 8 个格子
			done += auto_sweep(mine, show, inp_row, inp_col); // 递归
		}

		print(show, rows, cols);
		// 根据 done 和 mine_num 判断是否胜利
		if (done + mine_num == rows * cols)
		{
			printf("胜利\n");
			break;
		}

		chk_inp(show, &inp_row, &inp_col, rows, cols); // 下一次输入
	}

	print_end(mine, show, rows, cols);
}

// 输入和校验
static void chk_inp(const char show[ROWS][COLS], int* inp_row, int* inp_col, int rows, int cols)
{
	while (true)
	{
		printf("请输入坐标:> ");
		scanf("%d%d", inp_row, inp_col);
		if ((*inp_row < 1) || (*inp_col < 1) || (*inp_row > rows) || (*inp_col > cols) || 
			('*' != show[*inp_row][*inp_col])) // 此处表达式从左到右计算，如果下标越界则能提前得出true，不会报错
		{
			printf("输入错误，请重试\n");
		}
		else
		{
			break;
		}

	}

}

// 计算周围雷的个数
static char mine_around(const char mine[ROWS][COLS], int row, int col)
{
	int rdec = row - 1;
	int cdec = col - 1;
	int rinc = row + 1;
	int cinc = col + 1;
	return (mine[rdec][cdec] + mine[rdec][col] + mine[rdec][cinc] +
			mine[row][cdec] +                  + mine[row][cinc] +
			mine[rinc][cdec] + mine[rinc][col] + mine[rinc][cinc]);
}

// 排查周围8个格子
static int auto_sweep(const char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int count = 0;
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if ('*' == show[row + i][col + j]) // 当这个格子没有排查过并且不是边缘才进入排查
			{
				count++;
				char show_num = mine_around(mine, row + i, col + j); // 检查周围雷的个数
				if (show_num)
				{
					show[row + i][col + j] = show_num + '0'; // 将雷的个数放在 show 数组对应格子中
				}
				else
				{
					show[row + i][col + j] = ' '; // 如果是 0 则对应格子放入空格，并且自动排查周围 8 个格子
					count += auto_sweep(mine, show, row + i, col + j);
				}

			}

		}

	}

	return count;
}

// 打印结算
static void print_end(const char mine[ROWS][COLS], const char show[ROWS][COLS], int rows, int cols)
{
	for (int i = 0; i < cols; i++)
	{
		printf("--");
	}

	printf("-\n");
	for (int i = 0; i <= cols; i++) // 打印列号
	{
		printf("%d ", i);
	}
	
	printf("\n");
	for (int i = 1; i <= rows; i++)
	{
		printf("%d ", i); // 行号
		for (int j = 1; j <= cols; j++)
		{
			if (0 == mine[i][j]) // 如果是雷则打印 #，如果不是雷则打印 show
			{
				printf("%c ", show[i][j]);
			}
			else
			{
				printf("# ");
			}

		}

		printf("\n");
	}

	for (int i = 0; i < cols; i++)
	{
		printf("--");
	}

	printf("-\n\n");
}