#pragma once
#pragma once
#pragma once
#include <iostream>
#include <sstream>
using namespace std;


class Interfaz {
public:
	static void Presentacion();
	static void TipodeJuego();
	static void Estudiantes();
	static void infoIncorrecta();
	static void EscogeTipo();

	static void preguntaNumeroTableros();
	static void preguntaNumeroJugadores();
	static void muestraNombreJugador();
	static void muestraTipodeJuego();
	static void muestraNumeroRandom();
	static void BingoLogo();
	static void MenuPrincipal();
	static void Regresar();
	static void Objetivo();
	static void ErrorValorInvalido();
	static void Felicidades();
	static void salir();
	static void NumFueraRango();

	static int validaEntero();

	static void ModoJuego1();
	static void ModoJuego2();
	static void ModoJuego3();
	static void ModoJuego4();
	static void ModoJuego5();
	static void ModoJuego6();
	static void ModoJuego7();
	static void ModoJuego8();
	static void ModoJuego9();
};

