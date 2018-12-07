/* @JUDGE_ID:RATIONAL331 843 C++ */

/* @BEGIN_OF_SOURCE_CODE */

#include<iostream>
#include<string>
#include<vector>

std::vector<std::string> split(const std::string&);
int returnIndex(char*, char, int);

int main() {

	char originalArray[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	char encodedArray[26] = { '0', };

	int n;
	std::cin >> n;

	std::string * dict = new std::string[n];

	for (int i = 0; i < n; i++) {
		std::string dictionaryWord;
		std::cin >> dictionaryWord;
		dict[i] = dictionaryWord;
	}
	
	std::string codedLine;
	while (true) {
		if (std::cin.eof()) { 
			delete[] dict; 
			return 0; 
		}

		std::cin >> codedLine;
		std::vector<std::string> encodedVector = split(codedLine);
		
		bool isSuccess = true;


		for (auto v : encodedVector) {
			for (int i = 0; i < n; i++) {
				if (v.length() == dict[i].length()) {
					for (int link = 0; link < v.length(); link++) {
						char linkChar = encodedArray[returnIndex(originalArray, v[link], 26)];
						if (linkChar == '0') {
							encodedArray[returnIndex(originalArray, v[link], 26)] = dict[i].at(link);
						}
						else {
							if (linkChar != dict[i].at(link)) {
								isSuccess = false;
								break;
							}
						}
					}
				}
			}			
		}
		
		for (auto v : encodedVector) {
			for (int link = 0; link < v.length(); link++) {
				char printChar = encodedArray[returnIndex(originalArray, v[link], 26)];
				if(isSuccess) std::cout << printChar;
				else std::cout << '*';
				
			}
			std::cout << " ";
		}
		
		std::cout << std::endl;
	}


	return 0;
}

std::vector<std::string> split(const std::string& line) {
	
	std::vector<std::string> tokenList;
	std::string token = "";
	for (int i = 0; i < line.length(); i++) {
		if (line[i] != ' ') {
			token.push_back(line[i]);
		}
		else {
			tokenList.push_back(token);
		}
	}

	tokenList.push_back(token);


	return tokenList;

}

int returnIndex(char* arrary, char find, int numOfArray) {
	for (int i = 0; i < numOfArray; i++) {
		if (arrary[i] == find) { return i; }
	}
	return 0;
}

/* @END_OF_SOURCE_CODE */