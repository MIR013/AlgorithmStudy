#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
int A[12];//���ڸ� ����
vector<int> operation; //PLUS=0,MINUS=1,MUL=2,DIV=3 
int totalMin = 1000000001;
int totalMax = -1000000001; //�ִ밡 -���� ���� �� ������ ����

void theOperator() //���� ����� �� ���ϱ�(������ ����� ���� �ٸ�!! ��� ���� ���´�)
{
	do {
		int cal = A[0];//�� ó�� ���� �־�д�
		for (int i = 1; i < N; i++) {//�������� ��� �� ����
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

		//�ִ� �ּ� ���
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
		������ ������ �����ϰ� �տ��� ���� ���ʷ� ����� ��
		�������� �� ���� ��, ������ ��� ���� ���� ������ �Ѵ�.
		���� ����� �ִ�, �ּ��� ���� ���϶�
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