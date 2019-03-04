//#include<stdio.h>
//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<string>
//
////노드와 연결된 곳을 depth기준으로 찾는 것이 dfs이다.
////상하좌우의 노드를 보고 연결되어 있으면 각 노드와 연결 된 곳을 
////보는 것이다.
////이렇게 하면 노드가 n*n으로 여러개가 되어 있어서 접근할때 편하다
////리스트의 경우 visited상태가 3개여야 할 듯
////상하좌우를 봐서 구간을 나눠야 하는 문제의 경우 행렬을 사용하면 쉽고편하게 풀림
////그 외에 연결된 노드를 하나하나 다 따라가는 길을 찾는 것은 리스트가 더 빠름
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
//	//행렬이 쉽지만 이번에는 리스트로 풀어볼까?
//	//아니 너무 복잡함 그냥 행렬로 푸는게 나을듯
//
//	cin >> n;
//
//	//리스트 생성
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
//	//소팅 후 출력
//	cout << total << endl;
//	sort(bsize.begin(), bsize.end());
//	for (int i = 0; i < bsize.size(); i++)
//		printf("%d\n", bsize[i]);
//	return 0;
//}