#pragma once
#include <Windows.h>

/*
	Di den o co toa do x, y tren man hinh cua so
*/
void gotoxy(int x, int y);


/*
	Kha nang thay doi kich thuoc cua cua so hien thi
*/
void resizeWindow(int, int);


/*
	Kiem soat kha nang hien thi cua con tro trong dau ra cua bang dieu khien
*/
void setCursor(bool);


/*
	Kha nang an thanh thanh cuon cua cua so hien thi
*/
void hideScrollBar();


/*
	Khoi tao cua so hien thi
*/
void initWindow(int, int);