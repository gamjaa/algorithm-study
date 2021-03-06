// LIS.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
int seq[500];
int cache[500];

int lis(int index) {
	int& ret = cache[index];
	ret = 1;	// 자기 자신

	int longest = 0;

	for (int i = index; i < N; i++) {
		if (seq[index] < seq[i]) {
			longest = max(longest, cache[i]);
		}
	}

	return ret += longest;
}

int solve() {
	int ret = 0;
	for (int i = N - 1; i >= 0; i--) {
		ret = max(lis(i), ret);
	}
	return ret;
}

int main()
{
	int C;
	cin >> C;

	for (int c = 0; c < C; c++) {
		cin >> N;
		
		memset(seq, 0, sizeof(int) * 500);
		memset(cache, 0, sizeof(int) * 500);

		for (int i = 0; i < N; i++) {
			cin >> seq[i];
		}

		cout << solve() << endl;
	}

    return 0;
}

