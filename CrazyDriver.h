#pragma once

#include<string>
using namespace std;

#include "Piloto.h";

class CrazyDriver: public virtual Piloto
{

public: 
	CrazyDriver(string n);
	/*string getStringDescricao()const override;
	void acelera()override;
	void verPosicao();
	void perdePosicao();
	void randomAcidente();*/


};