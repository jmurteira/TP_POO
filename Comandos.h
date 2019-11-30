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
	Dga* dga;
	Campeonato * camp;
	string comando;
public:

	Comandos();

	string lerComando();
	Dgv* getDgv();
	Dga* getDga();
	Campeonato* getCamp();
	void setCamp(Campeonato * c);
	void atribuiDgv(Dgv * d);
	void atribuiDga(Dga* da);
};

