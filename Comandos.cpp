#include "Comandos.h"
#include "Campeonato.h"
#include "Autodromo.h"
#include "Piloto.h"
#include "Carro.h"
#include "Dgv.h"
#include "Dga.h"
#include "Consola.h"
#include <sstream>
#include <iostream>
#include <vector>

Comandos::Comandos():dga(nullptr), dgv(nullptr), camp(nullptr) {}


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


	int contador = 0; //para verificar se o numero de parametros do comando est� certo
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
			else if (op1 == "savedgv") {
				if (is >> op2) {
					saveDgv(op2);
					return op1;
				}
				else
					cout << "numero de parametros errado. savedgv <nome> " << endl;
			}
			else if (op1 == "loaddgv") {
				if (is >> op2) {
					alteraDgv(op2);
					return op1;
				}
				else
					cout << "numero de parametros errado. loaddgv <nome> " << endl;
			}
			else if (op1 == "deldgv") {
				if (is >> op2) {
					delDgv(op2);
					return op1;
				}
				else
					cout << "numero de parametros errado. deldgv <nome> " << endl;
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
					else if (op4 == "a") { //falta isto! ver se os carros tamb�m s�o destruidos
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
					while (is >> op2) {
						getCamp()->setCorrida(getDga()->procuraAutodromo(op2));
					}
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
	string str1;
	char ch1;
	float flt1;
	Consola::gotoxy(75, 17);
	cout << "Introduza comando:";
	Consola::gotoxy(75, 18);
	cout << " -> ";
	getline(cin, comando);
	istringstream is(comando);
	if (is >> op1) {
		if (op1 == "passatempo") {
			if (is >> op2) {
				//cout << getCamp()->getCorridaAtiva()->getNome() << endl;
				if(getCamp()->getCorridaAtiva() != nullptr)
					getCamp()->passatempo(op2);
				return op1;
			}
			else
				cout << "numero de parametros errado. passatempo <n>" << endl;
		}
		else if (op1 == "corrida") {
			getCamp()->proximaCorrida();
			return op1;
		}
		else if (op1 == "listacarros") {
			if (getCamp()->getCorridaAtiva() != nullptr) {
				Consola::gotoxy(75, 20);
				cout << getCamp()->getCorridaAtiva()->listacarros();
				cin.get();
			}
			//cout << "ListarCarros";
			return op1;
		}
		else if (op1 == "carregabat") {
			if (is >> ch1) {
				if (is >> flt1) {
					if (getCamp()->getCorridaAtiva() != nullptr) {
						getCamp()->carregabat(ch1, flt1);
					}
					return op1;
				}
				else
					cout << "numero de parametros errado. carregabat <letraCarro> <Q>";
			}
			else
				cout << "numero de parametros errado. carregabat <letraCarro> <Q>";
		}
		else if (op1 == "carregatudo") {
			if (getCamp()->getCorridaAtiva() != nullptr)
				getCamp()->carregaTudo();
			return op1;
		}
		else if (op1 == "acidente") {
			if (is >> ch1) {
				if (getCamp()->getCorridaAtiva() != nullptr) {
					getCamp()->acidente(ch1);
					cout << "Acidente no carro " << ch1;
				}
				return op1;
			}
			else
				cout << "numero de parametros errado. acidente <letraCarro>";
		}
		else if (op1 == "stop") {
			if (is >> op2) {
				if (getCamp()->getCorridaAtiva() != nullptr)
					getCamp()->stop(str1);
				return op1;
			}
			else
				cout << "numero de parametros errado. stop <nomePiloto>";
		}
		else if (op1 == "destroi") {
			if (is >> ch1) {
				if (getCamp()->getCorridaAtiva() != nullptr) {
					getCamp()->destroiCarro(ch1);
					getDgv()->apagaCarro(ch1);
				}
				return op1;
			}
			else
				cout << "numero de parametros errado. destroi <letraCarro> <Q>";
		}
		else if (op1 == "log") {
			cout << "log";
			return op1;
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

vector<Dgv*> Comandos::getVectorDgvs()const {
	return vectorDGVS;
}

void Comandos::atribuiDgv(Dgv* d) {
	dgv = d;
	for (vector<Dgv*>::const_iterator it = vectorDGVS.cbegin();
		it != vectorDGVS.cend();
		it++)
		if ((*it) != nullptr && (*it)->getDgvId() == d->getDgvId())
			return;
	vectorDGVS.push_back(d);
}

void Comandos::alteraDgv(string id) {
	for (vector<Dgv*>::const_iterator it = vectorDGVS.cbegin();
		it != vectorDGVS.cend();
		it++) {
		if ((*it) != nullptr && (*it)->getDgvId() == id) {
			atribuiDgv(*it);
			cout << "DGV com o nome \"" << id << "\" passou a ativa!" << endl;
			return;
		}
	}
	cout << "Nao existe DGV com o nome \"" << id << "\"!" << endl <<
		"Por favor altere o nome para poder efetuar a alteracao!" << endl;
}

void Comandos::saveDgv(string id) {
	bool existe = false;
	for (vector<Dgv*>::const_iterator it = vectorDGVS.cbegin();
		it != vectorDGVS.cend();
		it++)
		if ((*it) != nullptr && (*it)->getDgvId() == id)
			existe = true;
	if (existe == false) {
		vectorDGVS.push_back(new Dgv(id, *dgv));
		cout << "DGV gravada com o nome \"" << id << "\"!" << endl;
	}
	else
		cout << "Ja existe uma DGV gravada com o nome \"" << id << "\"!" << endl <<
		"Por favor altere o nome para poder efetuar a gravacao!" << endl;

}

void Comandos::delDgv(string id) {
	bool existe = false;

	if (vectorDGVS.size() > 1) {
		for (vector<Dgv*>::const_iterator it = vectorDGVS.cbegin();
			it != vectorDGVS.cend();) {
			if ((*it) != nullptr && (*it)->getDgvId() == id) {
				if ((*it) == getDgv()) {
					cout << "DGV com o nome \"" << id << "\" nao pode ser apagada uma vez que e a DGV ativa!" << endl <<
						"Por favor altere o nome para poder apagar a gravacao!" << endl;
					return;
				}
				else if ((*it) != getDgv()) {
					existe = true;
					it = vectorDGVS.erase(it);
					cout << "DGV com o nome \"" << id << "\" foi apagada com sucesso!" << endl;
				}
			}
			else
				it++;
		}
	}
	if (existe == false)
		cout << "Nao existe DGV com o nome \"" << id << "\"!" << endl <<
		"Por favor altere o nome para poder apagar a gravacao!" << endl;
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