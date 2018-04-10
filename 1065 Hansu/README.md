## 문제
https://www.acmicpc.net/problem/1065

어떤 양의 정수 X의 자리수가 등차수열을 이룬다면, 그 수를 한수라고 한다. 등차수열은 연속된 두 개의 수의 차이가 일정한 수열을 말한다. N이 주어졌을 때, 1보다 크거나 같고, N보다 작거나 같은 한수의 개수를 출력하는 프로그램을 작성하시오. 

## 입력
첫째 줄에 1,000보다 작거나 같은 자연수 N이 주어진다.

## 출력
첫째 줄에 1보다 크거나 같고, N보다 작거나 같은 한수의 개수를 출력한다.

## 코드
```cpp
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
```

- 문제가 설명하는 한수에 대한 개념을 이해한다면 어렵지 않게 풀 수 있는 문제이다.
- 주어진 수가 한수인지 판단해서 카운트 하도록 재귀함수를 사용해서 작성했다.