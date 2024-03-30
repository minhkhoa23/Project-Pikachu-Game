#include "NormalBoard.h"
#include "DifficultBoard.h"
#include "LeaderBoard.h"
int main() {
	int status;
	Player p;
	initWindow(1000, 500);
	while ((status = MainMenu()) != 4) {
		switch (status) {
		case 0:
			getPlayerInfo(p);
			normalMode(p);
			break;
		case 1:
			getPlayerInfo(p);
			difficultMode(p);
			break;
		case 2:
			readLeaderBoard();
			break;
		case 3:
			Tutorial();
			break;
		default:
			break;
		}
	}
	return 0;
}