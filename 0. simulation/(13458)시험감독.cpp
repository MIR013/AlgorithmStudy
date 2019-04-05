#include<iostream>
#include<vector>
using namespace std;

int N;
vector<int> stu;//�� �濡�ִ� ������ ��
int B, C;//�Ѱ������� ������ �� �ִ� ������ ��, �ΰ������� ������ �� �ִ� ������ ��
long long supervisor = 0;//�ʿ��� �������� ��

void supervise()
{
	//������ �����忡 �Ѱ������� ���� 1�� �־�� �ϰ�, �ΰ������� ���� �� �־ �ȴ�.
	//�� ��� �� ������ 1�� + �ΰ����� ������ ����, �� ������ 2��... �Ұ���
	for (int i = 0; i < stu.size(); i++)
	{
		//������ ������ �� �� 1000000*1000000(b=1,c=1)
		//�� �������� ���� ���� X
		int check = stu[i] - B;
		supervisor++;//�ϴ� �� ������ ����.
		if (check <= 0)
			continue;

		// �� �������� Ŀ�� ���� ���
		double sub = (double)check / C;
		if (sub - (int)sub > 0) {//�Ҽ����� ������ ��� ������ +1 �ؾ��Ѵ�.
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