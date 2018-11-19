#include "Bingo.h"
//------------------------------Bingo.cpp-------------------------------
Bingo::Bingo() {
	this->primero = this->ultimo = NULL;
	this->bingoSig = NULL;
	numeroBingo = 0;
	initBingo();
}
Bingo::Bingo(int n) {
	this->primero = NULL;
	this->bingoSig = NULL;
	numeroBingo = n;
	initBingo();

}

void Bingo::initBingo() { // Llena el bingo segun las restricciones numericas de cada letra del bingo y configura todos los enlaces entre los nodos.
	this->setPrimero(llenaLetra(1));
	Nodo * I = llenaLetra(16);
	Nodo * N = llenaLetra(31);
	Nodo * G = llenaLetra(46);
	Nodo * O = llenaLetra(61);
	I->setLaterales(getPrimero(), N);
	G->setLaterales(N, O);
	getPrimero()->setDiagonales();
	O->setDiagonales();
}

Nodo * Bingo::insertar(int pNum, Nodo * pNodo) {
	Nodo * nuevoNodo = new Nodo(pNum);
	if (pNodo->getNum() == 0)
		pNodo->setNum(pNum);
	else {
		nuevoNodo->setAbajo(pNodo);
		pNodo->setArriba(nuevoNodo);
		//ultimo=pNodo;
		pNodo = nuevoNodo;
	}
	return pNodo;
}

Nodo * Bingo::getPrimero() {
	return this->primero;
}

void Bingo::setPrimero(Nodo * pNodo) {
	this->primero = pNodo;
}

Nodo* Bingo::getUltimo() {
	return ultimo;
}

void Bingo::setUltimo(Nodo * pNodo) {
	ultimo = pNodo;
}

void Bingo::setBingoSig(Bingo * sig) {
	bingoSig = sig;
}

Bingo * Bingo::getBingoSig() {
	return bingoSig;
}

int Bingo::getNumero() {
	return numeroBingo;
}

Nodo * Bingo::llenaLetra(int min) {
	Nodo * lNodo = new Nodo();
	Nodo * primeroCol = getPrimero();
	int insertados[5];
	int tam = 0;
	for (int i = 0;i<5;i++) {
		int random = (rand() % 15 + min);
		while (existe(random, insertados, tam)) {
			random = (rand() % 15 + min);
		}
		insertados[i] = random;
		if (i == 0) { ultimo = lNodo = insertar(random, lNodo); }
		else { lNodo = insertar(random, lNodo); }
		tam++;
	}
	return lNodo;
}
bool Bingo::existe(int random, int v[], int tam) {
	if (tam == 0) {
		return false;
	}
	else {
		for (int i = 0;i<tam;i++) {
			if (v[i] == random) {
				return true;
			}
		}
	}
	return false;
}

bool Bingo::existe(int n, Nodo * pos) {
	Nodo * temp;
	for (temp = pos; temp != NULL; temp = temp->getAbajo()) {
		if (temp->getNum() == n) {
			return true;
		}
	}
	return false;
}

string Bingo::toString() {
	stringstream s;
	s << " ----------------------------" << endl;
	s << "|" << setw(3) << setfill(' ') << "B" << setw(6) << setfill(' ') << "I" << setw(6) << setfill(' ') << "N" << setw(6) << setfill(' ') << "G" << setw(6) << setfill(' ') << "O" << setw(2) << setfill(' ') << "|" << endl;
	s << " ----------------------------" << endl;
	Nodo * temp = getPrimero();//B1 es el primero
	Nodo * temp2 = getPrimero();
	while (temp2 != NULL) {
		while (temp != NULL) {
			//temp->setElemento(i);
			//i++;
			if (temp->getMarca() == true) {
				s << "| " << setw(2) << setfill(' ') << 'X' << setw(2) << setfill(' ') << "|";
			}
			else {
				s << temp->toString();
			}
			temp = temp->getDer();
		}
		s << endl;
		temp2 = temp2->getAbajo();
		temp = temp2;
	}
	return s.str();
}