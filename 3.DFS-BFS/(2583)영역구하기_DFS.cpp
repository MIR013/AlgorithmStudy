//#include<stdio.h>
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int dirx[4] = { 0,0,1,-1 };
//int diry[4] = { 1,-1,0,0 };
//
//int adj[101][101] = { 0 };
//int visited[101][101] = { 0 };
//int total = 0; //��ü ������ ��
//int blocksize = 0; //�� ������ ����� �ӽ� ����
//vector<int> bsize; //�� ������ ������
//int N, M, K;
//
//void dfs(int x, int y)
//{
//	visited[x][y] = 1;
//	blocksize++;
//
//	for (int i = 0; i < 4; i++)
//	{
//		int nextx = x + dirx[i];
//		int nexty = y + diry[i];
//
//		//��尪�� 0 �� ���� �� ����
//		//�ű��� ũ�⸦ ����ϱ� ������
//		if ((nextx >= 0) && (nextx < N) && (nexty >= 0) && (nexty < M)) {
//			if (!visited[nextx][nexty] && !adj[nextx][nexty])
//			{
//				dfs(nextx, nexty);
//			}
//		}
//	}
//	return;
//}
//void makeGraph(int x1, int y1, int x2, int y2)
//{
//	//7 5
//	// 0 2 4 4 
//
//	for (int i = x1; i < x2; i++)
//	{
//		for (int j = y1; j < y2; j++)
//		{
//			adj[i][j] = 1;
//		}
//	}
//	return;
//}
//int main()
//{
//	cin >> M >> N >> K;
//
//	//������� �����
//	//��ǥ�� �޾Ƽ� �̰��� ĭ ������ ��ķ� �ٲ� ��
//	for (int i = 0; i < K; i++)
//	{
//		int x1, x2, y1, y2;
//		cin >> x1 >> y1 >> x2 >> y2;
//		makeGraph(x1, y1, x2, y2);
//	}
//
//	//�׷����� �ٲ���� �ҵ� (0,0)�� ���� �Ʒ����� �����ϴϱ�
//	/*
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < M; j++)
//		{
//			printf("%d ", adj[i][j]);
//		}
//		printf("\n");
//	}
//	*/
//	//�������ϱ�
//	//��,��,��,��� �̵��ذ��鼭
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < M; j++)
//		{
//			if ((!visited[i][j]) && (!adj[i][j])) {
//				dfs(i, j);
//				total++;
//				bsize.push_back(blocksize);
//				blocksize = 0;
//			}
//		}
//	}
//
//	//���� �� ���
//	cout << total << endl;
//	sort(bsize.begin(), bsize.end());
//	for (int i = 0; i < bsize.size(); i++)
//		printf("%d ", bsize[i]);
//	printf("\n");
//
//	return 0;
//}