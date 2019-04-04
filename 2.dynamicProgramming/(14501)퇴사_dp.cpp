#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
pair<int, int> input[16]; //걸리는 시간, 완료시 받는 돈
bool isFull[16] = { false, };//해당 칸이 찾는지 확인
vector<int> result;//실행할 일의 index 저장
int maxMoney = -1;//최대 돈

void scheduling(int day)//날짜
{
	//종료조건
	if (day+input[day].first>=N+1) { //day가 더 들어갈 수 없다 -> 종료
		if (day + input[day].first == N + 1) {//n일에 딱 맞춰서 끝나는 경우
			result.push_back(input[day].second);//돈넣기
		}

		//최대 최소 비교
		int sum = 0;
		for (int i = 0; i < result.size(); i++)
		{
			sum += result[i];
		}
		if (sum > maxMoney)
			maxMoney = sum;

		if (day + input[day].first == N + 1) {//n일에 딱 맞춰서 끝나는 경우
			result.pop_back();
		}
		return;
	}


	//진행조건
	result.push_back(input[day].second);//돈넣기
	for (int i = day + input[day].first; i <= N; i++) {//이전꺼 기준으로 올 수 있는거 다 봐야한다.
		scheduling(i);//일단 되던 안되던 들어가고 종료조건에서 확인
	}


	result.pop_back();
	return;
}
int main()
{
	/*
		조건에 맞는 경우의 수 조합을 모두 구하면 될 듯
		(1,3,7...)eks whgkqdml rotnsms tkdrhksdl djqtdmsk
	*/
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> input[i].first >> input[i].second; // 걸리는 일 수, 받는 돈
	}
	
	for (int i = 1; i <= N; i++) {
		scheduling(i);
	}


	cout << maxMoney << endl;

	return 0;
}