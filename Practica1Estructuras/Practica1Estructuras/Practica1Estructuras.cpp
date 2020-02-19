#include <iostream>
#include <stdio.h>
#include<stdlib.h>
#include <conio.h>
#include<windows.h>
#include "Texto.h"
#include "Archivo.h"
#include "ListaO1.h"
#include <fstream>
#define letra_a 1
#define Espacio 32
#define Enter 13
#define Borrar 127
#define Reporte 3

#define Remplazar 23

#define Guarda 19 

#define FlechaIzq 25

#define FlechaDer 27

#define FlechaAbajo 25


using namespace std;	
Texto texto;
void Menu();
void Marco();
char L;
char B;
Archivo archivo;
Nodo nodos;
void Cargar();
void Abrir();
void Crear();

void Buscar();

void gotoxy(short x, short y) {
	COORD pos;
	pos.X = x;
	pos.Y = y;
	HANDLE H;
	H = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleCursorPosition(H, pos);
}


int main()
{
	Menu();
	
	return 0;
}
void Menu() {
	system("color e");
	Marco();

    int opcion;
	gotoxy(20, 2);
	printf("UNIVERSIDAD DE SANCARLOS DE GUATEMALA\n");
	gotoxy(20, 3);
	printf("FACULTAD DE INGENIERIA \n");
	gotoxy(20, 4);
	printf("ESTRUCTURA DE DATOS \n");
	gotoxy(20, 5);
	printf("JUAN DIEGO ALVARADO SALGUERO \n");
	gotoxy(20, 6);
	printf("201807335 \n");

	gotoxy(25, 12);
	printf("Menu \n");
	gotoxy(25, 13);
	printf("1.Crear Archivo \n");
	gotoxy(25, 14);
	printf("2.Abrir Archivo \n");
	gotoxy(25, 15);
	printf("3.Archivos Recientes \n");
	gotoxy(25, 16);
	printf("4.Salir \n");
	gotoxy(25, 17);
	printf("Escoja Opcion \n");
	gotoxy(25, 18);

	cin>>opcion;

	switch (opcion) {

	case 1:

		system("cls");
		Crear();

		break;
		
	case 2:
		system("cls");
		Cargar();
		break;
	case 3:

		system("cls");
		Abrir();
		break;
	case 4:

		system("cls");
		texto.Ver();
		break;
	

	}


}
void Marco() {

	int x, y, i, d;
	for (i = 2; i <100; i++)
	{
		gotoxy(i, 1);
		printf("%c ",177);
		gotoxy(i, 30);
		printf("%c", 177);


	}
	for (d = 2; d < 30; d++)
	{
		gotoxy(1, d);
		printf("%c", 178);
	
		gotoxy(80, d);
		printf("%c", 178);

	}

	gotoxy(1, 1);
	printf("%c", 02);
	gotoxy(00, 1);	
	printf("%c", 02);
	gotoxy(1, 30);
	printf("%c", 01);
}

void Crear() {
	system("color e");
	gotoxy(8, 25);

	cout << "^w(Buscar yRemplzar)";

	gotoxy(40, 25);
	cout << "^r(Reporte Palabras)";

	gotoxy(65, 25);
	cout << "^r(Guardar)";

	int x=4;
	int y = 4;

	gotoxy(x, y);
	texto.Ver();
	do
	{

		
		L = _getch();
		x++;
		cout << L;
		gotoxy(x, y);
	
		if (L==Enter)
		{
			y++;
			x = 4;
		}
		else if (x==75)
		{
			cout << "|";
			x = 4;
			y++;
		}
		else if (L==Borrar || L==FlechaIzq)
		{
			x--;

		}
		else if (L== Guarda)
		{
			Marco();
			texto.Guardar();
			Marco();
			Menu();

		}
		
		else if (L == FlechaAbajo || L=='\n')
		{
			y++;
		}
	
		else if (L!= letra_a )
 
		{
			texto.Agregar(L);
		}
		else if (L== Reporte)
		{
			cout << "reporte";
			texto.Grafo();
		}
		

	} while (L!=Remplazar);
	Buscar();
	system("cls");


}
void Cargar() {
	system("cls");
	string Opcion;
	Marco();
	gotoxy(3, 3);
	cout << "---------------------------Archivos recientes------------------------------";
	gotoxy(25, 6);
	archivo.Ver();
	gotoxy(25, 15);

	cout << "Que desea hacer?  -M regresa a MENU -X generaReporte";
	cin >> Opcion;
	if (Opcion=="x")
	{

		archivo.Grafo();
		Menu();
	}
	else {
		Menu();
	}
};
void Abrir() {
	string Nombre;
	Marco();
	string Ruta;
	char r;
	gotoxy(1, 3);
	cout << "---------------------Ingrese el Nombre del Archivo------------------------------";
	gotoxy(25, 5);
	cin >> Nombre;
	gotoxy(1, 7);
	cout << "---------------------Ingrese la ruta del Archivo------------------------------";
	gotoxy(3, 9);
	cin >> Ruta;

	system("cls");
	Marco();
	archivo.VerL(Ruta);

	archivo.Agregar("Prueba2", "Pueba2.txt");
	archivo.Agregar("Prueba3", "Pueba3.txt");
	archivo.Agregar("Prueba4", "Pueba4.txt");
     archivo.Agregar(Nombre, Ruta);
	 Marco();
	
}

	

void Buscar () {

	char Contenido [] ="";

	char Remplazo [] = "";

	char x=' ';
	gotoxy(25, 4);
	
	
	cout << "Ingrese Palabra A buscar \n";
	cin >> Contenido;

	cout << "Ingrese Palabra A remplazar \n";
	cin >> Remplazo;

	texto.Buscar(Contenido,Remplazo);
	nodos.Agregar(Contenido,Remplazo);
	nodos.Grafo();
	system("cls");
	Menu();
}

