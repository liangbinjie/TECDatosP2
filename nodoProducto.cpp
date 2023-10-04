#include "nodoProducto.h"

NodoProducto::NodoProducto() {
	id = 0;
    FB= 0;
	idPais = 0;
    idCiudad = 0;
	int idRest = 0;
    idMenu = 0;
	nombre = "";
	izq = NULL;
	der = NULL;
}

NodoProducto::NodoProducto(int pId, int pIdPais, int pIdCiudad, int pIdRest, int pIdMenu, string pNombre) {
	id = pId;
    FB= 0;
	idPais = pIdPais;
    idCiudad = pIdCiudad;
	int idRest = pIdRest;
    idMenu = pIdMenu;
	nombre = pNombre;
	izq = NULL;
	der = NULL;
}
