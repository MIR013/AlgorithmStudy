#include<iostream>
#include<vector>
using namespace std;

int visited[999];
vector<int> permutation;
vector<int> combination;
int comb = 3;
int n;

void makeComb(int index)
{
	if (combination.size() == comb) {
		cout << "( ";
		for (int i = 0; i < comb; i++) {
			cout << combination[i] << " ";
		}
		cout << ")" << endl;

		combination.pop_back();//마지막 삭제
		return;
	}


	for (int i = index+1; i <= n; i++) {
		combination.push_back(i);
		makeComb(i);
	}
	combination.pop_back();//자기자신이 다 돌았을 경우
	return;
}
void makePerm(int index)
{
	if (permutation.size() == n) {
		cout << "( ";
		for (int i = 0; i < n; i++) {
			cout << permutation[i] << " ";
		}
		cout << ")" << endl;
	}


	for (int i = 1; i <= n; i++) {
		if (!visited[i]) { //방문한 적 없어야
			visited[i] = 1;//방문
			permutation.push_back(i);
			makePerm(i);
			visited[i] = 0;//돌아왔으니 방문 안한거가 됨
			permutation.pop_back();
		}
	}
	return;
}
int main()
{
	cin >> n;

	makePerm(0);

	cout << "<<combination>>" << endl;
	for (int i = 1; i <= n; i++) {
		combination.push_back(i);
		makeComb(i);
	}

	return 0;
}