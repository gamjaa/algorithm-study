## 문제
p. 195 https://algospot.com/judge/problem/read/FENCE

너비가 같은 N개의 나무 판자를 붙여 세운 울타리가 있습니다. 시간이 지남에 따라 판자들이 부러지거나 망가져 높이가 다 달라진 관계로 울타리를 통째로 교체하기로 했습니다. 이 때 버리는 울타리의 일부를 직사각형으로 잘라내 재활용하고 싶습니다. 그림 (b)는 (a)의 울타리에서 잘라낼 수 있는 많은 직사각형 중 가장 넓은 직사각형을 보여줍니다. 울타리를 구성하는 각 판자의 높이가 주어질 때, 잘라낼 수 있는 직사각형의 최대 크기를 계산하는 프로그램을 작성하세요. 단 (c)처럼 직사각형을 비스듬히 잘라낼 수는 없습니다.

판자의 너비는 모두 1이라고 가정합니다.

![](https://algospot.com/media/judge-attachments/506874700c7251881727ee4e70a1d502/fence.png)

## 입력
첫 줄에 테스트 케이스의 개수 C (C≤50)가 주어집니다. 각 테스트 케이스의 첫 줄에는 판자의 수 N (1≤N≤20000)이 주어집니다. 그 다음 줄에는 N개의 정수로 왼쪽부터 각 판자의 높이가 순서대로 주어집니다. 높이는 모두 10,000 이하의 음이 아닌 정수입니다.

## 출력
각 테스트 케이스당 정수 하나를 한 줄에 출력합니다. 이 정수는 주어진 울타리에서 잘라낼 수 있는 최대 직사각형의 크기를 나타내야 합니다.

## 코드
```cpp
#include <iostream>
#include <vector>
using namespace std;

int WIDTH;

int calc(vector<int>& fence, int fenceIndex) {
	int height = fence[fenceIndex];
	int size = 0;
	bool ok = false;
		
	for (int i = fenceIndex + 1; i < WIDTH; i++) {
		if (height > fence[i]) {
			break;
		}
		ok = true;
		size += height;
	}
	for (int i = fenceIndex - 1; i >= 0; i--) {		
		if (height > fence[i]) {
			break;
		}
		ok = true;
		size += height;
	}
	
	return size + (ok ? height : 0);
}

int resolve(vector<int>& fence) {
	int result = 0;
	
	for (int i = 0; i < WIDTH; i++) {
		result = max(result, calc(fence, i));	
	}
	
	return result;
}

int main(int argc, char* argv[]) {
	int testcase;
	cin >> testcase;
	
	for (int times = 0; times < testcase; times++) {
		cin >> WIDTH;
		vector<int> fence;
		
		for (int i = 0; i < WIDTH; i++) {
			int input;
			cin >> input;
			fence.push_back(input);
		}
		
		cout << resolve(fence) << endl;
	}
	
	return 0;
}
```
- 간단한 방법으로 풀었지만 수행시간이 길다. 책의 풀이를 보고 다시 한 번 공부하기