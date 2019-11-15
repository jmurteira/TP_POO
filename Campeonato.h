#pragma once
#include <string>
#include <vector>
#include "Autodromo.h"
#include "Piloto.h"

class Campeonato
{
	int tam = 1;					//num de corridas (autodromos)
	int realizadas = 0;				//num de corridas concluidas
	vector <Autodromo> corrida[1];
	vector <Piloto> participantes[5];
	vector <Piloto> classGeral[5];

public:
	Campeonato();
	~Campeonato();
};

