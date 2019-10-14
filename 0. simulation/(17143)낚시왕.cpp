#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int R, C, M;//행, 열, 상어의 수
int fishman = 0;//낚시꾼의 현재 위치(c주위로 움직인다)
int total_size = 0;
typedef struct shark {
	int speed;
	int size; //가 -1이면 없는 걸로 하자
	int dir; //위:1 아래:2 오른쪽:3 왼쪽:4
};
vector<shark> map[101][101];//상어의 위치 저장

void printMap()
{
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			printf("%2d ", map[i][j][0].size);
		}
		printf("\n");
	}
	printf("\n");

}
bool nextValue(int *nexts, int init, int end, int speed)//시작값, 처음 방향, 배열끝 어디인지, 움직일 거리
{
	int time = 0;
	int initdir = init;
	while (time < speed) {
		//움직인 후 방향변경해야하누..
		*nexts += init;
		//테두리 만날 경우
		if (*nexts < 1 || *nexts > end) {
			init = -init;//방향변경
			*nexts += (2 * init);
		}
		time++;
	}
	//방향값이 변경된다면 이것도 알려줘야함
	if (initdir != init) {
		return false;//변경됨
	}
	return true;
}
shark sortShark(vector<shark> arr)
{
	int maxIndex = -1;
	int maxValue = -1;
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i].size > maxValue) {
			maxValue = arr[i].size;
			maxIndex = i;
		}
	}

	return arr[maxIndex];
}
void eatShark()
{
	//중첩된 상어가 있다면 소팅해서 가장 큰애만 남긴다.
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (map[i][j].size() > 1) {
				shark temp = sortShark(map[i][j]);
				map[i][j].erase(map[i][j].begin(), map[i][j].end());
				map[i][j].push_back(temp);
			}
		}
	}

	return;
}
void moveShark()
{
	//하나하나보구 움직입시더..
	//=> 여러마리 중복문제는 그냥 크기 비교하면 해결될 듯
	//쨋든 가장 큰 물고기가 남으니까

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			//상어가 존재한다면
			if (map[i][j][0].size != -1) {
				int dir = map[i][j][0].dir;
				int speed = map[i][j][0].speed;
				int nextx = i, nexty = j;
				int time = 0;
				//이동 + 테두리 확인
				switch (dir) {
				case 1:
					if (!nextValue(&nextx, -1, R, speed)) {
						map[i][j][0].dir = 2;//방향전환
					}
					nexty = j;
					break;
				case 2:
					if (!nextValue(&nextx, 1, R, speed)) {
						map[i][j][0].dir = 1;//방향전환
					}
					nexty = j;
					break;
				case 3:
					nextx = i;
					if (!nextValue(&nexty, 1, C, speed)) {
						map[i][j][0].dir = 4;
					}
					break;
				case 4:
					nextx = i;
					if (!nextValue(&nexty, -1, C, speed)) {
						map[i][j][0].dir = 3;
					}
					break;
				}

				//그자리에 상어가 있는지...?
				//이거 다 움직이고 난 후에 크기비교해야할 것 같은데
				//상어 이동
				map[nextx][nexty].push_back(map[i][j][0]);
				//원래 있던 곳 없어짐(삭제)
				map[i][j][0].size = -1;

			}
		}
	}

}
void getShark(int here)
{
	//여기서는 반드시 0만 볼 수 있음
	for (int i = 1; i <= R; i++)
	{
		//밑으로 내려가믄서 상어를 확인한다.
		if (map[i][here][0].size != -1)
		{
			//상어 먹음
			total_size += map[i][here][0].size;

			map[i][here][0].dir = 0;
			map[i][here][0].size = -1;
			map[i][here][0].speed = 0;
			break;
		}

	}

	return;
}

int main()
{
	cin >> R >> C >> M;
	int num = 0;//상어의 인덱스 부여

	//초기화
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			map[i][j].push_back({ -1,-1,-1 });
		}
	}

	for (int i = 0; i < M; i++)
	{
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		shark temp;
		temp.speed = s;
		temp.dir = d;
		temp.size = z;
		map[r][c][0] = temp;
	}

	//printMap();


	while (fishman < C) {
		//낚시왕이 오른쪽으로 움직임
		fishman++;
		//상어잡기
		getShark(fishman);
		//상어 이동
		moveShark();
		//상어 먹기
		eatShark();

		//printMap();
	}

	cout << total_size << endl;

	return 0;
}