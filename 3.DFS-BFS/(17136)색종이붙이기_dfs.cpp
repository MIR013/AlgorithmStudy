#include<iostream>
#include<vector>
using namespace std;

int minColor = 987654321;

int map[10][10];
int visited[10][10] = { 0, };
int usedSize[6] = { 0, };
bool cannotuse = true;

void changeVisited(int x, int y, int size, int value)
{
	for (int i = x; i < x + size; i++)
	{
		for (int j = y; j < y + size; j++) {
			visited[i][j] = value;
		}
	}
	return;
}
bool isCan(int size, int x, int y)
{
	for (int i = x; i < x + size; i++)
	{
		for (int j = y; j < y + size; j++) {
			if (!map[i][j] || visited[i][j]) //0이 있거나 이미 좋이를 놓은 곳
			{
				return false;
			}
		}
	}
	return true;
}
bool isFull() //모든 곳에 색종이를 넣었는지 확인
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++) {
			if (map[i][j] != visited[i][j]) {
				return  false;
			}
		}
	}
	return true;
}
void color(int usedNum, int paperSize)
{
	//종료조건

	//이미 최소값보다 커진 경우
	if (usedNum >= minColor) return;
	//다 썼을 경우
	if (usedSize[paperSize] > 5)return;
	if (isFull()) //모든 곳에 색종이를 둔 경우 
	{
		//최소 색종이 사용량 계산
		if (usedNum < minColor)
			minColor = usedNum;
		cannotuse = false;

		return;
	}


	//진행조건
	//하나하나 보면서 종이가 놓여져 있지 않고 놓여질 수 있는자리에서
	//사이즈를 5~1로 다 가본다.
	int i, j;
	bool find = false;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++) {
			if (map[i][j] && !visited[i][j]) {
				find = true;
				break;
				//여기서 for문을 돌려줄 필요가 없는게 어차피 얘는 가능한 맨 처음 값을 가져오는 부분임
				//배귀를 돌면서 모든 종이 둘 수 있는 곳에 다 가기 때문에
				//여기서는 처음으로 1이 나온 곳을 찾아가면 된다
				//거기서 사이즈가 5~1로가는 걸
			}
		}
		if (find)break;
	}
	//5~1사이즈를 확인
	for (int s = 5; s >0 ; s--)
	{
		//이 사이즈 가능한지 확인
		if (isCan(s, i, j)) {//되면 넣는다 -> 5가 됐었으면 4,3,2,1도 된다. isCan안돌리려고
			//배열이라 새 값 넣어 줘야 할 듯 - dfs는 돌아온대!
			changeVisited(i, j, s, 1);
			usedSize[s]++;//사용함을 의미...!->5이상인지는 종료조건에서 판단
			color(usedNum + 1, s); //★★★★재귀에서 돌아오면서 visited도 원래 상태로 돌아온다!! ★★★★★★★
			//다시 돌려야 하지
			usedSize[s]--;//안쓴게 되니까
			changeVisited(i, j, s, 0);//방문 안한게 되니까

		}

	}



	return;
}
int main()
{

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			cin >> map[i][j];

	color(0, 0);
	if (cannotuse)
		cout << -1 << endl;
	else
		cout << minColor << endl;

	return 0;
}