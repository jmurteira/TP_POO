#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <iostream>


class Autodromo;
class Piloto;
class Classificacao;
class Dgv;
class Carro;

using namespace std;

class Campeonato
{
	Dgv* dgv;
	int tam = 1;					//num de corridas (autodromos)
	int realizadas = 0;				//num de corridas concluidas
	//Autodromo* corrida;
	vector <Autodromo*> corridas;
	vector <Piloto*> participantes;
	vector<Classificacao*> classGeral;

public:
	Campeonato();
	~Campeonato();

	void passatempo(int t);

	int getTam() const;

	void setCorrida(Autodromo * aut);
	
	//Autodromo* getCorrida() const;
	vector <Piloto*> getParticipantes() const;
	Autodromo* getCorridaAtiva() const;
	vector<Piloto*> getPistaAtiva() const;
	vector <Autodromo*> getCorridas() const;

	void carregabat(char ident, float q);
	void carregaTudo();

	int getAutorizados() const;

	bool addParticipantes(); //funcao para adicionar carros no autodromo. perguntar quantos para a pista e quantos para a garagem

	void atualizaClassif();

	bool iniciaCamp();

	Dgv* getDgv()const;
	void setDgv(Dgv* d);

	bool getIniciada()const;

	bool finalizaCorrida(vector<Piloto*> pista);

	int getRealizadas();
	void setRealizadas(int n);
	
	void proximaCorrida();
};