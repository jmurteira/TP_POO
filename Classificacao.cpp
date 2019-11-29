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