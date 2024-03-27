#include "NormalBoard.h"
#include <iostream>
using namespace std;

char background[20][41];

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

void renderBoard(BOX1** board) {
	for (int i = 0; i < boardheight; i++) {
		for (int j = 0; j < boardwidth; j++) {
			board[i][j].drawBox(112);
		}
	}
}

void move(BOX1** board, toaDo& pos, int& status, Player& p, toaDo selectedPos[], int& couple) {
	int temp, key;
	temp = _getch();
	if (temp != 0 && temp != 224) {
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
							gotoxy(40, 0);
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
							gotoxy(70, 0);
							cout << "Life: " << p.life;
						}
					}
					else {
						board[selectedPos[0].y][selectedPos[0].x].drawBox(70);
						board[selectedPos[1].y][selectedPos[1].x].drawBox(70);
						Sleep(500);

						p.life--;
						gotoxy(70, 0);
						cout << "life: " << p.life;
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
		switch (key = _getch()) {
		case PhimLen:
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

			break;
		case PhimXuong:
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
			break;
		case PhimTrai:
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
			break;
		case PhimPhai:
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
		default:
			break;
		}
	}
}

void normalMode(Player& p) {
	srand(time(NULL));
	
	BOX1** board = new BOX1 * [boardheight];
	initBoard(board);

	gotoxy(10, 0);
	cout << "Name: " << p.name;
	gotoxy(40, 0);
	cout << "Point: " << p.point;
	gotoxy(70, 0);
	cout << "Life: " << p.life;

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
		gotoxy(50, 17);
		char c;
		cout << "Do you want to continue next game? (Y/N): ";
		cin >> c;
		cin.ignore();
		system("cls");
		if (c == 'y' || c == 'Y') normalMode(p);
		//
	}
	else if (p.life == 0) {
		displayStatus(0);
		//
		Sleep(5000);
	}
	system("cls");
}