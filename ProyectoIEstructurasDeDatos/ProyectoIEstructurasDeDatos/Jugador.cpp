#include "Jugador.h"

Jugador::Jugador() {
	nombre = "";
	jugadorSig = NULL;
}

Jugador::Jugador(string pNombre) {
	nombre = pNombre;
}

void Jugador::setNombre(string pNombre) {
	nombre = pNombre;
}

void Jugador::setJugadorSig(Jugador * jug) {
	jugadorSig = jug;
}
Jugador * Jugador::getJugadorSig() {
	return jugadorSig;
}

string Jugador::getNombre() {
	return nombre;
}

string Jugador::toString() {
	stringstream s;
	s << "Nombre:" << getNombre() << endl;
	return s.str();
}
