#pragma once
#include <string>
using namespace std;

#ifndef __CHESS
#define __CHESS
class Piece {
private:
	string pieceCode;		//ü���ǿ� ǥ�õǴ� �⹰�� �̸� W or B P, B, N, Q, K (��ĭ���� ���)
	bool moveCount = false;		//�⹰�� ������ Ƚ��
public:
	void changeCode(string code);		// pieceCode�� ������ ���� �Ǵ� �ֱ�
	void changeMoveCount(bool mc);		// moveCount�� ������ ���� �Ǵ� �ֱ�

	string showCode();					// pieceCode ��ȯ
	bool showMoveCount();				// moveCount ��ȯ
};

class Chess {
private:
	string CellName;		// ĭ�� �̸�	// A1 ~ H8
	string Color;			// ĭ�� ��		// ���
	int CellNum = NULL;		// ĭ�� ��ȣ	// 0 ~ 63	(index)
	bool Exist = false;		// �⹰�� ����	// true, false
	bool EBorder = false;	// ĭ�� ��輱	// true, false
	bool WBorder = false;
	bool SBorder = false;
	bool NBorder = false;
	bool resRook = false;	// ���� �̵� ���� ����
	bool resBishop = false;	// ����� �̵� ���� ����
	bool resKnight = false;	// ����Ʈ�� �̵� ���� ����
	bool resQueen = false;	// ���� �̵� ���� ����
	bool resKing = false;	// ŷ�� �̵� ���� ����
	bool resPawn = false;	// ��� ���� �̵� ���� ����
public:
	Piece* piece = NULL;

	void insertCellName(string name);	// CellName�� ������ �ֱ� 
	void insertColor(string color);		// Color�� ������ �ֱ�
	void insertCellNum(int num);		// CellNum�� ������ �ֱ�
	void insertExist(bool e);			// Exist�� ������ �ֱ�
	void insertEBoarder(bool b);		// Boarder�� ������ �ֱ�
	void insertWBoarder(bool b);		// Boarder�� ������ �ֱ�
	void insertNBoarder(bool b);		// Boarder�� ������ �ֱ�
	void insertSBoarder(bool b);		// Boarder�� ������ �ֱ�
	void insertResRook(bool r);
	void insertResBishop(bool r);
	void insertResKnight(bool r);
	void insertResQueen(bool r);
	void insertResKing(bool r);
	void insertResPawn(bool r);
	void initData(Chess* p);			// ü���� ���� ����
	void initResData(Chess* p);			// ���� Res�����͵� ���ʰ����� ����

	string showCellName();			// CellName ��ȯ
	string showColor();				// Color ��ȯ
	bool showExist();				// Exist ��ȯ
	bool showEBorder();				// Border ��ȯ
	bool showWBorder();
	bool showNBorder();
	bool showSBorder();
	bool showCellNum();				// CellNum ��ȯ

	bool showResRook();				// Res ��ȯ
	bool showResBishop();
	bool showResKnight();
	bool showResQueen();
	bool showResKing();
	bool showResPawn();

	void RangeCheck(Chess* p, string secPiece);						// �Է��� �⹰�� �̵� ����
	bool possibleMove(Chess* p, char secCell[],char secPiece[]);					// ������ �� �ִ� ������ Ȯ��
	bool checkInput(Chess cell[], char secPiece[], char secCell[], int color);		// �Է��� ���� ��ȿ�� �������� Ȯ��

	bool swapData(Chess* p1, Chess* p2);							// ���� ������ �ٲٱ�
	string movePiece(Chess cell[], string code, string cellname);	// �⹰ �����̱�

	int kingCheck(Chess* p);
	void promotion(Chess* p);			// ���� ���θ��
};
#endif //__CHESS

#ifndef __INPUT_OUTPUT
#define __INPUT_OUTPUT

void printMenu();								// Menu ���
void printBoard(Chess* p);						// ü������ ���� ��Ȳ ���
void printInfo(Chess cell[], int index);		// ������ ���� Ȯ�ο� �Լ�

#endif	//__INPUTOUTPUT