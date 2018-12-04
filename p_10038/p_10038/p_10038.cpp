/* @JUDGE_ID:	RATIONAL331		10038		C++ */

/* @BEGIN_OF_SOURCE_CODE*/

#include<iostream>

int main() {
	int numberOfList;
	while (true) {

		if (std::cin.eof()) { return 0; }
		//numberOfList에 배열에 넣을 숫자값을 입력
		std::cin >> numberOfList;
		
		//배열에 들어온 순서대로 정렬
		int * list = new int[numberOfList];
		for (int index = 0; index < numberOfList; index++) {
			int temp;
			std::cin>> temp;
			list[index] = temp;
		}

		//jollyList는 배열의 a(k)와 a(k+1)을 비교하여서 그 차를 이용하여 인덱스에 넣는 배열이다.
		int * jollyList = new int[numberOfList - 1];
		//jollyList 초기화
		for (int init = 0; init < numberOfList - 1; init++) {
			jollyList[init] = 0;
		}

		//jollyFlag가 jolly인지 아닌지를 나타내는 플래그 변수
		bool jollyFlag = true;

		for (int indexK = 0; indexK < numberOfList - 1; indexK++) {
			int difference = std::abs(list[indexK] - list[indexK + 1]);
			
			//차가 0이거나 입력정수에 비해 크면 애초에 jolly가 아니다.
			if (difference <= 0 || difference >= numberOfList) {
				jollyFlag = false;
				break;
			}

			if (jollyList[difference - 1] == 0) {
				jollyList[difference - 1] = difference;
			}
			else {
				jollyFlag = false;
				break;
			}
		}

		if (jollyFlag) std::cout << "Jolly" << std::endl;
		else std::cout << "Not jolly" << std::endl;

		delete[] jollyList;
		delete[] list;
	}
	return 0;
}

/* @END_OF_SOURCE_CODE*/
