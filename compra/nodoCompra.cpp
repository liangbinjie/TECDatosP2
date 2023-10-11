#include "nodoCompra.h"

NodoCompra::NodoCompra(int idCliente, int cp, int cc, int cr, int cm, string pp, bool dt) {
	this->idCliente = idCliente;
	idPais = cp;
	idCiudad = cc;
	idRest = cr;
	idMenu = cm;
	productos = pp;
	driveThru = dt;
	siguiente = NULL;
}

