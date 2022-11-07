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
			cout << "기보 출력" << "\n";
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
				for (i = 0; i < 2; i++) {	// 한 수(턴)
					system("cls");
					printBoard(Chess);
					cout << "1: 말 이동 2: 체스 설명 0: 종료(기권)\n>>";
					cin >> sec;
					switch (sec)
					{
					case 49:
						if (i % 2)
							cout << "(흑)";
						else
							cout << "(백)";
						cout << "움직일 말과 이동할 칸을 선택해주세요." << "\n"
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
							cout << "잘못된 입력입니다. 다시 입력해주세요." << endl;
							Sleep(1000);
							continue;
						}
						break;
					case 50:
						cout << "체스 설명 칸\n";
						break;
					case 48:
						end = 0;
						break;
					default:
						cout << "다시 입력부탁드립니다.";
						Sleep(1000);
						continue;
					}
					if (end == 0) {
						break;
					}
				}
				turn++;		// 수(턴) 증가
			}
		}
		else if (start == 50) {
			system("cls");
			cout << "체스 설명" << endl;
			getchar();
		}
		else if (start == 51) {
			cout << "종료하시겠습니까? \n(Y = 1, N = 2)>>";
			cin >> end;
			if (end == 1) {
				return 0;
			}
			else {
				continue;
			}
		}
		else {
			cout << "지원하지 않는 입력입니다";
			Sleep(1000);
			continue;
		}
	}

}
