#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
int map[17][17];
int totalNum = 0;
//����:0, ����:1, �׵θ�:2

int whatisit(int fx, int fy, int lx, int ly)
{
	int right = ly - fy;
	int down = lx - fx;
	if (right && down)
		return 2;
	else if (right)
		return 0;
	else
		return 1;
}
void movePipe(int fx, int fy, int lx, int ly)//���� �������� ��ġ�� �����Ѵ�.
{
	//��������
	if (lx == N && ly == N) { //�������� �������� ���� ������ �ȴ�.
		totalNum++;
		return;
	}

	//��������
	//���� �׵θ��� �ǵ����� �� ��
	switch (whatisit(fx, fy, lx, ly)) {
	case 0://����
		//���������� �б�
		if (map[lx][ly + 1] != 1 && ly + 1 <= N)
			movePipe(lx, ly, lx, ly + 1);
		//���������� ���ٰ� ȸ��
		if (map[lx][ly + 1] != 1 && map[lx + 1][ly + 1] != 1 && map[lx + 1][ly] != 1 && ly + 1 <= N && lx + 1 <= N)
			movePipe(lx, ly, lx + 1, ly + 1);
		break;
	case 1://����
		//�Ʒ��� �б�
		if (map[lx + 1][ly] != 1 && lx + 1 <= N)
			movePipe(lx, ly, lx + 1, ly);
		//�Ʒ��� ���ٰ� ȸ��
		if (map[lx + 1][ly] != 1 && map[lx][ly + 1] != 1 && map[lx + 1][ly + 1] != 1 && ly + 1 <= N && lx + 1 <= N)
			movePipe(lx, ly, lx + 1, ly + 1);
		break;
	case 2://�밢��
		//�밢������ ����
		if (map[lx + 1][ly] != 1 && map[lx][ly + 1] != 1 && map[lx + 1][ly + 1] != 1 && ly + 1 <= N && lx + 1 <= N)
			movePipe(lx, ly, lx + 1, ly + 1);
		//������
		if (map[lx][ly + 1] != 1 && ly + 1 <= N)
			movePipe(lx, ly, lx, ly + 1);
		//�Ʒ�
		if (map[lx + 1][ly] != 1 && lx + 1 <= N)
			movePipe(lx, ly, lx + 1, ly);

		break;
	default:
		cout << "error" << endl;
		break;
	}

	return;
}
int main()
{
	/*
		dfs�� ã�Ƽ� �����ϸ� Ƚ�� ������Ű�� �ǰڴ�
		��, visited�� ������� �ʴ´�!
		�Ϸķΰ��� ���� ���̴ϲ�
		x�� ���� y�� ������!! �򰥸��� �� ��
		�����ϴ� ���� ����
	*/

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	movePipe(1, 1, 1, 2);

	cout << totalNum << endl;

	return 0;
}