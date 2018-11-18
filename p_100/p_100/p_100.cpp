/* @JUDGE_ID:	RATIONAL331		100		C++	*/

/* @BEGIN_OF_SOURCE_CODE@ */

#include<iostream>

int main() {
	// first�� last�� �Է��� �޴´�..
	int first, last;
	while (true) {
		//first�� last�� �ܺη� ���� �޴´�.
		std::cin >> first >> last;

		//���̻� �Էµ��� ������ �ٷ� ����
		if (std::cin.eof()) return 0;

		//��¿� ������ temp_i�� temp_j�� �����. ����� ���� ���⼭ Ʋ��;
		int temp_i = first, temp_j = last;

		//first�� �� Ŭ��� last�� ���� �ٲ۴�.
		if (first > last) std::swap(first, last);

		//////////////////////////////////////////////////////////////
		int max = 0;
		//max�� ���ݱ��� ����Դ� �� �߿� ���� ū ���� �����Ѵ�.
			
		for (int index = first; index <= last; index++) {
			int temp = index; // temp�� �̿��Ͽ� ���ڸ� �����Ѵ�.				
			int count = 1; //count�� ���ݱ��� �� ���ڿ� ���� ����Ŭ�� �����̴�.
			while (temp != 1) { //temp�� 1�� �ƴҵ��� �Ʒ��� �ݺ����� �����Ѵ�.
				if (temp % 2 == 0) { //temp�� ¦���̸�
					temp /= 2; //temp�� 2�� ������.
					count += 1; //����Ŭ ���� 1 �ø���.
				}
				else { //temp�� ¦���� �ƴҰ��
					temp *= 3; //temp�� 3���ϰ�
					temp += 1; //temp�� 1�� ���Ѵ�.
					count += 1; //����Ŭ�� ���� 1 ���Ѵ�.
				}
			}
			if (max < count) { //temp�� 1�̵Ǿ� �� �̻� �ݺ����� ������ �ȵȴٸ� max�� ���ݱ��� count�� ���� ����. 
				max = count; //count�� �� ũ�� max�� ���Ž�Ų��.
			}
		}
		//��� ���Ŀ� ���� ����Ѵ�.
		std::cout << temp_i << " " << temp_j << " " << max << std::endl;
		
	}
	return 0;
}
/* @END_OF_SOURCE_CODE@ */
