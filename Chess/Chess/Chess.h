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
	void changeCode(string code);		// pieceCode�� ������ ���� �Ǵ� �ֱ�
	void changeMoveCount(int mc);		// moveCount�� ������ ���� �Ǵ� �ֱ�

	string showCode();					// pieceCode ��ȯ
	int showMoveCount();				// moveCount ��ȯ
};

class Chess {
private:
	string CellName;		// ĭ�� �̸�	// A1 ~ H8
	string Color;			// ĭ�� ��		// ���
	int CellNum = NULL;		// ĭ�� ��ȣ	// 0 ~ 63	(index)
	bool Exist = false;		// �⹰�� ����	// true, false
	bool Border = false;	// ĭ�� ��輱	// true, false
public:
	Piece* piece = NULL;

	void insertCellName(string name);	// CellName�� ������ �ֱ� 
	void insertColor(string color);		// Color�� ������ �ֱ�
	void insertCellNum(int num);		// CellNum�� ������ �ֱ�
	void insertExist(bool e);			// Exist�� ������ �ֱ�
	void insertBoarder(bool b);			// Boarder�� ������ �ֱ�
	void initData(Chess* p);			// ü���� ���� �����ϱ�
	void promotion(Chess* p);					// ���� ���θ��

	string showCellName();			// CellName ��ȯ
	string showColor();				// Color ��ȯ
	bool showExist();				// Exist ��ȯ
	bool showBorder();				// Border ��ȯ

	bool checkInput(Chess cell[], char secPiece[], char secCell[]);			// �Է��� ���� ��ȿ�� �������� Ȯ��

	bool swapData(Chess* p1, Chess* p2);						// ���� ������ �ٲٱ�
	string movePiece(Chess cell[], string code, string cellname);	// �⹰ �����̱�
};
#endif //__CHESS

#ifndef __INPUT_OUTPUT
#define __INPUT_OUTPUT

void printMenu();								// Menu ���
void printBoard(Chess* p);						// ü������ ���� ��Ȳ ���
void printInfo(Chess cell[], int index);		// ������ ���� Ȯ�ο� �Լ�

#endif	//__INPUTOUTPUT