// CLOCKSYNC.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
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

