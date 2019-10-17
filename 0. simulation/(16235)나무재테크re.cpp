#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

int N, M, K;//�迭ũ��, ���� ���� ��, ���
int A[101][101];//�߰��� ��� ����
int energy[101][101];//���� �������
vector<int> tree[11][11]; //����� ���� ����, ���̸� ������.

void springSum()
{
	vector<int> liveTree[11][11];
	vector<int> deadTree[11][11];

	//������ ���õ� ä�� �־�� �Ѵ�.(���� �������� ��� ��� ��)
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (tree[i][j].size() > 1) {
				sort(tree[i][j].begin(), tree[i][j].end());
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			vector<int>::iterator iter;
			for (iter = tree[i][j].begin(); iter != tree[i][j].end(); iter++) {
				//�ƹ��͵� ������ �ȵ�����
				int age = *iter;
				if (energy[i][j] >= age) {//����� �� ������ �ش�.
					energy[i][j] -= age;
					liveTree[i][j].push_back(*iter + 1);
				}
				else {//���
					deadTree[i][j].push_back(age);
				}
			}

		}
	}
	//��Ƴ��� ������ ����
	swap(tree, liveTree);

	//����
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			vector<int>::iterator iter;
			for (iter = deadTree[i][j].begin(); iter != deadTree[i][j].end(); iter++) {
				energy[i][j] += int((*iter) / 2);
			}
		}
	}


	return;
}
void atum()
{
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			vector<int>::iterator iter;
			for (iter = tree[i][j].begin(); iter != tree[i][j].end(); iter++) {
				if (*iter % 5 == 0) {
					//���̰� 5�� ������ ����!
					for (int r = i - 1; r <= i + 1; r++) {
						for (int c = j - 1; c <= j + 1; c++) {
							if (r == i && c == j) continue; //�ڱ��ڽ�
							if (r <= 0 || r > N || c <= 0 || c > N) continue; //�ٱ�
							tree[r][c].push_back(1);//�����߰�
						}
					}

				}
			}
		}
	}
	return;
}
void wint()
{

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			energy[i][j] += A[i][j];//����߰�
		}
	}
	return;
}
int main()
{
	/*
		N�� 10 �����ΰ� ���ϱ�..
		M���� ����
		���� ó���� ����� 5�� ����
		����
		 > ��: �ڽ��� ���̸�ŭ ��� �Ա� + ���� 1 ����
		 (��ĭ�� ���� ������ ������ ���̰� � �������� ����� ����.
		 ��� �������� �ٷ� ���)
		 > ����: ���� ���� ������ ������� ��ȭ(������������/2), �Ҽ��� ����
		 > ����: 5�ǹ�� ������ ������ ������ 8���� ĭ�� ���̰� 1�� ���� ����
		 > �ܿ�: s2d2�� ��� �߰�(input���� �־���)

		K�� �� ������ ������?
	*/
	//�Է�
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
			energy[i][j] = 5;
		}
	}
	for (int i = 0; i < M; i++) {
		int r, c, age;
		cin >> r >> c >> age;
		tree[r][c].push_back(age);
	}

	//K�Ⱓ ����!
	while (K > 0) {
		//��+����
		springSum();
		//����
		atum();
		//�ܿ�
		wint();

		K--;
	}
	//����ִ� ���� ���� ���
	int result = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			vector<int>::iterator iter;
			for (iter = tree[i][j].begin(); iter != tree[i][j].end(); iter++) {
				result++;
			}
		}
	}
	cout << result << endl;

	return 0;
}