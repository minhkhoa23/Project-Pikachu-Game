#pragma once
#include "Box.h"

bool nextcheck(BOX1** board, int p1, int p2, int q1, int q2);

bool linecheck(BOX1** board, int p1, int p2, int q1, int q2);

bool IcheckNormal(BOX1** board, int p1, int p2, int q1, int q2);

bool LcheckNormal(BOX1** board, int p1, int p2, int q1, int q2);

bool ZcheckNormal(BOX1** board, int p1, int p2, int q1, int q2);

bool UcheckNormal(BOX1** board, int p1, int p2, int q1, int q2);

bool allcheck(BOX1** board, int p1, int p2, int q1, int q2);

bool checkValidPairs(BOX1** board);