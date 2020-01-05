#pragma once
class Dga;
class Dgv;
class Comandos;
class Consola;
class Carro;
class Piloto;
class Campeonato;
class Autodromo;

class Logica
{
	Comandos* comando;

public:
	Logica(Comandos* com);

	//funcao para correr o simulador
	void Simulador();

	//Dgv* getDgv();
	Dga* getDga();
	Comandos* getComandos();
};

