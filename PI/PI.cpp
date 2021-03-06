// PI.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

char str[10000];
int cache[10000];

int calc(int index, int length) {
	bool check = true;
	int different = str[index] - str[index + 1];
	for (int i = index + 2; i < index + length; i++) {
		if (different != str[i - 1] - str[i]) {
			check = false;
			break;
		}
	}
	if (check && different == 0) return 1;
	else if (check && (different == 1 || different == -1)) return 2;
	else if (check) return 5;

	check = true;
	for (int i = index + 2; i < index + length; i++) {
		if (str[i - 2] != str[i]) {
			check = false;
			break;
		}
	}
	if (check) return 4;

	return 10;
}

int solve(int index) {
	int& ret = cache[index];
	if (ret != -1)
		return ret;

	int d = 999999999;
	for (int i = 3; i <= 5; i++) {
		if (index + i >= 10000 || str[index + i - 1] == 0) {
			return d;
		}
		if (index + i == strlen(str)) {
			d = min(d, calc(index, i));
		} else {
			d = min(d, solve(index + i) + calc(index, i));
		}
	}

	return ret = d;
}

int main()
{
	int C;
	cin >> C;

	for (int c = 0; c < C; c++) {
		memset(str, 0, sizeof(char) * 10000);
		memset(cache, -1, sizeof(int) * 10000);

		cin >> str;

		cout << solve(0) << endl;
	}

	return 0;
}

