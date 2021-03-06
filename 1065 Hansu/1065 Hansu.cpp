// 1065 Hansu.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int countHansu(int n) {
	if (n < 100)
		return n;

	int x = n;
	int a = x % 10;
	x /= 10;
	int b = x % 10;
	x /= 10;
	int d = a - b;

	while (x > 0) {
		if (b - x % 10 != d) {
			return countHansu(n - 1);
		}

		b = x % 10;
		x /= 10;
	}

	return 1 + countHansu(n - 1);
}

int main()
{
	int n;
	cin >> n;

	cout << countHansu(n) << endl;;

    return 0;
}

