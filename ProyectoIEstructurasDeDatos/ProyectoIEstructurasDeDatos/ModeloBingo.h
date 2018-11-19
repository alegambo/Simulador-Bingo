#pragma once
#pragma once
#ifndef MODELOBINGO_H
#define MODELOBINGO_H
#include "Bingo.h"

class ModeloBingo {
private:
	int modo;
	int cantidadBingos;
	Bingo * bingoPrimero;
public:
	ModeloBingo(int, int);
	void insertar(int);
	int getModo();
	int getCantidadBingos();
	Bingo * getBingoPrimero();

	bool buscar(int, int);//el numero del carton, numero a buscar
	bool juegoL(int);
	bool juegoC(int);
	bool juegoX(int);
	bool juegoD1(int);
	bool juegoD2(int);
	bool juegoO(int);
	bool juegoV(int);
	bool juegoU(int);
	bool juegoH(int);
	bool juegoLleno(int);

	string toString();
	string mostrarCol(int, int);
	string mostrarCol2(int, int);
	bool verificarCarton(int, int);
	virtual ~ModeloBingo();
};

#endif // MODELOBINGO_H
