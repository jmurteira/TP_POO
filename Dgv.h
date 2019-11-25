#pragma once
#include <vector>
#include <string>

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
	Carro* novoCarro(string marc, string mod, char ident);
	Piloto* novoPiloto(string n, int t);

	Carro* procuraCarro(char ident) const;
	Piloto* procuraPiloto(string nome) const;


};

