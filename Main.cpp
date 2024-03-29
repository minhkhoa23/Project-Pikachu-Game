#include "NormalBoard.h"
int main() {
	int status;
	Player p;
	initWindow(1000, 500);
	p.name = "test";
	p.life = 3;
	p.point = 0;
	normalMode(p);
	return 0;
}