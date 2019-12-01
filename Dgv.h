#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

class Piloto;
class Carro;

using namespace std;

class Dgv
{
	string DgvID;
	vector<Piloto*> pilotos;
	vector<Carro*> carros;
public:


	Dgv(string id);
	Carro* novoCarro(int capAtual, int capMax, string marc, string mod,  char ident = ' ');
	Piloto* novoPiloto(string t, string n);

	Carro* procuraCarro(char ident) const;
	Piloto* procuraPiloto(string nome) const;

	void carregaP(string fich);
	void carregaC(string fich);

	//verificador da identificacao do carro, se existe algum igual no vector
	bool verificaIdent(char ident);

	//verificador do nome do piloto, se já existe algum com o mesmo nome no vector
	bool verificaNomePiloto(string nome);


	int verificaNumParametrosFicheiroTexto(string fich);

	string descricaoCarro() const;
	string descricaoPiloto() const;

	void entraNoCarro(char ident, string nome);
	void saiDoCarro(char ident);

	void apagaCarro(char ident);
	void apagaPiloto(string nome);

	vector<Piloto*> getPilotos() const;

	

	//void criaCarro(int capAtual, int capMax, string marc, string mod);
	//void criaPiloto(int t, string nome);
	//void criaAutodromo()
};

