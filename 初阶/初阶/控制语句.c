// 分支语句 if
// if (表达式)
//     语句;
// 
// if (表达式)
//     语句1;
// else
//     语句2;
// 
// if (表达式1)
//     语句1;
// else if (表达式2)
//     语句2;
// else
//     语句3;
// 
// 在嵌套使用时，else 只会与最近的 if 匹配

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 判断年龄段
void if_main()
{
	int inp = 0;
	printf("\nif\n年龄\n");
	scanf("%d", &inp);
	if (inp < 18 && inp > 0)
	{
		printf("青少年\n");
	}
	else if (inp >= 18 && inp < 28)
	{
		printf("青年\n");
	}
	else if (inp >= 28 && inp < 40)
	{
		printf("中年\n");
	}
	else if (inp >= 40 && inp < 60)
	{
		printf("壮年\n");
	}
	else if (inp >= 60 && inp < 100)
	{
		printf("老年\n");
	}
	else if (inp >= 100)
	{
		printf("老寿星\n");
	}
	else
	{
		printf("年龄\n");
	}

}

// 分支语句 switch
// switch (整形表达式)
// {
//     case 整形常量表达式:
//         语句1;
//     case 整形常量表达式:
//         语句2;
//     default:
//         语句n;
// }
// 
// case 只是决定 switch 的入口，需要配合 break 跳出

// 判断星期
void switch_main()
{
	int day = 0;
	printf("\nswitch\n天\n");
	scanf("%d", &day);
	switch (day)
	{
	case 1:
		printf("星期一\n");
		break;
	case 2:
		printf("星期二\n");
		break;
	case 3:
		printf("星期三\n");
		break;
	case 4:
		printf("星期四\n");
		break;
	case 5:
		printf("星期五\n");
		break;
	case 6:
		printf("星期六\n");
		break;
	case 7:
		printf("星期日\n");
		break;
	default:
		printf("星期%d\n", day);
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

// 循环语句 while
// while (表达式)
//     循环语句;
// 表达式 为真则执行 循环语句
// 使用 break 可跳出循环；使用 continue 跳过本次循环后面的代码，然后转到 表达式 判断是否进入下一次循环

// 字符串输入和提取字符串数字
void while_main()
{
	int ch = 0;
	char inp[20] = { 0 };
	printf("\nwhile\n字符串\n");
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

	printf("提取数字\n");
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

// 循环语句 for
// for (表达式1; 表达式2; 表达式3;)
//     循环语句;
// 
// 表达式1 为初始化，表达式2 为条件判断，表达式3 为调整部分
// 运行到 for 语句时先执行表达式1，然后 表达式2 为真则执行循环语句，接着执行 表达式3，再判断 表达式2 是否满足下一次循环条件
// 使用 break 可跳出循环；使用 continue 跳过本次循环后面的代码，然后转到 表达式3 执行，接着转到 表达式2 判断是否进入下一次循环
// 表达式2 省略则判断恒真

// 打印1~9
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

// 循环语句 do-while
// do
//     循环语句;
// while (表达式);
// 
// 循环语句 至少会执行1次，执行 循环语句 后，表达式 为真则再次执行 循环语句
// 使用 break 可跳出循环；使用 continue 跳过本次循环后面的代码，然后转到表达式判断是否进入下一次循环

// 计算阶乘
void do_main()
{
	printf("\ndo-while\nCtrl+Z\n");
	int chk = 0;
	do
	{
		;
	} while ((chk = getchar()) != EOF);

	printf("1!+2!+3!+……+10!\n");
	int i = 1, n = 1, ret = 1, retu = 0;
	do
	{
		ret *= n;
		retu += ret;
		n++;
	} while (n <= 10);

	printf("%d\n", retu);
}