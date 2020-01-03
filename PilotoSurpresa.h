
#pragma once
#include<string>
using namespace std;

#include "Piloto.h";
class Carro;
class PilotoSurpresa : public virtual Piloto
{
	int distAcelera;
	//Carro* carro;
public:
	PilotoSurpresa(string n);
	/*string getStringDescricao()const override;
	void acelera()override;*/
	void passaTempoPiloto(int t, int dist, vector<int> p)override;
	bool turbo();
	void setDistAcelera();
	//ver botao de emergencia
	//void acelera()override;
};