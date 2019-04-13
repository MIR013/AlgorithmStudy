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

		combination.pop_back();//������ ����
		return;
	}


	for (int i = index+1; i <= n; i++) {
		combination.push_back(i);
		makeComb(i);
	}
	combination.pop_back();//�ڱ��ڽ��� �� ������ ���
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
		if (!visited[i]) { //�湮�� �� �����
			visited[i] = 1;//�湮
			permutation.push_back(i);
			makePerm(i);
			visited[i] = 0;//���ƿ����� �湮 ���ѰŰ� ��
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