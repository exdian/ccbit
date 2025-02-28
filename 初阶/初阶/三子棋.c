#include "三子棋.h"

// 游戏入口
void game_chess3()
{
	int inp = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu(); // 菜单
		scanf("%d", &inp);
		switch (inp)
		{
		default:
			printf("please try again\n");
			break;
		case 1: // 开始
			printf("三子棋\n");
			inside();
			break;
		case 2: // 退出
			printf("exited\n");
			break;
		}

	} while (inp != 2);

}

// 打印菜单
static void menu()
{
	printf("=============  三子棋  =============\n");
	printf("======  1. start    2. quit   ======\n");
	printf("====================================\n");
}

// 开始游戏
static void inside()
{
	// 棋盘初始化
	char chess[ROW][COL] = { 0 };
	memset(chess, ' ', ROW * COL);

	// 打印棋盘
	chess_board(chess, ROW, COL);

	char ret = 0;
	while (true)
	{
		// 玩家下棋
		player_step(chess, ROW, COL);

		// 打印棋盘
		chess_board(chess, ROW, COL);

		// 判断输赢
		ret = chk_board(chess, ROW, COL);
		if (1 != ret)
		{
			break;
		}

		// 电脑下棋
		computer_step(chess, ROW, COL);

		// 打印棋盘
		chess_board(chess, ROW, COL);

		// 判断输赢
		ret = chk_board(chess, ROW, COL);
		if (1 != ret)
		{
			break;
		}

	}

	if ('*' == ret)
	{
		printf("玩家胜利\n");
	}
	else if ('#' == ret)
	{
		printf("电脑胜利\n");
	}
	else
	{
		printf("平局\n");
	}

	press_enter();
}

// 打印棋盘
static void chess_board(const char arr[ROW][COL], int row, int col)
{
#define 占位 "  "
#if COL < 10

	for (int j = 0; j < col; j++)
	{
		if (0 == j)
		{
			printf(占位);
		}
		else
		{
			printf(" ");
		}

		printf(" %d ", j + 1);
	}

#else

	for (int j = 0; j < col; j++)
	{
		if (0 == j)
		{
			printf(占位);
		}
		else
		{
			printf(" ");
		}

		printf("%3d", j + 1);
	}

#endif // COL < 10

	printf("\n");
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (0 == j)
			{
				printf("%2d", i + 1);
			}
			else
			{
				printf("|");
			}

			printf(" %c ", arr[i][j]);
		}

		printf("\n");
		if (i < row - 1)
		{
			for (int j = 0; j < col; j++)
			{
				if (0 == j)
				{
					printf(占位);
				}
				else
				{
					printf("|");
				}

				printf("---");
			}

		}

		printf("\n");
	}

#undef 占位
}

// 玩家下棋
static void player_step(char arr[ROW][COL], int row, int col)
{
	int r = -1, c = -1;
	while (true)
	{
		printf("玩家下棋:> 行 列\n");
		scanf("%d %d", &r, &c);
		if (r <= row && c <= col && r >= 1 && c >= 1)
		{
			if (' ' == arr[r - 1][c - 1])
			{
				arr[r - 1][c - 1] = '*';
				break;
			}
			else
			{
				printf("这个位置有棋啦\n");
			}

		}
		else
		{
			printf("输入错误，请重试\n");
		}

	}

}

// 电脑下棋
static void computer_step(char arr[ROW][COL], int row, int col)
{
	// 扫描边缘，记录子力，顶端和底端行扫描，左右两端列扫描
	//
	// 扫描中间，行列和对角扫描，寻找特殊棋形
	//for (int i = RULE / 2; i < row; i++)
	//{
	//	for (int j = RULE / 2; j < col; j++)
	//	{
	//
	//	}
	//
	//}

	while (true)
	{
		int r = rand() % row;
		int c = rand() % col;
		if (' ' == arr[r][c])
		{
			printf("电脑下棋:> %d %d\n", r + 1, c + 1);
			arr[r][c] = '#';
			break;
		}

	}

}

// 判断输赢
static char chk_board(const char arr[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++) // 判断行
	{
		if (arr[i][0] != ' ' && arr[i][0] == arr[i][1] && arr[i][0] == arr[i][2])
		{
			return arr[i][0];
		}

	}

	for (int i = 0; i < col; i++) // 判断列
	{
		if (arr[0][i] != ' ' && arr[0][i] == arr[1][i] && arr[0][i] == arr[2][i])
		{
			return arr[0][i];
		}

	}

	if (arr[0][0] != ' ' && arr[0][0] == arr[1][1] && arr[0][0] == arr[2][2]) // 判断对角
	{
		return arr[0][0];
	}

	if (arr[0][2] != ' ' && arr[0][2] == arr[1][1] && arr[0][2] == arr[2][0]) // 判断对角
	{
		return arr[0][2];
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (' ' == arr[i][j])
			{
				return 1; // 如果棋盘未满返回1
			}

		}

	}

	return 0;
}

// 按下Enter继续
void press_enter()
{
	printf("按下Enter继续\n");
	getchar();
	while (getchar() != '\n');
}

#undef ROW
#undef COL