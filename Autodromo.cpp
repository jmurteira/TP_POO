#include "Autodromo.h"
#include "Piloto.h"
#include "Carro.h"
//#include "Dgv.h"
#include "Interface.h"
#include <sstream>



Autodromo::Autodromo(int cap, int dist, string n):capacidade(cap), distancia(dist), nome(n),  iniciada(false), finalizada(false), classifAtualizada(false) //classifAtualizada???
{
	if (cap < 2){
		capacidade = 2; //minimo definido no enunciado
		cout << "A capacidade minima da pista e de 2 participantes. Capacidade definida a 2" << endl;
	}
	else if (cap > 6){
		capacidade = 6; //considerando a capacidade maxima dos autodromos = 6
		cout << "A capacidade maxima da pista e de 6 participantes. Capacidade definida a 6" << endl;
	}
	if (dist < 100){
		distancia = 100;
		cout << "A distancia minima da pista e de 100 metros. Distancia definida a 100" << endl;
	}
	else if (dist > 1000){
		distancia = 1000;
		cout << "A distancia maxima da pista é de 1000 metros. Capacidade definida a 1000" << endl;
	}
}


Autodromo::~Autodromo()
{
}

string Autodromo::getNome() const{
	return nome;
}

void Autodromo::passatempo(int t){

		for (vector<Piloto*>::const_iterator it = pista.cbegin();
		it != pista.cend();
		it++) {
			//(*it)->getCarro()
			(*it)->passaTempoPiloto(t, getDistancia());
		}
}

void Autodromo::atualizaClassif() {
	for (int i = 0; i < capacidade; i++) {
		
	}
}

bool Autodromo::getIniciada() const {
	return iniciada;
}

void Autodromo::setIniciada(bool inic) {
	iniciada = inic;
	for (vector<Piloto*>::const_iterator it = pista.cbegin();
		it != pista.cend();
		it++) {
		(*it)->setAtualizado(false);
		(*it)->getCarro()->setPosicao(0);
	}
}

int Autodromo::getDistancia() const {
	return distancia;
}

bool Autodromo::getFinalizada() const {
	return finalizada;
}

void Autodromo::setFinalizada(bool fin) {
	finalizada = fin;
}

bool Autodromo::getClassifAtualizada() const {
	return classifAtualizada;
}

void Autodromo::acidente(char ident, int flag) {
	for (vector<Piloto*>::const_iterator it = pista.cbegin();
		it != pista.cend();) {
		if ((*it)->getCarro()->getIdent() == ident) {
			//apagar carro da pista uma vez que está danificado irremediavelmente
			(*it)->acidente();
			adicionaCarro((*it)->getCarro());
			if(flag == 1){
				(*it)->sairCarro();
			}
			it = pista.erase(it);
		}
		else
			++it;
	}
}

void Autodromo::destroiCarro(char ident, int flag) {
	for (vector<Piloto*>::const_iterator it = pista.cbegin();
		it != pista.cend();) {
		if ((*it)->getCarro()->getIdent() == ident) {
			if (flag == 1) {
				(*it)->sairCarro();
			}
			it = pista.erase(it);
		}
		else
			++it;
	}
}


vector <Piloto*> Autodromo::getPista() const {
	return pista;
}

vector <Carro*> Autodromo::getGaragem() const {
	return garagem;
}

Piloto* Autodromo::procuraPilotoPorCarro(Carro * c) const {
	//Carro* c = procuraCarro(ident);
	for (vector<Piloto*>::const_iterator it = pista.cbegin();
		it != pista.cend();
		it++)
		if ((*it)->getCarro() == c)
			return *it;
	cout << "Carro nao encontrado";
	return nullptr;
}

void Autodromo::carregabat(Carro * c, float q) {
	Piloto* p = procuraPilotoPorCarro(c);
	if (p != nullptr) {
		p->carregaCarro(q);
	}
	else
		return;
}

//vector <Piloto *> Autodromo::getPista()const {
//	return pista;
//}
//
//vector <Carro> Autodromo::getGaragem()const {
//	//return garagem;
//}

string Autodromo::getStringDescricao()const {
	ostringstream os;
	os << "Autodromo de: " << nome << endl << "Distancia: " << distancia << " metros" << endl << "Capacidade: " << capacidade << " carros" <<endl;
	return os.str();
}


//Dgv* Autodromo::getDgv()const{
//	return dgv;
//}
//void Autodromo::setDgv(Dgv* d) {
//	dgv = d;
//}


void Autodromo::adicionaParticipante(Piloto* p) {
	pista.push_back(p);
}

void Autodromo::adicionaCarro(Carro* c) {
	garagem.push_back(c);
}



string Autodromo::listacarros() const {
	string res = "\n---------------Carros inscritos no campeonato---------------\n";
	res += "Carros na pista:\n";
	vector<Piloto*> copiapilotos = getPista();
	vector<Carro*> copiacarros = getGaragem();
	for (vector<Piloto*>::const_iterator it = copiapilotos.begin();
		it != copiapilotos.end();
		it++)
		res += "\n" + (*it)->getCarro()->getStringDescricao();
	res += "\nCarros na garagem:\n";
	for (vector<Carro*>::const_iterator it = copiacarros.begin();
		it != copiacarros.end();
		it++){
		if((*it)->getOcupado() == false)
			res += "\n" + (*it)->getStringDescricao();
	}
	res += "\nCarregar qualquer tecla para continuar";
	return res;
}
