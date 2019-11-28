#pragma once
#include <string>


class Carro;

using namespace std;

class Piloto
{
	string nome;
	int tipo;

	Carro * carro;		//ponteiro para carro						(ponteiro de carro para piloto e de piloto para carro ???)


public:
	Piloto(string n, int t);
	~Piloto();

	void entrarCarro(Carro * c);
	void sairCarro();

	void acelera();
	void trava();

	void passaTempoPiloto(int t, int dist);

	string getNome() const;
	char getIdCarro() const;

	Carro* getCarro() const;

	string getStringDescricao()const;
	

	
};

