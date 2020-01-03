#include "CrazyDriver.h"
#include "Carro.h"
#include "Classificacao.h"

CrazyDriver::CrazyDriver(string n):Piloto("CrazyDriver", n) {}


int CrazyDriver::inicio_aleatorio() {

	int aleatorio = rand() % 5 + 1;

	return aleatorio;
}


void CrazyDriver::passaTempoPiloto(int t, int dist, vector<int> p) {
	int flag = 0;

	if (getCarro()->getEnergia() == 0) {
		getCarro()->BotaoSOS(true);
	}
	else {
		if (flag == 0) {
			int tempo = getCarro()->getTempo() + t;
			getCarro()->setTempo(tempo);
		}
		if (getCarro()->getTempo() >= inicio_aleatorio()) {
			if (p.size() > 1) {
				if (verificaUltimo(p) != false) {
					if (verificaPrimeiro(p) != true) {
						acelera();
						getCarro()->passaTempoCarro(t, dist);
						flag = 1;
					}
					else
					{
						getCarro()->passaTempoCarro(t, dist);
						flag = 1;
					}
				}
				else
					trava();
			}
		}
	}
}

//
//void CrazyDriver::perguntaPista() {
//}

