#include<iostream>
#include<stdio.h>

using namespace std;

//ť���
char front_cube[10] = { 'r', };
char back_cube[10] = { 'o', };
char up_cube[10] = { 'w', };
char down_cube[10] = { 'y', };
char left_cube[10] = { 'g', };
char right_cube[10] = { 'b', };

/*
			u1 u2 u3
			u4 u5 u6
			u7 u8 u9
  l1 l2 l3  f1 f2 f3  r1 r2 r3  b1 b2 b3
  l4 l5 l6  f4 f5 f6  r4 r5 r6  b4 b5 b6
  l7 l8 l9  f7 f8 f9  r7 r8 r9  b7 b8 b9
			d1 d2 d3
			d4 d5 d6
			d7 d8 d9

*/

void trunmain(char *target, int rotate)
{
	if (!rotate)//0�̸� �ݽð�
	{
		char dump[2];
		dump[0] = target[1]; dump[1] = target[2];
		target[1] = target[3]; target[2] = target[6];
		target[3] = target[9]; target[6] = target[8];
		target[8] = target[4]; target[9] = target[7];
		target[7] = dump[0]; target[4] = dump[1];

	}
	else { //1�̸� �ð�
		char dump[2];
		dump[0] = target[1]; dump[1] = target[2];
		target[1] = target[7]; target[2] = target[4];
		target[4] = target[8]; target[7] = target[9];
		target[8] = target[6]; target[9] = target[3];
		target[3] = dump[0]; target[6] = dump[1];
	}

	return;
}
int main()
{
	int testcase;

	scanf("%d", &testcase);
	for (int t = 0; t < testcase; t++) {

		int windNum; // ť�� ȸ�� Ƚ��

		 //ť�� �ʱ�ȭ
		for (int i = 1; i <= 9; i++) {
			front_cube[i] = 'r'; back_cube[i] = 'o';
			up_cube[i] = 'w'; down_cube[i] = 'y';
			left_cube[i] = 'g'; right_cube[i] = 'b';

		}

		scanf("%d", &windNum);
		for (int w = 0; w < windNum; w++) {
			char rotate[3]; //ť�� ȸ���ϴ� ���� 0:��, 1:����, 2:\0
			cin >> rotate;
			//ť�� ������ - �� �Ӹ��ƴ϶� �ڱ��ڽ� �鵵 ���ư�;;;;;
			if (rotate[0] == 'F') {
				if (rotate[1] == '+') { //�ð����
					char dump[3];
					dump[0] = up_cube[7]; dump[1] = up_cube[8]; dump[2] = up_cube[9];
					up_cube[7] = left_cube[9]; up_cube[8] = left_cube[6]; up_cube[9] = left_cube[3];
					left_cube[3] = down_cube[1]; left_cube[6] = down_cube[2]; left_cube[9] = down_cube[3];
					down_cube[1] = right_cube[7]; down_cube[2] = right_cube[4]; down_cube[3] = right_cube[1];
					right_cube[1] = dump[0]; right_cube[4] = dump[1]; right_cube[7] = dump[2];
					//frount�� ������
					trunmain(front_cube, 1);
				}
				else { // �ݽð����
					char dump[3];
					dump[0] = up_cube[7]; dump[1] = up_cube[8]; dump[2] = up_cube[9];
					up_cube[7] = right_cube[1]; up_cube[8] = right_cube[4]; up_cube[9] = right_cube[7];
					right_cube[1] = down_cube[3]; right_cube[4] = down_cube[2]; right_cube[7] = down_cube[1];
					down_cube[1] = left_cube[3]; down_cube[2] = left_cube[6]; down_cube[3] = left_cube[9];
					left_cube[9] = dump[0]; left_cube[6] = dump[1]; left_cube[3] = dump[2];
					//frount�� ������
					trunmain(front_cube, 0);

				}
			}
			else if (rotate[0] == 'B') {
				if (rotate[1] == '+') { //�ð����
					char dump[3];
					dump[0] = up_cube[3]; dump[1] = up_cube[2]; dump[2] = up_cube[1];
					up_cube[1] = right_cube[3]; up_cube[2] = right_cube[6]; up_cube[3] = right_cube[9];
					right_cube[3] = down_cube[9]; right_cube[6] = down_cube[8]; right_cube[9] = down_cube[7];
					down_cube[7] = left_cube[1]; down_cube[8] = left_cube[4]; down_cube[9] = left_cube[7];
					left_cube[1] = dump[0]; left_cube[4] = dump[1]; left_cube[7] = dump[2];

					trunmain(back_cube, 1);

				}
				else { // �ݽð����
					char dump[3];
					dump[0] = up_cube[1]; dump[1] = up_cube[2]; dump[2] = up_cube[3];
					up_cube[1] = left_cube[7]; up_cube[2] = left_cube[4]; up_cube[3] = left_cube[1];
					left_cube[1] = down_cube[7]; left_cube[4] = down_cube[8]; left_cube[7] = down_cube[9];
					down_cube[7] = right_cube[9]; down_cube[8] = right_cube[6]; down_cube[9] = right_cube[3];
					right_cube[3] = dump[0]; right_cube[6] = dump[1]; right_cube[9] = dump[2];

					trunmain(back_cube, 0);
				}
			}
			else if (rotate[0] == 'U') {
				if (rotate[1] == '+') { //�ð����
					char dump[3];
					dump[0] = front_cube[1]; dump[1] = front_cube[2]; dump[2] = front_cube[3];
					front_cube[1] = right_cube[1]; front_cube[2] = right_cube[2]; front_cube[3] = right_cube[3];
					right_cube[1] = back_cube[1]; right_cube[2] = back_cube[2]; right_cube[3] = back_cube[3];
					back_cube[1] = left_cube[1]; back_cube[2] = left_cube[2]; back_cube[3] = left_cube[3];
					left_cube[1] = dump[0]; left_cube[2] = dump[1]; left_cube[3] = dump[2];

					trunmain(up_cube, 1);
				}
				else { // �ݽð����
					char dump[3];
					dump[0] = front_cube[1]; dump[1] = front_cube[2]; dump[2] = front_cube[3];
					front_cube[1] = left_cube[1]; front_cube[2] = left_cube[2]; front_cube[3] = left_cube[3];
					left_cube[1] = back_cube[1]; left_cube[2] = back_cube[2]; left_cube[3] = back_cube[3];
					back_cube[1] = right_cube[1]; back_cube[2] = right_cube[2]; back_cube[3] = right_cube[3];
					right_cube[1] = dump[0]; right_cube[2] = dump[1]; right_cube[3] = dump[2];

					trunmain(up_cube, 0);
				}
			}
			else if (rotate[0] == 'D') {
				if (rotate[1] == '+') { //�ð����
					char dump[3];
					dump[0] = front_cube[7]; dump[1] = front_cube[8]; dump[2] = front_cube[9];
					front_cube[7] = left_cube[7]; front_cube[8] = left_cube[8]; front_cube[9] = left_cube[9];
					left_cube[7] = back_cube[7]; left_cube[8] = back_cube[8]; left_cube[9] = back_cube[9];
					back_cube[7] = right_cube[7]; back_cube[8] = right_cube[8]; back_cube[9] = right_cube[9];
					right_cube[7] = dump[0]; right_cube[8] = dump[1]; right_cube[9] = dump[2];

					trunmain(down_cube, 1);
				}
				else { // �ݽð����
					char dump[3];
					dump[0] = front_cube[7]; dump[1] = front_cube[8]; dump[2] = front_cube[9];
					front_cube[7] = right_cube[7]; front_cube[8] = right_cube[8]; front_cube[9] = right_cube[9];
					right_cube[7] = back_cube[7]; right_cube[8] = back_cube[8]; right_cube[9] = back_cube[9];
					back_cube[7] = left_cube[7]; back_cube[8] = left_cube[8]; back_cube[9] = left_cube[9];
					left_cube[7] = dump[0]; left_cube[8] = dump[1]; left_cube[9] = dump[2];

					trunmain(down_cube, 0);
				}
			}
			else if (rotate[0] == 'L') {
				if (rotate[1] == '+') { //�ð����
					char dump[3];
					dump[0] = front_cube[1]; dump[1] = front_cube[4]; dump[2] = front_cube[7];
					front_cube[1] = up_cube[1]; front_cube[4] = up_cube[4]; front_cube[7] = up_cube[7];
					up_cube[1] = back_cube[9]; up_cube[4] = back_cube[6]; up_cube[7] = back_cube[3];
					back_cube[3] = down_cube[7]; back_cube[6] = down_cube[4]; back_cube[9] = down_cube[1];
					down_cube[1] = dump[0]; down_cube[4] = dump[1]; down_cube[7] = dump[2];

					trunmain(left_cube, 1);
				}
				else { // �ݽð����
					char dump[3];
					dump[0] = front_cube[1]; dump[1] = front_cube[4]; dump[2] = front_cube[7];
					front_cube[1] = down_cube[1]; front_cube[4] = down_cube[4]; front_cube[7] = down_cube[7];
					down_cube[1] = back_cube[9]; down_cube[4] = back_cube[6]; down_cube[7] = back_cube[3];
					back_cube[3] = up_cube[7]; back_cube[6] = up_cube[4]; back_cube[9] = up_cube[1];
					up_cube[1] = dump[0]; up_cube[4] = dump[1]; up_cube[7] = dump[2];

					trunmain(left_cube, 0);
				}
			}
			else if (rotate[0] == 'R') {
				if (rotate[1] == '+') { //�ð����
					char dump[3];
					dump[0] = front_cube[3]; dump[1] = front_cube[6]; dump[2] = front_cube[9];
					front_cube[3] = down_cube[3]; front_cube[6] = down_cube[6]; front_cube[9] = down_cube[9];
					down_cube[3] = back_cube[7]; down_cube[6] = back_cube[4]; down_cube[9] = back_cube[1];
					back_cube[1] = up_cube[9]; back_cube[4] = up_cube[6]; back_cube[7] = up_cube[3];
					up_cube[3] = dump[0]; up_cube[6] = dump[1]; up_cube[9] = dump[2];

					trunmain(right_cube, 1);
				}
				else { // �ݽð����
					char dump[3];
					dump[0] = front_cube[3]; dump[1] = front_cube[6]; dump[2] = front_cube[9];
					front_cube[3] = up_cube[3]; front_cube[6] = up_cube[6]; front_cube[9] = up_cube[9];
					up_cube[9] = back_cube[1]; up_cube[6] = back_cube[4]; up_cube[3] = back_cube[7];
					back_cube[1] = down_cube[9]; back_cube[4] = down_cube[6]; back_cube[7] = down_cube[3];
					down_cube[3] = dump[0]; down_cube[6] = dump[1]; down_cube[9] = dump[2];

					trunmain(right_cube, 0);
				}
			}

		}

		//���� ť�� ���
		for (int i = 1; i < 10; i++) {
			printf("%c", up_cube[i]);
			if (i % 3 == 0)
				printf("\n");
		}

	}

	return 0;
}