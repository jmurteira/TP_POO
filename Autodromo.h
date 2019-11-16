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
	bool iniciada;						//a combinação dos bools "iniciada", "finalizada" permite saber quais as corridas que já foram feitas, as que ainda não foram feitas e a que está a decorrer
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

