#include <iostream>
using namespace std;


// importando clases
#include "nodoPais.h"
#include "arbolPais.h"
#include "nodoCiudad.h"
#include "arbolCiudad.h"

int main() {


	ArbolCiudad ciudades;
	ciudades.insertar(12, "San Jose");
	ciudades.insertar(132, "Alajuela");
	ciudades.insertar(28, "Cartago");
	ciudades.insertar(9, "Heredia");
	ciudades.insertar(1, "Puntarenas");
	ciudades.insertar(26, "Puntarenas");
	ciudades.insertar(77, "Puntarenas");
	ciudades.insertar(13, "Puntarenas");
	ciudades.insertar(98, "Puntarenas");
	ciudades.insertar(14, "Puntarenas");
	ciudades.insertar(12, "Puntarenas");
	ciudades.insertar(24, "Puntarenas");
	ciudades.insertar(17, "Puntarenas");
	ciudades.insertar(48, "Puntarenas");
	ciudades.insertar(71, "Puntarenas");
	ciudades.insertar(132, "Puntarenas");
	
	cout<<"hola"<<endl;
	ciudades.preorden();
	ciudades.inorden();
	ciudades.existe(12);
	ArbolPais paises;
	//paises.cargarPais();
	paises.insertar(9, "USA");
//	paises.insertar(46, "ES");
//	paises.insertar(100, "ASW");
//	paises.insertar(4, "CVB");
//	paises.insertar(5, "QWE");
//	paises.insertar(76, "WER");
//	paises.insertar(23, "SDF");
//	paises.insertar(63, "CHN");
//	paises.insertar(23, "SQW");
	//paises.modificar(345, "KOREA");
	//paises.modificar(234, "no se");
	paises.preorden();
	//paises.postorden();
	//paises.inorden();
	//paises.buscar(4567);
	//paises.buscar(200);
	return 0;
}
