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
		
	}
}

//vector <Piloto *> Autodromo::getPista()const {
//	return pista;
//}
//
//vector <Carro> Autodromo::getGaragem()const {
//	//return garagem;
//}

string Autodromo::getAsString()const {
	ostringstream os;
	os << "Autodromo de: " << nome << endl << "Distancia: " << distancia << " metros";
	return os.str();
}