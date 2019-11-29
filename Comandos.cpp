#include "Comandos.h"
#include "Campeonato.h"
#include "Piloto.h"
#include "Carro.h"
#include "Dgv.h"
#include "Dga.h"
#include <sstream>
#include <iostream>

Comandos::Comandos(){}


void Comandos::lerComando() {
	string op1;
	string op2;
	string op3;
	char op4;
	char op5;
	string op6;
	string op7;
	

	
	do {
		cout << "\nIntroduza comando: ";
		getline(cin, comando);
		istringstream is(comando);
		if (is >> op1) {
			if (op1 == "carregaP") {
				if (is >> op2)
					getDgv()->carregaP(op2);
			}
			else if (op1 == "carregaC") {
				if (is >> op2)
					getDgv()->carregaC(op2);
			}
			else if (op1 == "carregaA")
				return;
			else if (op1 == "cria") {
				if (is >> op4) {
					if (op4 == 'c') {
						is >> op6 >> op7 >> op2 >> op3;
						getDgv()->novoCarro(stoi(op6), stoi(op7), op2, op3);
					}
					else if (op4 == 'p'){
						is >> op2 >> op3;
						getDgv()->novoPiloto(op2,op3);
					}
					else if (op4 == 'a') {
						is >> op2 >> op3;
						
					}
				}
			}
			else if (op1 == "apaga") {
				if (is >> op4) {
					if (op4 == 'c') {
						if (is >> op5)
							getDgv()->apagaCarro(op5);
					}
					else if (op4 == 'p') {
						if (is >> op2)
							getDgv()->apagaPiloto(op2);
					}
					else if (op4 == 'a')
						cout << "apaga autodromo";
					else
						cout << "parametro errado. apaga <letraTipo> identificador (c - carro, p - piloto, a - autodromo)" << endl;
				}
			}

			else if (op1 == "entranocarro") {
				if (is >> op4)
					if (is >> op2)
						getDgv()->entraNoCarro(op4, op2);
			}
			else if (op1 == "saidocarro") {
				if (is >> op4)
					getDgv()->saiDoCarro(op4);
				else
					return;
				//cout << "parametro inexistente" << endl;
			}
			else if (op1 == "lista") {
					cout << "\n\n\nLISTA\n\n\n";
				cout << getDgv()->descricaoCarro();
				cout << getDgv()->descricaoPiloto();
			}
			else if (op1 == "sair") {
				return;
			}
			else if (op1 == "passatempo") {
				if (is >> op2)
				{
					getCamp()->passatempo(stoi(op2));
				}	
			}
			else
				cout << "comando inexistente" << endl;
		}
	} while (op1 != "sair");

}

Dgv* Comandos::getDgv() {

	return dgv;
}

Campeonato* Comandos::getCamp() {

	return camp;
}


void Comandos::atribuiDgv(Dgv* d) {
	dgv = d;
}