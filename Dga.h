#pragma once
#pragma once
#include <vector>
#include <string>
#include <fstream>

class Piloto;
class Carro;
class Autodromo;

using namespace std;

class Dga
{
	string DgaID;
	vector<Autodromo*> autodromos;
public:


	Dga(string id);

	Autodromo* novoAutodromo(int cap, int dist, string n);

	Autodromo* procuraAutodromo(string nome) const;

	void carregaA(string fich);
	void apagaAutodromo(string nome);
	int verificaNumParametrosFicheiroTexto(string fich);

	string descricaoAutodromo() const;

	Carro* novoCarro(string marc, string mod, char ident);
	Piloto* novoPiloto(string n, int t);

	Carro* procuraCarro(char ident) const;
	Piloto* procuraPiloto(string nome) const;

	//so para verificar que nesta meta só existe um autodromo
	int getDgaSize()const;

};

