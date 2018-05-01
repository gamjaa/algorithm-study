## ����
p. 226 https://algospot.com/judge/problem/read/TRIANGLEPATH

```
6
1  2
3  7  4
9  4  1  7
2  7  5  9  4
```
�� ���¿� ���� �ﰢ�� ������� ��ġ�� �ڿ������� �ֽ��ϴ�. �� ���� ���ڿ��� ������, �� ���� �� ĭ�� �Ʒ��� ������ �� �Ʒ� �ٷ� �������� ��θ� ������� �մϴ�. ��δ� �Ʒ� �ٷ� ������ ������ �ٷ� �Ʒ� ����, Ȥ�� ������ �Ʒ� ���ڷ� ������ �� �ֽ��ϴ�. �� �� ��� ��� �� ���Ե� ������ �ִ� ���� ã�� ���α׷��� �ۼ��ϼ���.

## �Է�
�Է��� ù �ٿ��� �׽�Ʈ ���̽��� �� C(C <= 50)�� �־����ϴ�. �� �׽�Ʈ ���̽��� ù �ٿ��� �ﰢ���� ũ�� n(2 <= n <= 100)�� �־�����, �� �� n�ٿ��� �� 1��~n���� ���ڷ� �ﰢ�� �� �����ٿ� �ִ� ���ڰ� ���ʺ��� �־����ϴ�. �� ���ڴ� 1 �̻� 100000 ������ �ڿ����Դϴ�.

## ���
�� �׽�Ʈ ���̽����� �� �ٿ� �ִ� ����� ���� ���� ����մϴ�.

## �ڵ�
```cpp
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
```