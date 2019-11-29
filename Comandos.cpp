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
	string op4;
	char op5;
	string op6;
	string op7;
	int num1;
	int num2;

	int contador = 0; //para verificar se o numero de parametros do comando está certo
	
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
					if (op4 == "c") {
						if (is >> num1)
							contador += 1;
						if (is >> num2)
							contador += 1;
						if (is >> op2)
							contador += 1;
						if (is >> op3) {
							contador += 1;
						}
						if (contador == 4) {
							getDgv()->novoCarro(num1, num2, op2, op3);
							contador = 0;
						}
						else if (contador != 4) {
							cout << "numero de parametros errado. cria <c> <dados do objeto> (energia energiaMax Marca Modelo)" << endl;
							contador = 0;
						}
					}
					else if (op4 == "p") {
						if (is >> op2){
							if (op2 != "classico"){
								cout << "introduzir tipo de piloto. ainda so existe do tipo classico." << endl;
							}
							else
								contador += 1;
						}
						if (is >> op3)
							contador += 1;
						if (contador == 2) {
							getDgv()->novoPiloto(op2, op3);
							contador = 0;
						}
						else if (contador != 2) {
							cout << "numero de parametros errado. cria <p> <dados do objeto> (tipo nome)" << endl;
							contador = 0;
						}
					}
					else if (op4 == "a") {
						if (is >> num1) {
							contador += 1;
						}
						if (is >> op1)
							contador += 1;
						if (is >> op2)
							contador += 1;
						if (contador == 3) {
							//getDgv()->novoPiloto(op2, op3);
							getDga()->novoAutodromo(num1, op1);
							contador = 0;
						}
						else if (contador != 3) {
							cout << "numero de parametros errado. cria <a> <dados do objeto> (N comprimento nome)" << endl;
							contador = 0;
						}

					}
					else
						cout << "parametro errado. cria <letraTipo> (c - carro, p - piloto, a - autodromo) <dados do objeto>" << endl;
				}
				else
					cout << "numero de parametros errado. cria <letraTipo> (c - carro, p - piloto, a - autodromo) <dados do objeto>" << endl;
			}
			else if (op1 == "apaga") {
				if (is >> op4) {
					if (op4 == "c") {
						if (is >> op5)
							getDgv()->apagaCarro(op5);
					}
					else if (op4 == "p") {
						if (is >> op2)
							getDgv()->apagaPiloto(op2);
					}
					else if (op4 == "a")
						cout << "apaga autodromo";
					else
						cout << "parametro errado. apaga <letraTipo> identificador (c - carro, p - piloto, a - autodromo)" << endl;
				}
			}

			else if (op1 == "entranocarro") {
				if (is >> op5)
					if (is >> op2)
						getDgv()->entraNoCarro(op5, op2);
			}
			else if (op1 == "saidocarro") {
				if (is >> op5)
					getDgv()->saiDoCarro(op5);
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
			else if (op1 == "campeonato") {
				if (is >> op2) {
					cout << "\n\nCOMECOU O CAMPEONATO\n" << endl;
					getCamp();
				}
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

Dga* Comandos::getDga() {
	return dga;
}

Campeonato* Comandos::getCamp() {

	return camp;
}


void Comandos::atribuiDgv(Dgv* d) {
	dgv = d;
}