#include "DifficultBoard.h"
#include<iostream>
using namespace std;

char BG[20][41];



/*
	Them mot nut moi cho duoi danh sach lien ket
*/
void push(BOX2*& head, BOX2* p) {
	if (head == NULL) {
		head = p;
	}
	else {
		BOX2* temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = p;
	}
}


/*
	Khoi tao danh sach lien ket 2 chieu
*/
void initList(BOX2** arr) {
	for (int i = 0; i < boardheight; i++) {
		arr[i] = NULL;
		for (int j = 0; j < 8; j++) {
			BOX2* p = new BOX2;
			p->i = i;
			p->j = j;
			p->next = NULL;
			push(arr[i], p);
		}
	}

	int flagNum = 20;
	while (flagNum) {
		int i, time = 2;
		char c = 65 + rand() % 26;
		while (time)
		{
			i = rand() % 5;
			int j = rand() % 8;
			BOX2* p = findTheNode(arr, i, j);
			if (p->c == ' ') {
				p->c = c;
				time--;
			}
		}
		flagNum--;
	}
}


/*
	Xoa toan bo danh sach lien ket 2 chieu
*/
void deleteList(BOX2** arr) {
	for (int i = 0; i < boardheight; i++) {
		BOX2* temp;
		while (arr[i] != NULL)
		{
			temp = arr[i];
			arr[i] = arr[i]->next;
			temp->deleteBox();
			if (temp->j < 4) displayBackground(BG, temp->j, i);
			Sleep(500);
			delete temp;
		}
	}
	delete[]arr;
}


/*
	Ve o trong danh sach lien ket 2 chieu
*/
void renderList(BOX2** arr) {
	for (int i = 0; i < boardheight; i++) {
		BOX2* temp = arr[i];
		while (temp != NULL)
		{
			temp->drawBox(112);
			temp = temp->next;
		}
	}
}


/*
	Di chuyen con tro dang chon o len tren bang danh sach lien ket
*/
void MoveUp(BOX2** arr, toaDo& pos) {
	for (int i = pos.x; i < boardwidth; i++) {
		for (int j = pos.y - 1; j >= 0; j--) {
			if (findTheNode(arr, j, i) != NULL) {
				pos.x = i;
				pos.y = j;
				return;
			}
		}
	}

	for (int i = pos.x - 1; i >= 0; i--) {
		for (int j = pos.y - 1; j >= 0; j--) {
			if (findTheNode(arr, j, i) != NULL) {
				pos.x = i;
				pos.y = j;
				return;
			}
		}
	}

	for (int i = pos.x; i < boardwidth; i++) {
		for (int j = boardheight - 1; j > pos.y; j--) {
			if (findTheNode(arr, j, i) != NULL) {
				pos.x = i;
				pos.y = j;
				return;
			}
		}
	}

	for (int i = pos.x; i >= 0; i--) {
		for (int j = boardheight - 1; j > pos.y; j--) {
			if (findTheNode(arr, j, i) != NULL) {
				pos.x = i;
				pos.y = j;
				return;
			}
		}
	}

}


/*
	Di chuyen con tro dang chon o xuong duoi bang danh sach lien ket
*/
void MoveDown(BOX2** arr, toaDo& pos) {
	for (int i = pos.x; i < boardwidth; i++) {
		for (int j = pos.y + 1; j < boardheight; j++) {
			if (findTheNode(arr, j, i) != NULL) {
				pos.x = i;
				pos.y = j;
				return;
			}
		}
	}

	for (int i = pos.x - 1; i >= 0; i--) {
		for (int j = pos.y + 1; j < boardheight; j++) {
			if (findTheNode(arr, j, i) != NULL) {
				pos.x = i;
				pos.y = j;
				return;
			}
		}
	}

	for (int i = pos.x; i < boardwidth; i++) {
		for (int j = 0; j < pos.y; j++) {
			if (findTheNode(arr, j, i) != NULL) {
				pos.x = i;
				pos.y = j;
				return;
			}
		}
	}

	for (int i = pos.x - 1; i >= 0; i--) {
		for (int j = 0; j < pos.y; j++) {
			if (findTheNode(arr, j, i) != NULL) {
				pos.x = i;
				pos.y = j;
				return;
			}
		}
	}
}


/*
	Di chuyen con tro dang chon o sang trai bang danh sach lien ket
*/
void MoveLeft(BOX2** arr, toaDo& pos) {
	for (int i = pos.y; i >= 0; i--) {
		for (int j = pos.x - 1; j >= 0; j--) {
			if (findTheNode(arr, i, j) != NULL) {
				pos.x = j;
				pos.y = i;
				return;
			}
		}
	}

	for (int i = pos.y + 1; i < boardheight; i++) {
		for (int j = pos.x - 1; j >= 0; j--) {
			if (findTheNode(arr, i, j) != NULL) {
				pos.x = j;
				pos.y = i;
				return;
			}
		}
	}

	for (int i = pos.y; i >= 0; i--) {
		for (int j = boardwidth - 1; j > pos.x; j--) {
			if (findTheNode(arr, i, j) != NULL) {
				pos.x = j;
				pos.y = i;
				return;
			}
		}
	}

	for (int i = pos.y + 1; i < boardheight; i++) {
		for (int j = boardwidth - 1; j > pos.x; j--) {
			if (findTheNode(arr, i, j) != NULL) {
				pos.x = j;
				pos.y = i;
				return;
			}
		}
	}
}


/*
	Di chuyen con tro dang chon o sang phai bang danh sach lien ket
*/
void MoveRight(BOX2** arr, toaDo& pos) {
	for (int i = pos.y; i >= 0; i--) {
		for (int j = pos.x + 1; j < boardwidth; j++) {
			if (findTheNode(arr, i, j) != NULL) {
				pos.x = j;
				pos.y = i;
				return;
			}
		}
	}

	for (int i = pos.y + 1; i < boardheight; i++) {
		for (int j = pos.x + 1; j < boardwidth; j++) {
			if (findTheNode(arr, i, j) != NULL) {
				pos.x = j;
				pos.y = i;
				return;
			}
		}
	}

	for (int i = pos.y; i >= 0; i--) {
		for (int j = 0; j < pos.x; j++) {
			if (findTheNode(arr, i, j) != NULL) {
				pos.x = j;
				pos.y = i;
				return;
			}
		}
	}

	for (int i = pos.y + 1; i < boardheight; i++) {
		for (int j = 0; j < pos.x; j++) {
			if (findTheNode(arr, i, j) != NULL) {
				pos.x = j;
				pos.y = i;
				return;
			}
		}
	}
}


/*
	Di chuyen con tro dang chon o len tren sang ben phai sang ben trai hoac xuong duoi bang danh sach lien ket
*/
void move(BOX2** arr, toaDo& pos, int& status, Player& p, toaDo selectedPos[], int& couple) {
	int temp, key;
	temp = _getch();
	if (temp && temp != 224 && temp != Phimw && temp != Phims && temp != Phima && temp != Phimd) { // neu ko phai la dau mui ten
		if (temp == PhimEsc) { // neu la ESC
			status = 2;
		}
		else if (temp == PhimEnter || temp == PhimCach) { // neu la Enter
			if (pos.x == selectedPos[0].x && pos.y == selectedPos[0].y) {
				BOX2* temp = findTheNode(arr, pos.y, pos.x);
				temp->drawBox(70);
				Sleep(500);

				temp->isSelected = 0;
				couple = 2;
				selectedPos[0] = { -1, -1 };
				p.life--;
				gotoxy(100, 18);
				cout << "Life: " << p.life;
			} // kiem tra lap lai
			else {
				selectedPos[2 - couple].x = pos.x;
				selectedPos[2 - couple].y = pos.y;
				findTheNode(arr, pos.y, pos.x)->isSelected = 1;
				couple--;

				if (couple == 0) { // neu da chon 1 cap
					BOX2* p1, * p2;
					p1 = findTheNode(arr, selectedPos[0].y, selectedPos[0].x);
					p2 = findTheNode(arr, selectedPos[1].y, selectedPos[1].x);
					if (p1->c == p2->c) {  // neu cap nay hop nhau
						if (allCheck(arr, selectedPos[0].y, selectedPos[0].x, selectedPos[1].y, selectedPos[1].x)) {
							p.point += 20;
							gotoxy(100, 13);
							cout << "Point: " << p.point;

							p1->drawBox(40);
							p2->drawBox(40);
							Sleep(500);

							DifMode(arr, selectedPos[0].y, selectedPos[0].x, selectedPos[1].y, selectedPos[1].x, BG);
						}
						else {
							p1->drawBox(70);
							p2->drawBox(70);
							Sleep(500);

							p.life--;
							gotoxy(100, 17);
							cout << "Life: " << p.life;
						}
					}
					else {
						p1->drawBox(70);
						p2->drawBox(70);
						Sleep(500);

						p.life--;
						gotoxy(100, 17);
						cout << "Life: " << p.life;
					}
					// tra ve noi san xuat
					p1->isSelected = 0;
					p2->isSelected = 0;
					couple = 2;
					selectedPos[0] = { -1, -1 };
					selectedPos[1] = { -1, -1 };

					for (int i = pos.y; i < boardheight; i++) {
						for (int j = pos.x; j < boardheight; j++) {
							if (findTheNode(arr, i, j) != NULL) {
								pos.x = j;
								pos.y = i;
								return;
							}
						}
					}

					for (int i = 0; i <= pos.y; i++) { // chuyen den CELL_1 o tren
						for (int j = 0; j <= pos.x; j++) {
							if (findTheNode(arr, i, j) != NULL) {
								pos.x = j;
								pos.y = i;
								return;
							}
						}
					}
				}
			}
		}
	}
	else
	{
		if ((pos.y != selectedPos[0].y || pos.x != selectedPos[0].x) && (pos.y != selectedPos[1].y || pos.x != selectedPos[1].x)) // ktra xem o nay co dang duoc chon hay khong
			findTheNode(arr, pos.y, pos.x)->isSelected = 0;
		if (temp == 224) {
			key = _getch();
			switch (key) {
			case PhimLen:
				MoveUp(arr, pos);
				break;
			case PhimXuong:
				MoveDown(arr, pos);
				break;
			case PhimTrai:
				MoveLeft(arr, pos);
				break;
			case PhimPhai:
				MoveRight(arr, pos);
				break;
			default:
				break;
			}
		}
		switch (temp)
		{
		case Phimw:
			MoveUp(arr, pos);
			break;
		case Phims:
			MoveDown(arr, pos);
			break;
		case Phima:
			MoveLeft(arr, pos);
			break;
		case Phimd:
			MoveRight(arr, pos);
			break;
		default:
			break;
		}
	}
}


/*
	ham tong hop, khoi chay game che do kho
*/
void difficultMode(Player& p) {
	srand(time(0));
	getBackGround(BG);

	BOX2** board = new BOX2 * [boardheight];
	initList(board);

	createInfoBoard();
	gotoxy(97, 6);
	setColor(10);
	cout << "PIKACHU";
	setColor(12);
	cout << " GAME";
	setColor(1);
	cout << " PROJECT";
	setColor(4);
	gotoxy(97, 7);
	cout << "HARDCORE MODE";
	setColor(7);
	gotoxy(100, 9);
	cout << "Name: " << p.name;
	gotoxy(100, 13);
	cout << "Point: " << p.point;
	gotoxy(100, 17);
	cout << "Life: " << p.life;

	toaDo selectedPos[] = { {-1, -1}, {-1, -1} };
	int couple = 2;
	toaDo curPosition{ 0, 0 };
	int status = 0; 
	//0. dang choi game
	//1. het game
	//2. nguoi choi chon thoat

	while (!status && p.life) {
		findTheNode(board, curPosition.y, curPosition.x)->isSelected = 1;

		renderList(board);

		move(board, curPosition, status, p, selectedPos, couple);

		if ((!checkValidPairs(board))) status = 1;
	}

	renderList(board);
	deleteList(board);
	Sleep(500);
	system("cls");

	if (p.life && status == 1) {
		displayStatus(1);
		gotoxy(50, 17);
		char c;
		cout << "Do you want to continue next game? (Y/N): ";
		cin >> c;
		cin.ignore();
		system("cls");
		if (c == 'y' || c == 'Y') difficultMode(p);
		else writeLeaderBoard(p);
	}
	else if (p.life == 0) {
		displayStatus(0);
		writeLeaderBoard(p);
		Sleep(5000);
	}
	system("cls");
}
