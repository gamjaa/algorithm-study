## 문제
p. 230 https://algospot.com/judge/problem/read/LIS

어떤 정수 수열에서 0개 이상의 숫자를 지우면 이 수열의 부분 수열 (subsequence) 를 얻을 수 있다. 예를 들어 10 7 4 9 의 부분 수열에는 7 4 9, 10 4, 10 9 등이 있다. 단, 10 4 7 은 원래 수열의 순서와 다르므로 10 7 4 9 의 부분 수열이 아니다.

어떤 부분 수열이 순증가할 때 이 부분 수열을 증가 부분 수열 (increasing subsequence) 라고 한다. 주어진 수열의 증가 부분 수열 중 가장 긴 것의 길이를 계산하는 프로그램을 작성하라.

어떤 수열의 각 수가 이전의 수보다 클 때, 이 수열을 순증가 한다고 한다.

## 입력
입력의 첫 줄에는 테스트 케이스의 수 C (<= 50) 가 주어진다. 각 테스트 케이스의 첫 줄에는 수열에 포함된 원소의 수 N (<= 500) 이 주어진다. 그 다음 줄에 수열이 N개의 정수가 주어진다. 각 정수는 1 이상 100,000 이하의 자연수이다.

## 출력
각 테스트케이스마다 한 줄씩, 주어진 수열의 가장 긴 증가 부분 수열의 길이를 출력한다.

## 코드
```cpp
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
```
- 뒤에서부터 계산해서 가장 큰 수를 찾는다.