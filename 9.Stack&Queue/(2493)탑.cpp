#include<algorithm>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

int findRecept(int value, vector<int> buildings,int start)//송신하는 탑 높이, 탑, 시작할 인덱스
{
	for (int i = start; i >= 0; i--) {
		if (buildings[i] >= value) { //높은데 걸리면 돌자
			return i;//1부터 시작해서..
		}
	}
	//높은데 안걸렸을 경우
	return -1;
}
int main()
{
	int n;
	vector<int> communication;
	vector<pair<int,int> > stack; //[건물번호, 높이]
	cin >> n;
	for (int i = 0; i < n; i++) {
		int data;
		cin >> data;
		communication.push_back(data);
	}
	/*
		stack: 내 앞에 나보다 큰 건물들의 모임
		스택에 추가할때, 나보다 작으면 pop하고
						 나보다 크면 내 앞의 건물로 송신됨 그 후 push
		스택에 아무 내용이 없다면, 내 앞에 큰게 없다는 뜻
	
		스택은 o(n)은 반드시 돌아야 한다.
	*/
	for (int i = 0; i < n; i++) {
		//스택 확인
		if (stack.empty()) {
			printf("%d ", 0);
			stack.push_back(make_pair(i+1, communication[i]));
		}
		else {
			//나와 값 비교
			int value = communication[i];
			//pop하기 - top보다 크면
			while (!stack.empty()) {//다 pop되서 비면 여기서 걸림
				if (value <= stack.back().second) {
					break;
				}
				stack.pop_back();
			}
			//출력
			if (stack.empty()) {
				printf("%d ", 0);
			}
			else {
				printf("%d ", stack.back().first);
			}
			//넣기
			stack.push_back(make_pair(i + 1, value));
		}
	}



	return 0;
}