#include "Autodromo.h"
#include <sstream>



Autodromo::Autodromo(string n, int dist):nome(n), distancia(dist), iniciada(false), finalizada(false)
{
}


Autodromo::~Autodromo()
{
}

void Autodromo::atualizaClassif() {
	for (int i = 0; i < participantes; i++) {
		//if(pista[i]) ???
	}
}

string Autodromo::getAsString()const {
	ostringstream os;
	os << "Autodromo de: " << nome << endl << "Distancia: " << distancia << " metros";
	return os.str();
}