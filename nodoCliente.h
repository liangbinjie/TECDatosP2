#ifndef NODOCLIENTE_H
#define NODOCLIENTE_H

#include <iostream>
using namespace std;

class NodoCliente {
	public:
		int cedula;
		string nombre;
		//NodoProducto* izq;
		//NodoProducto* der;
		friend class arbolCliente;

		NodoCliente();
		NodoCliente(int cedula, string nombre);
		
};

typedef NodoCliente* pnodoCliente;


#endif