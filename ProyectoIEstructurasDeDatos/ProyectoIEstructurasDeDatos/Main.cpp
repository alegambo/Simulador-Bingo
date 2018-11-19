#include "Controladora.h"
#include "Interfaz.h"
#include <iostream>;
#include <iomanip>
#include <fstream>
#include <stdlib.h>

using namespace std;


int main() {

	Controladora *x = new Controladora();
	x->iniciar();

	delete x;

	cin.get();
	return 0;

}