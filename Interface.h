#pragma once

class Dga;
class Dgv;
class Comandos;
class Consola;
class Carro;
class Piloto;

using namespace std;

class Interface
{
	Dga* dga;
	Dgv* dgv;
	Comandos* comando;

public:
	Interface(Dgv*d, Dga*da, Comandos* com);

	//funcao para correr o simulador
	void Simulador();

	Dgv *getDgv();
	Dga *getDga();
};

