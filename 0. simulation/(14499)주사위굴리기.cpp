#include<iostream>
#include<vector>
using namespace std;

int N, M;
int map[20][20];
int dirx[5] = { -1000,0,0,-1,1 };//��=1,��,��,��
int diry[5] = { -1000,1,-1,0,0 };
//�ֻ����� ��ȣ ��: ���������� ���⿡ ���� �����ְų� �ϸ� �ȴ�.
int dice[7] = { 0, };//��=1,��,����,��,��,�Ʒ�
pair<int, int> now;//���� �ֻ��� ��ġ

void changeNum(int diceIndex,int x,int y)
{
	if (!map[x][y]) {//ĭ�� 0�� ���
		map[x][y] = dice[diceIndex];
	}
	else {
		dice[diceIndex] = map[x][y];
		map[x][y] = 0;
	}
	return;
}
bool moveDice(int dir)
{
	int temp1,temp2;

	//�ֻ��� ���� ��ġ �ű��
	int nextx = now.first + dirx[dir];
	int nexty = now.second + diry[dir];
	//�׵θ� ���̸� ����
	if (nextx < 0 || nextx >= N || nexty < 0 || nexty >= M) {
		return false;
	}
	now.first = nextx; now.second = nexty;

	//������ �ֻ��� �� ���� dice[1]�� ����� �Ѵ� �ݵ��
	//�� ���⿡ �°� �� �ٲٱ�!
	switch (dir)
	{
	case 1: //��
		//�ֻ��� ������(���ٲٱ�)
		temp1 = dice[1];//�� ����
		temp2 = dice[3];//�� ����

		dice[1] = dice[4];//��->��
		dice[3] = temp1;//��->��
		dice[4] = dice[6];//�Ʒ�->��
		dice[6] = temp2;//��->�Ʒ�
		break;
	case 2: //��
		temp1 = dice[4];//�� ����
		temp2 = dice[6];//�Ʒ� ����

		dice[4] = dice[1];
		dice[6] = temp1;
		dice[1] = dice[3];
		dice[3] = temp2;
		break;
	case 3: //��
		temp1 = dice[5];//�� ����
		temp2 = dice[6];//�Ʒ� ����

		dice[5] = dice[1];
		dice[6] = temp1;
		dice[1] = dice[2];
		dice[2] = temp2;
		break;
	case 4: //��
		temp1 = dice[2];//�� ����
		temp2 = dice[6];//�Ʒ� ����

		dice[2] = dice[1];
		dice[6] = temp1;
		dice[1] = dice[5];
		dice[5] = temp2;
		break;
	default:
		break;
	}

	//ĭ�� �� �ű��
	changeNum(6, nextx, nexty);

	return true;
}
int main()
{
	int order;
	cin >> N >> M >> now.first >> now.second >> order;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];

	for (int time = 0; time < order; time++)
	{
		int dir;
		cin >> dir;
		if(moveDice(dir))//���϶���!
			cout << dice[1] << endl;//�ֻ��� �� �� ���
	}

	return 0;
}