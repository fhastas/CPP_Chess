#include <iostream>
#include "Chess.h"

void printLongSquare(int eo, int num) {
	if (num == 1) {
		cout << "  │■  ■  ■┃□  □  □┃■  ■  ■┃□  □  □┃■  ■  ■┃□  □  □┃■  ■  ■┃□  □  □│" << endl;
	}
	else if (num == 0) {
		cout << "  │□  □  □┃■  ■  ■┃□  □  □┃■  ■  ■┃□  □  □┃■  ■  ■┃□  □  □┃■  ■  ■│" << endl;
	}

	if (eo == 0) {
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
	for (j = 0; j < 63; j++)	// 끝으로 이동 p[63]
		p++;
	for (k = 0; k < 8; k++) {
		cout << "      " << row << " ";
		row++;
	}
	cout << endl;
	cout << "  ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐" << endl;
	for (i = 1; i < 9; i++) {
		printLongSquare(1, i % 2);
		for (j = 1; j < 8; j++) {
			if (j == 1) {
				cout << col;
				if ((i % 2) == 0) {
					cout << " │□ ";
				}
				else if ((i % 2) == 1) {
					cout << " │■ ";
				}
			}
			cout << p->piece->showCode(p->piece);
			printShortSquare((i % 2), (j % 2));
			p--;	// 다음 칸으로
			if (j == 7) {
				if ((i % 2) == 0) {
					cout << p->piece->showCode(p->piece) << " ■│" << endl;
				}
				else if ((i % 2) == 1) {
					cout << p->piece->showCode(p->piece) << " □│" << endl;
				}
				p--;	// 다음 칸으로
			}
		}
		if ((i % 8) == 0) {
			printLongSquare(1, i % 2);
		}
		else {
			printLongSquare(0, i % 2);
		}
		col--;
	}
	cout << "  └───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┘" << endl;

	return;
}

int printMenu() {
	int f;
	while (1) {
		cout
			<< "┌───────────────┐" << "\n"
			<< "│ 1. 게임 시작 \t│" << "\n"
			<< "│ 2. 게임 설명 \t│" << "\n"
			<< "│ 3. 게임 종료 \t│" << "\n"
			<< "└───────────────┘" << "\n기능을 선택해주세요>>";
		cin >> f;

		return f;
	}
}