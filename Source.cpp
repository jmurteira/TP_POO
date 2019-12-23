#include "Autodromo.h"
#include "Carro.h"
#include "Comandos.h"
#include "Dga.h"
#include "Dgv.h"
#include "Consola.h"
#include "Interface.h"
#include "Logica.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <time.h>

using namespace std;

int main() {
	srand(time(0)); //nao sei se � a melhor cena mas se estiver no construtor carro repete sempre a mesma letra. supostamente s� deve ser chamada uma vez
	
	/*Consola::setBackgroundColor(Consola::BRANCO_CLARO);
	Consola::setTextColor(Consola::PRETO);

	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 10; j++) {
			Consola::gotoxy(i+45, j);
			cout << " ";
		}
	}

	Consola::setBackgroundColor(Consola::PRETO);
	Consola::setTextColor(Consola::BRANCO);

	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 6; j++) {
			Consola::gotoxy(i + 52, j+2);
			cout << " ";
		}
	}*/

	Dga dga("Portugal");
	Dgv dgv("Portugal");
	//Autodromo aut1 = Autodromo("Vienna", 4268);
	//dga.novoAutodromo(2,1000, "Estoril");
	//dga.novoAutodromo(2, 10, "Estoril");
	
	/*dgv.novoCarro("A", "Romeu",10, 50);
	dgv.novoCarro("B", "Corsa", 10, 50);
	dgv.novoCarro("C", "Romeu", 10, 50);
	dgv.novoCarro("D", "Corsa", 10, 50);
	dgv.novoCarro("E", "Romeu", 10, 50);
	dgv.novoCarro("F", "Corsa", 10, 50);
	dgv.novoCarro("G", "Romeu", 10, 50);
	dgv.novoCarro("H", "Corsa", 10, 50);
	dgv.novoCarro("I", "Romeu", 10, 50);
	dgv.novoCarro("J", "Corsa", 10, 50);
	dgv.novoCarro("K", "Romeu", 10, 50);
	dgv.novoCarro("L", "Corsa", 10, 50);
	dgv.novoCarro("M", "Romeu", 10, 50);
	dgv.novoCarro("N", "Corsa", 10, 50);
	dgv.novoCarro("O", "Romeu", 10, 50);
	dgv.novoCarro("P", "Corsa", 10, 50);
	dgv.novoCarro("Q", "Romeu", 10, 50);
	dgv.novoCarro("R", "Corsa", 10, 50);
	dgv.novoCarro("S", "Corsa", 10, 50);
	dgv.novoCarro("T", "Corsa", 10, 50);
	dgv.novoCarro("U", "Corsa", 10, 50);
	dgv.novoCarro("V", "Corsa", 10, 50);
	dgv.novoCarro("W", "Corsa", 10, 50);
	dgv.novoCarro("X", "Corsa",10, 50);*/
	//dgv.novoCarro(10, 50,"Y", "Corsa");
	//dgv.novoCarro(10, 50,"Z", "Corsa");
	//dgv.novoCarro(10, 50, "asdfsd", "Corsa");
	//dgv.novoCarro (10, 50,"asdafsdffsd", "Corsa");


	//cout << dgv.descricaoCarro() << endl;

	//cout << aut1.getAsString();

	//int teste;
	//Carro c1 = Carro("Alfa", "Romeu", 10, 50);
	
	//c1.carregaBat();
	//c1.acelera();
	/*c1.acelera();
	c1.acelera();
	c1.acelera();
	c1.acelera();
	c1.acelera();
	c1.acelera();
	c1.acelera();
	c1.acelera();
	c1.acelera();*/
	
	//c1.passaTempoCarro(548,5000);
	//cout << endl << endl << c1.getAsString();
	


	//Piloto p1 = Piloto("Vettel", 1);
	//Piloto p2 = Piloto("Michael", 2);
	//dgv.novoPiloto("classico","Vettel");
	//dgv.novoPiloto("classico","Michael");
	//cout << endl << p1.getStringDescricao();
	//cout << endl << p2.getStringDescricao();

	//p1.entrarCarro(&c1);
	//cout << endl << "------------------------------------------"<<endl << "O piloto " << p1.getNome() << " entrou no carro com id: " << p1.getCarro() << endl;
	//cout << endl << p1.getStringDescricao();
	//cout << endl << c1.getStringOcupado();

	//cout <<  dgv.descricaoPiloto();

	//p2.entrarCarro(&c1);
	//cout << endl << p2.getStringDescricao();

	//p1.sairCarro();
	//cout << endl << p1.getStringDescricao();
	//cout << endl << c1.getStringOcupado();


	//p2.entrarCarro(&c1);
	//cout << endl << p2.getStringDescricao();

	//APENAS EST� AQUI PARA TESTAR
	Comandos c = Comandos();
	Logica logic = Logica(&dgv, &dga, &c);
	c.atribuiDgv(&dgv);
	c.atribuiDga(&dga);
	//c.lerComando();


	Interface i =Interface(&logic);
	i.Simulador();

	/*cout << endl << endl << endl;
	dgv.carregaP("pilotos.txt");
	cout << endl << endl;*/

	cin.get();
}

