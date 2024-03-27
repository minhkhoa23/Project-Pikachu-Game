#include "BackGround.h"
#include "ConsoleSettings.h"
#include "Box.h"
#include <iostream>

void displayStatus(bool win) {
    if (win) {
        setColor(9);
        gotoxy(44, 10);
        cout << "                                           _ ";
        gotoxy(44, 11);
        cout << " _   _  ___  _   _  __      _____  _ __   | |";
        gotoxy(44, 12);
        cout << "| | | |/ _ \\| | | | \\ \\ /\\ / / _ \\| '_ \\  | |";
        gotoxy(44, 13);
        cout << "| |_| | (_) | |_| |  \\ V  V / (_) | | | | |_|";
        gotoxy(44, 14);
        cout << " \\__, |\\___/ \\__,_|   \\_/\\_/ \\___/|_| |_| (_)";
        gotoxy(44, 15);
        cout << " |___/                                       ";
        setColor(7);
    }
    else {
        setColor(12);
        gotoxy(44, 10);
        cout << "                     _                          __";
        gotoxy(44, 11);
        cout << " _   _  ___  _   _  | | ___  ___  ___    _____ / /";
        gotoxy(44, 12);
        cout << "| | | |/ _ \\| | | | | |/ _ \\/ __|/ _ \\  |_____| | ";
        gotoxy(44, 13);
        cout << "| |_| | (_) | |_| | | | (_) \\__ \\  __/   _____| | ";
        gotoxy(44, 14);
        cout << " \\__, |\\___/ \\__,_| |_|\\___/|___/\\___|  |_____| | ";
        gotoxy(44, 15);
        cout << " |___/                                         \\_\\ ";
        setColor(7);
    }
}

void displayBackground(char background[][41], int x, int y) {
	setColor(9);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 11; j++) {
			gotoxy((x + 1) * 10 + j, (y + 1) * 4 + i);
			cout << background[y * 4 + i][x * 10 + j];
		}
	}
	setColor(7);
}