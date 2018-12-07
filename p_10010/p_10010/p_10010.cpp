/* JUDGE_ID: RATIONAL331 10010 c++ */	
/* @BEGIN_OF_SOURCE_CODE */
#include<iostream>
#include<string>

void compare(char**, std::string, int, int);
bool recursive(char **, const std::string&, int, int, int, int, int, int, int);

int main() {
	int testCase;
	std::cin >> testCase;

	

	//  m은 행 n은 열
	int m, n;
	char ** grid = nullptr;

	for (int caseNum = 0; caseNum < testCase; caseNum++) {
		std::cin.get();
		std::cin.ignore();

		std::cin >> m;
		std::cin >> n;

		// 문장을 넣을 그리드 생성
		grid = new char* [m];
		for (int i = 0; i < m; i++) grid[i] = new char[n];

		// 받을 문장을 그리드 안에 넣기
		for (int i = 0; i < m; i++) {
			std::string inputLine;
			std::cin >> inputLine;
			// 문자 하나 하나를 그리드에 넣기
			for (int j = 0; j < n; j++) {
				grid[i][j] = toupper(inputLine[j]);
			}
		}

		// 비교 단어의 갯수
		int k;
		std::cin >> k;

		for (int i = 0; i < k; i++) {
			std::string word;
			std::cin >> word;
			compare(grid, word, m, n);
		}

		if(caseNum != testCase-1) std::cout << std::endl;


		for (int i = 0; i < m; i++) delete[] grid[i];
		delete[] grid;
	}
	return 0;
}

void compare(char** grid, std::string word, int m, int n) {
	for (int mIndex = 0; mIndex < m; mIndex++) {
		for (int nIndex = 0; nIndex < n; nIndex++) {
			if (grid[mIndex][nIndex] == toupper(word[0])) {
				if (word.length() == 1) {
					std::cout << mIndex + 1 << " " << nIndex + 1 << std::endl;
					return;
				}
				else {
					if (recursive(grid, word, mIndex, nIndex, m, n, -1, -1, 1) ||
						recursive(grid, word, mIndex, nIndex, m, n, -1, 0, 1) ||
						recursive(grid, word, mIndex, nIndex, m, n, -1, 1, 1) ||
						recursive(grid, word, mIndex, nIndex, m, n, 0, -1, 1) ||
						recursive(grid, word, mIndex, nIndex, m, n, 0, 1, 1) ||
						recursive(grid, word, mIndex, nIndex, m, n, 1, -1, 1) ||
						recursive(grid, word, mIndex, nIndex, m, n, 1, 0, 1) ||
						recursive(grid, word, mIndex, nIndex, m, n, 1, 1, 1)) {

						std::cout << mIndex + 1 << " " << nIndex + 1 << std::endl;

						return;
					}
				}
			}
		}
	}
}

bool recursive(char ** grid, const std::string& word, int currentM, int currentN, int m, int n, int nextM, int nextN, int count) {
	if (count == word.length()) return true;

	if (currentM + nextM < 0 || currentN + nextN < 0 || currentM + nextM >= m || currentN + nextN >= n) return false;
	if (grid[currentM + nextM][currentN + nextN] != toupper(word[count])) return false;
	
	if(recursive(grid, word, currentM + nextM, currentN + nextN, m, n, nextM, nextN, ++count)) return true;

	return false;
}

/* @END_OF_SOURCE_CODE */