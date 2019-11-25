#pragma once
#include <string>

class Dgv;
using namespace std;

//todas as funcionalidades do carro: acelerar, travar, etc que são controladas pelo piloto têm de ficar privadas, pois só o piloto é que as controla

class Carro
{
	string marca;
	string modelo;
	char ident;			//identificador do carro, verificar que nunca têm o mesmo ident. dgv?
	int posicao;		//---> ESQUECE ISTO (ERA APENAS UMA IDEIA) -1 (garagem), >0 (em corrida), 0 (nao interessa ou inicio corrida ?) 
	int cronometro;		//tempo em segudos

	float energia;
	float energiaMax;
	float n_energia; // utiliza uma vez a manivela de carregamento de energia no carro identificado por letraCarro fornecendo Q mAh. é um dos comandos, para a meta 2, mas para já fica om default igual 5
	int velocidade;
	int velMax;
	bool ocupado;		//ver se tem piloto ou não
	bool sinalEmerg;
	bool avariado;

	//ponteiro para piloto ( ??? )
	void acelera();
	void trava();

public:
	Carro(string marc, string mod, char id = 'a');
	~Carro();
	
	char getIdent()const;

	//carro ocupado ou desocupado
	bool getOcupado()const;
	
	bool setOcupado();
	bool setDesocupado();

	//ideia das funções
	//Velocidade
	
	
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
	string ListaCarros()const;
};

