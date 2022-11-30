#pragma once
#include <string>
using namespace std;

#ifndef __CHESS
#define __CHESS
class Piece {
private:
	string pieceCode;		//ü���ǿ� ǥ�õǴ� �⹰�� �̸� W or B P, B, N, Q, K (��ĭ���� ���)
	int moveCount = 0;		//�⹰�� ������ Ƚ��
public:
	void changeCode(Piece* p, string code);
	void changeMoveCount(Piece* p, int mc);

	string showCode(Piece* p);
	int showMoveCount(Piece* p);
};

class Chess {
private:
	string CellName;		//ĭ�� �̸�		// A1 ~ H8
	string Color;			//ĭ�� ��		// ���
	int CellNum = NULL;		//ĭ�� ��ȣ		// 1 ~ 64
	bool Exist = false;		//�⹰�� ����	// true, false
	bool Border = false;	//ĭ�� ��輱	// true, false
public:
	Piece* piece = NULL;

	void insertCellName(Chess* p, string name);		// CellName�� ������ �ֱ� 
	void insertColor(Chess* p, string color);		// Color�� ������ �ֱ�
	void insertCellNum(Chess* p, int num);			// CellNum�� ������ �ֱ�
	void insertExist(Chess* p, bool e);				// Exist�� ������ �ֱ�
	void insertBoarder(Chess* p, bool b);			// Boarder�� ������ �ֱ�
	void initData(Chess* p);						// ü���� ���� �����ϱ�

	string showCellName(Chess* p);					// CellName ��ȯ
	string showColor(Chess* p);						// Color ��ȯ

	void movePiece(Chess cell[], string code, string cellname);	// �⹰ �����̱�
};
#endif //__CHESS

#ifndef __PRINT
#define __PRINT

int printMenu();								// Menu ���
void printBoard(Chess* p);						// ü������ ���� ��Ȳ ���							

#endif	//__PRINT