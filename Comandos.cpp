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

	cout << "\nIntroduza comando: ";

	getline(cin, comando);
	istringstream is(comando);

	

	if (is >> op1) {
		if (comando == "carregaP")
			return 1;
		else if (comando == "carregaC")
			return 2;
		else if (comando == "carregaA")
			return 3;
		else if (comando == "cria")
			return 4;
		else if (comando == "apaga")
			return 5;
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
			//cout << Comandos().dgv->getDgv().descricaoCarro();
			cout << getDgv()->descricaoCarro();
			//return 9;
			return 0;
		}
	}


}

Dgv* Comandos::getDgv() {

	return dgv;
}


void Comandos::atribuiDgv(Dgv* d) {
	dgv = d;
}