#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <iostream>


class Autodromo;
class Piloto;
class Classificacao;
class Dgv;

using namespace std;

class Campeonato
{
	Dgv* dgv;
	int tam = 1;					//num de corridas (autodromos)
	int realizadas = 0;				//num de corridas concluidas
	Autodromo* corrida;
	//vector <Autodromo*> corrida;
	//vector <Piloto*> participantes[5];
	vector<Classificacao*> classGeral;

public:
	Campeonato();
	~Campeonato();

	void passatempo(int t);

	int getTam() const;

	void setCorrida(Autodromo * aut);

	void addParticipantes(int n_pista, int n_garagem); //funcao para adicionar carros no autodromo. perguntar quantos para a pista e quantos para a garagem

	void atualizaClassif();

	void iniciaCamp();
};

