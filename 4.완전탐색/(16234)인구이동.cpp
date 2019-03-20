#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, R, L;
int map[51][51]; //인구수 저장!
//연합인 애들은 같은 넘버링으로 구성하자 -> 위에 있는애, 왼쪽에 있는애 기준
int united[51][51];
int moving; //전체 인구 이동 수
bool isMoving;

void printmap()
{
	printf("\nmap\n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	printf("\nunited\n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", united[i][j]);
		}
		printf("\n");
	}
	printf("----------------\n");
}
void virus(int x, int y)
{
	// x->y로 바꾼다. 값을 전파해 버리자 구냥..
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (united[i][j] == x)
				united[i][j] = y;
		}
	}
	return;
}
void move()
{
	do {
		isMoving = false;
		pair<int, int > newunited[3000] = { {0,0}, }; // 연합왕국의 새 인구 부여를 위한 배열 (다 더한 인구수,나라 개수)
		//인구이동 ㄱㄱ
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				//오른쪽, 아래만 보면 되지 않나?
				//위,좌 안봐서 중첩 x
				int checkRx, checkRy;
				//오른쪽 확인 - 연합국일 경우 skip
				checkRx = i; checkRy = j + 1;
				//out of range 확인
				if (checkRy < N) {
					if (united[checkRx][checkRy] != united[i][j]) {
						//다른 나라일 경우 문을 열지말지 결정
						int people = abs((map[i][j] - map[checkRx][checkRy]));
						if (people >= L && people <= R)
						{
							//문 열자 
							if (united[checkRx][checkRy] != (checkRx*N + checkRy)) {//원래 지나라가 아닌데 값이 바뀔 경우 전파
								virus(united[checkRx][checkRy], united[i][j]);
							}
							united[checkRx][checkRy] = united[i][j];
							isMoving = true;
						}
					}
				}

				//아래쪽 확인 - 연합국일 경우 skip
				int checkDx, checkDy;
				checkDx = i + 1; checkDy = j;
				//out of range 확인
				if (checkDx < N) {
					if (united[checkDx][checkDy] != united[i][j]) {
						//다른 나라일 경우 문을 열지말지 결정
						int people = abs((map[i][j] - map[checkDx][checkDy]));
						if (people >= L && people <= R)
						{
							//문 열자 
							if (united[checkDx][checkDy] != (checkDx*N + checkDy)) {//원래 지나라가 아닌데 값이 바뀔 경우 전파
								virus(united[checkDx][checkDy], united[i][j]);
							}
							united[checkDx][checkDy] = united[i][j];
							isMoving = true;
						}
					}
				}
			}
		}

		//인구 이동 후 연합 국가 인구 다시 계산
		//같은 넘버인 애들 -> 값 다 더하고 
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				newunited[united[i][j]] = { newunited[united[i][j]].first + map[i][j],newunited[united[i][j]].second + 1 };
			}
		}

		//printf("%d %d\n", newunited[0].first, newunited[0].second);
		//printmap();

		//값 다시 넣기 + 연합 종료(초기화)
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				map[i][j] = newunited[united[i][j]].first / newunited[united[i][j]].second;
				united[i][j] = N * i + j;
			}
		}

		moving += 1;
	} while (isMoving); //끝나고 이동한 적 없으면 종료

	printf("%d", moving-1);
	return;
}
int main()
{
	//input
	scanf("%d %d %d", &N, &L, &R);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			united[i][j] = N * i + j;
		}
	}

	//move
	move();

	return 0;
}