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

	void setLugar(int l);
	void setTempo(int t);
	void setPontos(int pts);
	void setPiloto(Piloto * p);

	Piloto* getPiloto() const;
};

