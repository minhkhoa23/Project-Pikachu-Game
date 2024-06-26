#include "NormalBoard.h"
#include "CheckNormal.h"
#include "LeaderBoard.h"
#include <iostream>
using namespace std;

char background[20][41];


/*
	Khoi tao bang man choi bang mang con tro 2 chieu
*/
void initBoard(BOX1** board) {
	for (int i = 0; i < boardheight; i++) {
		board[i] = new BOX1[boardwidth];
		for (int j = 0; j < boardwidth; j++) {
			board[i][j].j = j;
			board[i][j].i = i;
		}
	}

	int flagnum = (boardwidth * boardheight) / 2;
	while (flagnum != 0) {
		int index;
		int time = 2;
		char c = 65 + rand() % 26;
		while (time) {
			index = rand() % 40;
			if (board[index / 8][index % 8].c == ' ') {
				board[index / 8][index % 8].c = c;
				time--;
			}
		}
		flagnum--;
	}
}


/*
	Xoa bang man choi bang mang con tro 2 chieu
*/
void deleteBoard(BOX1** board) {
	for (int i = 0; i < boardheight; i++) {
		for (int j = 0; j < boardwidth; j++) {
			if (board[i][j].isValid) {
				board[i][j].deleteBox();
				if (j < 4) {
					displayBackground(background, j, i);
					Sleep(300);
				}
			}
		}
	}
	for (int i = 0; i < boardheight; i++) {
		delete[] board[i];
	}
	delete [] board;
}


/*
	Xuat bang man choi len con so man choi bang con tro 2 chieu
*/
void renderBoard(BOX1** board) {
	for (int i = 0; i < boardheight; i++) {
		for (int j = 0; j < boardwidth; j++) {
			board[i][j].drawBox(112);
		}
	}
}


/*
	Di chuyen con tro len tren trong bang man choi bang con tro 2 chieu
*/
void MoveUp(BOX1** board, toaDo& pos) {
	for (int i = pos.x; i < boardwidth; i++) {
		for (int j = pos.y - 1; j >= 0; j--) {
			if (board[j][i].isValid) {
				pos.x = i;
				pos.y = j;
				return;
			}
		}
	}

	for (int i = pos.x - 1; i >= 0; i--) {
		for (int j = pos.y - 1; j >= 0; j--) {
			if (board[j][i].isValid) {
				pos.x = i;
				pos.y = j;
				return;
			}
		}
	}

	for (int i = pos.x; i < boardwidth; i++) {
		for (int j = boardheight - 1; j > pos.y; j--) {
			if (board[j][i].isValid) {
				pos.x = i;
				pos.y = j;
				return;
			}
		}
	}

	for (int i = pos.x; i >= 0; i--) {
		for (int j = boardheight - 1; j > pos.y; j--) {
			if (board[j][i].isValid) {
				pos.x = i;
				pos.y = j;
				return;
			}
		}
	}
}


/*
	Di chuyen con tro xuong duoi trong bang man choi bang con tro 2 chieu
*/
void MoveDown(BOX1** board, toaDo& pos) {
	for (int i = pos.x; i < boardwidth; i++) {
		for (int j = pos.y + 1; j < boardheight; j++) {
			if (board[j][i].isValid) {
				pos.x = i;
				pos.y = j;
				return;
			}
		}
	}

	for (int i = pos.x - 1; i >= 0; i--) {
		for (int j = pos.y + 1; j < boardheight; j++) {
			if (board[j][i].isValid) {
				pos.x = i;
				pos.y = j;
				return;
			}
		}
	}

	for (int i = pos.x; i < boardwidth; i++) {
		for (int j = 0; j < pos.y; j++) {
			if (board[j][i].isValid) {
				pos.x = i;
				pos.y = j;
				return;
			}
		}
	}

	for (int i = pos.x - 1; i >= 0; i--) {
		for (int j = 0; j < pos.y; j++) {
			if (board[j][i].isValid) {
				pos.x = i;
				pos.y = j;
				return;
			}
		}
	}
}


/*
	Di chuyen con tro sang trai trong bang man choi bang con tro 2 chieu
*/
void MoveLeft(BOX1** board, toaDo& pos) {
	for (int i = pos.y; i >= 0; i--) {
		for (int j = pos.x - 1; j >= 0; j--) {
			if (board[i][j].isValid) {
				pos.x = j;
				pos.y = i;
				return;
			}
		}
	}

	for (int i = pos.y + 1; i < boardheight; i++) {
		for (int j = pos.x - 1; j >= 0; j--) {
			if (board[i][j].isValid) {
				pos.x = j;
				pos.y = i;
				return;
			}
		}
	}

	for (int i = pos.y; i >= 0; i--) {
		for (int j = boardwidth - 1; j > pos.x; j--) {
			if (board[i][j].isValid) {
				pos.x = j;
				pos.y = i;
				return;
			}
		}
	}

	for (int i = pos.y + 1; i < boardheight; i++) {
		for (int j = boardwidth - 1; j > pos.x; j--) {
			if (board[i][j].isValid) {
				pos.x = j;
				pos.y = i;
				return;
			}
		}
	}
}


/*
	Di chuyen tro sang phai trong bang man choi bang con tro 2 chieu
*/
void MoveRight(BOX1** board, toaDo& pos) {
	for (int i = pos.y; i >= 0; i--) {
		for (int j = pos.x + 1; j < boardwidth; j++) {
			if (board[i][j].isValid) {
				pos.x = j;
				pos.y = i;
				return;
			}
		}
	}

	for (int i = pos.y + 1; i < boardheight; i++) {
		for (int j = pos.x + 1; j < boardwidth; j++) {
			if (board[i][j].isValid) {
				pos.x = j;
				pos.y = i;
				return;
			}
		}
	}

	for (int i = pos.y; i >= 0; i--) {
		for (int j = 0; j < pos.x; j++) {
			if (board[i][j].isValid) {
				pos.x = j;
				pos.y = i;
				return;
			}
		}
	}

	for (int i = pos.y + 1; i < boardheight; i++) {
		for (int j = 0; j < pos.x; j++) {
			if (board[i][j].isValid) {
				pos.x = j;
				pos.y = i;
				return;
			}
		}
	}
}


/*
	Goi y nuoc di tiep theo cho nguoi choi bang cach xac dinh mot cap o phu hop va dam bao co duong di hop le
*/
void moveSuggestion(BOX1** map, toaDo guidePos[])
{
	for (int i = 1; i < boardheight - 1; i++)
	{
		for (int j = 1; j < boardwidth - 1; j++)
		{
			if (!map[i][j].isValid)
				continue;

			for (int k = 1; k < boardheight - 1; k++)
			{
				for (int l = 1; l < boardwidth - 1; l++)
				{
					if (i == k && l == j)
						continue;
					if (map[k][l].isValid == false)
						continue;
					if (map[i][j].c == map[k][l].c)
					{
						if (allcheck(map, i, j, k, l) == true)
						{
							guidePos[0].x = j;
							guidePos[0].y = i;
							guidePos[1].x = l;
							guidePos[1].y = k;
							return;
						}
					}
				}
			}
		}
	}
}


/*
	Di chuyen con tro trong bang man choi bang con tro 2 chieu
*/
void move(BOX1** board, toaDo& pos, int& status, Player& p, toaDo selectedPos[], int& couple) {
	int temp, key;
	temp = _getch();
	if (temp == Phimh) {
		if (p.hint == 0) {
			return;
		}
		toaDo guidePos[2] = { {0,0},{0,0} };
		moveSuggestion(board, guidePos);

		board[guidePos[0].y][guidePos[0].x].isSelected = 1;
		board[guidePos[1].y][guidePos[1].x].isSelected = 1;

		board[guidePos[0].y][guidePos[0].x].drawBox(100);
		board[guidePos[1].y][guidePos[1].x].drawBox(100);

		Sleep(500);

		board[guidePos[0].y][guidePos[0].x].isSelected = 0;
		board[guidePos[1].y][guidePos[1].x].isSelected = 0;

		//renderBoard(map, height, width);

		p.hint--;
		p.point -= 5;
		gotoxy(100, 13);
		cout << "           ";
		gotoxy(100, 13);
		cout << "Point: " << p.point;
		gotoxy(100, 21);
		cout << "Hint left: " << p.hint;
	}
	if (temp != 0 && temp != 224 && temp != Phima && temp != Phimd && temp != Phimw && temp != Phims) {
		if (temp == PhimEsc) {
			status = 2;
		}
		else if (temp == PhimEnter || temp == PhimCach) {
			if (pos.x == selectedPos[0].x && pos.y == selectedPos[0].y) {
				board[selectedPos[0].y][selectedPos[0].x].drawBox(74); // chon sai nen o hien mau do
				Sleep(500); //hien o mau do trong 0,5s

				board[selectedPos[0].y][selectedPos[0].x].isSelected = 0;
				couple = 2;
				selectedPos[0] = { -1,-1 };
				p.life--; // tru 1 mang khi sai
				cout << "Life: " << p.life;
			} // chon 2 cap trung 1 o
			else {
				selectedPos[2 - couple].x = pos.x;
				selectedPos[2 - couple].y = pos.y;
				board[pos.y][pos.x].isSelected = 1;
				couple--;
				if (couple == 0) {
					if (board[selectedPos[0].y][selectedPos[0].x].c == board[selectedPos[1].y][selectedPos[1].x].c) {
						if (allcheck(board, selectedPos[0].y, selectedPos[0].x, selectedPos[1].y, selectedPos[1].x)) {
							p.point += 20;
							gotoxy(100, 13);
							cout << "Point: " << p.point;

							board[selectedPos[0].y][selectedPos[0].x].drawBox(40);
							board[selectedPos[1].y][selectedPos[1].x].drawBox(40);
							Sleep(500);

							board[selectedPos[0].y][selectedPos[0].x].isValid = 0;
							board[selectedPos[0].y][selectedPos[0].x].deleteBox();
							if (selectedPos[0].x < 4) {
								displayBackground(background, selectedPos[0].x, selectedPos[0].y);
							}

							board[selectedPos[1].y][selectedPos[1].x].isValid = 0;
							board[selectedPos[1].y][selectedPos[1].x].deleteBox();
							if (selectedPos[1].x < 4) {
								displayBackground(background, selectedPos[1].x, selectedPos[1].y);
							}
						}
						else {
							board[selectedPos[0].y][selectedPos[0].x].drawBox(70);
							board[selectedPos[1].y][selectedPos[1].x].drawBox(70);
							Sleep(500);

							p.life--;
							gotoxy(100, 17);
							cout << "Life: " << p.life;
						}
					}
					else {
						board[selectedPos[0].y][selectedPos[0].x].drawBox(70);
						board[selectedPos[1].y][selectedPos[1].x].drawBox(70);
						Sleep(500);

						p.life--;
						gotoxy(100, 17);
						cout << "Life: " << p.life;
					}

					board[selectedPos[0].y][selectedPos[0].x].isSelected = 0;
					board[selectedPos[1].y][selectedPos[1].x].isSelected = 0;
					couple = 2;
					selectedPos[0] = { -1,-1 };
					selectedPos[1] = { -1,-1 };

					for (int i = pos.y; i < boardheight; i++) {
						for (int j = pos.x; j < boardwidth; j++) {
							if (board[i][j].isValid) {
								pos.x = j;
								pos.y = i;
								return;
							}
						}
					}

					for (int i = 0; i <= pos.y; i++) {
						for (int j = 0; j <= pos.x; j++) {
							if (board[i][j].isValid) {
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
	else {
		if ((pos.y != selectedPos[0].y || pos.x != selectedPos[0].x) && (pos.y != selectedPos[1].y || pos.x != selectedPos[1].x)) {
			board[pos.y][pos.x].isSelected = 0;
		}
		if (temp == Phimw || temp == Phima || temp == Phims || temp == Phimd) {
			int wasd = temp;
			switch (wasd) {
			case Phimw:
				MoveUp(board, pos);
				break;
			case Phims:
				MoveDown(board, pos);
				break;
			case Phima:
				MoveLeft(board, pos);
				break;
			case Phimd:
				MoveRight(board, pos);
				break;
			default:
				break;
			}
		}
		if (temp == 224) {
			key = _getch();
			switch (key) {
			case PhimLen:
				MoveUp(board, pos);
				break;
			case PhimXuong:
				MoveDown(board, pos);
				break;
			case PhimTrai:
				MoveLeft(board, pos);
				break;
			case PhimPhai:
				MoveRight(board, pos);
				break;
			default:
				break;
			}
		}
	}
	}


/*
	Kiem soat luong tro choi o che do binh thuong khoi tao tro choi, xu ly hanh ?ong cua nguoi choi, trang thai tro choi quan ly tro choi theo cac kich ban.
*/
void normalMode(Player& p) {
	srand(time(NULL));
	getBackGround(background);

	BOX1** board = new BOX1 * [boardheight];
	initBoard(board);

	createInfoBoard();
	gotoxy(97, 6);
	setColor(10);
	cout << "PIKACHU";
	setColor(4);
	cout << " GAME";
	setColor(1);
	cout << " PROJECT";
	setColor(7);
	gotoxy(100, 9);
	cout << "Name: " << p.name;
	gotoxy(100, 13);
	cout << "Point: " << p.point;
	gotoxy(100, 17);
	cout << "Life: " << p.life;
	gotoxy(100, 21);
	cout << "Hint left: " << p.hint;

	toaDo selectedPos[] = { {-1,-1},{-1,-1} };
	int couple = 2;
	toaDo curPosition{ 0,0 };
	int status = 0;
	//0. dang choi game
    //1. het game
    //2. nguoi choi chon thoat

	while (!status && p.life) {
		board[curPosition.y][curPosition.x].isSelected = 1;

		renderBoard(board);

		move(board, curPosition, status, p, selectedPos, couple);

		if ((!checkValidPairs(board))) {
			status = 1;
		}
	}

	renderBoard(board);
	deleteBoard(board);
	Sleep(500);
	system("cls");

	if (p.life && status == 1) {
		displayStatus(1);
		gotoxy(40, 17);
		char c;
		cout << "Do you want to continue next game? (Y/N): ";
		cin >> c;
		cin.ignore();
		system("cls");
		if (c == 'y' || c == 'Y') normalMode(p);
		else writeLeaderBoard(p);
	}
	else if (p.life == 0) {
		displayStatus(0);
		writeLeaderBoard(p);
		Sleep(5000);
	}
	system("cls");
}
