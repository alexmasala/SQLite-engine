#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Column
{
	const int idColoana;
	char* denumire;
	string tip;
	int dimensiune;
	char* valoareImplicita;
	bool isNullable;
	static int nrColoane;

	//interfata publica
public:
	Column() :idColoana(nrColoane+=1)
	{
		this->denumire = nullptr;
		this->tip = "";
		this->valoareImplicita = nullptr;
		this->dimensiune = 0;
		this->isNullable = false;
	}
	Column(const char* denumire, string tip, int dimensiune, const char* valImplicita, bool nullable) :idColoana(nrColoane+=1)
	{
		this->denumire = new char[strlen(denumire) + 1];
		strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
		if (tip.length() > 0)
		{
			this->tip = tip;
		}
		if (dimensiune > 0)
		{
			this->dimensiune = dimensiune;
		}
		this->valoareImplicita = new char[strlen(valImplicita) + 1];
		strcpy_s(this->valoareImplicita, strlen(valImplicita) + 1, valImplicita);
		this->isNullable = nullable;
	}
	Column(const char* denumire, string tip, int dimensiune, const char* valImplicita) :idColoana(nrColoane+=1)
	{
		this->denumire = new char[strlen(denumire) + 1];
		strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
		if (tip.length() > 0)
		{
			this->tip = tip;
		}
		else
		{
			this->tip = "";
		}
		if (dimensiune > 0)
		{
			this->dimensiune = dimensiune;
		}
		else
		{
			this->dimensiune = 0;
		}
		this->valoareImplicita = new char[strlen(valImplicita) + 1];
		strcpy_s(this->valoareImplicita, strlen(valImplicita) + 1, valImplicita);
		this->isNullable = false;
	}
	Column(const Column& c) :idColoana(c.idColoana)
	{
		if (c.denumire != nullptr)
		{
			this->denumire = new char[strlen(c.denumire) + 1];
			strcpy_s(this->denumire, strlen(c.denumire) + 1, c.denumire);
		}
		else
		{
			this->denumire = nullptr;
		}
		this->tip = c.tip;
		this->dimensiune = c.dimensiune;
		if (c.valoareImplicita != nullptr)
		{
			this->valoareImplicita = new char[strlen(c.valoareImplicita) + 1];
			strcpy_s(this->valoareImplicita, strlen(c.valoareImplicita) + 1, c.valoareImplicita);
		}
		else
		{
			this->valoareImplicita = nullptr;
		}
		this->isNullable = c.isNullable;

	}
	Column& operator=(const Column& c)
	{
		delete[] this->denumire;
		delete[] this->valoareImplicita;
		if (c.denumire != nullptr)
		{
			this->denumire = new char[strlen(c.denumire) + 1];
			strcpy_s(this->denumire, strlen(c.denumire) + 1, c.denumire);
		}
		else
		{
			this->denumire = nullptr;
		}
		this->tip = c.tip;
		this->dimensiune = c.dimensiune;
		if (c.valoareImplicita != nullptr)
		{
			this->valoareImplicita = new char[strlen(c.valoareImplicita) + 1];
			strcpy_s(this->valoareImplicita, strlen(c.valoareImplicita) + 1, c.valoareImplicita);
		}
		else
		{
			this->valoareImplicita = nullptr;
		}
		this->isNullable = c.isNullable;

		return *this;
	}
	int getIdColoana()
	{
		return this->idColoana;
	}
	char* getDenumire()
	{
		if (denumire != nullptr)
		{
			char* copieDen = new char[strlen(denumire) + 1];
			strcpy_s(copieDen, strlen(denumire) + 1, denumire);
			return copieDen;
		}
		else
		{
			return nullptr;
		}
	}
	string getTip()
	{
		return this->tip;
	}
	int getDimensiune()
	{
		return this->dimensiune;
	}
	char* getValoareImplicita()
	{
		if (valoareImplicita != nullptr)
		{
			char* copieVal = new char[strlen(valoareImplicita) + 1];
			strcpy_s(copieVal, strlen(valoareImplicita) + 1, valoareImplicita);
			return copieVal;
		}
		else
		{
			return nullptr;
		}
	}
	bool getNullable()
	{
		return this->isNullable;
	}
	static int getNrColoane()
	{
		return Column::nrColoane;
	}
	void setDenumire(const char* denumire)
	{
		if (this->denumire != nullptr)
		{
			delete[] this->denumire;
		}
		this->denumire = new char[strlen(denumire) + 1];
		strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
	}
	void setTip(string tip)
	{
		if (tip.length() > 0)
		{
			this->tip = tip;
		}
	}
	void setDimensiune(int dimensiune)
	{
		if (dimensiune > 0)
		{
			this->dimensiune = dimensiune;
		}
		else
		{
			this->dimensiune = 0;
		}
	}
	void setValoareImplicita(const char* valoare)
	{
		if (this->valoareImplicita != nullptr)
		{
			delete[] this->valoareImplicita;
		}
		this->valoareImplicita = new char[strlen(valoare) + 1];
		strcpy_s(this->valoareImplicita, strlen(valoare) + 1, valoare);
	}
	void setNullable(int isNullable)
	{
		this->isNullable = isNullable;
	}

	//supraincarcari
	bool operator!()
	{
		return dimensiune == 0;
	}
	bool operator<(Column& c)
	{
		bool less = false;
		if (this->dimensiune < c.dimensiune)
		{
			less = true;
		}
		return less;
	}
	bool operator==(Column& c)
	{
		bool same = false;
		if (strcmp(this->denumire, c.denumire) == 0)
		{
			same = true;
		}
		return same;
	}
	explicit operator string()
	{
		return this->tip;
	}
	Column operator++()
	{
		this->dimensiune++;
		return *this;
	}
	Column operator++(int i)
	{
		Column copy = *this;
		this->dimensiune++;
		return copy;
	}
	Column operator+(int val)
	{
		Column copy = *this;
		copy.dimensiune += val;
		return copy;
	}

	friend ostream& operator<<(ostream&, Column);
	friend istream& operator>>(istream& input, Column& c);
};

int Column::nrColoane = 0;

ostream& operator<<(ostream& consola, Column c)
{
	cout << "Denumire: ";
	if (c.denumire != nullptr)
	{
		consola << c.denumire << endl;
	}
	cout << "Tip: ";
	consola << c.tip << endl;
	cout << "Dimensiune: ";
	consola << c.dimensiune << endl;
	cout << "Valoare implicita: ";
	if (c.valoareImplicita != nullptr)
	{
		consola << c.valoareImplicita << endl;
	}
	cout << "Nullable? 1-da, 0-nu:   ";
	consola << c.isNullable << endl;
	return consola;
}

istream& operator>>(istream& input, Column& c)
{
	if (c.denumire != nullptr)
	{
		delete[] c.denumire;
	}
	if (c.valoareImplicita != nullptr)
	{
		delete[] c.valoareImplicita;
	}
	cout << "Denumire coloana: ";
	input >> ws;
	char buffer[100];
	input.getline(buffer, 101);
	c.denumire = new char[strlen(buffer) + 1];
	strcpy_s(c.denumire, strlen(buffer) + 1, buffer);
	cout << "Tip coloana: ";
	input >> ws;
	input.getline(buffer, 101);
	c.tip = buffer;
	cout << "Dimensiune coloana: ";
	input >> c.dimensiune;
	cout << "Valoare implicita: ";
	input >> ws;
	input.getline(buffer, 101);
	c.valoareImplicita = new char[strlen(buffer) + 1];
	strcpy_s(c.valoareImplicita, strlen(buffer) + 1, buffer);
	bool optional;
	cout << "Nullable? 1-da, 0-nu:  " << endl;
	input >> optional;
	if (optional == 1)
	{
		c.isNullable = true;
	}
	else
	{
		c.isNullable = false;
	}
	return input;
}

Column operator+(int v, Column c)
{
	int d = c.getDimensiune();
	d += v;
	c.setDimensiune(d);
	return c;
}

class Table
{
	const int idTabela;
	char* nume = NULL;
	int nrColoane;
	Column* columns = nullptr;
	static char descriere[200];
	static int nrMaximColoane;
	static int nr_Tabele;

public:
	Table() :idTabela(++nr_Tabele)
	{
		this->nume = nullptr;
		this->nrColoane = 0;
		this->columns = nullptr;
	}
	Table(const char* nume, int nrColoane, Column* columns) :idTabela(++nr_Tabele)
	{
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);
		if (columns != nullptr && nrColoane > 0)
		{
			this->nrColoane = nrColoane;
			this->columns = new Column[nrColoane];
			for (int i = 0; i < nrColoane; i++)
			{
				this->columns[i] = columns[i];
			}
		}
		else
		{
			this->nrColoane = 0;
			this->columns = nullptr;
		}
	}
	Table(const char* nume) :idTabela(++nr_Tabele)
	{
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);
		this->nrColoane = 0;
		this->columns = nullptr;
	}
	Table(const Table& t) :idTabela(++nr_Tabele)
	{
		if (t.nume != nullptr)
		{
			this->nume = new char[strlen(t.nume) + 1];
			strcpy_s(this->nume, strlen(t.nume) + 1, t.nume);
		}
		else
		{
			this->nume = nullptr;
		}
		if (t.columns != nullptr && t.nrColoane != 0)
		{
			this->nrColoane = t.nrColoane;
			this->columns = new Column[t.nrColoane];
			for (int i = 0; i < t.nrColoane; i++)
			{
				this->columns[i] = t.columns[i];
			}
		}
		else
		{
			this->nrColoane = 0;
			this->columns = nullptr;
		}
	}
	~Table()
	{
		if (nume != nullptr)
		{
			delete[] nume;
		}
		if (columns != nullptr)
		{
			delete[] columns;
		}
	}
	Table& operator=(Table& t)
	{
		if (this->nume != nullptr)
		{
			delete[] nume;
		}
		if (this->columns != nullptr)
		{
			delete[] columns;
		}
		if (t.nume != nullptr)
		{
			this->nume = new char[strlen(t.nume) + 1];
			strcpy_s(this->nume, strlen(t.nume) + 1, t.nume);
		}
		else
		{
			this->nume = nullptr;
		}
		if (t.columns != nullptr && t.nrColoane != 0)
		{
			this->nrColoane = t.nrColoane;
			this->columns = new Column[t.nrColoane];
			for (int i = 0; i < t.nrColoane; i++)
			{
				this->columns[i] = t.columns[i];
			}
		}
		else
		{
			this->nrColoane = 0;
			this->columns = nullptr;
		}
		return *this;
	}
	//getters & setters
	int getIdTabela() //const => doar get
	{
		return this->idTabela;
	}
	const char* getNumeTabela()
	{
			return this->nume;
	}
	void setNumeTabela(const char* n)
	{
		if (this->nume != nullptr)
		{
			delete[] this->nume;
		}
		this->nume = new char[strlen(n) + 1];
		strcpy_s(this->nume, strlen(n) + 1, n);
	}

	void setNumeTabela_Comenzi(const char* n)
	{
		this->nume = new char[strlen(n) + 1];
		strcpy_s(this->nume, strlen(n) + 1, n);
	}

	int getNrColoane()
	{
		return this->nrColoane;
	}
	void setColumns(Column* c, int nr)
	{
		if (c != nullptr && nr != 0)
		{
			this->nrColoane = nr;
			if (this->columns != nullptr)
			{
				delete[] this->columns;
			}
			this->columns = new Column[nr];
			for (int i = 0; i < nr; i++)
			{
				this->columns[i] = c[i];
			}
		}
		else
		{
			this->nrColoane = 0;
			this->columns = nullptr;
		}
	}
	Column* getColumns()
	{
		return this->columns;
	}
	Column getColumn(int poz)
	{
		if (poz >= 0 && poz < this->nrColoane)
		{
			return this->columns[poz];
		}
	}
	static int getNrTabele()
	{
		return nr_Tabele;
	}
	static int getNrMaximColoane()
	{
		return nrMaximColoane;
	}
	static void setNrMaximColoane(int i)
	{
		if (i <= 20)
		{
			Table::nrMaximColoane = i;
		}
		else
		{
			Table::nrMaximColoane = 20;
		}
	}
	//supraincarcari
	explicit operator int()
	{
		return this->nrColoane;
	}
	bool operator!()
	{
		return columns == nullptr;
	}
	bool operator==(Table& t)
	{
		if (strcmp(this->nume, t.nume) == 0)
			return true;
		else
			return false;
	}

	Table operator+(Column c)
	{
		Table t = *this;
		Column* aux = new Column[t.nrColoane + 1];
		for (int i = 0; i < t.nrColoane; i++)
		{
			aux[i] = t.columns[i];
		}
		aux[t.nrColoane] = c;
		t.nrColoane++;
		if (t.columns != nullptr) {
			delete[] t.columns;
		}
		t.columns = aux;
		return t;
	}
	Column operator[](int index)
	{
		if (index >= 0 && index < this->nrColoane)
		{
			return columns[index];
		}
	}
	Table operator++(int i)
	{
		this->setNrMaximColoane(i);
		return *this;
	}
	friend Table operator++(Table& t, int i)
	{
		Table t1 = t;
		t1.setNrMaximColoane(i);
		return t1;
	}
	bool operator>(Table& t)
	{
		if (this->getNrColoane() > t.getNrColoane())
			return true;
		else
			return false;
	}
	friend ostream& operator<<(ostream&, Table);
	friend istream& operator>>(istream&, Table&);
};

int Table::nr_Tabele = 0;
int Table::nrMaximColoane = 20;
char Table::descriere[200] = "Tables are database objects that contain all the data in a database. In tables, data is logically organized in a row-and-column format similar to a spreadsheet.";


ostream& operator<<(ostream& o, Table t)
{
	cout << "Nume tabela: ";
	o << t.nume << endl;
	cout << "Nr coloane: ";
	o << t.nrColoane << endl;
	cout << "Coloane: " << endl;
	for (int i = 0; i < t.nrColoane; i++)
	{
		o << "Denumire coloana: " << t.columns[i].getDenumire() << " | " <<
			"Dimensiune: " << t.columns[i].getDimensiune() << " | " <<
			"Tip: " << t.columns[i].getTip() << " | " <<
			"Valoare default: " << t.columns[i].getValoareImplicita() << endl;
	}
	return o;
}

istream& operator>>(istream& in, Table& t)
{
	cout << "Numele tabelei: ";
	char buffer[100];
	in.getline(buffer, 101);
	if (t.nume != nullptr)
	{
		delete[] t.nume;
	}
	t.nume = new char[strlen(buffer) + 1];
	strcpy_s(t.nume, strlen(buffer) + 1, buffer);
	if (t.columns)
	{
		delete[] t.columns;
	}
	cout << "Nr coloane: ";
	in >> t.nrColoane;
	t.columns = new Column[t.nrColoane];
	for (int i = 0; i < t.nrColoane; i++)
	{
		cout << "Coloana " << i + 1 << endl;
		in >> t.columns[i];
	}
	return in;
}

class Database
{
	const int capacitateDB;
	Table* tables;
	int nrTabele;
	char* numeDB;
	static char descriereDB[200];

public:
	Database() :capacitateDB(0)
	{
		this->tables = nullptr;
		this->nrTabele = 0;
		this->numeDB = nullptr;
	}
	Database(int cap, const char* n, int nr, Table* t) :capacitateDB(cap)
	{
		this->numeDB = new char[strlen(n) + 1];
		strcpy_s(this->numeDB, strlen(n) + 1, n);
		if (nr > 0)
		{
			this->nrTabele = nr;
		}
		this->tables = new Table[nr];
		for (int i = 0; i < nr; i++)
		{
			this->tables[i] = t[i];
		}
	}
	Database(int c, const char* n) :capacitateDB(0)
	{
		this->numeDB = new char[strlen(n) + 1];
		strcpy_s(this->numeDB, strlen(n) + 1, n);
		this->nrTabele = 0;
		this->numeDB = nullptr;
	}
	Database(const Database& db) :capacitateDB(db.capacitateDB)
	{
		if (db.numeDB != nullptr)
		{
			this->numeDB = new char[strlen(db.numeDB) + 1];
			strcpy_s(this->numeDB, strlen(db.numeDB) + 1, db.numeDB);
		}
		else
		{
			this->numeDB = nullptr;
		}
		if (db.tables != nullptr && db.nrTabele != 0)
		{
			this->nrTabele = db.nrTabele;
			this->tables = new Table[nrTabele];
			for (int i = 0; i < nrTabele; i++)
			{
				this->tables[i] = db.tables[i];
			}
		}
		else
		{
			this->tables = nullptr;
			this->nrTabele = 0;
		}
	}
	Database& operator=(const Database& db)
	{
		if (this->numeDB != nullptr)
		{
			delete[] this->numeDB;
		}
		if (this->tables != nullptr)
		{
			delete[] this->tables;
		}
		if (db.numeDB != nullptr)
		{
			this->numeDB = new char[strlen(db.numeDB) + 1];
			strcpy_s(this->numeDB, strlen(db.numeDB) + 1, db.numeDB);
		}
		else
		{
			this->numeDB = nullptr;
		}
		if (db.tables != nullptr && db.nrTabele != 0)
		{
			this->nrTabele = db.nrTabele;
			this->tables = new Table[nrTabele];
			for (int i = 0; i < nrTabele; i++)
			{
				this->tables[i] = db.tables[i];
			}
		}
		else
		{
			this->tables = nullptr;
			this->nrTabele = 0;
		}
		return *this;
	}
	~Database()
	{
		if (this->numeDB != nullptr)
		{
			delete[] this->numeDB;
		}
		if (this->tables != nullptr)
		{
			delete[] this->tables;
		}
	}
	string getDescriereDB()
	{
		string aux = Database::descriereDB;
		return aux;
	}
	int getCapacitateDB() //const => doar get
	{
		return this->capacitateDB;
	}
	const char* getNumeDB()
	{
		if (this->numeDB != nullptr)
		{
			char* copieNumeDB = new char[strlen(this->numeDB) + 1];
			strcpy_s(copieNumeDB, strlen(this->numeDB) + 1, this->numeDB);
			return copieNumeDB;
		}
		else
		{
			return nullptr;
		}
	}
	int getNrTabele()
	{
		return this->nrTabele;
	}
	Table* getTables()
	{
		return this->tables;
	}
	Table getTable(int poz)
	{
		if (poz >= 0 && poz < this->nrTabele)
		{
			return this->tables[poz];
		}
	}
	void setTables(Table* tb, int nr)
	{
		if (tb != nullptr && nr != 0)
		{
			this->nrTabele = nr;
			if (this->tables != nullptr)
			{
				delete[] this->tables;
			}
			this->tables = new Table[nr];
			for (int i = 0; i < nr; i++)
			{
				this->tables[i] = tb[i];
			}
		}
		else
		{
			this->nrTabele = 0;
			this->tables = nullptr;
		}
	}
	void setNumeDB(const char* numeDB)
	{
		if (this->numeDB != nullptr)
		{
			delete[] this->numeDB;
		}
		this->numeDB = new char[strlen(numeDB) + 1];
		strcpy_s(this->numeDB, strlen(numeDB) + 1, numeDB);
	}
	Table operator[](int index)
	{
		if (index >= 0 && index < this->nrTabele)
		{
			return this->tables[index];
		}
	}
	explicit operator int()
	{
		return this->nrTabele;
	}
	bool operator!()
	{
		return tables == nullptr;
	}
	bool operator==(Database& db)
	{
		if (strcmp(this->numeDB, db.numeDB) == 0)
			return true;
		else
			return false;
	}
	friend ostream& operator<<(ostream&, Database);
	friend istream& operator>>(istream&, Database&);
};

char Database::descriereDB[200] = "A database is an organized collection of structured information, or data, typically stored electronically in a computer system.";


ostream& operator<<(ostream& o, Database d)
{
	cout << "Nume baza de date: ";
	if (d.numeDB != nullptr)
	{
		o << d.numeDB << endl;
	}
	else
	{
		o << "No name!" << endl;
	}
	cout << "Nr tabele: ";
	o << d.nrTabele << endl;
	return o;
}

istream& operator>>(istream& in, Database& db)
{
	cout << "Numele tabelei: ";
	char buffer[100];
	in.getline(buffer, 101);
	if (db.numeDB != nullptr)
	{
		delete[] db.numeDB;
	}
	db.numeDB = new char[strlen(buffer) + 1];
	strcpy_s(db.numeDB, strlen(buffer) + 1, buffer);
	return in;
}

class Field
{
	string typeOfData;
	char* value;
	static char descriptionOfFields[200];
	bool isNull;
	
public:
	Field()
	{
		this->typeOfData = "";
		this->value = nullptr;
		this->isNull = 1;
	}
	Field(const char* value, string tod)
	{
		this->value = new char[strlen(value) + 1];
		strcpy_s(this->value, strlen(value) + 1, value);
		if (tod.length() > 0)
		{
			this->typeOfData = tod;
		}
		else
			this->typeOfData = "";
		if (this->value != nullptr)
		{
			this->isNull = 0;
		}
	}
	Field(const char* value)
	{
		this->value = new char[strlen(value) + 1];
		strcpy_s(this->value, strlen(value) + 1, value);
		this->typeOfData = "";
		if (this->value != nullptr)
		{
			this->isNull = 0;
		}
	}
	Field(const Field& f)
	{
		if (f.value != nullptr)
		{
			this->value = new char[strlen(f.value) + 1];
			strcpy_s(this->value, strlen(f.value) + 1, f.value);
		}
		else
		{
			this->value = nullptr;
		}
		this->isNull = f.isNull;
		this->typeOfData = f.typeOfData;
	}
	Field& operator=(const Field& f)
	{
		delete[] this->value;
		if (f.value != nullptr)
		{
			this->value = new char[strlen(f.value) + 1];
			strcpy_s(this->value, strlen(f.value) + 1, f.value);
		}
		else
		{
			this->value = nullptr;
		}
		this->isNull = f.isNull;
		this->typeOfData = f.typeOfData;
		return *this;
	}
	~Field()
	{
		if (this->value != nullptr)
		{
			delete[] this->value;
		}
	}
	string getFieldType()
	{
		return this->typeOfData;
	}
	bool getIsNull()
	{
		return this->isNull;
	}
	const char* getValue()
	{
		if (this->value != nullptr)
		{
			char* copieValue = new char[strlen(this->value) + 1];
			strcpy_s(copieValue, strlen(this->value) + 1, this->value);
			return copieValue;
		}
		else
		{
			return nullptr;
		}
	}
	void setFieldType(string t)
	{
		this->typeOfData = t;
	}
	void setIsNull(bool nl)
	{
		this->isNull = nl;
	}
	void setValue(const char* val)
	{
		if (this->value != nullptr)
		{
			delete[] this->value;
		}
		this->value = new char[strlen(val) + 1];
		strcpy_s(this->value, strlen(val) + 1, val);
	}
	static string getDescriptionOfFields()
	{
		string aux = descriptionOfFields;
		return aux;
	}
	//operatori
	explicit operator int()
	{
		return strlen(this->value);
	}
	bool operator==(Field f)
	{
		return this->value == f.value;
	}
	bool operator<(Field f)
	{
		if (strlen(this->value) < strlen(f.value))
		{
			return true;
		}
	}
	friend ostream& operator<<(ostream&, Field);
	friend istream& operator>>(istream&, Field&);
};

char Field::descriptionOfFields[200] = "A database field is a single piece of information from a record.";

ostream& operator<<(ostream& o, Field f)
{
	cout << "Value: ";
	if (f.value != nullptr)
	{
		o << f.value << endl;
	}
	else
	{
		o << "null" << endl;
	}
	cout << "Type of data: ";
	o << f.typeOfData << endl;
	cout << "is null? 0-nu, 1-da" << endl;
	o << f.isNull <<endl;
	return o;
}

istream& operator>>(istream& in, Field& f)
{
	cout << "Value: ";
	char buffer[100];
	in >> ws;
	in.getline(buffer, 101);
	if (f.value != nullptr)
	{
		delete[] f.value;
	}
	f.value = new char[strlen(buffer) + 1];
	strcpy_s(f.value, strlen(buffer) + 1, buffer);
	cout << "Type: ";
	in >> ws;
	in.getline(buffer, 101);
	f.typeOfData = buffer;
	if (f.value != nullptr)
	{
		f.isNull = 0;
	}
	return in;
}

class Row
{
	const int idRow;
	int noOfFields;
	Field* fields;
	static char descriptionOfRows[200];
	static int noOfRows;

public:
	Row():idRow(++noOfRows)
	{
		this->noOfFields = 0;
		this->fields = nullptr;
	}
	Row(int no, Field* fields):idRow(++noOfRows)
	{
		if (fields != nullptr && no != 0)
		{
			this->noOfFields = no;
			this->fields = new Field[no];
			for (int i = 0; i < no; i++)
			{
				this->fields[i] = fields[i];
			}
		}
		else
		{
			this->noOfFields = 0;
			this->fields = nullptr;
		}
	}
	Row(const Row& r):idRow(r.idRow)
	{
		if (r.fields != nullptr && r.noOfFields != 0)
		{
			this->noOfFields = r.noOfFields;
			this->fields = new Field[r.noOfFields];
			for (int i = 0; i < r.noOfFields; i++)
			{
				this->fields[i] = r.fields[i];
			}

		}
		else
		{
			this->fields = nullptr;
			this->noOfFields = 0;
		}
	}
	Row& operator=(const Row& r)
	{
		if (this->fields != nullptr)
		{
			delete[] this->fields;
		}
		if (r.fields != nullptr && r.noOfFields != 0)
		{
			this->noOfFields = r.noOfFields;
			this->fields = new Field[r.noOfFields];
			for (int i = 0; i < r.noOfFields; i++)
			{
				this->fields[i] = r.fields[i];
			}

		}
		else
		{
			this->fields = nullptr;
			this->noOfFields = 0;
		}
		return *this;
	}
	int getIdRow()
	{
		return this->idRow;
	}
	int getNoOfFields()
	{
		return this->noOfFields;
	}
	Field getField(int i)
	{
		return this->fields[i];
	}
	void setFields(Field* f, int nr)
	{
		if (f!= nullptr && nr != 0)
		{
			this->noOfFields = nr;
			if (this->fields != nullptr)
			{
				delete[] this->fields;
			}
			this->fields = new Field[nr];
			for (int i = 0; i < nr; i++)
			{
				this->fields[i] = f[i];
			}
		}
		else
		{
			this->noOfFields = 0;
			this->fields = nullptr;
		}
	}
	~Row()
	{
		if (this->fields != nullptr)
		{
			delete[] this->fields;
		}
	}
	//operators
	bool operator==(Row r)
	{
		if (this->noOfFields == r.noOfFields)
		{
			return true;
		}
	}
	bool operator>(Row r)
	{
		if (this->noOfFields > r.noOfFields)
		{
			return true;
		}
	}
	string operator[](int poz)
	{
		if (poz >= 0 && poz < this->noOfFields)
		{
			return this->fields[poz].getValue();
		}
	}
	explicit operator int() {
		return this->noOfFields;
	}
	friend ostream& operator<<(ostream&, Row);
	friend istream& operator>>(istream&, Row&);
};

char Row::descriptionOfRows[200] = "A database record is collection of fields about the same person, item, or object in a database";
int Row::noOfRows = 0;

ostream& operator<<(ostream& o, Row r)
{
	cout << "Row ";
	o << r.idRow << " ";
	cout << "Values: ";
	for (int i = 0; i < r.noOfFields; i++)
	{
		o << r.fields[i].getValue() << " ";
	}
	return o;
}

istream& operator>>(istream& in, Row& r)
{
	cout << "Introduceti valorile: ";
	if (r.fields)
	{
		delete[] r.fields;
	}
	cout << "Nr valori: ";
	in >> r.noOfFields;
	r.fields = new Field[r.noOfFields];
	for (int i = 0; i < r.noOfFields; i++)
	{
		cout << "Valoare " << i + 1 << endl;
		in >> r.fields[i];
	}
	return in;
}

class Commands {
	static string descriere_comenzi;
};

string Commands::descriere_comenzi = "SQL commands can be used to search the database and to do other functions like creating tables, adding data to tables, modifying data, and dropping tables.";

void create_tabela(const char* nume_tabela, Table* tabels, Column* c/*const char* nume_coloana, string tip_coloana, int dimensiune_coloana, const char* valImplicita*/)
{
	tabels->setNumeTabela(nume_tabela);
	tabels->getColumns()->setDenumire(c->getDenumire());
	tabels->getColumns()->setTip(c->getTip());
	tabels->getColumns()->setDimensiune(c->getDimensiune());
	tabels->getColumns()->setValoareImplicita(c->getValoareImplicita());
}

class Create_Command
{
private:
	Table* t;
public:
	Create_Command() {
		this->t = nullptr;
	}

	Create_Command(Table* t) {
		this->t = t;
	}

	Create_Command(const Create_Command& cc)
	{
		this->t = cc.t;
	}

	void setTable_Create(Table* t)
	{
		this->t = t;
	}

	Table* getTable_Create()
	{
		return this->t;
	}

	void create_tabela(Table* tabels)
	{
		this->t->setNumeTabela_Comenzi(tabels->getNumeTabela());
		this->t->getColumns()->setDenumire(tabels->getColumns()->getDenumire());
		this->t->getColumns()->setTip(tabels->getColumns()->getTip());
		this->t->getColumns()->setDimensiune(tabels->getColumns()->getDimensiune());
		this->t->getColumns()->setValoareImplicita(tabels->getColumns()->getValoareImplicita());
	}

	friend ostream& operator<<(ostream&, Create_Command);
};

ostream& operator<<(ostream& o, Create_Command cc)
{
	cout << "Nume tabela: ";
	o << cc.t->getNumeTabela() << endl;
	cout << "Nr coloane: ";
	o << cc.t->getColumns()->getNrColoane() << endl;
	cout << "Coloane: " << endl;
	for (int i = 0; i < cc.t->getNrColoane(); i++)
	{
		o << "Denumire coloana: " << cc.t->getColumns()[i].getDenumire() << " | " <<
			"Dimensiune: " << cc.t->getColumns()[i].getDimensiune() << " | " <<
			"Tip: " << cc.t->getColumns()[i].getTip() << " | " <<
			"Valoare default: " << cc.t->getColumns()[i].getValoareImplicita() << endl;
	}
	return o;
}

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

