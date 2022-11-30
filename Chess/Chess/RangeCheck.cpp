#include "Chess.h"
void rookExplore(Chess* p, string secPiece);
void bishopExplore(Chess* p, string secPiece);
void knightExplore(Chess* p, string secPiece);
void queenExplore(Chess* p, string secPiece);
void kingExplore(Chess* p, string secPiece);
void pawnExplore(Chess* p, string secPiece, char color);

void Chess::RangeCheck(Chess* p, string secPiece)
{
	for (int i = 1; i <= 64; i++) {			  // �������� �̸��� ������ �ּҷ� �̵�
		if (p->piece->showCode() == secPiece) // ã����
			break;                            // ����
		else if (p->showCellName() == secPiece)
			break;                            //    ``
		else                                  // �ƴ϶��
			p++;                              // ���� ĭ����
	}
	switch (secPiece[1])
	{
	case'R':
		rookExplore(p, secPiece);
		break;
	case'B':
		bishopExplore(p, secPiece);
		break;
	case'N':
		knightExplore(p, secPiece);
		break;
	case'Q':
		queenExplore(p, secPiece);
		break;
	case'K':
		kingExplore(p, secPiece);
		break;
	case'P':
		pawnExplore(p, secPiece, p->piece->showCode()[0]);
		break;
	}
}

void rookExplore(Chess* p, string secPiece) {
	//��
	if (p->showEBorder() == false)//���� ��ġ�� ������ ��輱�� �ƴ϶��
	{
		int i = 1;
		p -= 1;//�ּҸ� ���������� �� ĭ �̵�
		while (true) {
			if (p->showExist())
			{
				if (p->piece->showCode()[0] == secPiece[0]) {//�Ʊ� �⹰�� ������ ��
					break;
				}
				else if (p->piece->showCode()[0] != secPiece[0]) {//�� �⹰�� ������ ��
					p->insertResRook(true);
					break;
				}
			}
			else if (p->showEBorder()) {//���� ��ġ�� ������ ��輱�̶��
				p->insertResRook(true);
				break;
			}
			else//���� ��ġ�� ��輱�� �ƴϰ� �⹰�� ������ �ʾ��� ��
			{
				p->insertResRook(true);
				i++;
				p -= 1;//�� ĭ ������
			}
		}
		p += 1 * i;
	}
	//��
	if (p->showWBorder() == false)//���� ��ġ�� ���� ��輱�� �ƴ϶��
	{
		int i = 1;
		p += 1;//�ּҸ� �������� �� ĭ �̵�
		while (true) {
			if (p->showExist())
			{
				if (p->piece->showCode()[0] == secPiece[0]) {//�Ʊ� �⹰�� ������ ��
					break;
				}
				else if (p->piece->showCode()[0] != secPiece[0]) {//�� �⹰�� ������ ��
					p->insertResRook(true);
					break;
				}
			}
			else if (p->showWBorder()) {//���� ��ġ�� ���� ��輱�̶��
				p->insertResRook(true);
				break;
			}
			else//���� ��ġ�� ��輱�� �ƴϰ� �⹰�� ������ �ʾ��� ��
			{
				p->insertResRook(true);
				i++;
				p += 1;//�� ĭ ������
			}
		}
		p -= 1 * i;
	}
	//��
	if (p->showSBorder() == false)//���� ��ġ�� �Ʒ��� ��輱�� �ƴ϶��
	{
		int i = 1;
		p -= 8;//�ּҸ� �Ʒ������� �� ĭ �̵�
		while (true) {
			if (p->showExist())
			{
				if (p->piece->showCode()[0] == secPiece[0]) {//�Ʊ� �⹰�� ������ ��
					break;
				}

				else if (p->piece->showCode()[0] != secPiece[0]) {//�� �⹰�� ������ ��
					p->insertResRook(true);
					break;
				}
			}
			else if (p->showSBorder()) {//���� ��ġ�� �Ʒ��� ��輱�̶��
				p->insertResRook(true);
				break;
			}
			else//���� ��ġ�� ��輱�� �ƴϰ� �⹰�� ������ �ʾ��� ��
			{
				p->insertResRook(true);
				i++;
				p -= 8;//�� ĭ ������
			}
		}
		p += 8 * i;
	}
	//��
	if (p->showNBorder() == false)//���� ��ġ�� ���� ��輱�� �ƴ϶��
	{
		int i = 1;
		p += 8;//�ּҸ� �������� �� ĭ �̵�
		while (true) {
			if (p->showExist())
			{
				if (p->piece->showCode()[0] == secPiece[0]) {//�Ʊ� �⹰�� ������ ��
					break;
				}
				else if (p->piece->showCode()[0] != secPiece[0]) {//�� �⹰�� ������ ��
					p->insertResRook(true);
					break;
				}
			}
			else if (p->showNBorder()) {//���� ��ġ�� ���� ��輱�̶��
				p->insertResRook(true);
				break;
			}
			else//���� ��ġ�� ��輱�� �ƴϰ� �⹰�� ������ �ʾ��� ��
			{
				p->insertResRook(true);
				i++;
				p += 8;//�� ĭ ������
			}
		}
		p -= 8 * i;
	}
}
void bishopExplore(Chess* p, string secPiece) {
	//��
	if ((p->showWBorder() == false) && (p->showNBorder() == false))//���� ��ġ�� ���� ��輱 AND ���� ��輱�� �ƴ϶��
	{
		int i = 1;
		p += 9;//�ּҸ� ���� ���� �� ĭ �̵�
		while (true) {
			if (p->showExist()) {
				if (p->piece->showCode()[0] == secPiece[0]) {//�Ʊ� �⹰�� ������ ��
					break;
				}
				else if (p->piece->showCode()[0] != secPiece[0]) {//�� �⹰�� ������ ��
					p->insertResBishop(true);
					break;
				}
			}
			else if ((p->showWBorder()) || (p->showNBorder())) {//���� ��ġ�� ���� ��輱�̶��
				p->insertResBishop(true);
				break;
			}
			else//���� ��ġ�� ��輱�� �ƴϰ� �⹰�� ������ �ʾ��� ��
			{
				p->insertResBishop(true);
				i++;
				p += 9;//�� ĭ ������
			}
		}
		p -= 9 * i;
	}
	//��
	if ((p->showEBorder() == false) && (p->showNBorder() == false))//���� ��ġ�� ���� ��輱 AND ���� ��輱�� �ƴ϶��
	{
		int i = 1;
		p += 7;//�ּҸ� ���� ���� �� ĭ �̵�
		while (true) {
			if (p->showExist()) {
				if (p->piece->showCode()[0] == secPiece[0]) {//�Ʊ� �⹰�� ������ ��							1
					break;
				}
				else if (p->piece->showCode()[0] != secPiece[0]) {//�� �⹰�� ������ ��								2
					p->insertResBishop(true);
					break;
				}
			}
			else if ((p->showEBorder()) || (p->showNBorder())) {//���� ��ġ�� ���� ��輱�̶��	3
				p->insertResBishop(true);
				break;
			}
			else//���� ��ġ�� ��輱�� �ƴϰ� �⹰�� ������ �ʾ��� ��
			{
				p->insertResBishop(true);
				i++;
				p += 7;//�� ĭ ������
			}
		}
		p -= 7 * i;
	}
	//��
	if ((p->showEBorder() == false) && (p->showSBorder() == false))//���� ��ġ�� ������ ��輱 AND ���� ��輱�� �ƴ϶��
	{
		int i = 1;
		p -= 9;//�ּҸ� ���� ���� �� ĭ �̵�
		while (true) {
			if (p->showExist()) {
				if (p->piece->showCode()[0] == secPiece[0]) {//�Ʊ� �⹰�� ������ ��
					break;
				}
				else if (p->piece->showCode()[0] != secPiece[0]) {//�� �⹰�� ������ ��
					p->insertResBishop(true);
					break;
				}
			}
			else if ((p->showEBorder()) || (p->showSBorder())) {//���� ��ġ�� ������ ��輱�̶��
				p->insertResBishop(true);
				break;
			}
			else//���� ��ġ�� ��輱�� �ƴϰ� �⹰�� ������ �ʾ��� ��
			{
				p->insertResBishop(true);
				i++;
				p -= 9;//�� ĭ ������
			}
		}
		p += 9 * i;
	}
	//��
	if ((p->showWBorder() == false) && (p->showSBorder() == false))//���� ��ġ�� ������ ��輱 AND ���� ��輱�� �ƴ϶��
	{
		int i = 1;
		p -= 7;//�ּҸ� ���� ���� �� ĭ �̵�
		while (true) {
			if (p->showExist()) {
				if (p->piece->showCode()[0] == secPiece[0]) {//�Ʊ� �⹰�� ������ ��
					break;
				}
				else if (p->piece->showCode()[0] != secPiece[0]) {//�� �⹰�� ������ ��
					p->insertResBishop(true);
					break;
				}
			}
			else if ((p->showWBorder()) || (p->showSBorder())) {//���� ��ġ�� ������ ��輱�̶��
				p->insertResBishop(true);
				break;
			}
			else//���� ��ġ�� ��輱�� �ƴϰ� �⹰�� ������ �ʾ��� ��
			{
				p->insertResBishop(true);
				i++;
				p -= 7;//�� ĭ ������
			}
		}
		p += 7 * i;
	}
}
void knightExplore(Chess* p, string secPiece) {
	int N = 0, S = 0, E = 0, W = 0;

	int i;
	if (p->showNBorder() == false) {
		for (i = 0; i < 2; i++) {
			p += 8;
			if (p->showNBorder()) {
				i++;
				N += (i + 1);
				break;
			}
		}
		p -= 8 * i;
	}
	else
		N += 1;

	if (p->showSBorder() == false) {
		for (i = 0; i < 2; i++) {
			p -= 8;
			if (p->showSBorder()) {
				i++;
				S += (i + 1);
				break;
			}
		}
		p += 8 * i;
	}
	else
		S += 1;

	if (p->showEBorder() == false) {
		for (i = 0; i < 2; i++) {
			p -= 1;
			if (p->showEBorder()) {
				i++;
				E += (i + 1);
				break;
			}
		}
		p += 1 * i;
	}
	else
		E += 1;

	if (p->showWBorder() == false) {
		for (i = 0; i < 2; i++) {
			p += 1;
			if (p->showWBorder()) {
				i++;
				W += (i + 1);
				break;
			}
		}
		p -= 1 * i;
	}
	else
		W += 1;

	// ���� N, S, W, E�� ���� true �Է�
	if (N == 0 || N == 3) {
		if (E == 0 || E > 1) {
			p += 15;
			if (p->showExist()) {
				if (p->piece->showCode()[0] != secPiece[0])
					p->insertResKnight(true);
			}
			else {
				p->insertResKnight(true);
			}
			p -= 15;
		}
		if (W == 0 || W > 1) {
			p += 17;
			if (p->showExist()) {
				if (p->piece->showCode()[0] != secPiece[0])
					p->insertResKnight(true);
			}
			else {
				p->insertResKnight(true);
			}
			p -= 17;
		}
	}
	if (S == 0 || S == 3) {
		if (E == 0 || E > 1) {
			p -= 17;
			if (p->showExist()) {
				if (p->piece->showCode()[0] != secPiece[0])
					p->insertResKnight(true);
			}
			else {
				p->insertResKnight(true);
			}
			p += 17;
		}
		if (W == 0 || W > 1) {
			p -= 15;
			if (p->showExist()) {
				if (p->piece->showCode()[0] != secPiece[0])
					p->insertResKnight(true);
			}
			else {
				p->insertResKnight(true);
			}
			p += 15;
		}
	}
	if (E == 0 || E == 3) {
		if (N == 0 || N > 1) {
			p += 6;
			if (p->showExist()) {
				if (p->piece->showCode()[0] != secPiece[0])
					p->insertResKnight(true);
			}
			else {
				p->insertResKnight(true);
			}
			p -= 6;
		}
		if (S == 0 || S > 1) {
			p -= 10;
			if (p->showExist()) {
				if (p->piece->showCode()[0] != secPiece[0])
					p->insertResKnight(true);
			}
			else {
				p->insertResKnight(true);
			}
			p += 10;
		}
	}
	if (W == 0 || W == 3) {
		if (N == 0 || N > 1) {
			p += 10;
			if (p->showExist()) {
				if (p->piece->showCode()[0] != secPiece[0])
					p->insertResKnight(true);
			}
			else {
				p->insertResKnight(true);
			}
			p -= 10;
		}
		if (S == 0 || S > 1) {
			p -= 6;
			if (p->showExist()) {
				if (p->piece->showCode()[0] != secPiece[0])
					p->insertResKnight(true);
			}
			else {
				p->insertResKnight(true);
			}
			p += 6;
		}
	}
	return;
}
void queenExplore(Chess* p, string secPiece) {
	//��
	if (p->showEBorder() == false)//���� ��ġ�� ������ ��輱�� �ƴ϶��
	{
		int i = 1;
		p -= 1;//�ּҸ� ���������� �� ĭ �̵�
		while (true) {
			if (p->showExist())
			{
				if (p->piece->showCode()[0] == secPiece[0]) {//�Ʊ� �⹰�� ������ ��
					break;
				}
				else if (p->piece->showCode()[0] != secPiece[0]) {//�� �⹰�� ������ ��
					p->insertResQueen(true);
					break;
				}
			}
			else if (p->showEBorder()) {//���� ��ġ�� ������ ��輱�̶��
				p->insertResQueen(true);
				break;
			}
			else//���� ��ġ�� ��輱�� �ƴϰ� �⹰�� ������ �ʾ��� ��
			{
				p->insertResQueen(true);
				i++;
				p -= 1;//�� ĭ ������
			}
		}
		p += 1 * i;
	}
	//��
	if (p->showWBorder() == false)//���� ��ġ�� ���� ��輱�� �ƴ϶��
	{
		int i = 1;
		p += 1;//�ּҸ� �������� �� ĭ �̵�
		while (true) {
			if (p->showExist())
			{
				if (p->piece->showCode()[0] == secPiece[0]) {//�Ʊ� �⹰�� ������ ��
					break;
				}
				else if (p->piece->showCode()[0] != secPiece[0]) {//�� �⹰�� ������ ��
					p->insertResQueen(true);
					break;
				}
			}
			else if (p->showWBorder()) {//���� ��ġ�� ������ ��輱�̶��
				p->insertResQueen(true);
				break;
			}
			else//���� ��ġ�� ��輱�� �ƴϰ� �⹰�� ������ �ʾ��� ��
			{
				p->insertResQueen(true);
				i++;
				p += 1;//�� ĭ ������
			}
		}
		p -= 1 * i;
	}
	//��
	if (p->showSBorder() == false)//���� ��ġ�� �Ʒ��� ��輱�� �ƴ϶��
	{
		int i = 1;
		p -= 8;//�ּҸ� �Ʒ������� �� ĭ �̵�
		while (true) {
			if (p->showExist())
			{
				if (p->piece->showCode()[0] == secPiece[0]) {//�Ʊ� �⹰�� ������ ��
					break;
				}
				else if (p->piece->showCode()[0] != secPiece[0]) {//�� �⹰�� ������ ��
					p->insertResQueen(true);
					break;
				}
			}
			else if (p->showSBorder()) {//���� ��ġ�� ������ ��輱�̶��
				p->insertResQueen(true);
				break;
			}
			else//���� ��ġ�� ��輱�� �ƴϰ� �⹰�� ������ �ʾ��� ��
			{
				p->insertResQueen(true);
				i++;
				p -= 8;//�� ĭ ������
			}
		}
		p += 8 * i;
	}
	//��
	if (p->showNBorder() == false)//���� ��ġ�� ���� ��輱�� �ƴ϶��
	{
		int i = 1;
		p += 8;//�ּҸ� �������� �� ĭ �̵�
		while (true) {
			if (p->showExist())
			{
				if (p->piece->showCode()[0] == secPiece[0]) {//�Ʊ� �⹰�� ������ ��
					break;
				}
				else if (p->piece->showCode()[0] != secPiece[0]) {//�� �⹰�� ������ ��
					p->insertResQueen(true);
					break;
				}
			}
			else if (p->showNBorder()) {//���� ��ġ�� ������ ��輱�̶��
				p->insertResQueen(true);
				break;
			}
			else//���� ��ġ�� ��輱�� �ƴϰ� �⹰�� ������ �ʾ��� ��
			{
				p->insertResQueen(true);
				i++;
				p += 8;//�� ĭ ������
			}
		}
		p -= 8 * i;
	}
	//��
	if ((p->showWBorder() == false) && (p->showNBorder() == false))//���� ��ġ�� ���� ��輱 AND ���� ��輱�� �ƴ϶��
	{
		int i = 1;
		p += 9;//�ּҸ� ���� ���� �� ĭ �̵�
		while (true) {
			if (p->showExist())
			{
				if (p->piece->showCode()[0] == secPiece[0]) {//�Ʊ� �⹰�� ������ ��
					break;
				}
				else if (p->piece->showCode()[0] != secPiece[0]) {//�� �⹰�� ������ ��
					p->insertResQueen(true);
					break;
				}
			}
			else if (p->showNBorder() || p->showWBorder()) {//���� ��ġ�� ������ ��輱�̶��
				p->insertResQueen(true);
				break;
			}
			else//���� ��ġ�� ��輱�� �ƴϰ� �⹰�� ������ �ʾ��� ��
			{
				p->insertResQueen(true);
				i++;
				p += 9;//�� ĭ ������
			}
		}
		p -= 9 * i;
	}
	//��
	if ((p->showEBorder() == false) && (p->showNBorder() == false))//���� ��ġ�� ���� ��輱 AND ���� ��輱�� �ƴ϶��
	{
		int i = 1;
		p += 7;//�ּҸ� ���� ���� �� ĭ �̵�
		while (true) {
			if (p->showExist())
			{
				if (p->piece->showCode()[0] == secPiece[0]) {//�Ʊ� �⹰�� ������ ��
					break;
				}
				else if (p->piece->showCode()[0] != secPiece[0]) {//�� �⹰�� ������ ��
					p->insertResQueen(true);
					break;
				}
			}
			else if (p->showNBorder() || p->showWBorder()) {//���� ��ġ�� ������ ��輱�̶��
				p->insertResQueen(true);
				break;
			}
			else//���� ��ġ�� ��輱�� �ƴϰ� �⹰�� ������ �ʾ��� ��
			{
				p->insertResQueen(true);
				i++;
				p += 7;//�� ĭ ������
			}
		}
		p -= 7 * i;
	}
	//��
	if ((p->showEBorder() == false) && (p->showSBorder() == false))//���� ��ġ�� ������ ��輱 AND ���� ��輱�� �ƴ϶��
	{
		int i = 1;
		p -= 9;//�ּҸ� ���� ���� �� ĭ �̵�
		while (true) {
			if (p->showExist())
			{
				if (p->piece->showCode()[0] == secPiece[0]) {//�Ʊ� �⹰�� ������ ��
					break;
				}

				else if (p->piece->showCode()[0] != secPiece[0]) {//�� �⹰�� ������ ��
					p->insertResQueen(true);
					break;
				}
			}
			else if ((p->showEBorder() == false) || (p->showSBorder() == false)) {//���� ��ġ�� ������ ��輱�̶��
				p->insertResQueen(true);
				break;
			}
			else//���� ��ġ�� ��輱�� �ƴϰ� �⹰�� ������ �ʾ��� ��
			{
				p->insertResQueen(true);
				i++;
				p -= 9;//�� ĭ ������
			}
		}
		p += 9 * i;
	}
	//��
	if ((p->showWBorder() == false) && (p->showSBorder() == false))//���� ��ġ�� ������ ��輱 AND ���� ��輱�� �ƴ϶��
	{
		int i = 1;
		p -= 7;//�ּҸ� ���� ���� �� ĭ �̵�
		while (true) {
			if (p->showExist())
			{
				if (p->piece->showCode()[0] == secPiece[0]) {//�Ʊ� �⹰�� ������ ��
					break;
				}

				else if (p->piece->showCode()[0] != secPiece[0]) {//�� �⹰�� ������ ��
					p->insertResQueen(true);
					break;
				}
			}
			else if ((p->showWBorder() == false) || (p->showSBorder() == false)) {//���� ��ġ�� ������ ��輱�̶��
				p->insertResQueen(true);
				break;
			}
			else//���� ��ġ�� ��輱�� �ƴϰ� �⹰�� ������ �ʾ��� ��
			{
				p->insertResQueen(true);
				i++;
				p -= 7;//�� ĭ ������
			}
		}
		p += 7 * i;
	}
}
void kingExplore(Chess* p, string secPiece)
{
	//��
	if (p->showEBorder() == false)//���� ��ġ�� ������ ��輱�� �ƴ϶��
	{
		p -= 1;		//�ּҸ� ���������� �� ĭ �̵�
		if ((p->piece->showCode()[0] == secPiece[0]) == false) {	// �Ʊ� �⹰�� �ƴ� ���
			p->insertResKing(true);
		}
		p += 1;		// ���ڸ���
	}
	//��
	if (p->showWBorder() == false)//���� ��ġ�� ���� ��輱�� �ƴ϶��
	{
		p += 1;//�ּҸ� �������� �� ĭ �̵�
		if ((p->piece->showCode()[0] == secPiece[0]) == false) {	// �Ʊ� �⹰�� �ƴ� ���
			p->insertResKing(true);
		}
		p -= 1;
	}
	//��
	if (p->showSBorder() == false)//���� ��ġ�� �Ʒ��� ��輱�� �ƴ϶��
	{
		p -= 8;		// �ּҸ� �Ʒ������� �� ĭ �̵�
		if ((p->piece->showCode()[0] == secPiece[0]) == false) {	// �Ʊ� �⹰�� �ƴ� ���
			p->insertResKing(true);
		}
		p += 8;		// ���ڸ���
	}
	//��
	if (p->showNBorder() == false)//���� ��ġ�� ���� ��輱�� �ƴ϶��
	{
		p += 8;		// �ּҸ� �������� �� ĭ �̵�
		if ((p->piece->showCode()[0] == secPiece[0]) == false) {	// �Ʊ� �⹰�� �ƴ� ���
			p->insertResKing(true);
		}
		p -= 8;		// ���ڸ���
	}
	//��
	if ((p->showWBorder() == false) || (p->showNBorder() == false))//���� ��ġ�� ���� ��輱 AND ���� ��輱�� �ƴ϶��
	{
		p += 9;//�ּҸ� ���� ���� �� ĭ �̵�
		if ((p->piece->showCode()[0] == secPiece[0]) == false) {	// �Ʊ� �⹰�� �ƴ� ���
			p->insertResKing(true);
		}
		p -= 9;
	}
	//��
	if ((p->showEBorder() == false) || (p->showNBorder() == false))//���� ��ġ�� ������ ��輱 AND ���� ��輱�� �ƴ϶��
	{
		p += 7;//�ּҸ� ���� ���� �� ĭ �̵�
		if ((p->piece->showCode()[0] == secPiece[0]) == false) {	// �Ʊ� �⹰�� �ƴ� ���
			p->insertResKing(true);
		}
		p -= 7;
	}
	//��
	if ((p->showEBorder() == false) || (p->showSBorder() == false))//���� ��ġ�� ������ ��輱 AND �Ʒ��� ��輱�� �ƴ϶��
	{
		p -= 9;//�ּҸ� ���� ���� �� ĭ �̵�
		if ((p->piece->showCode()[0] == secPiece[0]) == false) {	// �Ʊ� �⹰�� �ƴ� ���
			p->insertResKing(true);
		}
		p += 9;
	}
	//��
	if ((p->showWBorder() == false) || (p->showSBorder() == false))//���� ��ġ�� ���� ��輱 AND �Ʒ��� ��輱�� �ƴ϶��
	{
		p -= 7;//�ּҸ� ���� ���� �� ĭ �̵�
		if ((p->piece->showCode()[0] == secPiece[0]) == false) {	// �Ʊ� �⹰�� �ƴ� ���
			p->insertResKing(true);
		}
		p += 7;
	}
}
void pawnExplore(Chess* p, string secPiece, char color) {
	if (color == 'W')
	{
		if (p->piece->showMoveCount())//���� ������ ���� �ִٸ�
		{
			//��
			if (p->showNBorder() == false)//���� ��ġ�� ���� ��輱�� �ƴ϶��
			{
				p += 8;		//�ּҸ� �������� �� ĭ �̵�
				if (p->showExist() == false) {	//���� ��ġ�� �⹰�� �ִٸ�
					p->insertResPawn(true);
				}
				p -= 8;				// ���ڸ���
			}
			//��
			if ((p->showWBorder() == false) || (p->showNBorder() == false))//���� ��ġ�� ���� ��輱 AND ���� ��輱�� �ƴ϶��
			{
				p += 9;//�ּҸ� ���� ���� �� ĭ �̵�
				if (p->showExist())
				{
					if (p->showExist() && (p->piece->showCode()[0] != secPiece[0])) {//�� �⹰�� ������ ��
						p->insertResPawn(true);
					}
				}
				p -= 9;
			}
			//��
			if ((p->showEBorder() == false) || (p->showNBorder() == false))//���� ��ġ�� ���� ��輱 AND ���� ��輱�� �ƴ϶��
			{
				p += 7;//�ּҸ� ������ ���� �� ĭ �̵�
				if (p->showExist())
				{
					if (p->piece->showCode()[0] != secPiece[0]) {//�� �⹰�� ������ ��
						p->insertResPawn(true);
					}
				}
				p -= 7;			// ���ڸ���
			}
		}
		else//���� ������ ���� ���ٸ�
		{
			//��
			if (p->showNBorder() == false) {					// 1. ���� �⹰ ��ġ���� N������ �ִ��� Ȯ�� 2. �ƴ϶�� �ּ�����(ĭ �̵�)
				int i;											// 3.1 �⹰�� �����ٸ� ����  3.2 N������ �����ٸ� resPown = true �� ���� 			
				for (i = 1; i <= 2; i++)						// 3.3 �� ���� ��쿡�� resPown = true �� �ּ� ����(ĭ �̵�)	4. �����͸� ���ڸ��� �̵� �� �ٸ� �� Ž��
				{
					p += 8;//�ּҸ� �������� �� ĭ �̵���
					if (p->showExist()) {		// �⹰�� ������ ��
						i++;
						break;
					}
					else if (p->showNBorder()) {// ���� ��ġ�� ���� ��輱�̶��
						p->insertResPawn(true);
						i++;
						break;
					}
					else//���� ��ġ�� ��輱�� �ƴϰ� �⹰�� ������ �ʾ��� ��
					{
						p->insertResPawn(true);
					}
				}
				p -= 8 * (i - 1);
			}
			//��
			if ((p->showWBorder() == false) || (p->showNBorder() == false))//���� ��ġ�� ���� ��輱 AND ���� ��輱�� �ƴ϶��
			{
				p += 9;//�ּҸ� ���� ���� �� ĭ �̵�
				if (p->showExist())
				{
					if (p->piece->showCode()[0] != secPiece[0]) {//�� �⹰�� ������ ��
						p->insertResPawn(true);
					}
				}
				p -= 9;
			}
			//��
			if ((p->showEBorder() == false) || (p->showNBorder() == false))//���� ��ġ�� ���� ��輱 AND ���� ��輱�� �ƴ϶��
			{
				p += 7;//�ּҸ� ������ ���� �� ĭ �̵�
				if (p->showExist())
				{
					if (p->piece->showCode()[0] != secPiece[0]) {//�� �⹰�� ������ ��
						p->insertResPawn(true);
					}
				}
				p -= 7;			// ���ڸ���
			}
		}
	}
	else if (color == 'B')
	{
		if (p->piece->showMoveCount())//���� �������ٸ�
		{
			//��
			if (p->showSBorder() == false)//���� ��ġ�� �Ʒ��� ��輱�� �ƴ϶��
			{
				p -= 8;//�ּҸ� �Ʒ������� �� ĭ �̵�
				if (p->showExist() == false) {	// �⹰�� ���ٸ�
					p->insertResPawn(true);
				}
				p += 8;	//���ڸ���
			}
			//��
			if ((p->showEBorder() == false) || (p->showSBorder() == false))//���� ��ġ�� ������ ��輱 AND ���� ��輱�� �ƴ϶��
			{
				p -= 9;//�ּҸ� ���� ���� �� ĭ �̵�
				if (p->showExist())
				{
					if (p->piece->showCode()[0] != secPiece[0]) {//�� �⹰�� ������ ��
						p->insertResPawn(true);
					}
				}
				p += 9;
			}
			//��
			if ((p->showWBorder() == false) || (p->showSBorder() == false))//���� ��ġ�� ������ ��輱 AND ���� ��輱�� �ƴ϶��
			{
				p -= 7;//�ּҸ� ���� ���� �� ĭ �̵�
				if (p->showExist())
				{
					if (p->piece->showCode()[0] != secPiece[0]) {//�� �⹰�� ������ ��
						p->insertResPawn(true);
					}
				}
				p += 7;
			}
		}
		else
		{
			//��
			if (p->showSBorder() == false) {
				int i;
				for (i = 1; i <= 2; i++)
				{
					p -= 8;		//�ּҸ� �������� �� ĭ �̵�
					if (p->showExist()) {			// �⹰�� ������ ��
						i++;
						break;
					}
					else if (p->showSBorder()) {	// ���� ��ġ�� ���� ��輱�̶��
						p->insertResPawn(true);
						i++;
						break;
					}
					else {							//���� ��ġ�� ��輱�� �ƴϰ� �⹰�� ������ �ʾ��� ��
						p->insertResPawn(true);
					}
				}
				p += 8 * (i - 1);
			}
			//��
			if ((p->showEBorder() == false) || (p->showSBorder() == false))	// ���� ��ġ�� ������ ��輱 AND ���� ��輱�� �ƴ϶��
			{
				p -= 9;//�ּҸ� ���� ���� �� ĭ �̵�
				if (p->showExist())
				{
					if (p->piece->showCode()[0] != secPiece[0]) {	// �� �⹰�� ������ ��
						p->insertResPawn(true);
					}
				}
				p += 9;
			}
			//��
			if ((p->showWBorder() == false) || (p->showSBorder() == false))	// ���� ��ġ�� ������ ��輱 AND ���� ��輱�� �ƴ϶��
			{
				p -= 7;//�ּҸ� ���� ���� �� ĭ �̵�
				if (p->showExist())
				{
					if (p->piece->showCode()[0] != secPiece[0]) {	// �� �⹰�� ������ ��
						p->insertResPawn(true);
					}
				}
				p += 7;
			}
		}
	}
}

bool Chess::possibleMove(Chess* p, char secCell[], char secPiece[])
{
	for (int i = 1; i <= 64; i++) {				// �������� �̸��� ������ �ּҷ� �̵�

		if (p->showCellName() == secCell)		// ã����
			break;								// ����
		else									// �ƴ϶��
			p++;								// ���� ĭ����
	}
	switch (secPiece[1])
	{
	case'R':
		if (p->showResRook() == true)
			return true;
		else
			return false;
	case'B':
		if (p->showResBishop() == true)
			return true;
		else
			return false;
	case'N':
		if (p->showResKnight() == true)
			return true;
		else
			return false;
	case'Q':
		if (p->showResQueen() == true)
			return true;
		else
			return false;
	case'K':
		if (p->showResKing() == true)
			return true;
		else
			return false;
	case'P':
		if (p->showResPawn() == true)
			return true;
		else
			return false;
	}
}