// QUANTIZE.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 987654321;

int N, S;
int A[101], pSum[101], pSqSum[101];

void preCalc() {
	sort(A, A + N);
	pSum[0] = A[0];
	pSqSum[0] = A[0] * A[0];

	for (int i = 1; i < N; i++) {
		pSum[i] = pSum[i - 1] + A[i];
		pSqSum[i] = pSqSum[i - 1] + A[i] * A[i];
	}
}

int minError(int lo, int hi) {
	int sum = pSum[hi] - (lo == 0 ? 0 : pSum[lo - 1]);
	int sqSum = pSqSum[hi] - (lo == 0 ? 0 : pSqSum[lo - 1]);

	int m = int(0.5 + (double)sum / (hi - lo + 1));

	int ret = sqSum - 2 * m * sum + m * m * (hi - lo + 1);
	return ret;
}

int cache[101][11];

int quantize(int from, int parts) {
	if (from == N) return 0;

	if (parts == 0) return INF;

	int& ret = cache[from][parts];
	if (ret != -1) return ret;

	for (int partSize = 1; from + partSize <= N; partSize++) {
		ret = min(ret, minError(from, from + partSize - 1) + quantize(from + partSize, parts - 1));
	}

	return ret;
}

int main()
{
	int C;
	cin >> C;

	for (int c = 0; c < C; c++) {
		cin >> N;
		cin >> S;

		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}

		memset(cache, -1, sizeof(int) * 101 * 11);
		preCalc();

		cout << quantize(0, N) << endl;
	}

	return 0;
}

