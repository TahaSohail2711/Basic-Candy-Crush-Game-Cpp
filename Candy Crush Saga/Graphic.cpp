#include <iostream>
#include "myconsole.h"
#include "mygraphics.h"


using namespace std;



void main(){
	
	//PlaceCursor(30, 30);
	Maximized();
		//myLine(5, 5, 50, 50, RGB(255, 50, 10));
		int i = 1, j = 1;
		//while (i<1000){
		//	i++, j++;
		//	//ClearScreen();
		//	myEllipse(10, 10, i, j, RGB(0, 250, 2+i), RGB(218, 11+j, 255));
		//	Sleep(100);
		//}


		//ClearScreen();
		//i = 1, j = 1;
		//while (i<300){
		//	i++, j++;
		//	//ClearScreen();
		//	myEllipse(i, j, 100+i, 100+j, RGB(0, 250, 2), RGB(218, 15, 255));
		//	Sleep(10);

		//}
		////ClearScreen();
		//i = 300, j = 300;
		//while (i>0){
		//	i--, j--;
		//	ClearScreen();
		//	myEllipse(i, j, 100 + i, 100 + j, RGB(100, 250, 2), RGB(50, 15, 255));
		//	Sleep(10);
		//}
		//ClearScreen();
		//i = 1, j = 1;
		//while (i<500){
		//	i++, j++;
		//	//ClearScreen();
		//	myRect(50+i, 100, 100+i, 150, RGB(255, 10, 2), RGB(20, 11, 255));

		//	Sleep(10);
		//}
		//i = 1, j = 1;
		//while (i<500){
		//	i++, j++;
		//	//ClearScreen();
		//	myRect(50, 100 + i, 100, 150 + i, RGB(255, 10, 2), RGB(20, 11, 255));
		//	Sleep(10);
		//}
		//ClearScreen();
		//j = 1;
		//while (j<500){
		//	i--, j++;
		//	//ClearScreen();
		//	myRect(100 + j, 200, 200 + j, 300, RGB(255, 10, 2), RGB(20, 11, 255));
		//	myRect(100, 200 + j, 200, 300 + j, RGB(255, 10, 2), RGB(20, 11, 255));
		//	myRect(i-100, 200, i-200, 300, RGB(255, 10, 2), RGB(20, 11, 255));
		//	myRect(100, i-200, 200, i-300 , RGB(255, 10, 2), RGB(20, 11, 255));
		//	Sleep(10);
		//}
		ClearScreen();
		j = 1;
		while (j<500){
		   j++;
		  // system("cls");
			myDrawText(50, 50, 50, "Hello", RGB(250, 120, 50+j), RGB(100, 80, 100+j));
			Sleep(10);
		}
	
	system("Pause");
}