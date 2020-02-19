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



class aux
{
private:
	aux* First;
	aux* Last;

public:
	aux* next;
	aux* ant;
	char Letra;

	aux();
	aux(char Letra);
	void Ver();
	void Agregar(char Letra);

};
aux::aux() {
	ant= NULL;
	next = NULL;
	Letra = ' ';
	First = NULL;
	Last = NULL;
}
aux::aux(char L ) {
	ant= NULL;
	next = NULL;
}
void aux::Agregar(char L  ) {
	aux* P = new aux(L);
	if (this->First != NULL) {

		this->Last->next = P;
		P->ant= this->Last;
		P->next = NULL;
		this->Last = P;


	}
	else if (this->First == NULL) {

		this->First = P;
		this->First->next = NULL;
		this->First->ant= NULL;
		this->Last = First;
	}



}
void aux::Ver() {
	aux* act = this->First;
	if (First != NULL)
	{

		int contador = 0;
		while (act != NULL)
		{
			cout <<"-" <<act->Letra<<"-";
			act = act->next;
		}
	}
	else
	{
		cout << "ESTAAAAAA VACIAAAAAAAAAAAA";
	}
}
