#include "Dgv.h"
#include "Carro.h"
#include "Piloto.h"



Dgv::Dgv(string id):DgvID(id) {}

Carro* Dgv::novoCarro(string marc, string mod, char ident) {
	
	if(procuraCarro(ident) == nullptr && carros.size() < 26){
		ident = 'a' + rand() % 26;
		//cout << "teste1: " << ident << endl;
		while (verificaIdent(ident) == false) {
			ident = 'a' + rand() % 26;
			//cout << "teste2: " << ident << endl;
			
		}
		//cout << "teste3: " << ident << endl;
			Carro* p = new Carro(marc, mod, ident);
			carros.push_back(p);
			return p;
	}
	else if (procuraCarro(ident) == nullptr && carros.size() >= 26) {
		Carro* p = new Carro(marc, mod, ident = '?');
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



bool Dgv::verificaIdent(char ident) {
	for (vector<Carro*>::const_iterator it = carros.cbegin();
		it != carros.cend();
		it++)
		if ((*it)->getIdent() == ident) {
			//cout << "entrou" << endl;
				return false;
		}
		return true;
			
}


string Dgv::descricaoCarro() const {
	string res = "\nDGV - Carros Registados: \n---------------";
	for (vector<Carro*>::const_iterator it = carros.cbegin();
		it != carros.cend();
		it++)
		res += "\n" + (*it)->getStringDescricao();
	return res;
}

string Dgv::descricaoPiloto() const {
	string res = "\nDGV - Pilotos Registados: \n---------------";
	for (vector<Piloto*>::const_iterator it = pilotos.cbegin();
		it != pilotos.cend();
		it++)
		res += "\n" + (*it)->getStringDescricao();
	return res;


}
