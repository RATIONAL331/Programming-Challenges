/* @JUDGE_ID:RATIONAL331 10050 C++ */
/* @BEGIN_OF_SOURCE_CODE */

#include<iostream>

int main() {

	int T;
	std::cin >> T;
	for (int testNum = 0; testNum < T; testNum++) {
		// �� ��¥
		int N;
		std::cin >> N;
		// ������ ����
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
			if ((i-1) % 7 < 5) {// �ݿ��ϰ� ������� ����
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