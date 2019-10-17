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
	//집당 치킨거리를 구하고 전체적인 최소 치킨거리를 구한다.
	int total = 0;

	//집 당 치킨거리를 파악해보자!
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
		N이 2~50, M이 1~13이니까
		최대 50C13이면 미텼는데...?

		조합구하라고 하는것 같은데... 아 시간내 가능한건가...?
		100만당 1초정도..
	*/
	vector<int> numOfChicken;
	vector<pair<int, int> > locationOfChicken;
	int minDistance = 999999999;
	//입력
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

	//조합구하고 치킨거리계산 ㄱㄱ
	for (int i = 0; i < M; i++) {
		numOfChicken[i] = 1;//로 변경!!
	}
	sort(numOfChicken.begin(), numOfChicken.end());
	do {
		//조합계산
		vector<pair<int, int> > chicken;
		for (int i = 0; i < numOfChicken.size();i++) {
			if (numOfChicken[i] == 1) {
				chicken.push_back(locationOfChicken[i]);
			}
		}
		//이 조합에 따라 치킨거리 계산
		int minVal = chickenRoute(chicken);
		if (minDistance > minVal) minDistance = minVal;

		//print(chicken);
		//printf("%d\n================\n", minVal);


	} while (next_permutation(numOfChicken.begin(), numOfChicken.end()));

	cout << minDistance << endl;

	return 0;
}