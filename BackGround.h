#pragma once
#include "ConsoleSettings.h"
#include "Box.h"
#include <conio.h>

void displayStatus(bool win);

/*
	Sau khi hoan thanh luot choi cua nguoi choi 
	Neu nguoi choi chien thang:
		+ Xuat ra man hinh dong chu "You Win"
	Neu nguoi choi thua :
		+ Xuat ra man hinh dong chu "You Lose"
*/

void displayBackground(char background[][41], int x, int y);

void getBackGround(char background[][41]);

void getPlayerInfo(Player& p);

void createInfoBoard();

int MainMenu();

void Tutorial();