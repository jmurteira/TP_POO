#include "Campeonato.h"
#include "Autodromo.h"
#include "Piloto.h"
#include "Carro.h"
#include "Classificacao.h"
#include "Dgv.h"

Campeonato::Campeonato():corrida(nullptr), dgv(nullptr)
{
}


Campeonato::~Campeonato()
{
}

bool Campeonato::iniciaCamp() {
	if (getCorrida() != nullptr) {
		//cout << "DIF NULLPTR";
		if (getIniciada() == false) {
			//if(participantes.size() == 0)
			//cout << "FALSE";
			getCorrida()->setIniciada(true);
			cout << getIniciada() << endl;

			return true;
		}
		//else
			//cout << "TRUE";
	}
	else
		return false;
}

void Campeonato::passatempo(int t) {
	/*for (vector<Autodromo*>::const_iterator it = corrida.cbegin();
		it != corrida.cend();
		it++) {

	}*/
	//SÓ HÁ UMA CORRIDA
	//corrida->setIniciada(true);
	

	if (getCorrida()->getIniciada() == true ){
		if (getCorrida()->getFinalizada() == false)
			getCorrida()->passatempo(t);
	}
	else if (getIniciada() == false && getCorrida()->getFinalizada() == false)
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

int Campeonato::getAutorizados() const {
	vector <Piloto*> p = dgv->getPilotos();
	int i = 0;
	for (vector<Piloto*>::const_iterator it = p.cbegin();
		it != p.cend();
		it++) {
		if ((*it)->getCarro() != nullptr)
			i++;
	}

	return i;
}


//melhorar a funcao depois
bool Campeonato::addParticipantes() {
	int n_pista, n_garagem;
	string nome_piloto;
	char ident_carro;
	cout << "Indique o numero de participantes a introduzir na pista: ";
	cin >> n_pista;

	int autorizados = getAutorizados();



	if (n_pista < 2) {
		n_pista = 2;
		cout << "Capacidade minima dos autodromos e de: " << "2" << " carros. Adicionar 2 carros." << endl;
	}
	if (n_pista > 6) {
		n_pista = 6;
		cout << "Capacidade maxima dos autodromos e de: " << "6" << " carros. Adicionar 6 carros." << endl;
	}
	if (autorizados < n_pista) {
		cout << "Numero insuficiente de participantes validos" << endl << "Introduza <modo1> para voltar ao menu principal." << endl;
		return false;
	}
	for (size_t i = 0; i < n_pista; i++) {
		cout << "Inserir nome do piloto: " << endl;
		cin >> nome_piloto;
		if (getDgv()->procuraPiloto(nome_piloto) != nullptr ) {

			if (getDgv()->procuraPiloto(nome_piloto)->getCarro() != nullptr)
				getCorrida()->adicionaParticipante(getDgv()->procuraPiloto(nome_piloto));
			else
				cout << "Piloto sem Carro atribuido!!!" << endl << "Introduza piloto associado a um carro." << endl;
		}
	}
	for (size_t i = 0; i < n_pista; i++) {
		cout << "Inserir id do carro: " << endl;
		cin >> ident_carro;
		if (getDgv()->procuraCarro(ident_carro) != nullptr) {
			if (getDgv()->procuraCarro(ident_carro)->getOcupado() == true)
				getCorrida()->adicionaCarro(getDgv()->procuraCarro(ident_carro));
			else
				cout << "Carro sem piloto!!!" << endl << "Introduza carro associado a um piloto." << endl;

			cout << getCorrida()->getGaragem().size() << endl;
		}
	}

	if (getCorrida()->getPista().size() >= 2 && getCorrida()->getGaragem().size() >= 2)
		return iniciaCamp();
	else
		return false;
	

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

Dgv* Campeonato::getDgv()const{
	return dgv;
}
void Campeonato::setDgv(Dgv* d) {
	dgv = d;
}

bool Campeonato::getIniciada()const {
	return corrida->getIniciada();
}