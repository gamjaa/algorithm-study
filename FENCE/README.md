## ����
p. 195 https://algospot.com/judge/problem/read/FENCE

�ʺ� ���� N���� ���� ���ڸ� �ٿ� ���� ��Ÿ���� �ֽ��ϴ�. �ð��� ������ ���� ���ڵ��� �η����ų� ������ ���̰� �� �޶��� ����� ��Ÿ���� ��°�� ��ü�ϱ�� �߽��ϴ�. �� �� ������ ��Ÿ���� �Ϻθ� ���簢������ �߶� ��Ȱ���ϰ� �ͽ��ϴ�. �׸� (b)�� (a)�� ��Ÿ������ �߶� �� �ִ� ���� ���簢�� �� ���� ���� ���簢���� �����ݴϴ�. ��Ÿ���� �����ϴ� �� ������ ���̰� �־��� ��, �߶� �� �ִ� ���簢���� �ִ� ũ�⸦ ����ϴ� ���α׷��� �ۼ��ϼ���. �� (c)ó�� ���簢���� �񽺵��� �߶� ���� �����ϴ�.

������ �ʺ�� ��� 1�̶�� �����մϴ�.

![](https://algospot.com/media/judge-attachments/506874700c7251881727ee4e70a1d502/fence.png)

## �Է�
ù �ٿ� �׽�Ʈ ���̽��� ���� C (C��50)�� �־����ϴ�. �� �׽�Ʈ ���̽��� ù �ٿ��� ������ �� N (1��N��20000)�� �־����ϴ�. �� ���� �ٿ��� N���� ������ ���ʺ��� �� ������ ���̰� ������� �־����ϴ�. ���̴� ��� 10,000 ������ ���� �ƴ� �����Դϴ�.

## ���
�� �׽�Ʈ ���̽��� ���� �ϳ��� �� �ٿ� ����մϴ�. �� ������ �־��� ��Ÿ������ �߶� �� �ִ� �ִ� ���簢���� ũ�⸦ ��Ÿ���� �մϴ�.

## �ڵ�
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
- ������ ������� Ǯ������ ����ð��� ���. å�� Ǯ�̸� ���� �ٽ� �� �� �����ϱ�