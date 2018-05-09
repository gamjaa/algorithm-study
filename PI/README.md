## 문제
p. 239 https://algospot.com/judge/problem/read/PI

가끔 TV 에 보면 원주율을 몇만 자리까지 줄줄 외우는 신동들이 등장하곤 합니다. 이들이 이 수를 외우기 위해 사용하는 방법 중 하나로, 숫자를 몇 자리 이상 끊어 외우는 것이 있습니다. 이들은 숫자를 세 자리에서 다섯 자리까지로 끊어서 외우는데, 가능하면 55555 나 123 같이 외우기 쉬운 조각들이 많이 등장하는 방법을 택하곤 합니다.

이 때, 각 조각들의 난이도는 다음과 같이 정해집니다:

1. 모든 숫자가 같을 때 (예: 333, 5555) 난이도: 1
2. 숫자가 1씩 단조 증가하거나 단조 감소할 때 (예: 23456, 3210) 난이도: 2
3. 두 개의 숫자가 번갈아 가며 출현할 때 (예: 323, 54545) 난이도: 4
4. 숫자가 등차 수열을 이룰 때 (예: 147, 8642) 난이도: 5
5. 그 외의 경우 난이도: 10

원주율의 일부가 입력으로 주어질 때, 난이도의 합을 최소화하도록 숫자들을 3자리에서 5자리까지 끊어 읽고 싶습니다. 최소의 난이도를 계산하는 프로그램을 작성하세요.

## 입력
입력의 첫 줄에는 테스트 케이스의 수 C (<= 50) 가 주어집니다. 각 테스트 케이스는 8글자 이상 10000글자 이하의 숫자로 주어집니다.

## 출력
각 테스트 케이스마다 한 줄에 최소의 난이도를 출력합니다.

## 코드
```cpp
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
```
- 교재와 별다른 차이가 없어보이는데 시간 초과. 더 살펴볼 것