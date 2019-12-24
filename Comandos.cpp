#include "Comandos.h"
#include "Campeonato.h"
#include "Autodromo.h"
#include "Piloto.h"
#include "Carro.h"
#include "Dgv.h"
#include "Dga.h"
#include <sstream>
#include <iostream>

Comandos::Comandos(){}


string Comandos::lerComandoModo1() {
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
	//do {
		cout << "\nIntroduza comando: ";
		getline(cin, comando);
		istringstream is(comando);
		if (is >> op1) {
			if (op1 == "carregaP") {
				if (is >> op2){
					getDgv()->carregaP(op2);
					return op1;
				}
				else 
					cout << "numero de parametros errado. carregaP <nomeFicheiro> " << endl;
			}
			else if (op1 == "carregaC") {
				if (is >> op2){
					getDgv()->carregaC(op2);
					return op1;
				}
				else
					cout << "numero de parametros errado. carregaC <nomeFicheiro> " << endl;
			}
			else if (op1 == "carregaA") {
				if (is >> op2){
					getDga()->carregaA(op2);
					return op1;
				}
				else
					cout << "numero de parametros errado. carregaA <nomeFicheiro> " << endl;
			}
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
							return "cria c";
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
						if (is >> op6){
							op3.append(" ");
							op3.append(op6);
						}
						if (contador == 2) {
							getDgv()->novoPiloto(op2, op3);
							contador = 0;
							return "cria p";
							
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
						if (is >> num2)
							contador += 1;
						if (is >> op2)
							contador += 1;
						if (contador == 3) {
							if (getDga()->getDgaSize() == 0){
								getDga()->novoAutodromo(num1, num2, op2);
								//getDga()->procuraAutodromo(op2)->setDgv(getDgv());
								return "cria a";
							}
							else
								cout << "ja existe um autodromo." << endl;
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
						if (is >> op5){
							getDgv()->apagaCarro(op5);
							return "apaga c";
						}
					}
					else if (op4 == "p") {
						if (is >> op2){
							getDgv()->apagaPiloto(op2);
							return "apaga p";
						}
					}
					else if (op4 == "a") { //falta isto! ver se os carros também são destruidos
						if (is >> op2) {
							getDga()->apagaAutodromo(op2);
							return "apaga a";
						}
					}
					else
						cout << "parametro errado. apaga <letraTipo> identificador (c - carro, p - piloto, a - autodromo)" << endl;
				}
			}

			else if (op1 == "entranocarro") {
				if (is >> op5){
					if (is >> op2){
						getDgv()->entraNoCarro(op5, op2);
						return op1;
					}
					else
						cout << "numero de parametros errado. entranocarro <letraCarro> <nomePiloto>" << endl;
				}
				else
					cout << "numero de parametros errado. entranocarro <letraCarro> <nomePiloto>" << endl;
			}
			else if (op1 == "saidocarro") {
				if (is >> op5){
					getDgv()->saiDoCarro(op5);
					return op1;
				}
				else
					cout << "numero de parametros errado. saidocarro <letraCarro>" << endl;
			}
			else if (op1 == "lista") {
				cout << "\n\nLista de objectos existentes\n";
				cout << getDgv()->descricaoCarro();
				cout << getDgv()->descricaoPiloto();
				cout << getDga()->descricaoAutodromo();
				return op1;
			}
			else if (op1 == "sair") {
				return op1;
			}
			else if (op1 == "campeonato") {
			if (is >> op2)
			{
				if (getDga()->procuraAutodromo(op2) != nullptr) {
					cout << "\n\nCOMECOU O CAMPEONATO\n" << endl;
					setCamp(&(Campeonato()));
					getCamp()->setDgv(dgv);
					getCamp()->setCorrida(getDga()->procuraAutodromo(op2));
					if (getCamp()->addParticipantes() == true)
						return op1;
					else
						return " ";
				}
				else
					cout << "o autodromo " << op2 << " nao existe" << endl;
			}
			else
				cout << "numero de parametros errado. campeonato <A1> <A2> ... <An>" << endl;
			}
			else
				cout << "comando inexistente" << endl;
				return "";
		}
		else
			return "";
	//} while (op1 != "sair");
		
}

string Comandos::lerComandoModo2() {
	string op1;
	int op2;
	char ch1;
	float flt1;
	cout << "\nIntroduza comando: ";
	getline(cin, comando);
	istringstream is(comando);
	if (is >> op1) {
		if (op1 == "passatempo") {
			if (is >> op2) {
				cout << getCamp()->getCorridaAtiva()->getNome() << endl;
				getCamp()->passatempo(op2);
				return op1;
			}
			else
				cout << "numero de parametros errado. passatempo <n>" << endl;
		}
		else if (op1 == "carregabat") {
			if (is >> ch1) {
				if (is >> flt1) {
					getCamp()->carregabat(ch1, flt1);
				}
				else
					cout << "numero de parametros errado. carregabat <letraCarro> <Q>";
			}
			else
				cout << "numero de parametros errado. carregabat <letraCarro> <Q>";
		}
		else if (op1 == "carregatudo") {
			if (is >> op1) {
				cout << "CARREGA TUDO"; // alterar
			}
		}
		else if (op1 == "modo1") {
			return op1;
		}
		else
			cout << "comando inexistente" << endl;
		return "";
	}
	else
		return "";
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

void Comandos::setCamp(Campeonato* c) {
	camp = new Campeonato();
	//camp = c;
}


void Comandos::atribuiDgv(Dgv* d) {
	dgv = d;
}

void Comandos::atribuiDga(Dga* da) {
	dga = da;
}

string Comandos::getStringListaComandos()const {
	ostringstream os;
	os << "\nLista de Comandos: " << endl << endl;
	os << "Modo 1: Definicoes" << endl;
	os << "carregaP <nomeFicheiro>" << endl;
	os << "carregaC <nomeFicheiro>" << endl;
	os << "carregaA <nomeFicheiro>" << endl;
	os << "cria <letraTipo> <dados do objeto>" << endl;
	os << "apaga <letraTipo> identificador" << endl;
	os << "entranocarro <letraCarro> <nomePiloto>" << endl;
	os << "saidocarro <letraCarro>" << endl;
	os << "lista" << endl;
	os << "sair" << endl << endl;
	os << "Modo 2: Campeonato" << endl;
	os << "campeonato <A1> <A2> ... <An>" << endl;
	os << "passatempo <n>" << endl;
	os << "--------------------------" << endl;
	os << "Nota: chamar comando campeonato para entrar no modo2" << endl;
	os << "--------------------------" << endl;
	return os.str();
}

string Comandos::getStringListaComandosModo2()const {
	ostringstream os;
	os << "\nLista de Comandos: " << endl << endl;
	os << "Modo 2: Campeonato" << endl;
	os << "campeonato <A1> <A2> ... <An>" << endl;
	os << "passatempo <n>" << endl;
	os << "modo1 (voltar ao Modo 1)" << endl;
	return os.str();
}