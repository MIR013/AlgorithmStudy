#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int N;
int map[21][21];//index�� 1���� ����
vector<int> team1; //index�� �����Ѵ�.
int minTotal = 987654321;
bool endAll = false;//������ �ּҰ��� 0�� ������ ���δ� �����.

int capacity(vector<int> c)//�ش������� ���� ����� �ɷ�ġ�� ����Ѵ�.
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
	//��������
	//Ƚ���� �����ϸ� �� ����
	if (endAll==true)
		return;
	if (team1.size() == size) {
		
		/*
		for (int i = 0; i < team1.size(); i++) {
			cout << team1[i] << " ";
		}
		cout << " : ";
		*/
		
		//team2���ϱ�
		vector<int> team2; //team1�� ���� ���� index�� ���� �����Ѵ�.
		int index = 0;
		for (int i = 1; i <=N; i++) {
			bool isExist = false;
			//���Ѱ� �ƴ϶�� �߰��Ѵ�
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
		//������ �ּҰ� ���
		int cap1=capacity(team1);
		int cap2=capacity(team2);
		if (abs(cap1 - cap2) < minTotal) 
			minTotal = abs(cap1 - cap2);

		//���̰� 0�� ��� ��ü ���� ��Ű�� �� ������ ��
		if (minTotal == 0) {
			endAll = true;
			return;
		}
		
		team1.pop_back();
		return;
	}

	//��������
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

	//���� + �������� ����ؼ� �ּҰ��� ���Ѵ�.
	for (int i = 1; i <= N; i++) {
		team1.push_back(i);
		team(N / 2, i);
	}
	cout << minTotal << endl;

	return 0;
}