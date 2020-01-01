#include "Piloto.h"
#include "Carro.h"
#include "Classificacao.h"
#include <sstream>
#include <iostream>

using namespace std;

Piloto::Piloto(string t, string n):tipo(t), nome(n),carro(nullptr),atualizado(false)
{
	//verificar o nome do piloto de forma a ser único. ir ao vector da dgv?
	//nome = n;
}
Piloto::Piloto(const Piloto & orig):tipo(orig.tipo),nome(orig.nome),carro(nullptr),atualizado(false) {

}

Piloto::~Piloto()
{

}

//bool Piloto::comparaPts(const Classificacao* c1, const Classificacao* c2) {
//
//	const int pts1 = c1->getPontos();
//	const int pts2 = c2->getPontos();
//
//	/*const Time aTime = a->getTime();
//	const Time bTime = b->getTime();*/
//
//	if (pts1 < pts2)
//		return true;
//	else
//		return false;
//
//}

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

bool Piloto::getAtualizado()const {
	return atualizado;
}
void Piloto::setAtualizado(bool a) {
	atualizado = a;
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

string Piloto::getTipo()const {
	return tipo;
}

void Piloto::passaTempoPiloto(int t, int dist) {
	carro->passaTempoCarro(t, dist);
}

void Piloto::acidente() {
	getCarro()->setDanificado(true);
}

void Piloto::carregaCarro(float n_energia) {
	getCarro()->carregaBat(n_energia);
}


string Piloto::getStringDescricao()const {
	ostringstream os;
	os << "Piloto: " << nome << " (" << tipo << ")"<< endl;
	if (carro == nullptr)
		os << "Sem Carro atribuido" << endl;
	else
		os << "Com Carro atribuido" << " -> " << getCarro()->getIdent() << endl;
	return os.str();

}

Carro* Piloto::getCarro()  const {
		return carro;
}

