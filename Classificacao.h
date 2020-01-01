#pragma once

class Piloto;

class Classificacao
{
	Piloto* piloto;
	int lugar;
	int pontos;
public:

	Classificacao(int l, int t, int pts, Piloto * p);

	int getLugar() const;
	int getTempo() const;
	int getPontos() const;

	void setLugar(int l);
	void setTempo(int t);
	void setPontos(int pts);
	void setPiloto(Piloto * p);

	Piloto* getPiloto() const;
};

