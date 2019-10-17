#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int map[101][101] = { 0, }; //���� ����, �巡�� Ŀ���� �� ���� -> ������ x,y�� ������ �ٸ�
int dirx[4] = { 1,0,-1,0 };
int diry[4] = { 0,-1,0,1 }; //�� �ݽð�� �ٲٰ� �̰� �׷���


int calSquare()
{
	int sq = 0;

	for (int i = 0; i <= 100; i++)
	{
		for (int j = 0; j <= 100; j++)
		{
			if (map[i][j])//���� 1�̸� üũ ����
			{
				//�׵θ� üũ
				if ((j + 1) <= 100 && map[i][j + 1]) {//������
					if ((i + 1) <= 100 && map[i + 1][j + 1]) {//������ �Ʒ�
						if (map[i + 1][j]) {//�Ʒ�
							//�� ������ �簢�� �ϼ�
							sq++;
						}
					}
				}

			}

		}
	}

	return sq; //�簢���� �� ��ȯ
}
void drangonCurve(int x, int  y, int  dir, int  gen)
{
	vector<int> dragon;//������ ������ ��

	//0���� ����
	int nextx, nexty;	//������ �� ����
	pair<int, int> flag = make_pair( x,y );//������ �� ����
	dragon.push_back(dir);
	nextx = x + dirx[dir]; nexty = y + diry[dir];
	//printf("(%d %d)\n", x, y);
	//printf("(%d %d)\n", nextx, nexty);
	map[x][y] = 1; map[nextx][nexty] = 1; // �� ����

	//1~gen���� ����
	for (int i = 1; i <= gen; i++)
	{
		int last = dragon.size();//��, ���� �ƴ϶� ���� ������ �� ��
		//�ð���� ȸ��(���Ϳ� ���� + ��ǥ�� ǥ��)
		for (int j = last - 1; j >= 0; j--) //������ �ͺ��� ȸ���ؼ� �߰��ؾ� �Ѵ�.
		{
			int nextdir;
			//90���� �ð�ȸ��
			/*
			if (!dragon[j])
				nextdir = 3;
			else
				nextdir = (dragon[j] - 1);
				*/
			nextdir = (dragon[j] + 1) % 4; //��x�� y�� �ٲ����Ƿ� �ݽð�
			nextx += dirx[nextdir]; nexty += diry[nextdir];

			//�׵θ� ������ üũ!!! -> ���̾�� �� �߰�
			if (nextx < 0 || nextx >100 || nexty < 0 || nexty>100)
				continue;
			else {//�׵θ� ���̴ϱ� �߰�!
				dragon.push_back(nextdir);
				map[nextx][nexty] = 1;
				//printf("(%d %d)\n", nextx, nexty);
			}
		}
		//printf("\n");
	}


	return;
}
int main()
{
	int N;

	cin >> N;
	for (int time = 0; time < N; time++)
	{
		//input
		int x, y, dir, gen;
		cin >> x >> y >> dir >> gen;
		//�巡�� Ŀ�� ����
		drangonCurve(x, y, dir, gen);
	}

	//�簢���� �� ���
	cout << calSquare();

	return 0;
}