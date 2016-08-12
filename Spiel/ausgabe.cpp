#include "ausgabe.h"
#include <Windows.h>
using namespace std;
#include <iostream>
using namespace std;
#include <string>
using namespace std;

int ausgabe(string output) {

	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << output << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;

	string stop;
	cin >> stop;


	return(0);
}