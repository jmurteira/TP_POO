#pragma once
#include <string>
using namespace std;

//todas as funcionalidades do carro: acelerar, travar, etc que s�o controladas pelo piloto t�m de ficar privadas, pois s� o piloto � que as controla

class Carro
{
	string marca;
	string modelo;
	char ident;			//identificador do carro, verificar que nunca t�m o mesmo ident. dgv?
	int posicao;		//---> ESQUECE ISTO (ERA APENAS UMA IDEIA) -1 (garagem), >0 (em corrida), 0 (nao interessa ou inicio corrida ?) 
	int cronometro;		//tempo em segudos

	float energia;
	float energiaMax;
	float n_energia; // utiliza uma vez a manivela de carregamento de energia no carro identificado por letraCarro fornecendo Q mAh. � um dos comandos, para a meta 2, mas para j� fica om default igual 5
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

