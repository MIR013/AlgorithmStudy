#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N, M;
int map[8][8];
vector<pair<int, pair<int, int> > > cctv; //cctv�� ���� �ִ� 8 ����, ��ǥ
int caseOfCctv[6] = { -1,4,2,4,4,1 };//�� cctv�� �����ϴ� ����� ��
int minSq = 987654321;//�簢���� �ּ� ũ��
vector<int> stack;//����� �� ��� stack�� index�� cctv�� �ε����̰� ���� ���� cctv�� �� ���� ����� ���� �����Ѵ�.
//�� cctv�� ����� �� ���� Ȯ���ؾ� �� ������ �����ؾ� �ϴ°�
typedef enum compass{UP=1,RIGHT,DOWN,LEFT};
//cctv��ȣ, ����� ��, ����
int caseDir[6][5][5] = { {0}, 
{{0},{0,UP,0,0,0},{0,RIGHT,0,0,0},{0,DOWN,0,0,0},{0,LEFT,0,0,0}},
{{0},{0,LEFT,RIGHT,0,0},{0,UP,DOWN,0,0},{0},{0}},
{{0},{0,UP,RIGHT,0,0},{0,RIGHT,DOWN,0,0},{0,DOWN,LEFT,0,0},{0,LEFT,UP,0,0}},
{{0},{0,LEFT,UP,RIGHT,0},{0,UP,RIGHT,DOWN,0},{0,RIGHT,DOWN,LEFT,0},{0,DOWN,LEFT,UP,0}},
{{0},{0,UP,RIGHT,DOWN,LEFT},{0},{0},{0}}};
int dirx[5] = {0,-1,0,1,0};
int diry[5] = {0,0,1,0,-1};


int checkSq(int table[][8])//�簢���� ���
{
	int count = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (table[i][j] == 0)
				count++;
	return count;
}
void detect(int(*temp)[8]) //cctv�� �����ϴ� ���� -1�� �����.
{
	//cctv�� stack�� ���� üũ�ϱ�
	for (int i = 0; i < cctv.size(); i++)
	{
		for (int dir = 1; dir < 5; dir++)
		{
			int ndir = caseDir[cctv[i].first][stack[i]][dir];
			if (ndir == 0)//�̸� �� Ȯ�� ���Ѵ�!
				continue;
			int nextx = cctv[i].second.first + dirx[ndir];
			int nexty = cctv[i].second.second + diry[ndir];
			while (nextx >= 0 && nextx < N && nexty >= 0 && nexty < M)//map�� 0-7
			{//�׵θ����� �������� ���� 
				if (temp[nextx][nexty] == 6) {
					break;
				}
				if (temp[nextx][nexty] == 0)
					temp[nextx][nexty] = -1;


				//1-5�� �׳� �Ѿ��.
				nextx += dirx[ndir]; nexty += diry[ndir];
			}

			
		}
	}

	return;
}
/*
	�� ����� ���� ���� ���� ������ �߿� � �����̶��
	����� �ϴ� ���;� �ϴ� ���� cctv�� ������ ������ �ִ� 
	������ �� �ȿ��� 1~�� cctv�� ����� �� ��ŭ ������ ������ �̸� ����� �� �ֵ��� �ؾ��Ѵ�.
*/
void makeC(int cindex)//���� ����� ��, cctv�� �ε���
{
	//��������
	if (stack.size()==cctv.size())
	{
		//�׸��� - ����� ������ �׸��� ��¥ ���� �ɸ��� ������
		int temp[8][8];
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				temp[i][j] = map[i][j];

		detect(temp);

		//print
		/*

		printf("---------------\n");
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < M; y++) {
				printf("%d ", temp[x][y]);
			}
			printf("\n");
		}
		*/
		//�ּҰ� ���
		int min = checkSq(temp);
		if (minSq > min)
			minSq = min;
		//0�̸� �� �ƿ� ���������???? -> �ð�����

		stack.pop_back();
		return;
	}

	//��������
	//����� ���� �� �Ǿ����� �ڱⲨ �߰��ϰ� �����ַ� �Ѿ��(������)
	
	for (int i = 1; i <= caseOfCctv[cctv[cindex].first]; i++) //���⼭�� �� cctv���� ����� ���� �ٸ��Ƿ�!!
	{
		stack.push_back(i);
		makeC(cindex+1);//���� cctv�� ����� ���� �־��ش�.
	}

	stack.pop_back();
	return;
}
void watch()
{
	//��ͻ���ϸ� �ɰŰ�����
	//cctv�� ���� ���
	if (!cctv.size()) {
		minSq=checkSq(map);

	}
	else {
		//cctv�� ���� ���
		for (int i = 1; i <= caseOfCctv[cctv[0].first]; i++)
		{
			stack.push_back(i);
			makeC(1);//���� cctv�� ����� ���� �־��ش�.
		}
	}

	return;
}
int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] > 0 && map[i][j] < 6) //cctv���
				cctv.push_back({ map[i][j],{ i,j } });
		}
	}

	watch();
	cout << minSq << endl;

	return 0;
}