#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int N, M;//크기, 바이러스 개수
int input[51][51];
int dirx[4] = { -1,0,1,0 };//상,우,하,좌
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
	//전부 퍼지는데 걸리는 시간(최대 값)
	//안되면 -1
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
	queue<pair<int, int> > nextV;//바이러스 위치를 저장할 곳!
	int map[51][51];
	int visited[51][51] = { 0 }; //방문 여부를 확인하자!
	int max_val = -1;
	//bfs를 이용하여 바이러스를 퍼뜨리자!!!!!

	//초기화
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

		//4방향 - 벽인지, 맵을 초과하는지 확인, 비활성 바이러스는 갈 필요 읎다.
		for (int dir = 0; dir < 4; dir++)
		{
			int nextx = nextPos.first + dirx[dir];
			int nexty = nextPos.second + diry[dir];

			//맵초과
			if (nextx <= 0 || nextx > N || nexty <= 0 || nexty > N)
				continue;
			//벽
			if (map[nextx][nexty] == -1)
				continue;

			if (!visited[nextx][nexty]) {
				//증가하기!
				map[nextx][nexty] = map[nextPos.first][nextPos.second] + 1;

				//추가
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
		//시간 매우 짧음 - 알고리즘
		0: 빈칸 1:벽 2:바이러스 놓을 수 있는 위치
		바이러스 놓을 수 칬는 최대 경우의 수 10Cm -> 10번
		=> permutation이용 + bfs!!

		바이러스 놓기 -> 바이러스 퍼뜨릴 수 있는 시간 계산 -> 최소 비교

		permutation: 위치 5개 중 바이러스 3개
		123,124,125,234,235,345 요렇게 -> 중복 없으니 조합!
		조합은 0과1이 있는 배열을 이용해 순열을 만들어 주면 된다!

		편의를 위해 바이러스는 -2, 벽은 -1, 빈칸은 -3으로 표현한다.

	*/
	int time = 0, vNum = 0;//시간, 총 바이러스 개수
	int min_val = 999999999;//최소값
	bool min_true = false;//최소를 구할 수 있는가?
	vector<int> perm;
	vector<pair<int, int> > cases; //바이러스 놓을 경우의 수의 위치

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
	//permutation으로 조합 구현하기
	//을 위한 값 초기화
	for (int i = 0; i < M; i++)
		perm.push_back(1);
	for (int i = M; i < vNum; i++)
		perm.push_back(0);
	sort(perm.begin(), perm.end());//안하면 11100이라 끝납니당! - 여긴 꼭 해줘야함

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