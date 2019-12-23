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
	Logica* logica;

public:
	Interface(Logica* log);

	//funcao para correr o simulador
	void Simulador();

	Logica* getLogica();
};

