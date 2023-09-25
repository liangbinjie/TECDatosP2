#include <iostream>
using namespace std;


// importando clases
#include "nodoPais.h"
#include "arbolPais.h"

int main() {
	ArbolPais paises;
	paises.insertar(9, "USA");
	paises.insertar(46, "ES");
	paises.insertar(100, "ASW");
	paises.insertar(4, "CVB");
	paises.insertar(5, "QWE");
	paises.insertar(76, "WER");
	paises.insertar(23, "SDF");
	paises.insertar(63, "CHN");
	paises.insertar(23, "SQW");
	paises.preorden();
	paises.postorden();
	paises.inorden();
	paises.buscar(4);
	paises.buscar(200);
	return 0;
}
