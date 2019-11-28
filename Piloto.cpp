#include "Piloto.h"
#include "Carro.h"
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

void Piloto::acelera() { //A funçao acelera só aumenta em 1m/s de cada vez que é chamada? ou recebe o valor para aumentar?
	if (carro->getVelocidade() + 1 <= carro->getVelocidadeMax())
	{
		carro->setVelocidade(carro->getVelocidade() + 1);
	}
}

void Piloto::trava() {
	if (carro->getVelocidade() - 1 >= 0)
		carro->setVelocidade(carro->getVelocidade() - 1);
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

char Piloto::getIdCarro() const {
	if (carro != nullptr)
		return carro->getIdent();
}

void Piloto::passaTempoPiloto(int t, int dist) {
	carro->passaTempoCarro(t, dist);
}

string Piloto::getStringDescricao()const {
	ostringstream os;
	os << "Piloto: " << nome << endl;
	if (carro == nullptr)
		os << "Sem Carro atribuido" << endl;
	else
		os << "Com Carro atribuido" << endl;
	return os.str();

}

Carro* Piloto::getCarro()  const {
	return carro;
}

