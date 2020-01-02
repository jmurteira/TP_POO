#include "PilotoSurpresa.h"

#include "Carro.h"

PilotoSurpresa::PilotoSurpresa(string n) : Piloto("PilotoSurpresa", n) {}

void PilotoSurpresa::passaTempoPiloto(int t, int dist) {

	//ENERGIA, ACELERAÇÃO E MOVIMENTO
	if (getCarro()->getPosicao() % 5 == 0) {
		acelera();
	}
	if (getCarro()->getPosicao() > dist/2){
		turbo();
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