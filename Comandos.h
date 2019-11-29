#pragma once
#include <string>

class Carro;
class Piloto;
class Dgv;
class Dga;
class Campeonato;

using namespace std;
class Comandos
{
	Dgv * dgv;
	Campeonato * camp;
	string comando;
public:

	Comandos();

	void lerComando();
	Dgv* getDgv();
	Campeonato* getCamp();
	void atribuiDgv(Dgv * d);
};

