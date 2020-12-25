#pragma once
#include <iostream>
#include <string>
using namespace std;

class ColumnLayout
{
	const int id;
	char* nume_coloana;
	static string tip_coloana;
	int* dimensiune_coloana;
	string valoare_implicita;
	//	string filtru; /*  yes/no  */
	//	int coloana_filtru; /*  id cu valoare - ex: pt SELECT(nume) FROM studenti WHERE id = 1 */
};

class Table
{
	char* nume_tabela;
	int* capacitate_tabela;
	//const int nrColoane;
	ColumnLayout* columns;
	static string sourceFile;
};

class Database
{
	Table* tables;
};

//coloana de tip integer
class IntegerColumn : public ColumnLayout
{
	int* celule_integer;
};

//coloana de tip float
class FloatColumn : public ColumnLayout
{
	float* celule_float;
};

//coloana de tip text
class TextColumn : public ColumnLayout
{
	char* celule_text;
};

