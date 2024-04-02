#include "BackGround.h"
#include "ConsoleSettings.h"
#include "Box.h"
#include <fstream>
#include <iostream>

void displayStatus(bool win) {
    if (win) {
        setColor(9);
        gotoxy(40, 10);
        cout << "                                           _ ";
        gotoxy(40, 11);
        cout << " _   _  ___  _   _  __      _____  _ __   | |";
        gotoxy(40, 12);
        cout << "| | | |/ _ \\| | | | \\ \\ /\\ / / _ \\| '_ \\  | |";
        gotoxy(40, 13);
        cout << "| |_| | (_) | |_| |  \\ V  V / (_) | | | | |_|";
        gotoxy(40, 14);
        cout << " \\__, |\\___/ \\__,_|   \\_/\\_/ \\___/|_| |_| (_)";
        gotoxy(40, 15);
        cout << " |___/                                       ";
        setColor(7);
    }
    else {
        setColor(12);
        gotoxy(40, 10);
        cout << "                     _                          __";
        gotoxy(40, 11);
        cout << " _   _  ___  _   _  | | ___  ___  ___    _____ / /";
        gotoxy(40, 12);
        cout << "| | | |/ _ \\| | | | | |/ _ \\/ __|/ _ \\  |_____| | ";
        gotoxy(40, 13);
        cout << "| |_| | (_) | |_| | | | (_) \\__ \\  __/   _____| | ";
        gotoxy(40, 14);
        cout << " \\__, |\\___/ \\__,_| |_|\\___/|___/\\___|  |_____| | ";
        gotoxy(40, 15);
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

void getBackGround(char background[][41]) {
    ifstream f;
    f.open("BackGround.txt", ios::in);
    if (!f.is_open()) {
        for (int i = 0; i < 20; i++) {
            memset(background[i], ' ', 41);
        }
    }
    else {
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 41; j++) {
                background[i][j] = f.get();
            }
            f.ignore();
        }
        f.close();
    }
}

void createInfoBoard() {
    setColor(1);
    gotoxy(94, 4);
    cout << "--------------------------";

    for (int i = 5; i <= 8; i++) {
        gotoxy(94, i);
        setColor(6);
        cout << "|                        |";
    }
    for (int i = 9; i <= 13; i++) {
        gotoxy(94, i);
        setColor(4);
        cout << "|                        |";
    }
    for (int i = 14; i <= 18; i++) {
        gotoxy(94, i);
        setColor(9);
        cout << "|                        |";
    }
    for (int i = 19; i <= 23; i++) {
        gotoxy(94, i);
        setColor(13);
        cout << "|                        |";
    }
    gotoxy(94, 24);
    setColor(14);
    cout << "--------------------------";
    setColor(7);
}

int MainMenu() {
    int choice[5] = { 0,0,0,0,0 }, temp, key, curChoice = 0;
        setColor(1);
        gotoxy(10, 2);
        cout << " ____  _ _              _             ____                _         ____                      ";
        gotoxy(10, 3);
        cout << "|  _ \\(_) | ____ _  ___| |__  _   _  |  _ \\ _   _ _______| | ___   / ___| __ _ _ __ ___   ___ ";
        setColor(4);
        gotoxy(10, 4);
        cout << "| |_) | | |/ / _` |/ __| '_ \\| | | | | |_) | | | |_  /_  / |/ _ \\ | |  _ / _` | '_ ` _ \\ / _ \\";
        gotoxy(10, 5);
        cout << "|  __/| |   < (_| | (__| | | | |_| | |  __/| |_| |/ / / /| |  __/ | |_| | (_| | | | | | |  __/";
        setColor(10);
        gotoxy(10, 6);
        cout << "|_|   |_|_|\\_\\__,_|\\___|_| |_|\\__,_| |_|    \\__,_/___/___|_|\\___|  \\____|\\__,_|_| |_| |_|\\___|";

        while (1) {
            choice[curChoice] = 1;
            if (choice[0]) {
                setColor(112);
                for (int i = 0; i < 3; i++) {
                    gotoxy(50, 9 + i);
                    cout << "               ";
                }
                gotoxy(52, 10);
                setColor(112 + 1);
                cout << "Normal Mode";
            }
            else {
                setColor(7);

                for (int i = 0; i < 3; i++) {
                    gotoxy(50, 9 + i);
                    cout << "               ";
                }

                gotoxy(52, 10);
                setColor(1);
                cout << "Normal Mode";
            }

            if (choice[1]) {
                setColor(112);

                for (int i = 0; i < 3; i++) {
                    gotoxy(50, 12 + i);
                    cout << "                ";
                }

                gotoxy(51, 13);
                setColor(112 + 4);
                cout << "Hardcore Mode";
            }
            else {
                setColor(7);

                for (int i = 0; i < 3; i++) {
                    gotoxy(50, 12 + i);
                    cout << "                ";
                }

                gotoxy(51, 13);
                setColor(4);
                cout << "Hardcore Mode";
            }

            if (choice[2]) {
                setColor(112);

                for (int i = 0; i < 3; i++) {
                    gotoxy(50, 15 + i);
                    cout << "                ";
                }

                gotoxy(52, 16);
                setColor(112 + 2);
                cout << "Leaderboard";
            }
            else {
                setColor(7);

                for (int i = 0; i < 3; i++) {
                    gotoxy(50, 15 + i);
                    cout << "                ";
                }

                gotoxy(52, 16);
                setColor(6);
                cout << "Leaderboard";
            }

            if (choice[3]) {
                setColor(112);

                for (int i = 0; i < 3; i++) {
                    gotoxy(50, 18 + i);
                    cout << "                ";
                }

                gotoxy(53, 19);
                setColor(112 + 13);
                cout << "Tutorial";
            }
            else {
                setColor(7);
                for (int i = 0; i < 3; i++) {
                    gotoxy(50, 18 + i);
                    cout << "                ";
                }

                gotoxy(53, 19);
                setColor(13);
                cout << "Tutorial";
            }

            if (choice[4]) {
                setColor(112);

                for (int i = 0; i < 3; i++) {
                    gotoxy(50, 21 + i);
                    cout << "                ";
                }

                gotoxy(53, 22);
                setColor(112 + 8);
                cout << "Exit Game";
            }
            else {
                setColor(7);
                for (int i = 0; i < 3; i++) {
                    gotoxy(50, 21 + i);
                    cout << "                ";
                }

                gotoxy(53, 22);
                setColor(8);
                cout << "Exit game";
            }

        setColor(7);

        if (temp = _getch()) {
            if (temp != 224 && temp != 0 && temp != Phimw && temp != Phims)
            {
                if (temp == PhimEnter || temp == PhimCach) {
                    system("cls");
                    return curChoice;
                }
            }
            else {
                if (temp == 224) {
                    key = _getch();
                    switch (key)
                    {
                    case PhimLen:
                        choice[curChoice] = 0;
                        if (curChoice > 0) curChoice--;
                        else curChoice = 4;
                        break;
                    case PhimXuong:
                        choice[curChoice] = 0;
                        if (curChoice < 4) curChoice++;
                        else curChoice = 0;
                    default:
                        break;
                    }
                }
                switch (temp)
                {
                case Phimw:
                    choice[curChoice] = 0;
                    if (curChoice > 0) curChoice--;
                    else curChoice = 4;
                    break;
                case Phims:
                    choice[curChoice] = 0;
                    if (curChoice < 4) curChoice++;
                    else curChoice = 0;
                default:
                    break;
                }
            }
        }
    }
}

void getPlayerInfo(Player& p) {
    gotoxy(50, 12);
    cout << "Enter player name: ";
    cin >> p.name;
    cin.ignore();
    p.life = 3;
    p.point = 0;
    p.hint = 5;
}

void Tutorial() {
    setColor(9);
    gotoxy(40, 10);
    cout << "Press wasd or arrow key to move ";
    setColor(10);
    gotoxy(40, 12);
    cout << "Press space or enter to choose object";
    setColor(11);
    gotoxy(40, 14);
    cout << "Press esc to quit";
    _getch();
    system("cls");
}