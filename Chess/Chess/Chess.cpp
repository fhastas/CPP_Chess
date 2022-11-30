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
	if (mc == 0) {			// ���� ���� 0�̶�� moveCount ���� 0���� ����
		this->moveCount = mc;
		return;
	}
	this->moveCount += mc;	// �ƴ϶�� ���� ���� ���� ���� �߰�
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
	int i, j, lineNum = 1;							// i, j : for�� , lineNum : �� ����
	string wpNum = "1", bpNum = "1", cnNum = "1";	// wp, bp, cn : name��  ���� ����
	for (i = 1; i <= 64; i++) {
		/// Piece���� ���� �Է� ///
		//�ʱ� ��� Piece���� ���� �Է�
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
		// �ʱ� ������ Piece���� ���� �Է�
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

		/// ĭ���� ���� ///
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
			p->insertColor(" �� ");
		}
		else if ((((lineNum % 2) == 1) && ((i % 2) == 0)) || (((lineNum % 2) == 0) && ((i % 2) == 1))) {	// XOR
			p->insertColor(" �� ");
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
		if ((i % 8) == 0) {	// ���� �ٲ� ������
			lineNum++;			// ���� ����
			cnNum[0]++;			// 1->2, 2->3, ...
		}
		p++;			// ���� ĭ����
	}
	for (j = 0; j < 64; j++) // ���ڸ��� (cell[0]����)
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

	for (i = 0; i < 3; i++) {				// �Էµ� ���� �ҹ��ڶ��
		if ((secPiece[i] > 96 && secPiece[i] < 123) || (secCell[i] > 96 && secCell[i] < 123)) {
			*fInput = toupper(secPiece[i]);		// �빮�ڷ� ����
			*sInput = toupper(secCell[i]);
		}

		if (secPiece[i] != NULL)		// string�� ������ �� �߰� ����
			code += secPiece[i];			// ��ȯ�� ���ڸ� code�� �߰�
		if (secCell[i] != NULL)			// string�� ������ �� �߰� ����
			cellName += secCell[i];			// cellName�� �߰�

		fInput++;					// ���� ���ڷ� �̵�
		sInput++;					//		``
	}

	int check = 0;
	for (j = 0; j < 64; j++) {		// ĭ�� �ִ� ������ Ȯ��
		if (code.compare(cell[j].piece->showCode()) == 0)
			check++;
		if (cellName.compare(cell[j].showCellName()) == 0)
			check++;

		if (check == 2)	// �´� �������� Ȯ���ϱ� ���� 3���� ������ �ʿ� ����
			break;
	}

	if ((color == 0) && (code[0] == 'W')) {			// �Ͽ� ������ �� �ִ� �������� Ȯ��
		check++;
	}
	else if ((color == 1) && (code[0] == 'B')) {
		check++;
	}

	if (check == 3) {		// �Է��� ���� ���� ��ȿ�� ���̶��
		cell->RangeCheck(cell, secPiece);		// �Է��� �⹰�� �̵� ���� ������ ����
		return possibleMove(cell, secCell, secPiece); 	// possibleMove�� ��ȯ�� ��ȯ
	}
	return false;			// �ƴ϶�� false ��ȯ
}

bool Chess::swapData(Chess* p1, Chess* p2) {
	bool eat = false;
	if ((p2->Exist == true) && (p1 != p2)) {	// �̵��� �ڸ��� �⹰�� �ִٸ�
		p2->Exist = false;							// false�� ����
		eat = true;									// eat true�� ����
	}
	p1->piece->changeMoveCount(true);
	p2->piece->changeMoveCount(true);
	swap(p1->Exist, p2->Exist);	// p1 <-> p2 Exist ������ ����
	swap(p1->piece, p2->piece);	//			 piece �ּ� ����
	return eat;					// �⹰�� �Ծ����� �ȸԾ����� bool ���� ��ȯ
}

string Chess::movePiece(Chess cell[], string name, string cellname) {
	string result;
	int i;
	int movingPiece, placeToMove;

	for (i = 0; i < 64; i++) {					// ������ �⹰, ĭ ã��
		if (name == cell[i].piece->showCode()) {	// pieceCode�� ���ٸ�
			movingPiece = i;							// �ش� index�� movingPiece�� �ֱ�
		}
		if (cellname == cell[i].CellName) {			// cellName�� ���ٸ�
			placeToMove = i;							// �ش� index���� placeToMove�� �ֱ�
		}
	}

	if (cell[movingPiece].piece->showCode()[1] != 'P') {	// ���� �ƴ϶��
		result = cell[movingPiece].piece->showCode()[1];		// �ش� �⹰ code �߰�
	}

	if (swapData(&cell[movingPiece], &cell[placeToMove])) {	
		result += 'x';				// �⹰�� �Ծ��ٴ� ǥ��
	}
	else {
		if (cell[placeToMove].piece->showCode()[0] == 'W')
			result += ".";			// ����� �������ٴ� ǥ��
		else
			result += "...";		// �������� �������ٴ� ǥ��
	}
	result += tolower(cell[placeToMove].CellName[0]);		// ������ ĭ�� �̸��� �ҹ��ڷ� ��ȯ�� �߰�
	result += cell[placeToMove].CellName[1];				// �� �� ���ڵ� �߰�
	return result;											// �ش� ���� �⺸ ��� ��ȯ
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
			if (p->Exist == true) {					// Ž���� ĭ�� �⹰�� �����ϴµ�
				if (p->piece->showCode()[1] == 'P') {	// �� �⹰�� ���̶��
					cout << "���� : 1 / �� : 2 / ��� : 3 / ����Ʈ : 4" << endl;
					cout << "���� � �⹰�� �±޽�Ű�ðڽ��ϱ�? : ";
					cin >> what;
					if (p->piece->showCode()[0] == 'W') {		// ����̶��
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
							cout << "�߸��� �Է��Դϴ�!";

						}
					}
					else if (p->piece->showCode()[0] == 'B') {	// �������̶��
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
							cout << "�߸��� �Է��Դϴ�!";

						}
					}
				}
			}
			p++;
		}
		if (i == 0)						// ó���� �ݺ��̶�� 
			p += 48;
		//for (int k = 0; k < 48; k++)	// 48ĭ ������ �̵�
		//	p++;
	}

	return;
}