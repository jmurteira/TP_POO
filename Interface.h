#pragma once

class Dga;
class Dgv;
class Comandos;
class Consola;
class Carro;
class Piloto;
class Campeonato;
class Autodromo;
class Logica;

using namespace std;

class Interface
{
	//ISTO VAI SAIR DAQUI
	Dga* dga;
	Dgv* dgv;
	Comandos* comando;

	Logica* logica;



public:
	Interface(Logica* log);

	//funcao para correr o simulador
	void Simulador();

	Dgv *getDgv();
	Dga *getDga();
	Comandos* getComandos();
};

