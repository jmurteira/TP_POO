#pragma once
#include "Piloto.h";
#include<string>
using namespace std;


class Carro;
class Classificacao;

class CrazyDriver: public virtual Piloto
{
	int inicio;
	//Carro* carro;
public: 
	CrazyDriver(string n);
	void setInicio(int i);
	int getInicio() const;
	int inicio_aleatorio();
	/*string getStringDescricao()const override;
	void acelera()override;
	void perdePosicao();*/
	void passaTempoPiloto(int t, int dist, vector<int> p)override;
	//void perguntaPista();
};