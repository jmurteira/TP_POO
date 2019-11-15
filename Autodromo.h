#pragma once
#include <string>
#include <vector>
#include "Piloto.h"
#include "Carro.h"

class Autodromo
{
	int distancia;
	bool iniciada;						//a combina��o dos bools "iniciada", "finalizada" permite saber quais as corridas que j� foram feitas, as que ainda n�o foram feitas e a que est� a decorrer
	bool finalizada;
	//const static int maxCarrosGaragem;
	vector <Carro> garagem[20];
	vector <Piloto> pista[5];

	vector <Piloto> classificacao[5];	//(?)

public:
	Autodromo();
	~Autodromo();
};

