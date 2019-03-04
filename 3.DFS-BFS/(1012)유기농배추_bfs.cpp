//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<queue>
//#include<stdio.h>
//#include<string.h>
//
//using namespace std;
//
////bfs가 큐가 하나 더 있어서 메모리 초과가 뜨는것 같음;;
////이걸 없애려면 음... 리스트로 만들면 좋은데 굳이 잘 모르겠음 걍 dfs를 쓰자
//
//typedef struct point
//{
//	int x;
//	int y;
//};
//
//int adj[51][51] = { 0 };
//int visited[51][51] = { 0 };
//queue<point> q;
//int dirx[4] = { 0,1,0,-1 };
//int diry[4] = { 1,0,-1,0 };
//
//int total = 0;
//int m, n, k;
////방문해야 할 곳을 큐에다가 넣어둔다.
//void bfs(int x, int y)
//{
//	point p;
//	p.x = x; p.y = y;
//	q.push(p);
//	while (!q.empty())
//	{
//		point now = q.front();
//		q.pop();
//		visited[now.x][now.y] = 1;
//		for (int i = 0; i < 4; i++)
//		{
//			//상하좌우를 보고 1이면 연결되더 있다고 하고 그곳을 방문!
//			point next;
//			next.x = now.x + dirx[i];
//			next.y = now.y + diry[i];
//
//			//다음 확인할 노드의 범위체크
//			if ((next.x >= 0) && (next.x < n) && (next.y >= 0) && (next.y < m)) {
//				//그 노드가 1이고 그곳에 방문한 적이 없을 경우
//				if ((adj[next.x][next.y] == 1) && (!visited[next.x][next.y])) {
//					//그 노드로 이동!
//					q.push(next);
//				}
//			}
//		}
//	}
//
//}
//int main()
//{
//	/*
//	인접그래프 만들어서 dfs/bfs로 길을 찾아가면서
//	중간에 끊기게 되면 그때 배추벌레의 수를 늘리면 된다
//	*/
//	int testcase;
//	cin >> testcase;
//
//	for (int i = 0; i < testcase; i++)
//	{
//		int row, col;
//		cin >> m >> n >> k;
//
//		//인접 행렬이 편할때도 있고 인접 배열이 편할때도 있다 아마
//		//이 문제에서는 행렬로 풀어야 편한듯
//		for (int j = 0; j < k; j++)
//		{
//			cin >> col >> row;
//			adj[row][col] = 1;
//		}
//
//		//인접행렬을 다 둘러보면서 들어가야 할 곳으르 결정
//		for (int a = 0; a < n; a++)
//		{
//			for (int b = 0; b < m; b++)
//			{
//				if ((adj[a][b] == 1) && (visited[a][b] == 0)) {
//					bfs(a, b);
//					total++; //여기는 타고 들어가서 방문된 노드들은 들어올 수 없다
//				}
//			}
//		}
//
//		printf("%d\n", total);
//		//초기화
//		total = 0;
//		memset(adj, 0, sizeof(adj));
//		memset(visited, 0, sizeof(visited));
//	}
//
//
//
//	return 0;
//}