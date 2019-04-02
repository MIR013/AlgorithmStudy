#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int map[101][101];
int visited[101][101] = { 0, }; //방문 여부 저장
int N, M;
priority_queue<pair<int, pair<int, int> > > brick; // 깬 벽돌 수(오름,-로저장), 좌표(내림)
int dirx[4] = { 0,1,0,-1 }; //우,하,상,좌
int diry[4] = { 1,0,-1,0 };


void BFS()
{
	brick.push(make_pair(0, make_pair(1, 1))); //가장 처음 대입
	visited[1][1] = 1;

	while (!brick.empty())
	{
		pair<int, pair<int, int> > next; //다음으로 이동할 곳
		next = brick.top();
		brick.pop();

		//n,m에 도착 할 경우 끝낼 것
		if ((next.second.first) == N && (next.second.second) == M)
		{
			cout << (-next.first) << endl; //그때의 최소 벽돌의 개수를 출력
			break;
		}

		//우,하,상,좌 이동
		for (int dir = 0; dir < 4; dir++)
		{
			pair<int, pair<int, int> > newone;
			//좌표 저장할때, -로 해야한다.
			int nextx = (next.second.first) + dirx[dir];
			int nexty = (next.second.second) + diry[dir];

			//테두리 체크
			if (nextx <= 0 || nextx > N || nexty <= 0 || nexty > M)
				continue;

			//방문 한 적 없으면 이동 후 추가
			if (!visited[nextx][nexty]) {
				//벽이 있을 경우 이제까지 온 것에 ++
				if (map[nextx][nexty] == 1)
				{
					newone.first = next.first - 1;
				}
				//벽이 없을 경우 그냥 추가
				else {
					newone.first = next.first;
				}
				newone.second.first = nextx;
				newone.second.second = nexty;

				brick.push(newone);
				visited[nextx][nexty] = 1;//여긴 방문했다.
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