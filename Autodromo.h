#pragma once
#include <string>
#include <vector>
#include <iostream>

//nota: garagem tem de estar vazia se nao estiver la nenhum carro

class Interface; //provisorio, so para aceder a dgv
class Piloto;
class Carro;
class Classificacao;
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
	bool classifGeralAtualizada;
	vector <Carro*> garagem;
	vector <Piloto*> pista;

	vector <Classificacao*> classificacao;	//(?)

public:
	Autodromo(int cap, int dist, string n);
	~Autodromo();

	string getNome() const;

	void atualizaClassif();

	string getStringDescricao()const;

	void passatempo(int t, vector<int> p);

	bool getIniciada() const;
	void setIniciada(bool inic);

	int getDistancia() const;

	bool getFinalizada() const;
	void setFinalizada(bool fin);

	bool getClassifAtualizada() const;

	void acidente(char ident, int flag);
	void emergencia();
	void stop(string n);
	void removeCarroStop();
	void destroiCarro(char ident, int flag);
	vector <Piloto*> getPista() const;
	vector <Carro*> getGaragem() const;
	vector <Classificacao*> getClassificacao() const;

	Piloto* procuraPilotoPorCarro(Carro* c) const;

	void carregabat(Carro* c, float q);

	void adicionaParticipante(Piloto* p);
	void adicionaCarro(Carro* c);

	string listacarros() const;

	//Dgv* getDgv()const;
	//void setDgv(Dgv *d);

};

