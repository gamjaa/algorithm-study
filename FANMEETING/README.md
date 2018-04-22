## ����
p. 201 https://algospot.com/judge/problem/read/FANMEETING

���� ����� ���� ���̵� �׷����� ��׽� �Ͽ� �ö� �ִ� ȥ�� �� �׷� �����۽ôϾ ���� 10�ֳ� ��� �� ������ �����߽��ϴ�. �� ������ �� ������, ������ ������ �ҵ��� ������ �ϴ� ��縦 ����� �߽��ϴ�. �����۽ôϾ��� ������� �켱 ���뿡 �Ϸķ� ���ϴ�. �� ���ÿ� ������ M���� �ҵ��� ���� ���� �� ������ ����������� ������ �� �� �������� �����̸� ������ �ϳ��� ������ �մϴ�. ��� �ҵ��� ���ÿ� �� �� �����Դϴ�. �Ʒ� �׸��� ��� ������ �Ϻθ� �����ݴϴ�. a~d�� �� ���� �����۽ôϾ� ������̰�, 0~5�� ���� ���� �ҵ��Դϴ�.

������ �����۽ôϾ��� ���� ������� ���� �Ұ� �����ϱⰡ �θ��ϴٰ� ���ܼ�, ���� �Ұ��� ���� ��� �Ǽ��� �ϱ�� �߽��ϴ�. ���� �� ������ �ҵ��� ������ ���� �־��� �� �� ������ ����Ǵ� �������� �����۽ôϾ��� ��� ����� ���ÿ� ������ �ϴ� ���� �� ���̳� �ִ��� ����ϴ� ���α׷��� �ۼ��ϼ���.

## �Է�
ù �ٿ� �׽�Ʈ ���̽��� ���� C (C��20)�� �־����ϴ�. �� �׽�Ʈ ���̽��� ������� ������ �ҵ��� ������ ���� ��Ÿ���� �� ���� ���ڿ��� �����Ǿ� �ֽ��ϴ�. �� ���ڿ��� ���ʺ��� ������ ������� �� ������� ������ ��Ÿ���ϴ�.

M�� �ش��ϴ� ����� ����, F�� �ش��ϴ� ����� �������� ��Ÿ���ϴ�. ����� ���� ���� ���� ��� 1 �̻� 200,000 ������ �����̸�, ����� ���� �׻� ���� �� �����Դϴ�.

## ���
�� �׽�Ʈ ���̽����� �� �ٿ� ��� ������� ������ �ϴ� ���� �� ���̳� �ִ��� ����մϴ�.

## �ڵ�
- ���� �ۼ��� �ڵ�: Ÿ�Ӿƿ�
```cpp
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

bool check(char* members, char* fans, int fansIndex, vector<int>& maleMembers) {
	for (int i = 0; i < maleMembers.size(); i++) {
		if (fans[fansIndex + maleMembers[i]] == 'M')
			return false;
	}
	return true;
}

int solve(char* members, char* fans, int maxCount) {
	int membersCount = strlen(members);
	vector<int> maleMembers;	
	for (int i = 0; i < membersCount; i++) {
		if (members[i] == 'M')
			maleMembers.push_back(i);
	}
	
	int result = 0;
	for (int i = 0; i < maxCount; i++) {
		if (check(members, fans, i, maleMembers)) {
			result++;
		}
	}
	return result;
}

int main(int argc, char* argv[]) {
	int testcase;
	cin >> testcase;
	
	for (int times = 0; times < testcase; times++) {
		char members[200000];
		char fans[200000];
		cin >> members;
		cin >> fans;
		int maxCount = strlen(fans) - strlen(members) + 1;
		cout << solve(members, fans, maxCount) << endl;
	}
	
	return 0;
}
```
- ���� ������ �ۼ��� �ڵ�(Karatsuba)
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void addTo(vector<int>& a, const vector<int>& b, int k) {
	a.resize(max(a.size(), b.size() + k));
	for (int i = 0; i < b.size(); i++) {
		a[i + k] += b[i];
	}
}

void subFrom(vector<int>& a, const vector<int>& b) {
	for (int i = 0; i < b.size(); i++) {
		a[i] -= b[i];
	}
}

vector<int> multiply(const vector<int>& a, const vector<int>& b) {
	vector<int> c(a.size() + b.size() + 1, 0);
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b.size(); j++) {
			c[i + j] += a[i] * b[j];
		}
	}
	return c;
}

vector<int> karatsuba(const vector<int>& a, const vector<int>& b) {
	int an = a.size(), bn = b.size();
	if (an < bn)
		return karatsuba(b, a);

	if (an == 0 || bn == 0)
		return vector<int>();

	if (an <= 50)
		return multiply(a, b);

	int half = an / 2;
	vector<int> a0(a.begin(), a.begin() + half);
	vector<int> a1(a.begin() + half, a.end());
	vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));
	vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());

	vector<int> z2 = karatsuba(a1, b1);
	vector<int> z0 = karatsuba(a0, b0);
	addTo(a0, a1, 0);
	addTo(b0, b1, 0);
	vector<int> z1 = karatsuba(a0, b0);
	subFrom(z1, z0);
	subFrom(z1, z2);

	vector<int> ret;
	addTo(ret, z0, 0);
	addTo(ret, z1, half);
	addTo(ret, z2, half + half);
	return ret;
}

int solve(const string& members, const string& fans) {
	int N = members.size(), M = fans.size();
	vector<int> A(N), B(M);
	for (int i = 0; i < N; i++)
		A[i] = (members[i] == 'M');
	for (int i = 0; i < M; i++)
		B[M-i-1] = (fans[i] == 'M');

	vector<int> C = karatsuba(A, B);
	int count = 0;
	for (int i = N - 1; i < M; i++)
		if (C[i] == 0)
			count++;

	return count;
}

int main()
{
	int testcase;
	cin >> testcase;

	for (int times = 0; times < testcase; times++) {
		string members, fans;
		cin >> members;
		cin >> fans;
		cout << solve(members, fans) << endl;
	}

	return 0;
}
```