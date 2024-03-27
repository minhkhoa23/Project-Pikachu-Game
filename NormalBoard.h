#pragma once
#include <time.h>
#include <cstdlib>
#include <Windows.h>
#include <conio.h>
#include "BackGround.h"
#include "ConsoleSettings.h"
#include "Box.h"
#include "CheckNormal.h"

void initBoard(BOX1** board);
void deleteBoard(BOX1** board);
void renderBoard(BOX1** board);
void move(BOX1** board, toaDo& pos, int& status, Player& p, toaDo selectedPos[], int& couple);
void normalMode(Player& p);
