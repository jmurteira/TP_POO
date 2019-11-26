#include "Comandos.h"
#include "Piloto.h"
#include "Carro.h"
#include "Dgv.h"
#include <sstream>
#include <iostream>

Comandos::Comandos(){}


void Comandos::lerComando() {
	string op1;
	string op2;
	string op3;
	getline(cin, comando);
	istringstream is(comando);
	if (is >> op1) {
		if (comando == "carregaP")
			return;
		else if (comando == "carregaC")
			return;
		else if (comando == "carregaA")
			return;
		else if (comando == "cria")
			return;
		else if (comando == "apaga")
			return;
		else if (op1 == "entranocarro")
			return;
		else if (op1 ==  "saidocarro") {
			if (is >> op2)

				//m.getdgv->saidocarro(op2);
			else
				cout << "parametro inexistente" << endl;
		}
		else if (comando == "lista")

		return;
	}


}

