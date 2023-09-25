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
		cout << "Nuevo pais insertado" << endl;
	} else {
		if (existe(id)) {
			cout << "Este pais ya existe" << endl;
		} else {
			insertarAux(raiz, id, nombre);
			cout << "Nuevo pais insertado" << endl;
		}
	}
}


NodoPais* ArbolPais::buscarAux(NodoPais* r, int id) {
    if (r == NULL || r->id == id) {
        return r;
    }

    if (id < r->id) {
        return buscarAux(r->izq, id);
    } else {
        return buscarAux(r->der, id);
    }
}

void ArbolPais::buscar(int id) {
    NodoPais* buscado = buscarAux(raiz, id);
    if (buscado == NULL) {
        cout << "No existe este pais" << endl;
    } else {
        cout << "ID: " << buscado->id << "\nNombre: " << buscado->nombre << endl;
    }
}

NodoPais* ArbolPais::modificarAux(NodoPais* r, int id, string nombre) {
    if (r->id == id) {
    	r->nombre = nombre;
        return r;
    }

    if (id < r->id) {
        return modificarAux(r->izq, id, nombre);
    } else {
        return modificarAux(r->der, id, nombre);
    }
}

void ArbolPais::modificar(int id, string nombre) {
    
    if (!existe(id)) {
        cout << "No existe este pais" << endl;
    } else {
    	NodoPais* buscado = modificarAux(raiz, id, nombre);
    	cout << "Nombre modificado" << endl;
        cout << "ID: " << buscado->id << "\nNombre: " << buscado->nombre << endl;
    }
}

NodoPais* ArbolPais::existeAux(NodoPais* r, int id) {
    if (r == NULL || r->id == id) {
        return r;
    }

    if (id < r->id) {
        return existeAux(r->izq, id);
    } else {
        return existeAux(r->der, id);
    }
}

bool ArbolPais::existe(int id) {
    NodoPais* buscado = existeAux(raiz, id);
    if (buscado == NULL) {
        return false;
    } else {
        return true;
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


void ArbolPais::cargarPais() {
	ifstream archivo("Archivos/Paises.txt");
    string line;
    
    while (getline(archivo, line)) {
        stringstream ss(line);
        string temp;
        int idP;
        string name;

        getline(ss, temp, ';');
        idP = stoi(temp);

        getline(ss, name, ';');

        insertar(idP, name);
    }
    archivo.close();
}

