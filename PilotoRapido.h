#pragma once
#include<string>
using namespace std;

#include "Piloto.h";

class PilotoRapido : public virtual Piloto
{

public:
	PilotoRapido(string n);
	/*string getStringDescricao()const override;
	void acelera()override;*/
	//ver botao de emergencia

};