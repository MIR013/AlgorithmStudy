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
////�������
//int dirx[4] = { 0,1,0,-1 };
//int diry[4] = { -1,0,1,0 };
//
//int N, M;
//int adj[100][100] = { 0 };
//int visited[100][100] = { 0 };
//
//
////q�� �ְ� �װ� ��� ������ ���� node�� �̵��� ��
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
//		//��������
//		if ((now.x == (N - 1)) && (now.y == (M - 1))) {
//			break;
//		}
//			
//		//4���� �˻� �ؼ� �Ǵ¾ֵ� �� q�� ��������
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
//					//�� ��尡 �ڱ⿡�� ���µ� �ɸ��� ���� �����ϰ� ����!!!
//					adj[next.x][next.y] = adj[now.x][now.y] + 1;
//					q.push(next);
//				}
//			}
//		}
//		//�� ���� �ѱ����� ���� ��� route--�ϰ� ����
//	}
//	return;
//}
//int main()
//{
//	cin >> N >> M;
//
//	//�Է¹ޱ�
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
//	//���
//
//	cout << adj[N-1][M-1] << endl;
//
//	return 0;
//}