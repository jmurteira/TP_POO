#include "Autodromo.h"
#include "Carro.h"
#include "Comandos.h"
#include "Dga.h"
#include "Dgv.h"
#include "Consola.h"
#include "Interface.h"
#include "Logica.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <time.h>

using namespace std;

int main() {
	srand(time(NULL));
	
	Dga dga("Portugal");
	Dgv dgv("Portugal");
	Dgv dgve("Espanha");
	
	Comandos c = Comandos();
	Logica logic = Logica(&c);
	c.atribuiDgv(&dgve);
	c.atribuiDgv(&dgv);
	c.atribuiDga(&dga);

	Interface i =Interface(&logic);
	i.Simulador();

	cin.get();
}

