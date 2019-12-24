#pragma once
#include <string>
#include <cctype>

using namespace std;


class Carro
{
	string marca;
	string modelo;
	char ident;			//identificador do carro, verificar que nunca têm o mesmo ident. dgv?
	int posicao;		//-1 (garagem)???, >0 (em corrida), -2 (terminou a corrida) , 0 (nao interessa ou inicio corrida ?) 
	int cronometro;		//tempo em segudos

	float energia;
	float energiaMax;
	//float n_energia; // utiliza uma vez a manivela de carregamento de energia no carro identificado por letraCarro fornecendo Q mAh. é um dos comandos, para a meta 2, mas para já fica om default igual 5
	int velocidade;
	int velMax;
	bool ocupado;		//ver se tem piloto ou não
	bool sinalEmerg;
	bool avariado;

	

public:
	Carro(string marc, string mod, float capAtual, float capMax, char id = ' ');
	~Carro();
	
	char getIdent()const;

	//carro ocupado ou desocupado
	bool getOcupado()const;

	int getPosicao()const;
	void setPosicao(int pos);

	int getTempo()const;
	void setTempo(int t);

	void setOcupado();
	void setDesocupado();

	//ideia das funções
	//Velocidade

	
	
	int getVelocidade();
	void setVelocidade(int x);
	int getVelocidadeMax();

	//Energia
	void gastaEnergia();
	void carregaBat(float n_energia);
	float getEnergia() const;
	
	//Botao Emergencia
	void BotaoSOS();

	void passaTempoCarro(int t, int distPista);

	string getAsString()const;
	string getStringOcupado()const;
	string getStringDescricao()const;
	
};

