## 문제
p. 201 https://algospot.com/judge/problem/read/FANMEETING

가장 멤버가 많은 아이돌 그룹으로 기네스 북에 올라 있는 혼성 팝 그룹 하이퍼시니어가 데뷔 10주년 기념 팬 미팅을 개최했습니다. 팬 미팅의 한 순서로, 멤버들과 참가한 팬들이 포옹을 하는 행사를 갖기로 했습니다. 하이퍼시니어의 멤버들은 우선 무대에 일렬로 섭니다. 팬 미팅에 참가한 M명의 팬들은 줄을 서서 맨 오른쪽 멤버에서부터 시작해 한 명씩 왼쪽으로 움직이며 멤버들과 하나씩 포옹을 합니다. 모든 팬들은 동시에 한 명씩 움직입니다. 아래 그림은 행사 과정의 일부를 보여줍니다. a~d는 네 명의 하이퍼시니어 멤버들이고, 0~5는 여섯 명의 팬들입니다.

하지만 하이퍼시니어의 남성 멤버들이 남성 팬과 포옹하기가 민망하다고 여겨서, 남성 팬과는 포옹 대신 악수를 하기로 했습니다. 줄을 선 멤버들과 팬들의 성별이 각각 주어질 때 팬 미팅이 진행되는 과정에서 하이퍼시니어의 모든 멤버가 동시에 포옹을 하는 일이 몇 번이나 있는지 계산하는 프로그램을 작성하세요.

## 입력
첫 줄에 테스트 케이스의 개수 C (C≤20)가 주어집니다. 각 테스트 케이스는 멤버들의 성별과 팬들의 성별을 각각 나타내는 두 줄의 문자열로 구성되어 있습니다. 각 문자열은 왼쪽부터 오른쪽 순서대로 각 사람들의 성별을 나타냅니다.

M은 해당하는 사람이 남자, F는 해당하는 사람이 여자임을 나타냅니다. 멤버의 수와 팬의 수는 모두 1 이상 200,000 이하의 정수이며, 멤버의 수는 항상 팬의 수 이하입니다.

## 출력
각 테스트 케이스마다 한 줄에 모든 멤버들이 포옹을 하는 일이 몇 번이나 있는지 출력합니다.

## 코드
- 최초 작성한 코드: 타임아웃
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
- 교재 참고해 작성한 코드(Karatsuba)
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