#include "Comandos.h"
#include "Piloto.h"
#include "Carro.h"
#include "Dgv.h"
#include <sstream>
#include <iostream>

Comandos::Comandos(){}


int Comandos::lerComando() {
	string op1;
	string op2;
	string op3;
	char op4;
	char op5;

	

	
	do {
		cout << "\nIntroduza comando: ";
		getline(cin, comando);
		istringstream is(comando);
		if (is >> op1) {
			if (op1 == "carregaP")
				return 1;
			else if (op1 == "carregaC")
				return 2;
			else if (op1 == "carregaA")
				return 3;
			else if (op1 == "cria")
				return 4;
			else if (op1 == "apaga") {
				if (is >> op4) {
					if (op4 == 'c') {
						if (is >> op5)
							getDgv()->apagaCarro(op5);
					}
					else if (op4 == 'p')
						cout << "apaga piloto";
					else if (op4 == 'a')
						cout << "apaga autodromo";
					else
						cout << "parametro errado. apaga <letraTipo> identificador (c - carro, p - piloto, a - autodromo)" << endl;
				}
			}

			else if (op1 == "entranocarro")
				return 6;
			else if (op1 == "saidocarro") {
				if (is >> op2)
					return 7;
				//m.getdgv->saidocarro(op2);
				else
					return 8;
				//cout << "parametro inexistente" << endl;
			}
			else if (op1 == "lista") {
				cout << getDgv()->descricaoCarro();
				cout << getDgv()->descricaoPiloto();
			}
			else if (op1 == "sair")
				cout << "\nsair" << endl;
			else
				cout << "comando inexistente" << endl;
		}
	} while (op1 != "sair");

}

Dgv* Comandos::getDgv() {

	return dgv;
}


void Comandos::atribuiDgv(Dgv* d) {
	dgv = d;
}