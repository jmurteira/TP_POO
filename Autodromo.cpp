#include "Autodromo.h"
#include <sstream>



Autodromo::Autodromo(string n, int dist):nome(n), distancia(dist), iniciada(false), finalizada(false)
{
}


Autodromo::~Autodromo()
{
}

string Autodromo::getNome() const{
	return nome;
}

//void Autodromo::addParticipante(string n) {
//	pista->push_back(...);
//}

void Autodromo::passatempo(int t) {
		for (vector<Piloto*>::const_iterator it = pista.cbegin();
		it != pista.cend();
		it++) {
		
			(*it)->passaTempoPiloto(t, distancia);
		}
}

void Autodromo::atualizaClassif() {
	for (int i = 0; i < participantes; i++) {
		
	}
}

bool Autodromo::getIniciada() const {
	return iniciada;
}

bool Autodromo::getFinalizada() const {
	return finalizada;
}

bool Autodromo::getClassifAtualizada() const {
	return classifAtualizada;
}

vector <Piloto*> Autodromo::getPista() const {
	return pista;
}

vector <Carro*> Autodromo::getGaragem() const {
	return garagem;
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