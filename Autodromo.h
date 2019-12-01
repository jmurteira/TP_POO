#pragma once
#include <string>
#include <vector>
#include <iostream>

class Interface; //provisorio, so para aceder a dgv
class Piloto;
class Carro;
//class Dgv;

using namespace std;

class Autodromo
{
	//Dgv* dgv;
	string nome;
	int distancia;
	int capacidade;
	bool iniciada;		//a combinação dos bools "iniciada", "finalizada" permite saber quais as corridas que já foram feitas, as que ainda não foram feitas e a que está a decorrer
	bool finalizada;
	bool classifAtualizada;
	vector <Carro *> garagem;
	vector <Piloto *> pista;

	vector <Piloto *> classificacao[5];	//(?)

public:
	Autodromo(int cap , int dist, string n);
	~Autodromo();

	string getNome() const;

	void atualizaClassif();

	string getStringDescricao()const;

	void passatempo(int t);

	bool getIniciada() const;
	void setIniciada(bool inic);

	bool getFinalizada() const;
	bool getClassifAtualizada() const;

	vector <Piloto*> getPista() const;
	vector <Carro*> getGaragem() const;

	void adicionaParticipante(Piloto* p);
	void adicionaCarro(Carro* c);
	//Dgv* getDgv()const;
	//void setDgv(Dgv *d);

};

