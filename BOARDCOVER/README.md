## ����
https://algospot.com/judge/problem/read/BOARDCOVER

![](https://algospot.com/media/judge-attachments/2b7bfee35cbec2f4e799bb011ac18f69/03.png)

H*W ũ���� �������� �ֽ��ϴ�. �������� ���� ĭ�� �� ĭ���� ������ ���� ����� �ϰ� �ִµ� �� �� ��� �� ĭ�� 3ĭ¥�� L�� ����� ������� ���� �ͽ��ϴ�. �� �� ��ϵ��� �����Ӱ� ȸ���ؼ� ���� �� ������, ���� ��ġ�ų�, ���� ĭ�� ���ų�, ������ ������ �������� �� �˴ϴ�. �� �׸��� �� �����ǰ� �̸� ���� ����� �����ݴϴ�.

�������� �־��� �� �̸� ���� ����� ���� ����ϴ� ���α׷��� �ۼ��ϼ���.

## �Է�
�Է��� ù �ٿ��� �׽�Ʈ ���̽��� �� C (C <= 30) �� �־����ϴ�. �� �׽�Ʈ ���̽��� ù �ٿ��� 2���� ���� H, W (1 <= H,W <= 20) �� �־����ϴ�. ���� H �ٿ� �� W ���ڷ� �������� ����� �־����ϴ�. # �� ���� ĭ, . �� �� ĭ�� ��Ÿ���ϴ�. �Է¿� �־����� �����ǿ� �ִ� �� ĭ�� ���� 50 �� ���� �ʽ��ϴ�. 

## ���
�� �ٿ� �ϳ��� �� ĭ�� ��� ���� ����� ���� ����մϴ�.

## �ڵ�
```cpp
#include <iostream>
#include <vector>
using namespace std;

const int coverType[4][3][2] = {
	{ {0, 0}, {1, 0}, {0, 1} },
	{ {0, 0}, {0, 1}, {1, 1} },
	{ {0, 0}, {1, 0}, {1, 1} },
	{ {0, 0}, {1, 0}, {1, -1} }
};

bool set(vector<vector<int>>& board, int y, int x, int type, int delta) {
	bool ok = true;

	for (int i = 0; i < 3; i++) {
		const int ny = y + coverType[type][i][0];
		const int nx = x + coverType[type][i][1];

		if (ny < 0 || ny >= board.size() || nx < 0 || nx >= board[0].size()) {
			ok = false;
		}
		else if ((board[ny][nx] += delta) > 1) {
			ok = false;
		}
	}

	return ok;
}

int cover(vector<vector<int>>& board) {
	int y = -1, x = -1;

	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			if (board[i][j] == 0) {
				y = i;
				x = j;
				break;
			}
		}
		if (y != -1) break;
	}

	if (y == -1) return 1;

	int ret = 0;
	for (int type = 0; type < 4; type++) {
		if (set(board, y, x, type, 1)) {
			ret += cover(board);
		}

		set(board, y, x, type, -1);
	}

	return ret;
}

int main()
{
	int cycle;
	cin >> cycle;

	for (int times = 0; times < cycle; times++) {
		int h, w;
		cin >> h >> w;

		vector<vector<int>> board;
		int count = 0;

		for (int i = 0; i < h; i++) {
			vector<int> sub;
			char c[21];
			cin >> c;
			for (int j = 0; j < w; j++) {
				if (c[j] == 0)
					break;
				else if (c[j] == '#')
					sub.push_back(1);
				else {
					sub.push_back(0);
					count++;
				}
			}
			board.push_back(sub);
		}

		if (count > 50) {
			cout << 0 << endl;
			return 0;
		}

		cout << cover(board) << endl;
	}

	return 0;
}
```
- ��Ÿ ����
- ������ �� ����