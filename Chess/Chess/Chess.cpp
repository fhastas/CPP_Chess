#include <iostream>
#include <algorithm>
#include "Chess.h"
#include "Queue.h"
using namespace std;

void Piece::changeCode(string code) {
	this->pieceCode = code;
	return;
}

void Piece::changeMoveCount(bool mc) {
	if (mc == 0) {			// 넣을 값이 0이라면 moveCount 값을 0으로 변경
		this->moveCount = mc;
		return;
	}
	this->moveCount += mc;	// 아니라면 넣을 값을 원래 값에 추가
	return;
}

string Piece::showCode() {
	return this->pieceCode;
}

bool Piece::showMoveCount() {
	return this->moveCount;
}

void Chess::insertCellName(string na) {
	this->CellName = na;
	return;
}
void Chess::insertColor(string color) {
	this->Color = color;
	return;
}
void Chess::insertCellNum(int num) {
	this->CellNum = num;
	return;
}
void Chess::insertExist(bool ex) {
	this->Exist = ex;
	return;
}
void Chess::insertWBoarder(bool bo) {
	this->WBorder = bo;
	return;
}
void Chess::insertEBoarder(bool bo) {
	this->EBorder = bo;
	return;
}
void Chess::insertNBoarder(bool bo) {
	this->NBorder = bo;
	return;
}
void Chess::insertSBoarder(bool bo) {
	this->SBorder = bo;
	return;
}
void Chess::insertResRook(bool r) {
	this->resRook = r;
	return;
}
void Chess::insertResBishop(bool r) {
	this->resBishop = r;
	return;
}
void Chess::insertResKnight(bool r) {
	this->resKnight = r;
	return;
}
void Chess::insertResQueen(bool r) {
	this->resQueen = r;
	return;
}
void Chess::insertResKing(bool r) {
	this->resKing = r;
	return;
}
void Chess::insertResPawn(bool r) {
	this->resPawn = r;
	return;
}

string Chess::showCellName() {
	return this->CellName;
}
string Chess::showColor() {
	return this->Color;
}
bool Chess::showExist() {
	return this->Exist;
}
bool Chess::showEBorder() {
	return this->EBorder;
}
bool Chess::showWBorder() {
	return this->WBorder;
}
bool Chess::showSBorder() {
	return this->SBorder;
}
bool Chess::showNBorder() {
	return this->NBorder;
}
bool Chess::showCellNum() {
	return this->CellNum;
}
bool Chess::showResRook() {
	return this->resRook;
}
bool Chess::showResBishop() {
	return this->resBishop;
}
bool Chess::showResKnight() {
	return this->resKnight;
}
bool Chess::showResQueen() {
	return this->resQueen;
}
bool Chess::showResKing() {
	return this->resKing;
}
bool Chess::showResPawn() {
	return this->resPawn;
}


void Chess::initData(Chess* p) {
	int i, j, lineNum = 1;							// i, j : for문 , lineNum : 열 숫자
	string wpNum = "1", bpNum = "1", cnNum = "1";	// wp, bp, cn : name에  넣을 숫자
	for (i = 1; i <= 64; i++) {
		/// Piece들의 정보 입력 ///
		//초기 흰색 Piece들의 정보 입력
		if (i <= 16) {
			switch (i) {
			case (1):
				p->piece->changeCode("WR1");
				p->piece->changeMoveCount(0);
				break;
			case (2):
				p->piece->changeCode("WN1");
				p->piece->changeMoveCount(0);
				break;
			case (3):
				p->piece->changeCode("WB1");
				p->piece->changeMoveCount(0);
				break;
			case (4):
				p->piece->changeCode("WK");
				p->piece->changeMoveCount(0);
				break;
			case (5):
				p->piece->changeCode("WQ");
				p->piece->changeMoveCount(0);
				break;
			case (6):
				p->piece->changeCode("WB2");
				p->piece->changeMoveCount(0);
				break;
			case (7):
				p->piece->changeCode("WN2");
				p->piece->changeMoveCount(0);
				break;
			case (8):
				p->piece->changeCode("WR2");
				p->piece->changeMoveCount(0);
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
				p->piece->changeCode(wp);
				wpNum[0] += 1;	// 1->2, 2->3, ...

				p->piece->changeMoveCount(0);
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
				p->piece->changeCode(bp);
				bpNum[0] += 1;	// 1->2, 2->3, ...

				p->piece->changeMoveCount(0);
				break;
			}
			case (57):
				p->piece->changeCode("BR1");
				p->piece->changeMoveCount(0);
				break;
			case (58):
				p->piece->changeCode("BN1");
				p->piece->changeMoveCount(0);
				break;
			case (59):
				p->piece->changeCode("BB1");
				p->piece->changeMoveCount(0);
				break;
			case (60):
				p->piece->changeCode("BK");
				p->piece->changeMoveCount(0);
				break;
			case (61):
				p->piece->changeCode("BQ");
				p->piece->changeMoveCount(0);
				break;
			case (62):
				p->piece->changeCode("BB2");
				p->piece->changeMoveCount(0);
				break;
			case (63):
				p->piece->changeCode("BN2");
				p->piece->changeMoveCount(0);
				break;
			case (64):
				p->piece->changeCode("BR2");
				p->piece->changeMoveCount(0);
				break;
			}
		}

		/// 칸들의 정보 ///
		// CellName
		string cName;
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
		p->insertCellName(cName);
		cName.clear();

		// Color
		if ((((lineNum % 2) == 1) && ((i % 2) == 1)) || (((lineNum % 2) == 0) && ((i % 2) == 0))) {			// XAND
			p->insertColor(" ■ ");
		}
		else if ((((lineNum % 2) == 1) && ((i % 2) == 0)) || (((lineNum % 2) == 0) && ((i % 2) == 1))) {	// XOR
			p->insertColor(" □ ");
		}

		// CellNum
		p->insertCellNum(i);

		// Exist
		if ((i <= 16) or (i > 48)) {
			p->insertExist(true);
		}

		// Boarder
		if (i % 8 == 1) {
			p->insertEBoarder(true);
		}
		if (i % 8 == 0) {
			p->insertWBoarder(true);
		}
		if (i <= 8) {
			p->insertSBoarder(true);
		}
		if (i >= 57) {
			p->insertNBoarder(true);
		}
		if ((i % 8) == 0) {	// 줄이 바뀔 때마다
			lineNum++;			// 숫자 증가
			cnNum[0]++;			// 1->2, 2->3, ...
		}
		p++;			// 다음 칸으로
	}
	for (j = 0; j < 64; j++) // 제자리로 (cell[0]으로)
		p--;

	return;
}

void Chess::initResData(Chess* p) {
	for (int i = 0; i < 64; i++) {
		p->insertResPawn(false);
		p->insertResRook(false);
		p->insertResBishop(false);
		p->insertResKnight(false);
		p->insertResQueen(false);
		p->insertResKing(false);
		p++;
	}
	return;
}

bool Chess::checkInput(Chess cell[], char secPiece[], char secCell[], int color) {
	char* fInput, * sInput;
	int i, j;

	string code;
	string cellName;
	fInput = secPiece;
	sInput = secCell;

	for (i = 0; i < 3; i++) {				// 입력된 값이 소문자라면
		if ((secPiece[i] > 96 && secPiece[i] < 123) || (secCell[i] > 96 && secCell[i] < 123)) {
			*fInput = toupper(secPiece[i]);		// 대문자로 변경
			*sInput = toupper(secCell[i]);
		}

		if (secPiece[i] != NULL)		// string에 쓰래기 값 추가 방지
			code += secPiece[i];			// 변환된 글자를 code에 추가
		if (secCell[i] != NULL)			// string에 쓰래기 값 추가 방지
			cellName += secCell[i];			// cellName에 추가

		fInput++;					// 다음 글자로 이동
		sInput++;					//		``
	}

	int check = 0;
	for (j = 0; j < 64; j++) {		// 칸에 있는 값인지 확인
		if (code.compare(cell[j].piece->showCode()) == 0)
			check++;
		if (cellName.compare(cell[j].showCellName()) == 0)
			check++;

		if (check == 2)	// 맞는 색깔인지 확인하기 위해 3으로 수정할 필요 있음
			break;
	}

	if ((color == 0) && (code[0] == 'W')) {			// 턴에 움직일 수 있는 색깔인지 확인
		check++;
	}
	else if ((color == 1) && (code[0] == 'B')) {
		check++;
	}

	if (check == 3) {		// 입력한 값이 전부 유효한 값이라면
		cell->RangeCheck(cell, secPiece);		// 입력한 기물의 이동 통제 데이터 설정
		return possibleMove(cell, secCell, secPiece); 	// possibleMove의 반환값 반환
	}
	return false;			// 아니라면 false 반환
}

bool Chess::swapData(Chess* p1, Chess* p2) {
	bool eat = false;
	if ((p2->Exist == true) && (p1 != p2)) {	// 이동할 자리에 기물이 있다면
		p2->Exist = false;							// false로 변경
		eat = true;									// eat true로 변경
	}
	p1->piece->changeMoveCount(true);
	p2->piece->changeMoveCount(true);
	swap(p1->Exist, p2->Exist);	// p1 <-> p2 Exist 데이터 스왑
	swap(p1->piece, p2->piece);	//			 piece 주소 스왑
	return eat;					// 기물을 먹었는지 안먹었는지 bool 값을 반환
}

string Chess::movePiece(Chess cell[], string name, string cellname) {
	string result;
	int i;
	int movingPiece, placeToMove;

	for (i = 0; i < 64; i++) {					// 선택한 기물, 칸 찾기
		if (name == cell[i].piece->showCode()) {	// pieceCode가 같다면
			movingPiece = i;							// 해당 index값 movingPiece에 넣기
		}
		if (cellname == cell[i].CellName) {			// cellName가 같다면
			placeToMove = i;							// 해당 index값을 placeToMove에 넣기
		}
	}

	if (cell[movingPiece].piece->showCode()[1] != 'P') {	// 폰이 아니라면
		result = cell[movingPiece].piece->showCode()[1];		// 해당 기물 code 추가
	}

	if (swapData(&cell[movingPiece], &cell[placeToMove])) {	
		result += 'x';				// 기물을 먹었다는 표시
	}
	else {
		if (cell[placeToMove].piece->showCode()[0] == 'W')
			result += ".";			// 흰색이 움직였다는 표시
		else
			result += "...";		// 검은색이 움직였다는 표시
	}
	result += tolower(cell[placeToMove].CellName[0]);		// 움직인 칸의 이름를 소문자로 변환후 추가
	result += cell[placeToMove].CellName[1];				// 그 뒤 글자도 추가
	return result;											// 해당 턴의 기보 결과 반환
}

int Chess::kingCheck(Chess* p) {
	for (int i = 0; i < 64; i++) {
		if (p->showExist()) {
			if (p->piece->showCode()[1] == 'K') {
				if (p->resPawn || p->resRook || p->resBishop || p->resKnight || p->resQueen || p->resKing) {
					if (p->piece->showCode()[0] == 'W')
						return 1;
					if (p->piece->showCode()[0] == 'B')
						return 2;
				}
			}
		}
		p++;
	}
	return 0;
}

void Chess::promotion(Chess* p) {
	char what;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 8; j++) {
			if (p->Exist == true) {					// 탐색한 칸에 기물이 존재하는데
				if (p->piece->showCode()[1] == 'P') {	// 그 기물이 폰이라면
					cout << "여왕 : 1 / 룩 : 2 / 비숍 : 3 / 나이트 : 4" << endl;
					cout << "폰을 어떤 기물로 승급시키시겠습니까? : ";
					cin >> what;
					if (p->piece->showCode()[0] == 'W') {		// 흰색이라면
						switch (what)
						{
						case 49:
							p->piece->changeCode("WQP");
							break;
						case 50:
							p->piece->changeCode("WRP");
							break;
						case 51:
							p->piece->changeCode("WBP");
							break;
						case 52:
							p->piece->changeCode("WNP");
							break;
						default:
							cout << "잘못된 입력입니다!";

						}
					}
					else if (p->piece->showCode()[0] == 'B') {	// 검은색이라면
						switch (what)
						{
						case 49:
							p->piece->changeCode("BQP");
							break;
						case 50:
							p->piece->changeCode("BRP");
							break;
						case 51:
							p->piece->changeCode("BBP");
							break;
						case 52:
							p->piece->changeCode("BNP");
							break;
						default:
							cout << "잘못된 입력입니다!";

						}
					}
				}
			}
			p++;
		}
		if (i == 0)						// 처음한 반복이라면 
			p += 48;
		//for (int k = 0; k < 48; k++)	// 48칸 앞으로 이동
		//	p++;
	}

	return;
}