#include "Carro.h"
#include <sstream>



Carro::Carro(string marc, string mod,int id) : marca(marc), modelo(mod), ident(id), posicao(-2), cronometro(0), energiaMax(100), energia(75),velocidade(0), velMax(50), ocupado(false), sinalEmerg(false), avariado(false)
{
}


Carro::~Carro()
{
}

void Carro::atualizaCronometro(int t, int distPista) {

	for (int i = 1; i <= t; i++) {
		if (posicao < distPista)
		{
			posicao = posicao + velocidade;
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
	return os.str();
}