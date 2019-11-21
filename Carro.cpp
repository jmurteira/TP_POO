#include "Carro.h"
#include <sstream>
#include <time.h>



Carro::Carro(string marc, string mod) : marca(marc), modelo(mod), posicao(0), cronometro(0), energiaMax(100), energia(75),velocidade(0), velMax(50), ocupado(false), sinalEmerg(false), avariado(false)
{
	srand(time(0));
	ident = 'a' + rand() % 26;

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

bool Carro::setOcupado() {

	return ocupado = true;
}

bool Carro::setDesocupado() {

	return ocupado = false;
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


string Carro::CarroOcupado()const {
	ostringstream os;
	os << "Carro: " << getIdent() << endl;
	if (getOcupado() == false)
		os << "estado: carro livre" << endl;

	if (getOcupado() == true)
		os << "estado: carro ocupado" << endl;

	return os.str();

}


void Carro::acelera() { //A fun�ao acelera s� aumenta em 1m/s de cada vez que � chamada? ou recebe o valor para aumentar?
	if(velocidade + 1 <= velMax)
		velocidade = velocidade + 1;
}

void Carro::trava() {
	if (velocidade - 1 >= 0)
		velocidade = velocidade - 1;
}

int Carro::getVelocidade() {
	return velocidade;
}