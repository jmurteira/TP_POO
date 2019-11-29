#include "Classificacao.h"


Classificacao::Classificacao() {

}

int Classificacao::getLugar() const {
	return lugar;
}

int Classificacao::getTempo() const {
	return tempo;
}

int Classificacao::getPontos() const {
	return pontos;
}

Piloto* Classificacao::getPiloto() const {
	return piloto;
}

void Classificacao::setLugar(int l) {

}

void Classificacao::setTempo(int t) {
	tempo = t;
}

void Classificacao::setPontos(int pts) {
	pontos = pts;
}

void Classificacao::setPiloto(Piloto* p) {
	piloto = p;
}
