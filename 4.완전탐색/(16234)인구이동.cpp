#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, R, L;
int map[51][51]; //�α��� ����!
//������ �ֵ��� ���� �ѹ������� �������� -> ���� �ִ¾�, ���ʿ� �ִ¾� ����
int united[51][51];
int moving; //��ü �α� �̵� ��
bool isMoving;

void printmap()
{
	printf("\nmap\n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	printf("\nunited\n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", united[i][j]);
		}
		printf("\n");
	}
	printf("----------------\n");
}
void virus(int x, int y)
{
	// x->y�� �ٲ۴�. ���� ������ ������ ����..
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (united[i][j] == x)
				united[i][j] = y;
		}
	}
	return;
}
void move()
{
	do {
		isMoving = false;
		pair<int, int > newunited[3000] = { {0,0}, }; // ���տձ��� �� �α� �ο��� ���� �迭 (�� ���� �α���,���� ����)
		//�α��̵� ����
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				//������, �Ʒ��� ���� ���� �ʳ�?
				//��,�� �Ⱥ��� ��ø x
				int checkRx, checkRy;
				//������ Ȯ�� - ���ձ��� ��� skip
				checkRx = i; checkRy = j + 1;
				//out of range Ȯ��
				if (checkRy < N) {
					if (united[checkRx][checkRy] != united[i][j]) {
						//�ٸ� ������ ��� ���� �������� ����
						int people = abs((map[i][j] - map[checkRx][checkRy]));
						if (people >= L && people <= R)
						{
							//�� ���� 
							if (united[checkRx][checkRy] != (checkRx*N + checkRy)) {//���� ������ �ƴѵ� ���� �ٲ� ��� ����
								virus(united[checkRx][checkRy], united[i][j]);
							}
							united[checkRx][checkRy] = united[i][j];
							isMoving = true;
						}
					}
				}

				//�Ʒ��� Ȯ�� - ���ձ��� ��� skip
				int checkDx, checkDy;
				checkDx = i + 1; checkDy = j;
				//out of range Ȯ��
				if (checkDx < N) {
					if (united[checkDx][checkDy] != united[i][j]) {
						//�ٸ� ������ ��� ���� �������� ����
						int people = abs((map[i][j] - map[checkDx][checkDy]));
						if (people >= L && people <= R)
						{
							//�� ���� 
							if (united[checkDx][checkDy] != (checkDx*N + checkDy)) {//���� ������ �ƴѵ� ���� �ٲ� ��� ����
								virus(united[checkDx][checkDy], united[i][j]);
							}
							united[checkDx][checkDy] = united[i][j];
							isMoving = true;
						}
					}
				}
			}
		}

		//�α� �̵� �� ���� ���� �α� �ٽ� ���
		//���� �ѹ��� �ֵ� -> �� �� ���ϰ� 
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				newunited[united[i][j]] = { newunited[united[i][j]].first + map[i][j],newunited[united[i][j]].second + 1 };
			}
		}

		//printf("%d %d\n", newunited[0].first, newunited[0].second);
		//printmap();

		//�� �ٽ� �ֱ� + ���� ����(�ʱ�ȭ)
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				map[i][j] = newunited[united[i][j]].first / newunited[united[i][j]].second;
				united[i][j] = N * i + j;
			}
		}

		moving += 1;
	} while (isMoving); //������ �̵��� �� ������ ����

	printf("%d", moving-1);
	return;
}
int main()
{
	//input
	scanf("%d %d %d", &N, &L, &R);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			united[i][j] = N * i + j;
		}
	}

	//move
	move();

	return 0;
}