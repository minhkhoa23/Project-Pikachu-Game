#pragma once
#ifndef _CHECK2_H_
#define _CHECK2_H_

#include "Box.h"
#include "Background.h"
/* Che do kho duoc thuc hien duoi danh sach lien ket*/


/*
	Tim mot o y, x tren mang con danh sach lien ket cua che do kho
*/
BOX2* findTheNode(BOX2**, int, int);


/*
	O thu nhat co toa do y1, x1
	O thu hai co toa do y2, x2
	Kiem tra xem 2 o co the duoc noi voi nhau qua hinh chu I hay khong?
*/
bool Icheck(BOX2**, int, int, int, int);


/*
	O thu nhat co toa do y1, x1
	O thu hai co toa do y2, x2
	Kiem tra xem 2 o co the duoc noi voi nhau qua hinh chu L hay khong?
*/
bool Lcheck(BOX2**, int, int, int, int);


/*
	O thu nhat co toa do y1, x1
	O thu hai co toa do y2, x2
	Kiem tra xem 2 o co the duoc noi voi nhau qua hinh chu U hay Z hay khong?
*/
bool UandZcheck(BOX2**, int, int, int, int);


/*
	O thu nhat co toa do y1, x1
	O thu hai co toa do y2, x2
	Kiem tra xem 2 o co the duoc noi voi nhau qua hinh chu I hay L hay U hay Z hay khong?
*/
bool allCheck(BOX2**, int, int, int, int);


/*
	Thuc hien xoa mot o tren danh sach lien ket cac o o che do kho
	O duoc xoa co toa do y, x tren bang cua man choi
*/
void deleteNode(BOX2**, int, int, char[][41]);


/*
	Thuc hien xoa hai o tren danh sach lien ket co toa do lan luot la y1, x1 va y2, x2 cua bang tren man choi
*/
void DifMode(BOX2**, int, int, int, int, char[][41]);


/*
	Kiem tra xem co 2 nut nao trong bang co the noi voi nhau bang hinh I hay L hay U hay Z hay khong?
*/
bool checkValidPairs(BOX2**);

#endif