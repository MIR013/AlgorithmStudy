#include<queue>
#include<algorithm>
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
//편리를 위한 전역 설정
int R, C;
int sheep=0, wolf=0;//전체 양과 늑대의 수
char map[251][251];
int visited[251][251] = { 0, };//전체 0으로 초기화
int dirx[4] = {0,1,0,-1};//우,하,좌,상
int diry[4] = {1,0,-1,0};

void findAreaByBFS(int row,int col)//시작 행,열
{
	int s = 0, w = 0; //양과 늑대의 수
	queue<pair<int, int> > queue;
	queue.push(make_pair(row, col));
	visited[row][col] = 1;

	while (!queue.empty())
	{
		int x = queue.front().first;
		int y = queue.front().second;

		//상,하,좌,우 보면서 양의 수와 늑대의 수를 센다.
		for (int dir = 0; dir < 4; dir++) {
			int nextx = x + dirx[dir];
			int nexty = y + diry[dir];
			//테두리 벗어나는지 확인
			if (nextx < 0 || nextx >= R || nexty < 0 || nexty >= C)
				continue;

			char kinds = map[nextx][nexty];
			//#면 못감 - .o,v면 갈수 있음 + 방문한 적 없어야 간다.
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

	//큐 다돌았으면 한 영역을 다 돈 것이다.
	//양과 늑대 비교
	if (s <= w) {//늑대 승리
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
		양이든 늑대든 숫자 많은 놈이 이긴다.
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