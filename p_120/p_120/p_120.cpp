/* @JUDGE_ID:RATIONAL331 120 C++ */
/* @BEGIN_OF_SOURCE_CODE */
#include<iostream>
#include<vector>
#include<algorithm>

int search(std::vector<int>, int);
void flip(std::vector<int>&, int);

int main() {
	std::vector<int> pancakeLine;
	std::vector<int> copyPancakeLine;
	
	while (true) {
		if (std::cin.eof()) return 0;
		int a;
		a = std::cin.get();
		if (a == '\n') {
			copyPancakeLine = pancakeLine;
			std::sort(pancakeLine.begin(), pancakeLine.end());
			int len = pancakeLine.size()-1;
			while (len >= 0) {
				if (copyPancakeLine[len] != pancakeLine[len]) {
					int index = search(copyPancakeLine, pancakeLine[len]);
					if (index != 0) {
						flip(copyPancakeLine, index);
						flip(copyPancakeLine, len);
					}
					else {
						flip(copyPancakeLine, len);
					}
				}
				len--;
			}
			std::cout << "0" << std::endl;
			pancakeLine.clear();
		}
		else if (a != ' ') {
			pancakeLine.push_back(a-48);
		}		
	}
	return 0;
}
int search(std::vector<int> vec, int find) {
	int index = 0;
	for (int i : vec) {
		if (i == find) return index;
		else index++;
	}
}
void flip(std::vector<int>& vec, int index) {
	int start = 0; int last = index;
	while (start < last) {
		int temp = vec[start];
		vec[start] = vec[last];
		vec[last] = temp;
		start++;
		last--;
	}

	std::cout << vec.size() - index << " ";
}
/* @END_OF_SOURCE_CODE */
