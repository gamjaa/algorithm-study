// 2309 Seven Dwarfs.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dwarfs[9];
int arr[7];
bool isEnd = false;

void pickDwarfs(int n, int sum, int index, vector<int>& picked) {
	if (isEnd) {
		return;
	}
	else if (n == 0 && sum == 100) {
		isEnd = true;
		sort(picked.begin(), picked.end());
		for (int i = 0; i < 7; i++) {
			cout << picked[i] << endl;
		}
		return;
	}
	else if (n == 0) {
		return;
	}

	for (int i = index; i < 9; i++) {
		if (sum + dwarfs[i] <= 100) {
			picked.push_back(dwarfs[i]);
			pickDwarfs(n - 1, sum + dwarfs[i], i + 1, picked);
			picked.pop_back();
		}
	}
	return;
}

int main()
{
	for (int i = 0; i < 9; i++) {
		cin >> dwarfs[i];
	}

	vector<int> picked;
	pickDwarfs(7, 0, 0, picked);

    return 0;
}

