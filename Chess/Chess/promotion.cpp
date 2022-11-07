#include <iostream>
#include "Chess.h"
using namespace std;

void Chess::promotion(Chess* p) {
	char what;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 8; j++) {
			if (p->Exist == true) {					// 탐색한 칸에 기물이 존재하는데
				if (p->piece->showCode()[1] == 'P') {	// 그 기물이 폰이라면
					cout << "여왕 : 1 / 룩 : 2 / 비숍 : 3 / 나이트 : 4" << endl;
					cout << "폰을 어떤 기물로 승급시키시겠습니까? : ";
					cin >> what;
					if (p->piece->showCode()[0] == 'W') {		// 흰색이라면
						switch (what)
						{
						case 49:
							p->piece->changeCode("WQP");
							break;
						case 50:
							p->piece->changeCode("WRP");
							break;	
						case 51:
							p->piece->changeCode("WBP");
							break;
						case 52:
							p->piece->changeCode("WNP");
							break;
						default:
							cout << "잘못된 입력입니다!";
							
						}
					}
					else if (p->piece->showCode()[0] == 'B') {	// 검은색이라면
						switch (what)
						{
						case 49:
							p->piece->changeCode("BQP");
							break;
						case 50:
							p->piece->changeCode("BRP");
							break;
						case 51:
							p->piece->changeCode("BBP");
							break;
						case 52:
							p->piece->changeCode("BNP");
							break;
						default:
							cout << "잘못된 입력입니다!";
							
						}
					}
				}
			}
			p++;
		}
		if (i == 0)						// 처음한 반복이라면 
			p += 48;
			//for (int k = 0; k < 48; k++)	// 48칸 앞으로 이동
			//	p++;
	}

	return;
}