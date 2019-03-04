//#include<iostream>
//#include<stdio.h>
//#include<vector>
//#include<queue>
//#include<algorithm>
//
//using namespace std;
////한 노드는 각각 num를 값으로 가진다. weight가 존재할 수 있음
////더 추가할 경우 createNode,    의 배수를 바꿀 것!
//vector<vector<int> > adj; //i=0은 값을 주지 말고 1부터 채워 넣을 것
//				 //i가 홀수일때는 num, 짝수일대는 weight -> 지금은 그냥 수만 등록됨
//
//typedef enum { WHITE, GRAY, BLACK } col; //노드 방문 여부를 체크하는 것
//// 방문x: WHITE, 방문은 했으나 끝이 아닐때: GRAY, 끝일때: BLACK
//vector<col> color; //각 노드가 하나씩 가진다.
//vector<int> parent;//각 노드의 부모 노드를 저장
//
//queue<int> bfsQueue;
//
//
//void printNode(int vertex)
//{
//	for (int i = 1; i <= vertex; i++)
//	{
//		printf("%d: ", i);
//		for (int j = 1; j < adj[i].size(); j++)
//			printf("( %d )", adj[i][j]);
//		printf("\n");
//	}
//}
//void DFS_visit(int u)
//{
//	color[u] = GRAY;
//	printf("%d ", u);
//	//그 노드와 연결된 모든 노드를 확인한다.
//	for (int i = 1; i < adj[u].size(); i++)
//	{
//		int next = adj[u][i];
//		if (color[next] == WHITE)
//		{
//			parent[next] = u;
//			DFS_visit(next);
//		}
//	}
//
//	//맨 마지막 노드로 온 것
//	color[u] = BLACK;
//	return;
//}
//void DFS(int vertex, int start)
//{
//	//초기화
//	for (int i = 1; i <= vertex; i++)
//	{
//		color.push_back(WHITE);
//		parent.push_back(-1);
//	}
//	//dfs visit
///*
//	//모든 노드를 보는 것
//	for (int u = 1; u <= vertex; u++)
//	{
//		if (color[u] == WHITE)
//			DFS_visit(u);
//	}
//*/
////문제에서 start에서 시작해서 찾는 것임 
//	DFS_visit(start);
//}
//
//void BFS(int vertex,int start)
//{
//	//초기화
//	for (int u = 1; u <= vertex; u++)
//	{
//		color[u] = WHITE;
//		parent[u] = -1;
//	}
//	color[start] = GRAY; parent[start] = -1;
//	bfsQueue.push(start);
//	//큐에서 하나씩 빼면서 체크
//	while (!bfsQueue.empty())
//	{
//		int u = bfsQueue.front();
//		bfsQueue.pop();
//		printf("%d ", u);
//		for (int v = 1; v < adj[u].size(); v++)
//		{
//			int next = adj[u][v];
//			if (color[next] == WHITE) {
//				color[next] = GRAY; parent[next] = u;
//				bfsQueue.push(next);
//			}
//		}
//
//		//끝까지 다 왔다.
//		color[u] = BLACK;
//	}
//
//	return;
//}
//int main()
//{
//	//양방향 입니다!
//	int N, M, V;
//	int from, to;
//	cin >> N >> M >> V;
//
//	adj.resize(N + 1);
//	color.resize(N + 1);
//	parent.resize(N + 1);
//	//index가 0 인곳에는 안넣을 것임
//	for (int i = 1; i <= N; i++)
//		adj[i].push_back(0);
//
//	//index 1부터 들어감
//	for (int i = 1; i <= M; i++)
//	{
//		cin >> from >> to;
//
//		//node에 그 값이 존재하는지 확인한다
//		if (find(adj[from].begin(), adj[from].end(), to) == adj[from].end())//find는 값이 없다면 맨 마지막 값의 주소를 반환
//		{
//			//insertNode
//			adj[from].push_back(to);
//			//양방향
//			adj[to].push_back(from); //얘는 굳이 같은 값이 있는지 안찾아 줘도 됨
//
//		}
//	}
//
//	//인접리스트 내부 정렬 - 작은 노드부터 들어가야 한다.
//	for (int i = 1; i <= N; i++)
//		sort(adj[i].begin(), adj[i].end());
//
//	//printNode(N);
//	DFS(N, V);	
//	printf("\n");
//	BFS(N,V);
//
//	return 0;
//}