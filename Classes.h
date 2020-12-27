#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class ColumnLayout
{
	const int nrInregistrare;
	char* nume_coloana = NULL;
	char* tip_coloana = NULL;
	int* dimensiune_coloana = NULL;
	char* valoare_implicita = NULL;
	int is_nullable;
	int nrColoane = 0;
	static string descriere_coloana;
	int x; 

	//	string filtru; /*  yes/no  */
	//	int coloana_filtru; /*  id cu valoare - ex: pt SELECT(nume) FROM studenti WHERE id = 1 */

public:
	int getNrInregistrare() //nrInreg e const -> fara set()
	{
		return this->nrInregistrare;
	}

	char* getNumeColoana()
	{
		return this->nume_coloana;
	}
	void setNumeColoana(const char* nouNume_coloana)
	{

		if (this->nume_coloana != nullptr) {
			delete[] this->nume_coloana;
		}
		this->nume_coloana = new char[strlen(nouNume_coloana) + 1];
		strcpy_s(this->nume_coloana, strlen(nouNume_coloana) + 1, nouNume_coloana);
	}

	char* getTipColoana()
	{
		return this->tip_coloana;
	}

	void setTipColoana(const char* nouTip_coloana) 
	{
		if (this->tip_coloana != nullptr) {
			delete[] this->tip_coloana;
		}
		this->tip_coloana = new char[strlen(nouTip_coloana) + 1];
		strcpy_s(this->tip_coloana, strlen(nouTip_coloana) + 1, nouTip_coloana);
	}

	int* getDimensiuneColoana()
	{
		return this->dimensiune_coloana;
	}
	int getDimensiuneColoana(int i)
	{
		return dimensiune_coloana[i];
	}
	void setDimensiuneColoana(int* nouaDimensiune_coloana, int nouNrColoane)
	{

		if (this->dimensiune_coloana != nullptr) {
			delete[] this->dimensiune_coloana;
		}
		this->nrColoane = nouNrColoane;
		this->dimensiune_coloana = new int[nouNrColoane];

		for (int i = 0; i < nouNrColoane; i++) {
			this->dimensiune_coloana[i] = nouaDimensiune_coloana[i];
		}
	}

	char* getValoareImplicita()
	{
		return this->valoare_implicita;
	}

	void setValoareImplicita(const char* nouaValoare_implicita)
	{
		if (this->valoare_implicita != nullptr) {
			delete[] this->valoare_implicita;
		}
		this->valoare_implicita = new char[strlen(nouaValoare_implicita) + 1];
		strcpy_s(this->valoare_implicita, strlen(nouaValoare_implicita) + 1, nouaValoare_implicita);
	}

	int getIsNullable()
	{
		return this->is_nullable;
	}

	void setIsNullable(int is_nullable)
	{
		if(is_nullable == 0)
			this->is_nullable = is_nullable;
		else 
			this->is_nullable = 1;
	}

	int getNrColoane()
	{
		return this->nrColoane;
	}

	void setNrColoane(int nrColoane)
	{
			this->nrColoane = nrColoane;
	}

	static string getDescriereColoana()
	{
		return descriere_coloana;
	}

	static void setDescriereColoana(string descriere_coloana)
	{
		ColumnLayout::descriere_coloana = descriere_coloana;
	}

	void setX(int i) { x = i; }
	int getX() { return x; }

	ColumnLayout():nrInregistrare(1) {
		this->setNumeColoana("");
		this->setTipColoana("");
		this->setDimensiuneColoana(NULL,0);
		this->setValoareImplicita("");
		this->setIsNullable(0);
		this->setDescriereColoana("");
	}

	ColumnLayout(int nrInregistrare,const char* nume_coloana,const char* tip_coloana,int* dimensiune_coloana, int nrColoane,const char* valoare_implicita) :nrInregistrare(nrInregistrare) {
		this->setNumeColoana(nume_coloana);
		this->setNrColoane(nrColoane);
		this->setTipColoana(tip_coloana);
		this->setDimensiuneColoana(dimensiune_coloana, nrColoane);
		this->setValoareImplicita(valoare_implicita);
		this->setIsNullable(0);
		this->setDescriereColoana("");
	}

	ColumnLayout(const ColumnLayout& c) :nrInregistrare(c.nrInregistrare) {
		this->setNumeColoana(c.nume_coloana);
		this->setNrColoane(c.nrColoane);
		this->setTipColoana(c.tip_coloana);
		this->setDimensiuneColoana(c.dimensiune_coloana, c.nrColoane);
		this->setValoareImplicita(c.valoare_implicita);
	}

	~ColumnLayout()
	{
		if (nume_coloana != nullptr)
		{
			delete[] nume_coloana;
		}

		if (tip_coloana != nullptr)
		{
			delete[] tip_coloana;
		}

		if (dimensiune_coloana != nullptr)
		{
			delete[] dimensiune_coloana;
		}

		if (valoare_implicita != nullptr)
		{
			delete[] valoare_implicita;
		}
	}

	ColumnLayout& operator=(ColumnLayout& c)
	{
		this->setNumeColoana(c.nume_coloana);
		this->setNrColoane(c.nrColoane);
		this->setTipColoana(c.tip_coloana);
		this->setDimensiuneColoana(c.dimensiune_coloana, c.nrColoane);
		this->setValoareImplicita(c.valoare_implicita);
		return *this;
	}

	bool operator!()
	{
		return nrColoane > 0;
	}

	ColumnLayout operator++()
	{
		this->nrColoane++;
		return *this;
	}
	ColumnLayout operator++(int i)
	{
		ColumnLayout aux = *this;
		this->nrColoane++;
		return aux;
	}
	explicit operator int()
	{
		return nrInregistrare;
	}
	bool operator== (ColumnLayout& cl)
	{
		bool same = false;
		if (strcmp(this->nume_coloana, cl.nume_coloana) != 0)
		{
			same = true;
		}
		return same;
	}
	bool operator<(ColumnLayout& cl)
	{
		bool less = false;
		if (this->nrInregistrare < cl.nrInregistrare)
		{
			less = true;
		}
		return less;
	}

	friend istream& operator>>(istream&, ColumnLayout&);
	friend ostream& operator<<(ostream&, ColumnLayout);
};

string ColumnLayout::descriere_coloana = "In a relational database, a column is a set of data values of a particular simple type, one value for each row of the database.";

ostream& operator<<(ostream& out, ColumnLayout c)
{
	cout << "Nr inregistrare: ";
	out << c.getNrInregistrare() << endl;
	cout << "Numele tabelei: ";
	out << c.getNumeColoana() << endl;
	cout << "Nr. coloane: ";
	out << c.getNrColoane() << endl;
	cout << "Dimensiuni per coloana: ";
	for (int i = 0; i < c.getNrColoane(); i++)
	{
		out << c.getDimensiuneColoana(i) << " ";
	}
	out << endl;
	if (c.getNumeColoana() != nullptr)
	{
		for (int i = 0; i < c.getNrColoane(); i++)
		{
			out << c.getNumeColoana()[i] << " ";
		}
	}
	return out;
}

istream& operator>>(istream& in, ColumnLayout& c)
{
	cout << "Nume coloana: ";
	char input[100];
	in.getline(input, 101);
	c.nume_coloana = new char[strlen(input) + 1];
	strcpy_s(c.nume_coloana, strlen(input) + 1, input);
	cout << "Tip coloana: ";
	in.getline(input, 101);
	c.tip_coloana = new char[strlen(input) + 1];
	strcpy_s(c.tip_coloana, strlen(input) + 1, input);
	cout << "Valoare implicita: ";
	in.getline(input, 101);
	c.valoare_implicita = new char[strlen(input) + 1];
	strcpy_s(c.valoare_implicita, strlen(input) + 1, input);
	cout << "poate fi null: ";
	in >> c.is_nullable;
	cout << "nr coloane: ";
	in >> c.nrColoane;
	if (c.dimensiune_coloana != nullptr)
	{
		delete[] c.dimensiune_coloana;
	}
	if (c.nrColoane > 0)
	{
		c.dimensiune_coloana = new int[c.nrColoane];
		for (int i = 0; i < c.nrColoane; i++)
		{
			cout << "Dimensiune " << i + 1 << " ";
			in >> c.dimensiune_coloana[i];
		}
	}
	else
	{
		c.dimensiune_coloana = nullptr;
	}

	return in;
}

class Table
{
	char* nume_tabela = NULL;
	int capacitate_tabela;
//	int nrTotalColoane;
	ColumnLayout* columns = nullptr;
	static string descriere_tabela;

public:
	const char* getNumeTabela()
	{
		return this->nume_tabela;
	}
	void setNumeTabela(const char* nouNume_tabela)
	{

		if (this->nume_tabela != nullptr) {
			delete[] this->nume_tabela;
		}
		this->nume_tabela = new char[strlen(nouNume_tabela) + 1];
		strcpy_s(this->nume_tabela, strlen(nouNume_tabela) + 1, nouNume_tabela);
	}

	int getCapacitateTabela()
	{
		return this->capacitate_tabela;
	}

	void setCapacitateTabela(int capacitate_tabela)
	{
		this->capacitate_tabela = capacitate_tabela;
	}

	/*int getNrTotalColoane()
	{
		return this->nrTotalColoane;
	}

	void setNrTotalColoane(ColumnLayout* c)
	{
		this->nrTotalColoane = c->getNrColoane();
	}*/

	ColumnLayout* getColumnLayout()
	{
		return this->columns;
	}

	ColumnLayout getColumnLayout(int i)
	{
		return columns[i];

		// return dimensiune_coloana[i];
	}

	void setColumnLayout(ColumnLayout* c)
	{
		
		this->columns = c;
		//c->setNumeColoana(NULL);

		
	}

	//void setColumnLayout(ColumnLayout* c)
	//{
	//	if (c != nullptr) {
	//		delete[] c;
	//	}
	//	std::vector<ColumnLayout> v;

	//	c = new ColumnLayout[this->getNrTotalColoane()];
	//	for (int i = 0; i < this->getNrTotalColoane(); i++)
	//		v.push_back(*c);

	//	//this->columns = c;

	//	//if (this->columns != nullptr) {
	//	//	delete[] this->columns;
	//	//}
	//	////this->columns->setNrColoane(c->getNrColoane());

	//	//this->columns = new ColumnLayout[c->getNrColoane()];
	//	//for (int i = 0; i < c->getNrColoane(); i++)
	//	//this->columns[i] = c[i];
	//}

	static string getDescriereTabela()
	{
		return descriere_tabela;
	}

	static void setDescriereTabela(string descriere_tabela)
	{
		Table::descriere_tabela = descriere_tabela;
	}

	Table() 
	{
		this->setNumeTabela("");
		this->setCapacitateTabela(0);
		this->setColumnLayout(nullptr);
	}

	Table(const char* nume_tabela, int capacitate_tabela, ColumnLayout* columns) 
	{
		this->setNumeTabela(nume_tabela);
		this->setCapacitateTabela(capacitate_tabela);
		this->setColumnLayout(columns);
	}
	
	Table(const Table& t)
	{
		this->setNumeTabela(t.nume_tabela);
		this->setCapacitateTabela(t.capacitate_tabela);
		this->setColumnLayout(t.columns);
		this->setDescriereTabela(t.descriere_tabela);
	}
	
	~Table()
	{
		if (nume_tabela != nullptr)
		{
			delete[] nume_tabela;
		}

		/*if (columns != nullptr)
		{
			delete[] columns;
		}*/
	}

	Table& operator=(Table& t)
	{
		this->setNumeTabela(t.nume_tabela);
		this->setCapacitateTabela(t.capacitate_tabela);
		this->setColumnLayout(t.columns);
		this->setDescriereTabela(t.descriere_tabela);
		return *this;
	}

	explicit operator string()
	{
		return descriere_tabela;
	}

	//--pre
	Table operator--()
	{
		this->capacitate_tabela--;
		return *this;
	}

	//--post
	friend Table operator--(Table& t, int);

	bool operator!()
	{
		return columns == nullptr;
	}

	bool operator>(Table& t)
	{
		if (this->getCapacitateTabela() > t.getCapacitateTabela())
			return true;
		else
			return false;
	}

	bool operator==(Table& t)
	{
		if(strcmp(this->getNumeTabela(), t.getNumeTabela()) != 0)
			return true;
		else
			return false;
	}

	friend istream& operator>>(istream&, Table&);
	friend ostream& operator<<(ostream&, Table);
};

string Table::descriere_tabela = "Tables are database objects that contain all the data in a database. In tables, data is logically organized in a row-and-column format similar to a spreadsheet.";

//overloading operator--
Table operator--(Table& t1, int)
{
	Table table = t1;
	t1.capacitate_tabela = t1.capacitate_tabela--;
	return t1;
}

ostream& operator<<(ostream& out, Table t)
{
	cout << "Numele tabelei: ";
	out << t.getNumeTabela() << endl;
	cout << "Capacitate: ";
	out << t.getCapacitateTabela() << endl;
	cout << "Nr. coloane: ";
	out << t.getColumnLayout()->getNrColoane() << endl;
	cout << "Coloane: " << endl;

	// EXCEPTION IS THROWN
	/*cout << "Nume per coloana: " << endl;
	for (int i = 0; i < t.getColumnLayout()->getNrColoane(); i++)
	{
		out << t.getColumnLayout()[i].getNumeColoana() << " ";
	}*/

	// EXCEPTION IS THROWN
	/*cout << "Nume per coloana: " << endl;
	for (int i = 0; i < t.getColumnLayout()->getNrColoane(); i++)
	{
		out << t.getColumnLayout()[i].getNumeColoana() << " ";
	}*/

	cout << "Dimensiune per coloana: " << endl;
	for (int i = 0; i < t.getColumnLayout()->getNrColoane(); i++)
	{
		out << t.getColumnLayout()->getDimensiuneColoana()[i] << " ";
	}

	out << endl;

	return out;
}

istream& operator>>(istream& in, Table& t)
{
	cout << "Numele tabelei: ";
	char input[100];
	in.getline(input, 101);
	t.nume_tabela = new char[strlen(input) + 1];
	strcpy_s(t.nume_tabela, strlen(input) + 1, input);
	cout << "Capacitate: ";
	in >> t.capacitate_tabela;
	return in;
}


class Database
{
	const int capacitate_DB;
	Table* tables;
	char* DB_nume;
	static string descriere_DB;
};

string Database::descriere_DB = "A database is an organized collection of structured information, or data, typically stored electronically in a computer system.";


class Commands {
	static string descriere_comenzi;
};

string Commands::descriere_comenzi = "SQL commands can be used to search the database and to do other functions like creating tables, adding data to tables, modifying data, and dropping tables.";

class Select_Command {};
class Insert_Command {};
class Delete_Command {};
class Update_Command {};


////coloana de tip integer
//class IntegerColumn : public ColumnLayout
//{
//	int* celule_integer;
//};
//
////coloana de tip float
//class FloatColumn : public ColumnLayout
//{
//	float* celule_float;
//};
//
////coloana de tip text
//class TextColumn : public ColumnLayout
//{
//	char* celule_text;
//};

