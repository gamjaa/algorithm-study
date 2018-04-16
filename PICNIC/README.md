## ����
p.155 https://algospot.com/judge/problem/read/PICNIC

�ȵ�θ޴� ��ġ�� �ͽ��������ݿ����� ���� �ֿ� ������������ ��ǳ�� ���ϴ�. ���� �������� ��ǳ �� �л����� �� �� ¦�� ���� �ൿ�ϰ� �Ϸ��� �մϴ�. �׷��� ���� ģ���� �ƴ� �л��鳢�� ¦�� ���� �ָ� ���� �ο�ų� ���� ���ƴٴ��� �ʱ� ������, �׻� ���� ģ���� �л��鳢���� ¦�� ���� ��� �մϴ�.

�� �л����� �ֿ� ���� �̵��� ���� ģ������ ���ΰ� �־��� ��, �л����� ¦������ �� �ִ� ����� ���� ����ϴ� ���α׷��� �ۼ��ϼ���. ¦�� �Ǵ� �л����� �Ϻθ� �ٸ����� �ٸ� ����̶�� ���ϴ�. ���� ��� ���� �� ���� ����� ���� �ٸ� ����Դϴ�.

- (�¿�,����ī) (���,Ƽ�Ĵ�) (ȿ��,����)
- (�¿�,����ī) (���,����) (ȿ��,Ƽ�Ĵ�)

## �Է�
�Է��� ù �ٿ��� �׽�Ʈ ���̽��� �� C (C <= 50) �� �־����ϴ�. �� �׽�Ʈ ���̽��� ù �ٿ��� �л��� �� n (2 <= n <= 10) �� ģ�� ���� �� m (0 <= m <= n*(n-1)/2) �� �־����ϴ�. �� ���� �ٿ� m ���� ���� ������ ���� ģ���� �� �л��� ��ȣ�� �־����ϴ�. ��ȣ�� ��� 0 ���� n-1 ������ �����̰�, ���� ���� �Է¿� �� �� �־����� �ʽ��ϴ�. �л����� ���� ¦���Դϴ�.

## ���
�� �׽�Ʈ ���̽����� �� �ٿ� ��� �л��� ģ�������� ¦������ �� �ִ� ����� ���� ����մϴ�.

## �ڵ�
```cpp
#include <iostream>
#include <cstring>
using namespace std;
bool isFriends[10][10];

int countTeam(int start, int remain, bool student[10]) {
	if (remain == 0)
		return 1;

	int result = 0;
	for (int i = start; i < 10; i++) {
		if (!student[i]) {
			for (int j = i+1; j < 10; j++) {
				if (isFriends[i][j] && !student[i] && !student[j]) {
					student[i] = true;
					student[j] = true;
					result += countTeam(i, remain - 1, student);
					student[i] = false;
					student[j] = false;
				}
			}
		}
	}

	return result;
}

int main()
{
	int cycle;
	cin >> cycle;

	// �׽�Ʈ ���̽� �ݺ�
	for (int testCase = 0; testCase < cycle; testCase++) {
		memset(isFriends, false, 100);

		// �л� ��, ģ�� ��
		int studentCount, friendsCount;
		scanf_s("%d %d", &studentCount, &friendsCount);

		// ¦ �Է�
		for (int f = 0; f < friendsCount; f++) {
			int a, b;
			scanf_s("%d %d", &a, &b);
			isFriends[a][b] = true;
			isFriends[b][a] = true;
		}

		// ��ġ�� �ʴ� studentCount / 2 ���� ������ ��
		bool student[10] = { false };
		cout << countTeam(0, studentCount / 2, student) << endl;
	}

    return 0;
}
```
- å ������ ��Ʈ ��Ƽ� isFriends �迭 ����
- ���� ������ �ߺ��ؼ� ���� ���� ã�Ƽ� �ڵ� ����
- Visual Studio 2013 ���� ���������� scanf ����� ���������� ����
����Ϸ��� ������Ʈ ���� �ÿ� SDL �˻� üũ ����