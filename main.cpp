#include <iostream>
using namespace std;


// importando clases
#include "nodoPais.h"
#include "arbolPais.h"
#include "nodoCiudad.h"
#include "arbolCiudad.h"

int main() {


ArbolPais paises;
	paises.cargarPais();
	paises.insertar(9, "USA");
	paises.insertar(46, "ES");
	paises.insertar(100, "ASW");
	paises.insertar(4, "CVB");
	paises.insertar(4, "CVB");
	paises.insertar(5, "QWE");
	paises.insertar(76, "WER");
//	paises.insertar(23, "SDF");
//	paises.insertar(63, "CHN");
//	paises.insertar(23, "SQW");
	//paises.modificar(345, "KOREA");
	//paises.modificar(234, "no se");
	paises.preorden();


	ArbolCiudad ciudades;
	
	ciudades.insertar(12, 9, "San Jose", paises);
	ciudades.insertar(132, 9,"Alajuela", paises);
	ciudades.insertar(28, 9, "Cartago", paises);
	ciudades.cargarCiudades(paises);
	
	cout<<"hola"<<endl;
	ciudades.preorden();
	ciudades.inorden();
	ciudades.buscarCiudad(132,9,paises);
	ciudades.buscarCiudad(345,123,paises);
	ciudades.modificar(28,"Berlin",9,paises);
	ciudades.buscarCiudad(71,46,paises);
	
	//paises.postorden();
	//paises.inorden();
	//paises.buscar(4567);
	//paises.buscar(200);
	return 0;
}
