#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

int map[51][51]; //��ġ
int N, M;
vector<int> home[102]; //ġŲ �Ÿ� ����, -1�ϰ�� ������ ��, index 0�� �ȳ���
vector<pair<int, int> > whereHome; //���� �ִ� ��ġ ���� (�׷���)
vector<pair<int, int> > whereChicken; //ġŲ���� �ִ� ��ġ ���� (�׷���)
vector<int> stack; //���� ����� �� ���� �� -> ġŲ�� ��ǥ�� �ƴ϶� ��ȣ ����
int chickenRoad = 9876543; //������ ġŲ�Ÿ�

void makeC(int loc)
{
	// ��������
	if (stack.size() == M) { //stack�� ũ�Ⱑ M�̸� ����
		/*
		for (int i = 0; i < stack.size(); i++) {
			printf("(%d)", stack[i]);
		}
		printf("\n===========\n\n");
		*/
		//���⼭ ġŲ�� �ּҰŸ� ����
		int totalmin = 0;
		for (int i = 0; i < whereHome.size(); i++) {
			int min = 99999;
			for (int j = 0; j < M; j++)
			{
				if (home[i][stack[j]] < min) {//i��° ���� stack[j]�� ġŲ�� �� �Ÿ�
					min = home[i][stack[j]];
				}
			}
			totalmin += min;
		}
		if (chickenRoad > totalmin)
			chickenRoad = totalmin;
			   
		stack.pop_back();
		return;
	}
	//��������
	for (int next = loc + 1; next < whereChicken.size(); next++)
	{
		//push
		stack.push_back(next);
		makeC(next);
	}

	stack.pop_back();

	return;
}
void chicken()
{
	//��-ġŲ�� �� ��� �Ÿ� ã��
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j] == 2)//ġŲ���̸� �Ÿ����
			{
				for (int h = 0; h < whereHome.size(); h++) {
					home[h].push_back(abs(whereHome[h].first - i) + abs(whereHome[h].second - j));
				}
			}
		}
	}

	/*
		�� ���� �ּ� ġŲ�Ÿ��� ���� -> ġŲ���� ���� <=M�̸� ����
		�ƴϸ� ���� �ּҰ� ��Ʈ�� ����Ѵ�.
	*/
	for (int next = 0; next < whereChicken.size(); next++) {
		stack.push_back(next);
		makeC(next);
	}
	cout << chickenRoad << endl;
	//printf("%d\n", chickenRoad);

	return;
}
int main()
{
	//input
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) //���̸� �����Ѵ�.
				whereHome.push_back({ i,j });
			else if (map[i][j] == 2)
				whereChicken.push_back({ i,j });
		}
	}
	chicken();

	return 0;
}