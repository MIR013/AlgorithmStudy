#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>

using namespace std;

int laber[35][15] = { 0, }; //테두리 검사하기!!
int N, H, M;
vector<pair<int, int> > candy; //사다리를 놓을 수 있는 곳 (b번 세로선-b+1번 세로선 a번째 위치)
int len = 0;//candy의 전체 수
vector<int> stack; //놓을 사다리 index! -> candy의 index
bool findMin = false; //최소거리 찾았을 경우

void printlaber()
{
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= N; j++) {
			printf("%d ", laber[i][j]);
		}
		printf("\n");
	}
	printf("=====================\n");
}
bool simLaber(int(*testLaber)[15])
{
	for (int i = 1; i <= N; i++)
	{
		int now = i;
		for (int j = 1; j <= H; j++) {
			if (testLaber[j][now])//1일 경우 좌,우 확인
			{
				if (testLaber[j][now]==1)//왼쪽으로 이동
				{
					now -= 1;
				}
				else if (testLaber[j][now]==2) {//오른쪽으로 이동
					now += 1;
				}
				else {
					cout << "error!" << endl;
				}
			}
		}
		//i번째 사다리로 내려왔는지 확인
		if (i != now) { //하나라도 같은 열로 안내려 온게 있다면 바로 정지하고 -1
			return false;
		}
	}
	return true;//다 같으면 여기 올거니까 1
}
void choiceLab(int num, int check)
{
	//사다리 선택 경우의 수... num개 선택


	//종료조건
	if (findMin) {
		return; //이미 찾았으므로 더 안하고 return
	}
	if (stack.size() == num) {//stack에 넣은 개수와 넣어야 하는 개수가 같다면 종료
		//여기서 시뮬레이션 돌려야 할 듯..
		int temp[35][15] = { 0, };
		for (int i = 1; i <= H; i++) { //사다리 옮기기
			for (int j = 1; j <= N; j++) {
				temp[i][j] = laber[i][j];
			}
		}

		//추가된 사다리 그리기
		for (int i = 0; i < stack.size(); i++)
		{
			//연결되어있으면 pop & return 아니면 그리기
			int nowx = candy[stack[i]].first;
			int nowy = candy[stack[i]].second;
			if (!temp[nowx][nowy] && (nowy+1<=N))//테두리! ->들어갈 곳 둘다 0이어야 사다리 이어짐 하나라도 1이 아니면 거기 선이 있다는 것
			{
				if(!temp[nowx][nowy+1])
					temp[nowx][nowy] = 2; temp[nowx][nowy + 1] = 1; //사다리 추가
			}
			else {
				//이 경우 연결되어 있으니 이 경우의 수는 사용할 수 없음
				stack.pop_back(); //하나라도 연결되어 있으면 안됨
				return;
			}

		}
		//사다리 시뮬레이션
		if (simLaber(temp) == true)
		{
			findMin=true;
			cout << num << endl;
			return;
		}



		//다 돌았으니 pop
		stack.pop_back();
		return;
	}

	//진행조건
	for (int i = check + 1; i < len; i++) {
		stack.push_back(i);//index저장
		choiceLab(num, i); //다음으루
	}
	stack.pop_back(); //그냥 마지막에 다 되어도 pop
	return;
}
void manLaber()
{
	//사다리 시뮬(그냥 상태서도 되는지 확인하기 위함) -> 가능한지 판단 안되면 -1, 가능하면 1
	if (simLaber(laber) == true) {
		//추가로 안놔도 되는 경우
		cout << 0 << endl;
		return;
	}
	//printlaber();

	//1~3개로 사다리 놓아가며 확인(시뮬) - 가능하면 무조건 탈출
	int test;
	for (test = 1; test <= 3; test++) {//사다리 추개 개수: test
		//사다리 선택 (2,3개는 연속된거 나올라 주의)
		len = candy.size();

		//DFS같이
		for (int c = 0; c < len; c++) {
			if (findMin) return; //중간에 답이 나온 경우 이미 프린트 됐으니 종료
			stack.push_back(c);
			choiceLab(test, c); //(개수), 현재 수,횟수
		}

	}
	//4개째+불가능 이라면 -1
	if (test == 4) {
		cout << -1 << endl;
	}

	return;
}
int main()
{
	//input
	cin >> N >> M >> H;
	for (int i = 1; i <= M; i++)
	{
		int a, b;
		cin >> a >> b;
		//0:아래 1:왼쪽으로 갈 수 있음 2: 오른쪽으로 갈 수 있음
		laber[a][b] = 2; laber[a][b + 1] = 1; //입력은 테두리 상관없음
	}
	//사다리를 놓을 수 있는 곳 등록
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= N; j++) {//오른쪽(j+1)만 보면 된다. 테두리 주의
			if (!laber[i][j] && (j + 1 <= N))//테두리를 넘지않고 0인 곳-> 연결되지 않은 것만 선택
			{
				if (!laber[i][j + 1])//0이면 들어갈 수 있는 것
				{
					candy.push_back(make_pair(i, j));
				}
			}
		}
	}

	manLaber();

	return 0;
}