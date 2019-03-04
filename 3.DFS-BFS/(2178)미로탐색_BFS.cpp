//#include<stdio.h>
//#include<iostream>
//#include<vector>
//#include<queue>
//#include<algorithm>
//using namespace std;
//
//typedef struct dir {
//	int x;
//	int y;
//};
////상우하좌
//int dirx[4] = { 0,1,0,-1 };
//int diry[4] = { -1,0,1,0 };
//
//int N, M;
//int adj[100][100] = { 0 };
//int visited[100][100] = { 0 };
//
//
////q에 넣고 그걸 배는 과정에 따라 node의 이동이 됨
//void bfs(int x, int y)
//{
//	int turn;
//	queue<dir> q;
//	dir num;
//	num.x = x; num.y = y;
//	q.push(num);
//
//	while (!q.empty())
//	{
//		dir now = q.front();
//		q.pop();
//		visited[now.x][now.y] = 1;
//
//		
//		//종료조건
//		if ((now.x == (N - 1)) && (now.y == (M - 1))) {
//			break;
//		}
//			
//		//4방향 검색 해서 되는애들 다 q에 때려박음
//		for (int i = 0; i < 4; i++)
//		{
//			int nextx = now.x + dirx[i];
//			int nexty = now.y + diry[i];
//			if ((nextx >= 0) && (nextx < N) && (nexty >= 0) && (nexty < M))
//			{
//				if ((!visited[nextx][nexty]) && (adj[nextx][nexty]==1))
//				{
//					dir next;
//					next.x = nextx; next.y = nexty;
//					//각 노드가 자기에게 오는데 걸리는 수를 저장하고 있음!!!
//					adj[next.x][next.y] = adj[now.x][now.y] + 1;
//					q.push(next);
//				}
//			}
//		}
//		//갈 곳이 한군데도 없을 경우 route--하고 간다
//	}
//	return;
//}
//int main()
//{
//	cin >> N >> M;
//
//	//입력받기
//	for (int i = 0; i < N; i++)
//	{
//		char input[100];
//		scanf("%s", input);
//		for (int j = 0; j < M; j++)
//		{
//			int num = input[j] - '0';
//			adj[i][j] = num;
//		}
//	}
//	/*
//	//print adj
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < M; j++)
//			printf("%d ", adj[i][j]);
//		printf("\n");
//	}
//	*/
//	//bfs
//	bfs(0, 0);
//	//출력
//
//	cout << adj[N-1][M-1] << endl;
//
//	return 0;
//}