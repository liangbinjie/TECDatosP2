#ifndef NODOCOMPRA_H
#define NODOCOMPRA_H


#include <iostream>
using namespace std;

class NodoCompra {
	private:
		int idCliente;	
		int idPais;
		int idCiudad;
		int idRest;
		int idMenu;
		bool driveThru;
		int costo;
		string productos;
		NodoCompra *siguiente;
		
		friend class ListaCompra;
		
	public:
		NodoCompra(int idCliente, int cp, int cc, int cr, int cm, string pp, bool dt, int costo);
	
};



#endif


