#include<iostream>
#include<string>
using namespace std;

class Chess //체스판 클래스
{
public:
	string CellName;//칸의 이름
	string Color;//칸의 색
	string ChessPiece;//기물 이름
	string Code;//체스판에 표시되는 기물의 이름
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

int main()
{
	// A8~ H8은 체스판 끝이므로 Border = true
	// 칸의 이름 / 칸의 색 / 기물 이름 / 기물 코드 / 기물 유무 / 체스판 끝 / 칸 번호 / 기물이 움직인 횟수
	Chess A8("A8", "□", "WhiteRook1", "WR", true, true, 1, 0);// 객체 A8 생성
	Chess B8("B8", "■", "WhiteKnight1", "WN", true, true, 2, 0);
	Chess C8("C8", "□", "WhiteBishop1", "WB", true, true, 3, 0);
	Chess D8("D8", "■", "WhiteQueen", "WQ", true, true, 4, 0);
	Chess E8("E8", "□", "WhiteKing", "WK", true, true, 5, 0);
	Chess F8("F8", "■", "WhiteBishop2", "WB", true, true, 6, 0);
	Chess G8("G8", "□", "WhiteKnight2", "WN", true, true, 7, 0);
	Chess H8("H8", "■", "WhiteRook2", "WR", true, true, 8, 0);

	Chess A7("A7", "■", "WhitePawn1", "WP", true, false, 9, 0);
	Chess B7("B7", "□", "WhitePawn2", "WP", true, false, 10, 0);
	Chess C7("C7", "■", "WhitePawn3", "WP", true, false, 11, 0);
	Chess D7("D7", "□", "WhitePawn4", "WP", true, false, 12, 0);
	Chess E7("E7", "■", "WhitePawn5", "WP", true, false, 13, 0);
	Chess F7("F7", "□", "WhitePawn6", "WP", true, false, 14, 0);
	Chess G7("G7", "■", "WhitePawn7", "WP", true, false, 15, 0);
	Chess H7("H7", "□", "WhitePawn8", "WP", true, false, 16, 0);

	Chess A6("A6", "□", "blank", "□", false, false, 17, 0);
	Chess B6("B6", "■", "blank", "■", false, false, 18, 0);
	Chess C6("C6", "□", "blank", "□", false, false, 19, 0);
	Chess D6("D6", "■", "blank", "■", false, false, 20, 0);
	Chess E6("E6", "□", "blank", "□", false, false, 21, 0);
	Chess F6("F6", "■", "blank", "■", false, false, 22, 0);
	Chess G6("G6", "□", "blank", "□", false, false, 23, 0);
	Chess H6("H6", "■", "blank", "■", false, false, 24, 0);

	Chess A5("A5", "■", "blank", "■", false, false, 25, 0);
	Chess B5("B5", "□", "blank", "□", false, false, 26, 0);
	Chess C5("C5", "■", "blank", "■", false, false, 27, 0);
	Chess D5("D5", "□", "blank", "□", false, false, 28, 0);
	Chess E5("E5", "■", "blank", "■", false, false, 29, 0);
	Chess F5("F5", "□", "blank", "□", false, false, 30, 0);
	Chess G5("G5", "■", "blank", "■", false, false, 31, 0);
	Chess H5("H5", "□", "blank", "□", false, false, 32, 0);

	Chess A4("A4", "□", "blank", "□", false, false, 33, 0);
	Chess B4("B4", "■", "blank", "■", false, false, 34, 0);
	Chess C4("C4", "□", "blank", "□", false, false, 35, 0);
	Chess D4("D4", "■", "blank", "■", false, false, 36, 0);
	Chess E4("E4", "□", "blank", "□", false, false, 37, 0);
	Chess F4("F4", "■", "blank", "■", false, false, 38, 0);
	Chess G4("G4", "□", "blank", "□", false, false, 39, 0);
	Chess H4("H4", "■", "blank", "■", false, false, 40, 0);

	Chess A3("A3", "■", "blank", "■", false, false, 41, 0);
	Chess B3("B3", "□", "blank", "□", false, false, 42, 0);
	Chess C3("C3", "■", "blank", "■", false, false, 43, 0);
	Chess D3("D3", "□", "blank", "□", false, false, 44, 0);
	Chess E3("E3", "■", "blank", "■", false, false, 45, 0);
	Chess F3("F3", "□", "blank", "□", false, false, 46, 0);
	Chess G3("G3", "■", "blank", "■", false, false, 47, 0);
	Chess H3("H3", "□", "blank", "□", false, false, 48, 0);

	Chess A2("A2", "□", "BlackPawn1", "BP", true, false, 49, 0);
	Chess B2("B2", "■", "BlackPawn2", "BP", true, false, 50, 0);
	Chess C2("C2", "□", "BlackPawn3", "BP", true, false, 51, 0);
	Chess D2("D2", "■", "BlackPawn4", "BP", true, false, 52, 0);
	Chess E2("E2", "□", "BlackPawn5", "BP", true, false, 53, 0);
	Chess F2("F2", "■", "BlackPawn6", "BP", true, false, 54, 0);
	Chess G2("G2", "□", "BlackPawn7", "BP", true, false, 55, 0);
	Chess H2("H2", "■", "BlackPawn8", "BP", true, false, 56, 0);

	// A1 ~ H1은 체스판 끝이므로 Border = true
	Chess A1("A1", "■", "BlackRook1", "BR", true, true, 57, 0);
	Chess B1("B1", "□", "BlackKnight1", "BN", true, true, 58, 0);
	Chess C1("C1", "■", "BlackBishop1", "BB", true, true, 59, 0);
	Chess D1("D1", "□", "BlackQueen", "BQ", true, true, 60, 0);
	Chess E1("E1", "■", "BlackKing", "BK", true, true, 61, 0);
	Chess F1("F1", "□", "BlackBishop2", "BB", true, true, 62, 0);
	Chess G1("G1", "■", "BlackKnight2", "BN", true, true, 63, 0);
	Chess H1("H1", "□", "BlackRook2", "BR", true, true, 64, 0);

	int menu;

	cout << "┌──────────────┐" << endl;
	cout << "│ 1. 게임 시작 │" << endl;
	cout << "│ 2. 게임 설명 │" << endl;
	cout << "└──────────────┘" << endl;
	cout << "기능을 선택해 주세요 : ";
	cin >> menu;
	if (menu == 1)
	{
		cout << "        ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
		line1();
		cout << "        ┃ ■";
		cout << A1.Code;
		gap1();
		cout << B1.Code;
		gap2();
		cout << C1.Code;
		gap1();
		cout << D1.Code;
		gap2();
		cout << E1.Code;
		gap1();
		cout << F1.Code;
		gap2();
		cout << G1.Code;
		gap1();
		cout << H1.Code;
		cout << "□┃ 8" << endl;
		line1();

		line2();
		cout << "        ┃ □";
		cout << A2.Code;
		gap2();
		cout << B2.Code;
		gap1();
		cout << C2.Code;
		gap2();
		cout << D2.Code;
		gap1();
		cout << E2.Code;
		gap2();
		cout << F2.Code;
		gap1();
		cout << G2.Code;
		gap2();
		cout << H2.Code;
		cout << "■┃ 7" << endl;
		line2();

		line1();
		cout << "        ┃ ■";
		cout << A3.Code;
		gap1();
		cout << B3.Code;
		gap2();
		cout << C3.Code;
		gap1();
		cout << D3.Code;
		gap2();
		cout << E3.Code;
		gap1();
		cout << F3.Code;
		gap2();
		cout << G3.Code;
		gap1();
		cout << H3.Code;
		cout << "□┃ 6" << endl;
		line1();

		line2();
		cout << "        ┃ □";
		cout << A4.Code;
		gap2();
		cout << B4.Code;
		gap1();
		cout << C4.Code;
		gap2();
		cout << D4.Code;
		gap1();
		cout << E4.Code;
		gap2();
		cout << F4.Code;
		gap1();
		cout << G4.Code;
		gap2();
		cout << H4.Code;
		cout << "■┃ 5" << endl;
		line2();

		line1();
		cout << "        ┃ ■";
		cout << A5.Code;
		gap1();
		cout << B5.Code;
		gap2();
		cout << C5.Code;
		gap1();
		cout << D5.Code;
		gap2();
		cout << E5.Code;
		gap1();
		cout << F5.Code;
		gap2();
		cout << G5.Code;
		gap1();
		cout << H5.Code;
		cout << "□┃ 4" << endl;
		line1();

		line2();
		cout << "        ┃ □";
		cout << A6.Code;
		gap2();
		cout << B6.Code;
		gap1();
		cout << C6.Code;
		gap2();
		cout << D6.Code;
		gap1();
		cout << E6.Code;
		gap2();
		cout << F6.Code;
		gap1();
		cout << G6.Code;
		gap2();
		cout << H6.Code;
		cout << "■┃ 3" << endl;
		line2();

		line1();
		cout << "        ┃ ■";
		cout << A7.Code;
		gap1();
		cout << B7.Code;
		gap2();
		cout << C7.Code;
		gap1();
		cout << D7.Code;
		gap2();
		cout << E7.Code;
		gap1();
		cout << F7.Code;
		gap2();
		cout << G7.Code;
		gap1();
		cout << H7.Code;
		cout << "□┃ 2" << endl;
		line1();

		line2();
		cout << "        ┃ □";
		cout << A8.Code;
		gap2();
		cout << B8.Code;
		gap1();
		cout << C8.Code;
		gap2();
		cout << D8.Code;
		gap1();
		cout << E8.Code;
		gap2();
		cout << F8.Code;
		gap1();
		cout << G8.Code;
		gap2();
		cout << H8.Code;
		cout << "■┃ 1" << endl;
		line2();
		cout << "        ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
		cout << "            A     B     C     D     E     F     G     H" << endl;
		cout << "\n";
	}

}

