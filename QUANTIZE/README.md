## ����
p. 244 https://algospot.com/judge/problem/read/QUANTIZE

Quantization (����ȭ) ������, �� ���� ������ ���� ������ ���� ������ ���� ����� �ٻ��� ǥ�������ν� �ڷḦ �ս� �����ϴ� ������ ���Ѵ�. ���� ��� 16��Ʈ JPG ������ 4�÷� GIF ���Ϸ� ��ȯ�ϴ� ���� RGB �� ������ ������ 4�÷� ���� �ϳ��� ����ȭ�ϴ� ���̰�, Ű�� 161, 164, 170, 178 �� �л� ���� '160�� ��, 170�� ��' �̶�� ����� ǥ���ϴ� �� ���� ����ȭ��� �� �� �ִ�.

1000 ������ �ڿ������ ������ ������ �ִ� S���� �� ������ ����ϵ��� ����ȭ�ϰ� �ʹ�. �� �� ����ȭ�� ���ڴ� ���� ������ ���� ������ ���� �ִ�. ����ȭ�� �ϴ� ����� ���� ������ �ִ�. ���� 1 2 3 4 5 6 7 8 9 10 �� 2���� ���ڸ��� �Ἥ ǥ���Ϸ���, 3 3 3 3 3 7 7 7 7 7 �� ���� �� ���� �ְ�, 1 1 1 1 1 10 10 10 10 10 ���� �� ���� �ִ�. �츮�� �� ��, �� ���ں� ���� ������ ���� �ּ�ȭ�ϴ� ����ȭ ����� �˰� �ʹ�.

���� ���, ���� 1 2 3 4 5 �� 1 1 3 3 3 ���� ����ȭ�ϸ� ���� ������ ���� 0+1+0+1+4=6 �� �ǰ�, 2 2 2 4 4 �� ����ȭ�ϸ� ���� ������ ���� 1+0+1+0+1=3 �� �ȴ�.

������ S �� �־��� ��, ������ ���� ������ ���� �ּҰ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

## �Է�
�Է��� ù �ٿ��� �׽�Ʈ ���̽��� �� C (1 <= C <= 50) �� �־�����. �� �׽�Ʈ ���̽��� ù �ٿ��� ������ ���� N (1 <= N <= 100), ����� ������ �� S (1 <= S <= 10) �� �־�����. �� ���� �ٿ� N���� ������ ������ ���ڵ��� �־�����. ������ ��� ���� 1000 ������ �ڿ����̴�.

## ���
�� �׽�Ʈ ���̽�����, �־��� ������ �ִ� S ���� ���� ����ȭ�� �� ���� ������ ���� �ּҰ��� ����Ѵ�.

## �ڵ�
```cpp
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
```