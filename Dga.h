#pragma once
#pragma once
#include <vector>
#include <string>
#include <fstream>

class Piloto;
class Carro;
class Autodromo;
class Dgv;

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

	//so para verificar que nesta meta só existe um autodromo
	int getDgaSize()const;

};

