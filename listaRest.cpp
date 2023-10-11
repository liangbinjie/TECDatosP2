#include "listaRest.h"


nodoRest::nodoRest(int id, int idP, int idC, string nombre) {
    this->id = id;
    this->idPais = idC;
    this->idCiudad = idC;
    this->nombre = nombre;
    this->siguiente = NULL;
}

listaRest::listaRest() {
    head = NULL;
}

bool listaRest::existe(nodoRest* nuevo) {
    nodoRest* aux = head;
    while (aux != NULL) {
        if (aux->id == nuevo->id && aux->idPais == nuevo->idPais && aux->idCiudad == nuevo->idCiudad) {
            return true;
        }
        aux = aux->siguiente;
    }
    return false;
}

void listaRest::insertar(int id, int idP, int idC, string nombre, ArbolPais &paises, ArbolCiudad &ciudades, ArbolRestaurante& restaurantes) {
    nodoRest* nuevo = new nodoRest(id, idP, idC, nombre);
    if (existe(nuevo)) {
        cout << "Este restaurante ya existe" << endl;
        return;
    } else {
        if (ciudades.existeCiudad(idC, idP)) {
        if (paises.existePais(idP)) {
            if (head == NULL) {
                head = nuevo;
            } else {
                nodoRest* aux = head;
                while (aux->siguiente != NULL) {
                    aux = aux->siguiente;
                }
                aux->siguiente = nuevo;
            }
            restaurantes.insertar(idP, idC, id, nombre);
            cout << "Nuevo rest insertado" << endl;
        } else {
            cout << "No existe el pais o ciudad" << endl;
            return;
        }
        }
    }
}

void listaRest::cargarRest(ArbolPais &paises, ArbolCiudad &ciudades, ArbolRestaurante& restaurantes) {
    ifstream archivo("Archivos/Restaurantes.txt");
    string line;
    
    while (getline(archivo, line)) {
        stringstream ss(line);
        string temp;
        int idP, idC, idR;
        string name;

        getline(ss, temp, ';');
        idP = stoi(temp);

        getline(ss, temp, ';');
        idC = stoi(temp);

        getline(ss, temp, ';');
        idR = stoi(temp);

        getline(ss, name, ';');

       insertar(idR, idP, idC, name, paises, ciudades, restaurantes);
    }

    archivo.close();
}