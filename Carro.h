#pragma once
#include <string>
using namespace std;

class Carro
{
	string marca;
	string modelo;
	int ident;			//identificador do carro
	float energia;
	float energiaMax;
	int velocidade;
	int velMax;
	int cronometro;		//tempo em segudos
	bool ocupado;		//ver se tem piloto ou n�o
	bool sinalEmerg;
	bool avariado;

	//ponteiro para piloto ( ??? )

public:
	Carro();
	~Carro();
	
	//ideia das fun��es
	//Velocidade
	void acelera();
	void trava();
	int getVelocidade();

	//Energia
	void gastaEnergia();
	void carregaBat();
	float getEnergia();
	
	//Botao Emergencia
	void BotaoSOS();

};

