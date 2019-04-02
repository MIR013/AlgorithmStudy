#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
int A[12];//숫자를 저장
vector<int> operation; //PLUS=0,MINUS=1,MUL=2,DIV=3 
int totalMin = 1000000001;
int totalMax = -1000000001; //최대가 -값이 나올 수 있으니 주의

void theOperator() //순열 경우의 수 구하기(조합의 경우의 수와 다름!! 모든 값이 나온다)
{
	do {
		int cal = A[0];//맨 처음 값을 넣어둔다
		for (int i = 1; i < N; i++) {//다음꺼랑 계산 할 것임
			switch (operation[i - 1]) {
			case 0:// +
				cal += A[i];
				break;
			case 1:// -
				cal -= A[i];
				break;
			case 2:// *
				cal *= A[i];
				break;
			case 3:// /
				cal /= A[i];

				break;
			}
		}

		//최대 최소 계산
		if (totalMax < cal)
			totalMax = cal;
		if (totalMin > cal)
			totalMin = cal;

	} while (next_permutation(operation.begin(), operation.end()));


	return;
}
int main()
{
	/*
		연산자 순위를 무시하고 앞에서 부터 차례로 계산할 것
		나눗셈은 몫만 취할 것, 음수의 경우 나눈 몫을 음수로 한다.
		식의 결과가 최대, 최소인 것을 구하라
	*/
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < 4; i++) {
		int num;
		cin >> num;
		for (int j = 0; j < num; j++) {
			operation.push_back(i);
		}
	}


	theOperator();
	cout << totalMax << endl;
	cout << totalMin << endl;

	return 0;
}