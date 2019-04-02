#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N, M;
int map[8][8];
vector<pair<int, pair<int, int> > > cctv; //cctv를 저장 최대 8 종류, 좌표
int caseOfCctv[6] = { -1,4,2,4,4,1 };//각 cctv가 감시하는 경우의 수
int minSq = 987654321;//사각지대 최소 크기
vector<int> stack;//경우의 수 계산 stack의 index는 cctv의 인덱스이고 안의 값은 cctv의 각 현재 경우의 수를 저장한다.
//각 cctv의 경우의 수 마다 확인해야 할 방향을 저장해야 하는가
typedef enum compass{UP=1,RIGHT,DOWN,LEFT};
//cctv번호, 경우의 수, 방향
int caseDir[6][5][5] = { {0}, 
{{0},{0,UP,0,0,0},{0,RIGHT,0,0,0},{0,DOWN,0,0,0},{0,LEFT,0,0,0}},
{{0},{0,LEFT,RIGHT,0,0},{0,UP,DOWN,0,0},{0},{0}},
{{0},{0,UP,RIGHT,0,0},{0,RIGHT,DOWN,0,0},{0,DOWN,LEFT,0,0},{0,LEFT,UP,0,0}},
{{0},{0,LEFT,UP,RIGHT,0},{0,UP,RIGHT,DOWN,0},{0,RIGHT,DOWN,LEFT,0},{0,DOWN,LEFT,UP,0}},
{{0},{0,UP,RIGHT,DOWN,LEFT},{0},{0},{0}}};
int dirx[5] = {0,-1,0,1,0};
int diry[5] = {0,0,1,0,-1};


int checkSq(int table[][8])//사각지대 계산
{
	int count = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (table[i][j] == 0)
				count++;
	return count;
}
void detect(int(*temp)[8]) //cctv가 감시하는 곳을 -1로 만든다.
{
	//cctv와 stack을 보고 체크하기
	for (int i = 0; i < cctv.size(); i++)
	{
		for (int dir = 1; dir < 5; dir++)
		{
			int ndir = caseDir[cctv[i].first][stack[i]][dir];
			if (ndir == 0)//이면 더 확인 안한다!
				continue;
			int nextx = cctv[i].second.first + dirx[ndir];
			int nexty = cctv[i].second.second + diry[ndir];
			while (nextx >= 0 && nextx < N && nexty >= 0 && nexty < M)//map은 0-7
			{//테두리까지 갈때까지 진행 
				if (temp[nextx][nexty] == 6) {
					break;
				}
				if (temp[nextx][nexty] == 0)
					temp[nextx][nexty] = -1;


				//1-5는 그냥 넘어간다.
				nextx += dirx[ndir]; nexty += diry[ndir];
			}

			
		}
	}

	return;
}
/*
	이 경우의 수가 이전 것은 여러개 중에 몇개 선택이라면
	여기는 일단 나와야 하는 수가 cctv의 개수로 정해져 있다 
	하지만 그 안에서 1~각 cctv의 경우의 수 만큼 나오기 때문에 이를 출력할 수 있도록 해야한다.
*/
void makeC(int cindex)//현재 경우의 수, cctv의 인덱스
{
	//종료조건
	if (stack.size()==cctv.size())
	{
		//그리기 - 경우의 수마다 그리면 진짜 오래 걸리것 같은데
		int temp[8][8];
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				temp[i][j] = map[i][j];

		detect(temp);

		//print
		/*

		printf("---------------\n");
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < M; y++) {
				printf("%d ", temp[x][y]);
			}
			printf("\n");
		}
		*/
		//최소값 계산
		int min = checkSq(temp);
		if (minSq > min)
			minSq = min;
		//0이면 뭐 아예 멈춰버릴까???? -> 시간보고

		stack.pop_back();
		return;
	}

	//진행조건
	//경우의 수가 덜 되었으니 자기꺼 추가하고 다음애로 넘어간다(있으면)
	
	for (int i = 1; i <= caseOfCctv[cctv[cindex].first]; i++) //여기서는 각 cctv마다 경우의 수가 다르므로!!
	{
		stack.push_back(i);
		makeC(cindex+1);//다음 cctv의 경우의 수를 넣어준다.
	}

	stack.pop_back();
	return;
}
void watch()
{
	//재귀사용하면 될거같은데
	//cctv가 없을 경우
	if (!cctv.size()) {
		minSq=checkSq(map);

	}
	else {
		//cctv가 있을 경우
		for (int i = 1; i <= caseOfCctv[cctv[0].first]; i++)
		{
			stack.push_back(i);
			makeC(1);//다음 cctv의 경우의 수를 넣어준다.
		}
	}

	return;
}
int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] > 0 && map[i][j] < 6) //cctv등록
				cctv.push_back({ map[i][j],{ i,j } });
		}
	}

	watch();
	cout << minSq << endl;

	return 0;
}