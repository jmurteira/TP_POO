#pragma once
#include <string>

class Carro;
class Piloto;
class Dgv;

using namespace std;
class Comandos
{
	Dgv* dgv;
	string comando;
public:

	Comandos();

	
	int lerComando();
	void getDgv(Dgv* d);
};

