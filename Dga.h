#pragma once
#pragma once
#include <vector>
#include <string>

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

	Autodromo* novoAutodromo(int cap, string n, int dist);

	Autodromo* procuraAutodromo(string nome) const;

	Carro* novoCarro(string marc, string mod, char ident);
	Piloto* novoPiloto(string n, int t);

	Carro* procuraCarro(char ident) const;
	Piloto* procuraPiloto(string nome) const;


};

