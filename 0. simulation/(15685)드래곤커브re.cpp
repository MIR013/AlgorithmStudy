#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#define SIZE 101

using namespace std;

int map[SIZE][SIZE] = { 0 };
int dirx[4] = { 1,0,-1,0 };
int diry[4] = { 0,-1,0,1 };

void print(int size)
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			printf("%1d ", map[i][j]);
		}
		printf("\n");
	}
	printf("================\n");

	return;
}
int checkSquare()
{
	int result = 0;

	//1인 곳을 보고 사각형을 계산하자
	// i+1,j+1,i+1/j+1인 부분이 모두 1이면 사각현 하나 완성!
	// 칸수초과를 대비해 하나씩 줄여서 본다
	for (int i = 0; i < SIZE-1; i++) {
		for (int j = 0; j < SIZE-1; j++) {
			if (map[i][j] == 1) {
				if (map[i + 1][j] == 1 && map[i][j + 1] == 1 && map[i + 1][j + 1] == 1) {
					result++;
				}
			}
		}
	}

	return result;
}
void dragon(int x, int y, int dir, int g)
{

	//기준점
	int pointx = x + dirx[dir];
	int pointy = y + diry[dir];
	vector<pair<int, int> > dra;
	vector<int> direction;

	//커브가 된 곳을 1이라고 하자!
	map[y][x] = 1;
	map[pointy][pointx] = 1;
	direction.push_back(dir);
	dra.push_back(make_pair(x, y));
	dra.push_back(make_pair(pointx, pointy));
	//방향을 저장해 두고 있으면 나중에 그대로 옮기면 될거 같은데
	/*
	90도 회전하면
	위->왼, 왼->아래, 아래->오, 오->위
	(시작)->(point)이런 느낌임
	근데 이거 기준이 어디인지부터 확실히 할 것
	dra를 거꾸로 접근해야함!
	*/

	//print(10);

	while (g > 0) 
	{
		//기준점 기준으로 모든 값을 90도 시계
		int dsize = direction.size();
		int nextx = dra.back().first;
		int nexty = dra.back().second;

		for (int i = dsize-1; i >= 0; i--)
		{ 
			//기준점을 제외하고 연산
			//방향과 다음 엣지 추가!
			switch (direction[i])
			{
			case 0://오른 -> 위
				nextx += dirx[1];
				nexty += diry[1];
				direction.push_back(1);
				break;
			case 1://위 ->왼
				nextx += dirx[2];
				nexty += diry[2];
				direction.push_back(2);
				break;
			case 2://왼->아래
				nextx += dirx[3];
				nexty += diry[3];
				direction.push_back(3);
				break;
			case 3://아래->오
				nextx += dirx[0];
				nexty += diry[0];
				direction.push_back(0);
				break;
			}

			map[nexty][nextx] = 1;
			dra.push_back(make_pair(nextx, nexty));
		}

		//새 point를 지정해 줘야 한다.
		pointx = dra.back().first;
		pointy = dra.back().second;

		g--;
		//print(10);
	}


	return;
}
int main()
{
	/*
	x축이랑 y축 반대방향임
	//시작점, 시작방향, 세대
	끝점을 기준으로 시계방향으로 90도 회전
	100*100격자 + n개의 드래곤 커브

	커브 그리기 -> 사각형 계산하기

	*/

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		dragon(x, y, d, g);
	}

	cout << checkSquare() << endl;


	return 0;
}