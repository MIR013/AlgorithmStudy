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
		//중복이었던 값
		if (hex[0] == '\0')
			return -1;
		//제곱
		for (int j = 0; j < seat; j++) {
			mul *= 16;
		}
		if (hex[i]-'0' >= 10) {
			//문자일 경우
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
		//나올 수 있는 모든 경우를 찾는다
		//N/4 -1 회 반복
		for (int j = 0; j < N; j=j+time)
		{
			int k;
			for (k = 0;k<time; k++)
			{
				//한바퀴 도는 index 처리 %
				int next = (j + k + i) % N;
				icase[index][k] = input[next];
			}
			icase[index][k] = '\0';
			index++;
		}
	}

	// 중복된 값 제거
	int list[100];
	int listIndex = 0;
	for (int i = 0; i < index; i++)
	{
		for (int j = i+1; j < index; j++) {
			if (strcmp(icase[i],icase[j]) == 0) {
				icase[i][0] = '\0'; // 변환해도 0이 되게
				break; //같은게 한번이라도 나온 이상 더 비교할 필요 없음
			}
		}
		//printf("%s\n", icase[i]);
		// 10진수로 변환
		list[listIndex++]=toDecimal(icase[i], time);
	}
	
	//소팅 후 k번째 큰 값을 반환
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