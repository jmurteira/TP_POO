#pragma once
#include <string>
#include "Dgv.h"

class Carro;
class Piloto;
class Dgv;
class Dga;
class Campeonato;
class Autodromo;
class Log;

using namespace std;
class Comandos
{
	Log* log;
	Dgv * dgv;
	Dga* dga;
	Campeonato * camp;
	string comando;
	vector<Dgv*> vectorDGVS;

public:

	Comandos();

	string lerComandoModo1(); //modo1
	string lerComandoModo2(); //modo2
	Dgv* getDgv();
	Dga* getDga();
	Campeonato* getCamp();
	void setCamp(Campeonato * c);
	void atribuiDgv(Dgv * d);
	void atribuiDga(Dga* da);
	string getStringListaComandos()const;
	string getStringListaComandosModo2()const;
	vector<Dgv*> getVectorDgvs()const;

	void alteraDgv(string id);
	void saveDgv(string id);
	void delDgv(string id);

	Log* getLog();
	void atribuiLog(Log* l);
	void mostraLog();
};

