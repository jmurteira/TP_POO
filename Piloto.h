#pragma once
#include <string>
#include "Carro.h"

using namespace std;

class Piloto
{
	string nome;
	int tipo;

	Carro * carro;		//ponteiro para carro						(ponteiro de carro para piloto e de piloto para carro ???)


public:
	Piloto(string n, int t);
	~Piloto();

	void entrarCarro(Carro * c);
	void sairCarro();


	string getNome() const;
	char getCarro() const;

	string getAsString()const;

	
};

