#ifndef ARBOLPAIS_H
#define ARBOLPAIS_H

#include <iostream>
using namespace std;

#include "nodoPais.h"

class ArbolPais {
	private:
		NodoPais* raiz;
	public:
		ArbolPais();
		void insertarAux(NodoPais* r, int id, string nombre);
		void insertar(int id, string nombre);
		void cargarPais();
		
		void preorden(NodoPais* r);
		void preorden();
		void inorden(NodoPais* r);
		void inorden();
		void postorden(NodoPais* r);
		void postorden();
		
		
};

#endif
