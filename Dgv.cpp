
#include "Dgv.h"
#include "Carro.h"
#include "Piloto.h"

Dgv::Dgv(string id):DgvID(id) {}

Carro* Dgv::novoCarro(int capAtual, int capMax, string marc, string mod, char ident) {
	
	if(procuraCarro(ident) == nullptr && carros.size() < 26){
		ident = 'a' + rand() % 26;
		//cout << "teste1: " << ident << endl;
		while (!verificaIdent(ident)) {
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



Piloto* Dgv::novoPiloto(string t, string n) {
	while (verificaNomePiloto(n) == false) {
		cout << "Nome: " << n << " ja existe. Ira ser adicionado um identificador ao nome para futura distincao." << endl;
		int id = rand() % ((100 - 1) + 1) + 1;
		string id_unico = to_string(id);
		n.append(" ");
		n.append(id_unico);
	}
	if (procuraPiloto(n) == nullptr) {
		Piloto* p = new Piloto(t, n);
		pilotos.push_back(p);
		return p;
	}
	return nullptr;

}

void Dgv::carregaP(string fich) {
	string linha;
	string tipo;
	ifstream file(fich);
	if (file.is_open() && verificaNumParametrosFicheiroTexto(fich) == 2)
	{
		while (getline(file, linha))
		{
			string t;
			string nome;
			istringstream is(linha);
			is >> tipo;
			if (tipo == "classico" /*|| tipo == "Classico"*/) {
				t = 1;
				is >> nome;
				novoPiloto(t,nome);
			}
		}
		file.close();
	}
	else cout << endl << "Erro ao abrir o ficheiro";
}

void Dgv::carregaC(string fich) {
	string linha;
	ifstream file(fich);
	if (file.is_open() && verificaNumParametrosFicheiroTexto(fich) == 4)
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
								novoCarro(atual, max, marca, modelo );
							}
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

bool Dgv::verificaNomePiloto(string nome) {
	for (vector<Piloto*>::const_iterator it = pilotos.cbegin();
		it != pilotos.cend();
		it++)
		if ((*it)->getNome() == nome) {
			//cout << "entrou" << endl;
			return false;
		}
	return true;
}


int Dgv::verificaNumParametrosFicheiroTexto(string fich) {
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
				//cout << n_parametros <<endl;
			}
		
		file.close();
	}
	return n_parametros;
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

	if (c != nullptr && p->getCarro() == nullptr && c->getOcupado() == false){
		p->entrarCarro(c);
	}
	else if (c != nullptr && c->getOcupado() == true)
		cout << "carro com id: " << ident << " ja se encontra ocupado" << endl;
	else if (p!= nullptr && p->getCarro() != nullptr)
		cout << "Piloto: " << nome << " ja tem carro" << endl;
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
