#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

//�� ��Ϲ����� ���¸� �����Ѵ� -> �ð����/ �ݽð�����̸� ���ܼ� ȸ����Ų��.
vector<int> gear[5];//1~4���� ���, 0��°���� �ð�������� ���� �Ű���. ��, 12�� ������ �ε����� 0
int K;

void printGears()
{
	cout << "=========================" << endl;
	for (int i = 1; i<=4; i++) {
		for (int j = 0; j < 8; j++) {
			cout << gear[i][j];
		}
		cout << endl;
	}
}
int sumGear()
{
	int total = 0;
	for (int i = 1; i <= 4; i++) {
		if (gear[i][0] == 1) {
			total += (int)pow(2.0, (i - 1));
		}
	}
	return total;
}
void goNext(int index, int dir)//Ȯ���ϸ鼭 ����� �ȵǱ� �� Ȯ���� �� ���ܾ� �Ѵ�.
{
	if (dir == 1) {//�ð����
		int temp = gear[index][7];
		for (int i = 7; i >0; i--) {
			gear[index][i] = gear[index][i - 1];
		}
		gear[index][0] = temp;
	}
	else {//�ݽð����
		int temp = gear[index][0];
		for (int i = 0; i < 7; i++) {
			gear[index][i] = gear[index][i + 1];
		}
		gear[index][7] = temp;
	}
	return;
}
void rotation(int gearNum, int dir)
{
	int canRotate[4] = { 0, };//0�̸� ȸ�� �Ұ�
	//ȸ���� �������� ���� Ȯ���Ѵ�
	for (int i = 1; i < 4; i++) {
		if (gear[i][2] != gear[i + 1][6])//���� �ٸ� ���̾�� ȸ���� �����ϴ�.
			canRotate[i] = 1;
	}

	//���� - 2~6
	int nowDir = (-dir);
	for (int i = gearNum - 1; i > 0; i--) {
		//0�̸� ȸ���Ұ�
		if (canRotate[i] == 0)
			break;
		goNext(i, nowDir);
		nowDir = (-nowDir);//���� ��ȯ
	}
	
	//���� ȸ��
	goNext(gearNum, dir);

	//������ - 6~2
	nowDir = (-dir);
	for (int i = gearNum + 1; i <= 4; i++) {
		if (canRotate[i - 1] == 0)
			break;
		goNext(i, nowDir);
		nowDir = (-nowDir);//���� ��ȯ
	}
}
int main()
{
	/*
		ȸ�� �İ� �ƴ϶� ȸ�� �ϱ� ���� �� ���� �� ����
		���� ���� �ٸ��ٸ� �ݴ�������� ȸ���ϰ� �ȴ�.
	*/
	for (int i = 1; i <= 4; i++)
	{
		char input[9];
		cin >> input;
		for (int j = 0; j < 8; j++)
		{
			gear[i].push_back(input[j] - '0');
		}
	}
	cin >> K;
	for (int i = 0; i < K; i++) {
		int g, d;
		cin >> g >> d;
		rotation(g, d);
		//printGears();
	}
	cout << sumGear() << endl;

	return 0;
}