#pragma once
#include<string>
using namespace std;

#include "Piloto.h";
class Carro;
class PilotoRapido : public virtual Piloto
{
	int tresSeg;
	int dezSeg;
	//Carro* carro;
public:
	PilotoRapido(string n);
	/*string getStringDescricao()const override;
	void acelera()override;*/
	void passaTempoPiloto(int t, int dist, vector<int> p)override;
	int getTresSeg()const;
	void setTresSeg(int s);
	int getDezSeg()const;
	void setDezSeg(int s);
	//ver botao de emergencia
	//void acelera()override;
};