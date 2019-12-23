#include "Interface.h"
#include "Dga.h"
#include "Dgv.h"
#include "Comandos.h"
#include "Carro.h"
#include "Piloto.h"
#include "Consola.h"
#include "Campeonato.h"
#include "Autodromo.h"
#include "Logica.h"


Interface::Interface(Logica* log) {
	logica = log;
}


Logica* Interface::getLogica() {
	return logica;
}

void Interface::Simulador() {
	getLogica()->Simulador();
}