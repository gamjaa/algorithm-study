## ����
p.168 https://algospot.com/judge/problem/read/CLOCKSYNC

![](https://algospot.com/media/judge-attachments/d3428bd7a9a425b85c9d3c042b674728/clocks.PNG)
�׸��� ���� 4 x 4 ���� ���� ���·� ��ġ�� 16���� �ð谡 �ִ�. �� �ð���� ��� 12��, 3��, 6��, Ȥ�� 9�ø� ����Ű�� �ִ�. �� �ð���� ��� 12�ø� ����Ű���� �ٲٰ� �ʹ�.

�ð��� �ð��� �����ϴ� ������ ����� ��� 10�� �ִ� ����ġ���� �����ϴ� ������, �� ����ġ���� ��� ���Դ� 3������ ���Դ� 5���� �ð迡 ����Ǿ� �ִ�. �� ����ġ�� ���� ������, �ش� ����ġ�� ����� �ð���� �ð��� 3�ð��� ������ �����δ�. ����ġ��� �׵��� ����� �ð���� ����� ������ ����.

0	0, 1, 2
1	3, 7, 9, 11
2	4, 10, 14, 15
3	0, 4, 5, 6, 7
4	6, 7, 8, 10, 12
5	0, 2, 14, 15
6	3, 14, 15
7	4, 5, 7, 14, 15
8	1, 2, 3, 4, 5
9	3, 4, 5, 9, 13

�ð���� �� ���ٺ���, ���ʿ��� ���������� ������� ��ȣ�� �Ű����ٰ� ��������. �ð���� ���� ����Ű�� �ð����� �־����� ��, ��� �ð踦 12�÷� ������ ���� �ּ��� ������ �� ����ġ�� ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

## �Է�
�ð������ ���ٺ���, ���ʿ��� ���������� ������� ��ȣ�� �Ű����ٰ� ��������. �ð���� ���� ����Ű�� �ð����� �־����� ��, ��� �ð踦 12�÷� ������ ���� �ּ��� ������ �� ����ġ�� ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

## ���
�� �׽�Ʈ ���̽��� �� ���� ����Ѵ�. �ð���� ��� 12�÷� �������� ���� ������ �� ����ġ�� �ּ� ���� ����Ѵ�. ���� �̰��� �Ұ����� ��� -1 �� ����Ѵ�.

## �ڵ�
```cpp
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int BTN_COUNT = 10;
const vector<vector<int>> btn = {
	{ 0, 1, 2 },
	{ 3, 7, 9, 11 },
	{ 4, 10, 14, 15 },
	{ 0, 4, 5, 6, 7 },
	{ 6, 7, 8, 10, 12 },
	{ 0, 2, 14, 15 },
	{ 3, 14, 15 },
	{ 4, 5, 7, 14, 15 },
	{ 1, 2, 3, 4, 5 },
	{ 3, 4, 5, 9, 13 }
};

const int CLOCK_COUNT = 16;
int clocks[CLOCK_COUNT] = { 0, };

void btnClick(int btnNum) {
	for (int i = 0; i < btn[btnNum].size(); i++) {
		clocks[btn[btnNum][i]] = (clocks[btn[btnNum][i]] + 3 + 12) % 12;
	}	
}

//bool hasClock(int btnNum, int clockNum) {
//	return find(btn[btnNum].begin(), btn[btnNum].end(), clockNum) != btn[btnNum].end();
//}

bool isSuccess() {
	bool ok = true;
	for (int i = 0; i < CLOCK_COUNT; i++) {
		if (clocks[i] != 0) {
			ok = false;
			break;
		}
	}
	return ok;
}

int calc(int btnNum) {
	if (btnNum == BTN_COUNT)
		return isSuccess() ? 0 : 10000;

	int result = 10000;
	for (int i = 0; i < 4; i++) {
		result = min(result, i + calc(btnNum + 1));
		btnClick(btnNum);
	}

	return result;
}

int main()
{
	int testcase;
	cin >> testcase;

	for (int cycle = 0; cycle < testcase; cycle++) {
		for (int i = 0; i < CLOCK_COUNT; i++) {
			int time;
			cin >> time;
			if (time == 12)
				time = 0;
			clocks[i] = time;
		}

		int result = calc(0);
		if (result >= 10000) {
			result = -1;
		}
		cout << result << endl;
	}

    return 0;
}
```
- ������ ������ �߿����� ����
- �� ��ư�� 4�� ������ �� ���� �Ͱ� ����
- redeclared as different kind of symbol ����: ���̺귯���� �̸� �浹 �� �߻�