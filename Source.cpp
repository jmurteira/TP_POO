#include "Autodromo.h"
#include "Carro.h"
#include "Comandos.h"
#include "Dga.h"
#include "Dgv.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <time.h>

using namespace std;

int main() {
	srand(time(0)); //nao sei se é a melhor cena mas se estiver no construtor carro repete sempre a mesma letra. supostamente só deve ser chamada uma vez
	
	Dga dga("Portugal");
	Dgv dgv("Portugal");
	//Autodromo aut1 = Autodromo("Vienna", 4268);
	dga.novoAutodromo("Estoril",1000);
	dga.novoAutodromo("Estoril", 10);
	
	/*dgv.novoCarro("A", "Romeu");
	dgv.novoCarro("B", "Corsa");
	dgv.novoCarro("C", "Romeu");
	dgv.novoCarro("D", "Corsa");
	dgv.novoCarro("E", "Romeu");
	dgv.novoCarro("F", "Corsa");
	dgv.novoCarro("G", "Romeu");
	dgv.novoCarro("H", "Corsa");
	dgv.novoCarro("I", "Romeu");
	dgv.novoCarro("J", "Corsa");
	dgv.novoCarro("K", "Romeu");
	dgv.novoCarro("L", "Corsa");
	dgv.novoCarro("M", "Romeu");
	dgv.novoCarro("N", "Corsa");
	dgv.novoCarro("O", "Romeu");
	dgv.novoCarro("P", "Corsa");
	dgv.novoCarro("Q", "Romeu");
	dgv.novoCarro("R", "Corsa");
	dgv.novoCarro("S", "Corsa");
	dgv.novoCarro("T", "Corsa");
	dgv.novoCarro("U", "Corsa");
	dgv.novoCarro("V", "Corsa");
	dgv.novoCarro("W", "Corsa");
	dgv.novoCarro("X", "Corsa");*/
	dgv.novoCarro("Y", "Corsa",10,50);
	dgv.novoCarro("Z", "Corsa",10, 50);
	dgv.novoCarro("asdfsd", "Corsa", 10, 50);
	dgv.novoCarro("asdafsdffsd", "Corsa", 10, 50);


	cout << dgv.descricaoCarro() << endl;

	//cout << aut1.getAsString();

	int teste;
	Carro c1 = Carro("Alfa", "Romeu", 10, 50);
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
	c1.passaTempoCarro(548,5000);
	cout << endl << endl << c1.getAsString();
	


	//Piloto p1 = Piloto("Vettel", 1);
	//Piloto p2 = Piloto("Michael", 2);
	dgv.novoPiloto("Vettel", 1);
	dgv.novoPiloto("Michael", 2);
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

	//APENAS ESTÁ AQUI PARA TESTAR
	Comandos c = Comandos();
	c.atribuiDgv(&dgv);
	c.lerComando();

	/*cout << endl << endl << endl;
	dgv.carregaP("pilotos.txt");
	cout << endl << endl;*/

	cin.get();
}

