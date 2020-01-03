#pragma once
#include<string>
using namespace std;

#include "Piloto.h";
class Carro;
class Classificacao;

class CrazyDriver: public virtual Piloto
{
	//Carro* carro;
public: 
	CrazyDriver(string n);
	int inicio_aleatorio();
	/*string getStringDescricao()const override;
	void acelera()override;
	void perdePosicao();*/
	void passaTempoPiloto(int t, int dist, vector<int> p)override;
	//void perguntaPista();
};