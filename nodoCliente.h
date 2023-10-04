#ifndef NODOCLIENTE_H
#define NODOCLIENTE_H

#include <iostream>
using namespace std;

#define MAX 4
#define MIN 2

class NodoCliente {
	private:
    struct NodoClienteInternal {
        int val[MAX + 1], count;
        NodoCliente* link[MAX + 1];
    };

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