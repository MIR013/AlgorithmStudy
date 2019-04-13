#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

int N, M, D;
int map[16][16];
vector<pair<int, int> > enemy;
vector<int> stack; //arraw�� index�� ���� ���� ����!
int maxE = -1;



void findA(int index)
{
	//��������
	if (stack.size() == 3) {
		int total = 0;
		//�� �ü� �����϶�, ���� ��� ������������ �ݺ�!

		vector<pair<int, int> > temp_enemy;
		for (int i = 0; i < enemy.size(); i++)//swap
			temp_enemy.push_back(enemy[i]);
		while (!temp_enemy.empty())
		{
			//�ü��� ���� ���� �� ������ ���δ�. - ������ ����

			pair<int, int> candy[3] = { { 0,0 }, }; //�Ÿ�,index
			for (int i = 0; i < 3; i++)//�ü��� 3��
			{
				int arrowy = stack[i]; int arrowx = N;
				//���� �� �ִ� ��� ���� ���� ���� ������ > ���ʿ� �ִ°��� ���� ���δ�.
				for (int j = 0; j < temp_enemy.size(); j++)
				{ 
					int ex = temp_enemy[j].first;
					int ey = temp_enemy[j].second;
					int distance = abs(arrowx - ex) + abs(arrowy - ey);
					if (distance <= D) {
						if (candy[i].first==0)
							candy[i] = make_pair(distance, j);
						else {
							//�Ÿ��� ������ ����
							if (distance < candy[i].first) {
								candy[i] = make_pair(distance, j);
							}
							//�Ÿ��� ���� ���ʰŶ�� ����
							else if (distance == candy[i].first) {
								if (temp_enemy[j].second < temp_enemy[candy[i].second].second) {//y���� ���ؾ���
									//�� �� ���ʰŴ�
									candy[i] = make_pair(distance, j);
								}
								//���ų� ������ ���� ��� ����
							}
							//�Ÿ��� �ָ� ��� ����

						}
					}
				}

			}

			//�ü��� ���ÿ� ��ϱ�.. ��ֵ� ����
			int aliveIndex[999] = { 0, };
			for (int i = 0; i < 3; i++) {
				if(candy[i].first)
					aliveIndex[candy[i].second] = 1;
			}

			vector<pair<int, int> > temp2;
			int index = 0;
			for (int i = 0; i < temp_enemy.size(); i++) {
				if (!aliveIndex[i]) {
					temp2.push_back(temp_enemy[i]);
				}
				else {
					//���� �ֵ��� �ڸ�
					total++;
				}
			}
			temp_enemy.clear();
			for (int i = 0; i < temp2.size(); i++)//���� �� ����
				temp_enemy.push_back(temp2[i]);





			//���� �Ʒ��� �����δ�. - N+1�ΰ��� ����
			vector<pair<int, int> > temp;
			for (int i = 0; i < temp_enemy.size(); i++) {
				int nextx = temp_enemy[i].first + 1;
				int nexty = temp_enemy[i].second;
				if (nextx != N) {
					temp.push_back(make_pair(nextx, nexty));
				}
			}

			temp_enemy.clear();
			for (int i = 0; i < temp.size(); i++)//���� �� ����
				temp_enemy.push_back(temp[i]);


		}
		//�ִ� ����ȸ�� ��
		if (total > maxE)
			maxE = total;
			

		stack.pop_back();
		return;
	}

	//��������
	for (int i = index + 1; i < M; i++) {
		stack.push_back(i);
		findA(i);
	}

	//��
	stack.pop_back();
	return;
}
int main()
{
	/*
		������ �ϳ��� �� �� �ִ� ���� �ִ� ���� 1
		N+1���� ���� �ִ�.
		�ü� 3�� - ������ ��ġ ����, ��ĭ�� �ִ� 1��
					�Ÿ��� D ������ �� �� ����� �� ���� ����, ������ ���ʺ���
					���� ���� ���� �ü����� ���� �� ����
					���ݹ��� ���� out
					������ ������ ���� �Ʒ��� ��ĭ �̵��Ѵ�.
					������ �̵��� ��� ���ӿ���out
					��� ���� �������� ���� ����
		�Ÿ� = |r1-r2|+|c1-c2|
		�ü��� �������� ������ �� �ִ� ���� �ִ� ��
	*/
	cin >> N >> M >> D;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j])
				enemy.push_back(make_pair(i, j));
		}
	}


	//�������� �ü��� ��ġ�� ã��
	for (int i = 0; i < M; i++) {
		stack.push_back(i);
		findA(i);
	}

	cout << maxE << endl;


	return 0;
}