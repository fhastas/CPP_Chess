#pragma once
#include <iostream>
using namespace std;

#ifndef __CHESS
#define	__CHESS
//class ChessBoard //ü���� Ŭ����
//{
//private:
//	string CellName;//ĭ�� �̸�
//	string Color;//ĭ�� ��
//	int CellNum;//ĭ�� ��ȣ
//	bool Exist;//�⹰�� ����
//	bool Border;//ĭ�� ��輱
//
//	string ChessPiece;//�⹰ �̸�		W or B P(��), R(��), B(���), N(����Ʈ), Q(��), K(ŷ) 
//	string Code;//ü���ǿ� ǥ�õǴ� �⹰�� �̸�
//	int MoveCount;//�⹰�� ������ Ƚ��
//public:
//	string tempcode;//code ���� �����ϴ� ����
//	string tempcode2;
//	string tempCellName;//CellName ���� �����ϴ� ����
//	string tempcolor;//color ���� �����ϴ� ����
//	bool tempexist;//exist ���� �����ϴ� ����
//	string tempChessPiece;//ChessPiece ���� �����ϴ� ����
//	int tempmove;//move ���� �����ϴ� ����
//	bool tempborder;//border���� �����ϴ� ����
//
//	string temp1;// swap�Լ����� ���̴� ����
//	int temp2;
//
//};

enum Cellrow {A, B, C, D, E, F, G, H};

class Chess //ü���� Ŭ����
{
private:
	string CellName;//ĭ�� �̸�		//A1 ~ H8
	string Color;//ĭ�� ��			//���
	int CellNum;//ĭ�� ��ȣ			//
	bool Exist;//�⹰�� ����
	bool Border;//ĭ�� ��輱
		
	string ChessPiece;//�⹰ �̸�		W or B P(��), R(��), B(���), N(����Ʈ), Q(��), K(ŷ) 
	string Code;//ü���ǿ� ǥ�õǴ� �⹰�� �̸�
	int MoveCount = 0;//�⹰�� ������ Ƚ��
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