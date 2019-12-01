#include "Dga.h"
#include "Autodromo.h"
#include "Dgv.h"
#include "Carro.h"
#include "Piloto.h"
#include <sstream>
#include <iostream>


Dga::Dga(string id) :DgaID(id) {}

Autodromo* Dga::novoAutodromo(int cap, int dist, string n) {
	if (procuraAutodromo(n) == nullptr && autodromos.size() == 0) { //so ha um autodromo nesta meta
		Autodromo* a = new Autodromo(cap, dist, n);
		autodromos.push_back(a);
		return a;
	}
	return nullptr;
}

Autodromo* Dga::procuraAutodromo(string nome) const {
	for (vector<Autodromo*>::const_iterator it = autodromos.cbegin();
		it != autodromos.cend();
		it++)
		if ((*it)->getNome() == nome)
		{
			cout << endl << "Autodromo ja existente. " << endl;
			return *it;
		}
	return nullptr;
}


void Dga::carregaA(string fich) {
	string linha;
	ifstream file(fich);
	if (file.is_open() && verificaNumParametrosFicheiroTexto(fich) == 3)
	{
		while (getline(file, linha))
		{
			int cap, dist;
			string nome;
			istringstream is(linha);
			if (is >> cap) {
				if (is >> dist)
					if (is >> nome)
					{
						novoAutodromo(cap, dist, nome);
					}
			}
		}
		file.close();
	}
	else cout << endl << "Erro ao abrir o ficheiro";
}

int Dga::verificaNumParametrosFicheiroTexto(string fich) {
	int n_parametros = 0;
	string linha;
	ifstream file(fich);
	if (file.is_open())
	{
		getline(file, linha);

		int atual, max;
		string marca, modelo;
		istringstream is(linha);
		while (is >> linha)
		{
			++n_parametros;
			//cout << n_parametros << endl;
		}

		file.close();
	}
	return n_parametros;
}

//ter cuidado com isto porque penso que todos os carros sao destruidos
void Dga::apagaAutodromo(string nome) {
	if (procuraAutodromo(nome) != nullptr) {
		//cout << "entrou";
		for (size_t i = 0; i < autodromos.size(); i++) {
			if (autodromos[i]->getNome() == nome)
				for (size_t j = 0; j < autodromos[i]->getPista().size(); j++) { 
					//falta ir a dgv retirar os pilotos dos carros danificados. conclusao, os autodromos tambem devem estar na dgv
					autodromos[i]->getPista().erase(autodromos[i]->getPista().begin() + j); //retirar pilotos da pista
					autodromos[i]->getGaragem().erase(autodromos[i]->getGaragem().begin() + j); //retirar carros da garagem
				}
				//pilotos[i]->getCarro()->setDesocupado();
			autodromos.erase(autodromos.begin() + i);
		}

		delete procuraAutodromo(nome);
	}
	else
		cout << "piloto com nome: " << nome << " inexistente" << endl;
}

string Dga::descricaoAutodromo() const {
	string res = "\nDGV - Autodromos Registados: \n---------------";
	for (vector<Autodromo*>::const_iterator it = autodromos.cbegin();
		it != autodromos.cend();
		it++)
		res += "\n" + (*it)->getStringDescricao();
	return res;
}

int Dga::getDgaSize()const {

	return autodromos.size();

}

