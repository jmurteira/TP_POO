#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <iostream>

#include "Autodromo.h"
#include "Piloto.h"
#include "Classificacao.h"



class Campeonato
{
	int tam = 1;					//num de corridas (autodromos)
	int realizadas = 0;				//num de corridas concluidas
	Autodromo* corrida[1];
	//vector <Autodromo*> corrida;
	vector <Piloto*> participantes[5];
	vector <Classificacao*> classGeral[5];

public:
	Campeonato();
	~Campeonato();

	void passatempo(int t);

	int getTam() const;

	void atualizaClass();
};

