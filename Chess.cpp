#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<string>
using namespace std;
#define x_MAX 55//X좌표 최대값
#define x_MIN 10//X좌표 최소값
#define y_MAX 24//Y좌표 최대값
#define y_MIN 0//Y좌표 최소값
#define UP 72 // 아스키 코드에서 위 화살표는 72의 값을 가진다.
#define DOWN 80
#define LEFT 75
#define RIGHT 77

class Chess //체스판 클래스
{
public:
	string CellName;//칸의 이름
	string Color;//칸의 색
	string ChessPiece;//기물 이름!
	string Code;//체스판에 표시되는 기물의 이름!
	bool Exist;//기물의 유무
	bool Border;//칸의 경계선
	int CellNum;//칸의 번호
	int MoveCount;//기물이 움직인 횟수
	Chess(string CellName, string Color, string ChessPiece, string Code, bool Exist, bool Border, int CellNum, int MoveCount)
	{
		this->CellName = CellName;
		this->Color = Color;
		this->ChessPiece = ChessPiece;
		this->Code = Code;
		this->Exist = Exist;
		this->Border = Border;
		this->CellNum = CellNum;
		this->MoveCount = MoveCount;
	} // 생성자
};
void line1() {//체스판 틀1
	cout << "        ┃ ■■■□□□■■■□□□■■■□□□■■■□□□┃" << endl;

}
void line2() {//체스판 틀2
	cout << "        ┃ □□□■■■□□□■■■□□□■■■□□□■■■┃" << endl;
}
void gap1() {//체스판 틀3
	cout << "■□";
}
void gap2() {//체스판 틀4
	cout << "□■";
}

void gotoXY(int, int);

void gotoXY(int x, int y)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle, pos);
}

int main()
{
	// A8~ H8은 체스판 끝이므로 Border = true
	// 칸의 이름 / 칸의 색 / 기물 이름 / 기물 코드 / 기물 유무 / 체스판 끝 / 칸 번호 / 기물이 움직인 횟수
	Chess A1("A1", "□", "WhiteRook1", "WR", true, true, 1, 0);// 객체 A1 생성
	Chess B1("B1", "■", "WhiteKnight1", "WN", true, true, 2, 0);
	Chess C1("C1", "□", "WhiteBishop1", "WB", true, true, 3, 0);
	Chess D1("D1", "■", "WhiteQueen", "WQ", true, true, 4, 0);
	Chess E1("E1", "□", "WhiteKing", "WK", true, true, 5, 0);
	Chess F1("F1", "■", "WhiteBishop2", "WB", true, true, 6, 0);
	Chess G1("G1", "□", "WhiteKnight2", "WN", true, true, 7, 0);
	Chess H1("H1", "■", "WhiteRook2", "WR", true, true, 8, 0);

	Chess A2("A2", "■", "WhitePawn1", "WP", true, false, 9, 0);
	Chess B2("B2", "□", "WhitePawn2", "WP", true, false, 10, 0);
	Chess C2("C2", "■", "WhitePawn3", "WP", true, false, 11, 0);
	Chess D2("D2", "□", "WhitePawn4", "WP", true, false, 12, 0);
	Chess E2("E2", "■", "WhitePawn5", "WP", true, false, 13, 0);
	Chess F2("F2", "□", "WhitePawn6", "WP", true, false, 14, 0);
	Chess G2("G2", "■", "WhitePawn7", "WP", true, false, 15, 0);
	Chess H2("H2", "□", "WhitePawn8", "WP", true, false, 16, 0);

	Chess A3("A3", "□", "blank", "□", false, false, 17, 0);
	Chess B3("B3", "■", "blank", "■", false, false, 18, 0);
	Chess C3("C3", "□", "blank", "□", false, false, 19, 0);
	Chess D3("D3", "■", "blank", "■", false, false, 20, 0);
	Chess E3("E3", "□", "blank", "□", false, false, 21, 0);
	Chess F3("F3", "■", "blank", "■", false, false, 22, 0);
	Chess G3("G3", "□", "blank", "□", false, false, 23, 0);
	Chess H3("H3", "■", "blank", "■", false, false, 24, 0);

	Chess A4("A4", "■", "blank", "■", false, false, 25, 0);
	Chess B4("B4", "□", "blank", "□", false, false, 26, 0);
	Chess C4("C4", "■", "blank", "■", false, false, 27, 0);
	Chess D4("D4", "□", "blank", "□", false, false, 28, 0);
	Chess E4("E4", "■", "blank", "■", false, false, 29, 0);
	Chess F4("F4", "□", "blank", "□", false, false, 30, 0);
	Chess G4("G4", "■", "blank", "■", false, false, 31, 0);
	Chess H4("H4", "□", "blank", "□", false, false, 32, 0);

	Chess A5("A5", "□", "blank", "□", false, false, 33, 0);
	Chess B5("B5", "■", "blank", "■", false, false, 34, 0);
	Chess C5("C5", "□", "blank", "□", false, false, 35, 0);
	Chess D5("D5", "■", "blank", "■", false, false, 36, 0);
	Chess E5("E5", "□", "blank", "□", false, false, 37, 0);
	Chess F5("F5", "■", "blank", "■", false, false, 38, 0);
	Chess G5("G5", "□", "blank", "□", false, false, 39, 0);
	Chess H5("H5", "■", "blank", "■", false, false, 40, 0);

	Chess A6("A6", "■", "blank", "■", false, false, 41, 0);
	Chess B6("B6", "□", "blank", "□", false, false, 42, 0);
	Chess C6("C6", "■", "blank", "■", false, false, 43, 0);
	Chess D6("D6", "□", "blank", "□", false, false, 44, 0);
	Chess E6("E6", "■", "blank", "■", false, false, 45, 0);
	Chess F6("F6", "□", "blank", "□", false, false, 46, 0);
	Chess G6("G6", "■", "blank", "■", false, false, 47, 0);
	Chess H6("H6", "□", "blank", "□", false, false, 48, 0);

	Chess A7("A7", "□", "BlackPawn1", "BP", true, false, 49, 0);
	Chess B7("B7", "■", "BlackPawn2", "BP", true, false, 50, 0);
	Chess C7("C7", "□", "BlackPawn3", "BP", true, false, 51, 0);
	Chess D7("D7", "■", "BlackPawn4", "BP", true, false, 52, 0);
	Chess E7("E7", "□", "BlackPawn5", "BP", true, false, 53, 0);
	Chess F7("F7", "■", "BlackPawn6", "BP", true, false, 54, 0);
	Chess G7("G7", "□", "BlackPawn7", "BP", true, false, 55, 0);
	Chess H7("H7", "■", "BlackPawn8", "BP", true, false, 56, 0);

	// A1 ~ H1은 체스판 끝이므로 Border = true
	Chess A8("A8", "■", "BlackRook1", "BR", true, true, 57, 0);
	Chess B8("B8", "□", "BlackKnight1", "BN", true, true, 58, 0);
	Chess C8("C8", "■", "BlackBishop1", "BB", true, true, 59, 0);
	Chess D8("D8", "□", "BlackQueen", "BQ", true, true, 60, 0);
	Chess E8("E8", "■", "BlackKing", "BK", true, true, 61, 0);
	Chess F8("F8", "□", "BlackBishop2", "BB", true, true, 62, 0);
	Chess G8("G8", "■", "BlackKnight2", "BN", true, true, 63, 0);
	Chess H8("H8", "□", "BlackRook2", "BR", true, true, 64, 0);

	int x = 36;//X좌표 초기값
	int y = 20;//Y좌표 초기값
	int menu;//메뉴 선택 변수

	cout << "┌──────────────┐" << endl;
	cout << "│ 1. 게임 시작 │" << endl;
	cout << "│ 2. 게임 설명 │" << endl;
	cout << "└──────────────┘" << endl;
	cout << "기능을 선택해 주세요 : ";
	cin >> menu;
	if (menu == 1)//1번 선택시
	{
		while (1)
		{
			gotoXY(x, y);//x,y 함수
			if (_kbhit())// if(키보드가 눌렸을 시)
			{
				int input = _getch();// 키보드가 눌렸을 때의 값을 input 값에 저장
				if (input == DOWN) // 아래 화살표를 눌렀을 때
				{
					y = y + 3;
					if (y >= y_MAX)
					{
						y = y - 3;
					}
				}
				if (input == UP) // 위 화살표를 눌렀을 때
				{
					y = y - 3;
					if (y <= y_MIN)
					{
						y = y + 3;
					}
				}
				if (input == RIGHT) // 오른쪽 화살표를 눌렀을 때
				{
					x = x + 6;
					if (x >= x_MAX)
					{
						x = x - 6;
					}
				}
				if (input == LEFT) // 왼쪽 화살표를 눌렀을 때
				{
					x = x - 6;
					if (x <= x_MIN)
					{
						x = x + 6;
					}
				}

				system("cls");
				cout << "        ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
				line1();
				cout << "        ┃ ■";
				cout << A8.Code;
				gap1();
				cout << B8.Code;
				gap2();
				cout << C8.Code;
				gap1();
				cout << D8.Code;
				gap2();
				cout << E8.Code;
				gap1();
				cout << F8.Code;
				gap2();
				cout << G8.Code;
				gap1();
				cout << H8.Code;
				cout << "□┃ 8" << endl;
				line1();

				line2();
				cout << "        ┃ □";
				cout << A7.Code;
				gap2();
				cout << B7.Code;
				gap1();
				cout << C7.Code;
				gap2();
				cout << D7.Code;
				gap1();
				cout << E7.Code;
				gap2();
				cout << F7.Code;
				gap1();
				cout << G7.Code;
				gap2();
				cout << H7.Code;
				cout << "■┃ 7" << endl;
				line2();

				line1();
				cout << "        ┃ ■";
				cout << A6.Code;
				gap1();
				cout << B6.Code;
				gap2();
				cout << C6.Code;
				gap1();
				cout << D6.Code;
				gap2();
				cout << E6.Code;
				gap1();
				cout << F6.Code;
				gap2();
				cout << G6.Code;
				gap1();
				cout << H6.Code;
				cout << "□┃ 6" << endl;
				line1();

				line2();
				cout << "        ┃ □";
				cout << A5.Code;
				gap2();
				cout << B5.Code;
				gap1();
				cout << C5.Code;
				gap2();
				cout << D5.Code;
				gap1();
				cout << E5.Code;
				gap2();
				cout << F5.Code;
				gap1();
				cout << G5.Code;
				gap2();
				cout << H5.Code;
				cout << "■┃ 5" << endl;
				line2();

				line1();
				cout << "        ┃ ■";
				cout << A4.Code;
				gap1();
				cout << B4.Code;
				gap2();
				cout << C4.Code;
				gap1();
				cout << D4.Code;
				gap2();
				cout << E4.Code;
				gap1();
				cout << F4.Code;
				gap2();
				cout << G4.Code;
				gap1();
				cout << H4.Code;
				cout << "□┃ 4" << endl;
				line1();

				line2();
				cout << "        ┃ □";
				cout << A3.Code;
				gap2();
				cout << B3.Code;
				gap1();
				cout << C3.Code;
				gap2();
				cout << D3.Code;
				gap1();
				cout << E3.Code;
				gap2();
				cout << F3.Code;
				gap1();
				cout << G3.Code;
				gap2();
				cout << H3.Code;
				cout << "■┃ 3" << endl;
				line2();

				line1();
				cout << "        ┃ ■";
				cout << A2.Code;
				gap1();
				cout << B2.Code;
				gap2();
				cout << C2.Code;
				gap1();
				cout << D2.Code;
				gap2();
				cout << E2.Code;
				gap1();
				cout << F2.Code;
				gap2();
				cout << G2.Code;
				gap1();
				cout << H2.Code;
				cout << "□┃ 2" << endl;
				line1();

				line2();
				cout << "        ┃ □";
				cout << A1.Code;
				gap2();
				cout << B1.Code;
				gap1();
				cout << C1.Code;
				gap2();
				cout << D1.Code;
				gap1();
				cout << E1.Code;
				gap2();
				cout << F1.Code;
				gap1();
				cout << G1.Code;
				gap2();
				cout << H1.Code;
				cout << "■┃ 1" << endl;
				line2();
				cout << "        ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
				cout << "            A     B     C     D     E     F     G     H" << endl;
				cout << "\n";
				cout << "X : " << x << " Y : " << y; // 현재 X와 Y좌표 값을 출력, 나중에 없앨 예정
			}
		}
	}

}