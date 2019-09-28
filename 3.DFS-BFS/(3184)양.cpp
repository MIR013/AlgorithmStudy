#include<queue>
#include<algorithm>
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
//���� ���� ���� ����
int R, C;
int sheep=0, wolf=0;//��ü ��� ������ ��
char map[251][251];
int visited[251][251] = { 0, };//��ü 0���� �ʱ�ȭ
int dirx[4] = {0,1,0,-1};//��,��,��,��
int diry[4] = {1,0,-1,0};

void findAreaByBFS(int row,int col)//���� ��,��
{
	int s = 0, w = 0; //��� ������ ��
	queue<pair<int, int> > queue;
	queue.push(make_pair(row, col));
	visited[row][col] = 1;

	while (!queue.empty())
	{
		int x = queue.front().first;
		int y = queue.front().second;

		//��,��,��,�� ���鼭 ���� ���� ������ ���� ����.
		for (int dir = 0; dir < 4; dir++) {
			int nextx = x + dirx[dir];
			int nexty = y + diry[dir];
			//�׵θ� ������� Ȯ��
			if (nextx < 0 || nextx >= R || nexty < 0 || nexty >= C)
				continue;

			char kinds = map[nextx][nexty];
			//#�� ���� - .o,v�� ���� ���� + �湮�� �� ����� ����.
			if (!visited[nextx][nexty] && kinds != '#')
			{
				if (kinds == 'o')
					s++;
				else if (kinds == 'v')
					w++;

				visited[nextx][nexty] = 1;
				queue.push(make_pair(nextx, nexty));
			}

			
		}

		queue.pop();
	}

	//ť �ٵ������� �� ������ �� �� ���̴�.
	//��� ���� ��
	if (s <= w) {//���� �¸�
		sheep -= s;
	}
	else {
		wolf -= w;
	}

	return;
}
int main()
{
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'o')
				sheep++;
			else if (map[i][j] == 'v')
				wolf++;
		}
	}
	/*
		���̵� ����� ���� ���� ���� �̱��.
	*/
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (visited[i][j] == 0) {
				findAreaByBFS(i,j);
			}
		}
	}
	
	cout << sheep << " " << wolf << endl;

	return 0;
}