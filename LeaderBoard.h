#pragma once
#include "BackGround.h"
#include <fstream>
#include <iostream>
#include<conio.h>
#include "Box.h"

/* 
	doc file danh sach nguoi choi dat diem cao tu file "LeaderBoard.txt"
*/
void readLeaderBoard();


/*
	xuat ra file danh sach nguoi choi dat diem cao ra file "LeaderBoard.txt"
*/
void writeLeaderBoard(Player p);