#include "Interfaz.h"

void Interfaz::Presentacion() {
	cout << "***************************************" << endl;
	cout << " Proyecto Bingo " << endl;
	cout << " Curso: Estructuras de Datos " << endl;
	cout << " Profesor: Steven Brenes " << endl;
	cout << " Ciclo II 2017 " << endl;
	Interfaz::Estudiantes();
	cout << "***************************************" << endl;

}

void Interfaz::TipodeJuego() {
	system("cls");
	cout << " ----------------Seleccione el tipo de juego que desea jugar------------" << endl;
	cout << "1.- Carton lleno" << endl;
	cout << "2.- Horizontal" << endl;
	cout << "3.- Vertical" << endl;
	cout << "4.- Figura en L" << endl;
	cout << "5.- Figura en C" << endl;
	cout << "6.- Figura en U" << endl;
	cout << "7.- Figura en O" << endl;
	cout << "8.- Diagonal" << endl;
	cout << "9.- Figura en X" << endl;
	cout << "10.-    Regresar" << endl;
	cout << endl << endl;
}

void Interfaz::Estudiantes() {
	cout << "---------------------------------------------" << endl;
	cout << "Nombre de los Estudiantes:" << endl;
	cout << "Cristian Díaz Jiménez  Cedula: 304740934" << endl;
	cout << "Alejandro Gamboa  Cedula: 115790444" << endl;
	cout << "---------------------------------------------" << endl;
	cout << endl << endl;
}


void Interfaz::ModoJuego1() {
	cout << "Carton Lleno";
}
void Interfaz::ModoJuego2() {
	cout << "Horizontal";
}
void Interfaz::ModoJuego3() {
	cout << "Vertical";

}
void Interfaz::ModoJuego4() {
	cout << "Figura en L";

}
void Interfaz::ModoJuego5() {
	cout << "Figura en C";

}
void Interfaz::ModoJuego6() {
	cout << "Figura en U";

}
void Interfaz::ModoJuego7() {
	cout << "Figura en O";

}
void Interfaz::ModoJuego8() {
	cout << "Diagonal";

}
void Interfaz::ModoJuego9() {
	cout << "Figura en X";
}

void Interfaz::infoIncorrecta() {
	cout << "Informacion incorrecta" << endl;
	cout << "favor ingrese solo los numeros del carton que desea llenar separdo por ," << endl;
}

void Interfaz::EscogeTipo() {
	cout << "Escoja el tipo de Juego que desea Jugar" << endl;
}

void Interfaz::preguntaNumeroTableros() {
	cout << "Favor ingrese el numero de Tableros que van a jugar cada jugador: " << endl;
}

void Interfaz::preguntaNumeroJugadores() {
	cout << "Favor ingrese el numero de Jugadores: " << endl;
}

void Interfaz::muestraNombreJugador() {
	cout << "Jugador: ";
}
void Interfaz::muestraTipodeJuego() {
	cout << "Tipo de Juego: ";
}
void Interfaz::muestraNumeroRandom() {
	cout << "Numero: ";
}

void Interfaz::BingoLogo() {
	cout << "  ******        *******     **        *     *********      ******* " << endl;
	cout << "  *      *         *        *  *      *     *             *       *" << endl;
	cout << "  *     *          *        *   *     *     *             *       *" << endl;
	cout << "  ******           *        *    *    *     * * * *       *       *" << endl;
	cout << "  *     *          *        *     *   *     *       *     *       *" << endl;
	cout << "  *      *         *        *      *  *     *             *       *" << endl;
	cout << "  ******        *******     *        **     *******        *******" << endl;
	cout << endl << endl;

}
void Interfaz::MenuPrincipal() {
	cout << "------------------------------------------------------ " << endl;
	cout << "Ingrese el numero de la opcion a la que quiere acceder" << endl;
	cout << "-------------------------------------------------------" << endl;
	cout << "1.- Objetivo" << endl;
	cout << "2.- Jugar" << endl;
	cout << "3.- Salir" << endl;
	cout << endl << endl;
}

void Interfaz::Regresar() {
	cout << "99.-Salir\t";
}
void Interfaz::Objetivo() {
	cout << "----------------------------------------------------------------------------------------" << endl;
	cout << " El siguiente trabajo consiste en un juego de Bingo" << endl;
	cout << "el cual debera poseer una lista de Jugadores con diferentes cantidad de Bingos" << endl;
	cout << "Además se escogera entre los diferentes tipos" << endl;
	cout << "de bingo cuando ya alla seleccionado el tipo de juego se preguntara cuantos" << endl;
	cout << "cartones desea jugar; postreriormente y iniciara la simulacion. " << endl;
	cout << "Al final el Programa Dara un html con el carton ganador y la lista de numeros." << endl;
	cout << endl << endl;
}

void Interfaz::ErrorValorInvalido() {
	cout << "Error el numero que marcó es un valor invalido" << endl;
}

void Interfaz::Felicidades() {
	cout << "FELICIDADES USTED HA GANADO" << endl;
}

void Interfaz::salir() {
	system("cls");
	cout << "Esta seguro que quiere salir?" << endl;
	cout << "Digite s para salir o cualquier otra tecla para regresar" << endl;
}

void  Interfaz::NumFueraRango() {
	system("cls");
	cout << "El valor que usted digito está fuera de rango favor corrija" << endl;
}

int Interfaz::validaEntero() {
	int q;
	cin >> q;
	while (cin.fail()) {
		cout << "Valor invalido, digite un valor correcto: " << endl;
		cin.clear();
		cin.ignore();
		cin >> q;
	}
	return q;
}
