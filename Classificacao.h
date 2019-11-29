#pragma once

class Piloto;

class Classificacao
{
	Piloto* piloto;
	int lugar;
	int tempo;
	int pontos;
public:

	Classificacao();

	int getLugar() const;
	int getTempo() const;
	int getPontos() const;

	Piloto* getPiloto() const;
};

