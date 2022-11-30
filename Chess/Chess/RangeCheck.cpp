#include "Chess.h"
void rookExplore(Chess* p, string secPiece);
void bishopExplore(Chess* p, string secPiece);
void knightExplore(Chess* p, string secPiece);
void queenExplore(Chess* p, string secPiece);
void kingExplore(Chess* p, string secPiece);
void pawnExplore(Chess* p, string secPiece, char color);

void Chess::RangeCheck(Chess* p, string secPiece)
{
	for (int i = 1; i <= 64; i++) {			  // 목적지와 이름이 동일한 주소로 이동
		if (p->piece->showCode() == secPiece) // 찾으면
			break;                            // 멈춤
		else if (p->showCellName() == secPiece)
			break;                            //    ``
		else                                  // 아니라면
			p++;                              // 다음 칸으로
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
	//→
	if (p->showEBorder() == false)//현재 위치가 오른쪽 경계선이 아니라면
	{
		int i = 1;
		p -= 1;//주소를 오른쪽으로 한 칸 이동
		while (true) {
			if (p->showExist())
			{
				if (p->piece->showCode()[0] == secPiece[0]) {//아군 기물을 만났을 때
					break;
				}
				else if (p->piece->showCode()[0] != secPiece[0]) {//적 기물을 만났을 때
					p->insertResRook(true);
					break;
				}
			}
			else if (p->showEBorder()) {//현재 위치가 오른쪽 경계선이라면
				p->insertResRook(true);
				break;
			}
			else//현재 위치가 경계선도 아니고 기물을 만나지 않았을 때
			{
				p->insertResRook(true);
				i++;
				p -= 1;//한 칸 앞으로
			}
		}
		p += 1 * i;
	}
	//←
	if (p->showWBorder() == false)//현재 위치가 왼쪽 경계선이 아니라면
	{
		int i = 1;
		p += 1;//주소를 왼쪽으로 한 칸 이동
		while (true) {
			if (p->showExist())
			{
				if (p->piece->showCode()[0] == secPiece[0]) {//아군 기물을 만났을 때
					break;
				}
				else if (p->piece->showCode()[0] != secPiece[0]) {//적 기물을 만났을 때
					p->insertResRook(true);
					break;
				}
			}
			else if (p->showWBorder()) {//현재 위치가 왼쪽 경계선이라면
				p->insertResRook(true);
				break;
			}
			else//현재 위치가 경계선도 아니고 기물을 만나지 않았을 때
			{
				p->insertResRook(true);
				i++;
				p += 1;//한 칸 앞으로
			}
		}
		p -= 1 * i;
	}
	//↓
	if (p->showSBorder() == false)//현재 위치가 아래쪽 경계선이 아니라면
	{
		int i = 1;
		p -= 8;//주소를 아래쪽으로 한 칸 이동
		while (true) {
			if (p->showExist())
			{
				if (p->piece->showCode()[0] == secPiece[0]) {//아군 기물을 만났을 때
					break;
				}

				else if (p->piece->showCode()[0] != secPiece[0]) {//적 기물을 만났을 때
					p->insertResRook(true);
					break;
				}
			}
			else if (p->showSBorder()) {//현재 위치가 아래쪽 경계선이라면
				p->insertResRook(true);
				break;
			}
			else//현재 위치가 경계선도 아니고 기물을 만나지 않았을 때
			{
				p->insertResRook(true);
				i++;
				p -= 8;//한 칸 앞으로
			}
		}
		p += 8 * i;
	}
	//↑
	if (p->showNBorder() == false)//현재 위치가 위쪽 경계선이 아니라면
	{
		int i = 1;
		p += 8;//주소를 위쪽으로 한 칸 이동
		while (true) {
			if (p->showExist())
			{
				if (p->piece->showCode()[0] == secPiece[0]) {//아군 기물을 만났을 때
					break;
				}
				else if (p->piece->showCode()[0] != secPiece[0]) {//적 기물을 만났을 때
					p->insertResRook(true);
					break;
				}
			}
			else if (p->showNBorder()) {//현재 위치가 위쪽 경계선이라면
				p->insertResRook(true);
				break;
			}
			else//현재 위치가 경계선도 아니고 기물을 만나지 않았을 때
			{
				p->insertResRook(true);
				i++;
				p += 8;//한 칸 앞으로
			}
		}
		p -= 8 * i;
	}
}
void bishopExplore(Chess* p, string secPiece) {
	//↖
	if ((p->showWBorder() == false) && (p->showNBorder() == false))//현재 위치가 왼쪽 경계선 AND 위쪽 경계선이 아니라면
	{
		int i = 1;
		p += 9;//주소를 왼쪽 위로 한 칸 이동
		while (true) {
			if (p->showExist()) {
				if (p->piece->showCode()[0] == secPiece[0]) {//아군 기물을 만났을 때
					break;
				}
				else if (p->piece->showCode()[0] != secPiece[0]) {//적 기물을 만났을 때
					p->insertResBishop(true);
					break;
				}
			}
			else if ((p->showWBorder()) || (p->showNBorder())) {//현재 위치가 왼쪽 경계선이라면
				p->insertResBishop(true);
				break;
			}
			else//현재 위치가 경계선도 아니고 기물을 만나지 않았을 때
			{
				p->insertResBishop(true);
				i++;
				p += 9;//한 칸 앞으로
			}
		}
		p -= 9 * i;
	}
	//↗
	if ((p->showEBorder() == false) && (p->showNBorder() == false))//현재 위치가 왼쪽 경계선 AND 위쪽 경계선이 아니라면
	{
		int i = 1;
		p += 7;//주소를 왼쪽 위로 한 칸 이동
		while (true) {
			if (p->showExist()) {
				if (p->piece->showCode()[0] == secPiece[0]) {//아군 기물을 만났을 때							1
					break;
				}
				else if (p->piece->showCode()[0] != secPiece[0]) {//적 기물을 만났을 때								2
					p->insertResBishop(true);
					break;
				}
			}
			else if ((p->showEBorder()) || (p->showNBorder())) {//현재 위치가 왼쪽 경계선이라면	3
				p->insertResBishop(true);
				break;
			}
			else//현재 위치가 경계선도 아니고 기물을 만나지 않았을 때
			{
				p->insertResBishop(true);
				i++;
				p += 7;//한 칸 앞으로
			}
		}
		p -= 7 * i;
	}
	//↘
	if ((p->showEBorder() == false) && (p->showSBorder() == false))//현재 위치가 오른쪽 경계선 AND 위쪽 경계선이 아니라면
	{
		int i = 1;
		p -= 9;//주소를 왼쪽 위로 한 칸 이동
		while (true) {
			if (p->showExist()) {
				if (p->piece->showCode()[0] == secPiece[0]) {//아군 기물을 만났을 때
					break;
				}
				else if (p->piece->showCode()[0] != secPiece[0]) {//적 기물을 만났을 때
					p->insertResBishop(true);
					break;
				}
			}
			else if ((p->showEBorder()) || (p->showSBorder())) {//현재 위치가 오른쪽 경계선이라면
				p->insertResBishop(true);
				break;
			}
			else//현재 위치가 경계선도 아니고 기물을 만나지 않았을 때
			{
				p->insertResBishop(true);
				i++;
				p -= 9;//한 칸 앞으로
			}
		}
		p += 9 * i;
	}
	//↙
	if ((p->showWBorder() == false) && (p->showSBorder() == false))//현재 위치가 오른쪽 경계선 AND 위쪽 경계선이 아니라면
	{
		int i = 1;
		p -= 7;//주소를 왼쪽 위로 한 칸 이동
		while (true) {
			if (p->showExist()) {
				if (p->piece->showCode()[0] == secPiece[0]) {//아군 기물을 만났을 때
					break;
				}
				else if (p->piece->showCode()[0] != secPiece[0]) {//적 기물을 만났을 때
					p->insertResBishop(true);
					break;
				}
			}
			else if ((p->showWBorder()) || (p->showSBorder())) {//현재 위치가 오른쪽 경계선이라면
				p->insertResBishop(true);
				break;
			}
			else//현재 위치가 경계선도 아니고 기물을 만나지 않았을 때
			{
				p->insertResBishop(true);
				i++;
				p -= 7;//한 칸 앞으로
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

	// 변수 N, S, W, E에 따라 true 입력
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
	//→
	if (p->showEBorder() == false)//현재 위치가 오른쪽 경계선이 아니라면
	{
		int i = 1;
		p -= 1;//주소를 오른쪽으로 한 칸 이동
		while (true) {
			if (p->showExist())
			{
				if (p->piece->showCode()[0] == secPiece[0]) {//아군 기물을 만났을 때
					break;
				}
				else if (p->piece->showCode()[0] != secPiece[0]) {//적 기물을 만났을 때
					p->insertResQueen(true);
					break;
				}
			}
			else if (p->showEBorder()) {//현재 위치가 오른쪽 경계선이라면
				p->insertResQueen(true);
				break;
			}
			else//현재 위치가 경계선도 아니고 기물을 만나지 않았을 때
			{
				p->insertResQueen(true);
				i++;
				p -= 1;//한 칸 앞으로
			}
		}
		p += 1 * i;
	}
	//←
	if (p->showWBorder() == false)//현재 위치가 왼쪽 경계선이 아니라면
	{
		int i = 1;
		p += 1;//주소를 왼쪽으로 한 칸 이동
		while (true) {
			if (p->showExist())
			{
				if (p->piece->showCode()[0] == secPiece[0]) {//아군 기물을 만났을 때
					break;
				}
				else if (p->piece->showCode()[0] != secPiece[0]) {//적 기물을 만났을 때
					p->insertResQueen(true);
					break;
				}
			}
			else if (p->showWBorder()) {//현재 위치가 오른쪽 경계선이라면
				p->insertResQueen(true);
				break;
			}
			else//현재 위치가 경계선도 아니고 기물을 만나지 않았을 때
			{
				p->insertResQueen(true);
				i++;
				p += 1;//한 칸 앞으로
			}
		}
		p -= 1 * i;
	}
	//↓
	if (p->showSBorder() == false)//현재 위치가 아래쪽 경계선이 아니라면
	{
		int i = 1;
		p -= 8;//주소를 아래쪽으로 한 칸 이동
		while (true) {
			if (p->showExist())
			{
				if (p->piece->showCode()[0] == secPiece[0]) {//아군 기물을 만났을 때
					break;
				}
				else if (p->piece->showCode()[0] != secPiece[0]) {//적 기물을 만났을 때
					p->insertResQueen(true);
					break;
				}
			}
			else if (p->showSBorder()) {//현재 위치가 오른쪽 경계선이라면
				p->insertResQueen(true);
				break;
			}
			else//현재 위치가 경계선도 아니고 기물을 만나지 않았을 때
			{
				p->insertResQueen(true);
				i++;
				p -= 8;//한 칸 앞으로
			}
		}
		p += 8 * i;
	}
	//↑
	if (p->showNBorder() == false)//현재 위치가 위쪽 경계선이 아니라면
	{
		int i = 1;
		p += 8;//주소를 위쪽으로 한 칸 이동
		while (true) {
			if (p->showExist())
			{
				if (p->piece->showCode()[0] == secPiece[0]) {//아군 기물을 만났을 때
					break;
				}
				else if (p->piece->showCode()[0] != secPiece[0]) {//적 기물을 만났을 때
					p->insertResQueen(true);
					break;
				}
			}
			else if (p->showNBorder()) {//현재 위치가 오른쪽 경계선이라면
				p->insertResQueen(true);
				break;
			}
			else//현재 위치가 경계선도 아니고 기물을 만나지 않았을 때
			{
				p->insertResQueen(true);
				i++;
				p += 8;//한 칸 앞으로
			}
		}
		p -= 8 * i;
	}
	//↖
	if ((p->showWBorder() == false) && (p->showNBorder() == false))//현재 위치가 왼쪽 경계선 AND 위쪽 경계선이 아니라면
	{
		int i = 1;
		p += 9;//주소를 왼쪽 위로 한 칸 이동
		while (true) {
			if (p->showExist())
			{
				if (p->piece->showCode()[0] == secPiece[0]) {//아군 기물을 만났을 때
					break;
				}
				else if (p->piece->showCode()[0] != secPiece[0]) {//적 기물을 만났을 때
					p->insertResQueen(true);
					break;
				}
			}
			else if (p->showNBorder() || p->showWBorder()) {//현재 위치가 오른쪽 경계선이라면
				p->insertResQueen(true);
				break;
			}
			else//현재 위치가 경계선도 아니고 기물을 만나지 않았을 때
			{
				p->insertResQueen(true);
				i++;
				p += 9;//한 칸 앞으로
			}
		}
		p -= 9 * i;
	}
	//↗
	if ((p->showEBorder() == false) && (p->showNBorder() == false))//현재 위치가 왼쪽 경계선 AND 위쪽 경계선이 아니라면
	{
		int i = 1;
		p += 7;//주소를 왼쪽 위로 한 칸 이동
		while (true) {
			if (p->showExist())
			{
				if (p->piece->showCode()[0] == secPiece[0]) {//아군 기물을 만났을 때
					break;
				}
				else if (p->piece->showCode()[0] != secPiece[0]) {//적 기물을 만났을 때
					p->insertResQueen(true);
					break;
				}
			}
			else if (p->showNBorder() || p->showWBorder()) {//현재 위치가 오른쪽 경계선이라면
				p->insertResQueen(true);
				break;
			}
			else//현재 위치가 경계선도 아니고 기물을 만나지 않았을 때
			{
				p->insertResQueen(true);
				i++;
				p += 7;//한 칸 앞으로
			}
		}
		p -= 7 * i;
	}
	//↘
	if ((p->showEBorder() == false) && (p->showSBorder() == false))//현재 위치가 오른쪽 경계선 AND 위쪽 경계선이 아니라면
	{
		int i = 1;
		p -= 9;//주소를 왼쪽 위로 한 칸 이동
		while (true) {
			if (p->showExist())
			{
				if (p->piece->showCode()[0] == secPiece[0]) {//아군 기물을 만났을 때
					break;
				}

				else if (p->piece->showCode()[0] != secPiece[0]) {//적 기물을 만났을 때
					p->insertResQueen(true);
					break;
				}
			}
			else if ((p->showEBorder() == false) || (p->showSBorder() == false)) {//현재 위치가 오른쪽 경계선이라면
				p->insertResQueen(true);
				break;
			}
			else//현재 위치가 경계선도 아니고 기물을 만나지 않았을 때
			{
				p->insertResQueen(true);
				i++;
				p -= 9;//한 칸 앞으로
			}
		}
		p += 9 * i;
	}
	//↙
	if ((p->showWBorder() == false) && (p->showSBorder() == false))//현재 위치가 오른쪽 경계선 AND 위쪽 경계선이 아니라면
	{
		int i = 1;
		p -= 7;//주소를 왼쪽 위로 한 칸 이동
		while (true) {
			if (p->showExist())
			{
				if (p->piece->showCode()[0] == secPiece[0]) {//아군 기물을 만났을 때
					break;
				}

				else if (p->piece->showCode()[0] != secPiece[0]) {//적 기물을 만났을 때
					p->insertResQueen(true);
					break;
				}
			}
			else if ((p->showWBorder() == false) || (p->showSBorder() == false)) {//현재 위치가 오른쪽 경계선이라면
				p->insertResQueen(true);
				break;
			}
			else//현재 위치가 경계선도 아니고 기물을 만나지 않았을 때
			{
				p->insertResQueen(true);
				i++;
				p -= 7;//한 칸 앞으로
			}
		}
		p += 7 * i;
	}
}
void kingExplore(Chess* p, string secPiece)
{
	//→
	if (p->showEBorder() == false)//현재 위치가 오른쪽 경계선이 아니라면
	{
		p -= 1;		//주소를 오른쪽으로 한 칸 이동
		if ((p->piece->showCode()[0] == secPiece[0]) == false) {	// 아군 기물이 아닐 경우
			p->insertResKing(true);
		}
		p += 1;		// 제자리로
	}
	//←
	if (p->showWBorder() == false)//현재 위치가 왼쪽 경계선이 아니라면
	{
		p += 1;//주소를 왼쪽으로 한 칸 이동
		if ((p->piece->showCode()[0] == secPiece[0]) == false) {	// 아군 기물이 아닐 경우
			p->insertResKing(true);
		}
		p -= 1;
	}
	//↓
	if (p->showSBorder() == false)//현재 위치가 아래쪽 경계선이 아니라면
	{
		p -= 8;		// 주소를 아래쪽으로 한 칸 이동
		if ((p->piece->showCode()[0] == secPiece[0]) == false) {	// 아군 기물이 아닐 경우
			p->insertResKing(true);
		}
		p += 8;		// 제자리로
	}
	//↑
	if (p->showNBorder() == false)//현재 위치가 위쪽 경계선이 아니라면
	{
		p += 8;		// 주소를 위쪽으로 한 칸 이동
		if ((p->piece->showCode()[0] == secPiece[0]) == false) {	// 아군 기물이 아닐 경우
			p->insertResKing(true);
		}
		p -= 8;		// 제자리로
	}
	//↖
	if ((p->showWBorder() == false) || (p->showNBorder() == false))//현재 위치가 왼쪽 경계선 AND 위쪽 경계선이 아니라면
	{
		p += 9;//주소를 왼쪽 위로 한 칸 이동
		if ((p->piece->showCode()[0] == secPiece[0]) == false) {	// 아군 기물이 아닐 경우
			p->insertResKing(true);
		}
		p -= 9;
	}
	//↗
	if ((p->showEBorder() == false) || (p->showNBorder() == false))//현재 위치가 오른쪽 경계선 AND 위쪽 경계선이 아니라면
	{
		p += 7;//주소를 왼쪽 위로 한 칸 이동
		if ((p->piece->showCode()[0] == secPiece[0]) == false) {	// 아군 기물이 아닐 경우
			p->insertResKing(true);
		}
		p -= 7;
	}
	//↘
	if ((p->showEBorder() == false) || (p->showSBorder() == false))//현재 위치가 오른쪽 경계선 AND 아랫쪽 경계선이 아니라면
	{
		p -= 9;//주소를 왼쪽 위로 한 칸 이동
		if ((p->piece->showCode()[0] == secPiece[0]) == false) {	// 아군 기물이 아닐 경우
			p->insertResKing(true);
		}
		p += 9;
	}
	//↙
	if ((p->showWBorder() == false) || (p->showSBorder() == false))//현재 위치가 왼쪽 경계선 AND 아랫쪽 경계선이 아니라면
	{
		p -= 7;//주소를 왼쪽 위로 한 칸 이동
		if ((p->piece->showCode()[0] == secPiece[0]) == false) {	// 아군 기물이 아닐 경우
			p->insertResKing(true);
		}
		p += 7;
	}
}
void pawnExplore(Chess* p, string secPiece, char color) {
	if (color == 'W')
	{
		if (p->piece->showMoveCount())//폰이 움직인 적이 있다면
		{
			//↑
			if (p->showNBorder() == false)//현재 위치가 위쪽 경계선이 아니라면
			{
				p += 8;		//주소를 위쪽으로 한 칸 이동
				if (p->showExist() == false) {	//현재 위치에 기물이 있다면
					p->insertResPawn(true);
				}
				p -= 8;				// 제자리로
			}
			//↖
			if ((p->showWBorder() == false) || (p->showNBorder() == false))//현재 위치가 왼쪽 경계선 AND 위쪽 경계선이 아니라면
			{
				p += 9;//주소를 왼쪽 위로 한 칸 이동
				if (p->showExist())
				{
					if (p->showExist() && (p->piece->showCode()[0] != secPiece[0])) {//적 기물을 만났을 때
						p->insertResPawn(true);
					}
				}
				p -= 9;
			}
			//↗
			if ((p->showEBorder() == false) || (p->showNBorder() == false))//현재 위치가 왼쪽 경계선 AND 위쪽 경계선이 아니라면
			{
				p += 7;//주소를 오른쪽 위로 한 칸 이동
				if (p->showExist())
				{
					if (p->piece->showCode()[0] != secPiece[0]) {//적 기물을 만났을 때
						p->insertResPawn(true);
					}
				}
				p -= 7;			// 제자리로
			}
		}
		else//폰이 움직인 적이 없다면
		{
			//↑
			if (p->showNBorder() == false) {					// 1. 현재 기물 위치에서 N보더가 있는지 확인 2. 아니라면 주소증가(칸 이동)
				int i;											// 3.1 기물을 만났다면 종료  3.2 N보더를 만났다면 resPown = true 후 종료 			
				for (i = 1; i <= 2; i++)						// 3.3 그 외의 경우에는 resPown = true 후 주소 증가(칸 이동)	4. 포인터를 제자리로 이동 후 다른 곳 탐색
				{
					p += 8;//주소를 위쪽으로 한 칸 이동↑
					if (p->showExist()) {		// 기물을 만났을 때
						i++;
						break;
					}
					else if (p->showNBorder()) {// 현재 위치가 위쪽 경계선이라면
						p->insertResPawn(true);
						i++;
						break;
					}
					else//현재 위치가 경계선도 아니고 기물을 만나지 않았을 때
					{
						p->insertResPawn(true);
					}
				}
				p -= 8 * (i - 1);
			}
			//↖
			if ((p->showWBorder() == false) || (p->showNBorder() == false))//현재 위치가 왼쪽 경계선 AND 위쪽 경계선이 아니라면
			{
				p += 9;//주소를 왼쪽 위로 한 칸 이동
				if (p->showExist())
				{
					if (p->piece->showCode()[0] != secPiece[0]) {//적 기물을 만났을 때
						p->insertResPawn(true);
					}
				}
				p -= 9;
			}
			//↗
			if ((p->showEBorder() == false) || (p->showNBorder() == false))//현재 위치가 왼쪽 경계선 AND 위쪽 경계선이 아니라면
			{
				p += 7;//주소를 오른쪽 위로 한 칸 이동
				if (p->showExist())
				{
					if (p->piece->showCode()[0] != secPiece[0]) {//적 기물을 만났을 때
						p->insertResPawn(true);
					}
				}
				p -= 7;			// 제자리로
			}
		}
	}
	else if (color == 'B')
	{
		if (p->piece->showMoveCount())//폰이 움직였다면
		{
			//↓
			if (p->showSBorder() == false)//현재 위치가 아래쪽 경계선이 아니라면
			{
				p -= 8;//주소를 아래쪽으로 한 칸 이동
				if (p->showExist() == false) {	// 기물이 없다면
					p->insertResPawn(true);
				}
				p += 8;	//제자리로
			}
			//↘
			if ((p->showEBorder() == false) || (p->showSBorder() == false))//현재 위치가 오른쪽 경계선 AND 위쪽 경계선이 아니라면
			{
				p -= 9;//주소를 왼쪽 위로 한 칸 이동
				if (p->showExist())
				{
					if (p->piece->showCode()[0] != secPiece[0]) {//적 기물을 만났을 때
						p->insertResPawn(true);
					}
				}
				p += 9;
			}
			//↙
			if ((p->showWBorder() == false) || (p->showSBorder() == false))//현재 위치가 오른쪽 경계선 AND 위쪽 경계선이 아니라면
			{
				p -= 7;//주소를 왼쪽 위로 한 칸 이동
				if (p->showExist())
				{
					if (p->piece->showCode()[0] != secPiece[0]) {//적 기물을 만났을 때
						p->insertResPawn(true);
					}
				}
				p += 7;
			}
		}
		else
		{
			//↓
			if (p->showSBorder() == false) {
				int i;
				for (i = 1; i <= 2; i++)
				{
					p -= 8;		//주소를 위쪽으로 한 칸 이동
					if (p->showExist()) {			// 기물을 만났을 때
						i++;
						break;
					}
					else if (p->showSBorder()) {	// 현재 위치가 위쪽 경계선이라면
						p->insertResPawn(true);
						i++;
						break;
					}
					else {							//현재 위치가 경계선도 아니고 기물을 만나지 않았을 때
						p->insertResPawn(true);
					}
				}
				p += 8 * (i - 1);
			}
			//↘
			if ((p->showEBorder() == false) || (p->showSBorder() == false))	// 현재 위치가 오른쪽 경계선 AND 위쪽 경계선이 아니라면
			{
				p -= 9;//주소를 왼쪽 위로 한 칸 이동
				if (p->showExist())
				{
					if (p->piece->showCode()[0] != secPiece[0]) {	// 적 기물을 만났을 때
						p->insertResPawn(true);
					}
				}
				p += 9;
			}
			//↙
			if ((p->showWBorder() == false) || (p->showSBorder() == false))	// 현재 위치가 오른쪽 경계선 AND 위쪽 경계선이 아니라면
			{
				p -= 7;//주소를 왼쪽 위로 한 칸 이동
				if (p->showExist())
				{
					if (p->piece->showCode()[0] != secPiece[0]) {	// 적 기물을 만났을 때
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
	for (int i = 1; i <= 64; i++) {				// 목적지와 이름이 동일한 주소로 이동

		if (p->showCellName() == secCell)		// 찾으면
			break;								// 멈춤
		else									// 아니라면
			p++;								// 다음 칸으로
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