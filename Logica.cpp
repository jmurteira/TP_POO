#include "Logica.h"
#include "Interface.h"
#include "Dga.h"
#include "Dgv.h"
#include "Comandos.h"
#include "Carro.h"
#include "Piloto.h"
#include "Consola.h"
#include "Campeonato.h"
#include "Autodromo.h"

Logica::Logica(Dgv* d, Dga* da, Comandos* com) {
	dgv = d;
	dga = da;
	comando = com;
}

Dgv* Logica::getDgv() {
	return dgv;
}

Dga* Logica::getDga() {
	return dga;
}

Comandos* Logica::getComandos() {
	return comando;
}

void Logica::Simulador() {
	int flag_sair = 0;
	int flag_campeonato = 0;


	//e a corrida começa a partir do momento em que todos os carros da pista têm piloto
	//acaba corrida, aparece classificacao final //maybe
	//carregar qualquer tecla para voltar ao menu inicial


	Consola::setBackgroundColor(Consola::PRETO);

	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 10; j++) {
			Consola::gotoxy(i + 35, j + 8);
			cout << char(28);
		}
	}

	Consola::setBackgroundColor(Consola::PRETO);

	for (int i = 0; i < 42; i++) {
		for (int j = 0; j < 6; j++) {
			Consola::gotoxy(i + 39, j + 10);
			cout << " ";
		}
	}


	Consola::gotoxy(53, 12);
	cout << "RACE" << endl;
	Consola::gotoxy(59, 13);
	cout << "SIMULATOR" << endl;


	Consola::setTextColor(Consola::VERDE_CLARO);
	Consola::gotoxy(42, 20);
	cout << "Carregar numa tecla para continuar";


	Consola::getch();


	Consola::clrscr();


	cout << comando->getStringListaComandos();



	while (flag_sair == 0) {



		//for (int i = 0; i < 50; i++) {
		//	for (int j = 0; j < 10; j++) {
		//		Consola::gotoxy(i + 20, j + 10);
		//		cout << char(28);
		//	}
		//}

		//for (int i = 0; i < 50; i++) {
		//	for (int j = 0; j < 10; j++) {
		//		j++;
		//		Consola::gotoxy(i + 20, j + 10);
		//		cout << " ";
		//	}
		//}


		////fazer uma funcao para nao repetir isto
		//Consola::gotoxy(75, 3);
		//cout << "\nLista de Comandos: " << endl << endl;
		//Consola::gotoxy(75, 4);
		//cout << "Modo 2: Campeonato" << endl;
		//Consola::gotoxy(75, 5);
		//cout << "campeonato <A1> <A2> ... <An>" << endl;
		//Consola::gotoxy(75, 6);
		//cout << "passatempo <n>" << endl;
		//Consola::gotoxy(75, 7);
		//cout << "modo1 (voltar ao Modo 1)" << endl;


		string res = comando->lerComandoModo1();


		if (res == "sair") {
			flag_sair = 1;
			cout << "simulador terminou" << endl;
		}
		else if (res == "campeonato")
			flag_campeonato = 1;

		while (flag_campeonato == 1) {
			int flag = 0;
			//modo 2

			if (flag == 0) {
				Consola::clrscr();
				flag = 1;
			}

			for (int i = 0; i < 50; i++) {
				for (int j = 0; j < 10; j++) {
					Consola::gotoxy(i + 20, j + 10);
					cout << char(28);
					j++;
				}
			}

			int x = getComandos()->getCamp()->getRealizadas();

			/*for (int i = 0; i < getComandos()->getCamp()->getCorridas()[x]->getPista().size(); i++) {
				int pos = getComandos()->getCamp()->getCorridas()[x]->getPista()[i]->getCarro()->getPosicao();
				int dist = getComandos()->getCamp()->getCorridas()[x]->getDistancia();
				float x = round((pos * 50) / dist);
				for (int j = 0; j < 10; j++) {
					j++;
					Consola::gotoxy(x + 20, 2 * i + 1 + 10);
					cout << getComandos()->getCamp()->getCorridas()[x]->getPista()[i]->getCarro()->getIdent();
				}
			}*/

			for (int i = 0; i < getComandos()->getCamp()->getCorridaAtiva()->getPista().size(); i++) {
				int pos = getComandos()->getCamp()->getCorridaAtiva()->getPista()[i]->getCarro()->getPosicao();
				int dist = getComandos()->getCamp()->getCorridaAtiva()->getDistancia();
				float x = round((pos * 50) / dist);
				for (int j = 0; j < 10; j++) {
					j++;
					Consola::gotoxy(x + 20, 2 * i + 1 + 10);
					cout << getComandos()->getCamp()->getCorridaAtiva()->getPista()[i]->getCarro()->getIdent();
				}
			}


			//fazer uma funcao para nao repetir isto
			Consola::gotoxy(75, 3);
			cout << "\nLista de Comandos: " << endl << endl;
			Consola::gotoxy(75, 4);
			cout << "Modo 2: Campeonato" << endl;
			Consola::gotoxy(75, 5);
			cout << "campeonato <A1> <A2> ... <An>" << endl;
			Consola::gotoxy(75, 6);
			cout << "passatempo <n>" << endl;
			Consola::gotoxy(75, 7);
			cout << "listacarros";
			Consola::gotoxy(75, 8);
			cout << "carregabat <letraCarro> <Q>";
			Consola::gotoxy(75, 9);
			cout << "carregatudo";
			Consola::gotoxy(75, 10);
			cout << "corrida";
			Consola::gotoxy(75, 11);
			cout << "acidente <letraCarro>";
			Consola::gotoxy(75, 12);
			cout << "stop <nomePiloto>";
			Consola::gotoxy(75, 13);
			cout << "destroi <letraCarro>";
			Consola::gotoxy(75, 14);
			cout << "log";
			Consola::gotoxy(75, 15);
			cout << "modo1 (voltar ao Modo 1)" << endl;


			//cout << comando->getStringListaComandosModo2();

			res = comando->lerComandoModo2();

			if (res == "modo1") { //cancelar campeonato. cuidado: limpar vector pista e corrida
				flag_campeonato = 0;
				cout << "\ncampeonato cancelado. retornar ao modo 1.." << endl;
				Consola::getch();
				Consola::clrscr();

				Consola::gotoxy(75, 3);
				cout << "\nLista de Comandos: " << endl << endl;
				Consola::gotoxy(75, 4);
				cout << "Modo 2: Campeonato" << endl;
				Consola::gotoxy(75, 5);
				cout << "campeonato <A1> <A2> ... <An>" << endl;
				Consola::gotoxy(75, 6);
				cout << "passatempo <n>" << endl;
				Consola::gotoxy(75, 7);
				cout << "listacarros";
				Consola::gotoxy(75, 8);
				cout << "carregabat <letraCarro> <Q>";
				Consola::gotoxy(75, 9);
				cout << "carregatudo";
				Consola::gotoxy(75, 10);
				cout << "corrida";
				Consola::gotoxy(75, 11);
				cout << "acidente <letraCarro>";
				Consola::gotoxy(75, 12);
				cout << "stop <nomePiloto>";
				Consola::gotoxy(75, 13);
				cout << "destroi <letraCarro>";
				Consola::gotoxy(75, 14);
				cout << "log";
				Consola::gotoxy(75, 15);
				cout << "modo1 (voltar ao Modo 1)" << endl;




				Consola::clrscr();
				cout << comando->getStringListaComandos();
			}

			//cin.get();

			//quando campeonato terminar, pergunta se quer sair logo = flag_campeonato == 0 e flag_sair == 1. se so quiser voltar atras, flag_campeonato ==0.
		}

	}

}