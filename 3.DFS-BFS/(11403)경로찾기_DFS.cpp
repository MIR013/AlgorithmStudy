//#include<stdio.h>
//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
////행렬로 하면 문제가 훨씬 쉽게 풀리는데;;
//
//int ans[101][101] = { 0 };
//vector<vector<int> > adj;
//vector<int> visited;
//int enddfs;
//int turn;
//
//void printNode(int vertex)
//{
//	for (int i = 0; i < vertex; i++)
//	{
//		printf("%d: ", i);
//		for (int j = 0; j < adj[i].size(); j++)
//			printf("( %d )", adj[i][j]);
//		printf("\n");
//	}
//}
//void dfs(int start, int i, int j)
//{
//	turn++;
//	//i에서 j까지 가는 길이 있는지 검사
//	//자기자신에서 자기자신으로 가는게 무조건 1이 되어버리는구만;;
//	if ((i == j) && (turn!=1)) {
//		ans[start][j] = 1;
//		enddfs = 1;
//		return;
//	}
//	for (int a = 0; a < adj[i].size(); a++)
//	{
//		int next = adj[i][a];
//		if ((!visited[next]) && !enddfs) {
//			visited[next] = 1; //얘는 맨 처음꺼까지 봐야해서 맨 처음이 방문했다고 뜨면 안됨
//			dfs(start, next, j);
//		}
//	}
//	return;
//}
//int main()
//{
//	int N;
//	cin >> N;
//
//	//초기화 0부터 쓸거임
//	adj.resize(N);
//	visited.resize(N);
//	for (int i = 0; i < N; i++) {
//		visited.push_back(0);
//	}
//
//	//인접리스트 생성
//	int num;
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			cin >> num;
//			if (num)
//				adj[i].push_back(j);
//		}
//	}
//	//printNode(N);
//	//dfs
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++)
//		{
//			enddfs = 0; turn = 0;
//			//연결된 노드로 존재하면 dfs
//			dfs(i, i, j);
//			//visited 초기화
//			for (int k = 0; k < N; k++)
//				visited[k] = 0;
//		}
//	}
//
//	//출력
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			printf("%d ", ans[i][j]);
//		}
//		printf("\n");
//	}
//
//	return 0;
//}