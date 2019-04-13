#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;


char map[12][6];
int dirx[4] = { 0,-1,0,1 };//�»����
int diry[4] = { -1,0,1,0 };
int total = 0;

void drop()
{


	for (int i = 10; i >= 0; i--) { //i�� 11�϶��� �� �ʿ䰡 ����!
		for (int j = 5; j >= 0; j--) {
			//�ڱ��ڽ� �� Ȯ��
			if (map[i][j] != '.' && map[i + 1][j] == '.')
			{
				for (int k = i + 1; k < 12; k++) {
					if (map[k][j] != '.') break; //�ؿ� ���ĺ� ������ �׸�
					map[k][j] = map[k - 1][j];
					map[k - 1][j] = '.';
				}
			}
		}
	}


	return;
}
bool bfs(int visited[][6], int x, int y)
{
	/*
		bfs�� Ȯ�� �� ���ӵ� ������ 4�̻��̸� true�ƴϸ� false��ȯ
	*/
	vector<pair<int, int> > del;//����ֵ� ����
	queue<pair<int, int> > q;
	q.push(make_pair(x, y));
	del.push_back(make_pair(x, y));
	visited[x][y] = 1;
	char color = map[x][y];

	while (!q.empty())
	{
		int nowx = q.front().first;
		int nowy = q.front().second;
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nextx = nowx + dirx[dir];
			int nexty = nowy + diry[dir];
			//�׵θ� üũ
			if (nextx < 0 || nextx >= 12 || nexty < 0 || nexty >= 6)
				continue;
			//�湮���� üũ
			if (visited[nextx][nexty])
				continue;
			//�ش������� ���� ���� ���̸� �ְ� �ƴϸ� ����
			if (color == map[nextx][nexty]) {
				q.push(make_pair(nextx, nexty));
				del.push_back(make_pair(nextx, nexty));
				visited[nextx][nexty] = 1;
			}

		}
	}

	//del�� ���� üũ
	if (del.size() >= 4) {
		for (int i = 0; i < del.size(); i++)
			map[del[i].first][del[i].second] = '.';
		return true;
	}

	return false;
}
void puyopuyo()
{
	//�� ���򸶴� ���ӵȰ� �ִ��� Ȯ��!
	//������ ���ְ� drop���� �ٽ� Ȯ��!
	//���� �� �ִ� �ѿ䰡 ���� �׷��� �ִٸ� ���ÿ� ������ �ϰ� ���� �׷��� �������� �ѹ��� ���Ⱑ �߰��ȴ�.(����!!!!) - �̤�
	bool isCan;
	do {
		isCan = false;
		int visited[12][6] = { 0, };
		for (int i = 11; i >= 0; i--) {
			for (int j = 5; j >= 0; j--) {
				if (map[i][j] != '.' && !visited[i][j] && bfs(visited, i, j)) { //�湮�������� ���� Ȯ���ϰ� bfs����
					isCan = true;
				}
			}
		}
		if (isCan) {
			drop();
			total++;
		}
	} while (isCan);

	return;
}
int main()
{
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> map[i][j];
		}
	}
	puyopuyo();
	cout << total << endl;

	return 0;
}