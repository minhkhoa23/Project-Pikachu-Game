#pragma once
#include "Box.h"
#include<conio.h>
#include<time.h>
#include "ConsoleSettings.h"
#include "BackGround.h"
#include "checkDifficult.h"
#include "LeaderBoard.h"


/*
	Them mot nut moi cho duoi danh sach lien ket
*/
void push(BOX2*&, BOX2*);


/*
	Khoi tao danh sach lien ket 2 chieu 
*/
void initList(BOX2**);


/*
	Xoa toan bo danh sach lien ket 2 chieu
*/
void deleteList(BOX2**);


/*
	Ve o trong danh sach lien ket 2 chieu
*/
void renderList(BOX2**);


/*
	Di chuyen con tro dang chon o len tren sang ben phai sang ben trai hoac xuong duoi
*/
void move(BOX2**, toaDo&, int&, Player&, toaDo[], int&);


/*
	ham tong hop, khoi chay game che do kho
*/
void difficultMode(Player&);