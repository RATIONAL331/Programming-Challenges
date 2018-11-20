/* @JUDGE_ID: RATIONAL331 706 C++ */
/* @BEGIN_OF_SOURCE_CODE */
#include<iostream>
#include<string>

char calculateCharater(int*, int, int, int, int, int);

int main() {
	int s; std::string n;
	while(true){
		//숫자 입력받기
		//이때 n은 문자열로써 int로 받게되면 0으로 시작되는 것을 처리할 수 없게 된다.
		std::cin >> s >> n;
		if (std::cin.eof()) return 0;
		//stoi는 문자열을 숫자로 바꿔주는 함수이다.
		if (s == 0 && std::stoi(n) == 0) return 0;
		
		// 들어온 숫자 갯수 세기
		int countNumber = n.length();
		
		// 너비와 높이를 설정
		int width = (s + 2)*countNumber;
		int height = (2 * s + 3);
		
		// numberList는 들어온 문자열을 왼쪽부터 하나씩 대입한 배열이다.
		int* numberList = new int[countNumber];
		for(int index=0; index<countNumber; index++){
			numberList[index] = n[index]-48; //char형식으로 나오므로 처리를 해준다.
			
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

		// 디스플레이에서 숫자 사이에 공백을 집어넣기 위한 과정이다.
		// finalDisplay는 최종적으로 출력할 배열이다.
		char** finalDisplay = new char*[height];
		for (int index = 0; index < height; index++) {
			finalDisplay[index] = new char[width + countNumber-1];
		}
		
		// 빈칸사이는 공백으로 채우고 나머지는 똑같이 집어넣는다.
		for (int heightIdx = 0; heightIdx < height; heightIdx++) {
			int finalWidthIdx = 0;
			for (int widthIdx = 0; widthIdx < width + countNumber-1; widthIdx++) {
				if (widthIdx != 0 && (widthIdx % (s + 3) == (s + 2))) {
					finalDisplay[heightIdx][widthIdx] = ' ';
				}
				else {
					finalDisplay[heightIdx][widthIdx] = display[heightIdx][finalWidthIdx++];
				}

			}
		}

		// 디스플레이 출력하기
		for (int heightIdx = 0; heightIdx < height; heightIdx++) {
			for (int widthIdx = 0; widthIdx < width + countNumber-1; widthIdx++) {
				std::cout << finalDisplay[heightIdx][widthIdx];
			}
			std::cout << std::endl;
		}

		std::cout << std::endl;
		// 디스플레이 출력하기 위한 배열 삭제
		for (int index = 0; index < height; index++) {
			delete[] finalDisplay[index];
		}
		delete[] finalDisplay;
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
	int characterWidth = width / countNumber;
	switch (numberList[currentWidth/characterWidth]) {
	case 0:
		if ((currentHeight == 0 || currentHeight == height - 1) && !(currentWidth % characterWidth == 0 || currentWidth % characterWidth == characterWidth - 1)) return '-';
		if (!(currentHeight == 0 || currentHeight == height - 1 || currentHeight == height / 2) && (currentWidth % characterWidth == 0 || currentWidth % characterWidth == characterWidth - 1)) return '|';
		return ' ';
		break;
	case 1:
		if (!(currentHeight == 0 || currentHeight == height - 1 || currentHeight == height / 2) && currentWidth % characterWidth == characterWidth - 1) return '|'; 
		else return ' ';
		break;
	case 2:
		if ((currentHeight == 0 || currentHeight == height - 1 || currentHeight == height / 2) && !(currentWidth % characterWidth == 0 || currentWidth % characterWidth == characterWidth - 1)) return '-';
		if (!(currentHeight == 0 || currentHeight == height - 1 || currentHeight == height / 2)) { 
			if (currentHeight < height / 2 && currentWidth % characterWidth == characterWidth - 1) return '|';
			if(currentHeight > height / 2 && currentWidth % characterWidth == 0) return '|';
		}
		return ' ';
		break;
	case 3:
		if ((currentHeight == 0 || currentHeight == height - 1 || currentHeight == height / 2) && !(currentWidth % characterWidth == 0 || currentWidth % characterWidth == characterWidth - 1)) return '-';
		if (!(currentHeight == 0 || currentHeight == height - 1 || currentHeight == height / 2) && currentWidth % characterWidth == characterWidth - 1) return '|';
		return ' ';
		break;
	case 4:
		if ((currentHeight == height/2) && !(currentWidth % characterWidth == 0 || currentWidth % characterWidth == characterWidth - 1)) return '-';
		if (!(currentHeight == 0 || currentHeight == height - 1 || currentHeight == height / 2)) {
			if (currentHeight > height / 2 && currentWidth % characterWidth == characterWidth - 1) return '|';
			if (currentHeight < height / 2 && (currentWidth % characterWidth == 0 || currentWidth % characterWidth == characterWidth - 1)) return '|';
		}
		return ' ';
		break;
	case 5:
		if ((currentHeight == 0 || currentHeight == height - 1 || currentHeight == height / 2) && !(currentWidth % characterWidth == 0 || currentWidth % characterWidth == characterWidth - 1)) return '-';
		if (!(currentHeight == 0 || currentHeight == height - 1 || currentHeight == height / 2)) {
			if (currentHeight > height / 2 && currentWidth % characterWidth == characterWidth - 1) return '|';
			if (currentHeight < height / 2 && currentWidth % characterWidth == 0) return '|';
		}
		return ' ';
		break;
	case 6:
		if ((currentHeight == 0 || currentHeight == height - 1 || currentHeight == height / 2) && !(currentWidth % characterWidth == 0 || currentWidth % characterWidth == characterWidth - 1)) return '-';
		if (!(currentHeight == 0 || currentHeight == height - 1 || currentHeight == height / 2)) {
			if (currentHeight > height / 2 && (currentWidth % characterWidth == characterWidth - 1 || currentWidth % characterWidth == 0)) return '|';
			if (currentHeight < height / 2 && currentWidth % characterWidth == 0) return '|';
		}
		return ' ';
		break;
	case 7:
		if (currentHeight == 0 && !(currentWidth % characterWidth == 0 || currentWidth % characterWidth == characterWidth - 1)) return '-';
		if (!(currentHeight == 0 || currentHeight == height - 1 || currentHeight == height / 2) && currentWidth % characterWidth == characterWidth - 1) return '|';
		return ' ';
		break;
	case 8:
		if ((currentHeight == 0 || currentHeight == height - 1 || currentHeight == height / 2) && !(currentWidth % characterWidth == 0 || currentWidth % characterWidth == characterWidth - 1)) return '-';
		if (!(currentHeight == 0 || currentHeight == height - 1 || currentHeight == height / 2) && (currentWidth % characterWidth == 0 || currentWidth % characterWidth == characterWidth - 1)) return '|';
		return ' ';
		break;
	case 9:
		if ((currentHeight == 0 || currentHeight == height - 1 || currentHeight == height / 2) && !(currentWidth % characterWidth == 0 || currentWidth % characterWidth == characterWidth - 1)) return '-';
		if (!(currentHeight == 0 || currentHeight == height - 1 || currentHeight == height / 2)) {
			if (currentHeight > height / 2 && currentWidth % characterWidth == characterWidth - 1) return '|';
			if (currentHeight < height / 2 && (currentWidth % characterWidth == characterWidth - 1 || currentWidth % characterWidth == 0)) return '|';
		}
		return ' ';
		break;
	}
	return ' ';
}

/* @END_OF_SOURCE_CODE */