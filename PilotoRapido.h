#pragma once
#include <iostream> 
using namespace std;

#include "Piloto.h";

class PilotoRapido : public virtual Piloto
{

public:
	string getStringDescricao()const override;
	void acelera()override;
	//ver botao de emergencia

};

