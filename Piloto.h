#pragma once
#include <string>


class Carro;

using namespace std;

class Piloto
{
private:
	string nome;
	string tipo;
	bool atualizado;	//serve para saber se a classifica��o est� atualizada
	Carro * carro;		//ponteiro para carro

public:
	Piloto(string t, string n);
	Piloto(const Piloto& orig);
	~Piloto();

	//ver sinal de emergencia

	virtual void entrarCarro(Carro * c);
	void sairCarro();

	virtual void acelera();
	virtual void trava();

	bool getAtualizado()const;
	void setAtualizado(bool a);

	virtual void passaTempoPiloto(int t, int dist);

	string getNome() const;
	char getIdCarro() const;
	string getTipo()const;

	Carro* getCarro() const;

	void acidente();

	void carregaCarro(float n_energia);

	virtual string getStringDescricao()const;

};
