
#pragma once
#include<string>
using namespace std;

#include "Piloto.h";
class Carro;
class PilotoSurpresa : public virtual Piloto
{
	//Carro* carro;
public:
	PilotoSurpresa(string n);
	/*string getStringDescricao()const override;
	void acelera()override;*/
	void passaTempoPiloto(int t, int dist)override;
	bool turbo();
	//ver botao de emergencia
	//void acelera()override;
};