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
	Recode* rq = new Recode;	// Queue
	
	int end = 1, loser = 0;
	char start;

	
	while (true) {
		Chess->initData(Chess);
		system("cls");
		if (end == 0) {
			end = 1;
			cout << "기보 출력" << "\n";
			for (i = 0; i < rq->size(); i++) {
				cout << rq->dequeue() << "  ";
			}
			cout << endl;
		}
		if (loser > 0) {
			if (loser == 1)
				cout << "검은색의 승리";
			if (loser == 2)
				cout << "흰 색의 승리";
			cout << endl;
			loser = 0;
		}

		printMenu();
		cin >> start;

		if (start == 49) {
			int turn = 1, check = 0;
			//int index;
			char sec, secPiece[4], secCell[4];
			while (end) {
				for (int i = 0; i < 2; i++) {	// 한 수(턴)
					system("cls");
					printBoard(Chess);
					if (check > 0) {		// 체크 확인
						if (check == 1)			// 흰색 체크라면
							cout << "흰색 킹";
						if (check == 2)			// 검은색 체크라면
							cout << "검은색 킹";
						cout << " 체크" << endl;
					}
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
							<< "(ex >> WP6 C3 ) >> ";

						cin >> secPiece;	//움직일 기물 선택
						cin >> secCell;		//목적지

						if (Chess->checkInput(Chess, secPiece, secCell, i)) {
							string tmp;
							tmp += (char)(turn + 48);
							tmp += Chess->movePiece(cell, secPiece, secCell);	// 기물 이동
							rq->enqueue(tmp);						// 이번 턴의 기보값 저장

							Chess->promotion(Chess);				// 폰의 승급

							Chess->RangeCheck(Chess, secPiece);			// 체크 전 움직인 기물에 대한 이동 경로 조사
							check = Chess->kingCheck(Chess);			// 체크 확인후 check 변수에 반환값 저장		// check == 1 (흰색), check == 2 (검은색)
							Chess->initResData(Chess);					// Res데이터 기초값 설정
						}
						else {
							cout << "잘못된 입력입니다. 다시 입력해주세요." << endl;
							Sleep(1000);
							i--;
							continue;
						}
						break;
					case 50:
						cout << "체스 설명 칸\n";
						break;
					case 48:
						loser += i + 1;
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
