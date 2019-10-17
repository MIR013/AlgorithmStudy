#include<stdio.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string.h>

using namespace std;

int N, L, R;
int A[101][101];
bool isMove = false; //인구이동 했는지...?
int dirx[4] = { -1,0,1,0 };
int diry[4] = { 0,1,0,-1 };


void printAll(int arr[][101])
{
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			printf("%3d ", arr[i][j]);
		}
		printf("\n");
	}
	printf("======================\n");
	return;
}
void movePeople(int r,int c, int visited[][101])//인구이동
{
	//이거 영역 만드는거 자체를 bfs로 하고 상하좌우 다 보자
	queue<pair<int, int> > queue;
	vector<pair<int, int> > stack;//이거 값 변경할때 사용할 것
	int sum = 0;

	queue.push(make_pair(r, c));
	stack.push_back(make_pair(r, c));
	visited[r][c] = 1;
	sum = A[r][c];

	while (!queue.empty()) 
	{
		int nowx = queue.front().first;
		int nowy = queue.front().second;
		queue.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nextx = nowx + dirx[dir];
			int nexty = nowy + diry[dir];
			if (nextx <= 0 || nextx > N || nexty <= 0 || nexty > N) continue; //경계이상
			if (visited[nextx][nexty]) continue; //이미 방문한 곳
			//국경을 열 수 있다면 처리
			int diff = abs(A[nowx][nowy] - A[nextx][nexty]);
			if (diff >= L && diff <= R) {
				visited[nextx][nexty] = 1;
				stack.push_back(make_pair(nextx, nexty));
				queue.push(make_pair(nextx, nexty));
				sum += A[nextx][nexty];
			}
		}

	}
	//인구이동
	if (stack.size() > 1)
	{
		int average = int(sum / stack.size());
		vector<pair<int, int> >::iterator iter;
		for (iter = stack.begin(); iter != stack.end(); iter++) {
			A[iter->first][iter->second] = average;
		}
		isMove = true;
	}


	return;
}
int main()
{
	/*
	N: 땅의크기
	A: 인구수

	*/
	//변수
	int visited[101][101] = { 0 };
	int result = -1;//인구이동 발생 횟수 - 처음은 반드시 돌기 때문에 -1

	//입력
	cin >> N >> L >> R;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
		}
	}
	do {
		//인구이동 - bfs
		//printAll(A);

		//초기화
		isMove = false;
		memset(visited, 0, sizeof(visited));

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (!visited[i][j])
					movePeople(i, j, visited);
			}
		}
		result++;
	} while (isMove);

	//출력
	cout << result << endl;

	return 0;
}