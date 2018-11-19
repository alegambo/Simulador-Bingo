#pragma once
#pragma once
#pragma once
#ifndef PILA_H
#define PILA_H
#include "Lista.h" // definición de la clase Lista

template< class T >
class Pila : private Lista< T >
{
public:
	// push llama a la función insertarAlFrente de Lista
	void push(T& datos)
	{
		insertaFinal(datos);
	} // fin de la función push
	  // pop llama a la función eliminarDelFrente de Lista
	bool pop(T& datos)
	{

		return EliminaPrimero(datos);
	} // fin de la función pop

	T pop()
	{
		return sacaPrimero();
	}

	// estaPilaVacia llama a la función estaVacia de Lista
	bool estaPilaVacia() {
		return estaVacia();
	}

	void imprimirPila()
	{
		imprimir();
	} // fin de la función imprimir
}; // fin de la clase Pila

#endif
