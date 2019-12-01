#include "Campeonato.h"
#include "Autodromo.h"
#include "Piloto.h"
#include "Classificacao.h"
#include "Dgv.h"

Campeonato::Campeonato()
{
}


Campeonato::~Campeonato()
{
}

void Campeonato::iniciaCamp() {
	if (corrida != nullptr) {
		//cout << "DIF NULLPTR";
		if (corrida->getIniciada() == false) {
			//if(participantes.size() == 0)
			//cout << "FALSE";
			corrida->setIniciada(true);
		}
		//else
			//cout << "TRUE";
	}
	else
		cout << " ";
}

void Campeonato::passatempo(int t) {
	/*for (vector<Autodromo*>::const_iterator it = corrida.cbegin();
		it != corrida.cend();
		it++) {

	}*/
	//SÓ HÁ UMA CORRIDA

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

Autodromo* Campeonato::getCorrida() const {
	return corrida;
}

//melhorar a funcao depois
void Campeonato::addParticipantes(int n_pista, int n_garagem) {
	cout << "Indique o numero de carros a introduzir na pista: ";
	cin >> n_pista;
	if (n_pista < 2) {
		n_pista = 2;
		cout << "Capacidade minima dos autodromos e de: " << "2" << " carros. Adicionar 2 carros." << endl;
	}
	if (n_pista > 6) {
		n_pista = 6;
		cout << "Capacidade maxima dos autodromos e de: " << "6" << " carros. Adicionar 6 carros." << endl;
	}
	while (corrida->getPista().size() < n_pista) {
		

	}

}





//ATUALIZAR CLASSIF GERAL POIS TEMPOS CLASSIF ESPECIFICA DE CADA CORRIDA (NAO SEI SE É PRECISO NESTA META)
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