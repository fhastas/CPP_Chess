#include "ChessBoard.h"
using namespace std;

void Chess::initData(Chess* p) {
	int i, Paddress = 1;
	for (i = 1; i < 64; i++) {
		if (i <= 16) {
			// 기물 이름
			switch (i)
			{
			case (1):
				p->ChessPiece = "BR";
				break;
			case (2):
				p->ChessPiece = "BN";
				break;
			case (3):
				p->ChessPiece = "BB";
				break;
			case (4):
				p->ChessPiece = "BQ";
				break;
			case (5):
				p->ChessPiece = "BK";
				break;
			case (6):
				p->ChessPiece = "BB";
				break;
			case (7):
				p->ChessPiece = "BN";
				break;
			case (8):
				p->ChessPiece = "BR";
				break;
			case (9):
			case (10):
			case (11):
			case (12):
			case (13):
			case (14):
			case (15):
			case (16):
				p->ChessPiece = "BP";
				break;
			}
			
			//칸 이름
			char c[2];
			if(i)	
			{
				
			}

			//

		}
	}
}

void Chess::insertCellName() {
	
}
void Chess::insertColor() {

}
void Chess::insertCellNum() {

}
void Chess::insertExist() {

}
void Chess::insertBoarder() {

}
void Chess::insertChessPiece() {

}
void Chess::insertCode() {

}
void Chess::insertMoveCount() {

}
