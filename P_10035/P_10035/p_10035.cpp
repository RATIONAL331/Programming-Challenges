#include<iostream>
int main() {
	while (true) {


		long long left, right;


		std::cin >> left >> right;

		if (std::cin.eof()) return 0;

		long long tempLeft = left;
		long long tempRight = right;

		// digitLeft 와 digitRight은 입력된 두 숫자의 자릿수를 구하는 변수
		int digitLeft = 1;
		int digitRight = 1;

		while (left/10 != 0) {
			left = left / 10;
			digitLeft++;
		}

		while (right / 10 != 0) {
			right = right / 10;
			digitRight++;
		}

		int carry = 0;
		int leftNum = 1, rightNum = 1;
		int result = 0;
		while (leftNum <= digitLeft || rightNum <= digitRight) {
			int leftDigit = tempLeft % 10;
			int rightDigit = tempRight % 10;

			if (carry + leftDigit + rightDigit >= 10) {
				carry = 1;
				result++;
			}
			else {
				carry = 0;
			}
			tempLeft /= 10;
			tempRight /= 10;
			leftNum++;
			rightNum++;
		}
		if (result == 0) std::cout << "No carry operation." << std::endl;
		else if (result == 1) std::cout << "1 carry operation." << std::endl;
		else std::cout << result << " carry operations." << std::endl;
	}
	return 0;
}