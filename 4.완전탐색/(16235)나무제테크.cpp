//#include<stdio.h>
//#include<iostream>
//#include<queue>
//
//using namespace std;
//
//int N, M, K;
//int map[11][11]; //���� ����
//int s2d2[11][11]; //ä������ ���
//
//typedef struct tree {
//	//����ð��� �����Ѵٸ�?
//	int row;
//	int col;
//	int age; //����Ǿ��ִ°Ŷ� �����°� ������ �ٸ�...!
//};
//struct cmp {
//	bool operator()(tree t, tree u) {
//		return t.age > u.age;//��������
//	}
//};
//priority_queue<tree,vector<tree>,cmp> live; //����ִ� ���� ����
//
//
//void getmoney()
//{
//	//���� �ϳ��� ������� ������ ®�µ� �װ� �ƴ϶� ���� �������� ������ ��� ������;;
//	for (int time = 0; time < K; time++)
//	{
//		//pq�� �߰��� ������ �尬���ְ� �ǳ���
//		queue<tree> season; //����� �����鼭 ����ִ¾ֵ� ����
//		queue<tree> dead; //����� �����鼭 ���� �ֵ� ����
//
//		//�� �������� queue�� ���鼭 ������ ��� Ȯ���Ѵ�.
//		int checknum = live.size();
//		//��
//		for (int c = 0; c < checknum; c++)
//		{
//
//			tree check = live.top();
//			live.pop();
//			//��
//			if (map[check.row][check.col] - check.age >= 0) { //pq�� ���� ��ְ� ���� ���ϱ� ���� ����
//				map[check.row][check.col] -= check.age; //�ڱ� ���̸�ŭ ����� �԰�
//				check.age++;//���̰� 1����
//
//				//���׾����� �ٷ� ������ ���� - ����̶��� ������ ����
//				if (check.age % 5 == 0) {
//					//���̰� 5������� ������
//					for (int i = -1; i <= 1; i++) {
//						for (int j = -1; j <= 1; j++) {
//							if (i == 0 && j == 0) //������ ������ġ��
//								continue;
//							//��輱 üũ
//							if ((check.row + i) < 1 || (check.row + i) > N || (check.col + j) < 1 || (check.col + j) > N)
//								continue;
//							tree baby;
//							baby.row = check.row + i;
//							baby.col = check.col + j;
//							baby.age = 1;
//							season.push(baby); //���ο� ���� ���
//						}
//					}
//				}
//
//				season.push(check);//����ִ¾�
//			}
//			else {
//				//����� �����ϴ� - ����
//				dead.push(check);
//			}
//			
//		}
//		//pq�����
//		int slen = season.size();
//		for (int i = 0; i < slen; i++)
//		{
//			live.push(season.front());
//			season.pop();
//		}
//		
//
//		int dlen = dead.size();
//		//���� - ������ ����� ����
//		for (int c = 0; c < dlen; c++)
//		{
//			tree d = dead.front();
//			dead.pop();
//			map[d.row][d.col] += (d.age / 2); //�ڱ� ������ ������ �߰�
//		}
//		
//
//		//�ܿ� - ������ ��������� pq�Ⱦ�
//		for (int i = 1; i <= N; i++) { //��� �߰�
//			for (int j = 1; j <= N; j++) {
//				map[i][j] += s2d2[i][j];
//			}
//		}
//
//	}
//	//���� ������ ���� queue�� ��
//	cout << live.size();
//
//	return;
//}
//int main()
//{
//
//	cin >> N >> M >> K;
//	for (int i = 1; i <= N; i++) { //�迭 index 1���� ����
//		for (int j = 1; j <= N; j++) {
//			cin >> s2d2[i][j];//��� �ʱ�ȭ
//			map[i][j] = 5;//�� �ʱ�ȭ
//		}
//	}
//	//�����Է�
//	for (int i = 1; i <= M; i++) {
//		int x, y, z;
//		cin >> x >> y >> z;
//		tree init;
//		init.row = x; init.col = y;
//		init.age = z;
//		live.push(init);
//	}
//
//	getmoney();
//
//	return 0;
//}