#ifndef NODOMENU_H
#define NODOMENU_H

#include <iostream>
using namespace std;

struct NodoMenu {
    int clave;
    int nivel;
    int idPais;
    int idCiudad;
    int idRest;
    int cont;
    string nombre;
    NodoMenu* izquierda;
    NodoMenu* derecha;
};

#endif