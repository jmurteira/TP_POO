#pragma once
#include <string>
using namespace std;

class Carro
{
	string marca;
	string modelo;
	int ident;			//identificador do carro
	int posicao;		// -1 (garagem), >0 (em corrida), 0 (nao interessa ou inicio corrida ?) 
	int cronometro;		//tempo em segudos

	float energia;
	float energiaMax;
	int velocidade;
	int velMax;
	bool ocupado;		//ver se tem piloto ou não
	bool sinalEmerg;
	bool avariado;

	//ponteiro para piloto ( ??? )

public:
	Carro();
	~Carro();
	
	//ideia das funções
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

	void atualizaCronometro(int t, int distPista);

};

