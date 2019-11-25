#include "Dgv.h"
#include "Carro.h"
#include "Piloto.h"


Dgv::Dgv(string id):DgvID(id) {}

Carro* Dgv::novoCarro(string marc, string mod, char ident) {
	if (procuraCarro(ident) == nullptr) {
		Carro* p = new Carro(marc, mod, ident);
		carros.push_back(p);
		return p;
	}
	return nullptr;
}

Piloto* Dgv::novoPiloto(string n, int t) {
	if (procuraPiloto(n) == nullptr) {
		Piloto* p = new Piloto(n, t);
		pilotos.push_back(p);
		return p;
	}
	return nullptr;

}


Carro* Dgv::procuraCarro(char ident) const {
	for (vector<Carro*>::const_iterator it = carros.cbegin();
		it != carros.cend();
		it++)
		if ((*it)->getIdent() == ident)
			return *it;
	return nullptr;
}


Piloto* Dgv::procuraPiloto(string nome) const {
	for (vector<Piloto*>::const_iterator it = pilotos.cbegin();
		it != pilotos.cend();
		it++)
		if ((*it)->getNome() == nome)
			return *it;
	return nullptr;
}