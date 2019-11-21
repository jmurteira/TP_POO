#pragma once
#include <vector>
#include <string>

#include "Piloto.h"
#include "Carro.h"

using namespace std;

class Dgv
{
	string DgvID;
	vector<Piloto*> pilotos;
	vector<Carro*> carros;
public:


	Dgv(string id);
	//Carro* novoCarro(string marc, string mod);
	//Piloto* novoPiloto(string n, int t);




};

