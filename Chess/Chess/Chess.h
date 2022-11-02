#pragma once
#include <string>
using namespace std;

#ifndef __CHESS
#define __CHESS
class Piece {
private:
	string pieceCode;		//체스판에 표시되는 기물의 이름 W or B P, B, N, Q, K (빈칸에는 □■)
	int moveCount = 0;		//기물이 움직인 횟수
public:
	void changeCode(Piece* p, string code);
	void changeMoveCount(Piece* p, int mc);

	string showCode(Piece* p);
	int showMoveCount(Piece* p);
};

class Chess {
private:
	string CellName;		//칸의 이름		// A1 ~ H8
	string Color;			//칸의 색		// □■
	int CellNum = NULL;		//칸의 번호		// 1 ~ 64
	bool Exist = false;		//기물의 유무	// true, false
	bool Border = false;	//칸의 경계선	// true, false
public:
	Piece* piece = NULL;

	void insertCellName(Chess* p, string name);		// CellName에 데이터 넣기 
	void insertColor(Chess* p, string color);		// Color에 데이터 넣기
	void insertCellNum(Chess* p, int num);			// CellNum에 데이터 넣기
	void insertExist(Chess* p, bool e);				// Exist에 데이터 넣기
	void insertBoarder(Chess* p, bool b);			// Boarder에 데이터 넣기
	void initData(Chess* p);						// 체스판 기초 설정하기

	string showCellName(Chess* p);					// CellName 반환
	string showColor(Chess* p);						// Color 반환

	void movePiece(Chess cell[], string code, string cellname);	// 기물 움직이기
};
#endif //__CHESS

#ifndef __PRINT
#define __PRINT

int printMenu();								// Menu 출력
void printBoard(Chess* p);						// 체스판의 현재 상황 출력							

#endif	//__PRINT