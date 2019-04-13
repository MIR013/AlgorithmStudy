#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;


char map[12][6];
int dirx[4] = { 0,-1,0,1 };//좌상우하
int diry[4] = { -1,0,1,0 };
int total = 0;

void drop()
{


	for (int i = 10; i >= 0; i--) { //i가 11일때는 볼 필요가 없지!
		for (int j = 5; j >= 0; j--) {
			//자기자신 밑 확인
			if (map[i][j] != '.' && map[i + 1][j] == '.')
			{
				for (int k = i + 1; k < 12; k++) {
					if (map[k][j] != '.') break; //밑에 알파벳 있으면 그만
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
		bfs로 확인 후 연속된 공가니 4이상이면 true아니면 false반환
	*/
	vector<pair<int, int> > del;//지움애들 저장
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
			//테두리 체크
			if (nextx < 0 || nextx >= 12 || nexty < 0 || nexty >= 6)
				continue;
			//방문지역 체크
			if (visited[nextx][nexty])
				continue;
			//해당지역이 나와 같은 색이면 넣고 아니면 무시
			if (color == map[nextx][nexty]) {
				q.push(make_pair(nextx, nexty));
				del.push_back(make_pair(nextx, nexty));
				visited[nextx][nexty] = 1;
			}

		}
	}

	//del의 개수 체크
	if (del.size() >= 4) {
		for (int i = 0; i < del.size(); i++)
			map[del[i].first][del[i].second] = '.';
		return true;
	}

	return false;
}
void puyopuyo()
{
	//각 색깔마다 연속된게 있는지 확인!
	//있으면 없애고 drop한후 다시 확인!
	//터질 수 있는 뿌요가 여러 그룹이 있다면 동시에 터져야 하고 여러 그룹이 터지더라도 한번의 연쇄가 추가된다.(주의!!!!) - ㅜㅜ
	bool isCan;
	do {
		isCan = false;
		int visited[12][6] = { 0, };
		for (int i = 11; i >= 0; i--) {
			for (int j = 5; j >= 0; j--) {
				if (map[i][j] != '.' && !visited[i][j] && bfs(visited, i, j)) { //방문가능한지 먼저 확인하고 bfs실행
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