#pragma once
#include <string>

class Carro;
class Piloto;
class Dgv;

using namespace std;
class Comandos
{
	Dgv * dgv;
	string comando;
public:

	Comandos();

	
	void lerComando();
	Dgv* getDgv();
	void atribuiDgv(Dgv * d);
};

