/* @JUDGE_ID:RATIONAL331 10050 C++ */
/* @BEGIN_OF_SOURCE_CODE */

#include<iostream>

int main() {

	int T;
	std::cin >> T;
	for (int testNum = 0; testNum < T; testNum++) {
		// 총 날짜
		int N;
		std::cin >> N;
		// 정당의 갯수
		int P;
		std::cin >> P;
		
		int h;
		int * numOfP = new int[P];
		for (int p = 0; p < P; p++) {
			std::cin >> h;
			numOfP[p] = h;

		}

		int count = 0;

		for (int i = 1; i <= N; i++) {
			if ((i-1) % 7 < 5) {// 금요일과 토요일은 제외
				for (int p = 0; p < P; p++) {
					if (i % numOfP[p] == 0) { 
						count++; 
						break; 
					}
				}
			}
		}

		std::cout << count << std::endl;

		delete[] numOfP;
	}

	return 0;
}

/* @END_OF_SOURCE_CODE */