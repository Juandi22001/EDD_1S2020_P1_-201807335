#pragma once
#include <iostream>
#include <stdio.h>
#include<stdlib.h>
#include <conio.h>
#include<windows.h>
#include <fstream>
#include "Texto.h"

#include <fstream>
#include <string.h>
#include <string>
#define C 39
using namespace std;
class Archivo
{
private:
	Archivo* Primero;
	Archivo* Ultimo;

public:
	Archivo* siguiente;
	Archivo* anterior;
string  Letra;
	string Nombre;
	Archivo* Letras;
	Archivo();
	void Ver();

	Archivo(string Nombre,string Letra);
	void VerL(string Ruta);
	void Agregar(string Nombre,string Letra);
	void Grafo();

};
Texto texto;
Archivo::Archivo() {
	anterior = NULL;
	siguiente = NULL;
	Letra = ' ';
	Primero = NULL;
	Ultimo = NULL;
	Nombre = ' ';
}
void Archivo::Ver()
{
	Archivo* actual = this->Primero;
	if (this->Primero != NULL)
	{
		int cont = 0;
		do {
			cont++;
			cout << cont << "Nombre:" << actual->Nombre << "     " << actual->Letra << "\n";
			actual = actual->siguiente;
		} while (actual != this->Primero);
	}
}
Archivo::Archivo(string N,string L) {
	Letra = L;
	anterior = NULL;
	Nombre = N;
	siguiente = NULL;
}

void Archivo :: Agregar(string Nombre,string L){

	Archivo* nuevoNodo = new Archivo(Nombre,L);

	if (this->Primero == NULL)
	{
		this->Primero = nuevoNodo;
		Primero->siguiente = Primero;
		this->Ultimo = this->Primero;

	}
	else {
		this->Ultimo->siguiente = nuevoNodo;
		nuevoNodo->siguiente = this->Primero;
		this->Ultimo = nuevoNodo;

	}

}
void Archivo::VerL(string Ruta) {

	ifstream Archivo;

	string str("C++ String");
	string cadena;
	Archivo.open(Ruta, ios::in);
	if (Archivo.fail())
	{
		cout << "No se pudo abrir el archivo";
		exit(1);
	}

	while (!Archivo.eof())
	{
		getline(Archivo, str);
		for (size_t i = 0; i < str.size(); i++)
		{


			char Contenido = { str[i] };

			cout << Contenido;
			texto.Agregar(Contenido);
		}
	}
}
void Archivo::Grafo() {
	Archivo* actual = this->Primero;
	ofstream ar;

	ar.open("ReporteTexto.txt", ios::out);

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
		ar << "Nodo" << &*actual << "[ label = \"" << actual->Nombre << "\n"<<actual->Letra << "\" ];\n";
		
		if (actual->siguiente) {
			ar << "Nodo" << &*actual << "->";
			ar << "Nodo" << &*actual->siguiente << ";";

		}
		actual = actual->siguiente;

	} while (actual != this->Primero);
	ar << "\n" << "label = " << "ListadeArchivos \n"
		<< "	;\n \n }";


	ar.close();
	char Dot[] = "dot -Tjpg ReporteTexto.txt -o ReporteArchivo.jpg";
	system(Dot);

}
