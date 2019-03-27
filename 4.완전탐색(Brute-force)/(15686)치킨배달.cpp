#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

int map[51][51]; //위치
int N, M;
vector<int> home[102]; //치킨 거리 저장, -1일경우 삭제된 것, index 0은 안넣음
vector<pair<int, int> > whereHome; //집이 있는 위치 저장 (그래프)
vector<pair<int, int> > whereChicken; //치킨집이 있는 위치 저장 (그래프)
vector<int> stack; //조합 경우의 수 제작 용 -> 치킨집 좌표가 아니라 번호 저장
int chickenRoad = 9876543; //도시의 치킨거리

void makeC(int loc)
{
	// 종료조건
	if (stack.size() == M) { //stack의 크기가 M이면 종료
		/*
		for (int i = 0; i < stack.size(); i++) {
			printf("(%d)", stack[i]);
		}
		printf("\n===========\n\n");
		*/
		//여기서 치킨집 최소거리 측정
		int totalmin = 0;
		for (int i = 0; i < whereHome.size(); i++) {
			int min = 99999;
			for (int j = 0; j < M; j++)
			{
				if (home[i][stack[j]] < min) {//i번째 집과 stack[j]번 치킨집 간 거리
					min = home[i][stack[j]];
				}
			}
			totalmin += min;
		}
		if (chickenRoad > totalmin)
			chickenRoad = totalmin;
			   
		stack.pop_back();
		return;
	}
	//진행조건
	for (int next = loc + 1; next < whereChicken.size(); next++)
	{
		//push
		stack.push_back(next);
		makeC(next);
	}

	stack.pop_back();

	return;
}
void chicken()
{
	//집-치킨집 간 모든 거리 찾기
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j] == 2)//치킨집이면 거리계산
			{
				for (int h = 0; h < whereHome.size(); h++) {
					home[h].push_back(abs(whereHome[h].first - i) + abs(whereHome[h].second - j));
				}
			}
		}
	}

	/*
		각 집당 최소 치킨거리를 선택 -> 치킨집의 수가 <=M이면 종료
		아니면 다음 최소값 세트를 계산한다.
	*/
	for (int next = 0; next < whereChicken.size(); next++) {
		stack.push_back(next);
		makeC(next);
	}
	cout << chickenRoad << endl;
	//printf("%d\n", chickenRoad);

	return;
}
int main()
{
	//input
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) //집이면 저장한다.
				whereHome.push_back({ i,j });
			else if (map[i][j] == 2)
				whereChicken.push_back({ i,j });
		}
	}
	chicken();

	return 0;
}