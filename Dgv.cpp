#include "Dgv.h"
#include "Carro.h"
#include "Piloto.h"
#include <fstream>
#include <sstream>

Dgv::Dgv(string id):DgvID(id) {}

Carro* Dgv::novoCarro(string marc, string mod, int capAtual, int capMax, char ident) {
	
	if(procuraCarro(ident) == nullptr && carros.size() < 26){
		ident = 'a' + rand() % 26;
		//cout << "teste1: " << ident << endl;
		while (verificaIdent(ident) == false) {
			ident = 'a' + rand() % 26;
			//cout << "teste2: " << ident << endl;
			
		}
		//cout << "teste3: " << ident << endl;
			Carro* p = new Carro(marc, mod, capAtual, capMax, ident);
			carros.push_back(p);
			return p;
	}
	else if (procuraCarro(ident) == nullptr && carros.size() >= 26) {
		Carro* p = new Carro(marc, mod, capAtual, capMax, ident = '?');
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

void Dgv::carregaP(string fich) {
	string linha;
	string tipo;
	ifstream file(fich);
	if (file.is_open())
	{
		while (getline(file, linha))
		{
			int t;
			string nome;
			istringstream is(linha);
			is >> tipo;
			if (tipo == "classico" /*|| tipo == "Classico"*/) {
				t = 1;
				is >> nome;
				novoPiloto(nome,t);
			}
		}
		file.close();
	}
	else cout << endl << "Erro ao abrir o ficheiro";
}

void Dgv::carregaC(string fich) {
	string linha;
	ifstream file(fich);
	if (file.is_open())
	{
		while (getline(file, linha))
		{
			int atual, max;
			string marca, modelo;
			istringstream is(linha);
			if (is >> atual) {
				if (is >> max)
					if (is >> marca)
						if (is >> modelo)
							if (atual <= max) {
								novoCarro(marca, modelo, atual, max);
							}
			}
		}
		file.close();
	}
	else cout << endl << "Erro ao abrir o ficheiro";
}

void Dgv::carregaA(string fich) {
	string linha;
	string tipo;
	ifstream file(fich);
	if (file.is_open())
	{
		while (getline(file, linha))
		{
			int t;
			string nome;
			istringstream is(linha);
			is >> tipo;
			if (tipo == "classico" /*|| tipo == "Classico"*/) {
				t = 1;
				is >> nome;
				novoPiloto(nome, t);
			}
		}
		file.close();
	}
	else cout << endl << "Erro ao abrir o ficheiro";
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

void Dgv::apagaCarro(char ident) {
	if (procuraCarro(ident) != nullptr) {
		cout << "entrou";
		for (size_t i = 0; i < pilotos.size(); i++) {
			if (pilotos[i]->getIdCarro() == ident)
				pilotos[i]->sairCarro();
		}
		for(size_t i = 0; i < carros.size(); i++){
			if (carros[i]->getIdent() == ident)
				carros.erase(carros.begin() + i);
		}
		delete procuraCarro(ident);
	}
	else
		cout << "carro com id: " << ident << " inexistente" << endl;
}

void Dgv::apagaPiloto(string nome) {
	if (procuraPiloto(nome) != nullptr) {
		cout << "entrou";
		for (size_t i = 0; i < pilotos.size(); i++) {
			if (pilotos[i]->getNome() == nome)
				pilotos[i]->getCarro()->setDesocupado();
				pilotos.erase(pilotos.begin() + i);
		}
		delete procuraPiloto(nome);
	}
	else
		cout << "piloto com nome: " << nome << " inexistente" << endl;
}

void Dgv::entraNoCarro(char ident, string nome) {
	Carro* c = procuraCarro(ident);
	Piloto* p = procuraPiloto(nome);

	if (c != nullptr && p != nullptr && c->getOcupado() == false){
		p->entrarCarro(c);
	}
	else if (c != nullptr && c->getOcupado() == true)
		cout << "carro com id: " << ident << " ja se encontra ocupado" << endl;
	else if (c != nullptr)
		cout << "Piloto: " << nome << " ainda nao tem carro" << endl;
}

void Dgv::saiDoCarro(char ident) {
	Carro* c = procuraCarro(ident);
	if (c != nullptr && c->getOcupado() == false)
		cout << "carro com id: " << ident << " ja se encontra livre" << endl;
	else if (c != nullptr) {
		for (vector<Piloto*>::const_iterator it = pilotos.cbegin();
			it != pilotos.cend();
			it++) {
			if (c == (*it)->getCarro() && c->getOcupado() == true)
				(*it)->sairCarro();
		}
	}
	else
		cout << "carro com id: " << ident << " inexistente" << endl;
}