#include "CrazyDriver.h"
#include "Carro.h"
#include <iostream>
CrazyDriver::CrazyDriver(string n):Piloto("CrazyDriver", n) {}




int CrazyDriver::inicio_aleatorio() {

	int aleatorio = rand() % 5 + 1;

	return aleatorio;
}


void CrazyDriver::passaTempoPiloto(int t, int dist) {
	int flag = 0;
	
	if (flag == 0){
		int tempo = getCarro()->getTempo() + t;
		getCarro()->setTempo(tempo);
	}
	if(getCarro()->getTempo() >= inicio_aleatorio()){
		getCarro()->passaTempoCarro(t, dist);
		flag = 1;
	}
}