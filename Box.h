#pragma once
#ifndef _STRUCT_H_
#define _STRUCT_H_
#include <string>
using namespace std;

#define boardwidth 8
#define boardheight 5

#define PhimEnter 13
#define PhimEsc 27
#define PhimLen 72
#define PhimXuong 80
#define PhimPhai 77
#define PhimTrai 75
#define PhimCach 32
#define Phimw 119
#define Phima 97
#define Phims 115
#define Phimd 100
#define Phimh 104


/*
	Toa do tren cua so man hinh
*/
struct toaDo {
	int x;
	int y;
};


/*
	Thong tin cua nguoi choi
*/
struct Player {
	string name;
	int point;
	int life;
	int hint;
};


/*
	Thuc hien thay doi mau ky tu tren man hinh cua so 
	Tham so n dai dien cho mot mau van ban mong muon
*/
void setColor(int n);


/*
	Cau truc cua mot o o man choi o che do binh thuong
	Trong do 
		+ Ham thuc hien ve o tren man hinh cua so
		+ Ham thuc hien xoa o sau khi chon dung tren man hinh cua so
*/
struct BOX1 {
	int i, j;
	char c = ' ';
	bool isValid = 1, isSelected = 0;

	void drawBox(int);
	void deleteBox();
};


/*
Cau truc cua mot o o man choi o che do kho
	Trong do 
		+ Ham thuc hien ve o tren man hinh cua so
		+ Ham thuc hien xoa o sau khi chon dung tren man hinh cua so
*/
struct BOX2 {
    int i, j;
    char c = ' ';
    bool isSelected = 0;
    BOX2* next;
    void drawBox(int);
    void deleteBox();
};

#endif