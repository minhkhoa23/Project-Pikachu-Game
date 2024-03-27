#include "Box.h"
#include "ConsoleSettings.h"
#include "iostream"
using namespace std;

char box[5][12] = {
	{" --------- "},
	{"|         |"},
	{"|         |"},
	{"|         |"},
	{" --------- "},
};

void setColor(int n) {
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, n);
}

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


void BOX1::deleteBox() {
	int x = j + 1, y = i + 1;
	for (int i = 0; i < 5; i++) {
		gotoxy(x * 10, y * 4 + i);
		cout << "           ";
	}
}
