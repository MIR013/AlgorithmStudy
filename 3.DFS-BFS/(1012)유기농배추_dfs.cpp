//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<queue>
//#include<stdio.h>
//#include<string.h>
//
////dfs,bfs���� ��带 Ÿ��Ÿ�� ���� �湮�� �Ѵٴ� �����̴� �� ������ �ٸ���!
////���ʿ� search�ϴ� ����̴ϱ�!!
//
////�̰� �� Ʋ�ȴ��� ���ذ� �Ȱ��� -> �Է��� �߸��޾Ҿ���;;;;
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
//		//�����¿츦 ���� 1�̸� ����Ǵ� �ִٰ� �ϰ� �װ��� �湮!
//		int nextx = x + dirx[i];
//		int nexty = y + diry[i];
//
//		//���� Ȯ���� ����� ����üũ
//		if ((nextx >= 0) && (nextx < n) && (nexty >= 0) && (nexty < m)) {
//			//�� ��尡 1�̰� �װ��� �湮�� ���� ���� ���
//			if ((adj[nextx][nexty] == 1) && (!visited[nextx][nexty])) {
//				//�� ���� �̵�!
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
//	�����׷��� ���� dfs/bfs�� ���� ã�ư��鼭
//	�߰��� ����� �Ǹ� �׶� ���߹����� ���� �ø��� �ȴ�
//	*/
//	int testcase;
//	cin >> testcase;
//
//	for (int i = 0; i < testcase; i++)
//	{
//		int row, col;
//		cin >> m >> n >> k;
//
//		//���� ����� ���Ҷ��� �ְ� ���� �迭�� ���Ҷ��� �ִ� �Ƹ�
//		//�� ���������� ��ķ� Ǯ��� ���ѵ�
//		for (int j = 0; j < k; j++)
//		{
//			cin >> col >> row;
//			adj[row][col] = 1;
//		}
//
//		//��������� �� �ѷ����鼭 ���� �� ������ ����
//		for (int a = 0; a < n; a++)
//		{
//			for (int b = 0; b < m; b++)
//			{
//				if ((adj[a][b] == 1) && (visited[a][b] == 0)) {
//					dfs(a, b);
//					total++; //����� Ÿ�� ���� �湮�� ������ ���� �� ����
//				}
//			}
//		}
//
//		printf("%d\n", total);
//		//�ʱ�ȭ
//		total = 0;
//		memset(adj, 0, sizeof(adj));
//		memset(visited, 0, sizeof(visited));
//	}
//
//
//
//	return 0;
//}