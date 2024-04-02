#include "Box.h"
#include "ConsoleSettings.h"
#include "iostream"
using namespace std;


/*
    Mot o ben trong man choi
*/
char box[5][12] = {
	{" --------- "},
	{"|         |"},
	{"|         |"},
	{"|         |"},
	{" --------- "},
};


/*
    Thuc hien thay doi mau ky tu tren man hinh cua so
    Tham so n dai dien cho mot mau van ban mong muon
*/
void setColor(int n) {
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, n);
}


/*
    Thuc hien ve mot o trong man choi binh thuong
    Neu o duoc chon thi xuat ra man hinh nhung ky tu va mau sac duoc dinh san trong o
    Neu o khong duoc thi xuat ra man hinh nhung ky tu va mau sac duoc dinh san trong o
*/
void BOX1::drawBox(int color) {
	if (!isValid) {
		return;
	}
	int x = j + 1, y = i + 1;

	for (int i = 0; i < 5; i++) {
		gotoxy(x * 10, y * 4 + i);
		cout << box[i];
	}

	if (isSelected) {
		setColor(color + (c % 6 + 1)); // white background
		for (int i = 1; i < 4; i++) {
			gotoxy(x * 10 + 1, y * 4 + i);
			cout << "         ";
		}

		gotoxy(x * 10 + 5, y * 4 + 2);
		cout << c;
		setColor(7);
	}
	else {
		gotoxy(x * 10 + 5, y * 4 + 2);
		setColor(c % 6 + 1);
		cout << c;
		setColor(7);
	}
}


/*
    Thuc hien xoa mot o o che do binh thuong
*/
void BOX1::deleteBox() {
	int x = j + 1, y = i + 1;
	for (int i = 0; i < 5; i++) {
		gotoxy(x * 10, y * 4 + i);
		cout << "           ";
	}
}


/*
    Thuc hien ve mot o trong man choi kho
    Neu o duoc chon thi xuat ra man hinh nhung ky tu va mau sac duoc dinh san trong o
    Neu o khong duoc thi xuat ra man hinh nhung ky tu va mau sac duoc dinh san trong o
*/
void BOX2::drawBox(int color) {
	int x = j + 1, y = i + 1;

	for (int i = 0; i < 5; i++) {
		gotoxy(x * 10, y * 4 + i);
		cout << box[i];
	}

	if (isSelected) {
		setColor(color + (c % 6 + 1)); // white background
		for (int i = 1; i < 4; i++) {
			gotoxy(x * 10 + 1, y * 4 + i);
			cout << "         ";
		}

		gotoxy(x * 10 + 5, y * 4 + 2);
		cout << c;
		setColor(7);
	}
	else {
		gotoxy(x * 10 + 5, y * 4 + 2);
		setColor(c % 6 + 1);
		cout << c;
		setColor(7);
	}
}


/*
    Thuc hien xoa mot o o che do kho
*/
void BOX2::deleteBox() {
	int x = j + 1, y = i + 1;

	for (int i = 0; i < 5; i++) {
		gotoxy(x * 10, y * 4 + i);
		cout << "           ";
	}
}

