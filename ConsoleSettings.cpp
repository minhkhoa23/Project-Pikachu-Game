#include "ConsoleSettings.h"



/*
	Di den o co toa do x, y tren man hinh cua so
*/
void gotoxy(int x, int y)
{
    static HANDLE h = NULL;
    if (!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { x, y };
    SetConsoleCursorPosition(h, c);
}


/*
	Kha nang thay doi kich thuoc cua cua so hien thi
*/
void setCursor(bool visible) {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = 20;
    SetConsoleCursorInfo(console, &lpCursor);
}


/*
	Kiem soat kha nang hien thi cua con tro trong dau ra cua bang dieu khien
*/
void resizeWindow(int x, int y) {
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, x, y, TRUE);
}


/*
Kha nang an thanh thanh cuon cua cua so hien thi
*/
void hideScrollBar() {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screenBufferInfo;
    GetConsoleScreenBufferInfo(console, &screenBufferInfo);

    COORD new_screen_buffer_size;

    new_screen_buffer_size.X = screenBufferInfo.srWindow.Right - screenBufferInfo.srWindow.Left + 1;
    new_screen_buffer_size.Y = screenBufferInfo.srWindow.Bottom - screenBufferInfo.srWindow.Top + 1;

    SetConsoleScreenBufferSize(console, new_screen_buffer_size);
}


/*
	Khoi tao cua so hien thi
*/
void initWindow(int width, int length) {
    resizeWindow(width, length);
    hideScrollBar();
    setCursor(0);
}