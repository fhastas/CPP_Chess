#include<iostream>
#include<string>
using namespace std;

class Chess //체스판 클래스
{
private:
	string CellName;//칸의 이름
	string Color;//칸의 색
	int CellNum;//칸의 번호
	bool Exist;//기물의 유무
	bool Border;//칸의 경계선

	string ChessPiece;//기물 이름		W or B P(폰), R(룩), B(비숍), N(나이트), Q(퀸), K(킹) 
	string Code;//체스판에 표시되는 기물의 이름
	int MoveCount;//기물이 움직인 횟수
public:
	string tempcode;//code 값을 저장하는 변수
	string tempcode2;
	string tempCellName;//CellName 값을 저장하는 변수
	string tempcolor;//color 값을 저장하는 변수
	bool tempexist;//exist 값을 저장하는 변수
	string tempChessPiece;//ChessPiece 값을 저장하는 변수
	int tempmove;//move 값을 저장하는 변수
	bool tempborder;//border값을 저장하는 변수

	string temp1;// swap함수에서 쓰이는 변수
	int temp2;

};
void line1() {//체스판 틀1
	cout << "         □□□■■■□□□■■■□□□■■■□□□■■■" << endl;

}
void line2() {//체스판 틀2
	cout << "         ■■■□□□■■■□□□■■■□□□■■■□□□" << endl;
}
void gap1() {//체스판 틀3
	cout << "□■";
}
void gap2() {//체스판 틀4
	cout << "■□";
}

int main()
{
	int Paddress = 1;//P가 현재 위치한 주소값

	int a;//선택지 입력
	string input1;
	string input2;
	string input3;
	//칸의 이름,색,번호/기물의 유무, 이름, 체스판에 표시되는 기물의 이름, 기물이 움직인 횟수, 체스판의 경계

	Chess* p = new Chess[36];

	while (1)
	{
		if (Paddress <= 16)//검은 기물
		{
			switch (Paddress)
				case (1):
					p->tempcode = "BR";
					break;
				case (2):
					p->tempcode = "BN";
					break;
				case (3):
					p->tempcode = "BB";
					break;
				case (4):
					p->tempcode = "BN";
					break;
				case (5):
					p->tempcode = "BR";
					break;
				case (6):
					p->tempcode = "BN";
					break;
				case (7):
					p->tempcode = "BR";
					break;
				case (8):
					p->tempcode = "BN";
					break;
				case (9):
				case (10):
				case (11):
				case (12):
				case (13):
				case (14):
				case (15):
				case (16):
					p->tempcode = "BP";
					break;

		}
		else if (Paddress >= 48)	//하얀 기물 
		{

		}
			
		p->tempcode2 = 3;

		p++;			// 다음 칸의 주소로 이동
		Paddress++;		// 현재 칸의 값 증가
			
	}
	
	cout << "┌──────────────┐" << endl;
	cout << "│ 1. 게임 시작 │" << endl;
	cout << "│ 2. 게임 설명 │" << endl;
	cout << "└──────────────┘" << endl;
	cout << "기능을 선택해 주세요 : ";


}

