#include "Campeonato.h"
#include "Autodromo.h"
#include "Piloto.h"
#include "Classificacao.h"

Campeonato::Campeonato()
{
}


Campeonato::~Campeonato()
{
}

void Campeonato::passatempo(int t) {
	/*for (vector<Autodromo*>::const_iterator it = corrida.cbegin();
		it != corrida.cend();
		it++) {

	}*/
	//S� H� UMA CORRIDA
	if (corrida->getIniciada() == true && corrida->getFinalizada() == false)
		corrida->passatempo(t);
	else if (corrida->getIniciada() == false && corrida->getFinalizada() == false)
		cout << "\nNenhuma corrida a decorrer\n\n";
}

int Campeonato::getTam() const {
	return tam;
}

void Campeonato::setCorrida(Autodromo* aut) {
	corrida = aut;
}

void Campeonato::iniciaCamp() {
	if (corrida != nullptr) {
		if (corrida->getIniciada() == false) {
			corrida->setIniciada(true);
		}
	}
	else
		cout << " ";
}


//ATUALIZAR CLASSIF GERAL POIS TEMPOS CLASSIF ESPECIFICA DE CADA CORRIDA (NAO SEI SE � PRECISO NESTA META)
//void Campeonato::atualizaClassif() {
//	if (corrida->getFinalizada() == true && corrida->getClassifAtualizada() == false)
//	{
//		for (vector<Piloto*>::const_iterator it = corrida->getPista().cbegin();
//			it != corrida->getPista().cend();
//			it++) {
//
//			
//			if ((*it)->getCarro()->getPosicao() == -2 && (*it)->getAtualizado() == false) {
//				
//				int i = 0;
//
//				Classificacao* c = new Classificacao(i + 1, (*it)->getCarro()->getTempo(), 10/*Como ficam todos empatados, 10pts para todos*/, (*it));
//				classGeral.push_back(c);
//
//				(*it)->setAtualizado(true);
//
//				i++;
//			}
//		}
//	}
//}