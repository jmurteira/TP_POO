#include "Autodromo.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

int main() {

	Autodromo aut1 = Autodromo("Vienna", 4268);
	cout << aut1.getAsString();


	Carro c1 = Carro("Alfa", "Romeu", 1);
	c1.acelera();
	/*c1.acelera();
	c1.acelera();
	c1.acelera();
	c1.acelera();
	c1.acelera();
	c1.acelera();
	c1.acelera();
	c1.acelera();
	c1.acelera();*/
	c1.passaTempoCarro(548,5000);
	cout << endl << endl << c1.getAsString();

	Piloto p1 = Piloto("Vettel", 1);
	cout << endl << p1.getAsString();

	p1.entrarCarro(&c1);
	cout << endl << p1.getAsString();

	p1.sairCarro();
	cout << endl << p1.getAsString();

	cin.get();
}