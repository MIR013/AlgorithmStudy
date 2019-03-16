#include<iostream>
#include<stdlib.h>

using namespace std;

int dirx[4] = { -1,0,1,0 };
int diry[4] = { 0,1,0,-1 };
int N, W, H;
int minBrick = 987654321; //구슬을 다 던진 후 남은 벽돌의 개수
int wall[20][20]; //각 저장된 숫자는 주위에 영향을 주는 벽돌 수

void printWall()
{
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			printf("%d ", wall[i][j]);
		}
		printf("\n");
	}
	printf("-----------------------\n");
}
void drop()
{
	//벽돌 떨구기
	int newBrick[20]; int len = H - 1;
	for (int i = 0; i < W; i++)//col
	{
		for (int j = H - 1; j >= 0; j--) {//row
			if (wall[j][i] != 0) {
				newBrick[len] = wall[j][i];
				len--;
			}
		}
		//덮어쓰기
		for (int j = 0; j < H; j++) {
			if (j < len + 1)
				wall[j][i] = 0;
			else
				wall[j][i] = newBrick[j];
		}
		len = H - 1;
	}

	//printWall();
	return;
}
void breakBrick(int row, int col, int affect)
{
	//printf("(%d %d)\n", row, col);
	//printWall();
	wall[row][col] = 0;
	//상우하좌
	for (int dir = 0; dir < 4; dir++) {
		int nextx = row + dirx[dir];
		int nexty = col + diry[dir];
		for (int a = 1; a < affect; a++) {
			//테두리
			if (nextx<0 || nexty<0 || nextx>H || nexty>W)
				break;
			if (wall[nextx][nexty] >= 1)
			{
				int newaffect = wall[nextx][nexty];
				wall[nextx][nexty] = 0;
				breakBrick(nextx, nexty, newaffect);
			}
			wall[nextx][nexty] = 0;
			nextx += dirx[dir]; nexty += diry[dir];
		}
	}

	return;
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	int totalBrick = 0;

	freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int input[20][20]; // 엎기위해
		//input
		scanf("%d %d %d", &N, &W, &H);
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				scanf("%d", &input[i][j]);
				wall[i][j] = input[i][j];
				if (input[i][j] != 0)
					totalBrick++;
			}
		}
		//printf("original\n");
		//printWall();

		int Brick[4]; int ans[4];
		for (Brick[0] = 0; Brick[0] < W; Brick[0]++) {
			for (Brick[1] = 0; Brick[1] < W; Brick[1]++) {
				for (Brick[2] = 0; Brick[2] < W; Brick[2]++) {
					for (Brick[3] = 0; Brick[3] < W; Brick[3]++) {
						//init wall
						for (int i = 0; i < H; i++) {
							for (int j = 0; j < W; j++) {
								wall[i][j] = input[i][j];
							}
						}
						//brick wall
						for (int i = 0; i < N; i++) {
							//현재 위치 삭제
							int affect = 0; int row;
							for (row = 0; row < H; row++) {
								if (wall[row][Brick[i]] != 0) {
									affect = wall[row][Brick[i]];
									break;
								}
							}
							//printf(">>%d %d\n", row, Brick[i]);
							breakBrick(row, Brick[i], affect);
							//떨어트리기
							drop();
						}

						//최소값 비교

						//printf("(%d %d %d %d)\n", Brick[0], Brick[1], Brick[2], Brick[3]);
						int b = 0;
						for (int i = 0; i < H; i++) {
							for (int j = 0; j < W; j++) {
								if (wall[i][j] != 0)
									b++;
							}
						}
						if (minBrick > b) {
							for (int x = 0; x < N; x++)
								ans[x] = Brick[x];
							minBrick = b;
						}
						if (minBrick == 0) {
							break;
						}
						//printf(">>%d\n", b);
						//printWall();

						if (N < 4) break;
					}
					if (N < 3) break;
				}
				if (N < 2) break;
			}
		}

		//printf("%d %d %d %d\n", ans[0], ans[1], ans[2], ans[3]);
		printf("#%d %d\n", test_case, minBrick);
		minBrick = 987654321;
	}
	return 0;
}