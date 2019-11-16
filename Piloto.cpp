#include "Piloto.h"
#include <sstream>


Piloto::Piloto(string n, int t):tipo(t),carro(nullptr)
{
	//verificar o nome do piloto de forma a ser único
	//if()
	nome = n;
}


Piloto::~Piloto()
{

}

void Piloto::entrarCarro(Carro* c) {
	carro = c;
}

void Piloto::sairCarro() {
	carro = nullptr;
}

string Piloto::getNome() const {
	return nome;
}

int Piloto::getCarro() const {
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