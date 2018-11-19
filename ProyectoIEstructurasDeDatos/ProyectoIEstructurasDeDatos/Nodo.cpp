#include "Nodo.h"
// ------------ Nodo.cpp---------------------------
Nodo::Nodo(int pNum) {
	this->num = pNum;
	this->marca = false;
	this->abajo = izq = der = abajoIzq = abajoDer = arriba = NULL;
}

Nodo::Nodo() {
	this->num = 0;
	this->marca = false;
	this->abajo = izq = der = abajoIzq = abajoDer = arriba = NULL;
}

// Este metodo configura todos los enlaces izquierdos y derechos de la lista que invoca el metodo
void Nodo::setLaterales(Nodo * pIzq, Nodo * pDer) {
	Nodo * temp = this;
	Nodo * izq = pIzq;
	Nodo * der = pDer;
	while (temp != NULL) {
		temp->setIzq(izq);
		temp->setDer(der);
		izq->setDer(temp);
		der->setIzq(temp);
		der = der->getAbajo();
		izq = izq->getAbajo();
		temp = temp->getAbajo();
	}
}

//Este metodo configura los enlaces diagonales ÚNICAMENTE DE LOS NODOS QUE FORMAN PARTE DE LAS DIAGONALES DEL BINGO.
void Nodo::setDiagonales() {
	Nodo * diag = this;
	if (diag->getIzq() == NULL) {
		while (diag->getAbajo() != NULL) {
			diag->setAbajoDer(diag->getAbajo()->getDer());
			diag = diag->getAbajoDer();
		}
	}
	else {
		while (diag->getAbajo() != NULL) {
			diag->setAbajoIzq(diag->getAbajo()->getIzq());
			diag = diag->getAbajoIzq();
		}
	}
}

void Nodo::setNum(int pNum) { num = pNum; }
int Nodo::getNum() { return num; }
void Nodo::setMarca(bool m) { marca = m; }
bool Nodo::getMarca() { return marca; }
void Nodo::setAbajo(Nodo * pNodo) { abajo = pNodo; }
void Nodo::setArriba(Nodo * pNodo) { arriba = pNodo; }
void Nodo::setIzq(Nodo * pNodo) { izq = pNodo; }
void Nodo::setDer(Nodo * pNodo) { der = pNodo; }
void Nodo::setAbajoDer(Nodo * pNodo) { abajoDer = pNodo; }
void Nodo::setAbajoIzq(Nodo * pNodo) { abajoIzq = pNodo; }
Nodo * Nodo::getAbajo() { return abajo; }
Nodo * Nodo::getArriba() { return arriba; }
Nodo * Nodo::getDer() { return der; }
Nodo * Nodo::getIzq() { return izq; }
Nodo * Nodo::getAbajoDer() { return abajoDer; }
Nodo * Nodo::getAbajoIzq() { return abajoIzq; }

string Nodo::toString() {
	stringstream s;
	s << "| " << setw(2) << setfill('0') << getNum() << setw(2) << setfill(' ') << "|";
	return s.str();
}