// BOGGLE.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int cycle;
	char game[5][5];
	cin >> cycle;
	for (int testCase = 0; testCase < cycle; testCase++) {
		for (int line = 0; line < 5; line++)
			cin >> game[line];

		int words;
		cin >> words;
		for (int wordCount = 0; wordCount < words; wordCount++) {
			char word[10];
			cin >> word;
			hasWord(word);
		}
	}

    return 0;
}

bool hasWord(char* word) {
	char orgWord[10];
	
	return;
}

void roundCheck(int y, int x, char* remainWord) {

}
