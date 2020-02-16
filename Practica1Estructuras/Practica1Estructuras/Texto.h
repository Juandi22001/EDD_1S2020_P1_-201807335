#pragma once

#include <iostream>
#include <stdio.h>
#include<stdlib.h>
#include <conio.h>
#include<windows.h>
#include <fstream>
#define C 39
using namespace std;
class Texto
{
private:
	Texto* Primero;
	Texto* Ultimo;
	
public:
	Texto* siguiente;
	Texto* anterior;
	 char Letra;
	 Texto* Letras;
	Texto();
	Texto(char Letra);
	void Ver();
	void Agregar(char Letra);
	void Grafo();

};



Texto::Texto() {
	anterior = NULL;
	siguiente = NULL;
	Letra = ' ';
	Primero = NULL;
	Ultimo = NULL;
}
 Texto::Texto(char L) {
	 Letra = L;
	 anterior = NULL;
	 siguiente = NULL;
}
void Texto ::Agregar(char L) {
	Texto* nuevoNodo = new Texto(L);
	if (this->Primero != NULL) {

		this->Ultimo->siguiente = nuevoNodo;
		nuevoNodo->anterior = this->Ultimo;

		nuevoNodo->siguiente = NULL;
		this->Ultimo = nuevoNodo;


	}
	else if (this->Primero == NULL) {

		this->Primero = nuevoNodo;
		this->Primero->siguiente = NULL;
		this->Primero->anterior = NULL;
		this->Ultimo = Primero;
	}
		

	
}
void Texto ::  Ver() {	
	Texto* actual = this->Primero;
	if (Primero!=NULL)
	{

		int contador = 0;
		while (actual!= NULL)
		{  
			cout << actual->Letra<<"\n";
			actual = actual->siguiente;
		}
	}
	else
	{
		cout << "ESTAAAAAA VACIAAAAAAAAAAAA";
	}
}
void Texto :: Grafo() {
	Texto* actual = this->Primero;
	Texto* aux2 = new Texto();
	int pos=0;
	ofstream archivo;
		
	archivo.open("ReportePalabras.txt", ios::out);

	if (archivo.fail())
	{
		cout << "F";

	}

	archivo << "digraph G{ \n"

		<< "  subgraph cluster_0 { \n"
		<< "style = filled;\n"
		<< "		color = lightgrey;\n"
		<< "	node[style = filled,color = white];\n";
	do {
		archivo << "Nodo" << &*actual << "[ label = \"" << actual->Letra << "\" ];\n";
		if (actual->siguiente) {
			archivo << "Nodo" << &*actual << "->";
			archivo << "Nodo" << &*actual->siguiente << ";";
			archivo << "Nodo" << &*actual->siguiente << "->";
			archivo << "Nodo" << &*actual << ";";
		}
		actual = actual->siguiente;

	} while (actual != NULL);
	archivo <<"\n"<<"label = " << "Lista1 #1\n"
		<< "	;\n} \n }";


	archivo.close();
	char Dot[] = "dot -Tjpg ReportePalabras.txt -o graph.jpg";
	system(Dot);


}