#include "Interface.h"
#include "Dga.h"
#include "Dgv.h"
#include "Comandos.h"
#include "Carro.h"
#include "Piloto.h"
#include "Consola.h"



Interface::Interface(Dgv* d, Dga* da, Comandos* com) {
	dgv = d;
	dga = da;
	comando = com;
}


Dgv* Interface::getDgv() {
	return dgv;
}

Dga* Interface::getDga() {
	return dga;
}

void Interface::Simulador() {
	//imprimir as merdas todas bonitas da consola bla bla
	Consola::setBackgroundColor(Consola::BRANCO_CLARO);
	Consola::setTextColor(Consola::PRETO);

	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 10; j++) {
			Consola::gotoxy(i + 45, j);
			cout << " ";
		}
	}

	Consola::setBackgroundColor(Consola::PRETO);
	Consola::setTextColor(Consola::BRANCO);

	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 6; j++) {
			Consola::gotoxy(i + 52, j + 2);
			cout << " ";
		}
	}

	//nao percebo porque é que é preciso escrever 3x sair para sair
	do{
		comando->lerComando();

	
		if (comando->lerComando() == "carregaC")
			cout << "chupamisto" << endl;

	} while (comando->lerComando()!="sair");

}