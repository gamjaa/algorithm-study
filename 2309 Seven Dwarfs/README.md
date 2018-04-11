## 문제
https://www.acmicpc.net/problem/2309

왕비를 피해 일곱 난쟁이들과 함께 평화롭게 생활하고 있던 백설공주에게 위기가 찾아왔다. 일과를 마치고 돌아온 난쟁이가 일곱 명이 아닌 아홉 명이었던 것이다.

아홉 명의 난쟁이는 모두 자신이 "백설 공주와 일곱 난쟁이"의 주인공이라고 주장했다. 뛰어난 수학적 직관력을 가지고 있던 백설공주는, 다행스럽게도 일곱 난쟁이의 키의 합이 100이 됨을 기억해 냈다.

아홉 난쟁이의 키가 주어졌을 때, 백설공주를 도와 일곱 난쟁이를 찾는 프로그램을 작성하시오.

## 입력
아홉 개의 줄에 걸쳐 일곱 난쟁이의 키가 주어진다. 주어지는 키는 100을 넘지 않는 자연수이며, 아홉 난쟁이의 키는 모두 다르며, 가능한 정답이 여러가지인 경우에는 아무거나 출력한다.

## 출력
일곱 난쟁이의 키를 오름차순으로 출력한다.

## 코드
```cpp
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
```
- 'algorithm' Header에 sort(시작주소, 끝주소)가 있다.