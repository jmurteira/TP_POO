#pragma once
#include <string>
#include <vector>
#include "Piloto.h"
#include "Carro.h"

class Autodromo
{
	int distancia;
	bool iniciada;						//a combinação dos bools "iniciada", "finalizada" permite saber quais as corridas que já foram feitas, as que ainda não foram feitas e a que está a decorrer
	bool finalizada;
	//const static int maxCarrosGaragem;
	vector <Carro> garagem[20];
	vector <Piloto> pista[5];

	vector <Piloto> classificacao[5];	//(?)

public:
	Autodromo();
	~Autodromo();
};

