// 在程序设计中，有两种文件：程序文件、数据文件
// 程序文件包括源文件(.c)、目标文件(win环境下后缀为.obj)、可执行程序(win环境下后缀为.exe)
// 数据文件指的是程序运行时要从中输入的文件或者输出内容的文件，此处的输出输入是以内存为第一人称视角来描述的
// 文件名是唯一的，包含 3 部分：文件路径 + 文件名主干 + 文件后缀
// 
// 文件的打开和关闭要使用文件指针，也就是文件流
// 每个被使用的文件都在内存中开辟了一个相应的文件信息区，用来存放文件的相关信息，文件信息区是一个结构体变量，在 stdio.h 中取名为 FILE
// 文件指针就是指向内存中的某个文件信息区首地址的指针，通过文件指针就能够访问该文件
// 文件在读写之前应该先打开文件，在使用结束之后应该关闭文件
// 可以使用 fopen 函数打开文件，使用 fclose 关闭文件
// 
// 文件缓冲系统
// 系统会自动在内存中为程序中每一个正在使用的文件开辟一块文件缓冲区
// 从内存输出数据会先送到输出缓冲区，装满缓冲区后才一起送到磁盘上
// 输入数据到内存会把文件从磁盘中读取到输入缓冲区，再从缓冲区送到程序数据区。在读取时输入缓冲区会装满
// 缓冲区的大小取决于C编译系统
// 可以使用 fflush 函数刷新缓冲区，刷新时会将输出缓冲区的数据写到文件，另外 fclose 也会将输出缓冲区的数据写到文件
// 
// fopen
// 第一个参数是文件名，第二个参数是文件的打开模式，都是 const char* 类型数据
// 打开模式。+ 代表读和写，b 代表二进制
// "r"		打开一个文件进行读数据，当文件名不存在时返回空指针
// "w"		打开一个文件进行写数据，当文件名不存在时新建一个文件
// "a"		打开一个文件，在文件尾添加数据，当文件名不存在时新建一个文件
// "rb"		打开一个二进制文件进行读数据，当文件名不存在时时返回空指针
// "wb"		打开一个二进制文件进行写数据，当文件名不存在时新建一个文件
// "ab"		打开一个二进制文件，在文件尾添加数据，当文件名不存在时新建一个文件
// "r+"		打开一个文件进行读和写，当文件名不存在时返回空指针
// "w+"		打开一个文件进行读和写，当文件名不存在时新建一个文件
// "a+"		打开一个文件，在文件尾进行读和写，当文件名不存在时新建一个文件
// "rb+"	打开一个二进制文件进行读和写，当文件名不存在时返回空指针
// "wb+"	打开一个二进制文件进行读和写，当文件名不存在时新建一个文件
// "ab+"	打开一个二进制文件，在文件尾进行读和写，当文件名不存在时新建一个文件
// 
// fclose
// 传递文件指针可以关闭指向的文件，传递空指针时未定义，取决于编译器
// 
// C 程序会默认打开 3 个流：
// FILE* stdin	标准输入流，键盘
// FILE* stdout	标准输出流，屏幕
// FILE* stderr	标准错误流，屏幕
// 
// 文件的顺序读写
// fgetc	适用于所有输入流的字符输入函数
// fputc	适用于所有输出流的字符输出函数
// fgets	适用于所有输入流的字符串输入函数
// fputs	适用于所有输出流的字符串输出函数
// fscanf	适用于所有输入流的格式化输入函数
// fprintf	适用于所有输出流的格式化输出函数
// fread	适用于文件的二进制输入函数。返回值是完整读到的个数
// fwrite	适用于文件的二进制输出函数
// 
// 文件的随机读写
// fseek	根据文件指针的位置和偏移量来定位文件指针。第三个参数可选 SEEK_SET、SEEK_CUR、SEEK_END
// ftell	返回文件指针当前的偏移量
// rewind	使文件指针偏移量回到 0
// 
// 文件操作常用函数
// sscanf	读取字符串转换成格式化的数据(反序列化)
// sprintf	把格式化的数据转换成字符串(序列化)
// feof		当文件读取结束的时候，用来判断是不是遇到文件末尾结束
// ferror	当文件读取结束的时候，用来判断是不是读取失败结束

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
struct test
{
	char name[12];
	int age;
	float score;
};

void test_file()
{
	goto l1;

	{ // 逐字节读写
		FILE* pf = fopen("test.txt", "w");
		perror("fopen w");
		if (NULL == pf)
		{
			return;
		}

		for (char i = 33; i < 126; i++)
		{
			fputc(i, pf); // 一个一个字节写
		}

		fclose(pf); // 以写的方式打开只能写，要读的话需要关闭文件用读的方式打开
		perror("fclose");
		pf = NULL; // 关闭文件后文件指针要及时置为空指针
		pf = fopen("test.txt", "r");
		perror("fopen r");
		if (NULL == pf)
		{
			return;
		}

		int c = 0;
		while ((c = fgetc(pf)) != EOF) // 一个一个字节读
		{
			printf("%c", c);
		}

		while (fclose(pf) == EOF) // 关闭失败时进入
		{
			perror("fclose");
			getchar();
		}

		pf = NULL;
	}

	{
		// 以字符串为单位写
		FILE* pf = fopen("test.txt", "w");
		perror("\nfopen w");
		if (NULL == pf)
		{
			return;
		}

		fputs("!\"#$ % &'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}\n", pf);
		fputs("!\"#$ % &'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}", pf);
		fclose(pf);
		perror("fclose");
		pf = NULL;
		// 指定读多少个字节并在读取后在结尾添加'\0'
		pf = fopen("test.txt", "r");
		perror("fopen r");
		if (NULL == pf)
		{
			return;
		}

		char arr[10] = { 0 };
		printf(fgets(arr, 10, pf)); // 实际读了 9 个字节，第 10 个字节是'\0'
		printf(fgets(arr, 10, pf)); // 读了前 18 个字节
		while (fgets(arr, 10, pf) != NULL) // 读到文件末尾返回空指针
		{
			printf(arr);
		}

		fclose(pf);
		perror("\nfclose");
		pf = NULL;
	}
	
	{
		// 格式化写
		FILE* pf = fopen("test.txt", "w");
		perror("fopen w");
		if (NULL == pf)
		{
			return;
		}

		struct test s0 = { "name", 12, 1.5f };
		struct test s1 = { 0 };
		struct test s2 = { 0 };
		fprintf(pf, "%s %d %f\n", s0.name, s0.age, s0.score);
		fprintf(pf, "name:%s age:%d score:%f", "s.name", 11, 5.5f);
		fclose(pf);
		pf = NULL;
		// 格式化读
		pf = fopen("test.txt", "r");
		perror("fopen r");
		if (NULL == pf)
		{
			return;
		}

		fscanf(pf, "%s %d %f\n", s1.name, &s1.age, &s1.score); // 访问成员操作符优先于取地址操作符
		fscanf(pf, "name:%s age:%d score:%f", s2.name, &s2.age, &s2.score); // 读字符串遇到空格会停止
		fclose(pf);
		pf = NULL;
		printf("%s %d %f\nname:%s, age:%d, score:%f\n", s1.name, s1.age, s1.score, s2.name, s2.age, s2.score);
	}

	{ // 二进制的读和写不受'\0'、空格、换行以及其他任何字符的影响
	l1:; // 此处不加分号也能编译成功，但是VS会报错误 E1072 声明不能包含标签，疑似bug
		// 二进制的写操作
		FILE* pf = fopen("test.bin", "wb");
		perror("fopen w");
		if (NULL == pf)
		{
			return;
		}

		struct test s0 = { "name", 120, 0.05f };
		fwrite(&s0, sizeof(struct test), 1, pf); // 从传递的指针指向的地址开始，逐字节写入文件，直到达到指定的字节数
		fclose(pf);
		pf = NULL;
		// 二进制的读操作
		pf = fopen("test.bin", "rb");
		perror("fopen r");
		if (NULL == pf)
		{
			return;
		}

		struct test s1 = { 0 };
		fread(&s1, sizeof(s1), 1, pf); // 逐字节读取文件内容到指针指向的地址为首的区域，直到达到指定的字节数或 EOF
		struct test s2 = { 0 };
		fseek(pf, -2, SEEK_CUR); // 此时文件指针已经指到文件末尾，向前偏移 2 个字节
		fread(&s2, sizeof(s1), 1, pf); // 当前指针读取 2 个字节后会遇到 EOF，所以 s2 只有最低地址的 2 个字节发生了改变
		if (feof(pf)) // 当读取结束检查是否出现I/O错误
		{
			perror("end of file");
		}
		/*else */if (ferror(pf))
		{
			perror("fread");
		}

		fclose(pf);
		pf = NULL;
		printf("%s %d %f\n", s1.name, s1.age, s1.score);
	}

	{ // 修改文件指针偏移量
		FILE* pf = fopen("test.txt", "r");
		perror("fopen r");
		if (NULL == pf)
		{
			return;
		}

		long n = 1;
		rewind(pf); // 使偏移量归零
		fseek(pf, n, SEEK_SET); // 使用 SEEK_SET 设置偏移量为 n，也就是从第 n 个字节开始。第二个参数此时只能为自然数
		fseek(pf, n, SEEK_CUR); // SEEK_CUR 使偏移量在当前的基础上加 n
		fseek(pf, -n, SEEK_END); // 使用 SEEK_END 从文件末尾开始偏移 n 个字节。第二个参数此时只能为负整数
		n = ftell(pf); // 返回文件指针相对于起始位置的偏移量
		fclose(pf);
		pf = NULL;
	}

}