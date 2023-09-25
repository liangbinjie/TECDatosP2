#ifndef ARBOLPAIS_H
#define ARBOLPAIS_H

#include <iostream>
using namespace std;

#include "nodoPais.h"
#include <fstream>
#include <string>
#include <sstream>

class ArbolPais {
	private:
		NodoPais* raiz;
		
		void insertarAux(NodoPais* r, int id, string nombre);
		NodoPais* buscarAux(NodoPais* r, int id);
		void postorden(NodoPais* r);
		void inorden(NodoPais* r);
		void preorden(NodoPais* r);
		NodoPais* existeAux(NodoPais* r, int id);
		NodoPais* modificarAux(NodoPais* r, int id, string nombreNuevo);
	public:
		ArbolPais();
		
		void insertar(int id, string nombre);
		void cargarPais();
		void buscar(int id);
		bool existe(int id);
		void modificar(int id, string nombreNuevo);
		
		void preorden();
		void inorden();
		void postorden();	
};

#endif
