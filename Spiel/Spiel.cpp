#include <iostream>
using namespace std;
#include <string>
using namespace std;
#include <stdio.h>
#include <Windows.h>
using namespace std;
#include <fstream>
using namespace std;
#include <sstream>
using namespace std;
#include "ausgabe.h"

int Spielfeldgenerieren();
int mapreader();
int wegreader();
int repaint();
int spielfigursuchen();
int moveleft();
int moveright();
int moveup();
int movedown();
int action();
int inventar();

int schlüssel = 0;
int Stadt = 2;


int    Spielwege[30][30];
string Spielfeld[30][30];
	         //  z   l
string map;
string weg;
string output;
int spielfeldgröße = 30;

int a;
int b;
int c;
int d;
int e;
int f;
int g;
int h;
int i;
int j;

char command;

int main()
{
	map = "C:\\Users\\Ferdinand\\Desktop\\spiel\\res\\maps\\level1.txt";
	weg = "C:\\Users\\Ferdinand\\Desktop\\spiel\\res\\maps\\level1begehbar.txt";

	wegreader();

	mapreader();

	spielfigursuchen();

	repaint();

	int spielbeenden = 1;

	while (spielbeenden == 1)
	{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
			cin >> command;

			switch (command)
			{
			case 'w':

				if (b > 0)
				{
					if (Spielwege[a][b - 1] == 1)
					{
						repaint();
					}
					else if (Spielwege[c][d - 1] == 1)
					{
						repaint();
					}
					else if (Spielwege[g][h - 1] == 1)
					{
						repaint();
					}
					else if (Spielwege[e][f - 1] == 1)
					{
						repaint();
					}
					else if (Spielwege[i][j - 1] == 1)
					{
						repaint();
					}
					else
					{
						moveup();
						repaint();
					}
				}
				else
				{
					repaint();
				}

				break;
			case 's':
				if (j < spielfeldgröße - 1)
				{
					if (Spielwege[a][b + 1] == 1)
					{
						repaint();
					}
					else if (Spielwege[c][d + 1] == 1)
					{
						repaint();
					}
					else if (Spielwege[g][h + 1] == 1)
					{
						repaint();
					}
					else if (Spielwege[e][f + 1] == 1)
					{
						repaint();
					}
					else if (Spielwege[i][j + 1] == 1)
					{
						repaint();
					}
					else
					{
						movedown();
						repaint();

					}
				}
				else
				{
					repaint();
				}

				break;

			case 'a':
				if (c > 0)
				{
					if (Spielwege[a - 1][b] == 1)
					{
						repaint();
					}
					else if (Spielwege[c - 1][d] == 1)
					{
						repaint();
					}
					else if (Spielwege[g - 1][h] == 1)
					{
						repaint();
					}
					else if (Spielwege[e - 1][f] == 1)
					{
						repaint();
					}
					else if (Spielwege[i - 1][j] == 1)
					{
						repaint();
					}
					else
					{
						moveleft();
						repaint();
					}
				}
				else
				{
					repaint();
				}
				break;

			case 'd':
				if (g < spielfeldgröße)
				{
					if (Spielwege[a + 1][b] == 1)
					{
						repaint();
					}
					else if (Spielwege[c + 1][d] == 1)
					{
						repaint();
					}
					else if (Spielwege[g + 1][h] == 1)
					{
						repaint();
					}
					else if (Spielwege[e + 1][f] == 1)
					{
						repaint();
					}
					else if (Spielwege[i + 1][j] == 1)
					{
						repaint();
					}
					else
					{
						moveright();
						repaint();
					}
				}
				else
				{
					repaint();
				}
				break;

			case 'f':
				action();
				break;
			case 'm':
				Stadt = 1;
				break;
			case 'i':
				inventar();
				break;
			}
		}
	


	int ende;
	cin >> ende;

    return 0;
}

int mapreader() {

	ifstream namenliste(map, ios::in);

	string zeichenkette;

	int linienzähler = 0;



	while (getline(namenliste, zeichenkette))
	{

		char r[30];


		stringstream datenstrohm(zeichenkette);

		datenstrohm >> r[0] >> r[1] >> r[2] >> r[3] >> r[4] >> r[5] >> r[6] >> r[7] >> r[8] >> r[9] >> r[10] >> r[11] >> r[12] >> r[13] >> r[14] >> r[15] >> r[16] >> r[17] >> r[18] >> r[19] >> r[20] >> r[21] >> r[22] >> r[23] >> r[24] >> r[25] >> r[26] >> r[27] >> r[28] >> r[29];


		for (int i = 0; i < spielfeldgröße; i++)
		{
			

			Spielfeld[i][linienzähler-1] = r[i];
				
			
		}


		linienzähler++;
	}
	return(0);
	
}

int wegreader() {

	ifstream namenliste(weg, ios::in);

	string zeichenkette;

	int linienzähler = 0;



	while (getline(namenliste, zeichenkette))
	{

		int r[30];


		stringstream datenstrohm(zeichenkette);

		datenstrohm >> r[0] >> r[1] >> r[2] >> r[3] >> r[4] >> r[5] >> r[6] >> r[7] >> r[8] >> r[9] >> r[10] >> r[11] >> r[12] >> r[13] >> r[14] >> r[15] >> r[16] >> r[17] >> r[18] >> r[19] >> r[20] >> r[21] >> r[22] >> r[23] >> r[24] >> r[25] >> r[26] >> r[27] >> r[28] >> r[29];


		for (int i = 0; i < spielfeldgröße; i++)
		{


			Spielwege[i][linienzähler - 1] = r[i];


		}


		linienzähler++;
	}
	return(0);

}



int spielfigursuchen() {

	int indikator = 0;

	for (int x = 0; x < spielfeldgröße; x++)
	{
		for (int y = 0; y < spielfeldgröße; y++)
		{
			if (Spielfeld[x][y] == "O")
			{
				a = x;
				b = y;
			}else if (Spielfeld[x][y] == "-")
			{
				if (indikator == 0)
				{
					c = x;
					d = y;
					indikator++;
				}
				else if (indikator == 1)
				{
					g = x;
					h = y;
				}
			}
			else if (Spielfeld[x][y] == "T")
			{
				e = x;
				f = y;
			}
			else if (Spielfeld[x][y] == "^")
			{
				i = x;
				j = y;
			}
			else
			{

			}
		}

	}
	return(0);
}

int moveup() {
	
	Spielfeld[a][b] = "0";
	Spielfeld[c][d] = "0";
	Spielfeld[e][f] = "0";
	Spielfeld[g][h] = "0";
	Spielfeld[i][j] = "0";
	
	b = b - 1;
	d = d - 1;
	f = f - 1;
	h = h - 1;
	j = j - 1;
	
	Spielfeld[a][b] = "O";
	Spielfeld[c][d] = "-";
	Spielfeld[e][f] = "T";
	Spielfeld[g][h] = "-";
	Spielfeld[i][j] = "^";

	

	return(0);
}
int movedown() {

	Spielfeld[a][b] = "0";
	Spielfeld[c][d] = "0";
	Spielfeld[e][f] = "0";
	Spielfeld[g][h] = "0";
	Spielfeld[i][j] = "0";
	
	b = b + 1;
	d = d + 1;
	f = f + 1;
	h = h + 1;
	j = j + 1;
	
	Spielfeld[a][b] = "O";
	Spielfeld[c][d] = "-";
	Spielfeld[e][f] = "T";
	Spielfeld[g][h] = "-";
	Spielfeld[i][j] = "^";

	return(0);
}
int moveleft() {
	
	Spielfeld[a][b] = "0";
	Spielfeld[c][d] = "0";
	Spielfeld[e][f] = "0";
	Spielfeld[g][h] = "0";
	Spielfeld[i][j] = "0";
	
	a = a - 1;
	c = c - 1;
	e = e - 1;
	g = g - 1;
	i = i - 1;
	
	Spielfeld[a][b] = "O";
	Spielfeld[c][d] = "-";
	Spielfeld[e][f] = "T";
	Spielfeld[g][h] = "-";
	Spielfeld[i][j] = "^";

	return(0);
}
int moveright() {
	
	Spielfeld[a][b] = "0";
	Spielfeld[c][d] = "0";
	Spielfeld[e][f] = "0";
	Spielfeld[g][h] = "0";
	Spielfeld[i][j] = "0";

	a = a + 1;
	c = c + 1;
	e = e + 1;
	g = g + 1;
	i = i + 1;

	Spielfeld[a][b] = "O";
	Spielfeld[c][d] = "-";
	Spielfeld[e][f] = "T";
	Spielfeld[g][h] = "-";
	Spielfeld[i][j] = "^";

	return(0);
}


int repaint() 
{
	for (int i = 0; i < spielfeldgröße; i++)
	{
		for (int j = 0; j < spielfeldgröße; j++)
		{
			if (Spielfeld[j][i] == "0")
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 34);
				cout << Spielfeld[j][i] + " ";
			}
			else if(Spielfeld[j][i] == "x")
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
				cout << Spielfeld[j][i] + " ";
			}
			else if (Spielfeld[j][i] == "m")
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 102);
				cout << Spielfeld[j][i] + " ";
			}
			else if (Spielfeld[j][i] == "ü")
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 238);
				cout << Spielfeld[j][i] + " ";
			}
			else if (Spielfeld[j][i] == "O")
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 32);
				cout << Spielfeld[j][i] + " ";
			}
			else if (Spielfeld[j][i] == "T")
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 32);
				cout << Spielfeld[j][i] + " ";
			}
			else if (Spielfeld[j][i] == "-")
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 32);
				cout << Spielfeld[j][i] + " ";
			}
			else if (Spielfeld[j][i] == "I")
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 32);
				cout << Spielfeld[j][i] + " ";
			}
			else if (Spielfeld[j][i] == "^")
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 32);
				cout << Spielfeld[j][i] + " ";
			}
			else if (Spielfeld[j][i] == "r")
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 204);
				cout << Spielfeld[j][i] + " ";
			}
			else if (Spielfeld[j][i] == "b")
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 102);
				cout << Spielfeld[j][i] + " ";
			}
			else if (Spielfeld[j][i] == "g")
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 136);
				cout << Spielfeld[j][i] + " ";
			}
			else if (Spielfeld[j][i] == "d")
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 187);
				cout << Spielfeld[j][i] + " ";
			}
			else if (Spielfeld[j][i] == "h")
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 17);
				cout << Spielfeld[j][i] + " ";
			}
			else if (Spielfeld[j][i] == "q")
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 221);
				cout << Spielfeld[j][i] + " ";
			}
			if (j == spielfeldgröße-1)
			{

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
				cout << Spielfeld[j][i] << endl;
			}
		}
	}

	return(0);
}

int action() {
	if (Spielwege[a][b] == 2)
	{
		if (schlüssel == 0)
		{	
			output = "Hier komme ich nicht rein, mir fehlt ein Schluessel!";
			ausgabe(output);
			repaint();
		}
		else if (schlüssel == 1)
		{
			output = "Dast du wirklich gedacht, Das spiel ist hier vorbei?";
			ausgabe(output);
			output = "Ich habe an diesem kleinen Teil des Adventurens schon 6 Stunden gesessen!";
			ausgabe(output);
			output = "Und das nur für die Engine! Noch nen bisschen Storry da rinzuklatschen ist nicht so aufwendig!";
			ausgabe(output);
			output = "Also zurrück im spiel:";
			ausgabe(output);
			output = "Der Schlüssel passt hier nicht! Versich es mal in der stadt! villeicht kann dir da jemand helfen!";
			ausgabe(output);
			Stadt = 1;
			repaint();
		}
		
	}
	if(Spielwege[a][b] == 3)
	{
		output = "IHHHH! Ein Müllhaufen! ";
		ausgabe(output);

		output = "Doch was ist das? Ein Schlüssel?";
		ausgabe(output);

		output = "villeicht kann ich den ja noch irgendwann gebrauchen!";
		ausgabe(output);
		
		schlüssel = 1;
		repaint();


		
	}
	if (Spielwege[a][b] == 5)
	{
		if (Stadt == 2)
		{
			output = "Hir geht es nur in die stadt!";
			ausgabe(output);

			repaint();
		}
		if(Stadt == 1)
		{
			output = "Auf geht es: In die Stadt!";
			ausgabe(output);

			map = "C:\\Users\\Ferdinand\\Desktop\\spiel\\res\\maps\\level2.txt";
			weg = "C:\\Users\\Ferdinand\\Desktop\\spiel\\res\\maps\\level2begehbar.txt";

			wegreader();

			mapreader();

			spielfigursuchen();

			repaint();
		}
	}
	else if(Spielwege[a][b] == 4)
	{
		output = "Hir geht es nach Hause";
		ausgabe(output);

		map = "C:\\Users\\Ferdinand\\Desktop\\spiel\\res\\maps\\level1.txt";
		weg = "C:\\Users\\Ferdinand\\Desktop\\spiel\\res\\maps\\level1begehbar.txt";

		wegreader();

		mapreader();

		spielfigursuchen();

		repaint();
	}

	else if (Spielwege[a][b] == 0)
	{
		output = "Hier habe ich nichts gefunden!";
		ausgabe(output);
		repaint();
	}
	

	return(0);
}
int inventar() {

	output = " ";

	if (schlüssel == 1)
	{
		output = output + "1 X Ominöser Schlüssel";
	}
	else {
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << "Inventar" << endl << endl << endl << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << output << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
	string stop;
	cin >> stop;
	repaint();

	return(0);
}