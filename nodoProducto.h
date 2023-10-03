#ifndef NODOPRODUCTO_H
#define NODOPRODUCTO_H

#include <iostream>
using namespace std;

class NodoProducto {
	public:
		int id;
		int idPais;
        int idCiudad;
        int idMenu;
        int FB;
		string nombre;
		NodoProducto* izq;
		NodoProducto* der;
		friend class arbolProducto;

		NodoProducto();
		NodoProducto(int id, int idPais, int idCiudad, int idMenu, string nombre);
		
};

typedef NodoProducto* pnodoProducto;


#endif
