#pragma once
#include <vector>
#include <string>
#include <iostream>

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
	Carro* novoCarro(string marc, string mod, int capAtual, int capMax, char ident = ' ');
	Piloto* novoPiloto(string n, int t);

	Carro* procuraCarro(char ident) const;
	Piloto* procuraPiloto(string nome) const;

	void carregaP(string fich);
	void carregaC(string fich);
	void carregaA(string fich);

	
	bool verificaIdent(char ident);

	string descricaoCarro() const;
	string descricaoPiloto() const;

	void entraNoCarro(char ident, string nome);
	void saiDoCarro(char ident);

	void apagaCarro(char ident);
	void apagaPiloto(string nome);
};

