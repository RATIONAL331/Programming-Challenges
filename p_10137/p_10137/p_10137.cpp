/* @JUDGE_ID:	1003076		10137		C++		*/
/* @BEGIN_OF_SOURCE_CODE */

#include<iostream>

int compare(const void* a, const void* b) {
	double num1 = *(double *) a;
	double num2 = *(double *) b;
	if (num1 > num2) return -1;
	else if (num1 < num2) return 1;
	else return 0;

}

/*
전체적으로 구하는 방법은 
1) 들어온 값들을 저장한 배열(moneyList)을 이용하여 총금액을 구하고(moneySum), 
2) 총금액을 사람들에게 분배하는 값을 구하고(averageSum[n]), 
3) 들어온 값들을 저장한 배열과 분배하는 값의 차이를 각각 구해서 모두 더하여 (for-each(abs(moneyList[n]-averageSum[n])))
4) 이 값을 2로 나누게 되면 각 학생이 사용한 금액이 똑같아지기 위해 전달되어야 하는 금액의 총합이다.
*/
int main() {
	while (true) {
		//n은 들어올 돈값의 갯수를 저장하는 변수
		int n;
		std::cin >> n;
		if (std::cin.eof()) return 0;
		if (n == 0) return 0;
		

		//moneyList에는 들어온 돈값을 저장하는 배열
		double* moneyList = new double[n];
		double money;

		// 들어온 돈값을 모두 더하고 100을 곱한 값
		int moneySum = 0;

		// 들어온 값을 저장하고 계산하기 쉽게 모두 정수화 시키기
		for (int i = 0; i < n; i++) {
			std::cin >> money;
			moneyList[i] = money;
			moneySum += money * 100; //정수화 시키는 과정
		}

		//moneyList 정렬하기
		qsort(moneyList, n, sizeof(double), compare);
		
		// dollar는 합의 평균을 구하기 위한 변수, cent는 나머지 값
		int dollar = moneySum / n; 
		int cent = moneySum % n ;

		// averageSum은 돈값의 합을 평균을 저장하는 배열
		double* averageSum = new double[n];

		// 평균값으로 분배해주는 과정
		for (int i = 0; i < n; i++) {
			averageSum[i] = dollar;
		}

		for (int i = 0; i < cent; i++) {
			averageSum[i] += 1;
		}

		// 차이의 합구하기
		double differenceSum = 0;
		for (int i = 0; i < n; i++) {
			differenceSum += abs(moneyList[i] - averageSum[i]/100.0); //averageSum에는 아직 100으로 나눠지지 않은 값이 들어있다.
		}

		printf("$%.2f", differenceSum / 2.0); 
		std::cout << std::endl;
		
		delete[] averageSum;
		delete[] moneyList;
	}

	return 0;
}

/* @END_OF_SOURCE_CODE */