#include<iostream>
#include<string>
#include<vector>
#include<limits>

std::string calculate(std::vector<std::string>);
bool isAllTrue(std::vector<bool>&, int);
bool restCalculate(std::vector<std::string>, std::vector<bool>&, std::string, int);

int main() {
	int testCase;
	std::cin >> testCase;

	std::vector<std::string> * testVec = new std::vector<std::string> [testCase];

	for (int testNum = 0; testNum < testCase; testNum++) {
		
		std::vector<std::string> * fileVec = new std::vector<std::string>;

		std::cin.get();
		std::cin.ignore();

		while (true) {
			std::string line;
			std::cin >> line;


			if (std::cin.eof()) {
				testVec[testNum] = *fileVec;
				delete fileVec;
				break; 
			}

			

			if (int(line[0]) == 10) {
				testVec[testNum] = *fileVec;
				delete fileVec;
				break;
			}
			else {
				fileVec->push_back(line);
			}
		}
	}

	for (int i = 0; i < testCase; i++) {
		std::cout << calculate(testVec[i]) << std::endl;
		std::cout << std::endl;
	}

	delete[] testVec;
	
	return 0;
}

std::string calculate(std::vector<std::string> arr) {
	int max = 0;
	int min = std::numeric_limits<int>::max();

	std::vector<bool> visitInfo(arr.size());

	for (auto i : arr) {
		if (i.length() > max) max = i.length();
		if (i.length() < min) min = i.length();
	}

	int L = max + min;

	std::string temp;

	visitInfo[0] = true;

	for (int j = 1; j < arr.size(); j++) {
		if (visitInfo[j] == false && L - arr[0].length() == arr[j].length()) {
			visitInfo[j] = true;
			temp = arr[0] + arr[j];
			if (restCalculate(arr, visitInfo, temp, L)) {
				return temp;
			}
			else {
				visitInfo[j] = false;
			}
		}
		visitInfo[j] = false;
		}


	return temp;
}


bool restCalculate(std::vector<std::string> arr, std::vector<bool>& visitInfo, std::string temp, int L) {

	if (isAllTrue(visitInfo, arr.size())) return true;


	for (int i = 0; i < arr.size(); i++) {
		if (visitInfo[i] == false) {
			visitInfo[i] = true;
			for (int j = 0; j < arr.size(); j++) {
				if (i != j && visitInfo[j] == false && L - arr[i].length() == arr[j].length()) {
					visitInfo[j] = true;
					if (temp == arr[i] + arr[j]) {
						if(restCalculate(arr, visitInfo, temp, L)) return true;
						else { 
							visitInfo[j] = false;
							return false;
						}
					}
					else {
						visitInfo[j] = false;
						return false;
					}
				}
			}
		}
	}
	return false;
}

bool isAllTrue(std::vector<bool>& visitInfo, int length) {
	for (int i = 0; i < length; i++) {
		if (visitInfo[i] == false) return false;
	}
	return true;
}
