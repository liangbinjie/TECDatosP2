#ifndef LISTACOMPRA_H
#define LISTACOMPRA_H

#include <iostream>
#include "nodoCompra.h"
#include "compra.h"
#include <fstream>

using namespace std;

typedef NodoCompra* pNodoCompra;

class ListaCompra {
   private:
	   pNodoCompra primero;
	   
	public:
	    ListaCompra();
		void agregar(int idCliente, int cp, int cc, int cr, int cm, string compra, bool dt, int costo);
		void mostrar();
		void pagar();
		void facturaMontoMasAlto();
		void facturaMontoMasBajo();
		void comprasCliente(int idCliente);
	    
};

#endif
