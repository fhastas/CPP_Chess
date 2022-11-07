#include <iostream>
#include <Windows.h>
#include "Chess.h"
#include "Queue.h"
using namespace std;

int main() {
	int i;
	Chess cell[64];
	for (i = 0; i < 64; i++) {
		cell[i].piece = new Piece;
	}
	Chess* Chess = cell;		// p->cell, cell[index]->Piece
	Recode* rq = new Recode;
	
	int index, end = 1;
	char start;

	Chess->initData(Chess);
	while (true) {
		system("cls");
		if (end == 0) {
			end = 1;
			cout << "�⺸ ���" << "\n";
			for (i = 0; i < rq->size(); i++) {
				cout << rq->dequeue() << "  ";
			}
			cout << endl;
		}
		printMenu();
		cin >> start;

		if (start == 49) {
			int turn = 1;
			char sec, secPiece[4], secCell[4];
			while (end) {
				for (i = 0; i < 2; i++) {	// �� ��(��)
					system("cls");
					printBoard(Chess);
					cout << "1: �� �̵� 2: ü�� ���� 0: ����(���)\n>>";
					cin >> sec;
					switch (sec)
					{
					case 49:
						if (i % 2)
							cout << "(��)";
						else
							cout << "(��)";
						cout << "������ ���� �̵��� ĭ�� �������ּ���." << "\n"
							<< "(ex)>>(WP6 or C2) C3 >>";

						cin >> secPiece >> secCell;

						if (Chess->checkInput(Chess, secPiece, secCell)) {
							string tmp;
							tmp += (char)(turn + 48);
							tmp += Chess->movePiece(cell, secPiece, secCell);
							rq->enqueue(tmp);

							Chess->promotion(Chess);
						}
						else {
							cout << "�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���." << endl;
							Sleep(1000);
							continue;
						}
						break;
					case 50:
						cout << "ü�� ���� ĭ\n";
						break;
					case 48:
						end = 0;
						break;
					default:
						cout << "�ٽ� �Էº�Ź�帳�ϴ�.";
						Sleep(1000);
						continue;
					}
					if (end == 0) {
						break;
					}
				}
				turn++;		// ��(��) ����
			}
		}
		else if (start == 50) {
			system("cls");
			cout << "ü�� ����" << endl;
			getchar();
		}
		else if (start == 51) {
			cout << "�����Ͻðڽ��ϱ�? \n(Y = 1, N = 2)>>";
			cin >> end;
			if (end == 1) {
				return 0;
			}
			else {
				continue;
			}
		}
		else {
			cout << "�������� �ʴ� �Է��Դϴ�";
			Sleep(1000);
			continue;
		}
	}

}
