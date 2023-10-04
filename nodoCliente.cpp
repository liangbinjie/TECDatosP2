#include "nodoCliente.h"

NodoCliente::NodoCliente() {
	cedula = 0;
	nombre = "";
	//izq = NULL;
	//der = NULL;
}

NodoCliente::NodoCliente(int pCedula, string pNombre) {
	cedula = pCedula;
	nombre = pNombre;
	//izq = NULL;
	//der = NULL;
}

