#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

int N,M;
int map[51][51];

void print(vector<pair<int, int> > vec)
{
	vector<pair<int, int> >::iterator iter;
	for (iter = vec.begin(); iter != vec.end(); iter++)
	{
		printf("(%d %d) ", iter->first, iter->second);
	}
	printf("\n");
	return;
}
int chickenRoute(vector<pair<int, int> > loc)
{
	//���� ġŲ�Ÿ��� ���ϰ� ��ü���� �ּ� ġŲ�Ÿ��� ���Ѵ�.
	int total = 0;

	//�� �� ġŲ�Ÿ��� �ľ��غ���!
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j] == 1)
			{
				int minDistance = 999999;
				vector<pair<int, int> >::iterator iter;
				for (iter = loc.begin(); iter != loc.end(); iter++)
				{
					int dist = abs(i - iter->first) + abs(j - iter->second);
					if (minDistance > dist) minDistance = dist;
				}
				total += minDistance;
			}
		}
	}


	return total;
}
int main()
{
	/*
		N�� 2~50, M�� 1~13�̴ϱ�
		�ִ� 50C13�̸� ����µ�...?

		���ձ��϶�� �ϴ°� ������... �� �ð��� �����Ѱǰ�...?
		100���� 1������..
	*/
	vector<int> numOfChicken;
	vector<pair<int, int> > locationOfChicken;
	int minDistance = 999999999;
	//�Է�
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) 
			{ 
				numOfChicken.push_back(0);
				locationOfChicken.push_back(make_pair(i, j));
			}
		}
	}

	//���ձ��ϰ� ġŲ�Ÿ���� ����
	for (int i = 0; i < M; i++) {
		numOfChicken[i] = 1;//�� ����!!
	}
	sort(numOfChicken.begin(), numOfChicken.end());
	do {
		//���հ��
		vector<pair<int, int> > chicken;
		for (int i = 0; i < numOfChicken.size();i++) {
			if (numOfChicken[i] == 1) {
				chicken.push_back(locationOfChicken[i]);
			}
		}
		//�� ���տ� ���� ġŲ�Ÿ� ���
		int minVal = chickenRoute(chicken);
		if (minDistance > minVal) minDistance = minVal;

		//print(chicken);
		//printf("%d\n================\n", minVal);


	} while (next_permutation(numOfChicken.begin(), numOfChicken.end()));

	cout << minDistance << endl;

	return 0;
}