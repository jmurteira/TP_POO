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
	int flag_sair = 0;
	int flag_campeonato = 0;
	
	//imprimir as merdas todas bonitas da consola bla bla
	//talvez aparecer primeiro um "intro" a dizer Car Simulator e carregar qualquer tecla para entrar
	//depois apareceria uma lista de comandos, com uma distincao dos modos
	//assim que fosse escolhido o Campeonato, apareceria a pista e a garagem do autodromo e apenas os comandos do modo 2 (talvez)
	//o campeonato pede o numero de carros que vao para a pista
	//o mesmo mas para a garagem
	//e a corrida começa a partir do momento em que todos os carros da pista têm piloto
	//acaba corrida, aparece classificacao final //maybe
	//carregar qualquer tecla para voltar ao menu inicial
	
	//Consola::setBackgroundColor(Consola::BRANCO_CLARO);
	//Consola::setTextColor(Consola::VERDE_CLARO);
	////Consola::setTextColor(Consola::PRETO);

	//for (int i = 0; i < 30; i++) {
	//	for (int j = 0; j < 10; j++) {
	//		Consola::gotoxy(i + 45, j);
	//		cout << " ";
	//	}
	//}

	//Consola::setBackgroundColor(Consola::PRETO);
	////Consola::setTextColor(Consola::BRANCO);

	//for (int i = 0; i < 16; i++) {
	//	for (int j = 0; j < 6; j++) {
	//		Consola::gotoxy(i + 52, j + 2);
	//		cout << " ";
	//	}
	//}


	Consola::setBackgroundColor(Consola::PRETO);
	//Consola::setTextColor(Consola::VERDE_CLARO);
	//Consola::setTextColor(Consola::PRETO);

	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 10; j++) {
			Consola::gotoxy(i + 35, j + 8);
			cout << char(28);
		}
	}

	Consola::setBackgroundColor(Consola::PRETO);
	//Consola::setTextColor(Consola::BRANCO);

	for (int i = 0; i < 42; i++) {
		for (int j = 0; j < 6; j++) {
			Consola::gotoxy(i + 39, j + 10);
			cout << " ";
		}
	}

	
	Consola::gotoxy(53, 12);
	cout << "RACE" <<endl;
	Consola::gotoxy(59, 13);
	cout << "SIMULATOR" << endl;

	
	Consola::setTextColor(Consola::VERDE_CLARO);
	Consola::gotoxy(42, 20);
	cout << "Carregar numa tecla para continuar";

	
	Consola::getch();
	

	Consola::clrscr();

	
	cout << comando->getStringListaComandos();



	while (flag_sair == 0){

		
		string res = comando->lerComandoModo1();

		if (res == "sair")
			flag_sair = 1;

		else if (res == "campeonato")
			flag_campeonato = 1;

		while (flag_campeonato == 1) {
			//modo 2
			res = comando->lerComandoModo2();

			//quando campeonato terminar, pergunta se quer sair logo = flag_campeonato == 0 e flag_sair == 1. se so quiser voltar atras, flag_campeonato ==0.

		}

	}
	
	

	
}