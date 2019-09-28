#include <string>
#include <vector>
#include <algorithm>
#include<math.h>
#include<sstream>
#include<stdio.h>
#include<iostream>
#include<set>

using namespace std;

set<int> result;//�ߺ� ���ִ��� Ȯ��


bool isPrim(int n) {
	if (n <= 1) return false;
	if (n == 2) return true;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n%i == 0)
			return false;
	}
	return true;
}
void combination(string arr,int k) { //nCk�� n�� �� k�� ���� (�ߺ�x)
	vector<int> forComb;
	int length = arr.size();
	for (int i = 0; i < k; i++)
		forComb.push_back(1);
	for (int j = k; j < arr.size(); j++)
		forComb.push_back(0);
	//����
	sort(forComb.begin(), forComb.end());

	do {
		//1�� �ڸ��� ��ġ�� ������ �ȴ�.
		string num;
		for (int i = 0; i < length; i++)
			if (forComb[i] == 1)
				num += arr[i];
		cout << num << endl;
	} while (next_permutation(forComb.begin(), forComb.end()));

}
void permutation(string arr, int k,vector<int> stack, vector<int> visited) { //nPk�� n�� �� k�� ���� (�ߺ�o)
	//�ڸ��� k �� ����� ��(index����)
	//arr������ nPn�� next_permutation�� ����ϸ� �ȴ�.
	if (stack.size() >= k) {
		//�ڸ� ��ȣ�� ��Ÿ���� �Ŷ� ����������
		/*
		for (int i = 0; i < stack.size(); i++)
			printf("%d ", stack[i]);
		printf("\n");
		*/
		
		//�Ҽ��Ǻ�
		string num;
		for (int i = 0; i < stack.size(); i++) {
			num += arr[stack[i]];
		}
		int num_val = stoi(num);
		printf("%d\n", num_val);
		if (isPrim(num_val)) {
			result.insert(num_val);
		}
		

		return;
	}

	for (int i = 0; i < arr.size(); i++) {
		if (!visited[i]) {
			visited[i] = 1;
			stack.push_back(i);
			permutation(arr, k, stack, visited);
			visited[i] = 0;
			stack.pop_back();
		}
	}


	return;
}
int solution(string numbers) {
	int answer = 0;

	/*
	permutation ���� ������
	string <-> int ��ȯ ������
	*/

	//�ڸ��� �� perm
	int length = numbers.size();
	/*
		permutation�� ��� sort�� ���� ����� �Ѵ�!
		�ݺ��� ������ �ڷᱸ���� ��ȯ�ϸ� �ȵȴ�.
		������ �����Ϸ��� [0,0,1,1,1]���� ����Ʈ�� ���� index�� ó���� ��� �Ѵ�.
		�ٵ� ���� ������ �ƴ϶� �ڸ��� �� ��ü ����� �� �̴�.
	*/


	vector<int> stack;
	vector<int> visited;
	for (int i = 0; i < length; i++) {
		visited.push_back(0);
	}
	for (int i = 1; i <= length; i++) {
		permutation(numbers, i, stack, visited);
	}

	answer = result.size();

	return answer;
}

int main()
{

	printf("%d\n",solution("0123456"));

	return 0;
}