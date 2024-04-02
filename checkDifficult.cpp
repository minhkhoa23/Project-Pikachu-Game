#include "checkDifficult.h"
/* Che do kho duoc thuc hien duoi danh sach lien ket*/

/*
	Tim mot o y, x tren mang con danh sach lien ket cua che do kho
*/
BOX2* findTheNode(BOX2** arr, int y, int x) {
	if (y < 0 || y > 4 || x < 0 || x > 7) return NULL;
	BOX2* temp = arr[y];
	while (temp != NULL) {
		if (temp -> j == x) {
			return temp;
		}
		temp = temp -> next;
	}
	return NULL;
}


/*
	O thu nhat co toa do y1, x1
	O thu hai co toa do y2, x2
	Kiem tra xem 2 o co the duoc noi voi nhau qua hinh chu I hay khong?
*/
bool Icheck(BOX2** arr, int y1, int x1, int y2, int x2) {
	int ma, mi, i = 0;
	BOX2* temp, * tempHead;
	if (x1 == x2) {
		ma = max(y1, y2);
		mi = min(y1, y2);
		tempHead = findTheNode(arr, mi, x1);
		temp = tempHead;
		while (temp == NULL) {
			mi++;
			temp = findTheNode(arr, mi, x1);
			tempHead = temp;
			if (mi == ma) {
				return true;
			}
			if (temp != NULL) {
				return false;
			}
		}
		while (temp != NULL) {
			i++;
			temp = findTheNode(arr, mi + i, x1);
			while (temp == NULL) {
				i++;
				temp = findTheNode(arr, mi + i, x1);
				if (mi + i > ma) {
					return true;
				}
			}
			if (mi + i > ma) {
				return true;
			}
			if (mi + i == ma) {
				if (temp == NULL) {
					return true;
				}
				if (temp->c == tempHead->c) {
					return true;
				}
				return false;
			}
			if (temp != NULL) {
				return false;
			}
		}
	}
	if (y1 == y2) {
		i = 0;
		ma = max(x1, x2);
		mi = min(x1, x2);
		tempHead = findTheNode(arr, y1, mi);
		temp = tempHead;
		while (temp == NULL) {
			mi++;
			temp = findTheNode(arr, mi, x1);
			tempHead = temp;
			if (mi > ma) {
				return true;
			}
		}
		while (temp != NULL) {
			i++;
			temp = temp->next;
			if (mi + i > ma) {
				return true;
			}
			if (mi + i == ma) {
				if (temp == NULL) {
					return true;
				}
				if (temp->c == tempHead->c) {
					return true;
				}
				return false;
			}
			if (temp != NULL) {
				return false;
			}
		}
	}
	return false;
}


/*
	O thu nhat co toa do y1, x1
	O thu hai co toa do y2, x2
	Kiem tra xem 2 o co the duoc noi voi nhau qua hinh chu L hay khong?
*/
bool Lcheck(BOX2** arr, int y1, int x1, int y2, int x2) {
	BOX2* temp;
	temp = findTheNode(arr, y1, x2);
	if (temp == NULL) {
		int x = x2, y = y1;
		while (temp == NULL) {
			if (x2 > x1) {
				x--;
			}
			else {
				x++;
			}
			temp = findTheNode(arr, y1, x);
		}
		temp = NULL;
		while (temp == NULL) {
			if (y2 > y1) {
				y++;
			}
			else {
				y--;
			}
			temp = findTheNode(arr, y, x2);
		}
		if (Icheck(arr, y1, x1, y1, x)) {
			if (Icheck(arr, y2, x2, y, x2)) {
				return true;
			}
		}
		else if (Icheck(arr, y1, x1, y1, x)) {
			if (Icheck(arr, y2, x2, y, x2)) {
				return true;
			}
		}
	}

	temp = findTheNode(arr, y2, x1);
	if (temp == NULL) {
		int x = x1, y = y2;
		while (temp == NULL) {
			if (x2 > x1) {
				x++;
			}
			else {
				x--;
			}
			temp = findTheNode(arr, y2, x);
		}
		temp = NULL;
		while (temp == NULL) {
			if (y2 > y1) {
				y--;
			}
			else {
				y++;
			}
			temp = findTheNode(arr, y, x1);
		}
		if (Icheck(arr, y1, x1, y1, x)) {
			if (Icheck(arr, y2, x2, y, x2)) {
				return true;
			}
		}
		else if (Icheck(arr, y2, x2, y2, x)) {
			if (Icheck(arr, y1, x1, y, x1)) {
				return true;
			}
		}
	}

	return false;
}


/*
	O thu nhat co toa do y1, x1
	O thu hai co toa do y2, x2
	Kiem tra xem 2 o co the duoc noi voi nhau qua hinh chu U hay Z hay khong?
*/
bool UandZcheck(BOX2** arr, int y1, int x1, int y2, int x2) {
	if ((findTheNode(arr, y1 - 1, x1) == NULL && findTheNode(arr, y2 - 1, x2) == NULL || findTheNode(arr, y1 + 1, x1) == NULL && findTheNode(arr, y2 + 1, x2) == NULL) && (y1 == y2)) {
		return true;
	}

	if ((x1 == 0 && x2 == 0) || (findTheNode(arr, y1, x1)->next == NULL && findTheNode(arr, y2, x2)->next == NULL)) {
		return true;
	}

	BOX2* tempTail, * tempHead;
	if ((Icheck(arr, y1, x1, 0, x1) || Icheck(arr, y1, x1, 4, x1)) && (y1 != y2)) {
		tempTail = findTheNode(arr, y1, x2);
		if (tempTail == NULL) {
			int y = y1;
			if ((Icheck(arr, y1, x1, 0, x1))) {
				while (tempTail == NULL) {
					y++;
					tempTail = findTheNode(arr, y, x2);
				}
			}
			if (Icheck(arr, y, x2, y2, x2)) {
				return true;
			}
			y = y1;
			if (Icheck(arr, y1, x1, 4, x1)) {
				tempTail = NULL;
				while (tempTail == NULL) {
					y--;
					tempTail = findTheNode(arr, y, x2);
				}
			}
			if (Icheck(arr, y, tempTail->j, y2, x2)) {
				return true;
			}
		}
		if (Icheck(arr, tempTail->i, tempTail->j, y2, x2)) {
			return true;
		}
	}
	if ((Icheck(arr, y2, x2, 0, x2) || Icheck(arr, y2, x2, 4, x2)) && (y1 != y2)) {
		tempTail = findTheNode(arr, y2, x1);
		if (tempTail == NULL) {
			int y = y2;
			if (Icheck(arr, y2, x2, 0, x2)) {
				while (tempTail == NULL) {
					y++;
					tempTail = findTheNode(arr, y, x1);
				}
			}
			if (Icheck(arr, y, x1, y1, x1)) {
				return true;
			}
			y = y2;
			if (Icheck(arr, y2, x2, 4, x2)) {
				while (tempTail == NULL) {
					y--;
					tempTail = findTheNode(arr, y, x1);
				}
			}
			if (Icheck(arr, y, x1, y1, x1)) {
				return true;
			}
		}
		else {
			if (Icheck(arr, tempTail->i, tempTail->j, y1, x1)) {
				return true;
			}
		}
	}

	int ma, mi;
	ma = max(y1, y2);
	mi = min(y1, y2);
	if (x1 != x2) {
		for (int i = 0; (i < boardheight); i++) {
			tempHead = findTheNode(arr, i, x1);
			int x = x1;
			tempTail = findTheNode(arr, i, x2);
			x = x2;
			if (Icheck(arr, i, x1, i, x2)) {
				if (Icheck(arr, i, x1, y1, x1) && Icheck(arr, i, x2, y2, x2)) {
					return true;
				}
			}
		}
	}

	ma = max(x1, x2);
	mi = min(x1, x2);
	if (y1 != y2) {
		for (int i = 0; i < boardheight; i++) {
			tempHead = findTheNode(arr, y1, i);
			int y = y1;
			tempTail = findTheNode(arr, y2, i);
			y = y2;
			if (Icheck(arr, y1, i, y2, i)) {
				if (Icheck(arr, y1, i, y1, x1) && Icheck(arr, y2, i, y2, x2)) {
					return true;
				}
			}
		}
	}
	return false;
}


/*
	O thu nhat co toa do y1, x1
	O thu hai co toa do y2, x2
	Kiem tra xem 2 o co the duoc noi voi nhau qua hinh chu I hay L hay U hay Z hay khong?
*/
bool allCheck(BOX2** arr, int y1, int x1, int y2, int x2) {
	if (Icheck(arr, y1, x1, y2, x2)) return true;
	else if (Lcheck(arr, y1, x1, y2, x2)) return true;
	else if (UandZcheck(arr, y1, x1, y2, x2)) return true;
	return false;
}


/*
	Thuc hien xoa mot o tren danh sach lien ket cac o o che do kho
	O duoc xoa co toa do y, x tren bang cua man choi
*/
void deleteNode(BOX2** arr, int y, int x, char bg[][41]) {
	BOX2* p = findTheNode(arr, y, x);
	if (x == 0) {
		if (arr[y] -> next == NULL) {
			arr[y] -> deleteBox();
			if (arr[y] -> j < 4) displayBackground(bg, arr[y] -> j, y);
			arr[y] = NULL;
			return;
		}
		arr[y] -> c = p -> next -> c;

		p = arr[y] -> next;
		if (p -> next == NULL) {
			p -> deleteBox();
			if (p -> j < 4) displayBackground(bg, p -> j, y);
			delete p;
			arr[y] -> next = NULL;
		}
		else {
			while (p -> next->next != NULL)
			{
				p -> c = p -> next -> c;
				p = p -> next;
			}
			p -> c = p -> next ->  c;
			p->next->deleteBox();
			if (p -> next -> j < 4) displayBackground(bg, p -> next -> j, p -> next -> i);
			delete p -> next;
			p -> next = NULL;
		}
	}
	else if (p -> next != NULL) {
		while (p -> next -> next != NULL)
		{
			p -> c = p -> next -> c;
			p = p -> next;
		}
		p -> c = p -> next -> c;
		p -> next -> deleteBox();
		if (p -> next -> j < 4) displayBackground(bg, p -> next -> j, p -> next -> i);
		delete p -> next;
		p -> next = NULL;
	}
	else {
		p->deleteBox();
		if (p -> j < 4) displayBackground(bg, p -> j, p -> i);
		delete p;
		p = findTheNode(arr, y, x - 1);
		p -> next = NULL;
	}
}


/*
	Thuc hien xoa hai o tren danh sach lien ket co toa do lan luot la y1, x1 va y2, x2 cua bang tren man choi
*/
void DifMode(BOX2** arr, int y1, int x1, int y2, int x2, char bg[][41]) {
	if (x1 > x2)
	{
		deleteNode(arr, y1, x1, bg);
		deleteNode(arr, y2, x2, bg);
	}
	else {
		deleteNode(arr, y2, x2, bg);
		deleteNode(arr, y1, x1, bg);
	}
}



/*
	Kiem tra xem co 2 nut nao trong bang co the noi voi nhau bang hinh I hay L hay U hay Z hay khong?
*/
bool checkValidPairs(BOX2** arr) {
	BOX2* Head, * temp;
	for (int i = 0; i < 5; i++) {
		Head = arr[i];
		while (Head != NULL) {
			int j = i;
			temp = Head->next;
			while (temp == NULL && j < 4) {
				j++;
				temp = arr[j];
			}
			while (temp != NULL) {
				if (Head->c == temp->c) {
					if (allCheck(arr, Head->i, Head->j, temp->i, temp->j)) {
						return true;
					}
				}
				temp = temp->next;
				if ((temp == NULL) && (j < 4)) {
					j++;
					temp = findTheNode(arr, j, 0);
				}
			}
			Head = Head->next;
		}
	}
	return false;
}