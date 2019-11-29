#include "Dga.h"
#include "Autodromo.h"
#include <sstream>
#include <iostream>

Dga::Dga(string id) :DgaID(id) {}

Autodromo* Dga::novoAutodromo(int cap, int dist, string n) {
	if (procuraAutodromo(n) == nullptr) {
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
			cout << endl << "Nome de Autodromo ja existente. " << endl;
			return *it;
		}
	return nullptr;
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