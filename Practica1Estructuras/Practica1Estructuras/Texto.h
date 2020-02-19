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

void gotoxy2(short x, short y) {
	COORD pos;
	pos.X = x;
	pos.Y = y;
	HANDLE H;
	H = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleCursorPosition(H, pos);
}



class Texto
{
private:
	Texto* Primero;
	Texto* Ultimo;
	
public:
	Texto* siguiente;
	Texto* anterior;
	 char Letra;
	
	Texto();
	Texto(char Letra);
	Texto(char Letra []);

	void Ver();
	void Agregar(char Letra);
	void Grafo();
	void Guardar();
	void Buscar(char B  [], char Remplazo [] );
	void Remplazar(Texto*Actual,Texto*aux ,char R []);
	inline Texto* getUltimo() {
		return this->Ultimo;
		
	};
	inline Texto*  getPrimero() {
		return this->Primero;
	};
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
 Texto::Texto(char L[]) {
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
	

		int contador = 0;
		while (actual!= NULL)
		{
			gotoxy2(4, 2);
			cout <<actual->Letra;
			actual = actual->siguiente;
		}
	
}
void Texto::Buscar(char  Busqueda[], char Remplazo []) {

	Texto* actual = this->Primero;
	Texto* aux = new Texto();
	Texto* aux2 = new Texto();

	
//	Texto* nuevoNodo = new Texto(L);

	
	string PalabraBusqueda = Busqueda;
	string recol="";
	
	int cont = 0;
	while (actual!=NULL) {
		recol += actual->Letra;
		
		if (recol.compare(PalabraBusqueda) == 0) {
			aux = actual;

			for (int i = 0; i < recol.size(); i++)
			{

				if (actual->anterior == NULL)
				{
					cout << "primer nodo";
					this->Primero = aux->siguiente;


				}
				else if (aux->siguiente == NULL)
				{
					actual->anterior = this->Ultimo;
					this->Ultimo->siguiente = NULL;

				}
				else {
					actual->anterior->siguiente = aux->siguiente;
					aux->siguiente->anterior = aux->anterior;
				}

				

				actual = actual->anterior;
			}
			Remplazar(actual, aux, Remplazo);

			Grafo();
			
		}
		else	 if (actual->Letra ==' ')
		 {
			 
			recol = "";
			
		}
	
		if (actual != NULL)
		{
			actual = actual->siguiente;
		}
	}
	
}
/*
void Texto::Buscar(char  Busqueda [],char Remplazar  []) {
	Texto* actual = this->Primero;
	int cont=0 ;
	string PalabraBusqueda = Busqueda;
	Texto* nuevoNodo = new Texto(Remplazar);
	string recolectorLetras = "";
	do {

		recolectorLetras += actual->Letra;
		for (size_t i = 0; i < PalabraBusqueda.size(); i++)
		{
			recolectorLetras += actual->Letra;
			if (actual->Letra == PalabraBusqueda[i])
			{
			
				
	
				cont++;
				
				if (cont == PalabraBusqueda.size() )
				{ 
					cout << "		 PALABRA ENCONTRADA: " << palabraEncontrada<<endl;
					/*for (size_t i = 0; i <sizeof(actual->Letra); i++)
					{
						if (actual->anterior==NULL)
						{
							this->Primero = actual->siguiente;
						}
						else if (actual->siguiente == NULL) {
							this->Ultimo = actual->anterior;
						}else{
						actual->anterior->siguiente = actual->siguiente;
						actual->siguiente->anterior = actual->anterior;

						cont = 0;
						}

					}
					for (size_t i = 0; i < (sizeof(Remplazar) / 2); i++)
					{
						actual->siguiente->anterior = nuevoNodo;
					
						nuevoNodo->siguiente = actual->siguiente;
						nuevoNodo->anterior = actual;
					}  
					cout << "\n";
					Ver();
			
				}
				actual = actual->siguiente;
			}
			else {
				
				
			
				cont = 0;
				actual = actual->siguiente;
				break;
			}
			
			
		}

		if (actual!=NULL)
		{
			actual = actual->siguiente;
		}
	} while (actual != NULL);
	

}*/
void Texto::Remplazar(Texto* Actual,Texto* aux, char R  []) {
	Texto Lista;
	for (size_t i = 0; i < sizeof(R); i++)
	{
		Lista.Agregar(R[i]);

	if (Actual==NULL)
		{
			this->Primero =Lista.getPrimero();
			Lista.getUltimo()->siguiente = aux->siguiente;
			
	}
	else if (aux->siguiente==NULL)
	{
		Actual->anterior = Lista.getPrimero();
		Lista.getPrimero()->anterior = Actual->anterior;
		
	}
	
		else {
           


				Actual->siguiente = Lista.getPrimero();
			Lista.getPrimero()->anterior = Actual;
			Lista.getUltimo()->siguiente = aux->siguiente;
			aux->siguiente->anterior = Lista.getUltimo();



		}
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

void Texto::Guardar()
{
	
	Texto* actual = this->Primero;
	ofstream arc;
	system("cls");

	string NombreArchivo;
	gotoxy2(25, 15);

	cout << "Escoja como guardar el archivo \n";
	gotoxy2(25, 16);
	cin >> NombreArchivo;

	NombreArchivo = NombreArchivo + ".txt";
	arc.open(NombreArchivo, ios::out);
	while (actual!=NULL)
	{

	
	

	arc << actual->Letra ;
	actual = actual->siguiente;
	}
	if (arc.fail())
	 {
		 cout << "F";

	 }

	 arc.close();
	
}

