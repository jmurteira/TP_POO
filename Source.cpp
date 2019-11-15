#include "Autodromo.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

int main() {

	Autodromo aut1 = Autodromo("Vienna", 4268);
	cout << aut1.getAsString();

	cin.get();
}