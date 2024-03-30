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

struct toaDo {
	int x;
	int y;
};

struct Player {
	string name;
	int point;
	int life;
	int hint;
};

void setColor(int n);

struct BOX1 {
	int i, j;
	char c = ' ';
	bool isValid = 1, isSelected = 0;

	void drawBox(int);
	void deleteBox();
};
struct BOX2 {
    int i, j;
    char c = ' ';
    bool isSelected = 0;
    BOX2* next;
    void drawBox(int);
    void deleteBox();
};
#endif