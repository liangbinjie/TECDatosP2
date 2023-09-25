#ifndef NODOPAIS_H
#define NODOPAIS_H

#include <iostream>
using namespace std;

class NodoPais {
	public:
		int id;
		string nombre;
		NodoPais* izq;
		NodoPais* der;
		friend class ArbolPais;

		NodoPais();
		NodoPais(int id, string nombre);
		
};

typedef NodoPais* pnodoPais;


#endif
