#pragma once
#pragma once
#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include <sstream>
#include "NodoPila.h"
using namespace std;

template <class T>
class Lista
{
private:
	NodoPila<T>* primerNodo;
	NodoPila<T>* ultimoNodo;

	//funcion utilitaria
	NodoPila<T> *getNuevoNodo(const T&);

	int tamLista;
public:
	Lista();
	~Lista();

	bool estaVacia() const;
	void insertarInicio(const T&);
	void insertaFinal(const T&);
	bool EliminaPrimero(T&);
	bool EliminaUltimo(T&);
	void insertarElementoOrdenados(T&);//***************
	bool encuentra(T&);


	T sacaPrimero();
	int getTamLista();
	void eliminar();
	void imprimir() const;   //*******************
};


//-----------------------------------------------------------------
template <class T>
Lista<T>::Lista()
{
	primerNodo = ultimoNodo = NULL;
	tamLista = 0;
}
//-----------------------------------------------------------------

template <class T>
bool Lista<T>::encuentra(T& valor) {
	if (estaVacia()) { return false; }
	else
	{
		bool esta = false;
		NodoPila<T>* aux = primerNodo;
		while (aux != NULL && esta == false)
		{
			if (aux->getInfo() == valor)
			{
				esta = true;
			}
			else
			{
				aux = aux->Siguiente;
			}
		}
		return esta;
	}
}


template <class T>
bool Lista<T>::EliminaPrimero(T& valor)
{
	if (estaVacia()) {
		return false;
	}
	else {
		NodoPila<T>* aux = primerNodo;
		if (primerNodo == ultimoNodo)
			primerNodo = ultimoNodo = NULL;
		else
			primerNodo = primerNodo->getNSig();
		valor = aux;
		delete aux;
		tamLista = tamLista - 1;
		return true;
	}
}





template <class T>
bool Lista<T>::EliminaUltimo(T& valor)
{
	if (estaVacia()) { return false; }
	else {
		NodoPila<T>* temp = ultimoNodo;
		if (primerNodo == ultimoNodo)
			primerNodo = ultimoNodo = 0;
		else
		{
			NodoPila<T>* actual = primerNodo;
			while (actual->getNSig() != ultimoNodo)
				actual = actual->getNSig();

			ultimoNodo = actual;
			actual->setNSig(NULL);
		}
		valor = temp->Info;
		delete temp;
		tamLista = tamLista - 1;
		return true;
	}
}

template <class T>
T Lista<T>::sacaPrimero() {
	if (estaVacia()) {
		return NULL;
	}
	else
	{
		NodoPila<T> *aux = ultimoNodo;
		if (primerNodo == ultimoNodo && ultimoNodo != NULL)
		{
			primerNodo = ultimoNodo = NULL;
			return aux->getInfo();

		}
		else {

			ultimoNodo = aux->getAnt();
			ultimoNodo->setSig(NULL);
			tamLista = tamLista - 1;
			return aux->getInfo();
		}
	}

}


//-----------------------------------------------------------------
template <class T>
Lista<T>::~Lista()
{
	if (!estaVacia()) // la Lista no está vacía
	{
		NodoPila<T> *actualPtr = primerNodo;
		NodoPila<T> *tempPtr;

		while (actualPtr != 0) // elimina los nodos restantes
		{
			tempPtr = actualPtr;
			actualPtr = actualPtr->Siguiente;
			delete tempPtr;
		} // fin de while
	} // fin de if
}

//------------------------------------------------------------------------------------------
template <class T>
bool Lista<T>::estaVacia() const
{
	return primerNodo == NULL;
}

//--------------------------------------------------------------------------------------
template <class T>
int Lista<T>::getTamLista()
{
	return tamLista;
}

//-------------------------------------------------------------------
template <class T>
void Lista<T>::insertarInicio(const T &valor)
{

	NodoPila<T>* nuevoPtr = getNuevoNodo(valor);
	if (estaVacia()) {
		primerNodo = ultimoNodo = nuevoPtr;
		tamLista = tamLista + 1;
	}
	else
	{
		primerNodo->setAnt(nuevoPtr);
		nuevoPtr->Siguiente = primerNodo;
		primerNodo = nuevoPtr;
		nuevoPtr->setAnt(NULL);
		tamLista = tamLista + 1;

	}

}
//-------------------------------------------------------------------

template <class T>
void Lista<T>::insertaFinal(const T& valor)
{
	NodoPila<T> *nuevoPtr = getNuevoNodo(valor);
	if (estaVacia())
		primerNodo = ultimoNodo = nuevoPtr;
	else
	{
		nuevoPtr->setAnt(ultimoNodo);
		ultimoNodo->Siguiente = nuevoPtr;
		ultimoNodo = nuevoPtr;
		ultimoNodo->setSig(NULL);
		tamLista = tamLista + 1;
	}
}

//------------------------------------------------------------------
template <class T>
void Lista<T>::insertarElementoOrdenados(T& E) {
	if (estaVacia() || E<primerNodo->getInfo()) {
		insertarInicio(E);
	}
	else
	{
		NodoPila<T>* aux = primerNodo;
		while (aux->Siguiente && E>aux->Siguiente->getInfo()) {
			aux = aux->Siguiente;
		}
		if (aux->Siguiente == NULL) {
			insertaFinal(E);
		}
		else {
			NodoPila<T>* nuevo = getNuevoNodo(E);
			nuevo->setSig(aux->Siguiente);
			nuevo->setAnt(aux);
			aux->Siguiente = nuevo;
			tamLista = tamLista + 1;

		}

	}
};


template< class T>
NodoPila<T> *Lista<T>::getNuevoNodo(const T &valor)
{
	return new NodoPila<T>(valor);
};

//------------------------------------------------------------------
template <class T>
void Lista<T>::imprimir() const
{
	if (estaVacia() == true)
	{
		cout << "Esta Vacia" << endl;
		return;
	}
	else {
		NodoPila<T>* actualPtr = primerNodo;
		cout << "La Lista Es" << endl;
		while (actualPtr != 0)
		{
			cout << actualPtr->Info << ' ';
			actualPtr = actualPtr->Siguiente;
		}
	}
}

#endif

