#include<iostream>
#include<vector>
using namespace std;

int N;
vector<int> stu;//한 방에있는 응시자 수
int B, C;//총감독관이 감시할 수 있는 응시자 수, 부감독관이 감시할 수 있는 응시자 수
long long supervisor = 0;//필요한 감독관의 수

void supervise()
{
	//각각의 시험장에 총감독관은 오직 1명만 있어야 하고, 부감독관은 여러 명 있어도 된다.
	//각 방당 총 감독관 1명 + 부감독관 여러명 가능, 총 감독관 2명... 불가능
	for (int i = 0; i < stu.size(); i++)
	{
		//가능한 감독관 총 수 1000000*1000000(b=1,c=1)
		//총 감독관이 먼저 들어간다 X
		int check = stu[i] - B;
		supervisor++;//일단 총 감독은 들어간다.
		if (check <= 0)
			continue;

		// 총 감독관이 커버 못할 경우
		double sub = (double)check / C;
		if (sub - (int)sub > 0) {//소수점이 존재할 경우 무조건 +1 해야한다.
			supervisor += (int)sub + 1;
		}
		else {
			supervisor += (int)sub;
		}
	}

	return;
}
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		stu.push_back(input);
	}
	cin >> B >> C;

	supervise();
	cout << supervisor << endl;
	
	return 0;
}