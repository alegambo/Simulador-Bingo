#pragma once
#pragma once
//----------------Nodo.h--------------------------------
#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;
class Nodo {
private:
	int num;
	bool marca;
	Nodo * abajo;
	Nodo * arriba;
	Nodo * izq;
	Nodo * der;
	Nodo * abajoDer;
	Nodo * abajoIzq;
public:
	Nodo();
	Nodo(int);
	void setNum(int);
	int getNum();
	void setMarca(bool);
	bool getMarca();
	void setLaterales(Nodo*, Nodo*);
	void setDiagonales();

	void setAbajo(Nodo *);
	void setArriba(Nodo *);
	void setIzq(Nodo *);
	void setDer(Nodo *);
	void setAbajoDer(Nodo *);
	void setAbajoIzq(Nodo *);
	Nodo * getAbajo();
	Nodo * getArriba();
	Nodo * getDer();
	Nodo * getIzq();
	Nodo * getAbajoDer();
	Nodo * getAbajoIzq();

	string toString();
};

