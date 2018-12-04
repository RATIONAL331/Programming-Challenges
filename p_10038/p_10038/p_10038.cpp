/* @JUDGE_ID:	RATIONAL331		10038		C++ */

/* @BEGIN_OF_SOURCE_CODE*/

#include<iostream>

int main() {
	int numberOfList;
	while (true) {

		if (std::cin.eof()) { return 0; }
		//numberOfList�� �迭�� ���� ���ڰ��� �Է�
		std::cin >> numberOfList;
		
		//�迭�� ���� ������� ����
		int * list = new int[numberOfList];
		for (int index = 0; index < numberOfList; index++) {
			int temp;
			std::cin>> temp;
			list[index] = temp;
		}

		//jollyList�� �迭�� a(k)�� a(k+1)�� ���Ͽ��� �� ���� �̿��Ͽ� �ε����� �ִ� �迭�̴�.
		int * jollyList = new int[numberOfList - 1];
		//jollyList �ʱ�ȭ
		for (int init = 0; init < numberOfList - 1; init++) {
			jollyList[init] = 0;
		}

		//jollyFlag�� jolly���� �ƴ����� ��Ÿ���� �÷��� ����
		bool jollyFlag = true;

		for (int indexK = 0; indexK < numberOfList - 1; indexK++) {
			int difference = std::abs(list[indexK] - list[indexK + 1]);
			
			//���� 0�̰ų� �Է������� ���� ũ�� ���ʿ� jolly�� �ƴϴ�.
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
