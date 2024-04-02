#pragma once
#include <time.h>
#include <cstdlib>
#include <Windows.h>
#include <conio.h>
#include "BackGround.h"
#include "ConsoleSettings.h"
#include "Box.h"
#include "CheckNormal.h"
#include "LeaderBoard.h"

void initBoard(BOX1** board);

void deleteBoard(BOX1** board);

void renderBoard(BOX1** board);

void MoveUp(BOX1** board, toaDo& pos);

void MoveDown(BOX1** board, toaDo& pos);

void MoveLeft(BOX1** board, toaDo& pos);

void MoveRight(BOX1** board, toaDo& pos);

void move(BOX1** board, toaDo& pos, int& status, Player& p, toaDo selectedPos[], int& couple);

void createInfoBoard();

void normalMode(Player& p);

void moveSuggestion(BOX1** map, toaDo guidePos[]);