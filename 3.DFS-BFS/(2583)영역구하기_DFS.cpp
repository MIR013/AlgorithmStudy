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
//int total = 0; //전체 공간의 수
//int blocksize = 0; //각 공간의 사이즈를 임시 저장
//vector<int> bsize; //각 공간의 사이즈
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
//		//노드값이 0 인 곳만 들어갈 것임
//		//거기의 크기를 재야하기 때문에
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
//	//인접행렬 만들기
//	//좌표를 받아서 이것을 칸 단위의 행렬로 바꿀 것
//	for (int i = 0; i < K; i++)
//	{
//		int x1, x2, y1, y2;
//		cin >> x1 >> y1 >> x2 >> y2;
//		makeGraph(x1, y1, x2, y2);
//	}
//
//	//그래프도 바꿔줘야 할듯 (0,0)이 왼쪽 아래에서 시작하니까
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
//	//영역구하기
//	//상,하,좌,우로 이동해가면서
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
//	//소팅 후 출력
//	cout << total << endl;
//	sort(bsize.begin(), bsize.end());
//	for (int i = 0; i < bsize.size(); i++)
//		printf("%d ", bsize[i]);
//	printf("\n");
//
//	return 0;
//}