#pragma once
#pragma once
#ifndef JUGADOR_H
#define	JUGADOR_H
#include<iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <cstdlib>
#include <stdio.h>
#include "Interfaz.h"
using namespace std;

class Jugador {
private:
	string nombre;
	Jugador * jugadorSig;//Para lista de jugadores en la controladora

public:
	Jugador();
	Jugador(string);
	void setNombre(string);
	void setJugadorSig(Jugador *);
	Jugador * getJugadorSig();
	string getNombre();
	string toString();
};

#endif	/* JUGADOR_H */
