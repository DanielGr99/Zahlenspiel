#include <iostream>
#include "Header.h"

using namespace std;

void printgame(int i, int points, int pointspc);
int compare(int i, int num, int numpc);
char printmenu(char c);
void printwintxt(int points, int pointspc);

int main()
{
	#define clearc system("cls")			//Konsole leeren

	char c = ' ';

	do
	{
		int i = 0, num, numpc, points = 0, pointspc = 0, win = 2;

		c = printmenu(c);
		if (c != '1')
			break;
		while (points != 5 && pointspc != 5)
		{
			clearc;
			printgame(i,points,pointspc);
			cin >> num;
			numpc = Header::createrandom(1, 20);
			win = compare(i, num, numpc);
			if (win == 1)
				points += 1;
			else if (win == 0)
				pointspc += 1;
			cout << "\nIhre Zahl: " << num << "\tDie Zahl des Computers: " << numpc << endl;
			Header::delay(2);
			++i;
		}
		clearc;
		printwintxt(points, pointspc);
	} while (c == '1');
	

	return 0;
}
char printmenu(char c)			//Druckt das Menü
{
	cout << "Spiel starten(1)\t" << "Programm beenden(0)" << endl;
	cin >> c;
	return c;
}
void printgame(int i, int points, int pointspc)			//Druckt die Frage
{
	cout << "\n\tSie haben " << points << " Punkte.\t\t" << "Der Computer hat " << pointspc << " Punkte.\n" << endl;
	if (i % 2 == 0)
		cout << "Waehle eine Zahl zwischen 1 und 20, ist sie groesser wie die des PCs (hoechstens 5 groesser) hast du einen Punkt." << endl;
	else
		cout << "Waehle eine Zahl zwischen 1 und 20, ist sie kleiner wie die des PCs (hoechstens 5 kleiner) hast du einen Punkt." << endl;
}
int compare(int i, int num ,int numpc)		//Vergleicht die Zahlen
{
	int win;
	if (i % 2 == 0 && num > numpc&&num<=20)
	{
		if ((num - numpc) <= 5)
			win = 1;
		else if ((num - numpc) > 5)
			win = 0;
	}
	else if (i % 2 != 0 && num < numpc&&num<=20)
	{
		if ((numpc - num) <= 5)
			win = 1;
		else if ((numpc - num) > 5)
			win = 0;
	}
	else if (i % 2 == 0 && numpc > num&&num<=20 || i % 2 != 0 && numpc < num&&num<=20)
	{
		win = 0;
	}
	else if (num == numpc||num>20)
	{ 
		win = 2; 

	}
		
		
	return win;
}
void printwintxt(int points, int pointspc)			//Ermittelt den Gewinner
{
	if (points == 5)
		cout << "Hurra du hast Gewonnen!\n\n" << "Deine Punkte: " << points << "\tDie Punkte des Computers: " << pointspc << "\n" << endl;
	else
		cout << "Du hast leider verloren.\n\n" << "Deine Punkte: " << points << "\tDie Punkte des Computers: " << pointspc << "\n" << endl;

}