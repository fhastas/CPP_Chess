#include <iostream>
#include "Chess.h"
using namespace std;

void Chess::promotion(Chess* p) {
	char what;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 8; j++) {
			if (p->Exist == true) {					// Ž���� ĭ�� �⹰�� �����ϴµ�
				if (p->piece->showCode()[1] == 'P') {	// �� �⹰�� ���̶��
					cout << "���� : 1 / �� : 2 / ��� : 3 / ����Ʈ : 4" << endl;
					cout << "���� � �⹰�� �±޽�Ű�ðڽ��ϱ�? : ";
					cin >> what;
					if (p->piece->showCode()[0] == 'W') {		// ����̶��
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
							cout << "�߸��� �Է��Դϴ�!";
							
						}
					}
					else if (p->piece->showCode()[0] == 'B') {	// �������̶��
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
							cout << "�߸��� �Է��Դϴ�!";
							
						}
					}
				}
			}
			p++;
		}
		if (i == 0)						// ó���� �ݺ��̶�� 
			p += 48;
			//for (int k = 0; k < 48; k++)	// 48ĭ ������ �̵�
			//	p++;
	}

	return;
}