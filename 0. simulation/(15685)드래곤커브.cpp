#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int map[101][101] = { 0, }; //격자 상태, 드래곤 커브의 점 저장 -> 문제와 x,y가 방향이 다름
int dirx[4] = { 1,0,-1,0 };
int diry[4] = { 0,-1,0,1 }; //★ 반시계로 바꾸고 이건 그래도


int calSquare()
{
	int sq = 0;

	for (int i = 0; i <= 100; i++)
	{
		for (int j = 0; j <= 100; j++)
		{
			if (map[i][j])//값이 1이면 체크 시작
			{
				//테두리 체크
				if ((j + 1) <= 100 && map[i][j + 1]) {//오른쪽
					if ((i + 1) <= 100 && map[i + 1][j + 1]) {//오른쪽 아래
						if (map[i + 1][j]) {//아래
							//다 있으면 사각형 완성
							sq++;
						}
					}
				}

			}

		}
	}

	return sq; //사각형의 수 반환
}
void drangonCurve(int x, int  y, int  dir, int  gen)
{
	vector<int> dragon;//방향을 저장할 것

	//0세대 구성
	int nextx, nexty;	//마지막 점 배정
	pair<int, int> flag = make_pair( x,y );//마지막 점 저장
	dragon.push_back(dir);
	nextx = x + dirx[dir]; nexty = y + diry[dir];
	//printf("(%d %d)\n", x, y);
	//printf("(%d %d)\n", nextx, nexty);
	map[x][y] = 1; map[nextx][nexty] = 1; // 점 저장

	//1~gen세대 구성
	for (int i = 1; i <= gen; i++)
	{
		int last = dragon.size();//즉, 점이 아니라 행이 저장이 된 것
		//시계방향 회전(벡터에 저장 + 좌표에 표시)
		for (int j = last - 1; j >= 0; j--) //마지막 것부터 회전해서 추가해야 한다.
		{
			int nextdir;
			//90도로 시계회전
			/*
			if (!dragon[j])
				nextdir = 3;
			else
				nextdir = (dragon[j] - 1);
				*/
			nextdir = (dragon[j] + 1) % 4; //★x와 y를 바꿨으므로 반시계
			nextx += dirx[nextdir]; nexty += diry[nextdir];

			//테두리 밖인지 체크!!! -> 안이어야 값 추가
			if (nextx < 0 || nextx >100 || nexty < 0 || nexty>100)
				continue;
			else {//테두리 안이니까 추가!
				dragon.push_back(nextdir);
				map[nextx][nexty] = 1;
				//printf("(%d %d)\n", nextx, nexty);
			}
		}
		//printf("\n");
	}


	return;
}
int main()
{
	int N;

	cin >> N;
	for (int time = 0; time < N; time++)
	{
		//input
		int x, y, dir, gen;
		cin >> x >> y >> dir >> gen;
		//드래곤 커브 구성
		drangonCurve(x, y, dir, gen);
	}

	//사각형의 수 계산
	cout << calSquare();

	return 0;
}