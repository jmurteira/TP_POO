#include "Campeonato.h"
#include "Autodromo.h"
#include "Piloto.h"
#include "Carro.h"
#include "Classificacao.h"
#include "Dgv.h"
#include "Consola.h"

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
	for (int i = 0; i < t; i++) {

		if (getCorridaAtiva() != nullptr) {
			getCorridaAtiva()->passatempo(1);
			finalizaCorrida(getPistaAtiva());//TESTE
		}
	}
	if (getCorridaAtiva() == nullptr)
		cout << "\nNenhuma corrida a decorrer\n\n";
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

vector <Piloto*> Campeonato::getParticipantes() const {
	return participantes;
}

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
	return nullptr;
}

vector<Piloto*> Campeonato::getPistaAtiva() const {
	return getCorridaAtiva()->getPista();
}

int Campeonato::getRealizadas() {
	return realizadas;
}

void Campeonato::carregabat(char ident, float q) {		//NAO ESTÁ A FUNCIOANAR (não percebo o porquê)
														//DUVIDA EM QUE CARROS É PARA CARREGAR A BATERIA E QUAIS OS REQUISITOS (SE É PRECISO ESTAR NO CAMPEONATO/CORRIDA)
														//NESTE MOMENTO ESTÁ A CARREGAR TODOS OS CARROS DA DGV (NAO TEM VERIFICAÇÃO)
	//Autodromo * a = getCorridaAtiva();
	Piloto * p = getDgv()->procuraPilotoPorCarro(ident);
	//Piloto * partic = a->procuraPilotoPorCarro(p->getCarro());
	if(p != nullptr)
		p->carregaCarro(q);
	//partic->carregaCarro(q);
}

void Campeonato::carregaTudo() {
	const vector<Piloto*> copia = getPistaAtiva();
	vector<Piloto*>::const_iterator it;
	for (it = copia.begin();
		it != copia.end();
		it++) {
		float q = (*it)->getCarro()->getEnergiaMax();
		(*it)->carregaCarro(q);
		(*it)->getCarro()->setVelocidade(1);
	}
}

void Campeonato::acidente(char ident) {
	if (getCorridaAtiva() == nullptr) {
		cout << "Nenhuma corrida a decorrer!";
		cin.get();
	}
	else{
		getCorridaAtiva()->acidente(ident);
		retiracarrocampeonato(ident);
	}
}

void Campeonato::setRealizadas(int n) {
	realizadas = n;
}

bool Campeonato::finalizaCorrida(vector<Piloto*> pista) {
	
	int emCorrida = 0;

	if (pista.size() == 0)
		return false;

	for (vector<Piloto*>::const_iterator it = pista.cbegin();
		it != pista.cend();
		it++) {

		if ((*it)->getCarro()->getPosicao() != -2)
		{
			emCorrida++;
		}
	}

	if (emCorrida > 0)
		return false;

	else if (emCorrida == 0) {
		setRealizadas(getRealizadas() + 1);
		getCorridaAtiva()->setFinalizada(true);
		return true;
	}
}

void Campeonato::proximaCorrida() {
	if (getCorridas().size() > realizadas) {
		getCorridas()[getRealizadas()]->setIniciada(true);
		Consola::gotoxy(75, 20);
		cout << "Proxima Corrida: "<< getCorridaAtiva()->getNome();
		cin.get();
		return;
	}
	else {
		Consola::gotoxy(75, 20);
		cout << "Ja estao concluidas todas as corridas!";
		cin.get();
	}
}

void Campeonato::retiracarrocampeonato(char ident) {
	vector<Piloto*> copia = getCorridaAtiva()->getPista();
	vector<Piloto*>::const_iterator it;
	for (it = copia.cbegin();
		it != copia.cend();
		it++) {
		if ((*it)->getCarro()->getIdent() == ident) {
			getCorridaAtiva()->adicionaCarro((*it)->getCarro());
			(*it)->sairCarro();
			delete (*it);
			it = copia.erase(it);
		}
	}
		/*for (size_t i = 0; i < getCorridaAtiva()->getPista().size(); i++) {
			if (getCorridaAtiva()->getPista()[i]->getCarro()->getIdent() == ident) {
				getCorridaAtiva()->adicionaCarro(getParticipantes()[i]->getCarro());
				getCorridaAtiva()->getPista()[i]->sairCarro();
				getCorridaAtiva()->getPista().erase(getCorridaAtiva()->getPista().end() - i);
			}
		}*/
}
		

