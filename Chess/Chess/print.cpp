#include <iostream>
#include "Chess.h"

void printLongSquare(int eo, int num) {
	if (num == 1) {				// 홀수 번째 줄
		cout << "  │■  ■  ■┃□  □  □┃■  ■  ■┃□  □  □┃■  ■  ■┃□  □  □┃■  ■  ■┃□  □  □│" << endl;
	}
	else if (num == 0) {		// 짝수 번째 줄
		cout << "  │□  □  □┃■  ■  ■┃□  □  □┃■  ■  ■┃□  □  □┃■  ■  ■┃□  □  □┃■  ■  ■│" << endl;
	}

	if (eo == 0) {				//
		cout << "  ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤" << endl;
	}

	return;
}
void printShortSquare(int eo, int num) {
	if (((eo == 0) && (num == 0)) || ((eo == 1) && (num == 1))) {		// XAND
		cout << " ■│□ ";
		return;
	}
	else if (((eo == 1) && (num == 0)) || ((eo == 0) && (num == 1))) {	// XOR
		cout << " □│■ ";
		return;
	}
}
void printBoard(Chess* p) {
	int i, j, k;
	char row = 'A', col = '8';
	for (j = 0; j < 63; j++)				// 끝으로 이동 p[63]
		p++;
	cout << endl;
	cout << "  ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐" << endl;
	for (i = 1; i < 9; i++) {
		printLongSquare(1, i % 2);
		for (j = 1; j < 8; j++) {
			if (j == 1) {					// 처음 행일 경우
				cout << col;				// 1 ~ 8 출력
				if ((i % 2) == 0) {				// 짝수일 경우
					cout << " │□ ";
				}
				else if ((i % 2) == 1) {		// 홀수일 경우
					cout << " │■ ";
				}
			}

			if (p->showExist()) {				// 말이 존재할 경우
				cout << p->piece->showCode();		// pieceCode 출력
												// 출력한 기물이 King 또는 Queen일 경우
				if ((p->piece->showCode()[1] == 'K') || (p->piece->showCode())[1] == 'Q') {
					if(p->piece->showCode()[2] == NULL)
						cout << " ";				// 한 칸 더 띄우기
				}
			}
			else {								// 아닐 경우
				cout << p->showColor();				// Color 출력
			}
			printShortSquare((i % 2), (j % 2));
			p--;	// 다음 칸으로

			if (j == 7) {						// 마지막 행일 경우 그리고
				if (p->showExist()) {				// 말이 존재할 경우
					cout << p->piece->showCode();		// Code 출력
													// 출력된 말이 킹 또는 퀸일 경우
					if ((p->piece->showCode()[1] == 'K') || (p->piece->showCode())[1] == 'Q') {
						if (p->piece->showCode()[2] == NULL)
							cout << " ";				// 한 칸 더 띄우기
					}
				}
				else {								// 아닐 경우
					cout << p->showColor();				// Color 출력
				}
				if ((i % 2) == 0) {					// 짝수일 경우 
					cout << " ■│" << endl;		
				}
				else if ((i % 2) == 1) {			// 홀수일 경우
					cout << " □│" << endl;
				}
				p--;	// 다음 칸으로
			}
		}
		if ((i % 8) == 0) {					// 마지막 줄일 경우
			printLongSquare(1, i % 2);		
		}
		else {								// 아닐경우
			printLongSquare(0, i % 2);
		}
		col--;	// 8->7, 7->6, ...
	}
	cout << "  └───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┘" << endl;

	for (k = 0; k < 8; k++) {				// A ~ H 출력
		cout << "      " << row << " ";
		row++;
	}
	cout << endl;

	return;
}

void printMenu() {
	cout
		<< "┌───────────────┐" << "\n"
		<< "│ 1. 게임 시작 \t│" << "\n"
		<< "│ 2. 게임 설명 \t│" << "\n"
		<< "│ 3. 게임 종료 \t│" << "\n"
		<< "└───────────────┘" << "\n기능을 선택해주세요>>";
	return;
}

void printInfo(Chess cell[], int index) {
	cout << cell[index].showCellName() << endl;
	cout << cell[index].showWBorder() << endl;
	return;
}