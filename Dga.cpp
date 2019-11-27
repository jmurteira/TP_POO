#include "Dga.h"
#include "Autodromo.h"
#include <sstream>
#include <iostream>

Dga::Dga(string id) :DgaID(id) {}

Autodromo* Dga::novoAutodromo(string n, int dist) {
	if (procuraAutodromo(n) == nullptr) {
		Autodromo* a = new Autodromo(n, dist);
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
			cout << endl << "Nome de Autodromo j� existente. " << endl;
			return *it;
		}
	return nullptr;
}