//#include<stdio.h>
//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<string>
//
////���� ����� ���� depth�������� ã�� ���� dfs�̴�.
////�����¿��� ��带 ���� ����Ǿ� ������ �� ���� ���� �� ���� 
////���� ���̴�.
////�̷��� �ϸ� ��尡 n*n���� �������� �Ǿ� �־ �����Ҷ� ���ϴ�
////����Ʈ�� ��� visited���°� 3������ �� ��
////�����¿츦 ���� ������ ������ �ϴ� ������ ��� ����� ����ϸ� �������ϰ� Ǯ��
////�� �ܿ� ����� ��带 �ϳ��ϳ� �� ���󰡴� ���� ã�� ���� ����Ʈ�� �� ����
//
//using namespace std;
//int adj[25][25] = { 0 };
//int visited[25][25] = { 0 };
//
//int dirx[4] = { 0,0,1,-1 };
//int diry[4] = { 1,-1,0,0 };
//
//int n;
//int total = 0;
//int blocknum = 0;
//vector<int> bsize;
//
//void dfs(int x,int y)
//{
//	visited[x][y] = 1;
//	blocknum++;
//
//	for (int i = 0; i < 4; i++)
//	{
//		int nextx = x + dirx[i];
//		int nexty = y + diry[i];
//
//		if ((nextx >= 0) && (nextx < n) && (nexty >= 0) && (nexty < n))
//		{
//			if ((!visited[nextx][nexty]) && (adj[nextx][nexty]))
//			{
//				dfs(nextx, nexty);
//			}
//		}
//
//	}
//
//	return;
//}
//int main()
//{
//	//����� ������ �̹����� ����Ʈ�� Ǯ���?
//	//�ƴ� �ʹ� ������ �׳� ��ķ� Ǫ�°� ������
//
//	cin >> n;
//
//	//����Ʈ ����
//	for (int i = 0; i < n; i++)
//	{
//		char input[25];
//		scanf("%s", input);
//		for (int j = 0; j < n; j++)
//		{
//			int num = input[j]-'0';
//			adj[i][j] = num;
//		}
//	}
//
//	//dfs
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++) {
//			if ((!visited[i][j]) && (adj[i][j]))
//			{
//				dfs(i,j);
//				total++;
//				bsize.push_back(blocknum);
//				blocknum = 0;
//			}
//		}
//	}
//	//���� �� ���
//	cout << total << endl;
//	sort(bsize.begin(), bsize.end());
//	for (int i = 0; i < bsize.size(); i++)
//		printf("%d\n", bsize[i]);
//	return 0;
//}