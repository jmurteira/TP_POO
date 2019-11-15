#include "Autodromo.h"
#include <sstream>



Autodromo::Autodromo(string n, int dist):nome(n), distancia(dist), iniciada(false), finalizada(false)
{
}


Autodromo::~Autodromo()
{
}

string Autodromo::getAsString()const {
	ostringstream os;
	os << "Autodromo de: " << nome << endl << "Distancia: " << distancia << " metros";
	return os.str();
}