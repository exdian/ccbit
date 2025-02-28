#include "������.h"

// ��Ϸ���
void game_chess3()
{
	int inp = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu(); // �˵�
		scanf("%d", &inp);
		switch (inp)
		{
		default:
			printf("please try again\n");
			break;
		case 1: // ��ʼ
			printf("������\n");
			inside();
			break;
		case 2: // �˳�
			printf("exited\n");
			break;
		}

	} while (inp != 2);

}

// ��ӡ�˵�
static void menu()
{
	printf("=============  ������  =============\n");
	printf("======  1. start    2. quit   ======\n");
	printf("====================================\n");
}

// ��ʼ��Ϸ
static void inside()
{
	// ���̳�ʼ��
	char chess[ROW][COL] = { 0 };
	memset(chess, ' ', ROW * COL);

	// ��ӡ����
	chess_board(chess, ROW, COL);

	char ret = 0;
	while (true)
	{
		// �������
		player_step(chess, ROW, COL);

		// ��ӡ����
		chess_board(chess, ROW, COL);

		// �ж���Ӯ
		ret = chk_board(chess, ROW, COL);
		if (1 != ret)
		{
			break;
		}

		// ��������
		computer_step(chess, ROW, COL);

		// ��ӡ����
		chess_board(chess, ROW, COL);

		// �ж���Ӯ
		ret = chk_board(chess, ROW, COL);
		if (1 != ret)
		{
			break;
		}

	}

	if ('*' == ret)
	{
		printf("���ʤ��\n");
	}
	else if ('#' == ret)
	{
		printf("����ʤ��\n");
	}
	else
	{
		printf("ƽ��\n");
	}

	press_enter();
}

// ��ӡ����
static void chess_board(const char arr[ROW][COL], int row, int col)
{
#define ռλ "  "
#if COL < 10

	for (int j = 0; j < col; j++)
	{
		if (0 == j)
		{
			printf(ռλ);
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
			printf(ռλ);
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
					printf(ռλ);
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

#undef ռλ
}

// �������
static void player_step(char arr[ROW][COL], int row, int col)
{
	int r = -1, c = -1;
	while (true)
	{
		printf("�������:> �� ��\n");
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
				printf("���λ��������\n");
			}

		}
		else
		{
			printf("�������������\n");
		}

	}

}

// ��������
static void computer_step(char arr[ROW][COL], int row, int col)
{
	// ɨ���Ե����¼���������˺͵׶���ɨ�裬����������ɨ��
	//
	// ɨ���м䣬���кͶԽ�ɨ�裬Ѱ����������
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
			printf("��������:> %d %d\n", r + 1, c + 1);
			arr[r][c] = '#';
			break;
		}

	}

}

// �ж���Ӯ
static char chk_board(const char arr[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++) // �ж���
	{
		if (arr[i][0] != ' ' && arr[i][0] == arr[i][1] && arr[i][0] == arr[i][2])
		{
			return arr[i][0];
		}

	}

	for (int i = 0; i < col; i++) // �ж���
	{
		if (arr[0][i] != ' ' && arr[0][i] == arr[1][i] && arr[0][i] == arr[2][i])
		{
			return arr[0][i];
		}

	}

	if (arr[0][0] != ' ' && arr[0][0] == arr[1][1] && arr[0][0] == arr[2][2]) // �ж϶Խ�
	{
		return arr[0][0];
	}

	if (arr[0][2] != ' ' && arr[0][2] == arr[1][1] && arr[0][2] == arr[2][0]) // �ж϶Խ�
	{
		return arr[0][2];
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (' ' == arr[i][j])
			{
				return 1; // �������δ������1
			}

		}

	}

	return 0;
}

// ����Enter����
void press_enter()
{
	printf("����Enter����\n");
	getchar();
	while (getchar() != '\n');
}

#undef ROW
#undef COL