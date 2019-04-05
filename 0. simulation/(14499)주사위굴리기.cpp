#include<iostream>
#include<vector>
using namespace std;

int N, M;
int map[20][20];
int dirx[5] = { -1000,0,0,-1,1 };//동=1,서,북,남
int diry[5] = { -1000,1,-1,0,0 };
//주사위의 번호 수: 굴릴때마다 방향에 따라 때겨주거나 하면 된다.
int dice[7] = { 0, };//위=1,앞,오른,왼,뒤,아래
pair<int, int> now;//현재 주사위 위치

void changeNum(int diceIndex,int x,int y)
{
	if (!map[x][y]) {//칸이 0일 경우
		map[x][y] = dice[diceIndex];
	}
	else {
		dice[diceIndex] = map[x][y];
		map[x][y] = 0;
	}
	return;
}
bool moveDice(int dir)
{
	int temp1,temp2;

	//주사위 현재 위치 옮기기
	int nextx = now.first + dirx[dir];
	int nexty = now.second + diry[dir];
	//테두리 밖이면 무시
	if (nextx < 0 || nextx >= N || nexty < 0 || nexty >= M) {
		return false;
	}
	now.first = nextx; now.second = nexty;

	//무조건 주사위 맨 위를 dice[1]에 맞춰야 한다 반드시
	//각 방향에 맞게 값 바꾸기!
	switch (dir)
	{
	case 1: //동
		//주사위 뒤집기(값바꾸기)
		temp1 = dice[1];//위 저장
		temp2 = dice[3];//동 저장

		dice[1] = dice[4];//서->위
		dice[3] = temp1;//위->동
		dice[4] = dice[6];//아래->서
		dice[6] = temp2;//동->아래
		break;
	case 2: //서
		temp1 = dice[4];//서 저장
		temp2 = dice[6];//아래 저장

		dice[4] = dice[1];
		dice[6] = temp1;
		dice[1] = dice[3];
		dice[3] = temp2;
		break;
	case 3: //북
		temp1 = dice[5];//서 저장
		temp2 = dice[6];//아래 저장

		dice[5] = dice[1];
		dice[6] = temp1;
		dice[1] = dice[2];
		dice[2] = temp2;
		break;
	case 4: //남
		temp1 = dice[2];//서 저장
		temp2 = dice[6];//아래 저장

		dice[2] = dice[1];
		dice[6] = temp1;
		dice[1] = dice[5];
		dice[5] = temp2;
		break;
	default:
		break;
	}

	//칸에 수 옮기기
	changeNum(6, nextx, nexty);

	return true;
}
int main()
{
	int order;
	cin >> N >> M >> now.first >> now.second >> order;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];

	for (int time = 0; time < order; time++)
	{
		int dir;
		cin >> dir;
		if(moveDice(dir))//참일때만!
			cout << dice[1] << endl;//주사위 맨 위 출력
	}

	return 0;
}