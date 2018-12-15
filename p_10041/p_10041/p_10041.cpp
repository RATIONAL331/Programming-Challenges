/* @JUDGE_ID:RATIONAL331 10041 C++ */
/* @BEGIN_OF_SOURCE_CODE */
#include<iostream>

int compare(const void* a1, const void* a2) {
	if (*(int*)a1 > *(int*)a2) return 1;
	else if (*(int*)a1 < *(int*)a2) return -1;
	else return 0;
}

int main() {
	int testCase;
	std::cin >> testCase;
	for (int i = 0; i < testCase; i++) {
		int r;
		std::cin >> r;


		int * addressArr = new int[r];

		for (int j = 0; j < r; j++) {
			int address;
			std::cin >> address;
			addressArr[j] = address;
		}

		std::qsort(addressArr, r, sizeof(int), compare);

		int mean = addressArr[r / 2];

		int distance = 0;

		for (int j = 0; j < r; j++) {
			distance += std::abs(addressArr[j] - mean);
		}
		
		std::cout << distance << std::endl;

		delete[] addressArr;
	}


	return 0;

}
/* @END_OF_SOURCE_CODE */