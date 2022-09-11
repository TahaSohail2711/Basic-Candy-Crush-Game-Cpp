// 19L-2241
// 19L-2361
// 19L-1218
// 19L-2272

#include<iostream>
#include "myconsole.h"
#include "mygraphics.h"
#include<fstream>
#include<cstdlib>

using namespace std;
const int rows = 9, cols = 9;
int arr[rows][cols];

COLORREF purple = RGB(117, 0, 117);
COLORREF black = RGB(0, 0, 0);
COLORREF white = RGB(255, 255, 255);
COLORREF blue = RGB(0, 0, 255);
COLORREF orange = RGB(255, 128, 0);
COLORREF red = RGB(255, 0, 0);
COLORREF pink = RGB(255, 0, 100);
COLORREF brown = RGB(183, 91, 0);
COLORREF grey = RGB(150, 150, 150);
COLORREF yellow = RGB(255, 230, 0);
COLORREF green = RGB(0, 255, 0);
COLORREF wrap = RGB(64, 102, 102);
void Bomb(int x1, int y1, int x2, int y2);
void Candy(int x1, int y1, int x2, int y2, COLORREF color);
void StCandy(int x1, int y1, int x2, int y2, COLORREF color);
void WrCandy(int x1, int y1, int x2, int y2, COLORREF color);
void Call(int i, int j, int a);
void StCrush(int& score);
void Crush(int& score);
void WrapCrush(int& score);
void Intro();
void Move(int& score);
int Random();
void Swap(int& a, int& b);
int Check(int r, int c, int m, int n);
void CShift();
void Board(int& score);
void ClearMenu();
void Candies();
void Grid(int turns, int score);
void Score(int a, int m, int& score);
void Turn(int& score);
void Valid(int m, int n, int x, int y, int& score);
void congrats();
void youlose();

void main()
{
	int rex = 0, score = 0;
	FullScreen();
	Intro();
	do
	{
		cout << "Enter \n\t 1). To start \n\t 2). To load saved game" << endl;
		cin >> rex;
		if (rex < 0 && rex > 3)
			cout << "*** Inproper Input ***" << endl;
	} while (rex < 0 && rex > 3);
	if (rex == 1)
	{
		system("cls");
		Board(score);
		int r;

		for (int i = 0; i < rows; i++)

		{
			for (int t = 0; t < cols; t++)
			{
				int val = Random();
				arr[t][i] = val;
				int x = (100) + (t * 50);
				int y = 600 + (i * 50);
				Call(y, x, val);
			}
		}
		
		for (int i = 0; i < 20; )
		{
			cout << "YOUR SCORE IS : " << score << endl;
			cout << "No. of turns: " << 20 - i << endl;
			Turn(score);

			PlaceCursor(5, 5);
			i++;
			if (i >= 1)
				Grid(20 - i, score);
			ClearScreen();
		}
		if (score >= 3000)
		{
			congrats();
		}
		else
		{
			youlose();
		}
	}
	else if (rex == 2)
	{
		int f;
		system("cls");
		ifstream fin;
		fin.open("Save.txt");
		fin >> f;
		fin >> score;
		int i = 20 - f;
		while (!fin.eof())
		{
			for (int t = 0; t < rows; t++)
			{
				for (int j = 0; j < cols; j++)
				{
					fin >> arr[t][j];
				}
			}
		}
		fin.close();
		for (; i < 20; i++)
		{
			PlaceCursor(5, 5);
			Turn(score);
			PlaceCursor(1, 1);
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\YOUR SCORE IS : " << score << endl;
			cout << "No. of turns: " << 20 - i << endl;
			Sleep(30);
			if (i >= 1)
				Grid(20 - i, score);
			ClearScreen();
		}
		if (score >= 3000)
		{
			congrats();
		}
		else
		{
			youlose();
		}
	}

}
void Turn(int& score)
{
	myRect(595, 95, 1050, 550, red, orange);
	Board(score);
	Candies();
	Move(score);
	Crush(score);
	StCrush(score);
	WrapCrush(score);
	PlaceCursor(1, 1);
}
void Candies()
{
	for (int i = 0; i < rows; i++)
	{
		for (int t = 0; t < cols; t++)
		{
			int val = arr[t][i];
			int x = (100) + (t * 50);
			int y = 600 + (i * 50);
			Call(y, x, val);
		}
	}
}
void ClearMenu()
{
	myRect(0, 0, 350, 500, black, black);
	Sleep(10);
}
void Board(int& score)
{
	myRect(595, 95, 1050, 550, red, RGB(241, 149, 21));
	char Score[] = " SCORE ";
	myDrawTextWithFont(1100, 100, 70, Score, orange, black);
	Sleep(10);
	char mnt[] = "A B C D E F G H I ";
	myDrawTextWithFont(590, 15, 67, mnt, orange, black);
	char asd[] = "0"; myDrawTextWithFont(540, 90, 60, asd, orange, black);
	char asf[] = "1."; myDrawTextWithFont(540, 140, 60, asf, orange, black);
	char asg[] = "2."; myDrawTextWithFont(540, 190, 60, asg, orange, black);
	char ash[] = "3."; myDrawTextWithFont(540, 240, 60, ash, orange, black);
	char asj[] = "4."; myDrawTextWithFont(540, 290, 60, asj, orange, black);
	char ask[] = "5."; myDrawTextWithFont(540, 340, 60, ask, orange, black);
	char asl[] = "6."; myDrawTextWithFont(540, 390, 60, asl, orange, black);
	char asz[] = "7."; myDrawTextWithFont(540, 440, 60, asz, orange, black);
	char asx[] = "8."; myDrawTextWithFont(540, 490, 60, asx, orange, black);
	for (int i = 0; i < rows; i++)
	{
		for (int t = 0; t < cols; t++)
		{
			int val = arr[t][i];
			int x = (100) + (t * 50);
			int y = 600 + (i * 50);
			Call(y, x, val);
		}
	}
	Sleep(20);
	PlaceCursor(1, 1);

}
int Random()
{
	int val = rand() % 5;
	return val + 1;
}
void Intro()
{
	bool flag = false;
	FullScreen();
	int j = 0;

	char str[] = "CANDY CRUSH";
	myDrawTextWithFont(350, 350, 150, str, RGB(251, 83, 2), RGB(0, 0, 0));
	Sleep(2000);
	system("cls");
	for (int i = 0; i < 250; i++)
	{
		for (int j = 0; j < 300; j++)
		{
			SetColorAtPoint(i, j, RGB(255, 255, 255));
			j++;
		}
	}
	for (int i = 0; i < 150 && i != -1; )
	{
		char abc[] = "PRESENTED BY :";
		myDrawTextWithFont(500, 100 + i, 75, abc, RGB(251, 83, 2), RGB(0, 0, 0));
		Sleep(10);
		char def[] = " >> Nivyan Shuaib";
		myDrawTextWithFont(590, 182 + i, 35, def, RGB(251, 83, 2), RGB(0, 0, 0));
		Sleep(10);
		char ghj[] = " >> Taha Sohail";
		myDrawTextWithFont(590, 224 + i, 35, ghj, RGB(251, 83, 2), RGB(0, 0, 0));
		Sleep(10);
		char klm[] = " >> Shahood Amir";
		myDrawTextWithFont(590, 266 + i, 35, klm, RGB(251, 83, 2), RGB(0, 0, 0));
		Sleep(10);
		char nop[] = " >> Khursand Sohail";
		myDrawTextWithFont(590, 308 + i, 35, nop, RGB(251, 83, 2), RGB(0, 0, 0));
		Sleep(10);
		char enter[] = ">>> PRESS ENTER TO  ";
		myDrawTextWithFont(460, 690, 30, enter, RGB(255, 255, 0), RGB(0, 0, 0));
		Sleep(10);
		char enter1[] = "SKIP THE INTRO <<<";
		myDrawTextWithFont(715, 690, 30, enter1, RGB(255, 255, 0), RGB(0, 0, 0));
		Sleep(10);
		i++;
		if (CheckWhichKeyPressed(flag, 20))
		{
			i = -1;
		}
	}
	system("cls");
}
void Candy(int x1, int y1, int x2, int y2, COLORREF color)
{
	COLORREF black = RGB(0, 0, 0);
	myEllipse(x1, y1, x2, y2, black, color);
	Sleep(10);
}
void WrCandy(int x1, int y1, int x2, int y2, COLORREF color)
{
	COLORREF wrap = RGB(192, 192, 192);
	myRect(x1 - 5, y1 - 5, x2 + 5, y2 + 5, color, wrap);
	myEllipse(x1, y1, x2, y2, color, color);
	Sleep(10);
}
void StCandy(int x1, int y1, int x2, int y2, COLORREF color)
{
	int d = (y2 - y1) / 2;
	COLORREF white = RGB(255, 255, 255);
	myEllipse(x1, y1, x2, y2, white, color);
	myLine(x1 + 5, y1 + (d / 2), x2 - 3, y1 + (d / 2), white);
	myLine(x1, y1 + (d), x2, y1 + (d), white);
	myLine(x1 + 5, y1 + (3 * d / 2), x2 - 3, y1 + (3 * d / 2), white);
	Sleep(10);
}
void Bomb(int x1, int y1, int x2, int y2)
{
	COLORREF purple = RGB(117, 0, 117), white = RGB(255, 255, 255), yellow = RGB(255, 230, 0), red = RGB(255, 0, 0)
		, black = RGB(0, 0, 0), blue = RGB(0, 0, 255), green = RGB(0, 255, 0), orange = RGB(255, 128, 0);
	int hx = (x2 - x1) / 10;
	int hy = (x2 - x1) / 10;
	myEllipse(x1, y1, x2, y2, white, purple);
	myEllipse(x1 + hx, y1 + hy, x2 - hx, y2 - hy, red, red);
	myEllipse(x1 + (2 * hx), y1 + (2 * hy), x2 - (2 * hx), y2 - (2 * hy), blue, blue);
	myEllipse(x1 + (3 * hx), y1 + (3 * hy), x2 - (3 * hx), y2 - (3 * hy), black, green);
	myEllipse(x1 + (4 * hx), y1 + (4 * hy), x2 - (4 * hx), y2 - (4 * hy), black, orange);
	myEllipse(x1 + (5 * hx), y1 + (5 * hy), x2 - (5 * hx), y2 - (5 * hy), yellow, black);
	Sleep(10);
}
void Crush(int& score)
{
	// Rows
	int i, j = 0, a;
	int m, n = 0;
	int x, y, b;
	for (i = 0; i < 9; i++)
	{
		j = 0;
		while (j < 7)
		{
			m = 0;
			do
			{
				if (arr[i][j] == arr[i][j + 1])
				{
					j++;
					m++;
					x = i;
					y = j;
					if (m >= 2 && m <= 4)
					{
						n = m;
					}
				}
				else
				{
					m = -1;
					j++;
				}
			} while (m != -1);
			b = n;

			if (n == 2)
			{
				int p = arr[i][j - (n + 1)];
				Score(p, n, score);
				while (n >= 0)
				{
					arr[i][j - (n + 1)] = NULL;
					n--;
					CShift();
				}
			}
			else if (n == 3)
			{
				int p = arr[i][j - (n + 1)];
				Score(p, n, score);
				arr[i][j - (n + 1)] = (arr[i][j - (n + 1)] + 5);
				n--;
				while (n >= 0)
				{
					arr[i][j - (n + 1)] = NULL;
					n--;
					CShift();
				}
			}
			else if (n == 4)
			{
				int p = arr[i][j - (n + 1)];
				Score(p, n, score);
				arr[i][j - (n + 1)] = 16;
				n--;
				while (n >= 0)
				{
					arr[i][j - (n + 1)] = NULL;
					n--;
					CShift();
				}
			}
		}
	}
	//Columns
	i = 0; j = 0; a = 0;
	int o = 0, p = 0;
	x = 0; y = 0; b = 0;
	for (i = 0; i < 9; i++)
	{
		j = 0;
		while (j < 7)
		{
			o = 0;
			do
			{
				if (arr[j][i] == arr[j + 1][i])
				{
					j++;
					o++;
					x = i;
					y = j;
					if (o >= 2)
					{
						p = o;
					}
				}
				else
				{
					o = -1;
					j++;
				}
			} while (o != -1);
			b = p;
			if (p == 2)
			{
				int l = arr[j - (p + 1)][i];
				Score(l, p, score);
				while (p >= 0)
				{
					arr[j - (p + 1)][i] = NULL;
					p--;
					CShift();
				}
			}
			else if (p == 3)
			{
				int l = arr[j - (n + 1)][i];
				Score(l, p, score);
				arr[j - (p + 1)][i] = (arr[j - (p + 1)][i] + 5);
				p--;
				while (p >= 0)
				{
					arr[j - (p + 1)][i] = NULL;
					p--;
					CShift();
				}
			}
			else if (n == 4)
			{
				int l = arr[j - (n + 1)][i];
				Score(l, p, score);
				arr[j - (p + 1)][i] = 16;
				p--;
				while (p >= 0)
				{
					arr[j - (p + 1)][i] = NULL;
					p--;
					CShift();
				}
			}
		}
	}

}
void StCrush(int& score)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (arr[i][j] > 5 && arr[i][j] < 11)
			{

			}
		}
	}
}
void WrapCrush(int& score)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (arr[i][j] > 10 && arr[i][j] < 16)
			{

			}
		}
	}
}
void CShift()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (arr[i][j] == 0)
			{
				for (int l = i; i > 0; i--)
				{
					arr[i][j] = arr[i - 1][j];
				}
				arr[0][j] = Random();
			}
		}
	}

}
void Score(int a, int m, int& score)
{
	long int s = 0;
	if (a == 1)
		s = 30;
	else if (a == 2)
		s = 50;
	else if (a == 3)
		s = 40;
	else if (a == 4)
		s = 30;
	else if (a == 5)
		s = 60;
	score = score + (s * (m + 1));
}
void Call(int i, int j, int a)
{
	if (a == 1)
		Candy(i, j, i + 40, j + 40, red);
	else if (a == 2)
		Candy(i, j, i + 40, j + 40, blue);
	else if (a == 3)
		Candy(i, j, i + 40, j + 40, green);
	else if (a == 4)
		Candy(i, j, i + 40, j + 40, purple);
	else if (a == 5)
		Candy(i, j, i + 40, j + 40, orange);
	else if (a == 6)
		StCandy(i, j, i + 40, j + 40, red);
	else if (a == 7)
		StCandy(i, j, i + 40, j + 40, blue);
	else if (a == 8)
		StCandy(i, j, i + 40, j + 40, green);
	else if (a == 9)
		StCandy(i, j, i + 40, j + 40, purple);
	else if (a == 10)
		StCandy(i, j, i + 40, j + 40, orange);
	else if (a == 11)
		WrCandy(i, j, i + 40, j + 40, red);
	else if (a == 12)
		WrCandy(i, j, i + 40, j + 40, blue);
	else if (a == 13)
		WrCandy(i, j, i + 40, j + 40, green);
	else if (a == 14)
		WrCandy(i, j, i + 40, j + 40, purple);
	else if (a == 15)
		WrCandy(i, j, i + 40, j + 40, orange);
	else if (a == 16)
		Bomb(i, j, i + 40, j + 40);
}
void Move(int& score)
{
	char x, z;
	int y, m, n;
	do
	{
		PlaceCursor(5, 5);
		cout << "Enter column of candy you to change: ";
		cin >> x;
		if (x != 'A' && x != 'a' && x != 'B' && x != 'b' && x != 'C' && x != 'c' && x != 'D' && x != 'd' && x != 'E' && x != 'e' && x != 'F' && x != 'f' && x != 'G' && x != 'g' && x != 'H' && x != 'h' && x != 'I' && x != 'i')
			cout << "* Improper Input *" << endl;
		if (x == 'A' || x == 'a')
			n = 0;
		if (x == 'B' || x == 'b')
			n = 1;
		if (x == 'C' || x == 'c')
			n = 2;
		if (x == 'D' || x == 'd')
			n = 3;
		if (x == 'E' || x == 'e')
			n = 4;
		if (x == 'F' || x == 'f')
			n = 5;
		if (x == 'G' || x == 'g')
			n = 6;
		if (x == 'H' || x == 'h')
			n = 7;
		if (x == 'I' || x == 'i')
			n = 8;
	} while (x != 'A' && x != 'a' && x != 'B' && x != 'b' && x != 'C' && x != 'c' && x != 'D' && x != 'd' && x != 'E' && x != 'e' && x != 'F' && x != 'f' && x != 'G' && x != 'g' && x != 'H' && x != 'h' && x != 'I' && x != 'i');
	do
	{
		cout << "Enter rox of candy you to change: ";
		cin >> y;
		m = y;
		if (y < 0 || y > 8)
			cout << "* Improper Input *" << endl;
	} while (y < 0 || y > 8);
	do
	{
		cout << "\nTo shift candy UPWARDS press 'W'\nTo shift candy DOWNWARDS press 'S'\nTo shift candy to the RIGHT press 'A'\nTo shift candy to the LEFT press 'D'" << endl;
		cin >> z;
		if (z != 'W' && z != 'w' && z != 'A' && z != 'a' && z != 'S' && z != 's' && z != 'D' && z != 'd')
			cout << "* Improper Input *" << endl;
	} while (z != 'W' && z != 'w' && z != 'A' && z != 'a' && z != 'S' && z != 's' && z != 'D' && z != 'd');
	int check;
	int a;
	int p, q;
	if (z == 'W' || z == 'w')
	{
		p = m - 1, q = n;
		Valid(m, n, p, q, score);
	}
	else if (z == 'S' || z == 's')
	{
		p = m + 1, q = n;
		Valid(m, n, p, q, score);
	}
	else if (z == 'A' || z == 'a')
	{
		p = m, q = n - 1;
		Valid(m, n, p, q, score);
	}
	else if (z == 'D' || z == 'd')
	{
		p = m, q = n + 1;
		Valid(m, n, p, q, score);
	}
}
void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
int Check(int r, int c, int m, int n)
{
	int i = m, t = n;
	//For Rows
	if ((arr[r][c] == arr[i][t + 1]) && (arr[r][c] == arr[i][t + 2]))
		return 1;
	else if ((arr[r][c] == arr[i][t + 1]) && (arr[r][c] == arr[i][t - 1]))
		return 1;
	else if ((arr[r][c] == arr[i][t - 1]) && (arr[r][c] == arr[i][t - 2]))
		return 1;
	else if ((arr[r][c] == arr[t][i + 1]) && (arr[r][c] == arr[t][i + 2]))
		return 1;
	else if ((arr[r][c] == arr[t][i + 1]) && (arr[r][c] == arr[t][i - 1]))
		return 1;
	else if ((arr[r][c] == arr[t][i - 1]) && (arr[r][c] == arr[t][i - 2]))
		return 1;
	///////
	if ((arr[m][n] == arr[i][t + 1] || arr[m][n] == arr[i][t + 1] % 5) && (arr[m][n] == arr[i][t + 2] || arr[m][n] == arr[i][t + 2] % 5))
		return 1;
	else if ((arr[m][n] == arr[i][t + 1] || arr[m][n] == arr[i][t + 1] % 5) && arr[m][n] == arr[i][t - 1] || arr[m][n] == arr[i][t - 1] % 5)
		return 1;
	else if ((arr[m][n] == arr[i][t - 1] || arr[m][n] == arr[i][t - 1] % 5) && (arr[m][n] == arr[i][t - 2] || arr[m][n] == arr[i][t - 2] % 5))
		return 1;
	else if ((arr[m][n] == arr[t][i + 1] || arr[m][n] == arr[t][i + 1] % 5) && (arr[m][n] == arr[t][i + 2] || arr[m][n] == arr[t][i + 2] % 5))
		return 1;
	else if ((arr[m][n] == arr[t][i + 1] || arr[m][n] == arr[t][i + 1] % 5) && (arr[m][n] == arr[t][i - 1] || arr[m][n] == arr[t][i + 1] % 5))
		return 1;
	else if ((arr[m][n] == arr[t][i - 1] || arr[m][n] == arr[t][i - 1] % 5) && (arr[m][n] == arr[t][i - 2] || arr[m][n] == arr[t][i - 2] % 5))
		return 1;
	//For Columns
	else if ((arr[r][c] == arr[t + 1][i]) && (arr[r][c] == arr[t + 2][i]))
		return 1;
	else if ((arr[r][c] == arr[t + 1][i]) && (arr[r][c] == arr[t - 1][i]))
		return 1;
	else if ((arr[r][c] == arr[t - 1][i]) && (arr[r][c] == arr[t - 2][i]))
		return 1;
	else if ((arr[r][c] == arr[i + 1][t]) && (arr[r][c] == arr[i + 2][t]))
		return 1;
	else if ((arr[r][c] == arr[i + 1][t]) && (arr[r][c] == arr[i - 1][t]))
		return 1;
	else if ((arr[r][c] == arr[i - 1][t]) && (arr[r][c] == arr[i - 2][t]))
		return 1;
	/////
	else if ((arr[m][n] == arr[t + 1][i] || arr[m][n] == arr[t + 1][i] % 5) && (arr[m][n] == arr[t + 2][i] || arr[m][n] == arr[t + 2][i] % 5))
		return 1;
	else if ((arr[m][n] == arr[t + 1][i] || arr[m][n] == arr[t + 1][i] % 5) && (arr[m][n] == arr[t - 1][i] || arr[m][n] == arr[t - 1][i] % 5))
		return 1;
	else if ((arr[m][n] == arr[t - 1][i] || arr[m][n] == arr[t - 1][i] % 5) && (arr[m][n] == arr[t - 2][i] || arr[m][n] == arr[t - 2][i] % 5))
		return 1;
	else if ((arr[m][n] == arr[i + 1][t] || arr[m][n] == arr[i + 1][t] % 5) && (arr[m][n] == arr[i + 2][t] || arr[m][n] == arr[i + 2][t] % 5))
		return 1;
	else if ((arr[m][n] == arr[i + 1][t] || arr[m][n] == arr[i + 1][t] % 5) && (arr[m][n] == arr[i - 1][t] || arr[m][n] == arr[i - 1][t] % 5))
		return 1;
	else if ((arr[m][n] == arr[i - 1][t] || arr[m][n] == arr[i - 1][t] % 5) && (arr[m][n] == arr[i - 2][t] || arr[m][n] == arr[i - 2][t] % 5))
		return 1;
	////////////////////////////////////////////////////////
	else if (arr[r][c] == 16 || arr[m][n] == 16)
		return 5;
	else if ((arr[r][c] == 16 && arr[m][n] < 6 || arr[m][n] == 16 && arr[r][c] < 6)) // bomb to simple 
		return 2;
	else if ((arr[r][c] > 10 && arr[r][c] < 16) && (arr[m][n] > 10 && arr[m][n] < 16)) // wrap with wrap
		return 3;
	else if ((arr[r][c] > 10 && arr[r][c] < 16) && (arr[m][n] > 5 && arr[m][n] < 11)) //strip with wrap
		return 4;
	else if ((arr[m][n] > 10 && arr[m][n] < 16) && (arr[r][c] > 5 && arr[r][c] < 11))  // wrap with strip
		return 4;
	else if (arr[m][n] == 16 && (arr[r][c] > 6 && arr[r][c] < 11) || arr[r][c] == 16 && (arr[m][n] > 6 && arr[m][n] < 11))  // strip to bomb;
		return 6;
	else if (arr[m][n] == 16 && (arr[r][c] > 10 && arr[r][c] < 16) || arr[r][c] == 16 && (arr[m][n] > 10 && arr[m][n] < 16))  // wrap to bomb;
		return 7;
	return 0;
}
void Grid(int turns, int score)
{
	ofstream fout;
	fout.open("Save.txt");
	fout << turns << endl;
	fout << score << endl;
	for (int i = 0; i < 9; i++)
	{
		for (int t = 0; t < 9; t++)
			fout << arr[i][t] << " ";
		fout << "\n";
	}
	fout.close();
}
void Valid(int m, int n, int x, int y, int& score)
{
	int a;
	if (Check(m, n, x, n) == 1)
		Swap(arr[m][n], arr[x][y]);
	else if (Check(m, n, x, y) == 2)
	{
		a;
		if (arr[m][n] != 16)
			a = arr[m][n];
		else
			a = arr[x][y];
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (arr[i][j] == a)
					arr[i][j] = 0;
			}
		}
		score = score + 300;
	}
	else if (Check(m, n, x, y) == 4)
	{
		for (int i = 0; i < rows; i++)
		{
			arr[x][i] = 0;
			arr[x + 1][i] = 0;
			arr[x - 1][i] = 0;
		}
		for (int j = 0; j < cols; j++)
		{
			arr[j][y] = 0;
			arr[j][y + 1] = 0;
			arr[j][y - 1] = 0;
		}
		score = score + 500;
	}
	else if (Check(m, n, x, y) == 5)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				arr[i][j] = 0;
			}
		}
		score = score + 1200;
	}
	else if (Check(m, n, x, y) == 6)
	{
		if (arr[m][n] != 16)
			a = arr[m][n];
		else
			a = arr[x][y] % 5;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (arr[i][j] == a)
					arr[i][j] = arr[i][j] + 5;
			}
		}
		score = score + 300;
	}
	else if (Check(m, n, x, y) == 7)
	{
		if (arr[m][n] != 16)
			a = arr[m][n];
		else
			a = arr[x][y] % 5;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (arr[i][j] == a)
					arr[i][j] = arr[i][j] + 10;
			}
		}
		score = score + 400;
	}
	else
		cout << "* Combination not possible *" << endl;
}
void youlose()
{
	FullScreen();
	char abc[] = "you lose\n";
	for (int i = 0; i < 320 && i != -1; )
	{
		myDrawTextWithFont(500, i, 100, abc, RGB(251, 83, 2), RGB(0, 0, 0));
		Sleep(50);
		i = i + 4;
	}
	int fx1 = 500;
	int fx2 = 320;
	system("cls");
	myDrawTextWithFont(fx1, fx2, 100, abc, RGB(251, 83, 2), RGB(0, 0, 0));
	Sleep(300);
	system("cls");
	myDrawTextWithFont(fx1, fx2, 100, abc, red, RGB(0, 0, 0));
	Sleep(300);
	system("cls");
	myDrawTextWithFont(fx1, fx2, 100, abc, blue, RGB(0, 0, 0));
	Sleep(300);
	system("cls");
	myDrawTextWithFont(fx1, fx2, 100, abc, pink, RGB(0, 0, 0));
	Sleep(300);
	system("cls");
	myDrawTextWithFont(fx1, fx2, 100, abc, grey, RGB(0, 0, 0));
	Sleep(300);
	system("cls");
	myDrawTextWithFont(fx1, fx2, 100, abc, orange, RGB(0, 0, 0));
	Sleep(300);
	system("cls");
	myDrawTextWithFont(fx1, fx2, 100, abc, red, RGB(0, 0, 0));
	Sleep(800);
	system("cls");
	char uwon[] = "better luck next time\n";
	myDrawTextWithFont(280, 302, 100, uwon, red, RGB(0, 0, 0));
	Sleep(1000);
	system("cls");
	char th[] = "but thankyouh for testing our game\n";
	myDrawTextWithFont(350, 350, 50, th, black, red);
	Sleep(1000);

}
void congrats()
{
	FullScreen();
	char abc[] = "congratulations\n";
	for (int i = 0; i < 320 && i != -1; )
	{
		myDrawTextWithFont(450, i, 75, abc, RGB(251, 83, 2), RGB(0, 0, 0));
		Sleep(50);
		i = i + 4;
	}
	int fx1 = 380;
	int fx2 = 301;
	system("cls");
	myDrawTextWithFont(fx1, fx2, 100, abc, RGB(251, 83, 2), RGB(0, 0, 0));
	Sleep(300);
	system("cls");
	myDrawTextWithFont(fx1, fx2, 100, abc, red, RGB(0, 0, 0));
	Sleep(300);
	system("cls");
	myDrawTextWithFont(fx1, fx2, 100, abc, blue, RGB(0, 0, 0));
	Sleep(300);
	system("cls");
	myDrawTextWithFont(fx1, fx2, 100, abc, pink, RGB(0, 0, 0));
	Sleep(300);
	system("cls");
	myDrawTextWithFont(fx1, fx2, 100, abc, grey, RGB(0, 0, 0));
	Sleep(300);
	system("cls");
	myDrawTextWithFont(fx1, fx2, 100, abc, orange, RGB(0, 0, 0));
	Sleep(300);
	system("cls");
	myDrawTextWithFont(fx1, fx2, 100, abc, red, RGB(0, 0, 0));
	Sleep(800);
	system("cls");
	char uwon[] = "you won\n";
	myDrawTextWithFont(500, 302, 100, uwon, red, RGB(0, 0, 0));
	Sleep(1000);
	system("cls");
	char th[] = "thankyouh for testing our game\n";
	myDrawTextWithFont(380, 350, 50, th, black, red);
	Sleep(1000);

}