#include <iostream>
#include "Chess.h"

void printLongSquare(int eo, int num) {
	if (num == 1) {				// Ȧ�� ��° ��
		cout << "  ����  ��  �᦭��  ��  �ভ��  ��  �᦭��  ��  �ভ��  ��  �᦭��  ��  �ভ��  ��  �᦭��  ��  �ঢ" << endl;
	}
	else if (num == 0) {		// ¦�� ��° ��
		cout << "  ����  ��  �ভ��  ��  �᦭��  ��  �ভ��  ��  �᦭��  ��  �ভ��  ��  �᦭��  ��  �ভ��  ��  �ᦢ" << endl;
	}

	if (eo == 0) {				//
		cout << "  ����������������������������������������������������������������������������������������������������������������������������������" << endl;
	}

	return;
}
void printShortSquare(int eo, int num) {
	if (((eo == 0) && (num == 0)) || ((eo == 1) && (num == 1))) {		// XAND
		cout << " �ᦢ�� ";
		return;
	}
	else if (((eo == 1) && (num == 0)) || ((eo == 0) && (num == 1))) {	// XOR
		cout << " �ঢ�� ";
		return;
	}
}
void printBoard(Chess* p) {
	int i, j, k;
	char row = 'A', col = '8';
	for (j = 0; j < 63; j++)				// ������ �̵� p[63]
		p++;
	cout << endl;
	cout << "  ����������������������������������������������������������������������������������������������������������������������������������" << endl;
	for (i = 1; i < 9; i++) {
		printLongSquare(1, i % 2);
		for (j = 1; j < 8; j++) {
			if (j == 1) {					// ó�� ���� ���
				cout << col;				// 1 ~ 8 ���
				if ((i % 2) == 0) {				// ¦���� ���
					cout << " ���� ";
				}
				else if ((i % 2) == 1) {		// Ȧ���� ���
					cout << " ���� ";
				}
			}

			if (p->showExist()) {				// ���� ������ ���
				cout << p->piece->showCode();		// pieceCode ���
												// ����� �⹰�� King �Ǵ� Queen�� ���
				if ((p->piece->showCode()[1] == 'K') || (p->piece->showCode())[1] == 'Q') {
					if(p->piece->showCode()[2] == NULL)
						cout << " ";				// �� ĭ �� ����
				}
			}
			else {								// �ƴ� ���
				cout << p->showColor();				// Color ���
			}
			printShortSquare((i % 2), (j % 2));
			p--;	// ���� ĭ����

			if (j == 7) {						// ������ ���� ��� �׸���
				if (p->showExist()) {				// ���� ������ ���
					cout << p->piece->showCode();		// Code ���
													// ��µ� ���� ŷ �Ǵ� ���� ���
					if ((p->piece->showCode()[1] == 'K') || (p->piece->showCode())[1] == 'Q') {
						if (p->piece->showCode()[2] == NULL)
							cout << " ";				// �� ĭ �� ����
					}
				}
				else {								// �ƴ� ���
					cout << p->showColor();				// Color ���
				}
				if ((i % 2) == 0) {					// ¦���� ��� 
					cout << " �ᦢ" << endl;		
				}
				else if ((i % 2) == 1) {			// Ȧ���� ���
					cout << " �ঢ" << endl;
				}
				p--;	// ���� ĭ����
			}
		}
		if ((i % 8) == 0) {					// ������ ���� ���
			printLongSquare(1, i % 2);		
		}
		else {								// �ƴҰ��
			printLongSquare(0, i % 2);
		}
		col--;	// 8->7, 7->6, ...
	}
	cout << "  ����������������������������������������������������������������������������������������������������������������������������������" << endl;

	for (k = 0; k < 8; k++) {				// A ~ H ���
		cout << "      " << row << " ";
		row++;
	}
	cout << endl;

	return;
}

void printMenu() {
	cout
		<< "����������������������������������" << "\n"
		<< "�� 1. ���� ���� \t��" << "\n"
		<< "�� 2. ���� ���� \t��" << "\n"
		<< "�� 3. ���� ���� \t��" << "\n"
		<< "����������������������������������" << "\n����� �������ּ���>>";
	return;
}

void printInfo(Chess cell[], int index) {
	cout << cell[index].showCellName() << endl;
	cout << cell[index].showWBorder() << endl;
	return;
}