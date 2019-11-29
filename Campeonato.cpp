#include "Campeonato.h"




Campeonato::Campeonato()
{
	for (unsigned int i = 0; i < 1; i++)
		corrida[i] = NULL;
}


Campeonato::~Campeonato()
{
}

void Campeonato::passatempo(int t) {
	/*for (vector<Autodromo*>::const_iterator it = corrida.cbegin();
		it != corrida.cend();
		it++) {

	}*/
	//SÓ HÁ UMA CORRIDA
	if (corrida[0]->getIniciada() == true && corrida[0]->getFinalizada() == false)
		corrida[0]->passatempo(t);
}

int Campeonato::getTam() const {
	return tam;
}

void Campeonato::atualizaClass() {
	if (corrida[0]->getFinalizada() == true && corrida[0]->getClassifAtualizada() == false)
	{
		for (vector<Piloto*>::const_iterator it = corrida[0]->getPista().cbegin();
			it != corrida[0]->getPista().cend();
			it++) {

			if ((*it)->getCarro()->getPosicao() == -2) {
				
				int i = 1;



				//classGeral[i] = (*it);

				i++;
			}
		}
	}
}