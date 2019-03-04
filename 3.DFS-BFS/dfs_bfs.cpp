//#include<iostream>
//#include<stdio.h>
//#include<vector>
//#include<queue>
//#include<algorithm>
//
//using namespace std;
////�� ���� ���� num�� ������ ������. weight�� ������ �� ����
////�� �߰��� ��� createNode,    �� ����� �ٲ� ��!
//vector<vector<int> > adj; //i=0�� ���� ���� ���� 1���� ä�� ���� ��
//				 //i�� Ȧ���϶��� num, ¦���ϴ�� weight -> ������ �׳� ���� ��ϵ�
//
//typedef enum { WHITE, GRAY, BLACK } col; //��� �湮 ���θ� üũ�ϴ� ��
//// �湮x: WHITE, �湮�� ������ ���� �ƴҶ�: GRAY, ���϶�: BLACK
//vector<col> color; //�� ��尡 �ϳ��� ������.
//vector<int> parent;//�� ����� �θ� ��带 ����
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
//	//�� ���� ����� ��� ��带 Ȯ���Ѵ�.
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
//	//�� ������ ���� �� ��
//	color[u] = BLACK;
//	return;
//}
//void DFS(int vertex, int start)
//{
//	//�ʱ�ȭ
//	for (int i = 1; i <= vertex; i++)
//	{
//		color.push_back(WHITE);
//		parent.push_back(-1);
//	}
//	//dfs visit
///*
//	//��� ��带 ���� ��
//	for (int u = 1; u <= vertex; u++)
//	{
//		if (color[u] == WHITE)
//			DFS_visit(u);
//	}
//*/
////�������� start���� �����ؼ� ã�� ���� 
//	DFS_visit(start);
//}
//
//void BFS(int vertex,int start)
//{
//	//�ʱ�ȭ
//	for (int u = 1; u <= vertex; u++)
//	{
//		color[u] = WHITE;
//		parent[u] = -1;
//	}
//	color[start] = GRAY; parent[start] = -1;
//	bfsQueue.push(start);
//	//ť���� �ϳ��� ���鼭 üũ
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
//		//������ �� �Դ�.
//		color[u] = BLACK;
//	}
//
//	return;
//}
//int main()
//{
//	//����� �Դϴ�!
//	int N, M, V;
//	int from, to;
//	cin >> N >> M >> V;
//
//	adj.resize(N + 1);
//	color.resize(N + 1);
//	parent.resize(N + 1);
//	//index�� 0 �ΰ����� �ȳ��� ����
//	for (int i = 1; i <= N; i++)
//		adj[i].push_back(0);
//
//	//index 1���� ��
//	for (int i = 1; i <= M; i++)
//	{
//		cin >> from >> to;
//
//		//node�� �� ���� �����ϴ��� Ȯ���Ѵ�
//		if (find(adj[from].begin(), adj[from].end(), to) == adj[from].end())//find�� ���� ���ٸ� �� ������ ���� �ּҸ� ��ȯ
//		{
//			//insertNode
//			adj[from].push_back(to);
//			//�����
//			adj[to].push_back(from); //��� ���� ���� ���� �ִ��� ��ã�� �൵ ��
//
//		}
//	}
//
//	//��������Ʈ ���� ���� - ���� ������ ���� �Ѵ�.
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