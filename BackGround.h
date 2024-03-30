#pragma once
#include "ConsoleSettings.h"
#include "Box.h"
#include <conio.h>

void displayStatus(bool win);
void displayBackground(char background[][41], int x, int y);
void getBackGround(char background[][41]);
void getPlayerInfo(Player& p);
void createInfoBoard();
int MainMenu();
void Tutorial();