#include <iostream>
#include "Chess.h"

void printLongSquare(int eo, int num) {
	if (num == 1) {
		cout << "  ����  ��  �᦭��  ��  �ভ��  ��  �᦭��  ��  �ভ��  ��  �᦭��  ��  �ভ��  ��  �᦭��  ��  �ঢ" << endl;
	}
	else if (num == 0) {
		cout << "  ����  ��  �ভ��  ��  �᦭��  ��  �ভ��  ��  �᦭��  ��  �ভ��  ��  �᦭��  ��  �ভ��  ��  �ᦢ" << endl;
	}

	if (eo == 0) {
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
	for (j = 0; j < 63; j++)	// ������ �̵� p[63]
		p++;
	for (k = 0; k < 8; k++) {
		cout << "      " << row << " ";
		row++;
	}
	cout << endl;
	cout << "  ����������������������������������������������������������������������������������������������������������������������������������" << endl;
	for (i = 1; i < 9; i++) {
		printLongSquare(1, i % 2);
		for (j = 1; j < 8; j++) {
			if (j == 1) {
				cout << col;
				if ((i % 2) == 0) {
					cout << " ���� ";
				}
				else if ((i % 2) == 1) {
					cout << " ���� ";
				}
			}
			cout << p->piece->showCode(p->piece);
			printShortSquare((i % 2), (j % 2));
			p--;	// ���� ĭ����
			if (j == 7) {
				if ((i % 2) == 0) {
					cout << p->piece->showCode(p->piece) << " �ᦢ" << endl;
				}
				else if ((i % 2) == 1) {
					cout << p->piece->showCode(p->piece) << " �ঢ" << endl;
				}
				p--;	// ���� ĭ����
			}
		}
		if ((i % 8) == 0) {
			printLongSquare(1, i % 2);
		}
		else {
			printLongSquare(0, i % 2);
		}
		col--;
	}
	cout << "  ����������������������������������������������������������������������������������������������������������������������������������" << endl;

	return;
}

int printMenu() {
	int f;
	while (1) {
		cout
			<< "����������������������������������" << "\n"
			<< "�� 1. ���� ���� \t��" << "\n"
			<< "�� 2. ���� ���� \t��" << "\n"
			<< "�� 3. ���� ���� \t��" << "\n"
			<< "����������������������������������" << "\n����� �������ּ���>>";
		cin >> f;

		return f;
	}
}