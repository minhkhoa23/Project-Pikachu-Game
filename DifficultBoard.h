#pragma once
#include "Box.h"
#include<conio.h>
#include<time.h>
#include "ConsoleSettings.h"
#include "BackGround.h"
#include "checkDifficult.h"
#include "LeaderBoard.h"

void push(BOX2*&, BOX2*);
void initList(BOX2**);
void deleteList(BOX2**);
void renderList(BOX2**);
void move(BOX2**, toaDo&, int&, Player&, toaDo[], int&);
void difficultMode(Player&);