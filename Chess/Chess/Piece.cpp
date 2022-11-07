#include "Chess.h"

void Piece::changeCode(string code) {
	this->pieceCode = code;
	return;
}

void Piece::changeMoveCount(int mc) {
	if (mc == 0) {			// 넣을 값이 0이라면 moveCount 값을 0으로 변경
		this->moveCount = mc;
		return;
	}
	this->moveCount += mc;	// 아니라면 넣을 값을 원래 값에 추가
	return;
}

string Piece::showCode() {
	return this->pieceCode;
}

int Piece::showMoveCount() {
	return this->moveCount;
}