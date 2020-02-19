#pragma once

#include <iostream>
#include <stdio.h>
#include<stdlib.h>
#include <conio.h>
#include<windows.h>
#include <fstream>
#include <string>
#include <msxml.h>

using namespace std;

void gotoxy4(short x, short y) {
	COORD pos;
	pos.X = x;
	pos.Y = y;
	HANDLE H;
	H = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleCursorPosition(H, pos);
}


class Nodo
{
private:
	Nodo* Primero;
	Nodo* Ultimo;

public:
	Nodo* siguiente;
	string Letra;
	string remplazo;
	Nodo();
	Nodo(string Letra,string remplazo);
	Nodo(char Letra[]);

	void Ver();
	void Agregar(string Letra,string remplazo);
	void Grafo();
	void Guardar();
	void Buscar(char B[], char Remplazo[]);
	void Remplazar(Nodo* Actual, Nodo* aux, char R[]);
	inline Nodo* getUltimo() {
		return this->Ultimo;

	};
	inline Nodo* getPrimero() {
		return this->Primero;
	};
};


	
Nodo::Nodo() {

	siguiente = NULL;
	Letra = ' ';
	Primero = NULL;
	remplazo = ' ';
	Ultimo = NULL;
}
Nodo::Nodo(string L,string r) {
	Letra = L;
	remplazo = r;

	siguiente = NULL;
}
void Nodo:: Agregar(string p,string remplazo) {
	Nodo* nuevoNodo = new Nodo(p,remplazo);

	if (this->Primero == NULL) {

		this->Primero = nuevoNodo;
		this->Primero->siguiente = NULL;
		this->Ultimo = nuevoNodo;

	}
	else if (this->Primero != NULL) {
		this->Ultimo->siguiente = nuevoNodo;
		nuevoNodo->siguiente = NULL;
		this->Ultimo = nuevoNodo;
	}

}

void Nodo::Grafo() {
	Nodo* actual = this->Primero;
	ofstream ar;

	ar.open("ReporteOrden.txt", ios::out);

	if (ar.fail())
	{
		cout << "F";

	}

	ar << "digraph G{ \n"

		<< "  	rankdir = LR;  \n"
		<< "style = filled;\n"
		<< "		color = lightgrey;\n"
		<< "	node[style = filled,color= darkkhaki, shape=box3d];\n";
	do {
		ar << "Nodo" << &*actual << "[ label = \"" << actual->Letra <<" "<< "remplazada por--	" << actual->remplazo << "\" ];\n";

		if (actual->siguiente) {
			ar << "Nodo" << &*actual << "->";
			ar << "Nodo" << &*actual->siguiente << ";";

		}
		actual = actual->siguiente;

	} while (actual != NULL);
	ar << "\n" << "label = " << "ListadePalabras \n"
		<< "	;\n \n }";


	ar.close();
	char Dot[] = "dot -Tjpg ReporteOrden.txt -o ReporteOrden.jpg";
	system(Dot);

}


