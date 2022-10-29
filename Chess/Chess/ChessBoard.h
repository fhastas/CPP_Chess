#pragma once
#include <iostream>
using namespace std;

#ifndef __CHESS
#define	__CHESS
//class ChessBoard //체스판 클래스
//{
//private:
//	string CellName;//칸의 이름
//	string Color;//칸의 색
//	int CellNum;//칸의 번호
//	bool Exist;//기물의 유무
//	bool Border;//칸의 경계선
//
//	string ChessPiece;//기물 이름		W or B P(폰), R(룩), B(비숍), N(나이트), Q(퀸), K(킹) 
//	string Code;//체스판에 표시되는 기물의 이름
//	int MoveCount;//기물이 움직인 횟수
//public:
//	string tempcode;//code 값을 저장하는 변수
//	string tempcode2;
//	string tempCellName;//CellName 값을 저장하는 변수
//	string tempcolor;//color 값을 저장하는 변수
//	bool tempexist;//exist 값을 저장하는 변수
//	string tempChessPiece;//ChessPiece 값을 저장하는 변수
//	int tempmove;//move 값을 저장하는 변수
//	bool tempborder;//border값을 저장하는 변수
//
//	string temp1;// swap함수에서 쓰이는 변수
//	int temp2;
//
//};

enum Cellrow {A, B, C, D, E, F, G, H};

class Chess //체스판 클래스
{
private:
	string CellName;//칸의 이름		//A1 ~ H8
	string Color;//칸의 색			//□■
	int CellNum;//칸의 번호			//
	bool Exist;//기물의 유무
	bool Border;//칸의 경계선
		
	string ChessPiece;//기물 이름		W or B P(폰), R(룩), B(비숍), N(나이트), Q(퀸), K(킹) 
	string Code;//체스판에 표시되는 기물의 이름
	int MoveCount = 0;//기물이 움직인 횟수
public:
	void initData(Chess* p);
	void insertCellName();
	void insertColor();
	void insertCellNum();
	void insertExist();
	void insertBoarder();
	void insertChessPiece();
	void insertCode();
	void insertMoveCount();

	void printBoard();

	void swapData();
};
#endif