#include "Carro.h"
#include <sstream>
#include <iostream>


Carro::Carro(string marc, string mod, float capAtual, float capMax, char id) : 
marca(marc), modelo(mod), ident(id), posicao(0), cronometro(0), energiaMax(capMax), energia(capAtual),velocidade(1), velMax(50), ocupado(false), sinalEmerg(false), avariado(false)//, n_energia(5)
{
		

	if (capAtual < 0)
		energia = 0;
	else if (capAtual > capMax)
		energia = energiaMax;
	else if (capMax > 100)
		energiaMax = 100;
		

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

int Carro::getPosicao()const {
	return posicao;
}

void Carro::setPosicao(int pos) {
	posicao = pos;
}

int Carro::getTempo()const {
	return cronometro;
}

void Carro::setTempo(int t) {
	cronometro = t;
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

float Carro::getEnergia() const {
	return energia;
}

float Carro::getEnergiaMax() const {
	return energiaMax;
}

void Carro::gastaEnergia() {
	if(energia -1 >= 0)
		energia = energia - 1;
}

void Carro::passaTempoCarro(int t, int distPista) {

	for (int i = 1; i <= t; i++) {
		if (posicao < distPista && posicao != -2)
		{
			if (energia != 0) {
				cout << ident <<  posicao << endl<< endl;
				setPosicao(getPosicao() + getVelocidade());
				cout << ident <<  posicao << endl<< endl;
				//gastaEnergia();
				cronometro++;
				if (posicao >= distPista) {
					posicao = -2;
				}
			}
		}
	}
}

string Carro::getAsString()const {		//tem coisas feitas para facilitar o teste das funções
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


string Carro::getStringDescricao()const {
	stringstream os;
	os << "Marca: " << marca<< " / Modelo: " << modelo
		<< " Identificacao: " << ident << " Energia: " << energia;
	if (getOcupado() == false)
		os << " Estado: carro livre" << endl;

	if (getOcupado() == true)
		os << " Estado: carro ocupado" << endl;

	return os.str();
}

int Carro::getVelocidade() {
	return velocidade;
}

int Carro::getVelocidadeMax() {
	return velMax;
}

void Carro::carregaBat(float n_energia) {

	if (velocidade == 0) {

		energia += n_energia;
		if (energia >= 100) {
			energia = 100;
			cout << "Bateria já atingiu " << energia << " mAh. Carregada ao máximo, nao necessita de mais carga" << endl;
		}
		else
			cout << "Carregou bateria com " << n_energia << " mAh." << endl;
		cout << "Bateria atingiu " << energia << " mAh. Falta " << energiaMax - energia << " para atingir o total." << endl;
	}
	else
		cout << "Carro ainda continua em andamento. Parar completamente o carro para efectuar carga." << endl;
	
}