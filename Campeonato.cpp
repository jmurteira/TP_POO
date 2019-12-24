#include "Campeonato.h"
#include "Autodromo.h"
#include "Piloto.h"
#include "Carro.h"
#include "Classificacao.h"
#include "Dgv.h"

Campeonato::Campeonato(): dgv(nullptr), tam(0), realizadas(0)
{
}


Campeonato::~Campeonato()
{
}

bool Campeonato::iniciaCamp() {
	if (getCorridas().size() != 0) {
		//cout << "DIF ZERO";
		if (getIniciada() == false) {
			getCorridas()[realizadas]->setIniciada(true);
			//cout << getIniciada() << endl;
			return true;
		}
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
	for (vector<Autodromo*>::const_iterator it = corridas.cbegin();
		it != corridas.cend();
		it++) {
		if ((*it)->getIniciada() == true && (*it)->getFinalizada() == false) {
			(*it)->passatempo(t);
		}

		else if ((*it)->getIniciada() == false && (*it)->getFinalizada() == false)
			cout << "\nNenhuma corrida a decorrer\n\n";
	}	
}

int Campeonato::getTam() const {
	return tam;
}

void Campeonato::setCorrida(Autodromo* aut) {
	//corrida = aut;
	corridas.push_back(aut);
}

//Autodromo* Campeonato::getCorrida() const {
//	return corrida;
//}

vector <Autodromo*> Campeonato::getCorridas() const {
	return corridas;
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

			if (getDgv()->procuraPiloto(nome_piloto)->getCarro() != nullptr) {
				participantes.push_back(getDgv()->procuraPiloto(nome_piloto));
				//adicionaParticipante(getDgv()->procuraPiloto(nome_piloto));
				for (vector<Autodromo*>::const_iterator it = corridas.cbegin();
					it != corridas.cend();
					it++) {
					(*it)->adicionaParticipante(getDgv()->procuraPiloto(nome_piloto));
				}
			}
			else
				cout << "Piloto sem Carro atribuido!!!" << endl << "Introduza piloto associado a um carro." << endl;
		}
	}
	for (size_t i = 0; i < n_pista; i++) {
		cout << "Inserir id do carro: " << endl;
		cin >> ident_carro;
		if (getDgv()->procuraCarro(ident_carro) != nullptr) {
			if (getDgv()->procuraCarro(ident_carro)->getOcupado() == true)

				for (vector<Autodromo*>::const_iterator it = corridas.cbegin();
					it != corridas.cend();
					it++) {
					(*it)->adicionaCarro(getDgv()->procuraCarro(ident_carro));
				}
			else
				cout << "Carro sem piloto!!!" << endl << "Introduza carro associado a um piloto." << endl;
		}
	}

	if (participantes.size() >= 2 && getCorridas()[0]->getGaragem().size() >= 2)
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
	return corridas[realizadas]->getIniciada();
}

Autodromo* Campeonato::getCorridaAtiva() const {
	for (vector<Autodromo*>::const_iterator it = corridas.cbegin();
		it != corridas.cend();
		it++) {
		if ((*it)->getFinalizada() == false && (*it)->getIniciada() == true) {
			return (*it);
		}
	}
}

int Campeonato::getRealizadas() {
	return realizadas;
}

void Campeonato::carregabat(char ident, float q) {		//DUVIDA EM QUE CARROS É PARA CARREGAR A BATERIA E QUAIS OS REQUISITOS (SE É PRECISO ESTAR NO CAMPEONATO/CORRIDA)
														//NESTE MOMENTO ESTÁ A CARREGAR TODOS OS CARROS DA DGV (NAO TEM VERIFICAÇÃO)
	//Autodromo * a = getCorridaAtiva();
	Piloto * p = getDgv()->procuraPilotoPorCarro(ident);
	//Piloto * partic = a->procuraPilotoPorCarro(p->getCarro());
	if(p != nullptr)
		p->carregaCarro(q);
	//partic->carregaCarro(q);
}

void Campeonato::setRealizadas(int n) {
	realizadas = n;
}

bool Campeonato::finalizaCorrida() {
	
	int emCorrida = 0;
	
	for (vector<Piloto*>::const_iterator it = getCorridaAtiva()->getPista().cbegin();
		it != getCorridaAtiva()->getPista().cend();
		it++) {

		if ((*it)->getCarro()->getPosicao() != -2)
		{
			emCorrida++;
		}
	}

	if (emCorrida > 0)
		return false;
	else {
		setRealizadas(getRealizadas() + 1);
		getCorridaAtiva()->setFinalizada(true);
		return true;
	}
}