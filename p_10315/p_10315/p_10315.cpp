#include <iostream>
#include <string>
#include<fstream>

int cardToRealValue(std::string, char*, char*, int, int);


int realValueToShapeIndex(int);
int realValueToValueIndex(int);


double distinguish(int*, int);

int main() {
	std::ofstream file("input.txt");
	char cardShape[] = { 'C', 'D', 'H', 'S' }; //4
	char cardValue[] = { '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A' }; //13

	int blackCards[5] = {0,};
	int whiteCards[5] = {0,};

	while (true) {

		if (std::cin.eof()) { file.close();  return 0; }

		for (int i = 0; i < 5; i++) {
			std::string card;
			std::cin >> card;
			blackCards[i] = cardToRealValue(card, cardShape, cardValue, 4, 13);
		}
		for (int i = 0; i < 5; i++) {
			std::string card;
			std::cin >> card;
			whiteCards[i] = cardToRealValue(card, cardShape, cardValue, 4, 13);
		}

		double black = distinguish(blackCards, 5);
		double white = distinguish(whiteCards, 5);



		if (black > white) std::cout << "Black wins." << std::endl;
		else if (black < white) std::cout << "White wins." << std::endl;
		else std::cout << "Tie." << std::endl;

		if (black > white) file << "Black wins." << std::endl;
		else if (black < white) file << "White wins." << std::endl;
		else file << "Tie." << std::endl;

	}
	file.close();
	return 0;
}

int returnIndex(char* arrayList, char findItem, int numOfElements) {
	for (int index = 0; index < numOfElements; index++) {
		if (arrayList[index] == findItem) return index;
	}
	return 0;
}

int cardToRealValue(std::string card, char* cardShape, char* cardValue, int shapeNum, int valueNum) {
	return returnIndex(cardValue, card[0], valueNum) + returnIndex(cardShape, card[1], shapeNum) * 13;
}


int realValueToShapeIndex(int realValue) {
	return realValue / 13;
}

int realValueToValueIndex(int realValue) {
	return realValue % 13;
}


int compare(const void* a, const void* b) {
	int temp_a = *(int*)a; int temp_b = *(int*)b;
	if (temp_a > temp_b) return 1;
	else if (temp_a < temp_b) return -1;
	else return 0;
}

double distinguish(int* values, int num) {
	// 정렬하면 비교하기 편해진다.
	int cardRealValue[5] = {0,};
	int cardRealShape[5] = {0,};
	for (int i = 0; i < 5; i++) {
		cardRealValue[i] = realValueToValueIndex(values[i]);
		cardRealShape[i] = realValueToShapeIndex(values[i]);
	}


	std::qsort(cardRealValue, num, sizeof(int), compare);
	std::qsort(cardRealShape, num, sizeof(int), compare);

	int max = 0;

	// 5장 모두 모양이 같으면서 -> 1번째 카드와 5번째 카드가 같으면 된다.
	if (cardRealShape[0] == cardRealShape[4]) {
		// 순차적이면
		if ((cardRealValue[0] + 4) == cardRealValue[4]
			|| (cardRealValue[0] + 12 == cardRealValue[4]) &&
			((cardRealValue[0] + 3 == cardRealValue[3]) ||
			((cardRealValue[0] + 2 == cardRealValue[2]) && (cardRealValue[4] - 1 == cardRealValue[3])) ||
				((cardRealValue[0] + 1 == cardRealValue[1] && cardRealValue[4] - 2 == cardRealValue[2])) ||
				(cardRealValue[4] - 3 == cardRealValue[1]))) {
			// 스트레이프 플러시이다.
			max += 90000000 + cardRealValue[4];
			return max;
		}
	}
	// 네 장의 카드가 value가 같을 경우 포카드
	if (cardRealValue[0] == cardRealValue[3] || cardRealValue[1] == cardRealValue[4]) {
		max += 80000000 + cardRealValue[3];
		return max; 
	}
	// 세장의 카드가 같은값을 가지고 두장의 카드가 같은 값을 가지는 경우, 이때 세장의 카드가 같은 값을 가지는 경우가 우위를 가진다.
	// 세장과 두장이 같은 값을 가지는 경우 (2,3)(3,2) 풀하우스
	if (((cardRealValue[0] == cardRealValue[2]) && (cardRealValue[3] == cardRealValue[4])) || ((cardRealValue[0] == cardRealValue[1]) && (cardRealValue[2] == cardRealValue[4]))) {
		max += 70000000 + cardRealValue[2];
		return max;
	}
	// 플러시는 다섯장의 카드의 무늬가 같은경우이다.
	if (cardRealShape[0] == cardRealShape[4]) { max += 60000000 + cardRealValue[0]; return max; }

	// 스트레이트는 다섯장의 카드가 연속적인 값을 가지면 된다.
	if ((cardRealValue[0] + 4) == cardRealValue[4]
		|| (cardRealValue[0] + 12 == cardRealValue[4]) &&
		((cardRealValue[0] + 3 == cardRealValue[3]) ||
		((cardRealValue[0] + 2 == cardRealValue[2]) && (cardRealValue[4] - 1 == cardRealValue[3])) ||
			((cardRealValue[0] + 1 == cardRealValue[1] && cardRealValue[4] - 2 == cardRealValue[2])) ||
			(cardRealValue[4] - 3 == cardRealValue[1]))) {
		max += 50000000 + cardRealValue[4];
		return max;
	}
	// 다섯장 중 세장이 같은 값을 가지는 경우 (000**)(*000*)(**000)
	if (cardRealValue[0] == cardRealValue[2] || cardRealValue[1] == cardRealValue[3] || cardRealValue[2] == cardRealValue[4]) {
		max += 40000000 + cardRealValue[2];
		return max;
	}
	// 다섯장중 두장이 같은 값을 가지는 경우가 2개 (0011*)(00*11)(*0011)
	if((cardRealValue[0] == cardRealValue[1] && cardRealValue[2] == cardRealValue[3]) || (cardRealValue[0] == cardRealValue[1] && cardRealValue[3] == cardRealValue[4]) 
		|| (cardRealValue[1] == cardRealValue[2] && cardRealValue[3] == cardRealValue[4])) {
		max += 30000000 + cardRealValue[3]*10000;
		if ((cardRealValue[0] == cardRealValue[1] && cardRealValue[2] == cardRealValue[3])) max += (cardRealValue[4]+1) * 100 + (cardRealValue[0]+1) * 10000;
		else if ((cardRealValue[0] == cardRealValue[1] && cardRealValue[3] == cardRealValue[4])) max += (cardRealValue[2]+1) * 100 + (cardRealValue[0]+1)*10000 ;
		else max += (cardRealValue[0]+1)*100 + (cardRealValue[1]+1) * 10000;
		return max;
	}
	// 다섯장중 두장이 같은 값을 가지는 경우 (00***)(*00**)(**00*)(***00)
	if (cardRealValue[0] == cardRealValue[1] || cardRealValue[1] == cardRealValue[2] || cardRealValue[2] == cardRealValue[3] || cardRealValue[3] == cardRealValue[4]) {
		if (cardRealValue[0] == cardRealValue[1]) max += 2000000 + cardRealValue[1]*10000;
		else if (cardRealValue[3] == cardRealValue[4]) max += 2000000 + cardRealValue[4]*10000;
		else max += 20000000 + cardRealValue[2]*10000;

		if (cardRealValue[0] == cardRealValue[1]) max += cardRealValue[4] * 100 + cardRealValue[3] * 10 + (cardRealValue[2] + 1);
		else if (cardRealValue[1] == cardRealValue[2]) max += cardRealValue[4] * 100 + cardRealValue[3] * 10 + (cardRealValue[0] + 1);
		else if (cardRealValue[2] == cardRealValue[3]) max += cardRealValue[4] * 100 + cardRealValue[1] * 10 + (cardRealValue[0] + 1);
		else max += cardRealValue[2] * 100 + cardRealValue[1] * 10 + (cardRealValue[0] + 1);

		return max;
	}
	
	// 최종적으로 등급가르기
	max += 10000000 + cardRealValue[4] * 10000 + cardRealValue[3] * 1000 + cardRealValue[2] * 100 + cardRealValue[1] * 10 + (cardRealValue[0]+1);

	return max;

}
