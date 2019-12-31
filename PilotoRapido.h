#pragma once
#include<string>
using namespace std;

#include "Piloto.h";
class Carro;
class PilotoRapido : public virtual Piloto
{
	Carro* carro;
public:
	PilotoRapido(string n);
	/*string getStringDescricao()const override;
	void acelera()override;*/
	//ver botao de emergencia
	//void acelera()override;
};