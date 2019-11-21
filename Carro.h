#pragma once
#include <string>
using namespace std;

class Carro
{
	string marca;
	string modelo;
	char ident;			//identificador do carro, verificar que nunca t�m o mesmo ident. dgv?
	int posicao;		//---> ESQUECE ISTO (ERA APENAS UMA IDEIA) -1 (garagem), >0 (em corrida), 0 (nao interessa ou inicio corrida ?) 
	int cronometro;		//tempo em segudos

	float energia;
	float energiaMax;
	int velocidade;
	int velMax;
	bool ocupado;		//ver se tem piloto ou n�o
	bool sinalEmerg;
	bool avariado;

	//ponteiro para piloto ( ??? )

public:
	Carro(string marc, string mod);
	~Carro();
	
	char getIdent()const;

	//carro ocupado ou desocupado
	bool getOcupado()const;
	
	bool setOcupado();
	bool setDesocupado();

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

	void passaTempoCarro(int t, int distPista);

	string getAsString()const;
	string CarroOcupado()const;
};

