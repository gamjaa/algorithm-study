## ����
p. 230 https://algospot.com/judge/problem/read/LIS

� ���� �������� 0�� �̻��� ���ڸ� ����� �� ������ �κ� ���� (subsequence) �� ���� �� �ִ�. ���� ��� 10 7 4 9 �� �κ� �������� 7 4 9, 10 4, 10 9 ���� �ִ�. ��, 10 4 7 �� ���� ������ ������ �ٸ��Ƿ� 10 7 4 9 �� �κ� ������ �ƴϴ�.

� �κ� ������ �������� �� �� �κ� ������ ���� �κ� ���� (increasing subsequence) ��� �Ѵ�. �־��� ������ ���� �κ� ���� �� ���� �� ���� ���̸� ����ϴ� ���α׷��� �ۼ��϶�.

� ������ �� ���� ������ ������ Ŭ ��, �� ������ ������ �Ѵٰ� �Ѵ�.

## �Է�
�Է��� ù �ٿ��� �׽�Ʈ ���̽��� �� C (<= 50) �� �־�����. �� �׽�Ʈ ���̽��� ù �ٿ��� ������ ���Ե� ������ �� N (<= 500) �� �־�����. �� ���� �ٿ� ������ N���� ������ �־�����. �� ������ 1 �̻� 100,000 ������ �ڿ����̴�.

## ���
�� �׽�Ʈ���̽����� �� �پ�, �־��� ������ ���� �� ���� �κ� ������ ���̸� ����Ѵ�.

## �ڵ�
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
	ret = 1;	// �ڱ� �ڽ�

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
- �ڿ������� ����ؼ� ���� ū ���� ã�´�.