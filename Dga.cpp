#include "Dga.h"
#include "Autodromo.h"
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
	if (file.is_open())
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

