#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

//각 톱니바퀴의 상태를 저장한다 -> 시계방향/ 반시계방향이면 땡겨서 회전시킨다.
vector<int> gear[5];//1~4까지 사용, 0번째부터 시계방향으로 값이 매겨짐. 즉, 12시 방향의 인덱스가 0
int K;

void printGears()
{
	cout << "=========================" << endl;
	for (int i = 1; i<=4; i++) {
		for (int j = 0; j < 8; j++) {
			cout << gear[i][j];
		}
		cout << endl;
	}
}
int sumGear()
{
	int total = 0;
	for (int i = 1; i <= 4; i++) {
		if (gear[i][0] == 1) {
			total += (int)pow(2.0, (i - 1));
		}
	}
	return total;
}
void goNext(int index, int dir)//확인하면서 땡기면 안되구 다 확인한 후 때겨야 한다.
{
	if (dir == 1) {//시계방향
		int temp = gear[index][7];
		for (int i = 7; i >0; i--) {
			gear[index][i] = gear[index][i - 1];
		}
		gear[index][0] = temp;
	}
	else {//반시계방향
		int temp = gear[index][0];
		for (int i = 0; i < 7; i++) {
			gear[index][i] = gear[index][i + 1];
		}
		gear[index][7] = temp;
	}
	return;
}
void rotation(int gearNum, int dir)
{
	int canRotate[4] = { 0, };//0이면 회전 불가
	//회전이 가능한지 먼저 확인한다
	for (int i = 1; i < 4; i++) {
		if (gear[i][2] != gear[i + 1][6])//서로 다른 극이어야 회전이 가능하다.
			canRotate[i] = 1;
	}

	//왼쪽 - 2~6
	int nowDir = (-dir);
	for (int i = gearNum - 1; i > 0; i--) {
		//0이면 회전불가
		if (canRotate[i] == 0)
			break;
		goNext(i, nowDir);
		nowDir = (-nowDir);//방향 전환
	}
	
	//본인 회전
	goNext(gearNum, dir);

	//오른쪽 - 6~2
	nowDir = (-dir);
	for (int i = gearNum + 1; i <= 4; i++) {
		if (canRotate[i - 1] == 0)
			break;
		goNext(i, nowDir);
		nowDir = (-nowDir);//방향 전환
	}
}
int main()
{
	/*
		회전 후가 아니라 회전 하기 전의 극 상태 에 따라
		극이 서로 다르다면 반대방향으로 회전하게 된다.
	*/
	for (int i = 1; i <= 4; i++)
	{
		char input[9];
		cin >> input;
		for (int j = 0; j < 8; j++)
		{
			gear[i].push_back(input[j] - '0');
		}
	}
	cin >> K;
	for (int i = 0; i < K; i++) {
		int g, d;
		cin >> g >> d;
		rotation(g, d);
		//printGears();
	}
	cout << sumGear() << endl;

	return 0;
}