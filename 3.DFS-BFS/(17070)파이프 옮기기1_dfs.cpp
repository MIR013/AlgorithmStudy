#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
int map[17][17];
int totalNum = 0;
//가로:0, 세로:1, 테두리:2

int whatisit(int fx, int fy, int lx, int ly)
{
	int right = ly - fy;
	int down = lx - fx;
	if (right && down)
		return 2;
	else if (right)
		return 0;
	else
		return 1;
}
void movePipe(int fx, int fy, int lx, int ly)//현재 파이프의 위치를 전달한다.
{
	//종료조건
	if (lx == N && ly == N) { //파이프의 마지막이 끝에 닿으면 된다.
		totalNum++;
		return;
	}

	//진행조건
	//벽과 테두리는 건들이지 말 것
	switch (whatisit(fx, fy, lx, ly)) {
	case 0://가로
		//오른쪽으로 밀기
		if (map[lx][ly + 1] != 1 && ly + 1 <= N)
			movePipe(lx, ly, lx, ly + 1);
		//오른쪽으로 갔다가 회전
		if (map[lx][ly + 1] != 1 && map[lx + 1][ly + 1] != 1 && map[lx + 1][ly] != 1 && ly + 1 <= N && lx + 1 <= N)
			movePipe(lx, ly, lx + 1, ly + 1);
		break;
	case 1://세로
		//아래로 밀기
		if (map[lx + 1][ly] != 1 && lx + 1 <= N)
			movePipe(lx, ly, lx + 1, ly);
		//아래로 갔다가 회전
		if (map[lx + 1][ly] != 1 && map[lx][ly + 1] != 1 && map[lx + 1][ly + 1] != 1 && ly + 1 <= N && lx + 1 <= N)
			movePipe(lx, ly, lx + 1, ly + 1);
		break;
	case 2://대각선
		//대각선으로 직진
		if (map[lx + 1][ly] != 1 && map[lx][ly + 1] != 1 && map[lx + 1][ly + 1] != 1 && ly + 1 <= N && lx + 1 <= N)
			movePipe(lx, ly, lx + 1, ly + 1);
		//오른쪽
		if (map[lx][ly + 1] != 1 && ly + 1 <= N)
			movePipe(lx, ly, lx, ly + 1);
		//아래
		if (map[lx + 1][ly] != 1 && lx + 1 <= N)
			movePipe(lx, ly, lx + 1, ly);

		break;
	default:
		cout << "error" << endl;
		break;
	}

	return;
}
int main()
{
	/*
		dfs로 찾아서 도착하면 횟수 증가시키면 되겠댜
		단, visited는 사용하지 않는다!
		일렬로가게 만들 것이니께
		x가 세로 y가 가로임!! 헷갈리지 말 것
		차지하는 공간 주의
	*/

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	movePipe(1, 1, 1, 2);

	cout << totalNum << endl;

	return 0;
}