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
	vector <Carro> garagem[20];
	vector <Piloto *> pista;

	vector <Piloto> classificacao[5];	//(?)

public:
	Autodromo(string n, int dist);
	~Autodromo();

	string getNome() const;

	//void addParticipante(string n);

	void atualizaClassif();

	string getAsString()const;

	void passatempo(int t);

	////obter a pista (participantes) ???
	//vector <Piloto> getPista()const;
	////obter os carros que estao na garagem ???
	//vector <Carro> getGaragem()const;
};

