#include "Autodromo.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

int main() {

	Autodromo aut1 = Autodromo("Vienna", 4268);
	cout << aut1.getAsString();

	//aut1.garagem->push_back();

	//aut1.

	Carro c1 = Carro("Alfa", "Romeu", 1);

	cout << endl << endl << c1.getAsString();

	cin.get();
}