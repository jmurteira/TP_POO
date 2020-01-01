#include "Classificacao.h"



Classificacao::Classificacao(int l, int t, int pts, Piloto* p) : lugar(l), pontos(pts), piloto(p) {

}

int Classificacao::getLugar() const {
	return lugar;
}

int Classificacao::getPontos() const {
	return pontos;
}

Piloto* Classificacao::getPiloto() const {
	return piloto;
}

void Classificacao::setLugar(int l) {

}

void Classificacao::setPontos(int pts) {
	pontos = pts;
}

void Classificacao::setPiloto(Piloto* p) {
	piloto = p;
}
