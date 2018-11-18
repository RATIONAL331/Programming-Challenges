/* @JUDGE_ID:	RATIONAL331		100		C++	*/

/* @BEGIN_OF_SOURCE_CODE@ */

#include<iostream>

int main() {
	// first와 last로 입력을 받는다..
	int first, last;
	while (true) {
		//first와 last를 외부로 부터 받는다.
		std::cin >> first >> last;

		//더이상 입력되지 않으면 바로 리턴
		if (std::cin.eof()) return 0;

		//출력용 변수인 temp_i와 temp_j를 만든다. 참고로 내가 여기서 틀림;
		int temp_i = first, temp_j = last;

		//first가 더 클경우 last와 값을 바꾼다.
		if (first > last) std::swap(first, last);

		//////////////////////////////////////////////////////////////
		int max = 0;
		//max는 지금까지 세어왔던 것 중에 가장 큰 것을 저장한다.
			
		for (int index = first; index <= last; index++) {
			int temp = index; // temp를 이용하여 숫자를 조작한다.				
			int count = 1; //count는 지금까지 그 숫자에 대한 사이클의 숫자이다.
			while (temp != 1) { //temp가 1이 아닐동안 아래의 반복문을 실행한다.
				if (temp % 2 == 0) { //temp가 짝수이면
					temp /= 2; //temp를 2로 나눈다.
					count += 1; //사이클 수를 1 올린다.
				}
				else { //temp가 짝수가 아닐경우
					temp *= 3; //temp를 3곱하고
					temp += 1; //temp에 1을 더한다.
					count += 1; //사이클의 수를 1 더한다.
				}
			}
			if (max < count) { //temp가 1이되어 더 이상 반복문이 진행이 안된다면 max와 지금까지 count의 수를 센다. 
				max = count; //count가 더 크면 max를 갱신시킨다.
			}
		}
		//출력 형식에 맏게 출력한다.
		std::cout << temp_i << " " << temp_j << " " << max << std::endl;
		
	}
	return 0;
}
/* @END_OF_SOURCE_CODE@ */
