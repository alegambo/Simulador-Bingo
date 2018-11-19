#pragma once
#pragma once
#pragma once
#ifndef PILA_H
#define PILA_H
#include "Lista.h" // definici�n de la clase Lista

template< class T >
class Pila : private Lista< T >
{
public:
	// push llama a la funci�n insertarAlFrente de Lista
	void push(T& datos)
	{
		insertaFinal(datos);
	} // fin de la funci�n push
	  // pop llama a la funci�n eliminarDelFrente de Lista
	bool pop(T& datos)
	{

		return EliminaPrimero(datos);
	} // fin de la funci�n pop

	T pop()
	{
		return sacaPrimero();
	}

	// estaPilaVacia llama a la funci�n estaVacia de Lista
	bool estaPilaVacia() {
		return estaVacia();
	}

	void imprimirPila()
	{
		imprimir();
	} // fin de la funci�n imprimir
}; // fin de la clase Pila

#endif
