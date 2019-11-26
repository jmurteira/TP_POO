#include "Carro.h"
#include "Dgv.h"
#include <sstream>
#include <time.h>
#include <iostream>


Carro::Carro(string marc, string mod, char id) : marca(marc), modelo(mod), ident(id), posicao(0), cronometro(0), energiaMax(100), energia(75),velocidade(0), velMax(50), ocupado(false), sinalEmerg(false), avariado(false), n_energia(5)
{
	
		srand(time(0));
		ident = ident + rand() % 26;

		//verificar com o vector dos carros do arquivo que n�o repetem os ids
	
	//estao alguns valores inicializados por defeito
}


Carro::~Carro()
{
}

char Carro::getIdent()const {
	
	return ident;
}

bool Carro::getOcupado()const {
	return ocupado;
}

void Carro::setOcupado() {
	ocupado = true;
}

void Carro::setDesocupado() {
	ocupado = false;
}

void Carro::setVelocidade(int x) {
	velocidade = x;
}


void Carro::passaTempoCarro(int t, int distPista) {

	for (int i = 1; i <= t; i++) {
		if (posicao < distPista)
		{
			posicao = posicao + velocidade;
			cronometro++;
		}
	}

}

string Carro::getAsString()const {		//tem coisas feitas para facilitar o teste das fun��es
	ostringstream os;
	os << "Carro com identificador: " << ident << endl << marca << modelo << endl;
	if (avariado == false)
		os << "Carro operacional" << endl;
	if (avariado == true)
		os << "Carro avariado" << endl;
	if(posicao > 0)
		os << "Situa-se no metro " << posicao << " da pista" << endl;
	if (posicao == 0)
		os << "Situa-se na partida" << endl;
	if (posicao == -1)
		os << "Situa-se na garagem" << endl;
	/*if (posicao == -2)
		os << "Nao se encontra presente" << endl;*/

	return os.str();
}


string Carro::getStringOcupado()const {
	ostringstream os;
	os << "Carro: " << getIdent() << endl;
	if (getOcupado() == false)
		os << "estado: carro livre" << endl;

	if (getOcupado() == true)
		os << "estado: carro ocupado" << endl;

	return os.str();

}




int Carro::getVelocidade() {
	return velocidade;
}

int Carro::getVelocidadeMax() {
	return velMax;
}

void Carro::carregaBat() {

	cout << "Carro: " << getIdent() << endl;

	if (velocidade == 0) {

		energia += n_energia;
		if (energia >= 100) {
			energia = 100;
			cout << "Bateria j� atingiu " << energia << " mAh. Carregada ao m�ximo, nao necessita de mais carga" << endl;
		}
		else
			cout << "Carregou bateria com " << n_energia << " mAh." << endl;
		cout << "Bateria atingiu " << energia << " mAh. Falta " << energiaMax - energia << " para atingir o total." << endl;
	}
	else
		cout << "Carro ainda continua em andamento. Parar completamente o carro para efectuar carga." << endl;
	
}