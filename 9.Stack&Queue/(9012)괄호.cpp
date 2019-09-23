#include<algorithm>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<stdlib.h>
using namespace std;


int main() {

	int n;
	cin >> n;
	cin.ignore(256, '\n'); //엔터 버퍼 삭제

	for (int i = 0; i < n; i++) {
		string bracket;
		string result;
		getline(cin, bracket);
		//cout << bracket << endl;
		//연 개수보다 단은개수가 많아지면 오류, 마지막에 연 개수와 닫은 개수가 0이 아니면 오류
		//열면 + 닫으면 -
		int status = 0;
		for (int i = 0; i < bracket.size(); i++) {
			if (bracket[i] == '(') {
				status++;
			}
			else {
				status--;
			}
			//close 한번이라도 open보다 커지면 걍 안되는 것임
			if (status < 0) {
				result = "NO";
				break;
			}
		}
		if (status != 0) {
			result = "NO";
		}
		else {
			result = "YES";
		}

		cout << result << endl;
	}

	return 0;
}