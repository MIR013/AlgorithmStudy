#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

//적당한 길이의 n인 이차원배열은 배열로 선언하기
int map[51][51]; //미세먼지 맵
int R, C, time;//행,열,남은시간
pair<int, int> machine[2];//공기청정기의 위치 [위,아래]
int dirx[4] = {-1,0,1,0};//상,우,하,좌
int diry[4] = {0,1,0,-1};

void printAll()
{
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			printf("%3d ", map[i][j]);
		}
		printf("\n");
	}

	return;
}
void upside()
{
	/*
		공기청정기 위쪽 방향	
		반시계니까 시계방향으로 접근
		machine[0]
	*/
	int mx = machine[0].first;
	int my = machine[0].second;

	//아래
	for (int i = mx-2; i >= 0; i--) {
		map[i+1][0] = map[i][0];
	}
	//왼쪽
	for (int i = 1; i <= C-1; i++) {
		map[0][i - 1] = map[0][i];
	}
	//위
	for (int i = 1; i <= mx; i++) {
		map[i - 1][C-1] = map[i][C - 1];
	}
	//오른쪽
	for (int i = C-2; i > 0; i--) {
		map[mx][i + 1] = map[mx][i];
	}
	map[mx][1] = 0;//공기청정기에서 나온 것

	return;
}
void downside()
{
	/*
		공기청정기 아래쪽 방향
		시계
		machine[1]
	*/

	int mx = machine[1].first;
	int my = machine[1].second;


	//위
	for (int i = mx+2; i < R; i++) {
		map[i - 1][0] = map[i][0];
	}
	//왼쪽
	for (int i = 1; i < C; i++) {
		map[R-1][i - 1] = map[R-1][i];
	}
	//아래
	for (int i = R - 2; i >= mx; i--) {
		map[i + 1][C-1] = map[i][C-1];
	}
	//오른쪽
	for (int i = C - 2; i > 0; i--) {
		map[mx][i + 1] = map[mx][i];
	}
	map[mx][1] = 0;//공기청정기에서 나온 것


	return;
}
void diffusion()
{
	/*
	map의 모든 미세먼지가 확산된다.
	단, 테두리를 벗아날 경우, 공기청정기에 붙는 경우는 늘어나지 않음
	요거 인접한 미세먼지의 경우 중첩되기 때문에 배열하나만 쓰면 지옥감
	swap해서 처리해 주자
	*/
	int temp[51][51] = { 0 };

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] == -1) {
				temp[i][j] = -1;
				continue;
			}
			if (map[i][j]) {
				int num = 0; // 확산한 개수
				int diff = int(map[i][j] / 5); //확산량
				//상하좌우 본다
				for (int dir = 0; dir < 4; dir++) {
					int nextx = i + dirx[dir];
					int nexty = j + diry[dir];

					//테두리 확인
					if (nextx < 0 || nextx >= R || nexty < 0 || nexty >= C)
						continue;
					//공기청정기인지 확인
					if (map[nextx][nexty] == -1)
						continue;
					//둘다 아니면 확산
					num++;
					temp[nextx][nexty] += diff;
				}
				//현재 자리 감소
				temp[i][j] += map[i][j] - (diff*num);
			}
		}
	}

	swap(map,temp);

	return;
}
int main()
{
	/*
		시뮬레이션
		미세먼지 확산 후 공기청정기
		이거 시간좀..
	*/
	//입력
	int p = 0; //machine의 인덱스
	cin >> R >> C >> time;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1) {
				machine[p++] = make_pair(i, j);
			}
		}
	}


	//미세먼지 시작
	while (time > 0)
	{
		//미세먼지 확산
		diffusion();
		//공기청정기 가동
		upside();
		downside();
		time--;
	}

	//남은 미세먼지 출력
	int total = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] != -1) {
				total += map[i][j];
			}
		}
	}
	cout << total << endl;
	
	return 0;
}