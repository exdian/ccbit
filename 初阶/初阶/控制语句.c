// ��֧��� if
// if (���ʽ)
//     ���;
// 
// if (���ʽ)
//     ���1;
// else
//     ���2;
// 
// if (���ʽ1)
//     ���1;
// else if (���ʽ2)
//     ���2;
// else
//     ���3;
// 
// ��Ƕ��ʹ��ʱ��else ֻ��������� if ƥ��

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// �ж������
void if_main()
{
	int inp = 0;
	printf("\nif\n����\n");
	scanf("%d", &inp);
	if (inp < 18 && inp > 0)
	{
		printf("������\n");
	}
	else if (inp >= 18 && inp < 28)
	{
		printf("����\n");
	}
	else if (inp >= 28 && inp < 40)
	{
		printf("����\n");
	}
	else if (inp >= 40 && inp < 60)
	{
		printf("׳��\n");
	}
	else if (inp >= 60 && inp < 100)
	{
		printf("����\n");
	}
	else if (inp >= 100)
	{
		printf("������\n");
	}
	else
	{
		printf("����\n");
	}

}

// ��֧��� switch
// switch (���α��ʽ)
// {
//     case ���γ������ʽ:
//         ���1;
//     case ���γ������ʽ:
//         ���2;
//     default:
//         ���n;
// }
// 
// case ֻ�Ǿ��� switch ����ڣ���Ҫ��� break ����

// �ж�����
void switch_main()
{
	int day = 0;
	printf("\nswitch\n��\n");
	scanf("%d", &day);
	switch (day)
	{
	case 1:
		printf("����һ\n");
		break;
	case 2:
		printf("���ڶ�\n");
		break;
	case 3:
		printf("������\n");
		break;
	case 4:
		printf("������\n");
		break;
	case 5:
		printf("������\n");
		break;
	case 6:
		printf("������\n");
		break;
	case 7:
		printf("������\n");
		break;
	default:
		printf("����%d\n", day);
		break;
	}

	switch (day)
	{
	default:
		printf("week%d\n", day);
		break;
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
		printf("weekday\n");
		break;
	case 6:
	case 7:
		printf("weekend\n");
		break;
	}

}

// ѭ����� while
// while (���ʽ)
//     ѭ�����;
// ���ʽ Ϊ����ִ�� ѭ�����
// ʹ�� break ������ѭ����ʹ�� continue ��������ѭ������Ĵ��룬Ȼ��ת�� ���ʽ �ж��Ƿ������һ��ѭ��

// �ַ����������ȡ�ַ�������
void while_main()
{
	int ch = 0;
	char inp[20] = { 0 };
	printf("\nwhile\n�ַ���\n");
	ch = scanf("%s", inp);
	while ((ch = getchar()) != '\n')
	{
		;
	}

	printf("Y/N\n");
	ch = getchar();
	if ('Y' == ch)
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}

	printf("��ȡ����\n");
	while ((ch = getchar()) != '\n');
	while ((ch = getchar()) != EOF)
	{
		if (((ch < '0') || (ch > '9')) && (ch != '\n'))
		{
			continue;
		}

		putchar(ch);
	}

}

// ѭ����� for
// for (���ʽ1; ���ʽ2; ���ʽ3;)
//     ѭ�����;
// 
// ���ʽ1 Ϊ��ʼ�������ʽ2 Ϊ�����жϣ����ʽ3 Ϊ��������
// ���е� for ���ʱ��ִ�б��ʽ1��Ȼ�� ���ʽ2 Ϊ����ִ��ѭ����䣬����ִ�� ���ʽ3�����ж� ���ʽ2 �Ƿ�������һ��ѭ������
// ʹ�� break ������ѭ����ʹ�� continue ��������ѭ������Ĵ��룬Ȼ��ת�� ���ʽ3 ִ�У�����ת�� ���ʽ2 �ж��Ƿ������һ��ѭ��
// ���ʽ2 ʡ�����жϺ���

// ��ӡ1~9
void for_main()
{
	printf("\nfor\n1~9\n");
	int i = 0;
	for (i = 1; i < 10; i++)
	{
		printf("%d ", i);
	}

	int x = 0, y = 0;
	for (x = 0, y = 0; (x < 2) && (y < 5); x++, y++)
	{
		printf("?");
	}

	printf("\n");
}

// ѭ����� do-while
// do
//     ѭ�����;
// while (���ʽ);
// 
// ѭ����� ���ٻ�ִ��1�Σ�ִ�� ѭ����� �󣬱��ʽ Ϊ�����ٴ�ִ�� ѭ�����
// ʹ�� break ������ѭ����ʹ�� continue ��������ѭ������Ĵ��룬Ȼ��ת�����ʽ�ж��Ƿ������һ��ѭ��

// ����׳�
void do_main()
{
	printf("\ndo-while\nCtrl+Z\n");
	int chk = 0;
	do
	{
		;
	} while ((chk = getchar()) != EOF);

	printf("1!+2!+3!+����+10!\n");
	int i = 1, n = 1, ret = 1, retu = 0;
	do
	{
		ret *= n;
		retu += ret;
		n++;
	} while (n <= 10);

	printf("%d\n", retu);
}