#pragma once
#pragma once
#ifndef BINGO_H
#define BINGO_H
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include "Nodo.h"

class Bingo {

private:
	int numeroBingo;
	Nodo * primero;
	Nodo * ultimo;
	Bingo * bingoSig;//apunta al siguiente bingo en caso de seleccionar mas de uno
public:
	Bingo();
	Bingo(int);
	void initBingo();
	Nodo * getPrimero();
	void setPrimero(Nodo*);
	Nodo * getUltimo();
	void setUltimo(Nodo *);
	void setBingoSig(Bingo *);
	Bingo* getBingoSig();
	Nodo * insertar(int, Nodo*);
	Nodo * getB1();
	Nodo * llenaLetra(int);
	int getNumero();
	bool existe(int, int[], int);
	bool existe(int, Nodo *);
	string toString();
	~Bingo();

};

#endif
