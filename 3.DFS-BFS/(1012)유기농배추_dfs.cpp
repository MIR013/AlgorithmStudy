//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<queue>
//#include<stdio.h>
//#include<string.h>
//
////dfs,bfs란게 노드를 타고타고 들어가서 방문을 한다는 개념이다 그 순서만 다를뿐!
////애초에 search하는 방법이니까!!
//
////이게 왜 틀렸는지 이해가 안가네 -> 입력을 잘못받았었음;;;;
//
//using namespace std;
//
//int adj[51][51] = { 0 };
//int visited[51][51] = { 0 };
//
//int dirx[4] = { 0,1,0,-1 };
//int diry[4] = { 1,0,-1,0 };
//
//int total = 0;
//int m, n, k;
//
//void dfs(int x, int y)
//{
//	visited[x][y] = 1;
//	for (int i = 0; i < 4; i++)
//	{
//		//상하좌우를 보고 1이면 연결되더 있다고 하고 그곳을 방문!
//		int nextx = x + dirx[i];
//		int nexty = y + diry[i];
//
//		//다음 확인할 노드의 범위체크
//		if ((nextx >= 0) && (nextx < n) && (nexty >= 0) && (nexty < m)) {
//			//그 노드가 1이고 그곳에 방문한 적이 없을 경우
//			if ((adj[nextx][nexty] == 1) && (!visited[nextx][nexty])) {
//				//그 노드로 이동!
//				dfs(nextx, nexty);
//			}
//		}
//	}
//
//	return;
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
//					dfs(a, b);
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