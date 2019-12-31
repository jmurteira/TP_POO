#include "PilotoRapido.h"
#include "Carro.h"

PilotoRapido::PilotoRapido(string n):Piloto("PilotoRapido", n) {}

void PilotoRapido::passaTempoPiloto(int t, int dist){

	if (((getCarro()->getEnergia()) / (getCarro()->getEnergiaMax())) > 0.5) {
		acelera();
		//getCarro()->passaTempoCarro(t, dist);
	}
	//else
		getCarro()->passaTempoCarro(t, dist);
}

