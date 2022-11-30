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
	void changeCode(string code);		// pieceCode에 데이터 변경 또는 넣기
	void changeMoveCount(int mc);		// moveCount에 데이터 변경 또는 넣기

	string showCode();					// pieceCode 반환
	int showMoveCount();				// moveCount 반환
};

class Chess {
private:
	string CellName;		// 칸의 이름	// A1 ~ H8
	string Color;			// 칸의 색		// □■
	int CellNum = NULL;		// 칸의 번호	// 0 ~ 63	(index)
	bool Exist = false;		// 기물의 유무	// true, false
	bool Border = false;	// 칸의 경계선	// true, false
public:
	Piece* piece = NULL;

	void insertCellName(string name);	// CellName에 데이터 넣기 
	void insertColor(string color);		// Color에 데이터 넣기
	void insertCellNum(int num);		// CellNum에 데이터 넣기
	void insertExist(bool e);			// Exist에 데이터 넣기
	void insertBoarder(bool b);			// Boarder에 데이터 넣기
	void initData(Chess* p);			// 체스판 기초 설정하기
	void promotion(Chess* p);					// 폰의 프로모션

	string showCellName();			// CellName 반환
	string showColor();				// Color 반환
	bool showExist();				// Exist 반환
	bool showBorder();				// Border 반환

	bool checkInput(Chess cell[], char secPiece[], char secCell[]);			// 입력한 값이 유효한 범위인지 확인

	bool swapData(Chess* p1, Chess* p2);						// 서로 데이터 바꾸기
	string movePiece(Chess cell[], string code, string cellname);	// 기물 움직이기
};
#endif //__CHESS

#ifndef __INPUT_OUTPUT
#define __INPUT_OUTPUT

void printMenu();								// Menu 출력
void printBoard(Chess* p);						// 체스판의 현재 상황 출력
void printInfo(Chess cell[], int index);		// 데이터 정보 확인용 함수

#endif	//__INPUTOUTPUT