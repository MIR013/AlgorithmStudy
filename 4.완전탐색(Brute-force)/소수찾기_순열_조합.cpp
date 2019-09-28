#include <string>
#include <vector>
#include <algorithm>
#include<math.h>
#include<sstream>
#include<stdio.h>
#include<iostream>
#include<set>

using namespace std;

set<int> result;//중복 값있는지 확인


bool isPrim(int n) {
	if (n <= 1) return false;
	if (n == 2) return true;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n%i == 0)
			return false;
	}
	return true;
}
void combination(string arr,int k) { //nCk로 n개 중 k개 뽑음 (중복x)
	vector<int> forComb;
	int length = arr.size();
	for (int i = 0; i < k; i++)
		forComb.push_back(1);
	for (int j = k; j < arr.size(); j++)
		forComb.push_back(0);
	//소팅
	sort(forComb.begin(), forComb.end());

	do {
		//1인 자리를 합치면 조합이 된다.
		string num;
		for (int i = 0; i < length; i++)
			if (forComb[i] == 1)
				num += arr[i];
		cout << num << endl;
	} while (next_permutation(forComb.begin(), forComb.end()));

}
void permutation(string arr, int k,vector<int> stack, vector<int> visited) { //nPk로 n개 중 k개 뽑음 (중복o)
	//자리수 k 당 경우의 수(index기준)
	//arr길이의 nPn은 next_permutation을 사용하면 된다.
	if (stack.size() >= k) {
		//자리 번호를 나타내는 거라서 만들어줘야함
		/*
		for (int i = 0; i < stack.size(); i++)
			printf("%d ", stack[i]);
		printf("\n");
		*/
		
		//소수판별
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
	permutation 사용법 익히기
	string <-> int 변환 익히기
	*/

	//자리수 당 perm
	int length = numbers.size();
	/*
		permutation의 경우 sort를 먼저 해줘야 한다!
		반복문 내에서 자료구조를 변환하면 안된다.
		조합을 구현하려면 [0,0,1,1,1]같은 리스트를 통해 index로 처리해 줘야 한다.
		근데 여긴 조합이 아니라 자리수 당 전체 경우의 수 이다.
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