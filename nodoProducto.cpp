#include "nodoProducto.h"

NodoProducto::NodoProducto(int cp, int cc, int cr, int cm, int cpro, string pNombre, int kc, int p, int cant) {
    codPais = cp;
    codCiudad = cc;
    codRest = cr;
    codMenu = cm;
    codProducto = cpro;
    nombre = pNombre;
    kcal = kc;
    precio = p;
    siguiente = NULL;
    contador = 0;
	cantidad = cant;
}

NodoProducto::NodoProducto(int cp, int cc, int cr, int cm, int cpro, string pNombre, int kc, int p, int cant, NodoProducto* sigNodo) {
    codPais = cp;
    codCiudad = cc;
    codRest = cr;
    codMenu = cm;
    codProducto = cpro;
    nombre = pNombre;
    kcal = kc;
    precio = p;
    siguiente = sigNodo;
    contador = 0;
	cantidad = cant;
}
