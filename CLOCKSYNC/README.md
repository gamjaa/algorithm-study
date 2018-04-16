## 문제
p.168 https://algospot.com/judge/problem/read/CLOCKSYNC

![](https://algospot.com/media/judge-attachments/d3428bd7a9a425b85c9d3c042b674728/clocks.PNG)
그림과 같이 4 x 4 개의 격자 형태로 배치된 16개의 시계가 있다. 이 시계들은 모두 12시, 3시, 6시, 혹은 9시를 가리키고 있다. 이 시계들이 모두 12시를 가리키도록 바꾸고 싶다.

시계의 시간을 조작하는 유일한 방법은 모두 10개 있는 스위치들을 조작하는 것으로, 각 스위치들은 모두 적게는 3개에서 많게는 5개의 시계에 연결되어 있다. 한 스위치를 누를 때마다, 해당 스위치와 연결된 시계들의 시간은 3시간씩 앞으로 움직인다. 스위치들과 그들이 연결된 시계들의 목록은 다음과 같다.

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

시계들은 맨 윗줄부터, 왼쪽에서 오른쪽으로 순서대로 번호가 매겨졌다고 가정하자. 시계들이 현재 가리키는 시간들이 주어졌을 때, 모든 시계를 12시로 돌리기 위해 최소한 눌러야 할 스위치의 수를 계산하는 프로그램을 작성하시오.

## 입력
시계들은맨 윗줄부터, 왼쪽에서 오른쪽으로 순서대로 번호가 매겨졌다고 가정하자. 시계들이 현재 가리키는 시간들이 주어졌을 때, 모든 시계를 12시로 돌리기 위해 최소한 눌러야 할 스위치의 수를 계산하는 프로그램을 작성하시오.

## 출력
각 테스트 케이스당 한 줄을 출력한다. 시계들을 모두 12시로 돌려놓기 위해 눌러야 할 스위치의 최소 수를 출력한다. 만약 이것이 불가능할 경우 -1 을 출력한다.

## 코드
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
- 누르는 순서는 중요하지 않음
- 한 버튼을 4번 누르면 안 누른 것과 같음
- redeclared as different kind of symbol 에러: 라이브러리와 이름 충돌 시 발생