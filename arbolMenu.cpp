#include <iostream>
#include "nodoMenu.h"
#include "arbolMenu.h"

ArbolMenu::ArbolMenu() {
    raiz = nullptr;
};

void ArbolMenu::insertar(int clave, int idPais, int idCiudad, int idRest, string nombre, ArbolPais paises, ArbolCiudad ciudades, ArbolRestaurante restaurantes) {
    if (existe(clave, idPais, idCiudad, idRest)) {
        cout << "Este menu ya existe" << endl;
        return;
    }
    if (paises.existePais(idPais) && ciudades.existeCiudad(idCiudad, idPais, paises) && restaurantes.existe(idRest, idPais, idCiudad)) {
        raiz = insertarRec(raiz, clave, idPais, idCiudad, idRest, nombre);
        cout << "Nuevo menu insertado" << endl;
    } else {
        cout << "No existe el restaurante/pais/ciudad" << endl;
    }
}

void ArbolMenu::mostrar() {
    mostrarRec(raiz, 0);
}

bool ArbolMenu::existe(int clave, int idPais, int idCiudad, int idRest) {
    return existeRec(raiz, clave, idPais, idCiudad, idRest);
}


NodoMenu* ArbolMenu::sesgar(NodoMenu* nodo) {
    if (nodo == nullptr)
        return nullptr;
    else if (nodo->izquierda != nullptr && nodo->izquierda->nivel == nodo->nivel) {
        NodoMenu* hijoIzquierdo = nodo->izquierda;
        nodo->izquierda = hijoIzquierdo->derecha;
        hijoIzquierdo->derecha = nodo;
        return hijoIzquierdo;
    }
    return nodo;
}

NodoMenu* ArbolMenu::dividir(NodoMenu* nodo) {
    if (nodo == nullptr)
        return nullptr;
    else if (nodo->derecha != nullptr && nodo->derecha->derecha != nullptr &&
             nodo->derecha->derecha->nivel == nodo->nivel) {
        NodoMenu* hijoDerecho = nodo->derecha;
        nodo->derecha = hijoDerecho->izquierda;
        hijoDerecho->izquierda = nodo;
        hijoDerecho->nivel++;
        return hijoDerecho;
    }
    return nodo;
}

NodoMenu* ArbolMenu::insertarRec(NodoMenu* nodo, int clave, int idPais, int idCiudad, int idRest, string nombre) {
    if (nodo == nullptr) {
        nodo = new NodoMenu{clave, 1, idPais, idCiudad, idRest, nombre, nullptr, nullptr};
    } else if (clave <= nodo->clave) {
        nodo->izquierda = insertarRec(nodo->izquierda, clave, idPais, idCiudad, idRest, nombre);
    } else if (clave > nodo->clave) {
        nodo->derecha = insertarRec(nodo->derecha, clave, idPais, idCiudad, idRest, nombre);
    }

    nodo = sesgar(nodo);
    nodo = dividir(nodo);

    return nodo;
}

void ArbolMenu::mostrarRec(NodoMenu* nodo, int profundidad) {
    if (nodo != nullptr) {
        mostrarRec(nodo->derecha, profundidad + 1);
        for (int i = 0; i < profundidad; i++) {
            std::cout << "  ";
        }
        std::cout << "(" << nodo->clave << "," << nodo->nivel << ")" << std::endl;
        mostrarRec(nodo->izquierda, profundidad + 1);
    }
}

bool ArbolMenu::existeRec(NodoMenu* nodo, int clave, int idPais, int idCiudad, int idRest) {
    if (nodo == nullptr) {
        return false;
    }
    
    if (clave == nodo->clave && idPais == nodo->idPais && nodo->idCiudad == idCiudad && idRest == nodo->idRest) {
        return true;
    } else if (clave < nodo->clave) {
        return existeRec(nodo->izquierda, clave, idPais, idCiudad, idRest);
    } else {
        return existeRec(nodo->derecha, clave, idPais, idCiudad, idRest);
    }
}

void ArbolMenu::buscar(int clave, int idPais, int idCiudad, int idRest) {
    if (!existe(clave, idPais, idCiudad, idRest)) {
        cout << "Este menu no existe" << endl;
        return;
    }
    return buscarRec(raiz, clave, idPais, idCiudad, idRest);
}

void ArbolMenu::buscarRec(NodoMenu* nodo, int clave, int idPais, int idCiudad, int idRest) {
    if (nodo == nullptr) {
        return;
    }
    
    if (clave == nodo->clave && idPais == nodo->idPais && nodo->idCiudad == idCiudad && idRest == nodo->idRest) {
        cout << "ID PAIS: " << nodo->idPais << endl;
        cout << "ID CIUDAD:" << nodo->idCiudad << endl;
        cout << "ID REST: " << nodo->idRest << endl;
        cout << "ID MENU: " << nodo->clave << endl;
        cout << "Nombre menu: " << nodo->nombre << endl;
        return;
    } else if (clave < nodo->clave) {
        return buscarRec(nodo->izquierda, clave, idPais, idCiudad, idRest);
    } else {
        return buscarRec(nodo->derecha, clave, idPais, idCiudad, idRest);
    }
}

void ArbolMenu::modificar(int clave, int idPais, int idCiudad, int idRest, string nombre) {
    if (!existe(clave, idPais, idCiudad, idRest)) {
        cout << "Este menu no existe" << endl;
        return;
    }
    return modificar(raiz, clave, idPais, idCiudad, idRest, nombre);
}

void ArbolMenu::modificar(NodoMenu* nodo, int clave, int idPais, int idCiudad, int idRest, string nombre) {
    if (nodo == nullptr) {
        return;
    }
    
    if (clave == nodo->clave && idPais == nodo->idPais && nodo->idCiudad == idCiudad && idRest == nodo->idRest) {
        nodo->nombre = nombre;
        cout << "Nombre menu cambiado a: " << nodo->nombre << endl;
        return;
    } else if (clave < nodo->clave) {
        return modificar(nodo->izquierda, clave, idPais, idCiudad, idRest, nombre);
    } else {
        return modificar(nodo->derecha, clave, idPais, idCiudad, idRest, nombre);
    }
}

void ArbolMenu::cargarMenus(ArbolPais paises, ArbolCiudad ciudades, ArbolRestaurante rests) {
    ifstream archivo("Archivos/Menu.txt");
    string line;
    
    while (getline(archivo, line)) {
        stringstream ss(line);
        string temp;
        int idP, idC, idR, idM;
        string name;

        getline(ss, temp, ';');
        idP = stoi(temp);

        getline(ss, temp, ';');
        idC = stoi(temp);

        getline(ss, temp, ';');
        idR = stoi(temp);

        getline(ss, temp, ';');
        idM = stoi(temp);

        getline(ss, name, ';');

        insertar(idM, idP, idC, idR, name, paises, ciudades, rests);
    }

    archivo.close();
}