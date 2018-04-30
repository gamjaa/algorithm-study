## ����
p. 218 https://algospot.com/judge/problem/read/WILDCARD

���ϵ�ī��� �پ��� �ü������ ���� �̸��� �Ϻθ����� ���� �̸��� �����ϴ� ����̴�. ���ϵ�ī�� ���ڿ��� �Ϲ����� ���ϸ�� ������, * �� ? �� ���� Ư�� ���ڸ� �����Ѵ�.

���ϵ�ī�� ���ڿ��� �տ��� �� ���ھ� ���ϸ�� ���ؼ�, ��� ���ڰ� ��ġ���� �� �ش� ���ϵ�ī�� ���ڿ��� ���ϸ�� ��ġ�ȴٰ� ����. ��, ���ϵ�ī�� ���ڿ��� ���Ե� ? �� � ���ڿ� ���ص� ��ġ�Ѵٰ� �����ϸ�, * �� 0 ���� �̻��� � ���ڿ����� ��ġ�Ѵٰ� ����.

���� ��� ���ϵ� ī�� he?p �� ���ϸ� help ����, heap ���� ��ġ������, helpp ���� ��ġ���� �ʴ´�. ���ϵ� ī�� *p* �� ���ϸ� help ����, papa ���� ��ġ������, hello ���� ��ġ���� �ʴ´�.

���ϵ�ī�� ���ڿ��� �Բ� ���ϸ��� ������ �־��� ��, �� �� ��ġ�Ǵ� ���ϸ���� ã�Ƴ��� ���α׷��� �ۼ��Ͻÿ�.

## �Է�
�Է��� ù �ٿ��� �׽�Ʈ ���̽��� �� C (1 <= C <= 10) �� �־�����. �� �׽�Ʈ ���̽��� ù �ٿ��� ���ϵ�ī�� ���ڿ� W �� �־�����, �� ���� �ٿ��� ���ϸ��� �� N (1 <= N <= 50) �� �־�����. �� �� N �ٿ� �ϳ��� �� ���ϸ��� �־�����. ���ϸ��� ���� ���� ���ĺ� ��ҹ��ڿ� ���ڸ����� �̷���� ������, ���ϵ�ī��� �� �ܿ� * �� ? �� ���� �� �ִ�. ��� ���ڿ��� ���̴� 1 �̻� 100 �����̴�.

## ���
�� �׽�Ʈ ���̽����� �־��� ���ϵ�ī�忡 ��ġ�Ǵ� ���ϵ��� �̸��� �� �ٿ� �ϳ��� �ƽ�Ű �ڵ� ����(����, �빮��, �ҹ��� ��)��� ����Ѵ�.

## �ڵ�
```cpp
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

string W, F;
int cache[101][101];

int match(int w, int f) {
	int& ret = cache[w][f];
	if (ret != -1)
		return ret;

	while (f < F.size() && w < W.size() && (W[w] == '?' || W[w] == F[f])) {
		++w; 
		++f;
	}

	if (w == W.size())
		return ret = (f == F.size());

	if (W[w] == '*') {
		for (int i = 0; f + i <= F.size(); i++) {
			if (match(w + 1, f + i))
				return ret = 1;
		}
	}

	return ret = 0;
}

int main()
{
	int testcase;
	cin >> testcase;

	for (int times = 0; times < testcase; times++) {
		cin >> W;

		int N;	// ���ϸ� ����
		cin >> N;

		vector<string> answer;
		for (int i = 0; i < N; i++) {
			memset(cache, -1, 101 * 101 * sizeof(int));
			cin >> F;
			if (match(0, 0))
				answer.push_back(F);
		}
		sort(answer.begin(), answer.end());
		for (int i = 0; i < answer.size(); i++)
			cout << answer[i] << endl;
	}

	return 0;
}
```
- �ٷ� ����ϴ� ���� �ƴ϶�, �ƽ�Ű �ڵ� ������ ����ؾ� �ϴ� �Ϳ� ����