#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int N, M;//ũ��, ���̷��� ����
int input[51][51];
int dirx[4] = { -1,0,1,0 };//��,��,��,��
int diry[4] = { 0,1,0,-1 };

void printAll(int map[][51])
{
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			printf("%2d ", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	return;
}
int checkMap(int map[][51])
{
	int max_val = -1;
	//���� �����µ� �ɸ��� �ð�(�ִ� ��)
	//�ȵǸ� -1
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (input[i][j] == 2) {
				continue;
			}
			int temp = map[i][j];
			if (temp == -3) {
				return -1;
			}
			if (temp > max_val) {
				max_val = map[i][j];
			}
		}
	}
	return max_val;
}
int spreadVirus(vector<pair<int, int> > cases)
{
	queue<pair<int, int> > nextV;//���̷��� ��ġ�� ������ ��!
	int map[51][51];
	int visited[51][51] = { 0 }; //�湮 ���θ� Ȯ������!
	int max_val = -1;
	//bfs�� �̿��Ͽ� ���̷����� �۶߸���!!!!!

	//�ʱ�ȭ
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			map[i][j] = input[i][j];
		}
	}
	for (int i = 0; i < cases.size(); i++) {
		nextV.push(cases[i]);
		map[cases[i].first][cases[i].second] = 0;
		visited[cases[i].first][cases[i].second] = 1;
	}

	//queue
	while (!nextV.empty()) {
		pair<int, int> nextPos = nextV.front();

		//4���� - ������, ���� �ʰ��ϴ��� Ȯ��, ��Ȱ�� ���̷����� �� �ʿ� ����.
		for (int dir = 0; dir < 4; dir++)
		{
			int nextx = nextPos.first + dirx[dir];
			int nexty = nextPos.second + diry[dir];

			//���ʰ�
			if (nextx <= 0 || nextx > N || nexty <= 0 || nexty > N)
				continue;
			//��
			if (map[nextx][nexty] == -1)
				continue;

			if (!visited[nextx][nexty]) {
				//�����ϱ�!
				map[nextx][nexty] = map[nextPos.first][nextPos.second] + 1;

				//�߰�
				nextV.push(make_pair(nextx, nexty));
				visited[nextx][nexty] = 1;
			}

		}

		nextV.pop();
	}

	int result = checkMap(map);
	//printAll(map);
	//printf("=====================\n");

	return result;
}
int main()
{
	/*
		//�ð� �ſ� ª�� - �˰���
		0: ��ĭ 1:�� 2:���̷��� ���� �� �ִ� ��ġ
		���̷��� ���� �� �z�� �ִ� ����� �� 10Cm -> 10��
		=> permutation�̿� + bfs!!

		���̷��� ���� -> ���̷��� �۶߸� �� �ִ� �ð� ��� -> �ּ� ��

		permutation: ��ġ 5�� �� ���̷��� 3��
		123,124,125,234,235,345 �䷸�� -> �ߺ� ������ ����!
		������ 0��1�� �ִ� �迭�� �̿��� ������ ����� �ָ� �ȴ�!

		���Ǹ� ���� ���̷����� -2, ���� -1, ��ĭ�� -3���� ǥ���Ѵ�.

	*/
	int time = 0, vNum = 0;//�ð�, �� ���̷��� ����
	int min_val = 999999999;//�ּҰ�
	bool min_true = false;//�ּҸ� ���� �� �ִ°�?
	vector<int> perm;
	vector<pair<int, int> > cases; //���̷��� ���� ����� ���� ��ġ

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> input[i][j];
			if (input[i][j] == 2) {
				cases.push_back(make_pair(i, j));
				vNum++;
				input[i][j] = -2;
			}
			else if (input[i][j] == 1) {
				input[i][j] = -1;
			}
			else {
				input[i][j] = -3;
			}
		}
	}
	//permutation���� ���� �����ϱ�
	//�� ���� �� �ʱ�ȭ
	for (int i = 0; i < M; i++)
		perm.push_back(1);
	for (int i = M; i < vNum; i++)
		perm.push_back(0);
	sort(perm.begin(), perm.end());//���ϸ� 11100�̶� �����ϴ�! - ���� �� �������

	do {
		vector<pair<int, int> > nextCase;
		for (int i = 0; i < vNum; i++) {
			if (perm[i] == 1) {
				nextCase.push_back(make_pair(cases[i].first, cases[i].second));
			}
		}
		int result = spreadVirus(nextCase);

		if (result < min_val && result != -1) {
			min_val = result;
			min_true = true;
		}

	} while (next_permutation(perm.begin(), perm.end()));

	if (min_true) {
		cout << min_val << endl;
	}
	else {
		cout << -1 << endl;
	}

	return 0;
}