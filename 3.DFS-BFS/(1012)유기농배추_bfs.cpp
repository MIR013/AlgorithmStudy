//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<queue>
//#include<stdio.h>
//#include<string.h>
//
//using namespace std;
//
////bfs�� ť�� �ϳ� �� �־ �޸� �ʰ��� �ߴ°� ����;;
////�̰� ���ַ��� ��... ����Ʈ�� ����� ������ ���� �� �𸣰��� �� dfs�� ����
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
////�湮�ؾ� �� ���� ť���ٰ� �־�д�.
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
//			//�����¿츦 ���� 1�̸� ����Ǵ� �ִٰ� �ϰ� �װ��� �湮!
//			point next;
//			next.x = now.x + dirx[i];
//			next.y = now.y + diry[i];
//
//			//���� Ȯ���� ����� ����üũ
//			if ((next.x >= 0) && (next.x < n) && (next.y >= 0) && (next.y < m)) {
//				//�� ��尡 1�̰� �װ��� �湮�� ���� ���� ���
//				if ((adj[next.x][next.y] == 1) && (!visited[next.x][next.y])) {
//					//�� ���� �̵�!
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
//					bfs(a, b);
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