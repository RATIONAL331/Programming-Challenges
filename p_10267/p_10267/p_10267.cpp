
/* @JUDGE_ID: RATIONAL331 10267 C++ */
/* @BEGIN_OF_SOURCE_CODE */

#include<iostream>
#include<string>
#include<fstream>

void deleteBoard(char**, int);
void fill(char**, int, int, int, int, int, int, char);
void printBoard(char** , int, int);
void calculateBoard(char**, int, int, int, int, char, char);

int main() {
	// first_command는 들어오는 줄에서 명령을 담당하는 첫번째 문자
	char first_command; 

	// 각종 칠하는데 사용하는 변수들
	int m, n, x, y, x1, x2, y1, y2; char c; std::string name;

	// board는 그림판을 나타내기 위한 변수;
	char** board = nullptr;

	//std::ofstream outFile("ouput.txt");

	while (true) {


		std::cin >> first_command;

		if (std::cin.eof() && board != nullptr) {
			deleteBoard(board, n);
			//outFile.close();
			return 0;
		}

		switch (first_command) {

		// x*y 이미지를 새로 만든다.
		case 'I':
			if (board != nullptr) {
				deleteBoard(board, n);
			}
			std::cin >> m >> n;
			board = new char*[n];
			for (int i = 0; i < n; i++) board[i] = new char[m];

			fill(board, m, n, 0, m - 1, 0, n - 1, 'O');

			break;

		// 모든 픽셀을 흰색으로 칠한다.
		case 'C':
			if (board != nullptr) {
				fill(board, m, n, 0, m-1, 0, n-1, 'O');
			}
			break;

		// (x,y)를 c로 칠한다.
		case 'L':
			if (board != nullptr) {
				std::cin >> x >> y >> c;
				fill(board, m, n, x-1, x-1, y-1, y-1, c);
			}
			break;

		// x열에 y1행부터 y2행까지 수직으로 c로 칠함
		case 'V':
			if (board != nullptr) {
				std::cin >> x >> y1 >> y2 >> c;
				fill(board, m, n, x-1, x-1, y1-1, y2-1, c);
		}
			break;

		// x1열부터 x2열 까지 y열에 수평으로 c로 칠함
		case 'H':
			if (board != nullptr) {
				std::cin >> x1 >> x2 >> y >> c;
				fill(board, m, n, x1-1, x2-1, y-1, y-1, c);
			}
			break;

		// (x1,y1) 부터 (x2,y2)로 표현된 직사각형을 c로 칠함
		case 'K':
			if (board != nullptr) {
				std::cin >> x1 >> y1 >> x2 >> y2 >> c;
				fill(board, m, n, x1-1, x2-1, y1-1, y2-1, c);
			}
			break;

		// (x,y)와 같은 색깔을 가진 부분을 c로 칠하기(재귀)
		case 'F':
			if (board != nullptr) {
				std::cin >> x >> y >> c;
				int tempX = x - 1; int tempY = y - 1;
				char originalC = board[tempY][tempX];
				calculateBoard(board, m, n, tempX, tempY, originalC, c);
			}
			break;

		// 파일명 + 배열 출력
		case 'S':
			if (board != nullptr) {
				std::cin >> name;
				std::cout << name << std::endl;
				printBoard(board, m, n);


				/*
				outFile << name << std::endl;
				for (int yIdx = 0; yIdx < n; yIdx++) {
					for (int xIdx = 0; xIdx < m; xIdx++) {
						outFile << board[yIdx][xIdx];
					}
					outFile << std::endl;
				}
				*/
			}
			else {
				std::cin >> name;
				std::cout << name << std::endl;
				
				//outFile << name << std::endl;
			}
			break;

		// 세션 종료
		case 'X':
			if (board != nullptr) {
				deleteBoard(board, n);
			}
			//outFile.close();
			return 0;
		}
	}
	return 0;
}

void deleteBoard(char** board, int m) {
	for (int i = 0; i < m; i++) delete[] board[i];
	delete[] board;	
}

void fill(char** board, int m, int n, int x1, int x2, int y1, int y2, char c) {
	if (x1 > x2) std::swap(x1, x2);
	if (y1 > y2) std::swap(y1, y2);
	if (x1 < 0 || y1 < 0 || x2 >= m || y2 >= n) return;

	for (int yIdx = y1; yIdx <= y2; yIdx++) {
		for (int xIdx = x1; xIdx <= x2; xIdx++) {
			board[yIdx][xIdx] = c;
		}
	}
	return;
}
void printBoard(char** board, int m, int n) {
	for (int yIdx = 0; yIdx < n; yIdx++) {
		for (int xIdx = 0; xIdx < m; xIdx++) {
			std::cout << board[yIdx][xIdx];
		}
		std::cout << std::endl;
	}

}

void calculateBoard(char** board, int m, int n, int tempX, int tempY, char originalC, char c) {
	if (tempX < 0 || tempY < 0 || tempX >= m || tempY >= n) return;
	if (originalC == c) return; //이 부분을 처리하지 않으면 무한반복에 걸린다 (갔던 곳을 또 갔다옴)

	fill(board, m, n, tempX, tempX, tempY, tempY, c);

	if (tempX - 1 >= 0) if(board[tempY][tempX - 1] == originalC) calculateBoard(board, m, n, tempX - 1, tempY, originalC, c);
	if (tempY - 1 >= 0) if(board[tempY - 1][tempX] == originalC) calculateBoard(board, m, n, tempX, tempY - 1, originalC, c);
	if (tempX + 1 <= m - 1) if (board[tempY][tempX + 1] == originalC) calculateBoard(board, m, n, tempX + 1, tempY, originalC, c);
	if (tempY + 1 <= n - 1) if (board[tempY + 1][tempX] == originalC) calculateBoard(board, m, n, tempX, tempY + 1, originalC, c);
	
	return;
}
/* @BEGIN_OF_SOURCE_CODE */


