#include "nodoCiudad.h"

NodoCiudad::NodoCiudad() {
	id = 0;
    FB= 0;
	idPais = 0;
	nombre = "";
	izq = NULL;
	der = NULL;
}

NodoCiudad::NodoCiudad(int pId, int pIdPais, string pNombre) {
	id = pId;
    FB= 0;
	idPais = pIdPais;
	nombre = pNombre;
	izq = NULL;
	der = NULL;
}
