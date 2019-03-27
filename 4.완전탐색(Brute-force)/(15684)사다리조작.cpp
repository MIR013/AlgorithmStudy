#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>

using namespace std;

int laber[35][15] = { 0, }; //�׵θ� �˻��ϱ�!!
int N, H, M;
vector<pair<int, int> > candy; //��ٸ��� ���� �� �ִ� �� (b�� ���μ�-b+1�� ���μ� a��° ��ġ)
int len = 0;//candy�� ��ü ��
vector<int> stack; //���� ��ٸ� index! -> candy�� index
bool findMin = false; //�ּҰŸ� ã���� ���

void printlaber()
{
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= N; j++) {
			printf("%d ", laber[i][j]);
		}
		printf("\n");
	}
	printf("=====================\n");
}
bool simLaber(int(*testLaber)[15])
{
	for (int i = 1; i <= N; i++)
	{
		int now = i;
		for (int j = 1; j <= H; j++) {
			if (testLaber[j][now])//1�� ��� ��,�� Ȯ��
			{
				if (testLaber[j][now]==1)//�������� �̵�
				{
					now -= 1;
				}
				else if (testLaber[j][now]==2) {//���������� �̵�
					now += 1;
				}
				else {
					cout << "error!" << endl;
				}
			}
		}
		//i��° ��ٸ��� �����Դ��� Ȯ��
		if (i != now) { //�ϳ��� ���� ���� �ȳ��� �°� �ִٸ� �ٷ� �����ϰ� -1
			return false;
		}
	}
	return true;//�� ������ ���� �ðŴϱ� 1
}
void choiceLab(int num, int check)
{
	//��ٸ� ���� ����� ��... num�� ����


	//��������
	if (findMin) {
		return; //�̹� ã�����Ƿ� �� ���ϰ� return
	}
	if (stack.size() == num) {//stack�� ���� ������ �־�� �ϴ� ������ ���ٸ� ����
		//���⼭ �ùķ��̼� ������ �� ��..
		int temp[35][15] = { 0, };
		for (int i = 1; i <= H; i++) { //��ٸ� �ű��
			for (int j = 1; j <= N; j++) {
				temp[i][j] = laber[i][j];
			}
		}

		//�߰��� ��ٸ� �׸���
		for (int i = 0; i < stack.size(); i++)
		{
			//����Ǿ������� pop & return �ƴϸ� �׸���
			int nowx = candy[stack[i]].first;
			int nowy = candy[stack[i]].second;
			if (!temp[nowx][nowy] && (nowy+1<=N))//�׵θ�! ->�� �� �Ѵ� 0�̾�� ��ٸ� �̾��� �ϳ��� 1�� �ƴϸ� �ű� ���� �ִٴ� ��
			{
				if(!temp[nowx][nowy+1])
					temp[nowx][nowy] = 2; temp[nowx][nowy + 1] = 1; //��ٸ� �߰�
			}
			else {
				//�� ��� ����Ǿ� ������ �� ����� ���� ����� �� ����
				stack.pop_back(); //�ϳ��� ����Ǿ� ������ �ȵ�
				return;
			}

		}
		//��ٸ� �ùķ��̼�
		if (simLaber(temp) == true)
		{
			findMin=true;
			cout << num << endl;
			return;
		}



		//�� �������� pop
		stack.pop_back();
		return;
	}

	//��������
	for (int i = check + 1; i < len; i++) {
		stack.push_back(i);//index����
		choiceLab(num, i); //��������
	}
	stack.pop_back(); //�׳� �������� �� �Ǿ pop
	return;
}
void manLaber()
{
	//��ٸ� �ù�(�׳� ���¼��� �Ǵ��� Ȯ���ϱ� ����) -> �������� �Ǵ� �ȵǸ� -1, �����ϸ� 1
	if (simLaber(laber) == true) {
		//�߰��� �ȳ��� �Ǵ� ���
		cout << 0 << endl;
		return;
	}
	//printlaber();

	//1~3���� ��ٸ� ���ư��� Ȯ��(�ù�) - �����ϸ� ������ Ż��
	int test;
	for (test = 1; test <= 3; test++) {//��ٸ� �߰� ����: test
		//��ٸ� ���� (2,3���� ���ӵȰ� ���ö� ����)
		len = candy.size();

		//DFS����
		for (int c = 0; c < len; c++) {
			if (findMin) return; //�߰��� ���� ���� ��� �̹� ����Ʈ ������ ����
			stack.push_back(c);
			choiceLab(test, c); //(����), ���� ��,Ƚ��
		}

	}
	//4��°+�Ұ��� �̶�� -1
	if (test == 4) {
		cout << -1 << endl;
	}

	return;
}
int main()
{
	//input
	cin >> N >> M >> H;
	for (int i = 1; i <= M; i++)
	{
		int a, b;
		cin >> a >> b;
		//0:�Ʒ� 1:�������� �� �� ���� 2: ���������� �� �� ����
		laber[a][b] = 2; laber[a][b + 1] = 1; //�Է��� �׵θ� �������
	}
	//��ٸ��� ���� �� �ִ� �� ���
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= N; j++) {//������(j+1)�� ���� �ȴ�. �׵θ� ����
			if (!laber[i][j] && (j + 1 <= N))//�׵θ��� �����ʰ� 0�� ��-> ������� ���� �͸� ����
			{
				if (!laber[i][j + 1])//0�̸� �� �� �ִ� ��
				{
					candy.push_back(make_pair(i, j));
				}
			}
		}
	}

	manLaber();

	return 0;
}