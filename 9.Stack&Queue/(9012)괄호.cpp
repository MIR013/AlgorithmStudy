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
	cin.ignore(256, '\n'); //���� ���� ����

	for (int i = 0; i < n; i++) {
		string bracket;
		string result;
		getline(cin, bracket);
		//cout << bracket << endl;
		//�� �������� ���������� �������� ����, �������� �� ������ ���� ������ 0�� �ƴϸ� ����
		//���� + ������ -
		int status = 0;
		for (int i = 0; i < bracket.size(); i++) {
			if (bracket[i] == '(') {
				status++;
			}
			else {
				status--;
			}
			//close �ѹ��̶� open���� Ŀ���� �� �ȵǴ� ����
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