#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int map[101][101];
int visited[101][101] = { 0, }; //�湮 ���� ����
int N, M;
priority_queue<pair<int, pair<int, int> > > brick; // �� ���� ��(����,-������), ��ǥ(����)
int dirx[4] = { 0,1,0,-1 }; //��,��,��,��
int diry[4] = { 1,0,-1,0 };


void BFS()
{
	brick.push(make_pair(0, make_pair(1, 1))); //���� ó�� ����
	visited[1][1] = 1;

	while (!brick.empty())
	{
		pair<int, pair<int, int> > next; //�������� �̵��� ��
		next = brick.top();
		brick.pop();

		//n,m�� ���� �� ��� ���� ��
		if ((next.second.first) == N && (next.second.second) == M)
		{
			cout << (-next.first) << endl; //�׶��� �ּ� ������ ������ ���
			break;
		}

		//��,��,��,�� �̵�
		for (int dir = 0; dir < 4; dir++)
		{
			pair<int, pair<int, int> > newone;
			//��ǥ �����Ҷ�, -�� �ؾ��Ѵ�.
			int nextx = (next.second.first) + dirx[dir];
			int nexty = (next.second.second) + diry[dir];

			//�׵θ� üũ
			if (nextx <= 0 || nextx > N || nexty <= 0 || nexty > M)
				continue;

			//�湮 �� �� ������ �̵� �� �߰�
			if (!visited[nextx][nexty]) {
				//���� ���� ��� �������� �� �Ϳ� ++
				if (map[nextx][nexty] == 1)
				{
					newone.first = next.first - 1;
				}
				//���� ���� ��� �׳� �߰�
				else {
					newone.first = next.first;
				}
				newone.second.first = nextx;
				newone.second.second = nexty;

				brick.push(newone);
				visited[nextx][nexty] = 1;//���� �湮�ߴ�.
			}
		}
	}



	return;
}
int main()
{
	char input[101];

	cin >> M >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> input;
		for (int j = 1; j <= M; j++)
		{
			map[i][j] = input[j - 1] - '0';
		}
	}


	BFS();

	return 0;
}