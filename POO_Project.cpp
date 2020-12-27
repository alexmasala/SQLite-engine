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

	ColumnLayout* obs= new ColumnLayout[2]{cl1,cl2};
	cout << obs[0]<<endl;
	cout << obs[1]<<endl;

	Table test("nume",11,obs);
	cout << test; 
	Table test1;
	cin >> test1;

	for (int i = 0; i < 2; i++)
		test.getColumnLayout()[i].getNumeColoana();

	Table t;
	t.setNumeTabela("Studenti");
	t.setCapacitateTabela(15);
	string str = (string)t;
	cout << str << endl;
	if (!t)
	cout << "Tabela " << t.getNumeTabela() << " nu are coloane!" << endl;
	
	Table t1;
	t1.setNumeTabela("Medicamente");
	t1.setCapacitateTabela(20);
	if (t1 > t)
		cout  << "Tabela " << t1.getNumeTabela() << " are o capacitate mai mare decat tabela " << t.getNumeTabela()<<endl;
	
	Table t2;
	t1.setNumeTabela("Studenti");
	if (t == t2)
		cout << "Tabelele au acelasi nume!" <<endl;
}