#include "Carro.h"



Carro::Carro()
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