#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
pair<int, int> input[16]; //�ɸ��� �ð�, �Ϸ�� �޴� ��
bool isFull[16] = { false, };//�ش� ĭ�� ã���� Ȯ��
vector<int> result;//������ ���� index ����
int maxMoney = -1;//�ִ� ��

void scheduling(int day)//��¥
{
	//��������
	if (day+input[day].first>=N+1) { //day�� �� �� �� ���� -> ����
		if (day + input[day].first == N + 1) {//n�Ͽ� �� ���缭 ������ ���
			result.push_back(input[day].second);//���ֱ�
		}

		//�ִ� �ּ� ��
		int sum = 0;
		for (int i = 0; i < result.size(); i++)
		{
			sum += result[i];
		}
		if (sum > maxMoney)
			maxMoney = sum;

		if (day + input[day].first == N + 1) {//n�Ͽ� �� ���缭 ������ ���
			result.pop_back();
		}
		return;
	}


	//��������
	result.push_back(input[day].second);//���ֱ�
	for (int i = day + input[day].first; i <= N; i++) {//������ �������� �� �� �ִ°� �� �����Ѵ�.
		scheduling(i);//�ϴ� �Ǵ� �ȵǴ� ���� �������ǿ��� Ȯ��
	}


	result.pop_back();
	return;
}
int main()
{
	/*
		���ǿ� �´� ����� �� ������ ��� ���ϸ� �� ��
		(1,3,7...)eks whgkqdml rotnsms tkdrhksdl djqtdmsk
	*/
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> input[i].first >> input[i].second; // �ɸ��� �� ��, �޴� ��
	}
	
	for (int i = 1; i <= N; i++) {
		scheduling(i);
	}


	cout << maxMoney << endl;

	return 0;
}