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


/*
	Khoi tao bang man choi bang mang con tro 2 chieu
*/
void initBoard(BOX1** board);


/*
	Xoa bang man choi bang mang con tro 2 chieu
*/
void deleteBoard(BOX1** board);


/*
	Xuat bang man choi len con so man choi bang con tro 2 chieu
*/
void renderBoard(BOX1** board);


/*
	Di chuyen con tro len tren trong bang man choi bang con tro 2 chieu
*/
void MoveUp(BOX1** board, toaDo& pos);


/*
	Di chuyen con tro xuong duoi trong bang man choi bang con tro 2 chieu
*/
void MoveDown(BOX1** board, toaDo& pos);


/*
	Di chuyen con tro sang trai trong bang man choi bang con tro 2 chieu
*/
void MoveLeft(BOX1** board, toaDo& pos);


/*
	Di chuyen tro sang phai trong bang man choi bang con tro 2 chieu
*/
void MoveRight(BOX1** board, toaDo& pos);


/*
	Di chuyen con tro trong bang man choi bang con tro 2 chieu
*/
void move(BOX1** board, toaDo& pos, int& status, Player& p, toaDo selectedPos[], int& couple);


/*
	Kiem soat luong tro choi o che do binh thuong khoi tao tro choi, xu ly hanh ?ong cua nguoi choi, trang thai tro choi quan ly tro choi theo cac kich ban
*/
void normalMode(Player& p);


/*
	Goi y nuoc di tiep theo cho nguoi choi bang cach xac dinh mot cap o phu hop va dam bao co duong di hop le
*/
void moveSuggestion(BOX1** map, toaDo guidePos[]);