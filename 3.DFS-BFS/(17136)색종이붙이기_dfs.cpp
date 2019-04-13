#include<iostream>
#include<vector>
using namespace std;

int minColor = 987654321;

int map[10][10];
int visited[10][10] = { 0, };
int usedSize[6] = { 0, };
bool cannotuse = true;

void changeVisited(int x, int y, int size, int value)
{
	for (int i = x; i < x + size; i++)
	{
		for (int j = y; j < y + size; j++) {
			visited[i][j] = value;
		}
	}
	return;
}
bool isCan(int size, int x, int y)
{
	for (int i = x; i < x + size; i++)
	{
		for (int j = y; j < y + size; j++) {
			if (!map[i][j] || visited[i][j]) //0�� �ְų� �̹� ���̸� ���� ��
			{
				return false;
			}
		}
	}
	return true;
}
bool isFull() //��� ���� �����̸� �־����� Ȯ��
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++) {
			if (map[i][j] != visited[i][j]) {
				return  false;
			}
		}
	}
	return true;
}
void color(int usedNum, int paperSize)
{
	//��������

	//�̹� �ּҰ����� Ŀ�� ���
	if (usedNum >= minColor) return;
	//�� ���� ���
	if (usedSize[paperSize] > 5)return;
	if (isFull()) //��� ���� �����̸� �� ��� 
	{
		//�ּ� ������ ��뷮 ���
		if (usedNum < minColor)
			minColor = usedNum;
		cannotuse = false;

		return;
	}


	//��������
	//�ϳ��ϳ� ���鼭 ���̰� ������ ���� �ʰ� ������ �� �ִ��ڸ�����
	//����� 5~1�� �� ������.
	int i, j;
	bool find = false;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++) {
			if (map[i][j] && !visited[i][j]) {
				find = true;
				break;
				//���⼭ for���� ������ �ʿ䰡 ���°� ������ ��� ������ �� ó�� ���� �������� �κ���
				//��͸� ���鼭 ��� ���� �� �� �ִ� ���� �� ���� ������
				//���⼭�� ó������ 1�� ���� ���� ã�ư��� �ȴ�
				//�ű⼭ ����� 5~1�ΰ��� ��
			}
		}
		if (find)break;
	}
	//5~1����� Ȯ��
	for (int s = 5; s >0 ; s--)
	{
		//�� ������ �������� Ȯ��
		if (isCan(s, i, j)) {//�Ǹ� �ִ´� -> 5�� �ƾ����� 4,3,2,1�� �ȴ�. isCan�ȵ�������
			//�迭�̶� �� �� �־� ��� �� �� - dfs�� ���ƿ´�!
			changeVisited(i, j, s, 1);
			usedSize[s]++;//������� �ǹ�...!->5�̻������� �������ǿ��� �Ǵ�
			color(usedNum + 1, s); //�ڡڡڡ���Ϳ��� ���ƿ��鼭 visited�� ���� ���·� ���ƿ´�!! �ڡڡڡڡڡڡ�
			//�ٽ� ������ ����
			usedSize[s]--;//�Ⱦ��� �Ǵϱ�
			changeVisited(i, j, s, 0);//�湮 ���Ѱ� �Ǵϱ�

		}

	}



	return;
}
int main()
{

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			cin >> map[i][j];

	color(0, 0);
	if (cannotuse)
		cout << -1 << endl;
	else
		cout << minColor << endl;

	return 0;
}