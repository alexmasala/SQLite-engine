#pragma once
#include <iostream>
#include <string>
using namespace std;

class ColumnLayout
{
	const int nrInregistrare;
	char* nume_coloana;
	char* tip_coloana;
	int* dimensiune_coloana;
	char* valoare_implicita;
	int is_nullable;
	int nrColoane;
	static string descriere_coloana;

	//	string filtru; /*  yes/no  */
	//	int coloana_filtru; /*  id cu valoare - ex: pt SELECT(nume) FROM studenti WHERE id = 1 */

public:
	int getIdnrInregistrare() //id e const -> fara set()
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

	static string getDescriereColoana()
	{
		return descriere_coloana;
	}

	static void setDescriereColoana(string descriere_coloana)
	{
		ColumnLayout::descriere_coloana = descriere_coloana;
	}

	ColumnLayout():nrInregistrare(1) {
		this->setNumeColoana("");
		this->setTipColoana("");;
		this->setDimensiuneColoana(NULL,0);
		this->setValoareImplicita("");
		this->setIsNullable(0);
		this->setDescriereColoana("");;
	}

	ColumnLayout(int nrInregistrare, char* nume_coloana, char* tip_coloana,int* dimensiune_coloana, int nrColoane, char* valoare_implicita) :nrInregistrare(nrInregistrare) {
		this->setNumeColoana(nume_coloana);
		this->setTipColoana(tip_coloana);
		this->setDimensiuneColoana(dimensiune_coloana, nrColoane);
		this->setValoareImplicita(valoare_implicita);
		/*this->setIsNullable(0);
		this->setDescriereColoana("");;*/
	}

};

class Table
{
	char* nume_tabela;
	const int capacitate_tabela;
	//const int nrColoane;
	ColumnLayout* columns;
	static string descriere_tabela;
};

class Database
{
	const int capacitate_DB;
	Table* tables;
	char* DB_nume;
	static string descriere_DB;
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

