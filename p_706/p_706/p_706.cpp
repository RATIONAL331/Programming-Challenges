/* @JUDGE_ID: RATIONAL331 706 C++ */
/* @BEGIN_OF_SOURCE_CODE */
#include<iostream>
#include<string>

char calculateCharater(int*, int, int, int, int, int);

int main() {
	int s; std::string n;
	while(true){
		//���� �Է¹ޱ�
		//�̶� n�� ���ڿ��ν� int�� �ްԵǸ� 0���� ���۵Ǵ� ���� ó���� �� ���� �ȴ�.
		std::cin >> s >> n;
		if (std::cin.eof()) return 0;
		//stoi�� ���ڿ��� ���ڷ� �ٲ��ִ� �Լ��̴�.
		if (s == 0 && std::stoi(n) == 0) return 0;
		
		// ���� ���� ���� ����
		int countNumber = n.length();
		
		// �ʺ�� ���̸� ����
		int width = (s + 2)*countNumber;
		int height = (2 * s + 3);
		
		// numberList�� ���� ���ڿ��� ���ʺ��� �ϳ��� ������ �迭�̴�.
		int* numberList = new int[countNumber];
		for(int index=0; index<countNumber; index++){
			numberList[index] = n[index]-48; //char�������� �����Ƿ� ó���� ���ش�.
			
		}

		// ���÷��� ���� �����
		char** display = new char*[height];
		for (int index = 0; index < height; index++) {
			display[index] = new char[width];
		}
		// �˸´� ���� �ֱ�
		for (int heightIdx = 0; heightIdx < height; heightIdx++) {
			for (int widthIdx = 0; widthIdx < width; widthIdx++) {
				display[heightIdx][widthIdx] = calculateCharater(numberList, heightIdx, widthIdx, height, width, countNumber);
			}
		}

		// ���÷��̿��� ���� ���̿� ������ ����ֱ� ���� �����̴�.
		// finalDisplay�� ���������� ����� �迭�̴�.
		char** finalDisplay = new char*[height];
		for (int index = 0; index < height; index++) {
			finalDisplay[index] = new char[width + countNumber-1];
		}
		
		// ��ĭ���̴� �������� ä��� �������� �Ȱ��� ����ִ´�.
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

		// ���÷��� ����ϱ�
		for (int heightIdx = 0; heightIdx < height; heightIdx++) {
			for (int widthIdx = 0; widthIdx < width + countNumber-1; widthIdx++) {
				std::cout << finalDisplay[heightIdx][widthIdx];
			}
			std::cout << std::endl;
		}

		std::cout << std::endl;
		// ���÷��� ����ϱ� ���� �迭 ����
		for (int index = 0; index < height; index++) {
			delete[] finalDisplay[index];
		}
		delete[] finalDisplay;
		// ������ numberList ����
		delete[] numberList;
		// ���÷��� ���� ����
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