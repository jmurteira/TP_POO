#include "PilotoRapido.h"
#include "Carro.h"

PilotoRapido::PilotoRapido(string n): tresSeg(0), dezSeg(0), Piloto("PilotoRapido", n) {}

void PilotoRapido::passaTempoPiloto(int t, int dist){

	//ENERGIA, ACELERAÇÃO E MOVIMENTO
	if (((getCarro()->getEnergia()) / (getCarro()->getEnergiaMax())) > 0.5) {
		acelera();
		getCarro()->passaTempoCarro(t, dist);
	}
	else {
		if (getTresSeg() != 3) {
			getCarro()->passaTempoCarro(t, dist);
			setTresSeg(getTresSeg() + 1);
		}
		else if (getTresSeg() == 3) {
			acelera();
			getCarro()->passaTempoCarro(t, dist);
			setTresSeg(0);
		}
	}

	if (getDezSeg() != 10) {
		setDezSeg(getDezSeg() + 1);
	}
	else if (getDezSeg() == 10) {
		if (rand() % 10 == 9) {
			getCarro()->BotaoSOS(true);
		}
		setDezSeg(0);
	}
}


int PilotoRapido::getTresSeg()const {
	return tresSeg;
}

void PilotoRapido::setTresSeg(int s) {
	if (s >= 0 && s <= 3) {
		tresSeg = s;
	}
}

int PilotoRapido::getDezSeg()const {
	return dezSeg;
}

void PilotoRapido::setDezSeg(int s) {
	if (s >= 0 && s <= 10) {
		dezSeg = s;
	}
}
