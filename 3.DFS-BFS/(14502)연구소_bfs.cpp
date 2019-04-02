#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int N, M;
int map[9][9];//(1,1)부터 저장
vector<pair<int, int> > virus; //바이러스들은 vector에 넣어두고 살핀다.
vector<pair<int, int> >wall;//벽을 칠 수 있는 곳 
vector<int> stack;//크기는 3으로 고정!! -> wall의 index를 계산한다.
int maxSafe = -1;
int dirx[4] = { 0,1,0,-1 }; //우하좌상
int diry[4] = { 1,0,-1,0 };

/*
void print(int table[][9])
{
	int safe = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			printf("%2d", table[i][j]);
		}
		printf("\n");
	}
	return;
}
*/
int checkSafe(int table[][9])
{
	int safe = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (!table[i][j]) {
				safe++;
			}
		}
	}
	return safe;
}
void spread(int r, int c, int table[][9], int visited[][9])//BFS
{
	queue<pair<int, int> > bfs;
	bfs.push(make_pair(r, c));
	visited[r][c] = 1;

	while (!bfs.empty())
	{
		pair<int, int> nextone = bfs.front();
		bfs.pop();

		//우,하,좌,상 확인 - 방문안하고 0인 곳에 퍼진다!!
		for (int dir = 0; dir < 4; dir++) {
			int nextx = nextone.first + dirx[dir];
			int nexty = nextone.second + diry[dir];
			//테두리 검사
			if (nextx <= 0 || nextx > N || nexty <= 0 || nexty > M)
				continue;
			if (table[nextx][nexty] == 0 && visited[nextx][nexty]==0) {
				//퍼질 수 있는 곳
				bfs.push(make_pair(nextx, nexty));
				visited[nextx][nexty] = 1;
				table[nextx][nexty] = 2;
			}
		}
	}

	return;
}
void lab(int index)
{
	//종료조건
	if(stack.size()==3)
	{
		/*
		for (int i = 0; i < stack.size(); i++)
		{
			printf("%d ", stack[i]);
		}
		printf("\n");
		*/
		

		int temp[9][9]; int visited[9][9] = { 0 };
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				temp[i][j] = map[i][j];
			}
		}
		//벽을 세운다
		for (int i = 0; i < stack.size(); i++)
		{
			temp[wall[stack[i]].first][wall[stack[i]].second] = 1;
		}

		//바이러스를 퍼트린다
		for (int x = 0; x < virus.size(); x++) {
			spread(virus[x].first, virus[x].second, temp, visited);
		}
		/*
		if (stack[0] == 0 && stack[1] == 4 && stack[2] == 16)
			print(temp);
		*/
		//안전지대의 최대값을 구한다.
		int a = checkSafe(temp);
		if (maxSafe < a)
			maxSafe = a;
		

		stack.pop_back();
		return;
	}

	//진행조건
	for (int i = index+1; i < wall.size(); i++) {
		stack.push_back(i);
		lab(i);
	}

	stack.pop_back();
	return;
}
int main()
{
	/*
		바이러스가 퍼져나가는 것: BFS
		벽을 세우는 방법: 완전탐색 -> n이 작기때문이다!.
		경우의 수가 3으로 주어졌으니 for문 3개써도 됨 근데 그냥 재귀를 써도 좋고
		경우의 수의 경우 중복이 안되므로 순열은 아닌 것 같다.
		...
		-> 결과: 이거 여기서 오래걸려도 서버에선 빠르게 도네...
	*/
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2)
				virus.push_back(make_pair(i, j));//바이러스 등록
			else if (map[i][j]==0)
				wall.push_back(make_pair(i, j));//벽 등록
		}
	}

	for (int i = 0; i < wall.size(); i++) {
		stack.push_back(i);
		lab(i);
	}
	
	cout << maxSafe << endl;

	return 0;
}