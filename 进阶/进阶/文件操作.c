// �ڳ�������У��������ļ��������ļ��������ļ�
// �����ļ�����Դ�ļ�(.c)��Ŀ���ļ�(win�����º�׺Ϊ.obj)����ִ�г���(win�����º�׺Ϊ.exe)
// �����ļ�ָ���ǳ�������ʱҪ����������ļ�����������ݵ��ļ����˴���������������ڴ�Ϊ��һ�˳��ӽ���������
// �ļ�����Ψһ�ģ����� 3 ���֣��ļ�·�� + �ļ������� + �ļ���׺
// 
// �ļ��Ĵ򿪺͹ر�Ҫʹ���ļ�ָ�룬Ҳ�����ļ���
// ÿ����ʹ�õ��ļ������ڴ��п�����һ����Ӧ���ļ���Ϣ������������ļ��������Ϣ���ļ���Ϣ����һ���ṹ��������� stdio.h ��ȡ��Ϊ FILE
// �ļ�ָ�����ָ���ڴ��е�ĳ���ļ���Ϣ���׵�ַ��ָ�룬ͨ���ļ�ָ����ܹ����ʸ��ļ�
// �ļ��ڶ�д֮ǰӦ���ȴ��ļ�����ʹ�ý���֮��Ӧ�ùر��ļ�
// ����ʹ�� fopen �������ļ���ʹ�� fclose �ر��ļ�
// 
// �ļ�����ϵͳ
// ϵͳ���Զ����ڴ���Ϊ������ÿһ������ʹ�õ��ļ�����һ���ļ�������
// ���ڴ�������ݻ����͵������������װ�����������һ���͵�������
// �������ݵ��ڴ����ļ��Ӵ����ж�ȡ�����뻺�������ٴӻ������͵��������������ڶ�ȡʱ���뻺������װ��
// �������Ĵ�Сȡ����C����ϵͳ
// ����ʹ�� fflush ����ˢ�»�������ˢ��ʱ�Ὣ���������������д���ļ������� fclose Ҳ�Ὣ���������������д���ļ�
// 
// fopen
// ��һ���������ļ������ڶ����������ļ��Ĵ�ģʽ������ const char* ��������
// ��ģʽ��+ �������д��b ���������
// "r"		��һ���ļ����ж����ݣ����ļ���������ʱ���ؿ�ָ��
// "w"		��һ���ļ�����д���ݣ����ļ���������ʱ�½�һ���ļ�
// "a"		��һ���ļ������ļ�β������ݣ����ļ���������ʱ�½�һ���ļ�
// "rb"		��һ���������ļ����ж����ݣ����ļ���������ʱʱ���ؿ�ָ��
// "wb"		��һ���������ļ�����д���ݣ����ļ���������ʱ�½�һ���ļ�
// "ab"		��һ���������ļ������ļ�β������ݣ����ļ���������ʱ�½�һ���ļ�
// "r+"		��һ���ļ����ж���д�����ļ���������ʱ���ؿ�ָ��
// "w+"		��һ���ļ����ж���д�����ļ���������ʱ�½�һ���ļ�
// "a+"		��һ���ļ������ļ�β���ж���д�����ļ���������ʱ�½�һ���ļ�
// "rb+"	��һ���������ļ����ж���д�����ļ���������ʱ���ؿ�ָ��
// "wb+"	��һ���������ļ����ж���д�����ļ���������ʱ�½�һ���ļ�
// "ab+"	��һ���������ļ������ļ�β���ж���д�����ļ���������ʱ�½�һ���ļ�
// 
// fclose
// �����ļ�ָ����Թر�ָ����ļ������ݿ�ָ��ʱδ���壬ȡ���ڱ�����
// 
// C �����Ĭ�ϴ� 3 ������
// FILE* stdin	��׼������������
// FILE* stdout	��׼���������Ļ
// FILE* stderr	��׼����������Ļ
// 
// �ļ���˳���д
// fgetc	�������������������ַ����뺯��
// fputc	������������������ַ��������
// fgets	�������������������ַ������뺯��
// fputs	������������������ַ����������
// fscanf	�����������������ĸ�ʽ�����뺯��
// fprintf	����������������ĸ�ʽ���������
// fread	�������ļ��Ķ��������뺯��������ֵ�����������ĸ���
// fwrite	�������ļ��Ķ������������
// 
// �ļ��������д
// fseek	�����ļ�ָ���λ�ú�ƫ��������λ�ļ�ָ�롣������������ѡ SEEK_SET��SEEK_CUR��SEEK_END
// ftell	�����ļ�ָ�뵱ǰ��ƫ����
// rewind	ʹ�ļ�ָ��ƫ�����ص� 0
// 
// �ļ��������ú���
// sscanf	��ȡ�ַ���ת���ɸ�ʽ��������(�����л�)
// sprintf	�Ѹ�ʽ��������ת�����ַ���(���л�)
// feof		���ļ���ȡ������ʱ�������ж��ǲ��������ļ�ĩβ����
// ferror	���ļ���ȡ������ʱ�������ж��ǲ��Ƕ�ȡʧ�ܽ���

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

	{ // ���ֽڶ�д
		FILE* pf = fopen("test.txt", "w");
		perror("fopen w");
		if (NULL == pf)
		{
			return;
		}

		for (char i = 33; i < 126; i++)
		{
			fputc(i, pf); // һ��һ���ֽ�д
		}

		fclose(pf); // ��д�ķ�ʽ��ֻ��д��Ҫ���Ļ���Ҫ�ر��ļ��ö��ķ�ʽ��
		perror("fclose");
		pf = NULL; // �ر��ļ����ļ�ָ��Ҫ��ʱ��Ϊ��ָ��
		pf = fopen("test.txt", "r");
		perror("fopen r");
		if (NULL == pf)
		{
			return;
		}

		int c = 0;
		while ((c = fgetc(pf)) != EOF) // һ��һ���ֽڶ�
		{
			printf("%c", c);
		}

		while (fclose(pf) == EOF) // �ر�ʧ��ʱ����
		{
			perror("fclose");
			getchar();
		}

		pf = NULL;
	}

	{
		// ���ַ���Ϊ��λд
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
		// ָ�������ٸ��ֽڲ��ڶ�ȡ���ڽ�β���'\0'
		pf = fopen("test.txt", "r");
		perror("fopen r");
		if (NULL == pf)
		{
			return;
		}

		char arr[10] = { 0 };
		printf(fgets(arr, 10, pf)); // ʵ�ʶ��� 9 ���ֽڣ��� 10 ���ֽ���'\0'
		printf(fgets(arr, 10, pf)); // ����ǰ 18 ���ֽ�
		while (fgets(arr, 10, pf) != NULL) // �����ļ�ĩβ���ؿ�ָ��
		{
			printf(arr);
		}

		fclose(pf);
		perror("\nfclose");
		pf = NULL;
	}
	
	{
		// ��ʽ��д
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
		// ��ʽ����
		pf = fopen("test.txt", "r");
		perror("fopen r");
		if (NULL == pf)
		{
			return;
		}

		fscanf(pf, "%s %d %f\n", s1.name, &s1.age, &s1.score); // ���ʳ�Ա������������ȡ��ַ������
		fscanf(pf, "name:%s age:%d score:%f", s2.name, &s2.age, &s2.score); // ���ַ��������ո��ֹͣ
		fclose(pf);
		pf = NULL;
		printf("%s %d %f\nname:%s, age:%d, score:%f\n", s1.name, s1.age, s1.score, s2.name, s2.age, s2.score);
	}

	{ // �����ƵĶ���д����'\0'���ո񡢻����Լ������κ��ַ���Ӱ��
	l1:; // �˴����ӷֺ�Ҳ�ܱ���ɹ�������VS�ᱨ���� E1072 �������ܰ�����ǩ������bug
		// �����Ƶ�д����
		FILE* pf = fopen("test.bin", "wb");
		perror("fopen w");
		if (NULL == pf)
		{
			return;
		}

		struct test s0 = { "name", 120, 0.05f };
		fwrite(&s0, sizeof(struct test), 1, pf); // �Ӵ��ݵ�ָ��ָ��ĵ�ַ��ʼ�����ֽ�д���ļ���ֱ���ﵽָ�����ֽ���
		fclose(pf);
		pf = NULL;
		// �����ƵĶ�����
		pf = fopen("test.bin", "rb");
		perror("fopen r");
		if (NULL == pf)
		{
			return;
		}

		struct test s1 = { 0 };
		fread(&s1, sizeof(s1), 1, pf); // ���ֽڶ�ȡ�ļ����ݵ�ָ��ָ��ĵ�ַΪ�׵�����ֱ���ﵽָ�����ֽ����� EOF
		struct test s2 = { 0 };
		fseek(pf, -2, SEEK_CUR); // ��ʱ�ļ�ָ���Ѿ�ָ���ļ�ĩβ����ǰƫ�� 2 ���ֽ�
		fread(&s2, sizeof(s1), 1, pf); // ��ǰָ���ȡ 2 ���ֽں������ EOF������ s2 ֻ����͵�ַ�� 2 ���ֽڷ����˸ı�
		if (feof(pf)) // ����ȡ��������Ƿ����I/O����
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

	{ // �޸��ļ�ָ��ƫ����
		FILE* pf = fopen("test.txt", "r");
		perror("fopen r");
		if (NULL == pf)
		{
			return;
		}

		long n = 1;
		rewind(pf); // ʹƫ��������
		fseek(pf, n, SEEK_SET); // ʹ�� SEEK_SET ����ƫ����Ϊ n��Ҳ���Ǵӵ� n ���ֽڿ�ʼ���ڶ���������ʱֻ��Ϊ��Ȼ��
		fseek(pf, n, SEEK_CUR); // SEEK_CUR ʹƫ�����ڵ�ǰ�Ļ����ϼ� n
		fseek(pf, -n, SEEK_END); // ʹ�� SEEK_END ���ļ�ĩβ��ʼƫ�� n ���ֽڡ��ڶ���������ʱֻ��Ϊ������
		n = ftell(pf); // �����ļ�ָ���������ʼλ�õ�ƫ����
		fclose(pf);
		pf = NULL;
	}

}