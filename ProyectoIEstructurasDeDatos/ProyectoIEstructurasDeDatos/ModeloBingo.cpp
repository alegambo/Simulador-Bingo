#include "ModeloBingo.h"

ModeloBingo::ModeloBingo(int pModo, int pCantidad) {
	this->bingoPrimero = NULL;//new Bingo(1);
	this->modo = pModo;
	this->cantidadBingos = pCantidad;
	for (int i = 1;i <= pCantidad;i++) {
		this->insertar(i);
	}
}

Bingo * ModeloBingo::getBingoPrimero() {
	return bingoPrimero;
}

int ModeloBingo::getCantidadBingos() {
	return cantidadBingos;
}

int ModeloBingo::getModo() {
	return modo;
}


void ModeloBingo::insertar(int pNum) {
	if (bingoPrimero == NULL) {
		bingoPrimero = new Bingo(pNum);
	}
	else {
		Bingo * aux = getBingoPrimero();
		while (aux->getBingoSig() != NULL) {
			aux = aux->getBingoSig();
		}
		aux->setBingoSig(new Bingo(pNum));
	}
}

string ModeloBingo::toString() {
	stringstream s;
	Bingo * temp = getBingoPrimero();
	while (temp != NULL) {
		s << "Bingo " << temp->getNumero() << endl << endl;
		s << temp->toString();
		temp = temp->getBingoSig();
	}
	s << endl << endl;
	return s.str();
}

string ModeloBingo::mostrarCol(int numBingo, int num) {
	stringstream s;
	s << "Seleccione enter" << endl;
	Bingo * temp = getBingoPrimero();
	for (int i = 1;i<numBingo;i++) {
		temp = temp->getBingoSig();
	}
	Nodo * nodoTemp = temp->getPrimero();
	int aux = num;
	while (aux>15) {
		nodoTemp = nodoTemp->getDer();//BINGO
		aux = aux - 15;//61, 46, 31,16
	}
	for (int i = 0;i<5;i++) {
		s << nodoTemp->getNum() << ", ";
		nodoTemp = nodoTemp->getAbajo();
	}
	s << endl;
	return s.str();
}

string ModeloBingo::mostrarCol2(int numBingo, int num) {
	stringstream s;
	s << "Seleccione enter" << endl;
	Bingo * temp = getBingoPrimero();
	for (int i = 1;i<numBingo;i++) {
		temp = temp->getBingoSig();
	}
	Nodo * nodoTemp = temp->getPrimero();
	int aux = num;
	while (aux>15) {
		nodoTemp = nodoTemp->getDer();//BINGO
		aux = aux - 15;//61, 46, 31,16
	}
	for (int i = 0;i<4;i++) {
		nodoTemp = nodoTemp->getAbajo();
	}
	for (int i = 0;i<5;i++) {
		s << nodoTemp->getNum() << ", ";
		nodoTemp = nodoTemp->getArriba();
	}
	s << endl;
	return s.str();
}

bool ModeloBingo::buscar(int numBingo, int num) {
	Bingo * temp = getBingoPrimero();
	for (int i = 1;i<numBingo;i++) {
		temp = temp->getBingoSig();
	}
	Nodo * nodoTemp = temp->getPrimero();
	int aux = num;
	while (aux>15) {
		nodoTemp = nodoTemp->getDer();//BINGO
		aux = aux - 15;//61, 46, 31,16
	}
	for (int i = 0;i<5;i++) {
		if (nodoTemp->getNum() == num) {
			nodoTemp->setMarca(true);
			return true;
		}
		nodoTemp = nodoTemp->getAbajo();
	}
	return false;
}


bool ModeloBingo::juegoC(int numBingo) {
	Bingo * temp = getBingoPrimero();
	for (int i = 1;i<numBingo;i++) {//obtenemos el carton
		temp = temp->getBingoSig();
	}
	Nodo * nodoTemp = temp->getUltimo();
	while (nodoTemp->getIzq() != NULL) {//revisa ultima fila
		if (nodoTemp->getMarca() != true) {
			return false;
		}
		nodoTemp = nodoTemp->getIzq();
	}
	while (nodoTemp->getArriba() != NULL) {//revisa primera columna menos el primero
		if (nodoTemp->getMarca() != true) {
			return false;
		}
		nodoTemp = nodoTemp->getArriba();
	}
	while (nodoTemp != NULL) {//revisa primera fila
		if (nodoTemp->getMarca() != true) {
			return false;
		}
		nodoTemp = nodoTemp->getDer();
	}
	return true;
}
bool ModeloBingo::juegoO(int numBingo) {
	Bingo * temp = getBingoPrimero();
	for (int i = 1;i<numBingo;i++) {//obtenemos el carton
		temp = temp->getBingoSig();
	}
	Nodo * nodoTemp = temp->getUltimo();
	while (nodoTemp->getIzq() != NULL) {//revisa ultima fila
		if (nodoTemp->getMarca() != true) {
			return false;
		}
		nodoTemp = nodoTemp->getIzq();
	}
	while (nodoTemp->getArriba() != NULL) {//revisa primera columna menos el primero
		if (nodoTemp->getMarca() != true) {
			return false;
		}
		nodoTemp = nodoTemp->getArriba();
	}
	while (nodoTemp->getDer() != NULL) {//revisa primera fila
		if (nodoTemp->getMarca() != true) {
			return false;
		}
		nodoTemp = nodoTemp->getDer();
	}
	while (nodoTemp->getAbajo() != NULL) {
		if (nodoTemp->getMarca() != true) {
			return false;
		}
		nodoTemp = nodoTemp->getAbajo();
	}

	return true;
}
bool ModeloBingo::juegoL(int numBingo) {
	Bingo * temp = getBingoPrimero();
	for (int i = 1;i<numBingo;i++) {//obtenemos el carton
		temp = temp->getBingoSig();
	}
	Nodo * nodoTemp = temp->getPrimero();
	while (nodoTemp->getAbajo() != NULL) {////revisa primera columna menos el ultimo
		if (nodoTemp->getAbajo()->getMarca() != true) {
			return false;
		}
		nodoTemp = nodoTemp->getAbajo();
	}
	while (nodoTemp != NULL) {//revisa ultima fila
		if (nodoTemp->getMarca() != true) {
			return false;
		}
		nodoTemp = nodoTemp->getDer();
	}
	return true;
}
bool ModeloBingo::juegoX(int numBingo) {
	Bingo * temp = getBingoPrimero();
	for (int i = 1;i<numBingo;i++) {//obtenemos el carton
		temp = temp->getBingoSig();
	}
	Nodo * nodoTemp = temp->getPrimero();
	while (nodoTemp != NULL) {
		if (nodoTemp->getMarca() != true) {
			return false;
		}
		nodoTemp = nodoTemp->getAbajoDer();
	}
	nodoTemp = temp->getPrimero();
	while (nodoTemp->getDer() != NULL) {//B1-B2-B3-B4-B5
		nodoTemp = nodoTemp->getDer();
	}
	while (nodoTemp != NULL) {
		if (nodoTemp->getMarca() != true) {
			return false;
		}
		nodoTemp = nodoTemp->getAbajoIzq();
	}
	return true;
}
bool ModeloBingo::juegoD1(int numBingo) {
	Bingo * temp = getBingoPrimero();
	for (int i = 1;i<numBingo;i++) {//obtenemos el carton
		temp = temp->getBingoSig();
	}
	Nodo * nodoTemp = temp->getPrimero();
	while (nodoTemp != NULL) {
		if (nodoTemp->getMarca() != true) {
			return false;
		}
		nodoTemp = nodoTemp->getAbajoDer();
	}
	return true;
}
bool ModeloBingo::juegoD2(int numBingo) {
	Bingo * temp = getBingoPrimero();
	for (int i = 1;i<numBingo;i++) {//obtenemos el carton
		temp = temp->getBingoSig();
	}
	Nodo * nodoTemp = temp->getPrimero();
	while (nodoTemp->getDer() != NULL) {//B1-B2-B3-B4-B5
		nodoTemp = nodoTemp->getDer();
	}
	while (nodoTemp != NULL) {
		if (nodoTemp->getMarca() != true) {
			return false;
		}
		nodoTemp = nodoTemp->getAbajoIzq();
	}
	return true;
}
bool ModeloBingo::juegoV(int numBingo) {
	Bingo * bingotemp = getBingoPrimero();
	for (int i = 1;i<numBingo;i++) {//obtenemos el carton
		bingotemp = bingotemp->getBingoSig();
	}
	Nodo * temp = bingotemp->getPrimero();//B1 es el primero
	Nodo * temp2 = bingotemp->getPrimero();
	while (temp2 != NULL) {
		int aux = 0;
		while (temp != NULL) {
			if (temp->getMarca() == true) {
				aux++;
			}
			temp = temp->getAbajo();
		}
		if (aux == 5) { return true; }
		else { temp2 = temp2->getDer();temp = temp2; }
	}
	return false;
}
bool ModeloBingo::juegoH(int numBingo) {
	Bingo * bingotemp = getBingoPrimero();
	for (int i = 1;i<numBingo;i++) {//obtenemos el carton
		bingotemp = bingotemp->getBingoSig();
	}
	Nodo * temp = bingotemp->getPrimero();//B1 es el primero
	Nodo * temp2 = bingotemp->getPrimero();
	while (temp2 != NULL) {
		int aux = 0;
		while (temp != NULL) {
			if (temp->getMarca() == true) {
				aux++;
			}
			temp = temp->getDer();
		}
		if (aux == 5) { return true; }
		else { temp2 = temp2->getAbajo();temp = temp2; }
	}
	return false;
}
bool ModeloBingo::juegoLleno(int numBingo) {
	Bingo * bingotemp = getBingoPrimero();
	for (int i = 1;i<numBingo;i++) {//obtenemos el carton
		bingotemp = bingotemp->getBingoSig();
	}
	Nodo * temp = bingotemp->getPrimero();//B1 es el primero
	Nodo * temp2 = bingotemp->getPrimero();
	while (temp2 != NULL) {
		while (temp != NULL) {
			if (temp->getMarca() != true) {
				return false;
			}
			temp = temp->getDer();
		}
		temp2 = temp2->getAbajo();
		temp = temp2;
	}
	return true;
}
bool ModeloBingo::juegoU(int numBingo) {
	Bingo * temp = getBingoPrimero();
	for (int i = 1;i<numBingo;i++) {//obtenemos el carton
		temp = temp->getBingoSig();
	}
	Nodo * nodoTemp = temp->getPrimero();
	while (nodoTemp->getAbajo() != NULL) {////revisa primera columna menos el ultimo
		if (nodoTemp->getAbajo()->getMarca() != true) {
			return false;
		}
		nodoTemp = nodoTemp->getAbajo();
	}
	while (nodoTemp->getAbajoDer() != NULL) {//revisa ultima fila menos ultma pos
		if (nodoTemp->getMarca() != true) {
			return false;
		}
		nodoTemp = nodoTemp->getDer();
	}
	while (nodoTemp != NULL) {//revisa ultima columna
		if (nodoTemp->getMarca() != true) {
			return false;
		}
		nodoTemp = nodoTemp->getArriba();
	}
	return true;
}


bool ModeloBingo::verificarCarton(int a, int b) {//modo, numero de carton
	switch (a) {
	case 1:
		juegoLleno(b);
		break;
	case 2:
		juegoH(b);
		break;
	case 3:
		juegoV(b);
		break;
	case 4:
		juegoL(b);
		break;
	case 5:
		juegoC(b);
		break;
	case 6:
		juegoU(b);
		break;
	case 7:
		juegoO(b);
		break;
	case 8:
		if (juegoD1(b) == true || juegoD2(b) == true) { return true; }
		else { return false; }
		break;
	case 9:
		juegoX(b);
		break;
	default: return false;

	}
}

ModeloBingo::~ModeloBingo() {}