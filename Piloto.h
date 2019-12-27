#pragma once
#include <string>


class Carro;

using namespace std;

class Piloto
{
	string nome;
	string tipo;
	bool atualizado;
	Carro * carro;		//ponteiro para carro						(ponteiro de carro para piloto e de piloto para carro ???)


public:
	Piloto(string t, string n);
	~Piloto();

	void entrarCarro(Carro * c);
	void sairCarro();

	void acelera();
	void trava();

	bool getAtualizado()const;
	void setAtualizado(bool a);

	void passaTempoPiloto(int t, int dist);

	string getNome() const;
	char getIdCarro() const;

	Carro* getCarro() const;

	void acidente();

	void carregaCarro(float n_energia);

	string getStringDescricao()const;

};

