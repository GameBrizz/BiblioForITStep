#include < iostream >
#include < conio.h >
#include < windows.h >
#include < iomanip >
#include < ctime >

using namespace std;
int chUi = 0, xUi = 20, yUi = 40, dirUi = 3, scoreUi = 0, _x = 0, _y = 0;
int xUi2 = 30, yUi2 = 30, dirUi2 = 2, scoreUi2 = 0;
void SetConsoleWinSizePosition(int width = 0, int heigth = 0, short x_position = 0, short y_position = 0)
{
	HWND hWnd = GetForegroundWindow();

	HANDLE wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetWindowPos(hWnd, NULL, x_position, y_position, 0, 0, NULL);
	SMALL_RECT windowSize;
	windowSize.Bottom = heigth;
	windowSize.Left = 0;
	windowSize.Right = width;
	windowSize.Top = 0;
	SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
	COORD bufferSize = { width + 1 , heigth + 1 };
	SetConsoleScreenBufferSize(wHnd, bufferSize);
}

//Console Color////////////////////////////////////////////
enum {
	clBlack, clNavy, clGreen, clTeal, clBrown,
	clPurple, clOlive, clGray, clSilver, clBlue,
	clLime, clCyan, clRed, clMagneta, clYellow,
	clWhite
};
///////////////////////////////////////////////////////////

void SetConsoleColorTextBackground(unsigned short Tex = clWhite, unsigned short Bg = clBlack)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	Bg = Bg << 4 | Tex;
	SetConsoleTextAttribute(hConsole, Bg);
}

void SetConsoleCursorPosition(short x_position, short y_position)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD _coordPosition = { x_position , y_position };
	SetConsoleCursorPosition(hConsole, _coordPosition);
}

void Ui(int x, int y)
{


	int xR = (rand() % 100);
	int yR = (rand() % 100);
	///////////////////сдвиг по Х/////////////////////////////////
	if (yR>80)
	{
		int uiL = (::yUi - y) > 0 ? ::yUi - y : y - ::yUi;
		uiL = 80 - uiL;
		int a = (rand() % 100) - uiL;
		int b = (rand() % 100);
		if (a < b)
		{

			int ax = (rand() % 100) + ((::xUi - x) * 7);
			int bx = (rand() % 100) + ((x - ::xUi) * 7);
			if (ax < bx)
			{
				::dirUi = 0;
			}
			else
			{
				::dirUi = 1;
			}

		}

	}

	//////////////////////////Сдвиг по Y////////////////////////////
	if (xR>80)
	{
		int uiL = (::xUi - y) > 0 ? ::xUi - x : x - ::xUi;
		uiL = 80 - uiL;
		int a = (rand() % 100) - uiL;
		int b = (rand() % 100);
		if (a < b)
		{

			int ax = (rand() % 100) + ((::yUi - y) * 7);
			int bx = (rand() % 100) + ((y - ::yUi) * 7);
			if (ax < bx)
			{
				::dirUi = 3;
			}
			else
			{
				::dirUi = 2;
			}

		}

	}
	////////////////////Движение UI//////////////////////////
	/*
	SetConsoleCursorPosition(75, 3);
	cout << ::dirUi;
	SetConsoleCursorPosition(75, 5);
	cout << "x = " << ::xUi;
	SetConsoleCursorPosition(75, 7);
	cout << "y = " << ::yUi;
	*/
	SetConsoleCursorPosition(xUi, yUi);
	SetConsoleColorTextBackground(clRed);
	char s = 1;
	switch (::dirUi) {
	case 0:
		SetConsoleCursorPosition(::xUi, ::yUi);
		cout << " ";
		::xUi++;
		if (::xUi > 70)
			::xUi = 0;
		SetConsoleCursorPosition(::xUi, ::yUi);
		cout << s;
		break;
	case 1:
		SetConsoleCursorPosition(::xUi, ::yUi);
		cout << " ";
		::xUi--;
		if (::xUi < 0)
			::xUi = 70;
		SetConsoleCursorPosition(::xUi, ::yUi);
		cout << s;
		break;
	case 2:
		SetConsoleCursorPosition(::xUi, ::yUi);
		cout << " ";
		::yUi--;
		if (::yUi < 0)
			::yUi = 40;
		SetConsoleCursorPosition(::xUi, ::yUi);
		cout << s;
		break;
	case 3:
		SetConsoleCursorPosition(::xUi, ::yUi);
		cout << " ";
		::yUi++;
		if (::yUi > 40)
			::yUi = 0;
		SetConsoleCursorPosition(::xUi, ::yUi);
		cout << s;
		break;
	}
	if (::xUi == ::_x&&::yUi == ::_y)
	{
		SetConsoleCursorPosition(72, 17);
		::scoreUi += 1;
		cout << "SCORE:";
		cout << ::scoreUi;
		::_x = rand() % 70;
		::_y = rand() % 40;
		SetConsoleCursorPosition(::_x, ::_y);
		SetConsoleColorTextBackground(clGreen);
		cout << (char)3;
	}


}

void Ui2(int x, int y)
{


	int xR = (rand() % 100);
	int yR = (rand() % 100);
	///////////////////сдвиг по Х/////////////////////////////////
	if (yR>80)
	{
		int uiL = (::yUi2 - y) > 0 ? ::yUi2 - y : y - ::yUi2;
		uiL = 80 - uiL;
		int a = (rand() % 100) - uiL;
		int b = (rand() % 100);
		if (a < b)
		{

			int ax = (rand() % 100) + ((::xUi2 - x) * 7);
			int bx = (rand() % 100) + ((x - ::xUi2) * 7);
			if (ax < bx)
			{
				::dirUi2 = 0;
			}
			else
			{
				::dirUi2 = 1;
			}

		}

	}

	//////////////////////////Сдвиг по Y////////////////////////////
	if (xR>80)
	{
		int uiL = (::xUi2 - y) > 0 ? ::xUi2 - x : x - ::xUi2;
		uiL = 80 - uiL;
		int a = (rand() % 100) - uiL;
		int b = (rand() % 100);
		if (a < b)
		{

			int ax = (rand() % 100) + ((::yUi2 - y) * 7);
			int bx = (rand() % 100) + ((y - ::yUi2) * 7);
			if (ax < bx)
			{
				::dirUi2 = 3;
			}
			else
			{
				::dirUi2 = 2;
			}

		}

	}
	////////////////////Движение UI//////////////////////////
	/*
	SetConsoleCursorPosition(75, 3);
	cout << ::dirUi;
	SetConsoleCursorPosition(75, 5);
	cout << "x = " << ::xUi;
	SetConsoleCursorPosition(75, 7);
	cout << "y = " << ::yUi;
	*/
	SetConsoleCursorPosition(xUi2, yUi2);
	SetConsoleColorTextBackground(clRed);
	char s = 1;
	switch (::dirUi2) {
	case 0:
		SetConsoleCursorPosition(::xUi2, ::yUi2);
		cout << " ";
		::xUi2++;
		if (::xUi2 > 70)
			::xUi2 = 0;
		SetConsoleCursorPosition(::xUi2, ::yUi2);
		cout << s;
		break;
	case 1:
		SetConsoleCursorPosition(::xUi2, ::yUi2);
		cout << " ";
		::xUi2--;
		if (::xUi2 < 0)
			::xUi2 = 70;
		SetConsoleCursorPosition(::xUi2, ::yUi2);
		cout << s;
		break;
	case 2:
		SetConsoleCursorPosition(::xUi2, ::yUi2);
		cout << " ";
		::yUi2--;
		if (::yUi2 < 0)
			::yUi2 = 40;
		SetConsoleCursorPosition(::xUi2, ::yUi2);
		cout << s;
		break;
	case 3:
		SetConsoleCursorPosition(::xUi2, ::yUi2);
		cout << " ";
		::yUi2++;
		if (::yUi2 > 40)
			::yUi2 = 0;
		SetConsoleCursorPosition(::xUi2, ::yUi2);
		cout << s;
		break;
	}
	if (::xUi2 == ::_x&&::yUi2 == ::_y)
	{
		SetConsoleCursorPosition(72, 19);
		::scoreUi2 += 1;
		cout << "SCORE:";
		cout << ::scoreUi2;
		::_x = rand() % 70;
		::_y = rand() % 40;
		SetConsoleCursorPosition(::_x, ::_y);
		SetConsoleColorTextBackground(clGreen);
		cout << (char)3;
	}


}




void main()
{
	srand(unsigned(time(NULL)));
	enum VKey { MVK_UP = 72, MVK_LEFT = 75, MVK_RIGHT = 77, MVK_DOWN = 80 };
	SetConsoleWinSizePosition(80, 40, 0, 130);
	SetConsoleColorTextBackground(clWhite, clBlack);
	for (int i = 0; i < 41; i++)
	{

		SetConsoleCursorPosition(71, i);
		cout << "|";

	}
	SetConsoleColorTextBackground(clRed);
	SetConsoleCursorPosition(72, 17);
	cout << "SCORE:";
	cout << ::scoreUi;

	SetConsoleColorTextBackground(clYellow);
	SetConsoleCursorPosition(72, 15);
	cout << "SCORE:";
	int ch = 0, x = 0, y = 0, dir = 0, score = -1;
	char s = 1;
	for (;;)
	{
		//обработка ввода
		if (_kbhit())
		{
			ch = _getch();
			if (ch == 0xe0)
			{
				ch = _getch();
				switch (ch)
				{
				case MVK_LEFT:
				{
					dir = 1;
				}
				break;
				case MVK_RIGHT:
				{
					dir = 0;
				}
				break;
				case MVK_UP:
				{

					dir = 2;
				}
				break;
				case MVK_DOWN:
				{
					dir = 3;
				}
				break;
				}

			}
		}
		//////////////////////////////////////
		if (x == ::_x&&y == ::_y)
		{
			SetConsoleColorTextBackground(clYellow, clBlack);
			score++;
			SetConsoleCursorPosition(78, 15);
			cout << score;
			::_x = rand() % 70;
			::_y = rand() % 40;
			SetConsoleCursorPosition(::_x, ::_y);
			SetConsoleColorTextBackground(clBlue, clBlack);
			SetConsoleColorTextBackground(clBlue, clBlack);
			cout << (char)3;
		}
		SetConsoleCursorPosition(x, y);
		int time_x = 5000 / (100 + score);
		SetConsoleColorTextBackground(clYellow);
		switch (dir) {
		case 0:
			SetConsoleCursorPosition(x, y);
			cout << " ";
			x++;
			if (x > 70)
				x = 0;
			SetConsoleCursorPosition(x, y);
			cout << s;
			Sleep(time_x);
			break;
		case 1:
			SetConsoleCursorPosition(x, y);
			cout << " ";
			x--;
			if (x < 0)
				x = 70;
			SetConsoleCursorPosition(x, y);
			cout << s;
			Sleep(time_x);
			break;
		case 2:
			SetConsoleCursorPosition(x, y);
			cout << " ";
			y--;
			if (y < 0)
				y = 40;
			SetConsoleCursorPosition(x, y);
			cout << s;
			Sleep(time_x * 2);
			break;
		case 3:
			SetConsoleCursorPosition(x, y);
			cout << " ";
			y++;
			if (y > 40)
				y = 0;
			SetConsoleCursorPosition(x, y);
			cout << s;
			Sleep(time_x * 2);
			break;
		}
		Ui2(_x, _y);
		Ui(_x, _y);
		Ui2(_x, _y);
		Ui(_x, _y);


		//////////////////////////////////////
	}
}