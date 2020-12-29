#include <iostream>
#include <string>
#include "Classes.h"
using namespace std;

int main()
{
	//TO-DO

	//-----------COLUMN-------------
	//ctors
	cout << " -----------------------COLUMN--------------------------- " << endl;
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
	cin >> c6;
	cout << c6;
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

	cout << endl << endl;

	//-----tabela-------
	cout << " -----------------------TABLE--------------------------- " << endl;
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
	cin >> table6;
	cout << table6;

	//getteri si setteri
	table6.setNumeTabela("Elevi");
	table6.setColumns(columnsArray, 2);
	cout << table6.getIdTabela() << " " << table6.getNrColoane() << " " << table6.getColumn(0) << table6.getColumn(1)<<endl;

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

	cout << endl << endl;

	cout << " -----------------------DATABASE--------------------------- "<<endl;
	Table* tablesArray = new Table[2]{ table2, table6 };
	Database db1(200, "DB1", 2, tablesArray);
	/*Database db2(db1);
	db2 = db1;*/
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
	//cout<<table2.getNumeTabela() << endl;
	//table2.setNumeTabela("Farmacie");
	//cout << table2.getNumeTabela();

	cout << endl << endl;

	//-------------field---------------
cout << "-------------FIELD---------------"<<endl;
	Field f1;
	Field f2("Ana", "text");
	Field f3(f2);
	//f1 = f2;

	//cin >> f1;
	cout << f2;

	f1.setValue("Ioana");
	f1.setFieldType("Text");
	f1.setIsNull(0);
	cout << f1.getValue() << " " << f1.getFieldType() << " " << f1.getIsNull() << " ";
	int nrC = (int)f2;
	cout << "nr de caractere: " << nrC << endl;
	bool less2 = f2 < f1;
	cout << " op <: " << less2 << endl;
	bool same4 = f2 == f1;
	cout << " op ==: " << same4 << endl;

	Field f4("10", "text");

	Field* fieldsArray = new Field[3]{ f1,f2,f4 };
	Row r;
	Row r1(3, fieldsArray);
	//Row r2(r1);
	Row r2;
	r2 = r1;

	//cin >> r;
	//cout << r;
	//cout << r1;
	
	Row r3;
	r3.setFields(fieldsArray, 3);
	cout << r3.getNoOfFields() << " " << r3.getField(0) << " " << r3.getField(1) << " " << r3.getField(2);

	cout << r3[2] << endl;

	//COMMANDS
	cout << "------------------------COMMANDS----------------------"<<endl;
	char* nume_table2 = new char[strlen(table2.getNumeTabela()) + 1];
	strcpy_s(nume_table2, strlen(table2.getNumeTabela()) + 1, table2.getNumeTabela());
	create_tabela(nume_table2, &table2, &cl1);

	//CREATE
	Create_Command cc(&table2);
	cc.create_tabela(&table2);
	//DISPLAY
	cout << "DISPLAY TABLE"<<endl;
		cout << cc;

	delete[] nume_table2;
}