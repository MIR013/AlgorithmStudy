#include<iostream>
#include<algorithm>
#include<queue>
#include<stdio.h>

using namespace std;

typedef struct shark {
	int row;
	int col;
	int size; //현재 크기
	int swim; //이동거리
};
struct cmp {
	bool operator()(shark t, shark u) {
		return t.swim < u.swim; // min heap
	}
};
int N;
int map[21][21];
int isVisited[21][21] = { 0, }; // 아기상어가 방문했는지 여부를 본다 최소값이므로 간데 갈필요 없음
shark baby; // 정보 누적할 애
int dirx[4] = { -1,0,0,1 };//상좌우하
int diry[4] = { 0,-1,1,0 };
int ate = 0; //먹었던 물고기 수
bool isescape = 0;

void printmap()
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void BFS()
{
	while (1)
	{
		//bfs - 아기상어가 물고기 먹으면 다시 시작함(baby에 정보 누적할 것)
		shark candy; //후보군! - 비교해야할듯..
		candy.swim = 0;
		//queue clear - 여기서 선언하면 자동 clear겠지...?
		queue<shark> pq; //이러면 거리 짧은 것 부터 보겠지...?
		//isVisited clear
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				isVisited[i][j] = 0;
			}
		}
		pq.push(baby); // init push
		isescape = 0;
		isVisited[baby.row][baby.col] = 0;//아기상어자리는 가지마

		//printf("-------------\n");
		//printmap();

		while (!pq.empty()) {
			//pop
			shark now = pq.front();
			pq.pop();

			//now가 후보보다 멀어지면 어차피 더 못감 -> 후보있는애 먹고 끝내기
			if (now.swim >= candy.swim && candy.swim!=0) {
				//상어위치도 교환
				map[candy.row][candy.col] = 9;
				map[baby.row][baby.col] = 0;
				//물고기를 먹었다 -> baby다시쓰기 + break + 지도 0으로
				baby.row = candy.row; baby.col = candy.col;
				baby.swim = candy.swim;

				ate++;
				//같은 수의 물고기를 먹었으면 크기 커짐
				if (ate == baby.size) {
					baby.size++;
					ate = 0;//다시 0으로
				}
				isescape = 1;
				break; //이럼 방향 for문을 빠져나감....!
			}


			//상좌하우 + 테두리 + 물고기를 보고 지나갈 수 있는지 = pq에 넣기
			for (int dir = 0; dir < 4; dir++) {
				int nextx = now.row + dirx[dir];
				int nexty = now.col + diry[dir];
				//테두리
				if (nextx < 0 || nextx >= N || nexty < 0 || nexty >= N)
					continue; //그냥 지나가
				//0인 경우 글로 간다
				if (map[nextx][nexty] == 0 && !isVisited[nextx][nexty]) {
					shark new_next;
					new_next.row = nextx; new_next.col = nexty;
					new_next.size = now.size; new_next.swim = now.swim + 1; //한칸 이동함!
					pq.push(new_next);
					isVisited[nextx][nexty] = 1;
				}
				//1~6인경우 -> 자기 사이즈랑 확인
				if (map[nextx][nexty] > 0 && map[nextx][nexty] < 7 && !isVisited[nextx][nexty]) {
					//크기가 나보다 크다
					if (baby.size < map[nextx][nexty])//이거 baby로해도 되지 않나
					{
						continue; //못감
					}
					//크기가 같다
					else if (baby.size == map[nextx][nexty] && !isVisited[nextx][nexty]) {
						//지나는 가는데 못먹음 0과 똑같음
						shark new_next;
						new_next.row = nextx; new_next.col = nexty;
						new_next.size = now.size; new_next.swim = now.swim + 1; //한칸 이동함!
						pq.push(new_next);
						isVisited[nextx][nexty] = 1;
					}
					//크기가 작다
					else if (now.size > map[nextx][nexty] && !isVisited[nextx][nexty])
					{
						//일단 후보에 넣고 비교
						//후보에 아무것도 없으면 새로 넣음
						if (candy.swim == 0) {
							candy.row = nextx; candy.col = nexty;
							candy.size = now.size;
							candy.swim = now.swim + 1;
							isVisited[nextx][nexty] = 1;
							pq.push(candy);//일단 넣어야..
						}
						else {
							//애초에 후보에 큰게 들어가 있을 수 없음
							if (candy.swim == now.swim + 1) { //는 1칸 앞 애들을 보니까
								//같을 경우 위->왼으로 먼저
								if (nextx < candy.row) {
									//새로온게 위에 있다 - 새 후보로
									candy.row = nextx; candy.col = nexty;
									candy.size = now.size;
									candy.swim = now.swim + 1;
									isVisited[nextx][nexty] = 1;
									pq.push(candy);
								}
								else if (nextx == candy.row) {
									//새로온게 같은 자리에 있다
									if (nexty < candy.col) {
										//왼쪽이 있는거 먼저 - 새 후보로
										candy.row = nextx; candy.col = nexty;
										candy.size = now.size;
										candy.swim = now.swim + 1;
										isVisited[nextx][nexty] = 1;
										pq.push(candy);
									}
									else {
										//오른쪽에 있다 - 후보에 안넣음
									}
								}
								else {
									//새로온게 아래에 있다. - 후보에 안넣음
								}
							}
							else {
								//여기 들어올 일 없음
								printf("error!\n");
							}
						}

					}
				}

			}
			//탈출
			if (isescape)
				break;
		}
		// bfs를 나왔을때 queue가 비어있으면 더이상 갈 데가 없다는 뜻
		// 근데 물고기를 안먹었어야 함
		if (pq.empty() && !isescape) {
			printf("%d\n", baby.swim);
			break;
		}

	}

	return;
}
int main()
{
	scanf("%d", &N);
	//input
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 9) {
				//아기상어 처음 위치 저장
				baby.row = i; baby.col = j;
				baby.size = 2; baby.swim = 0;
			}
		}
	}
	BFS();
	return 0;
}