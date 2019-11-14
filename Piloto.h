#pragma once
#include <string>

using namespace std;

class Piloto
{
	string nome;
	int tipo;
	//ponteiro para carro		(ponteiro de carro para piloto e de piloto para carro ???)


public:
	Piloto();
	~Piloto();

	
	void entrarCarro();
	void sairCarro();


};

