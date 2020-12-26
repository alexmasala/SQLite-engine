#include <iostream>
#include <string>
#include "Classes.h"
using namespace std;

int main()
{
	//TO-DO
	ColumnLayout column;

	//cout << column;


	//ColumnLayout column;
	int* c1 = new int[3]{ 1,2,3 };
	ColumnLayout cl1(2, "nume", "text", c1, 3, "necunoscut");
	int* c2 = new int[2]{ 3,2 };
	ColumnLayout cl2(3, "varsta", "number", c2, 2, "0");


	cout << !cl1 << endl;
	bool x = cl1 < cl2;
	cout << x << endl;
	bool s = cl1 == cl2;
	cout << s << endl;
	int nr = (int)cl1;
	cout << nr << endl;
	ColumnLayout coloana = ++column;
	cout << coloana.getNrColoane() <<endl;

	ColumnLayout cl4;
	cin >> cl4;
	cout << cl4;
	cout << column;
}