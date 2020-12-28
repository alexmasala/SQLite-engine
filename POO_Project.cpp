#include <iostream>
#include <string>
#include "Classes.h"
using namespace std;

int main()
{
	//TO-DO

	//-----------COLUMN-------------
	//ctors
	Column c1;
	Column c2("nume","text",200,"anonim");
	Column c3("oras","text",100,"unknown",false);
	////ctor de copiere
	Column c4(c3);
	//op egal
	Column c5;
	c5 = c4;
	cout << c5 << endl;
	//citire si afisare la consola
	Column c6;
	//cin >> c6;
	//cout << c6;
	//verificare getteri si setteri
	c6.setDenumire("nume");
	c6.setDimensiune(22);
	c6.setTip("Text");
	c6.setValoareImplicita("Maria");
	c6.setNullable(true);
	cout << c6.getIdColoana() << " " << c6.getDenumire() << " " << c6.getDimensiune() << " " << c6.getTip() << " " << c6.getValoareImplicita() << " " << c6.getNullable() << endl;
	//verificare operatori
	cout << "operator !: " << !c5 << endl;
	bool test = c3 < c2;
	cout << test << endl;
	bool same = c3 == c2;
	cout << same << endl;
	string type = (string)c3;
	cout << type <<endl;

	cout << c5.getDimensiune() << endl;
	cout << c6 << endl;
	c6 = ++c5;
	cout << c6 << endl;
	c6 = c6 + 5;
	cout << c6 << endl;

	//-----tabela-------
	Column cl1("nume", "text", 200, "necunoscut");
	Column cl2("varsta", "number", 100, "0");
	Column* columnsArray = new Column[2]{ cl1,cl2 };
	//verif constructori
	Table table1;
	Table table2("Studenti", 2, columnsArray);
	Table table3("Animale");
	cout << "nr tabele: " << table1.getNrTabele() << endl;
	//constr de copiere
	Table table4(table2);
	//op egal
	Table table5;
	table5 = table2;
	//afisiare si citire de la consola
	Table table6;
	//cin >> table6;
	//cout << table6;

	//getteri si setteri
	table6.setNumeTabela("Elevi");
	table6.setColumns(columnsArray, 2);
	cout << " ---------------------------------------------------------- ";
	cout << table6.getIdTabela() << " " << table6.getNrColoane() << " " << table6.getColumn(0) << table6.getColumn(1);

	//operatori
	cout << "op !: " << !table4 << endl;
	bool same2 = table2 == table3;
	cout << "op ==: " << same2 <<endl;
	cout << "op cast: " << (int)table2 << endl; 

	Column cl3("Descriere", "text", 300, "not completed");
	Table table8;
	
	cout << "table 2: " << endl;
	cout << table2.operator+(cl3);

	cout << "operator []: " << endl;
	cout << table2[1];
	
	bool greater = table4 > table1;
	cout << "operator >: " << greater << endl;

	cout << " ---------------------------------------------------------------------- ";
	cout << endl << endl;

	Table* tablesArray = new Table[2]{ table2, table6 };
	Database db1(200, "DB1", 2, tablesArray);
	//Database db2(db1);
	//db2 = db1;
	Database db2;
	/*cin >> db2;
	cout << db2;*/
	db2.setNumeDB("DBTest2");
	db2.setTables(tablesArray, 2);
	/*cout << db2.getNumeDB() << " ";
	cout << db2.getTable(0) << " ";
	cout << db2.getTable(1) << " ";*/
	cout << "op !: " << !db2 << endl;
	bool same3 = db1 == db2;
	cout << "op ==: " << same3 << endl;
	cout << "op cast: " << (int)db2 << endl;

}