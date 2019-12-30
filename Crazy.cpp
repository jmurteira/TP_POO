#include "Crazy.h"
#include "Piloto.h"
#include "Carro.h"

void Crazy::passaTempoPiloto(int t, int dist){
	getCarro()->passaTempoCarro(t, dist);
	//isto tem de ser diferente ofc xD
}