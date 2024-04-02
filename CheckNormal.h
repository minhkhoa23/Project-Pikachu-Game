#pragma once
#include "Box.h"
/* Che do binh thuong duoc thuc hien duoi mang con tro 2 chieu */


/* 
	O thu nhat co toa do p1, p2
	O thu hai co toa do q1, q2
	Kiem tra xem 2 o co thao dieu kien ke nhau hay khong
*/
bool nextcheck(BOX1** board, int p1, int p2, int q1, int q2);


/*
	O thu nhat co toa do p1, p2
	O thu hai co toa do q1, q2
	Kiem tra xem giua 2 o theo cot hay theo dong khong co o nam nam giua 
*/
bool linecheck(BOX1** board, int p1, int p2, int q1, int q2);


/*
	O thu nhat co toa do p1, p2
	O thu hai co toa do q1, q2
	Kiem tra xem giua 2 o co the noi voi nhau theo hinh chu I khong
*/
bool IcheckNormal(BOX1** board, int p1, int p2, int q1, int q2);


/*
	O thu nhat co toa do p1, p2
	O thu hai co toa do q1, q2
	Kiem tra xem giua 2 o co the noi voi nhau theo hinh chu L khong
*/
bool LcheckNormal(BOX1** board, int p1, int p2, int q1, int q2) ;


/*
	O thu nhat co toa do p1, p2
	O thu hai co toa do q1, q2
	Kiem tra xem giua 2 o co the noi voi nhau theo hinh chu Z khong
*/
bool ZcheckNormal(BOX1** board, int p1, int p2, int q1, int q2);


/*
	O thu nhat co toa do p1, p2
	O thu hai co toa do q1, q2
	Kiem tra xem giua 2 o co the noi voi nhau theo hinh chu U khong
*/
bool UcheckNormal(BOX1** board, int p1, int p2, int q1, int q2);


/*
	O thu nhat co toa do p1, p2
	O thu hai co toa do q1, q2
	Kiem tra xem giua 2 o co the noi voi nhau theo hinh chu I hay L hay U hay Z khong
*/
bool allcheck(BOX1** board, int p1, int p2, int q1, int q2);


/*
	Kiem tra xem co 2 nut nao trong bang co the noi voi nhau bang hinh I hay L hay U hay Z hay khong?
*/
bool checkValidPairs(BOX1** board);