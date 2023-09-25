#include "nodoPais.h"

NodoPais::NodoPais() {
	id = 0;
	nombre = "";
	izq = NULL;
	der = NULL;
}

NodoPais::NodoPais(int pId, string pNombre) {
	id = pId;
	nombre = pNombre;
	izq = NULL;
	der = NULL;
}
