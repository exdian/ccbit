// �������ܱ�ʾ��Ԫ�ص�ַ
// ���������������������sizeof ����������ʾ�������飻��������ʹ�� & ʱȡ��������������ĵ�ַ
// ���� arr ������������ʾ��������Ԫ�صĵ�ַ��arr �� &arr[0] Ч����ͬ����ַ�ڼӼ�����ʱ������Ԫ�صĴ�С���� &arr �ڼӼ�����ʱ��������������Ĵ�С

// ð������
void sort_bubble(int arr[], int count)
{
	int max_lab = count - 1;
	for (int i = 0; i < max_lab; i++)
	{
		int lab = max_lab - i;
		for (int j = 0; j < lab; j++)
		{
			int a = j + 1;
			if (arr[j] > arr[a]) // ����
			{
				int b = arr[j];
				arr[j] = arr[a];
				arr[a] = b;
			}

		}

	}

}