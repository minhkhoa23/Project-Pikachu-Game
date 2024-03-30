#pragma once
#ifndef _CHECK2_H_
#define _CHECK2_H_

#include "Box.h"
#include "Background.h"

BOX2* findTheNode(BOX2**, int, int);
bool Icheck(BOX2**, int, int, int, int);
bool Lcheck(BOX2**, int, int, int, int);
bool UandZcheck(BOX2**, int, int, int, int);
bool allCheck(BOX2**, int, int, int, int);
void deleteNode(BOX2**, int, int, char[][41]);
void DifMode(BOX2**, int, int, int, int, char[][41]);
bool checkValidPairs(BOX2**);

#endif