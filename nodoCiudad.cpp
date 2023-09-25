#include "nodoCiudad.h"

NodoCiudad::NodoCiudad() {
	id = 0;
    FB= 0;
	nombre = "";
	izq = NULL;
	der = NULL;
}

NodoCiudad::NodoCiudad(int pId, string pNombre) {
	id = pId;
    FB= 0;
	nombre = pNombre;
	izq = NULL;
	der = NULL;
}
