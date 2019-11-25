#include "Piloto.h"
#include <sstream>
#include <iostream>

using namespace std;

Piloto::Piloto(string n, int t):tipo(t),carro(nullptr)
{
	//verificar o nome do piloto de forma a ser único. ir ao vector da dgv?
	//if()
	nome = n;
	
}


Piloto::~Piloto()
{

}

void Piloto::entrarCarro(Carro* c) {
	
	if (c->getOcupado() == false) {

		carro = c;
		carro->setOcupado();
	}
	
}

void Piloto::sairCarro() {
	carro->setDesocupado();
	carro = nullptr;
	
}


string Piloto::getNome() const {
	return nome;
}

char Piloto::getCarro() const {
	if (carro != nullptr)
		return carro->getIdent();
}


string Piloto::getAsString()const {
	ostringstream os;
	os << "Piloto: " << nome << endl;
	if (carro == nullptr)
		os << "Sem Carro atribuido" << endl;
	else
		os << "Com Carro atribuido" << endl;
	return os.str();

}

