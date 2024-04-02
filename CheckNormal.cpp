#include "CheckNormal.h"
/* Che do binh thuong duoc thuc hien duoi mang con tro 2 chieu */


/*
    O thu nhat co toa do p1, p2
    O thu hai co toa do q1, q2
    Kiem tra xem 2 o co thao dieu kien ke nhau hay khong
*/
bool nextcheck(BOX1** board, int p1, int p2, int q1, int q2) {
	if ((p1 == p1 + 1 || p1 == q1 - 1) && (p2 == q2)) {
		if (board[p1][p2].c == board[q1][q2].c) {
			return true;
		}
	}
	if ((p2 == p2 + 1 || p2 == q2 - 1) && (p1 == q1)) {
		if (board[p1][p2].c == board[q1][q2].c) {
			return true;
		}
	}
	return false;
}


/*
    O thu nhat co toa do p1, p2
    O thu hai co toa do q1, q2
    Kiem tra xem giua 2 o theo cot hay theo dong khong co o nam nam giua
*/
bool linecheck(BOX1** board,int p1,int p2,int q1,int q2) {
	if (p1 == q1) {
		int y, x, dem = 0;
		if (p2 > q2) {
			x = q2;
			y = p2;
		}
		else {
			x = p2;
			y = q2;
		}
		for (int i = x; i <= y; i++) {
			if (board[p1][i].isValid) {
				dem++;
				if (dem == 2) {
					return false;
				}
			}
		}
		if ((dem == 1) && ((!board[p1][p2].isValid && board[q1][q2].isValid) || (board[p1][p2].isValid && !board[q1][q2].isValid))) {
			return true;
		}
		else if (dem == 0) {
			return true;
		}
		return false;
	}
	if (p2 == q2) {
		int x, y, dem = 0;
		if (p1 > q1) {
			x = q1;
			y = p1;
		}
		else {
			x = p1;
			y = q1;
		}
		for (int i = x; i <= y; i++) {
			if (board[i][p2].isValid) {
				dem++;
				if (dem == 2) {
					return false;
				}
			}
		}
		if ((dem == 1) && ((!board[p1][p2].isValid && board[q1][q2].isValid) || (board[p1][p2].isValid && !board[q1][q2].isValid))) {
			return true;
		}
		else if (dem == 0) {
			return true;
		}
		return false;
	}
	return false;
}


/*
    O thu nhat co toa do p1, p2
    O thu hai co toa do q1, q2
    Kiem tra xem giua 2 o co the noi voi nhau theo hinh chu I khong
*/
bool IcheckNormal(BOX1** board, int p1, int p2, int q1, int q2) {
	if (p1 == q1) {
		int y, x, dem = 0;
		if (p2 > q2) {
			x = q2;
			y = p2;
		}
		else {
			x = p2;
			y = q2;
		}
		for (int i = x + 1; i < y; i++) {
			if (board[p1][i].isValid) {
				return false;
			}
		}
		return true;
	}
	if (p2 == q2) {
		int x, y, dem = 0;
		if (p1 > q1) {
			x = q1;
			y = p1;
		}
		else {
			x = p1;
			y = q1;
		}
		for (int i = x + 1; i < y; i++) {
			if (board[i][p2].isValid) {
				return false;
			}
		}
		return true;
	}
	return false;
}


/*
    O thu nhat co toa do p1, p2
    O thu hai co toa do q1, q2
    Kiem tra xem giua 2 o co the noi voi nhau theo hinh chu L khong
*/
bool LcheckNormal(BOX1** board, int p1, int p2, int q1, int q2) {
	if (p1 == q1 || p2 == q2) {
		return false;
	}
	bool c1, c2;
	if (!board[p1][q2].isValid) {
		c1 = linecheck(board, p1, p2, p1, q2);
		c2 = linecheck(board, q1, q2, p1, q2);
		if (c1 && c2) {
			return true;
		}
	}
	if (!board[q1][p2].isValid) {
		c1 = linecheck(board, p1, p2, q1, p2);
		c2 = linecheck(board, q1, q2, q1, p2);
		if (c1 && c2) {
			return true;
		}
	}
	return false;
}


/*
    O thu nhat co toa do p1, p2
    O thu hai co toa do q1, q2
    Kiem tra xem giua 2 o co the noi voi nhau theo hinh chu Z khong
*/
bool ZcheckNormal(BOX1** board, int p1, int p2, int q1, int q2) {
	if (p1 == q1 || p2 == q2) {
		return false;
	}
	bool c1, c2, c3;
	int x, y;
	if (q2 < p2) {
		x = q2;
		y = p2;
	}
	else {
		x = p2;
		y = q2;
	}
	for (int i = x + 1; i < y; i++) {
		c3 = linecheck(board, p1, i, q1, i);
		if (c3) {
			c1 = linecheck(board, p1, p2, p1, i);
			c2 = linecheck(board, q1, q2, q1, i);
			if (c1 && c2) {
				return true;
			}
		}
	}
	if (q1 < p1) {
		x = q1;
		y = p1;
	}
	else {
		x = p1;
		y = q1;
	}
	for (int i = x + 1; i < y; i++) {
		c3 = linecheck(board, i, p2, i, q2);
		if (c3) {
			c1 = linecheck(board, p1, p2, i, p2);
			c2 = linecheck(board, q1, q2, i, q2);
			if (c1 && c2) {
				return true;
			}
		}
	}
	return false;
}


/*
    O thu nhat co toa do p1, p2
    O thu hai co toa do q1, q2
    Kiem tra xem giua 2 o co the noi voi nhau theo hinh chu U khong
*/
bool UcheckNormal(BOX1** board, int p1, int p2, int q1, int q2) {
	if (((p1 == q1) && (p1 == 0 || p1 == boardheight - 1) || ((p2 == q2) && (p2 == 0 || q2 == boardwidth - 1)))) {
		return true;
	}
	bool c1, c2, c3;
	int x, y;
	if (q2 < p2) {
		x = q2;
		y = p2;
	}
	else {
		x = p2;
		y = q2;
	}
	for (int i = 0; i < boardwidth; i++) {
		if (i <= x || i >= y) {
			c3 = linecheck(board, p1, i, q1, i);
			if (c3) {
				c1 = linecheck(board, p1, p2, p1, i);
				c2 = linecheck(board, q1, q2, q1, i);
				if (c1 && c2) {
					return true;
				}
			}
			else if (i == 0 || i == (boardwidth - 1)) {
				c1 = linecheck(board, p1, p2, p1, i);
				c2 = linecheck(board, q1, q2, q1, i);
				if ((c1 && c2) || (c1 && q2 == i) || (p2 == i && c2)) {
					return true;
				}
			}
		}
	}
	if (q1 < p1) {
		x = q1;
		y = p1;
	}
	else {
		x = p1;
		y = q1;
	}
	for (int i = 0; i < boardheight; i++) {
		if (i <= x || i >= y) {
			c3 = linecheck(board, i, p2, i, q2);
			if (c3) {
				c1 = linecheck(board, p1, p2, i, p2);
				c2 = linecheck(board, q1, q2, i, q2);
				if (c1 && c2) {
					return true;
				}
			}
			else if (i == 0 || i == (boardheight - 1)) {
				c1 = linecheck(board, p1, p2, i, p2);
				c2 = linecheck(board, q1, q2, i, q2);
				if ((c1 && c2) || (c1 && q1 == i) || (p1 == i && c2)) {
					return true;
				}
			}
		}
	}
	return false;
}


/*
    O thu nhat co toa do p1, p2
    O thu hai co toa do q1, q2
    Kiem tra xem giua 2 o co the noi voi nhau theo hinh chu I hay L hay U hay Z khong
*/
bool allcheck(BOX1** board, int p1, int p2, int q1, int q2) {
	if (nextcheck(board, p1, p2, q1, q2)) {
		return true;
	}
	else if (IcheckNormal(board, p1, p2, q1, q2)) {
		return true;
	}
	else if (LcheckNormal(board, p1, p2, q1, q2)) {
		return true;
	}
	else if (ZcheckNormal(board, p1, p2, q1, q2)) {
		return true;
	}
	else if (UcheckNormal(board, p1, p2, q1, q2)) {
		return true;
	}
	return false;
}


/*
    Kiem tra xem co 2 nut nao trong bang co the noi voi nhau bang hinh I hay L hay U hay Z hay khong?
*/
bool checkValidPairs(BOX1** board) {
	char check = 'A';
	while (check >= 'A' && check <= 'Z') {
		int cnt = 0;
		int* pos = new int[boardheight * boardwidth];
		for (int i = 0; i < boardheight; i++) {
			for (int j = 0; j < boardwidth; j++) {
				if (board[i][j].c == check && board[i][j].isValid) {
					pos[cnt++] = i;
					pos[cnt++] = j;
				}
			}
		}
		for (int i = 0; i < cnt - 2; i += 2) {
			for (int j = i + 2; j < cnt; j += 2) {
				if (allcheck(board, pos[i], pos[i + 1], pos[j], pos[j + 1])) {
					delete[] pos;
					return true;
				}
			}
		}
		check++;
		delete[]pos;
	}
	return false;
}