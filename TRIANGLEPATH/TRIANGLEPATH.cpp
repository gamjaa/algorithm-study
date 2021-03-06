// TRIANGLEPATH.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int game[100][100];
int cache[100][100];
int N;

int solve(int y, int x) {
	if (y >= N)
		return 0;

	int& ret = cache[y][x];
	if (ret > 0) {
		return ret;
	}

	ret += game[y][x];

	return ret += max(solve(y + 1, x), solve(y + 1, x + 1));
}

int main()
{
	int C;
	cin >> C;

	for (int c = 0; c < C; c++) {
		cin >> N;
		memset(game, 0, sizeof(int) * 100 * 100);
		memset(cache, 0, sizeof(int) * 100 * 100);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < i + 1; j++) {
				cin >> game[i][j];
			}
		}

		cout << solve(0, 0) << endl;
	}

    return 0;
}