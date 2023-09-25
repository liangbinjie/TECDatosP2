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
		void insertar(int id, string nombre);
		void cargarPais();
		NodoPais getRaiz();
		
		void preorden();
		
		
};

#endif
