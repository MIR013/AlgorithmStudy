#include<iostream>
using namespace std;

int N, M;
//0:북, 1:동, 2:남, 3:서
int dirx[4] = { 0,-1,0,1 };//각 방향의 왼쪽 표시
int diry[4] = { -1,0,1,0 }; //서,북,동,남
int map[51][51];
int clean[51][51] = { 0 };
int totalClean = 0;

void vaccum(int r, int c, int d)
{
	/*
		현재방향을 기준으로 왼쪽
		돌아가는 거 보니 재귀를 써야할 것 같은데
		종료조건은 내부에 있는 재귀..
	*/
	bool isRun = true;
	while (isRun) {
		//printf("(%d %d-%d)\n", r, c,d);
		//진행조건 - 4방향 탐지
		if (!clean[r][c] && !map[r][c]) {//현재 위치를 청소할 수 있을 경우->후진했을때는 청소하면 안됨
			clean[r][c] = 1;
			totalClean++;
		}
		int index = 0;
		do {
			//현재에서 왼쪽
			int nextx = r + dirx[d]; int nexty = c + diry[d];

			if (clean[nextx][nexty] == 0 && map[nextx][nexty] == 0) {
				//왼쪽에 청소x + 벽이 아닐 경우
				r = nextx; c = nexty; d = (d + 3) % 4;//그 방향으로 회전 및 전진
				break;
			}
			else if (clean[nextx][nexty] == 1 || map[nextx][nexty] == 1 || nextx < 0 || nextx >= N || nexty < 0 || nexty >= M) {
				//청소할 공간이 없다 or 벽일 경우 or 테두리일 경우
				d = (d + 3) % 4;//방향만 회전하고 계속

				//네 방향 모두 안 될 경우
				if (index == 3) {
					//후진 - 이건 왼쪽과 다름!!
					r = r + dirx[(d + 3) % 4];
					c = c + diry[(d + 3) % 4];
					//후진이 불가능한 경우- 테두리 or 벽 로봇 멈춤
					if (r < 0 || r >= N || c < 0 || c >= M || map[r][c] == 1) {
						isRun = false;
						break;
					}
					//후진이 가능한 경우
					else {
						index = 0;//2번으로 돌아간다.
						continue;
					}
				}
			}


			index++;
		} while (index < 4);
	}


	return;
}
int main()
{
	int r, c, d;//로봇의 상태

	cin >> N >> M;
	cin >> r >> c >> d;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];

	vaccum(r, c, d);
	cout << totalClean << endl;
	return 0;
}