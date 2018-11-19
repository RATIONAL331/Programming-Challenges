/* @JUDGE_ID:	RATIONAL331		10189		C++	 */	
/* @BEGIN_OF_SOURCE_CODE@ */
#include<iostream>
#include<string>

int calculateMineLand(char**, int, int, int, int);
int checkMine(char**, int, int, int, int);

int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};

int main() {

	int FIELD = 1;
	int a, b;

	while (true) {
		std::cin >> a >> b;
		if (std::cin.eof()) return 0;
		if (a == 0 && b == 0) return 0;
		
		//mineLand 구조만들기
		char** mineLand = new char*[a];
		for (int xline = 0; xline < a; xline++) {
			mineLand[xline] = new char[b];
		}
		//mineLand에 들어온 한 줄당 알맞게 빈칸에 집어넣기
		std::string mineLine;
		for (int countNum = 0; countNum < a; countNum++) {
			std::cin >> mineLine;
			for (int charater = 0; charater < b; charater++) {
				mineLand[countNum][charater]=mineLine.at(charater);
			}
		}

		if (FIELD != 1) std::cout << std::endl;

		std::cout << "Field #" << FIELD++ << ":" << std::endl;

		//출력하기
		for (int xindex = 0; xindex < a; xindex++) {
			for (int yindex = 0; yindex < b; yindex++) {
				if (mineLand[xindex][yindex] == '*') std::cout << '*';
				else std::cout<<calculateMineLand(mineLand, xindex, yindex, a, b);
			}
			std::cout << std::endl;
		}


		//mineLand 삭제하기
		for (int xline = 0; xline < a; xline++) {
			delete[] mineLand[xline];
		}
		delete[] mineLand;

	}



	return 0;
}

int calculateMineLand(char** mineLand, int pointx, int pointy, int realx, int realy) {
	int ret = 0;
	for (int index = 0; index < 8; index++) {
		ret += checkMine(mineLand, pointx+dx[index], pointy+dy[index], realx, realy);
	}
	return ret;

}
int checkMine(char** mineLand, int pointx, int pointy, int realx, int realy) {
	if (pointx < 0 || pointy < 0) return 0;
	if (pointx >= realx || pointy >= realy)return 0;
	if (mineLand[pointx][pointy]=='*') return 1;
	return 0;
}

/* @END_OF_SOURCE_CODE@ */