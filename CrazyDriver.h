#pragma once
#include<string>
using namespace std;

#include "Piloto.h";
class Carro;
class CrazyDriver: public virtual Piloto
{
	//Carro* carro;
public: 
	CrazyDriver(string n);
	int inicio_aleatorio();
	/*string getStringDescricao()const override;
	void acelera()override;
	void verPosicao();
	void perdePosicao();
	void randomAcidente();*/
	void passaTempoPiloto(int t, int dist)override;

};