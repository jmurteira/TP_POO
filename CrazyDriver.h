#pragma once

#include <iostream> 
using namespace std;

#include "Piloto.h";

class CrazyDriver: public virtual Piloto
{

public: 
	string getStringDescricao()const override;
	void acelera()override;
	void verPosicao();
	void perdePosicao();
	void randomAcidente();


};
