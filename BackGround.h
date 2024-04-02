#pragma once
#include "ConsoleSettings.h"
#include "Box.h"
#include <conio.h>


/*
	Sau khi hoan thanh luot choi cua nguoi choi 
	Neu nguoi choi chien thang:
		+ Xuat ra man hinh dong chu "You Win"
	Neu nguoi choi thua :
		+ Xuat ra man hinh dong chu "You Lose"
*/
void displayStatus(bool win);


/*
	Xuat ra man hinh hinh nen cua o co toa do con tro x, y tren man hinh cua so
*/
void displayBackground(char background[][41], int x, int y);


/*
	Xuat ra man hinh hinh nen duoc dau dang sau man choi 
	Hinh nen se dan xuat hien khi nguoi choi cang xoa duoc nhieu o
	Hinh nen an dang sau man choi duoc dua tren file text "BackGound.text" 
*/
void getBackGround(char background[][41]);


/*
	Nhap thong tin cua nguoi choi khi bat dau mot man choi
	Khoi tao cho nguoi choi:
		+ Luot choi
		+ Diem
		+ Luot goi y
*/
void getPlayerInfo(Player& p);


/*
	Tao ra hinh nen cho danh sach nguoi choi cung voi nhung thong tin di kem voi nguoi choi
*/
void createInfoBoard();


/*
	Khoi tao hinh nen cho danh sach lua chon cua nguoi choi khi moi bat dau game
	Nhung lua chon bao gom
		+ "hardcore mod"
		+ "normal code"
		+ "Leaderboard"
		+ "Exit"
*/
int MainMenu();


/*
	Xuat ra man hinh bang huong dan nguoi choi nhung thao tac co the thuc hien de choi tro choi
*/
void Tutorial();

