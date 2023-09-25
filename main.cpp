#include <iostream>
using namespace std;


// importando clases
#include "nodoPais.h"
#include "arbolPais.h"

int main() {
	ArbolPais paises;
	paises.insertar(1, "USA");
	paises.insertar(2, "ES");
	paises.preorden(paises.getRaiz());
	return 0;
}
