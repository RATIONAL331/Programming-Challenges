/* @JUDGE_ID: RATIONAL331 706 C++ */
/* @BEGIN_OF_SOURCE_CODE */
#include<iostream>

char calculateCharater(int*, int, int, int, int, int);

int main() {
	int s, n;
	while(true){
		std::cin >> s >> n;
		if (std::cin.eof()) return 0;
		if (s == 0 || n == 0) return 0;
		
		// 너비와 높이를 설정
		int width = (s + 2)*n;
		int height = (2 * s + 3);
		
		// 들어온 숫자 갯수 세기
		int tempNumber = n;
		int countNumber = 0;
		while (tempNumber != 0) {
			tempNumber /= 10;
			countNumber++;
		}

		tempNumber = n;
		int numberListIdx = countNumber - 1;
		int* numberList = new int[countNumber];
		while (tempNumber != 0) {
			int number = tempNumber % 10;
			tempNumber /= 10;
			numberList[numberListIdx--] = number;
		}

		// 디스플레이 공간 만들기
		char** display = new char*[height];
		for (int index = 0; index < height; index++) {
			display[index] = new char[width];
		}
		// 알맞는 문자 넣기
		for (int heightIdx = 0; heightIdx < height; heightIdx++) {
			for (int widthIdx = 0; widthIdx < width; widthIdx++) {
				display[heightIdx][widthIdx] = calculateCharater(numberList, heightIdx, widthIdx, height, width, countNumber);
			}
		}


		// 생성된 numberList 삭제
		delete[] numberList;
		// 디스플레이 공간 삭제
		for (int index = 0; index < height; index++) {
			delete[] display[index];
		}
		delete[] display;

	}
	
	return 0;
}

char calculateCharater(int* numberList, int currentHeight, int currentWidth, int height, int width, int countNumber) {
	switch (numberList[currentWidth/countNumber]) {
	case 0:
		
		break;
	case 1:
		if ((currentHeight == 0 || currentHeight == height - 1) && currentWidth) return '|'; //이부분부터
		else return ' ';
		break;
	case 2:

		break;
	case 3:

		break;
	case 4:

		break;
	case 5:

		break;
	case 6:

		break;
	case 7:

		break;
	case 8:

		break;
	case 9:

		break;
	}
}

/* @END_OF_SOURCE_CODE */