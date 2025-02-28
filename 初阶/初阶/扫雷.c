#include "ɨ��.h"

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
			printf("�����ڴ�\n");
			break;
		case 1:
			printf("��Ϸ��ʼ\n");
			inside();
			break;
		case 2:
			printf("���˳�\n");
			break;
		}

	} while (inp != 2);

}

// ��ӡ�˵�
static void menu()
{
		printf("==============  ɨ��  ==============\n");
		printf("======   1. ��ʼ    2. �˳�   ======\n");
		printf("====================================\n");
}

// ��ʼ��Ϸ
static void inside()
{
	// ��ʼ��
	char mine[ROWS][COLS] = { 0 }; // �׵���Ϣ
	char show[ROWS][COLS] = { 0 }; // ��ʾ��Ϣ���˴���ʹ��һ�����飬˼·����Ʒ��ţ��ֱ��ʾ��δ���Ų顢����δ���Ų顢�������Ų��״̬
	memset(mine, 0, ROWS * COLS); // ��ascii 1������ascii 0����ӡʱʹ�� %u
	//memset(show, '*', ROWS * COLS);
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (0 == i || ROWS - 1 == i || 0 == j || COLS - 1 == j)
			{
				show[i][j] = '%'; // �������Ȧ���޸�Ϊ %
			}
			else
			{
				show[i][j] = '*'; // δ�Ų��λ����ʾ *
			}
			
		}

	}
	
	// ������
	int mine_num = put_mine(mine, ROWS - 2, COLS - 2);

	// ��ӡ
	print(show, ROWS - 2, COLS - 2);
	//print(mine, ROWS - 2, COLS - 2);

	// �Ų�
	sweep(mine, show, mine_num, ROWS - 2, COLS - 2);
}

// ������
static int put_mine(char mine[ROWS][COLS], int rows, int cols)
{
	printf("�������׵�����\n");
	int mine_num = 0;
	scanf("%d", &mine_num);
	if (mine_num > rows * cols) // ��ֹ��ѭ��
	{
		mine_num = rows * cols;
	}

	if (mine_num < 0)
	{
		mine_num = 0;
	}

	int i = 0;
	while (i < mine_num) // �û�������� 0 �Ž���ѭ�������븺���� 0 ������ѭ��
	{
		int r = rand() % rows + 1;
		int c = rand() % cols + 1;
		if (0 == mine[r][c]) // ������ĸ��Ӳ����ײŽ���
		{
			i++;
			mine[r][c] = 1;
		}

	}

	return mine_num;
}

// ��ӡ char ���飬��Ȧ��ʼ
static void print(const char arr[ROWS][COLS], int rows, int cols)
{
	for (int i = 0; i < cols; i++)
	{
		printf("--");
	}

	printf("-\n");
	for (int i = 0; i <= cols; i++) // ��ӡ�к�
	{
		printf("%d ", i);
	}

	printf("\n");
	if (arr[0][0] > 2)
	{
		for (int i = 1; i <= rows; i++)
		{
			printf("%d ", i); // �к�
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
			printf("%d ", i); // �к�
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

// �Ų�
static void sweep(char mine[ROWS][COLS], char show[ROWS][COLS], int mine_num, int rows, int cols)
{
	int done = 0; // ���Ų�ĸ���
	int inp_row = 0;
	int inp_col = 0;
	chk_inp(show, &inp_row, &inp_col, rows, cols); // ��һ������
	if (1 == mine[inp_row][inp_col] && rows * cols != mine_num) // ������һ������
	{
		while (true)
		{
			int r = rand() % rows + 1;
			int c = rand() % cols + 1;
			if (0 == mine[r][c]) // ������ĸ��Ӳ����ײŽ���
			{
				mine[r][c] = 1;
				mine[inp_row][inp_col] = 0;
				break;
			}

		}

	}

	while (true)
	{
		if (1 == mine[inp_row][inp_col]) // ������������
		{
			printf("ʧ��\n");
			break;
		}
		
		done++;
		char show_num = mine_around(mine, inp_row, inp_col); // �����Χ�׵ĸ���
		if (show_num)
		{
			show[inp_row][inp_col] = show_num + '0'; // ���׵ĸ������� show �����Ӧ������
		}
		else
		{
			show[inp_row][inp_col] = ' '; // ����� 0 ���Ӧ���ӷ���ո񣬲����Զ��Ų���Χ 8 ������
			done += auto_sweep(mine, show, inp_row, inp_col); // �ݹ�
		}

		print(show, rows, cols);
		// ���� done �� mine_num �ж��Ƿ�ʤ��
		if (done + mine_num == rows * cols)
		{
			printf("ʤ��\n");
			break;
		}

		chk_inp(show, &inp_row, &inp_col, rows, cols); // ��һ������
	}

	print_end(mine, show, rows, cols);
}

// �����У��
static void chk_inp(const char show[ROWS][COLS], int* inp_row, int* inp_col, int rows, int cols)
{
	while (true)
	{
		printf("����������:> ");
		scanf("%d%d", inp_row, inp_col);
		if ((*inp_row < 1) || (*inp_col < 1) || (*inp_row > rows) || (*inp_col > cols) || 
			('*' != show[*inp_row][*inp_col])) // �˴����ʽ�����Ҽ��㣬����±�Խ��������ǰ�ó�true�����ᱨ��
		{
			printf("�������������\n");
		}
		else
		{
			break;
		}

	}

}

// ������Χ�׵ĸ���
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

// �Ų���Χ8������
static int auto_sweep(const char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int count = 0;
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if ('*' == show[row + i][col + j]) // ���������û���Ų�����Ҳ��Ǳ�Ե�Ž����Ų�
			{
				count++;
				char show_num = mine_around(mine, row + i, col + j); // �����Χ�׵ĸ���
				if (show_num)
				{
					show[row + i][col + j] = show_num + '0'; // ���׵ĸ������� show �����Ӧ������
				}
				else
				{
					show[row + i][col + j] = ' '; // ����� 0 ���Ӧ���ӷ���ո񣬲����Զ��Ų���Χ 8 ������
					count += auto_sweep(mine, show, row + i, col + j);
				}

			}

		}

	}

	return count;
}

// ��ӡ����
static void print_end(const char mine[ROWS][COLS], const char show[ROWS][COLS], int rows, int cols)
{
	for (int i = 0; i < cols; i++)
	{
		printf("--");
	}

	printf("-\n");
	for (int i = 0; i <= cols; i++) // ��ӡ�к�
	{
		printf("%d ", i);
	}
	
	printf("\n");
	for (int i = 1; i <= rows; i++)
	{
		printf("%d ", i); // �к�
		for (int j = 1; j <= cols; j++)
		{
			if (0 == mine[i][j]) // ����������ӡ #��������������ӡ show
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