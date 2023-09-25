#include "arbolPais.h"

ArbolPais::ArbolPais() {
	raiz = NULL;
}

void ArbolPais::insertarAux(NodoPais* r, int id, string nombre) {
	if (r->id > id) {
		if (r->izq == NULL) {
			r->izq = new NodoPais(id, nombre);
		} else {
			insertarAux(r->izq, id, nombre);
		}
	}
	if (r->id < id) {
		if (r->der == NULL) {
			r->der = new NodoPais(id, nombre);
		} else {
			insertarAux(r->der, id, nombre);
		}
	}
}

void ArbolPais::insertar(int id, string nombre) {
	if (raiz == NULL) {
		raiz = new NodoPais(id, nombre);
	} else {
		insertarAux(raiz, id, nombre);
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

void ArbolPais::preorden() {
	preorden(raiz);
	cout << endl;
}

void ArbolPais::inorden(NodoPais* r) {
	if (r == NULL) {
		return;
	} else {
		inorden(r->izq);
		cout << r->nombre << " - ";
		inorden(r->der);
	}
}

void ArbolPais::inorden() {
	inorden(raiz);
	cout << endl;
}

void ArbolPais::postorden(NodoPais* r) {
	if (r == NULL) {
		return;
	} else {
		postorden(r->izq);
		postorden(r->der);
		cout << r->nombre << " - ";
	}
}

void ArbolPais::postorden() {
	postorden(raiz);
	cout << endl;
}

