#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int N;
int map[21][21];//index는 1부터 시작
vector<int> team1; //index를 저장한다.
int minTotal = 987654321;
bool endAll = false;//차이의 최소값이 0이 나오면 전부다 멈춘다.

int capacity(vector<int> c)//해당팀으로 나눌 경우의 능력치를 계산한다.
{
	int cap = 0;
	for (int i = 0; i < N / 2; i++) {
		for (int j = 0; j < N / 2; j++)
		{
			cap += map[c[i]][c[j]];
		}
	}


	return cap;
}
void team(int size, int index)
{
	//종료조건
	//횟수를 증가하면 다 종료
	if (endAll==true)
		return;
	if (team1.size() == size) {
		
		/*
		for (int i = 0; i < team1.size(); i++) {
			cout << team1[i] << " ";
		}
		cout << " : ";
		*/
		
		//team2구하기
		vector<int> team2; //team1에 들어가지 않은 index를 여기 저장한다.
		int index = 0;
		for (int i = 1; i <=N; i++) {
			bool isExist = false;
			//속한게 아니라면 추가한다
			if (isExist)
				continue;
			for (int j = 0; j < size; j++) {
				if (i == team1[j]) {
					isExist = true;
					break;
				}
			}
			if (!isExist)
				team2.push_back(i);
		}
		/*
		for (int i = 0; i < team2.size(); i++) {
			cout << team2[i] << " ";
		}
		cout << endl;
		*/
		//차이의 최소값 계산
		int cap1=capacity(team1);
		int cap2=capacity(team2);
		if (abs(cap1 - cap2) < minTotal) 
			minTotal = abs(cap1 - cap2);

		//차이가 0일 경우 전체 종료 시키면 더 빨라질 듯
		if (minTotal == 0) {
			endAll = true;
			return;
		}
		
		team1.pop_back();
		return;
	}

	//진행조건
	for (int i = index + 1; i <= N; i++) {
		team1.push_back(i);
		team(N / 2, i);
	}
	team1.pop_back();
	return;
}
int main()
{
	//input
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	//순열 + 나머지를 계산해서 최소값을 구한다.
	for (int i = 1; i <= N; i++) {
		team1.push_back(i);
		team(N / 2, i);
	}
	cout << minTotal << endl;

	return 0;
}