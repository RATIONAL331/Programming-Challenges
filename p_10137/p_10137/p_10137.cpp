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
��ü������ ���ϴ� ����� 
1) ���� ������ ������ �迭(moneyList)�� �̿��Ͽ� �ѱݾ��� ���ϰ�(moneySum), 
2) �ѱݾ��� ����鿡�� �й��ϴ� ���� ���ϰ�(averageSum[n]), 
3) ���� ������ ������ �迭�� �й��ϴ� ���� ���̸� ���� ���ؼ� ��� ���Ͽ� (for-each(abs(moneyList[n]-averageSum[n])))
4) �� ���� 2�� ������ �Ǹ� �� �л��� ����� �ݾ��� �Ȱ������� ���� ���޵Ǿ�� �ϴ� �ݾ��� �����̴�.
*/
int main() {
	while (true) {
		//n�� ���� ������ ������ �����ϴ� ����
		int n;
		std::cin >> n;
		if (std::cin.eof()) return 0;
		if (n == 0) return 0;
		

		//moneyList���� ���� ������ �����ϴ� �迭
		double* moneyList = new double[n];
		double money;

		// ���� ������ ��� ���ϰ� 100�� ���� ��
		int moneySum = 0;

		// ���� ���� �����ϰ� ����ϱ� ���� ��� ����ȭ ��Ű��
		for (int i = 0; i < n; i++) {
			std::cin >> money;
			moneyList[i] = money;
			moneySum += money * 100; //����ȭ ��Ű�� ����
		}

		//moneyList �����ϱ�
		qsort(moneyList, n, sizeof(double), compare);
		
		// dollar�� ���� ����� ���ϱ� ���� ����, cent�� ������ ��
		int dollar = moneySum / n; 
		int cent = moneySum % n ;

		// averageSum�� ������ ���� ����� �����ϴ� �迭
		double* averageSum = new double[n];

		// ��հ����� �й����ִ� ����
		for (int i = 0; i < n; i++) {
			averageSum[i] = dollar;
		}

		for (int i = 0; i < cent; i++) {
			averageSum[i] += 1;
		}

		// ������ �ձ��ϱ�
		double differenceSum = 0;
		for (int i = 0; i < n; i++) {
			differenceSum += abs(moneyList[i] - averageSum[i]/100.0); //averageSum���� ���� 100���� �������� ���� ���� ����ִ�.
		}

		printf("$%.2f", differenceSum / 2.0); 
		std::cout << std::endl;
		
		delete[] averageSum;
		delete[] moneyList;
	}

	return 0;
}

/* @END_OF_SOURCE_CODE */