#pragma once
#include <string>
#include <vector>
#include "Piloto.h"
#include "Carro.h"

class Autodromo
{
	string nome;
	int distancia;
	const static int participantes = 5;
	bool iniciada;						//a combina��o dos bools "iniciada", "finalizada" permite saber quais as corridas que j� foram feitas, as que ainda n�o foram feitas e a que est� a decorrer
	bool finalizada;
	//const static int maxCarrosGaragem;
	vector <Carro> garagem[20];
	vector <Piloto> pista[participantes];

	vector <Piloto> classificacao[5];	//(?)

public:
	Autodromo(string n, int dist);
	~Autodromo();

	void atualizaClassif();

	string getAsString()const;

	////obter a pista (participantes) ???
	//vector <Piloto> getPista()const;
	////obter os carros que estao na garagem ???
	//vector <Carro> getGaragem()const;
};

