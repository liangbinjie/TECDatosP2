#include "arbolPais.h"

ArbolPais::ArbolPais() {
	raiz = NULL;
}

void ArbolPais::insertar(int id, string nombre) {
	if (raiz == NULL) {
		raiz = new NodoPais(id, nombre);
	} else {
		cout << "Hello" << endl;
	}
}

void ArbolPais::preorden(NodoPais* r) {
	if (r == NULL) {
		return;
	} else {
		cout << r->nombre << " - ";
		preorden(r->izq);
		preorden(r->der);
	}
}

NodoPais getRaiz() {
	return raiz;
}

