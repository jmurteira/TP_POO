#pragma once
#include <string>
#include <vector>

class Carro;
class Classificacao;

using namespace std;

class Piloto
{
private:
	string nome;
	string tipo;
	bool atualizado;	//serve para saber se a classificação está atualizada
	Carro * carro;		//ponteiro para carro

public:
	Piloto(string t, string n);
	Piloto(const Piloto& orig);
	~Piloto();

	//bool comparaPts(const Classificacao * c1, const Classificacao * c2);

	//ver sinal de emergencia

	virtual void entrarCarro(Carro * c);
	void sairCarro();

	virtual void acelera();
	virtual void trava();

	bool getAtualizado()const;
	void setAtualizado(bool a);

	virtual void passaTempoPiloto(int t, int dist, vector<int> p);

	bool verificaPrimeiro(vector<int> p) const;
	bool verificaUltimo(vector<int> p) const;

	string getNome() const;
	char getIdCarro() const;
	string getTipo()const;

	Carro* getCarro() const;

	void acidente();

	void carregaCarro(float n_energia);

	virtual string getStringDescricao()const;

};
