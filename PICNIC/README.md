## 문제
p.155 https://algospot.com/judge/problem/read/PICNIC

안드로메다 유치원 익스프레스반에서는 다음 주에 율동공원으로 소풍을 갑니다. 원석 선생님은 소풍 때 학생들을 두 명씩 짝을 지어 행동하게 하려고 합니다. 그런데 서로 친구가 아닌 학생들끼리 짝을 지어 주면 서로 싸우거나 같이 돌아다니지 않기 때문에, 항상 서로 친구인 학생들끼리만 짝을 지어 줘야 합니다.

각 학생들의 쌍에 대해 이들이 서로 친구인지 여부가 주어질 때, 학생들을 짝지어줄 수 있는 방법의 수를 계산하는 프로그램을 작성하세요. 짝이 되는 학생들이 일부만 다르더라도 다른 방법이라고 봅니다. 예를 들어 다음 두 가지 방법은 서로 다른 방법입니다.

- (태연,제시카) (써니,티파니) (효연,유리)
- (태연,제시카) (써니,유리) (효연,티파니)

## 입력
입력의 첫 줄에는 테스트 케이스의 수 C (C <= 50) 가 주어집니다. 각 테스트 케이스의 첫 줄에는 학생의 수 n (2 <= n <= 10) 과 친구 쌍의 수 m (0 <= m <= n*(n-1)/2) 이 주어집니다. 그 다음 줄에 m 개의 정수 쌍으로 서로 친구인 두 학생의 번호가 주어집니다. 번호는 모두 0 부터 n-1 사이의 정수이고, 같은 쌍은 입력에 두 번 주어지지 않습니다. 학생들의 수는 짝수입니다.

## 출력
각 테스트 케이스마다 한 줄에 모든 학생을 친구끼리만 짝지어줄 수 있는 방법의 수를 출력합니다.

## 코드
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

	// 테스트 케이스 반복
	for (int testCase = 0; testCase < cycle; testCase++) {
		memset(isFriends, false, 100);

		// 학생 수, 친구 수
		int studentCount, friendsCount;
		scanf_s("%d %d", &studentCount, &friendsCount);

		// 짝 입력
		for (int f = 0; f < friendsCount; f++) {
			int a, b;
			scanf_s("%d %d", &a, &b);
			isFriends[a][b] = true;
			isFriends[b][a] = true;
		}

		// 겹치지 않는 studentCount / 2 팀을 만들어야 함
		bool student[10] = { false };
		cout << countTeam(0, studentCount / 2, student) << endl;
	}

    return 0;
}
```
- 책 예제를 힌트 삼아서 isFriends 배열 만듦
- 같은 조합을 중복해서 세는 문제 찾아서 코드 수정
- Visual Studio 2013 이후 버전에서는 scanf 사용을 강제적으로 막음
사용하려면 프로젝트 생성 시에 SDL 검사 체크 해제