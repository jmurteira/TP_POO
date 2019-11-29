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

void Campeonato::iniciaCamp() {
	if (corrida[0]->getIniciada() == false) {
		corrida[0]->setIniciada(true);
	}
}


//ATUALIZAR CLASSIF GERAL POIS TEMPOS CLASSIF ESPECIFICA DE CADA CORRIDA (NAO SEI SE É PRECISO NESTA META)
void Campeonato::atualizaClassif() {
	if (corrida[0]->getFinalizada() == true && corrida[0]->getClassifAtualizada() == false)
	{
		for (vector<Piloto*>::const_iterator it = corrida[0]->getPista().cbegin();
			it != corrida[0]->getPista().cend();
			it++) {

			if ((*it)->getCarro()->getPosicao() == -2 && (*it)->getAtualizado() == false) {
				
				int i = 0;

				Classificacao* c = new Classificacao(i + 1, (*it)->getCarro()->getTempo(), 10/*Como ficam todos empatados, 10pts para todos*/, (*it));
				classGeral.push_back(c);

				(*it)->setAtualizado(true);

				i++;
			}
		}
	}
}