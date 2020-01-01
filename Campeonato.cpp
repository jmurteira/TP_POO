#include "Campeonato.h"
#include "Autodromo.h"
#include "Piloto.h"
#include "Carro.h"
#include "Classificacao.h"
#include "Dgv.h"
#include "Consola.h"
#include <algorithm>

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
			
			vector<Piloto*> copia = getPistaAtiva();
			for (vector<Piloto*>::const_iterator it = copia.cbegin(); it != copia.cend(); it++) {

				if ((*it)->getCarro()->getTempo() > 0 && (*it)->getTipo() == "CrazyDriver") {
					//if (rand() % 5 == 0) {		//ACHO QUE ISTO NÃO É 5% é para aí 20%
					/*ACHO QUE É ASSIM:*/
					if (rand() % 20 == 10) {
						acidente((*it)->getIdCarro());
					}
				}
			}
			
			finalizaCorrida(getPistaAtiva());//TESTE
			atualizaClassifGeral();

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
void Campeonato::atualizaClassifGeral() {
	if (getCorridaAtiva() == nullptr) {
		
		if (realizadas - 1 < 0) {
			if (classGeral.size() == 0) {
				for (int i = 0; i < getCorridas()[realizadas - 1]->getClassificacao().size(); i++)
					classGeral.push_back(getCorridas()[realizadas - 1]->getClassificacao()[i]);
			}
			else {
				for (vector<Classificacao*>::const_iterator it = classGeral.cbegin();
					it != classGeral.cend();
					it++) {
					for (int i = 0; i < getCorridas()[realizadas - 1]->getClassificacao().size(); i++) {
						if ((*it)->getPiloto() == getCorridas()[realizadas - 1]->getClassificacao()[i]->getPiloto()) {
							(*it)->setPontos((*it)->getPontos() + getCorridas()[realizadas - 1]->getClassificacao()[i]->getPontos);
						}
					}
				}
				sort(classGeral.begin(), classGeral.end(), comparaPts);
				int i = 0;
				for (vector<Classificacao*>::const_iterator it = classGeral.cbegin();
					it != classGeral.cend();
					it++) {
					(*it)->setLugar(i + 1);
					i++;
				}
			}
		}

	}
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
}

bool Campeonato::comparaPts(Classificacao c1, Classificacao c2){
	return (c1.getPontos() < c2.getPontos());
}

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

//falta remover o piloto da dgv, visto que morre
//meter uma mensagem a dizer que houve um acidente, que o carro em causa ficou danificado e que o piloto morreu
void Campeonato::acidente(char ident) {
	int flag = 0; //na ultima corrida, pode tirar o piloto do carro
	if (getCorridaAtiva() == nullptr) {
		cout << "Nenhuma corrida a decorrer!";
		cin.get();
	}
	else{
		for (vector<Autodromo*>::const_iterator it = corridas.begin();
			it != corridas.end();
			it++){
			if (it == (corridas.end() - 1))
				flag = 1;
			(*it)->acidente(ident, flag);
			}
	}
}

void Campeonato::destroiCarro(char ident) {
	//usar erase para retirar primeiro das pistas
	int flag = 0; //na ultima corrida, pode tirar o piloto do carro e remover o carro da dgv
	if (getCorridaAtiva() == nullptr) {
		cout << "Nenhuma corrida a decorrer!";
		cin.get();
	}
	else {
		for (vector<Autodromo*>::const_iterator it = corridas.begin();
			it != corridas.end();
			it++) {
			if (it == (corridas.end() - 1))
				flag = 1;
			(*it)->destroiCarro(ident, flag);
		}
	}
}


void Campeonato::setRealizadas(int n) {
	realizadas = n;
}

bool Campeonato::finalizaCorrida(vector<Piloto*> pista) {
	
	vector<Piloto*> copia = pista;

	int emCorrida = 0;

	if (pista.size() == 0)
		return false;

	for (vector<Piloto*>::const_iterator it = copia.cbegin();
		it != copia.cend();
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
		if (getCorridas()[getRealizadas()]->getFinalizada() == false) {
			Consola::gotoxy(75, 20);
			cout << "Corrida ainda em andamento!";
			cin.get();
			return;
		}
		else {
			getCorridas()[getRealizadas()]->setIniciada(true);
			Consola::gotoxy(75, 20);
			cout << "Proxima Corrida: " << getCorridaAtiva()->getNome();
			cin.get();
			return;
		}
	}
	else {
		Consola::gotoxy(75, 20);
		cout << "Ja estao concluidas todas as corridas!";
		cin.get();
	}
}

		