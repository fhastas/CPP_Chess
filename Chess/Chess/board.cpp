#include <algorithm>
#include "Chess.h"

void Chess::insertCellName(Chess* p, string na) {
	p->CellName = na;
	return;
}
void Chess::insertColor(Chess* p, string color) {
	p->Color = color;
	return;
}
void Chess::insertCellNum(Chess* p, int num) {
	p->CellNum = num;
	return;
}
void Chess::insertExist(Chess* p, bool ex) {
	p->Exist = ex;
	return;
}
void Chess::insertBoarder(Chess* p, bool bo) {
	p->Border = bo;
	return;
}

string Chess::showCellName(Chess* p) {
	return p->CellName;
}
string Chess::showColor(Chess* p) {
	return p->Color;
}

void Chess::initData(Chess* p) {
	int i, j, evenOdd = 1;
	string wpNum = "1";
	string bpNum = "1";
	for (i = 1; i <= 64; i++) {
		/// Piece들의 정보 입력 ///
		//초기 흰색 Piece들의 정보 입력
		if (i <= 16) {
			switch (i) {
			case (1):
				piece->changeCode(p->piece, "WR1");
				piece->changeMoveCount(p->piece, 0);
				break;
			case (2):
				piece->changeCode(p->piece, "WN1");
				piece->changeMoveCount(p->piece, 0);
				break;
			case (3):
				piece->changeCode(p->piece, "WB1");
				piece->changeMoveCount(p->piece, 0);
				break;
			case (4):
				piece->changeCode(p->piece, "WQ ");
				piece->changeMoveCount(p->piece, 0);
				break;
			case (5):
				piece->changeCode(p->piece, "WK ");
				piece->changeMoveCount(p->piece, 0);
				break;
			case (6):
				piece->changeCode(p->piece, "WB2");
				piece->changeMoveCount(p->piece, 0);
				break;
			case (7):
				piece->changeCode(p->piece, "WN2");
				piece->changeMoveCount(p->piece, 0);
				break;
			case (8):
				piece->changeCode(p->piece, "WR2");
				piece->changeMoveCount(p->piece, 0);
				break;
			case (9):
			case (10):
			case (11):
			case (12):
			case (13):
			case (14):
			case (15):
			case (16): {
				string wp;
				wp.append("WP");
				wp.append(wpNum);
				piece->changeCode(p->piece, wp);
				wpNum[0] += 1;

				piece->changeMoveCount(p->piece, 0);
				break;
			}
			}
		}
		// 초기 검은색 Piece들의 정보 입력
		else if (i >= 49) {
			switch (i) {
			case (49):
			case (50):
			case (51):
			case (52):
			case (53):
			case (54):
			case (55):
			case (56): {
				string bp;
				bp.append("BP");
				bp.append(bpNum);
				piece->changeCode(p->piece, bp);
				bpNum[0] += 1;

				piece->changeMoveCount(p->piece, 0);
				break;
			}
			case (57):
				piece->changeCode(p->piece, "BR1");
				piece->changeMoveCount(p->piece, 0);
				break;
			case (58):
				piece->changeCode(p->piece, "BN1");
				piece->changeMoveCount(p->piece, 0);
				break;
			case (59):
				piece->changeCode(p->piece, "BB1");
				piece->changeMoveCount(p->piece, 0);
				break;
			case (60):
				piece->changeCode(p->piece, "BQ ");
				piece->changeMoveCount(p->piece, 0);
				break;
			case (61):
				piece->changeCode(p->piece, "BK ");
				piece->changeMoveCount(p->piece, 0);
				break;
			case (62):
				piece->changeCode(p->piece, "BB2");
				piece->changeMoveCount(p->piece, 0);
				break;
			case (63):
				piece->changeCode(p->piece, "BN2");
				piece->changeMoveCount(p->piece, 0);
				break;
			case (64):
				piece->changeCode(p->piece, "BR2");
				piece->changeMoveCount(p->piece, 0);
				break;
			}
		}
		// 나머지 칸들의 Code 넣기
		else {
			if ((((evenOdd % 2) == 1) && ((i % 2) == 1)) || (((evenOdd % 2) == 0) && (i % 2) == 0)) {
				piece->changeCode(p->piece, " ■ ");
			}
			else if ((((evenOdd % 2) == 1) && ((i % 2) == 0)) || (((evenOdd % 2) == 0) && (i % 2) == 1)) {
				piece->changeCode(p->piece, " □ ");
			}
		}
		if ((i % 8) == 0)
			evenOdd++;		// 줄 홀수->짝수, 짝수->홀수

		/// 칸들의 정보 ///
		// CellName
		string cName;
		string cnNum = "1";
		switch (i % 8)
		{
		case 1:
			cName.append("H");
			break;
		case 2:
			cName.append("G");
			break;
		case 3:
			cName.append("F");
			break;
		case 4:
			cName.append("E");
			break;
		case 5:
			cName.append("D");
			break;
		case 6:
			cName.append("C");
			break;
		case 7:
			cName.append("B");
			break;
		case 0:
			cName.append("A");
			break;
		}
		cName.append(cnNum);
		insertCellName(p, cName);
		cName.clear();

		// Color
		if ((((evenOdd % 2) == 1) && ((i % 2) == 1)) || (((evenOdd % 2) == 0) && ((i % 2) == 0))) {			// XAND
			insertColor(p, " □ ");
		}
		else if ((((evenOdd % 2) == 1) && ((i % 2) == 0)) || (((evenOdd % 2) == 0) && ((i % 2) == 1))) {	// XOR
			insertColor(p, " ■ ");
		}

		// CellNum
		insertCellNum(p, i);

		// Exist
		if ((i <= 16) or (i >= 57)) {
			insertExist(p, true);
		}
		else {
			insertExist(p, false);
		}

		// Boarder
		if ((i <= 8) or (i >= 57) or ((i % 8) == 0) or ((i % 8) == 1)) {
			insertBoarder(p, true);
		}
		else {
			insertBoarder(p, false);
		}

		p++;	// 다음 칸으로
	}
	for (j = 0; j < 64; j++) // 제자리로 (p[0]으로)
		p--;

	return;
}

void Chess::movePiece(Chess cell[], string code, string cellname) {
	int i, j;
	int num1, num2, cellNum1, cellNum2;

	for (i = 0; i < 64; i++) {
		if (code == cell[i].piece->showCode(cell[i].piece)) {
			cellNum1 = i;
		}
	}
	num1 = ((int)cellname[0] - 4) % 10;
	num2 = ((int)cellname[1] + 2) % 10;
	cellNum2 = (num1 + ((num2 - 1) * 8)) - 1;

	swap(cell[cellNum1].piece, cell[cellNum2].piece);
	return;
}