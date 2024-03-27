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

struct toaDo {
	int x;
	int y;
};

struct Player {
	string name;
	int point;
	int life;
};

void setColor(int n);

struct BOX1 {
	int i, j;
	char c = ' ';
	bool isValid = 1, isSelected = 0;

	void drawBox(int);
	void deleteBox();
};

#endif