#include "Chess.h"

void Piece::changeCode(string code) {
	this->pieceCode = code;
	return;
}

void Piece::changeMoveCount(int mc) {
	if (mc == 0) {			// ���� ���� 0�̶�� moveCount ���� 0���� ����
		this->moveCount = mc;
		return;
	}
	this->moveCount += mc;	// �ƴ϶�� ���� ���� ���� ���� �߰�
	return;
}

string Piece::showCode() {
	return this->pieceCode;
}

int Piece::showMoveCount() {
	return this->moveCount;
}