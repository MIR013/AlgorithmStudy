//#include<stdio.h>
//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
////��ķ� �ϸ� ������ �ξ� ���� Ǯ���µ�;;
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
//	//i���� j���� ���� ���� �ִ��� �˻�
//	//�ڱ��ڽſ��� �ڱ��ڽ����� ���°� ������ 1�� �Ǿ�����±���;;
//	if ((i == j) && (turn!=1)) {
//		ans[start][j] = 1;
//		enddfs = 1;
//		return;
//	}
//	for (int a = 0; a < adj[i].size(); a++)
//	{
//		int next = adj[i][a];
//		if ((!visited[next]) && !enddfs) {
//			visited[next] = 1; //��� �� ó�������� �����ؼ� �� ó���� �湮�ߴٰ� �߸� �ȵ�
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
//	//�ʱ�ȭ 0���� ������
//	adj.resize(N);
//	visited.resize(N);
//	for (int i = 0; i < N; i++) {
//		visited.push_back(0);
//	}
//
//	//��������Ʈ ����
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
//			//����� ���� �����ϸ� dfs
//			dfs(i, i, j);
//			//visited �ʱ�ȭ
//			for (int k = 0; k < N; k++)
//				visited[k] = 0;
//		}
//	}
//
//	//���
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			printf("%d ", ans[i][j]);
//		}
//		printf("\n");
//	}
//
//	return 0;
//}