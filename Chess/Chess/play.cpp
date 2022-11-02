#include <iostream>
#include <Windows.h>
#include "Chess.h"
using namespace std;

int main() {
	int i;
	Chess cell[64];
	for (i = 0; i < 64; i++) {
		cell[i].piece = new Piece;
	}
	Chess* p = cell;

	int start, end;
	int turn = 0;
	char secPiece[3], secCell[3];

	while (true) {
		p->initData(p);
		system("cls");
		system("mode con cols=80 lines=80");
		start = printMenu();
		system("cls");

		if (start == 1) {
			while (true) {
				printBoard(p);
				turn++;
				if ((turn % 2) == 0)
					cout << "(흑)";
				else
					cout << "(백)";
				cout << "움직일 말과 움직일 칸을 선택해주세요." << "\n"
					<< "(ex)>>WP1 A3 >>";
				cin >> secPiece >> secCell;
				p->movePiece(cell, secPiece, secCell);
			}
		}
		else if (start == 2) {
			system("cls");
			cout << "체스 설명" << endl;
		}
		else if (start == 3) {
			cout << "종료하시겠습니까? \n(Y = 1, N = 2)>>";
			cin >> end;
			if (end == 1) {
				return 0;
			}
			else {
				continue;
			}
		}
	}
}
