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
	vector <Piloto*> participantes;
	vector<Classificacao*> classGeral;

public:
	Campeonato();
	~Campeonato();

	void passatempo(int t);

	int getTam() const;

	void setCorrida(Autodromo * aut);
	Autodromo* getCorrida() const;

	void addParticipantes(); //funcao para adicionar carros no autodromo. perguntar quantos para a pista e quantos para a garagem

	void atualizaClassif();

	void iniciaCamp();

	Dgv* getDgv()const;
	void setDgv(Dgv* d);

	bool getIniciada()const;
	
};