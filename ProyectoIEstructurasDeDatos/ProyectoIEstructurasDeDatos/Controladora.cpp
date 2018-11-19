#include "Controladora.h"


Controladora::Controladora() {
	AjustarVentana(75, 47);
	srand(time(0));
	jugadorPrimero = NULL;
	cantJugadores = 0;
	bingos = NULL;//new ModeloBingo(1,1);


}

Controladora::Controladora(Jugador * j, int a, int b) {
	AjustarVentana(75, 47);
	srand(time(0));
	jugadorPrimero = j;
	bingos = new ModeloBingo(a, b);
}

Controladora::Controladora(string n, string ni, int, int a, int b) {
	AjustarVentana(75, 47);
	srand(time(0));
	jugadorPrimero = new Jugador("1");
	bingos = new ModeloBingo(a, b);
}

void Controladora::setJugadorPrimero(Jugador * jug) {
	jugadorPrimero = jug;
}
Jugador * Controladora::getJugadorPrimero() {
	return jugadorPrimero;
}
void Controladora::setBingos(ModeloBingo * b) {
	this->bingos = b;
}
void Controladora::setBingos(int a, int b) {
	this->bingos = new ModeloBingo(a, b);
}
ModeloBingo * Controladora::getBingos() {
	return bingos;
}

void Controladora::insertarJugador(Jugador *jug) {
	if (jugadorPrimero == NULL) {
		jugadorPrimero = jug;
	}
	else {
		jug->setJugadorSig(jugadorPrimero);
		jugadorPrimero = jug;
	}
}

Jugador * Controladora::getJugador(string s) {
	Jugador * j = getJugadorPrimero();
	while (j != NULL) {
		if (j->getNombre() == s) {
			return j;
		}
		j = j->getJugadorSig();
	}
	return NULL;
}


void Controladora::iniciar() {
	int p = 0;
	bool noSalir1;
	Interfaz::Presentacion();
	system("pause");
	do {
		noSalir1 = true;
		system("cls");
		Interfaz::BingoLogo();
		Interfaz::MenuPrincipal();
		p = Interfaz::validaEntero();
		switch (p) {
		case 1: {
			system("cls");
			Interfaz::Objetivo();
			system("pause");
			break;}
		case 2: {
			system("cls");
			MenuTipoJuego("1");
			break;}
		case 3: {
			noSalir1 = !salir();
			break;}
		default: {
			Interfaz::NumFueraRango();
			system("pause");
			break;}
		}
	} while (noSalir1);
}

void Controladora::MenuTipoJuego(string nick) {
	int o = 0;
	int cant = 0;
	bool noSalir2;
	do
	{
		noSalir2 = true;
		Interfaz::TipodeJuego();
		o = Interfaz::validaEntero();
		if (o == 10) {
			noSalir2 = false;
		}
		else {
			Interfaz::preguntaNumeroJugadores();
			cantJugadores = Interfaz::validaEntero();

			Interfaz::preguntaNumeroTableros();
			cant = Interfaz::validaEntero();
			if (o>0 && o<10) {
				/* ESTO VA EN EL HTML --AQUI SE CARGAN TODOS LOS CARTONES/JUGADORES */
				for (int i = 0; i < cantJugadores; i++) {
					cout << "Jugador #" << (i + 1) << endl;
					setBingos(o, (1 + rand() % cant));
					cout << bingos->toString();
					cout << endl;
				}

				completo(o, (1 + rand() % cantJugadores));
				noSalir2 = false;
			}
			else {
				if (o == 10) {
					noSalir2 = false;
				}
				else {
					Interfaz::NumFueraRango();
					system("pause");
				}
			}
		}
	} while (noSalir2);
}

bool Controladora::salir() {
	char r;
	Interfaz::salir();
	cin >> r;
	if (r == 's') {
		//	if(   //LA LISTA DE BINGOS EL MODELO !=NULL){
		//		delete// MODELO ;}
	}
	return r == 's';
}


void Controladora::gotoxy(int x, int y) {
	HANDLE Bingo;
	Bingo = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwpos;
	dwpos.X = x;
	dwpos.Y = y;

	SetConsoleCursorPosition(Bingo, dwpos);

}

void Controladora::imprimeTipoJuego(int n) {
	if (n == 1) { Interfaz::ModoJuego1(); }
	if (n == 2) { Interfaz::ModoJuego2(); }
	if (n == 3) { Interfaz::ModoJuego3(); }
	if (n == 4) { Interfaz::ModoJuego4(); }
	if (n == 5) { Interfaz::ModoJuego5(); }
	if (n == 6) { Interfaz::ModoJuego6(); }
	if (n == 7) { Interfaz::ModoJuego7(); }
	if (n == 8) { Interfaz::ModoJuego8(); }
	if (n == 9) { Interfaz::ModoJuego9(); }
}

int Controladora::generarNumero(Lista<int>& lis) {
	int numero = (rand() % 75) + 1;
	while (lis.encuentra(numero) == true) {
		numero = (rand() % 75) + 1;
	}
	lis.insertarElementoOrdenados(numero);
	return numero;
};

void Controladora::muestraNumeroYLetra(int var) {
	if (var>0 && var<16) { cout << 'B' << var; }
	else {
		if (var>15 && var<31) { cout << 'I' << var; }
		else {
			if (var>30 && var<46) { cout << 'N' << var; }
			else {
				if (var>45 && var<61) { cout << 'G' << var; }
				else {
					if (var>60 && var<76) { cout << 'O' << var; }
					else { cout << setw(2) << setfill('0') << var; }

				}

			}
		}
	}
}

bool Controladora::validaString(string var) {
	Pila<char>* tempPila = new Pila<char>;
	bool inserto = true;
	int i = 0;
	while (i<var.length() && inserto == true)
	{
		if (i % 2 == 0)
		{
			if (var[i] == '1' || var[i] == '2' || var[i] == '3' || var[i] == '4') {
				tempPila->push(var[i]);
			}
			else
			{
				inserto = false;
			}
		}
		else {
			if (var[i] == ',')
			{
				tempPila->push(var[i]);
			}
			else
			{
				inserto = false;
			}
		}
		i++;
	}
	delete tempPila;
	return inserto;
}

void Controladora::completo(int o, int jugador) {
	while (!(bingos->verificarCarton(o, 1))) {
		llenado();
	}
	ofstream archivo;
	/* ESTO VA EN EL HTML */
	//mostrar el ganador en pantalla
	cout << endl << endl;
	Interfaz::Felicidades();
	cout << "Jugador #" << jugador << endl;
	cout << bingos->getBingoPrimero()->toString();
	cout << "Se ha creado un archivo html con la informacion del juego llamado Salida";
	cout << endl << endl;
	archivo.open("Salida.html", ios::out);
	if (archivo.fail()) {
		cout << "No se pudo crear el html";
		exit(1);
	}
	archivo << "<!DOCTYPE html><html><head><body>";
	archivo << "<h3>" << "Parametros del Juego</h3>" <<"</head>";
	archivo << "Los tipos de Juego Son:"<<"<p>"<< "1-Carton Lleno" << "<p>"
		<< "2-Horizontal" << "<p>" << "3-Vertical" << "<p>"
		<< "4-Figura en L" << "<p>" << "5-Figura en C" << "<p>" << "6-Figura en U" << "<p>"
		<< "7-Figura en O" << "<p>" << "8-Diagonal" << "<p>" << "9-Figura en X" << "<p>";
	archivo << "El Tipo de juego elegido fue el número:" << bingos->getModo() << "<p>" << endl << endl;
	archivo << "La cantidad de cartones jugados por jugador fue de:" << bingos->getCantidadBingos()<<"<p>" << endl << endl;
	archivo << "Felicidades Jugador Numero " << jugador;
	archivo << "<p>"<< "ERES EL GANADOR!" <<"<p>"<< endl;
	archivo << "Los cartones del ganador son" << "<p>";
	archivo << "<table><td><tr>" << bingos->toString() << "</table></td></tr>";
	archivo << "</body></html>";
	archivo.close();
	system("pause");


}
bool Controladora::llenado() {
	Pila<int>* tempPilaInt = new Pila<int>;
	int var = 0;
	int aux = 0;
	int x = 0;
	int convertir;
	string varS;
	bool lleno = false;

	while (lleno == false) {
		var = generarNumero(lis);
		pilTombola.push(var);

		cout << "Tombola saca # -> ";
		muestraNumeroYLetra(var);
		cout << endl;

		varS = "1";
		int ix = 0;
		for (int i = 0; i<varS.length();i++) {
			ix = i % 2;
			if (ix == 0) {
				if (varS[i] == '1') {
					convertir = 1;
					tempPilaInt->push(convertir);
				}
				else {
					if (varS[i] == '2') {
						convertir = 2;
						tempPilaInt->push(convertir);
					}
					else {
						if (varS[i] == '3') {
							convertir = 3;
							tempPilaInt->push(convertir);
						}
						else {
							if (varS[i] == '4') {
								convertir = 4;
								tempPilaInt->push(convertir);
							}
						}
					}
				}
			}
		}
		int valorAux = 0;
		while (!tempPilaInt->estaPilaVacia()) {
			valorAux = tempPilaInt->pop();
			if (valorAux>bingos->getCantidadBingos()) {
				system("pause");
			}
			else {
				if (bingos->buscar(valorAux, var) == false) {
				}
			}
		}
		lleno = true;
	};
	return lleno;
}

bool Controladora::AjustarVentana(int Ancho, int Alto) {
	_COORD Coordenada;
	Coordenada.X = Ancho;
	Coordenada.Y = Alto;

	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Right = Ancho - 1;
	Rect.Bottom = Alto - 1;

	// Obtener el handle de la consola
	HANDLE hConsola = GetStdHandle(STD_OUTPUT_HANDLE);

	// Ajustar el buffer al nuevo tamaño
	SetConsoleScreenBufferSize(hConsola, Coordenada);

	// Cambiar tamaño de consola a lo especificado en el buffer
	SetConsoleWindowInfo(hConsola, TRUE, &Rect);

	SetConsoleActiveScreenBuffer(hConsola);
	return TRUE;
}