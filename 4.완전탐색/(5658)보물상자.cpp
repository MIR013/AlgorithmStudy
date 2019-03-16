#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int N, k;
char input[100];

int toDecimal(char hex[],int size)
{
	int num=0;
	for (int i = 0; i < size; i++)
	{
		int seat = (N / 4) - i - 1;
		int mul = 1;
		//�ߺ��̾��� ��
		if (hex[0] == '\0')
			return -1;
		//����
		for (int j = 0; j < seat; j++) {
			mul *= 16;
		}
		if (hex[i]-'0' >= 10) {
			//������ ���
			num += ((hex[i]-'A'+10) * mul);
		}
		else {
			num += ((hex[i] - '0') * mul);
		}
	}
	return num;
}
int pwd()
{
	char icase[100][100];

	int time = N / 4;
	int index = 0;
	for (int i = 0; i < time; i++)
	{
		//���� �� �ִ� ��� ��츦 ã�´�
		//N/4 -1 ȸ �ݺ�
		for (int j = 0; j < N; j=j+time)
		{
			int k;
			for (k = 0;k<time; k++)
			{
				//�ѹ��� ���� index ó�� %
				int next = (j + k + i) % N;
				icase[index][k] = input[next];
			}
			icase[index][k] = '\0';
			index++;
		}
	}

	// �ߺ��� �� ����
	int list[100];
	int listIndex = 0;
	for (int i = 0; i < index; i++)
	{
		for (int j = i+1; j < index; j++) {
			if (strcmp(icase[i],icase[j]) == 0) {
				icase[i][0] = '\0'; // ��ȯ�ص� 0�� �ǰ�
				break; //������ �ѹ��̶� ���� �̻� �� ���� �ʿ� ����
			}
		}
		//printf("%s\n", icase[i]);
		// 10������ ��ȯ
		list[listIndex++]=toDecimal(icase[i], time);
	}
	
	//���� �� k��° ū ���� ��ȯ
	sort(list, list + listIndex, greater<int>());

	return list[k - 1];
}
int main()
{
	int test;
	FILE *f;
	f = fopen("input.txt", "r");
	
	fscanf(f, "%d", &test);
	for (int i = 0; i < test; i++)
	{
		fscanf(f, "%d %d", &N, &k);
		fscanf(f, "%s", input);
		printf("#%d %d\n", i, pwd());
	}

	return 0;
}