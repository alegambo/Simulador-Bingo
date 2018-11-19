#pragma once
#pragma once
#include "Interfaz.h"
#include "Jugador.h"
#include "ModeloBingo.h"
#include "Pila.h"
#include <iostream>
#include <cctype>
#include <windows.h>
#include <fstream>
#include <stdlib.h>
using namespace std;

class Controladora {
private:
	Lista<int> lis;
	Pila<int> pilTombola;
	int cantJugadores;
	Jugador * jugadorPrimero;
	ModeloBingo * bingos;
public:
	Controladora();
	Controladora(Jugador *, int, int);
	Controladora(string, string, int, int, int);
	void setJugadorPrimero(Jugador *);
	Jugador * getJugadorPrimero();
	void insertarJugador(Jugador *);
	Jugador * getJugador(string);
	void setBingos(ModeloBingo *);
	void setBingos(int, int);
	ModeloBingo *getBingos();
	void iniciar();
	void MenuTipoJuego(string);
	bool salir();
	void gotoxy(int, int); //permite el control de la ubicacion de las salidas en consola en los puntos x,y
	int generarNumero(Lista<int>&);

	void muestraNumeroYLetra(int);
	bool validaString(string);
	bool llenado();
	void completo(int, int);
	bool AjustarVentana(int, int);
	void imprimeTipoJuego(int);
};
