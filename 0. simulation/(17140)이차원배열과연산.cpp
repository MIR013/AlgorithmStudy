#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;
//배열쓰면 터지겠다.
int R, C;//배열 크기
//r,c는 값이 변경되므로 - 각 맞게 동기화 필요(0넣어주란 소리)
int input[9999][9999] = { 0 }; //이정도는 ㄱ ㅏ능

void printall()
{
	for (int i = 1; i <= R; i++) {
		for(int j=1;j<=C;j++){
			printf("%3d ", input[i][j]);
		}
		printf("\n");
	}
	printf("\n");

}
void sortR()
{
	int Cmax = C;
	//행을 쭉보면서 처릐(가로)
	for (int i = 1; i <= R; i++) {
		map<int, int> counts;//count값을 계산하기 위한 해시 생성
		for (int j = 1; j <= C; j++) {
			if (input[i][j] == 0) {
				continue;//0은 계산 안함!
			}
			if (counts.find(input[i][j]) == counts.end()) {
				//해시가 비어있을 경우
				counts[input[i][j]] = 1;
			}
			else {
				counts[input[i][j]] += 1;
			}
		}
		//소팅 (값:개수)니까 개수 -> 값 순으로 (벡터로 만든 뒤 사용)
		vector<pair<int, int> > vectorData;
		map<int, int>::iterator iter;
		for (iter = counts.begin(); iter != counts.end(); ++iter) {
			vectorData.emplace_back(make_pair(iter->second, iter->first)); //(개수, 값) 순서임
		}
		//소팅은 오름차순이 기준(개수는 오름차순 수도 오름차순)
		sort(vectorData.begin(), vectorData.end());
		//배열 재생성
		int index = 1;
		for (int k=0; k < vectorData.size(); k++) {
			input[i][index++] = vectorData[k].second;
			input[i][index++] = vectorData[k].first;
		}
		//크기가 줄어든 경우 뒷 부분은 0으로 변경한다.
		for (; index <= C; index++) {
			input[i][index] = 0;
		}
		//전체 길이는 마지막에 변화해야 한다.
		if (vectorData.size()*2 > Cmax) {
			Cmax = vectorData.size()*2;
		}
	}
	C = Cmax;

	return;
}
void sortC()
{
	int Rmax = R;
	//행을 쭉보면서 처릐(가로)
	for (int i = 1; i <= C; i++) {
		map<int, int> counts;//count값을 계산하기 위한 해시 생성
		for (int j = 1; j <= R; j++) {
			if (input[j][i] == 0) {
				continue;//0은 계산 안함!
			}
			if (counts.find(input[j][i]) == counts.end()) {
				//해시가 비어있을 경우
				counts[input[j][i]] = 1;
			}
			else {
				counts[input[j][i]] += 1;
			}
		}
		//소팅 (값:개수)니까 개수 -> 값 순으로 (벡터로 만든 뒤 사용)
		vector<pair<int, int> > vectorData;
		map<int, int>::iterator iter;
		for (iter = counts.begin(); iter != counts.end(); ++iter) {
			vectorData.emplace_back(make_pair(iter->second, iter->first)); //(개수, 값) 순서임
		}
		//소팅은 오름차순이 기준(개수는 오름차순 수도 오름차순)
		sort(vectorData.begin(), vectorData.end());
		//배열 재생성
		int index = 1;
		for (int k = 0; k < vectorData.size(); k++) {
			input[index++][i] = vectorData[k].second;
			input[index++][i] = vectorData[k].first;
		}
		//크기가 줄어든 경우 뒷 부분은 0으로 변경한다.
		for (; index <= R; index++) {
			input[index][i] = 0;
		}
		//전체 길이는 마지막에 변화해야 한다.
		if (vectorData.size() * 2 > Rmax) {
			Rmax = vectorData.size() * 2;
		}
	}
	R = Rmax;
	return;
}
int main()
{
	int r, c, k;
	int time = 0;
	cin >> r >> c >> k;
	
	/*
	최대 갯수의 2배로 커질 수 있다. 
	배열 최대 크기: 2147483647 -> 이차원이면 46300정도
	*/

	for (int i = 1; i < 4; i++) {
		for (int j = 1; j < 4; j++) {
			cin >> input[i][j];
		}
	}
	R = 3; C = 3;

	while (input[r][c] != k)
	{
		if (time > 100) {
			time = -1;
			break;
		}
		//행이 더 길다
		if (R >= C) {
			sortR();
		}
		else {
			//열이 더 길다
			sortC();
		}
		//printall();
		time++;
	}

	cout << time << endl;

	return 0;
}