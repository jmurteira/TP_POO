#include "Carro.h"
#include <sstream>



Carro::Carro(string marc, string mod,int id) : marca(marc), modelo(mod), ident(id), posicao(0), cronometro(0), energiaMax(100), energia(75),velocidade(0), velMax(50), ocupado(false), sinalEmerg(false), avariado(false)
{
}


Carro::~Carro()
{
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

string Carro::getAsString()const {
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

void Carro::acelera() {
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