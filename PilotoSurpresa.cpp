#include "PilotoSurpresa.h"

#include "Carro.h"

PilotoSurpresa::PilotoSurpresa(string n) : distAcelera(0), Piloto("PilotoSurpresa", n) {}

void PilotoSurpresa::passaTempoPiloto(int t, int dist, vector<int> p) {

	//ENERGIA, ACELERAÇÃO E MOVIMENTO
	setDistAcelera();

	if (getCarro()->getPosicao() % distAcelera == 0) {
		acelera();
	}
	if (p.size() > 1) {
		if (verificaPrimeiro(p) == false) {
			if (getCarro()->getPosicao() > dist / 2) {
				turbo();
			}
		}
	}
	getCarro()->passaTempoCarro(t, dist);
}

bool PilotoSurpresa::turbo() {
	if (getCarro()->getTurbo() > 0) {
		getCarro()->setVelocidade(getCarro()->getVelocidade() + 10);
		getCarro()->setTurbo(getCarro()->getTurbo() - 1);
		return true;
	}
	else
		return false;
}

void PilotoSurpresa::setDistAcelera() {
	if (distAcelera == 0) {
		distAcelera = rand() % 5 + 1;
	}
}