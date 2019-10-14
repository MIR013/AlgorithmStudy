#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int N, M;//Å©±â, ¹ÙÀÌ·¯½º °³¼ö
int input[51][51];
int dirx[4] = { -1,0,1,0 };//»ó,¿ì,ÇÏ,ÁÂ
int diry[4] = { 0,1,0,-1 };

void printAll(int map[][51])
{
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			printf("%2d ", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	return;
}
int checkMap(int map[][51])
{
	int max_val = -1;
	//ÀüºÎ ÆÛÁö´Âµ¥ °É¸®´Â ½Ã°£(ÃÖ´ë °ª)
	//¾ÈµÇ¸é -1
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (input[i][j] == 2) {
				continue;
			}
			int temp = map[i][j];
			if (temp == -3) {
				return -1;
			}
			if (temp > max_val) {
				max_val = map[i][j];
			}
		}
	}
	return max_val;
}
int spreadVirus(vector<pair<int, int> > cases)
{
	queue<pair<int, int> > nextV;//¹ÙÀÌ·¯½º À§Ä¡¸¦ ÀúÀåÇÒ °÷!
	int map[51][51];
	int visited[51][51] = { 0 }; //¹æ¹® ¿©ºÎ¸¦ È®ÀÎÇÏÀÚ!
	int max_val = -1;
	//bfs¸¦ ÀÌ¿ëÇÏ¿© ¹ÙÀÌ·¯½º¸¦ ÆÛ¶ß¸®ÀÚ!!!!!

	//ÃÊ±âÈ­
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			map[i][j] = input[i][j];
		}
	}
	for (int i = 0; i < cases.size(); i++) {
		nextV.push(cases[i]);
		map[cases[i].first][cases[i].second] = 0;
		visited[cases[i].first][cases[i].second] = 1;
	}

	//queue
	while (!nextV.empty()) {
		pair<int, int> nextPos = nextV.front();

		//4¹æÇâ - º®ÀÎÁö, ¸ÊÀ» ÃÊ°úÇÏ´ÂÁö È®ÀÎ, ºñÈ°¼º ¹ÙÀÌ·¯½º´Â °¥ ÇÊ¿ä ŸÁ´Ù.
		for (int dir = 0; dir < 4; dir++)
		{
			int nextx = nextPos.first + dirx[dir];
			int nexty = nextPos.second + diry[dir];

			//¸ÊÃÊ°ú
			if (nextx <= 0 || nextx > N || nexty <= 0 || nexty > N)
				continue;
			//º®
			if (map[nextx][nexty] == -1)
				continue;

			if (!visited[nextx][nexty]) {
				//Áõ°¡ÇÏ±â!
				map[nextx][nexty] = map[nextPos.first][nextPos.second] + 1;

				//Ãß°¡
				nextV.push(make_pair(nextx, nexty));
				visited[nextx][nexty] = 1;
			}

		}

		nextV.pop();
	}

	int result = checkMap(map);
	//printAll(map);
	//printf("=====================\n");

	return result;
}
int main()
{
	/*
		//½Ã°£ ¸Å¿ì ÂªÀ½ - ¾Ë°í¸®Áò
		0: ºóÄ­ 1:º® 2:¹ÙÀÌ·¯½º ³õÀ» ¼ö ÀÖ´Â À§Ä¡
		¹ÙÀÌ·¯½º ³õÀ» ¼ö ¯z´Â ÃÖ´ë °æ¿ìÀÇ ¼ö 10Cm -> 10¹ø
		=> permutationÀÌ¿ë + bfs!!

		¹ÙÀÌ·¯½º ³õ±â -> ¹ÙÀÌ·¯½º ÆÛ¶ß¸± ¼ö ÀÖ´Â ½Ã°£ °è»ê -> ÃÖ¼Ò ºñ±³

		permutation: À§Ä¡ 5°³ Áß ¹ÙÀÌ·¯½º 3°³
		123,124,125,234,235,345 ¿ä·¸°Ô -> Áßº¹ ¾øÀ¸´Ï Á¶ÇÕ!
		Á¶ÇÕÀº 0°ú1ÀÌ ÀÖ´Â ¹è¿­À» ÀÌ¿ëÇØ ¼ø¿­À» ¸¸µé¾î ÁÖ¸é µÈ´Ù!

		ÆíÀÇ¸¦ À§ÇØ ¹ÙÀÌ·¯½º´Â -2, º®Àº -1, ºóÄ­Àº -3À¸·Î Ç¥ÇöÇÑ´Ù.

	*/
	int time = 0, vNum = 0;//½Ã°£, ÃÑ ¹ÙÀÌ·¯½º °³¼ö
	int min_val = 999999999;//ÃÖ¼Ò°ª
	bool min_true = false;//ÃÖ¼Ò¸¦ ±¸ÇÒ ¼ö ÀÖ´Â°¡?
	vector<int> perm;
	vector<pair<int, int> > cases; //¹ÙÀÌ·¯½º ³õÀ» °æ¿ìÀÇ ¼öÀÇ À§Ä¡

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> input[i][j];
			if (input[i][j] == 2) {
				cases.push_back(make_pair(i, j));
				vNum++;
				input[i][j] = -2;
			}
			else if (input[i][j] == 1) {
				input[i][j] = -1;
			}
			else {
				input[i][j] = -3;
			}
		}
	}
	//permutationÀ¸·Î Á¶ÇÕ ±¸ÇöÇÏ±â
	//À» À§ÇÑ °ª ÃÊ±âÈ­
	for (int i = 0; i < M; i++)
		perm.push_back(1);
	for (int i = M; i < vNum; i++)
		perm.push_back(0);
	sort(perm.begin(), perm.end());//¾ÈÇÏ¸é 11100ÀÌ¶ó ³¡³³´Ï´ç! - ¿©±ä ²À ÇØÁà¾ßÇÔ

	do {
		vector<pair<int, int> > nextCase;
		for (int i = 0; i < vNum; i++) {
			if (perm[i] == 1) {
				nextCase.push_back(make_pair(cases[i].first, cases[i].second));
			}
		}
		int result = spreadVirus(nextCase);

		if (result < min_val && result != -1) {
			min_val = result;
			min_true = true;
		}

	} while (next_permutation(perm.begin(), perm.end()));

	if (min_true) {
		cout << min_val << endl;
	}
	else {
		cout << -1 << endl;
	}

	return 0;
}