#include "Chess.h"

void Piece::changeCode(Piece* p, string code) {
	p->pieceCode = code;
	return;
}

void Piece::changeMoveCount(Piece* p, int mc) {
	if (mc == 0) {
		p->moveCount = mc;
		return;
	}
	p->moveCount += mc;
	return;
}

string Piece::showCode(Piece* p) {
	return p->pieceCode;
}

int Piece::showMoveCount(Piece* p) {
	return p->moveCount;
}