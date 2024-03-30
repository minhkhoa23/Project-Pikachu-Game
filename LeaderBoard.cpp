#include "LeaderBoard.h"

void readLeaderBoard() {
	gotoxy(60, 5);
	setColor(3);
	cout << "LEADERBOARD";
	gotoxy(30, 6);
	setColor(2);
	cout << "NAME";
	gotoxy(100, 6);
	cout << "POINT";
	setColor(7);
	gotoxy(30, 7);
	for (int i = 0; i < 75; i++) {
		cout << "=";
	}

	ifstream f1;
	f1.open("leaderBoard.txt");
	if (f1) {
		Player p;

		int i = 0;
		while (getline(f1, p.name, ' ')) {
			f1 >> p.point;
			f1.get();
			gotoxy(30, 7 + i);
			for (int j = 0; j < 75; j++) {
				cout << "=";
			}
			if (i <= 4) setColor(4 - i / 2);
			gotoxy(30, 8 + i);
			cout << p.name;
			gotoxy(100, 8 + i);
			cout << p.point;
			if (i <= 4) setColor(7);
			i += 2;
		}
		f1.close();
	}
	_getch();
	system("cls");
}

void writeLeaderBoard(Player p) {
	ifstream fin("leaderBoard.txt");
	if (fin) {
		Player* list = new Player[10];
		int no_player = 0;
		string s;

		while (getline(fin, s, ' ')) {
			list[no_player].name = s;
			fin >> list[no_player].point;
			fin.get();
			no_player++;
		}

		int index = no_player - 1;
		for (index; index >= 0; index--) {
			if (p.point <= list[index].point) {
				break;
			}
		}

		if (no_player < 10) {
			for (int i = no_player; i > index + 1; i--) {
				list[i] = list[i - 1];
			}
			list[index + 1] = p;
			no_player++;
		}
		else {
			if (index != no_player - 1) {
				for (int i = no_player - 1; i > index + 1; i--) {
					list[i] = list[i - 1];
				}
				list[index + 1] = p;
			}
		}
		fin.close();


		ofstream fout("leaderBoard.txt");

		for (int i = 0; i < no_player; i++) {
			fout << list[i].name << " " << list[i].point << endl;
		}

		fout.close();

		delete[]list;
	}
	else {
		ofstream fout("leaderBoard.txt");
		fout << p.name << " " << p.point << endl;
		fout.close();
	}
}
